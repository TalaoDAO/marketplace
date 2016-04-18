<?php

/*
 * @file : LinkedIn API requests related functions
 */

/*
 * Called from submit callback at linkedin/token/%user
 * Let the user authorize us to gain access to his profile, and store credentials.
 * Also used for login.
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function linkedin_access_token($account) {
  //Get sure library is loaded before doing anything.
  linkedin_init();

  if ($account->uid < 1) {
    $anon = TRUE;
    $back = 'login';
  }
  else {
    $anon = FALSE;
    $back = 'token';
  }
  //setting up variables
  $base_url = "https://api.linkedin.com/uas/oauth";
  $signature = new OAuthSignatureMethod_HMAC_SHA1();
  $consumer_key = variable_get('linkedin_consumer_key', '');
  $consumer_secret = variable_get('linkedin_consumer_secret', '');
  $consumer = new OAuthConsumer($consumer_key, $consumer_secret, NULL);
  $random = md5(rand());
  $callback = url('linkedin/' . $back . '/' . $account->uid, array('absolute' => TRUE, 'query' => array('action' => $random))); // random will be used to discard direct call to the path and for anonymous
  // First or renewal request
  if (!isset($_GET['action']) || $_GET['action'] != $_SESSION['random']) {
    $_SESSION['random'] = $random;
    $url = $base_url . "/requestToken";
    $request = OAuthRequest::from_consumer_and_token($consumer, NULL, 'POST', $url);
    $request->set_parameter("oauth_callback", $callback);
    $request->sign_request($signature, $consumer, NULL);
    $header = $request->to_header();
    $response = _linkedin_http_request($url, $header, 'token_request');
    parse_str($response, $oauth);
    if (isset($oauth['oauth_problem'])) {
      if (variable_get('linkedin_debug_mode', 0) == 1) {
        drupal_set_message(t('LinkedIn debug : received error response : @error'), array('@error' => $oauth['oauth_problem']), 'warning');
      }
      else {
        drupal_set_message(t('There was a problem with the configuration of LinkedIn on this website. Please try again later.'), 'error');
      }
      watchdog('linkedin', t('Linkedin reported the following response : @error'), array('@error' => $oauth['oauth_problem']), WATCHDOG_ERROR);
      drupal_goto();
    }
    if ($oauth['oauth_token']) {

      if (!$anon) { // Logged in user : store request token for next step in db instead of $_SESSION for security       
        db_delete('linkedin_token')
          ->condition('uid', $account->uid)
          ->execute();
        $sql = array(
          'uid' => $account->uid,
          'token_key' => $oauth['oauth_token'],
          'token_secret' => $oauth['oauth_token_secret'],
          'type' => 'request',
        );
        drupal_write_record('linkedin_token', $sql);
        //Redirect the user to the authentication/authorisation page. This will authorise the token in LinkedIn
        drupal_goto($base_url . '/authorize?oauth_token=' . $oauth['oauth_token']);
      }
      else { // Anonymous user. We can't use db storage, but $_SESSION can not lead to identity forgery for anonymous
        $_SESSION['oauth_token_secret'] = $oauth['oauth_token_secret'];
        //Redirect the user to the authentication/authorisation page. This will authorise the token in LinkedIn
        drupal_goto($base_url . '/authenticate?oauth_token=' . $oauth['oauth_token']);
      }
    }
    else {
      if (variable_get('linkedin_debug_mode', 0) == 1) {
        drupal_set_message(t('LinkedIn debug : received no answer from linkedin.com. Check your API credential at admin/settings/linkedin'));
      }
      else {
        drupal_set_message(t('There was a problem with the configuration of LinkedIn on this website. Please try again later.'), 'error');
      }
      watchdog('linkedin', t('The website could not communicate with LinkedIn. It is likely your API credentials are misconfigured.'), array(), WATCHDOG_ERROR);
      drupal_goto();
    }
  }
  else {
    //this is called when the OAuth callback is invoked. User has authorised the token.
    //Now retrieve the stored request token and ask for an access token

    $url = $base_url . '/accessToken';
    if (!$anon) {
      $result = db_query("SELECT token_secret FROM {linkedin_token} WHERE uid = :uid AND type = :type", array(':uid' => $account->uid, ':type' => 'request'))->fetchField();
    }
    else {
      $result = $_SESSION['oauth_token_secret'];
    }
    $token = new OAuthConsumer($_REQUEST['oauth_token'], $result, 1);
    $request = OAuthRequest::from_consumer_and_token($consumer, $token, "POST", $url);
    $request->set_parameter("oauth_verifier", $_REQUEST['oauth_verifier']);
    $request->sign_request($signature, $consumer, $token);
    $header = $request->to_header();
    $response = _linkedin_http_request($url, $header, 'token_request');
    parse_str($response, $oauth);
    if (!$anon) {
      //Check if the same LinkedIn account is not already tied to another user
      $result = db_query("SELECT uid FROM {linkedin_token} WHERE token_key = :token_key AND token_secret = :token_secret AND type = :type ", array(':token_key' => $oauth['oauth_token'], ':token_secret' => $oauth['oauth_token_secret'], ':type' => 'access'))->fetchField();
      if ($result) {
        $registered = user_load($result);
        drupal_set_message(t('Sorry, this LinkedIn account is already associated with user !registered', array('!registered' => l($registered->name, 'user/' . $result))), 'warning');
        drupal_goto('user/' . $account->uid . '/edit/linkedin');
      }
      //save acces token for future requests
      $sql = array(
        'uid' => $account->uid,
        'token_key' => $oauth['oauth_token'],
        'token_secret' => $oauth['oauth_token_secret'],
        'type' => 'access',
      );
      drupal_write_record('linkedin_token', $sql, array('uid'));
      //associate LinkedIn ID with uid for future use
      $id = linkedin_get_profile_fields($account->uid, array('id'), TRUE);
      user_set_authmaps($account, array('authmap_linkedin' => $id['id']));
      drupal_goto("user/$account->uid/edit/linkedin");
    }
    else {
      $uid = db_query("SELECT uid FROM {linkedin_token} WHERE token_key = :token_key AND token_secret = :token_secret AND type = :type ", array(':token_key' => $oauth['oauth_token'], ':token_secret' => $oauth['oauth_token_secret'], ':type' => 'access'))->fetchField();

      if ($uid > 0) {
        module_invoke_all('linkedin_external_login', $uid);
      }
      else {
        module_invoke_all('linkedin_tie_external_login', $uid, $oauth['oauth_token'], $oauth['oauth_token_secret']);
      }
    }
  }
}

/*
 * Let us retrieve profile fields.
 * Returns an array contening the fields requested.
 * @params
 * $uid : the uid of the user we want to access infos
 * $fields : the fields we want to retrieve, as an array (see http://developer.linkedin.com/docs/DOC-1061 for complete list).
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function _linkedin_get_profile_fields($uid, $fields = array()) {
  //Get sure library is loaded before doing anything.
  linkedin_init();

  $base_url = "https://api.linkedin.com/v1/people/";

  $row = db_query("SELECT * FROM {linkedin_token} WHERE uid = :uid AND type = :type", array(':uid' => $uid, ':type' => 'access'))->fetchAssoc();
  if (!$row || empty($row)) {
    // This account does not have any LinkedIn account associated with.
    $response = array(
      'status' => '401',
      'error-code' => 'custom',
      'message' => 'No LinkedIn account is associated with this user',
    );
    if (variable_get('linkedin_debug_mode', 0) == 1) {
      drupal_set_message(t('Linkedin debug : @status : @message', array('@status' => $response['status'], '@message' => $response['message'])));
    }
    return $response;
  }

  global $user;
  if ($user->uid == $uid) {
    //User is requesting his own profile.
    $tokens = $row;
    $append = '~';
    $type = 'auth';
  }
  else {
    $tokens = db_query("SELECT * FROM {linkedin_token} WHERE uid = :uid AND type = :type", array(':uid' => $user->uid, ':type' => 'access'))->fetchAssoc();
    if (!$tokens) {
      //We don't have any LinkedIn account associated with the user viewing the profile.
      //Make the request on the behalf on viewed user and switch to public profile.
      $tokens = $row;
      $append = '~:public';
      $type = 'public';
    }
    else {
      //Fetch profile. Fields returned will depend on the relationships between viewing/viewed users
      $authname = db_query("SELECT authname FROM {authmap} WHERE uid = :uid AND module = :module", array(':uid' => $uid, ':module' => 'linkedin'))->fetchField();
      $append = 'id=' . $authname;
      $type = 'auth';
    }
  }
  $tokens = (array) $tokens;
  $append .= _linkedin_build_fields_request($fields, $type);
  $url = $base_url . $append;
  $response = linkedin_get_fields($url, $tokens);

  if (isset($response['error']['status']) && ($response['error']['status'] == 401 || $response['error']['status'] == 403)) {
    // No relationships between users, switch back to public profile and retry
    $tokens = (array) $row;
    $append = '~:public';
    $append .= _linkedin_build_fields_request($fields, 'public');
    $url = $base_url . $append;
    $response = linkedin_get_fields($url, $tokens);
  }
  if (isset($response['person'])) {
    $response = $response['person'];
  }
  else {
    $response = $response['error'];
  }
  if (variable_get('linkedin_debug_mode', 0) == 1) {
    if (isset($response['error-code'])) {
      drupal_set_message(t('Linkedin debug : LinkedIn.com answered "@status : @message', array('@status' => $response['status'], '@message' => $response['message'])));
    }
  }
  return $response;
}

/*
 * Returns an array contening the fields requested.
 * @params
 * $url : full request url to a linkedin API ressource (see API doc for syntax)
 * $tokens : the user tokens, as an array containing keys 'token_key' and 'token_secret' with their value
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function _linkedin_get_fields($url, $tokens) {
  //Get sure library is loaded before doing anything.
  linkedin_init();

  $signature = new OAuthSignatureMethod_HMAC_SHA1();
  $consumer_key = variable_get('linkedin_consumer_key', '');
  $consumer_secret = variable_get('linkedin_consumer_secret', '');
  $consumer = new OAuthConsumer($consumer_key, $consumer_secret, NULL);
  $token = new OAuthConsumer($tokens['token_key'], $tokens['token_secret'], 1);
  $request = OAuthRequest::from_consumer_and_token($consumer, $token, "GET", $url);
  $request->sign_request($signature, $consumer, $token);
  $header = $request->to_header("https://api.linkedin.com");
  $response = _linkedin_http_request($url, $header);
  parse_str($response);
  $response = _linkedin_parse_fields($response);
  if (isset($response['error-code'])) {
    $message = t('Linkedin debug : LinkedIn.com answered "@status : @message', array('@status' => $response['status'], '@message' => $response['message']));
    if (variable_get('linkedin_debug_mode', 0) == 1) {
      drupal_set_message($message, 'warning');
    }
    watchdog('warning', $message);
  }
  return $response;
}

/*
 * Let us 'put' data into user profile.
 * Usage :
 * $uid : the uid of the user we want to access infos
 * $api : the api we want to use to update. For now, only Share API is available
 * $body : The content to be sent.
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function _linkedin_put_profile_field($uid, $body, $api = 'shares') {
  //Get sure library is loaded before doing anything.
  linkedin_init();

  $base_url = 'https://api.linkedin.com/v1/people/~/';
  $url = $base_url . $api;

  if ($api == 'shares') {
    $xml = '<share>';
    if (isset($body['comment'])) {
      $xml .= '<comment>' . $body['comment'] . '</comment>';
    }
    if (isset($body['title']) && isset($body['submitted-url'])) {
      $xml .= '<content>';
      $xml .= '<title>' . $body['title'] . '</title>';
      $xml .= '<submitted-url>' . $body['submitted-url'] . '</submitted-url>';
      if (isset($body['submitted-image-url'])) {
        $xml .= '<submitted-image-url>' . $body['submitted-image-url'] . '</submitted-image-url>';
      }
      if (isset($body['description'])) {
        $xml .= '<description>' . $body['description'] . '</description>';
      }
      $xml .= '</content>';
    }
    $xml .= '<visibility><code>anyone</code></visibility>';
    $xml .= '</share>';
  }
  else {
    // Unsupported update method
    $message = t('Linkedin debug : Unsupported update method "@method"', array('@method' => $api));
    if (variable_get('linkedin_debug_mode', 0) == 1) {
      drupal_set_message($message, 'warning');
    }
    watchdog('warning', $message);
    return;
  }

  $signature = new OAuthSignatureMethod_HMAC_SHA1();
  $consumer_key = variable_get('linkedin_consumer_key', '');
  $consumer_secret = variable_get('linkedin_consumer_secret', '');
  $consumer = new OAuthConsumer($consumer_key, $consumer_secret, NULL);
  $row = db_query("SELECT * FROM {linkedin_token} WHERE uid = :uid AND type = :type", array(':uid' => $uid, ':type' => 'access'))->fetchAssoc();
  $token = new OAuthConsumer($row['token_key'], $row['token_secret'], 1);
  $request = OAuthRequest::from_consumer_and_token($consumer, $token, 'POST', $url, array());
  $request->sign_request($signature, $consumer, $token);
  $header = $request->to_header();
  $response = _linkedin_http_request($url, $header, $xml);
  if (isset($response['error-code'])) {
    $message = t('Linkedin debug : LinkedIn.com answered "@status : @message', array('@status' => $response['status'], '@message' => $response['message']));
    if (variable_get('linkedin_debug_mode', 0) == 1) {
      drupal_set_message($message, 'warning');
    }
    watchdog('warning', $message);
  }
  return $response;
}

/*
 * Some internal helper functions...
 */

function _linkedin_http_request($url, $header, $body = NULL) {

  $ch = curl_init();

  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 1);
  curl_setopt($ch, CURLOPT_HTTPHEADER, array($header));
  curl_setopt($ch, CURLOPT_URL, $url);

  if ($body) {
    curl_setopt($ch, CURLOPT_POST, 1);
    if ($body == 'token_request') {
      curl_setopt($ch, CURLOPT_POSTFIELDS, '');
    }
    else {
      curl_setopt($ch, CURLOPT_POSTFIELDS, $body);
      curl_setopt($ch, CURLOPT_HTTPHEADER, array($header, 'Content-Type: text/xml;charset=utf-8'));
      curl_setopt($ch, CURLOPT_POST, 1);
      curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'POST');
    }
  }

  $output = curl_exec($ch);
  curl_close($ch);
  return $output;
}

/*
 * Parser function. Based on xml2array() by Binny V A :  http://www.bin-co.com/php/scripts/xml2array/
 */

function _linkedin_parse_fields($contents) {
  if (!$contents) {
    return array();
  }

  if (!function_exists('xml_parser_create')) { //Get the XML parser of PHP - PHP must have this module for the parser to work
    if (variable_get('linkedin_debug_mode', 0) == 1) {
      drupal_set_message(t('Unable to find PHP parser. This module needs php-xml lib'), 'warning');
    }
    return array();
  }


  $parser = xml_parser_create('');
  xml_parser_set_option($parser, XML_OPTION_TARGET_ENCODING, "UTF-8"); // http://minutillo.com/steve/weblog/2004/6/17/php-xml-and-character-encodings-a-tale-of-sadness-rage-and-data-loss
  xml_parser_set_option($parser, XML_OPTION_CASE_FOLDING, 0);
  xml_parser_set_option($parser, XML_OPTION_SKIP_WHITE, 1);
  xml_parse_into_struct($parser, trim($contents), $xml_values);
  xml_parser_free($parser);

  if (!$xml_values) {
    return;
  }
  $xml_array = array();
  $parents = array();
  $opened_tags = array();
  $arr = array();

  $current = &$xml_array; //Reference
  //Go through the tags.
  $repeated_tag_index = array(); //Multiple tags with same name will be turned into an array
  foreach ($xml_values as $data) {
    unset($attributes, $value); //Remove existing values, or there will be trouble
    //This command will extract these variables into the foreach scope
    // tag(string), type(string), level(int), attributes(array).
    extract($data); //We could use the array by itself, but this cooler.

    $result = array();
    $attributes_data = array();

    if (isset($value)) {
      $result = $value;
    }
    //See tag status and do the needed.
    if ($type == "open") { //The starting of the tag '<tag>'
      $parent[$level - 1] = &$current;
      if (!is_array($current) or (!in_array($tag, array_keys($current)))) { //Insert New tag
        $current[$tag] = $result;
        if ($attributes_data) {
          $current[$tag . '_attr'] = $attributes_data;
        }
        $repeated_tag_index[$tag . '_' . $level] = 1;

        $current = &$current[$tag];
      }
      else { //There was another element with the same tag name
        if (isset($current[$tag][0])) { //If there is a 0th element it is already an array
          $current[$tag][$repeated_tag_index[$tag . '_' . $level]] = $result;
          $repeated_tag_index[$tag . '_' . $level]++;
        }
        else { //This section will make the value an array if multiple tags with the same name appear together
          $current[$tag] = array($current[$tag], $result); //This will combine the existing item and the new item together to make an array
          $repeated_tag_index[$tag . '_' . $level] = 2;

          if (isset($current[$tag . '_attr'])) { //The attribute of the last(0th) tag must be moved as well
            $current[$tag]['0_attr'] = $current[$tag . '_attr'];
            unset($current[$tag . '_attr']);
          }
        }
        $last_item_index = $repeated_tag_index[$tag . '_' . $level] - 1;
        $current = &$current[$tag][$last_item_index];
      }
    }
    elseif ($type == "complete") { //Tags that ends in 1 line '<tag />'
      //See if the key is already taken.
      if (!isset($current[$tag])) { //New Key
        $current[$tag] = $result;
        $repeated_tag_index[$tag . '_' . $level] = 1;
        if ($attributes_data) {
          $current[$tag . '_attr'] = $attributes_data;
        }
      }
      else { //If taken, put all things inside a list(array)
        if (isset($current[$tag][0]) && is_array($current[$tag])) { //If it is already an array...
          // ...push the new element into that array.
          $current[$tag][$repeated_tag_index[$tag . '_' . $level]] = $result;


          $repeated_tag_index[$tag . '_' . $level]++;
        }
        else { //If it is not an array...
          $current[$tag] = array($current[$tag], $result); //...Make it an array using using the existing value and the new value
          $repeated_tag_index[$tag . '_' . $level] = 2; //0 and 1 index is already taken
        }
      }
    }
    elseif ($type == 'close') { //End of tag '</tag>'
      $current = &$parent[$level - 1];
    }
  }

  return ($xml_array);
}

/*
 * Filter the requested fields to match the type of profile (public or auth)
 */

function _linkedin_build_fields_request($fields, $type = 'auth') {
  if (!empty($fields) || is_array($fields)) {
    $fieldslist = _linkedin_list_fields($type);
    $requested = '';
    foreach ($fields as $field) {
      if (in_array($field, $fieldslist)) {
        $requested .= $field . ',';
      }
    }
    $request = ':(' . trim($requested, ',') . ')';
  }
  return $request;
}

/*
 * Provides a list of available LinkedIn fields
 * $type : 'public' or 'auth'. Wether we need 'public' or 'standard' fields
 */

function _linkedin_list_fields($type = 'auth') {
  $fields = array(
    'id',
    'first-name',
    'last-name',
    'headline',
    'location',
    'industry',
    'summary',
    'specialties',
    'honors',
    'interests',
    'num-recommenders',
    'member-url-resources',
    'picture-url',
    'public-profile-url',
    'positions',
    'educations',
    //          @TODO //          'site-standard-profile-request', //          'api-standard-profile-request', //          'api-public-profile-request', Deprecated ? //          'site-public-profile-request', Deprecated ? //          'member-url', // Deprecated ?
  );
  if ($type == 'auth') {
    $standard_fields = array(
      'distance',
      'current-status',
      'current-status-timestamp',
      'num-connections',
      'num-connections-capped',
      'associations',
      'phone-numbers',
      'im-accounts',
      'twitter-accounts',
      'date-of-birth',
      'main-address',
      //        @TODO //        'relation-to-viewer', //        'proposal-comments', //        'recommendations-received',
    );
    $fields = array_merge($fields, $standard_fields);
  }
  return $fields;
}
