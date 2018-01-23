<?php

/**
 * @file : LinkedIn API requests related functions
 */
define('EMH_LINKEDIN_DIR_IMAGE', 'sites/default/files/picture');

/**
 * Let us retrieve profile fields.
 * Returns an array contening the fields requested.
 *
 * @param unknown $uid
 *          : the uid of the user we want to access infos.
 * @param array $fields
 *          : the fields we want to retrieve, as an array (see
 *   http://developer.linkedin.com/docs/DOC-1061 for complete list).
 *
 * @return string[]|unknown
 */
function _emh_linkedin_get_profile_fields($uid, $fields = []) {
  // Get sure library is loaded before doing anything.
  emh_linkedin_init();

  $base_url = "https://api.linkedin.com/v1/people/";

  $session = _hybridauth_session_load_by_uid($uid);
  $data_session = hybridauth_get_instance()->getSessionData();
  $data = unserialize($session['data']);

  $row = [
    'token_key' => unserialize($data['hauth_session.linkedin.token.access_token']),
    'token_secret' => unserialize($data['hauth_session.linkedin.token.access_token_secret']),
  ];

  if (!$row || empty($row)) {
    // This account does not have any LinkedIn account associated with.
    $response = [
      'status' => '401',
      'error-code' => 'custom',
      'message' => 'No LinkedIn account is associated with this user',
    ];
    if (variable_get('emh_linkedin_debug_mode', 0) == 1) {
      drupal_set_message(t('Linkedin debug : @status : @message', [
        '@status' => $response['status'],
        '@message' => $response['message'],
      ]));
    }
    return $response;
  }

  $session = _hybridauth_session_load_by_uid($uid);
  $data = unserialize($session['data']);

  $tokens = [
    'token_key' => unserialize($data['hauth_session.linkedin.token.access_token']),
    'token_secret' => unserialize($data['hauth_session.linkedin.token.access_token_secret']),
  ];

  if (!$tokens) {
    // We don't have any LinkedIn account associated with the user viewing the profile.
    // Make the request on the behalf on viewed user and switch to public profile.
    $tokens = $row;
    $append = '~:public';
    $type = 'public';
  }
  else {
    // Fetch profile. Fields returned will depend on the relationships between viewing/viewed users
    $identity = db_select('hybridauth_identity', 'ha_id')
      ->fields('ha_id')
      ->condition('uid', $uid, '=')
      ->execute()
      ->fetchAssoc();
    $authname = $identity['provider_identifier'];

    $append = 'id=' . $authname;
    $type = 'auth';
  }

  $tokens = (array) $tokens;
  $append .= _emh_linkedin_build_fields_request($fields, $type);
  $url = $base_url . $append;
  $response = emh_linkedin_get_request_fields($url, $tokens);

  if (isset($response['error']['status']) && ($response['error']['status'] == 401 || $response['error']['status'] == 403)) {
    // No relationships between users, switch back to public profile and retry

    $tokens = (array) $row;
    $append = '~:public';
    $append .= _emh_linkedin_build_fields_request($fields, 'public');
    $url = $base_url . $append;
    $response = emh_linkedin_get_request_fields($url, $tokens);
  }
  if (isset($response['person'])) {
    $response = $response['person'];
  }
  else {
    $response = $response['error'];
  }
  if (variable_get('emh_linkedin_debug_mode', 0) == 1) {
    if (isset($response['error-code'])) {
      drupal_set_message(t('Linkedin debug : LinkedIn.com answered "@status : @message', [
        '@status' => $response['status'],
        '@message' => $response['message'],
      ]));
    }
  }
  return $response;
}

/**
 * List of LinkedIn fields to complet user profile.
 *
 * @return string[]
 */
function _emh_linkedin_fields_build_profile() {
  // Basic Profile LinkedIn Fields
  $fields = [
    'first-name',
    'last-name',
    'location',
    'num-connections',
    'summary',
    'positions',
    'picture-urls::(original)',
    'email-address',
    'public-profile-url',
    'headline',
  ];

  return $fields;
}

/**
 * List of LinkedIn fields for user settings.
 *
 * @return string[]
 */
function _emh_linkedin_fields_user_update() {
  // Basic Profile LinkedIn Fields
  $fields = [
    'location',
    'summary',
    'positions',
    'picture-urls::(original)',
    'email-address',
    'public-profile-url',
    'headline',
  ];

  return $fields;
}

/**
 * Retrieve the list of a user's linkedin fields
 */
function _emh_linkedin_get_user_fields($user) {
  $user_fields = $user->data['emh_linkedin_fields'];
  $fields = [];
  foreach ($user_fields as $key => $value) {
    if ($value) {
      $fields[] = $key;
    }
  }

  return $fields;
}

/**
 * List obligatory of LinkedIn fields for user settings.
 *
 * @return string[]
 */
function _emh_linkedin_fields_default_user_update() {
  // Basic Profile LinkedIn Fields
  $fields = [
    'first-name',
    'last-name',
    'num-connections',
  ];

  return $fields;
}

/**
 * Return boolean if user can to update profile to linkedin.
 *
 * @param unknown $user
 *
 * @return unknown|boolean
 */
function _emh_linkedin_update_user($user) {
  if (isset($user->data['emh_linkedin_update'])) {
    return $user->data['emh_linkedin_update'];
  }
  return FALSE;
}

function _emh_linkedin_fields_to_user_fields($field, $user) {
  if (isset($field['value'])) {
    $item = $field['value'];
    switch ($field['name']) {

      case 'location' :

        $country_code = strtoupper($item['country']['code']);
        $country = country_get_list()[$country_code];

        $city = $item['name'];

        $city = substr($city, 0, strrpos($city, ','));
        $city = substr($city, 0, strrpos($city, ' '));

        if (empty($user->field_address)) {

          if (strcmp($country, $item['name']) != 0) {
            $user->field_address['und'][0]['locality'] = $city;
          }

          $user->field_address['und'][0]['country'] = $country_code;
        }
        else {
          // update
          if (strcmp($user->field_address['und'][0]['locality'], $item['name']) != 0) {
            if (strcmp($country, $item['name']) != 0) {
              $user->field_address['und'][0]['locality'] = $city;
            }
          }
          if (strcmp($user->field_address['und'][0]['country'], $country_code) != 0) {
            $user->field_address['und'][0]['country'] = $country_code;
          }
        }
        break;

      case 'num-connections' :

        if (empty($user->field_nb_contacts_linkedin)) {
          $user->field_nb_contacts_linkedin['und'][0]['value'] = $item;
        }
        else {
          // update
          if (strcmp($user->field_nb_contacts_linkedin['und'][0]['value'], $item) != 0) {
            $user->field_nb_contacts_linkedin['und'][0]['value'] = $item;
          }
        }
        break;

      case 'summary' :
        if (empty($user->field_employment_history)) {
          $user->field_employment_history['und'][0]['value'] = $item;
        }
        else {
          // update
          if (strcmp($user->field_employment_history['und'][0]['value'], $item) != 0) {
            $user->field_employment_history['und'][0]['value'] = $item;
          }
        }
        break;

      case 'positions' :

        $multiple = FALSE;

        if (array_key_exists(0, $item['position'])) {
          $taille = count($item['position']);
          $multiple = TRUE;
        }
        else {
          $taille = 1;
        }

        /*
         * for($i = 0 ; $i < $taille ; $i++) {
         * if($multiple) {
         * $position = $item['position'][$i];
         * } else {
         * $position = $item['position'];
         * }
         *
         * _emh_update_position($user, $position,$i);
         * }
         */
        if ($multiple) {
          $position = $item['position'][0];
        }
        else {
          $position = $item['position'];
        }

        $user = _emh_update_position($user, $position, 0);

        break;

      case 'picture-urls' :
        $url = $item['picture-url'];


        // download profile image LinkedIn
        $nom_img = $user->name . ".jpg";
        $dir_name = EMH_LINKEDIN_DIR_IMAGE;
        $path = $dir_name . "/" . $nom_img;

        $drupal_uri = file_build_uri("picture/" . $nom_img);

        // test if user have changed him linkedin picture
        if (isset($user->field_photo['und'][0]['fid'])) {
          $old = $user->field_photo['und'][0]['fid'];

          $md5image1 = md5(file_get_contents($url)); // linkedin
          $md5image2 = md5(file_get_contents($path)); // local
          if ($md5image1 != $md5image2) {
            // delete old image
            $file_old = file_load($old);
            file_delete($file_old, TRUE);
          }
          else {
            break;
          }
        }


        $handle = fopen($url, 'r');


        $file = file_save_data($handle, $drupal_uri, FILE_EXISTS_REPLACE);
        fclose($handle);

        //delete linkedin logo
        $img = image_load($drupal_uri);
        $rogne = 0.90;
        $width = (Integer) ($img->info['width'] * $rogne);
        $height = (Integer) ($img->info['height'] * $rogne);
        image_crop($img, 0, 0, $width, $height);
        image_save($img);

        $file = file_load($file->fid);
        $file->metadata['height'] = $height;
        $file->metadata['width'] = $width;
        $file->height = $height;
        $file->width = $width;
        file_save($file);
        file_usage_add($file, 'imagefield_crop', 'file', $file->fid);

        $user->field_photo['und'][0]['uri'] = $drupal_uri;
        $user->field_photo['und'][0]['fid'] = $file->fid;
        $user->field_photo['und'][0]['cropbox_x'] = 0;
        $user->field_photo['und'][0]['cropbox_y'] = 0;
        $user->field_photo['und'][0]['cropbox_height'] = $file->height;
        $user->field_photo['und'][0]['cropbox_width'] = $file->width;


        break;

      case 'public-profile-url' :
        $profile_URL = $item;

        if (empty($user->field_linkedin['und'][0]['url'])) {
          $user->field_linkedin['und'][0]['url'] = $profile_URL;
        }
        else {
          // update
          if (strcmp($user->field_linkedin['und'][0]['url'], $profile_URL) != 0) {
            $user->field_linkedin['und'][0]['url'] = $profile_URL;
          }
        }
        break;

      case 'headline' :

        if (empty($user->field_titre_metier['und'][0]['value'])) {
          $user->field_titre_metier['und'][0]['value'] = $item;
        }
        else {
          // update
          if (strcmp($user->field_titre_metier['und'][0]['value'], $item) != 0) {
            $user->field_titre_metier['und'][0]['value'] = $item;
          }
        }
        break;
    }
  }

  return $user;
}

/**
 * Update user data for multiple position fields.
 */
function _emh_update_position($user, $position, $i) {

  // field_position
  $title = $position['title'];

  if (!empty($title)) {

    $vocab = taxonomy_vocabulary_machine_name_load('position');

    if (empty($term = taxonomy_get_term_by_name($title, $vocab->machine_name))) {
      // add a new term
      $new_term = (object) [
        'name' => $title,
        'description' => $title,
        'vid' => $vocab->vid,
      ];

      taxonomy_term_save($new_term);
      $term = taxonomy_get_term_by_name($title, $vocab->machine_name);
    }
    // update
    $term_tmp = $term;
    $term = array_shift($term_tmp);

    if (empty($user->field_position)) {
      $user->field_position['und'][$i]['tid'] = $term->tid;
    }
    else {
      // update
      if (strcmp($user->field_position['und'][$i]['tid'], $term->tid) != 0) {
        $user->field_position['und'][$i]['tid'] = $term->tid;
      }
    }
  }

  // field_entreprise
  $company_name = $position['company']['name'];
  $node_name = 'corporate';

  if (!empty($company_name)) {

    $company_name = emh_suppr_accents($company_name, 'ISO-8859-1');

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $node_name)
      ->propertyCondition('title', $company_name, 'like');
    $result = $query->execute();

    if (isset($result['node'])) {
      $company = array_shift($result['node']);
    }
    else {
      // add a new company
      $company = new stdClass();
      $company->title = $position['company']['name'];
      $company->type = "corporate";
      node_object_prepare($company); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
      $company->language = 'und'; // Or e.g. 'en' if locale is enabled
      $company->uid = $user->uid;
      $company->status = 1; // (1 or 0): published or not
      $company->promote = 1; // (1 or 0): promoted to front page
      $company->comment = 0; // 0 = comments disabled, 1 = read only, 2 = read/write

      $company = node_submit($company); // Prepare node for saving
      node_save($company);
    }

    if (empty($user->field_entreprise)) {
      $user->field_entreprise['und'][$i]['target_id'] = $company->nid;
    }
    else {
      // update
      if (strcmp($user->field_entreprise['und'][$i]['target_id'], $company->nid) != 0) {
        $user->field_entreprise['und'][$i]['target_id'] = $company->nid;
      }
    }
  }

  // field_activities_linkedin
  if (empty($user->field_activities_linkedin)) {
    if (isset($position['summary'])) {
      $user->field_activities_linkedin['und'][$i]['value'] = $position['summary'];
    }
  }
  else {
    // update
    if (strcmp($user->field_activities_linkedin['und'][$i]['value'], $position['summary']) != 0) {
      if (isset($position['summary'])) {
        $user->field_activities_linkedin['und'][$i]['value'] = $position['summary'];
      }
    }
  }
  return $user;
}

/**
 * Provides a list of available LinkedIn fields.
 * $type : 'public' or 'auth'. Wether we need 'public' or 'standard' fields.
 */
function _emh_linkedin_list_fields($type = 'auth') {
  $fields = [
    'id',
    'first-name',
    'last-name',
    'headline',
    'location',
    'email-address',
    'headline',
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
    'current-share',
    'picture-urls::(original)',
  ];
  if ($type == 'auth') {
    $standard_fields = [
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
    ];
    $fields = array_merge($fields, $standard_fields);
  }
  return $fields;
}

/**
 * Filter the requested fields to match the type of profile (public or auth).
 *
 * @param unknown $fields
 * @param string $type
 *
 * @return string
 */
function _emh_linkedin_build_fields_request($fields, $type = 'auth') {
  if (!empty($fields) || is_array($fields)) {
    $fieldslist = _emh_linkedin_list_fields($type);
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

/**
 * Returns an array contening the fields requested.
 *
 * @params
 * $url : full request url to a linkedin API ressource (see API doc for syntax)
 * $tokens : the user tokens, as an array containing keys 'token_key' and
 *   'token_secret' with their value
 */
function _emh_linkedin_get_request_fields($url, $tokens) {
  // Get sure library is loaded before doing anything.
  emh_linkedin_init();

  $signature = new OAuthSignatureMethod_HMAC_SHA1();
  // LinkedIn key and key secret from Hybridauth module
  $consumer_key = variable_get('hybridauth_provider_LinkedIn_keys_key', '');
  $consumer_secret = variable_get('hybridauth_provider_LinkedIn_keys_secret', '');
  $consumer = new OAuthConsumer($consumer_key, $consumer_secret, NULL);
  $token = new OAuthConsumer($tokens['token_key'], $tokens['token_secret'], 1);
  $request = OAuthRequest::from_consumer_and_token($consumer, $token, "GET", $url);
  $request->sign_request($signature, $consumer, $token);
  $header = $request->to_header("https://api.linkedin.com");
  $response = _emh_linkedin_http_request($url, $header);
  parse_str($response);
  $response = _emh_linkedin_parse_fields($response);
  if (isset($response['error-code'])) {
    $message = t('Linkedin : LinkedIn.com answered "@status : @message', [
      '@status' => $response['status'],
      '@message' => $response['message'],
    ]);
    if (variable_get('emh_linkedin_debug_mode', 0) == 1) {
      drupal_set_message($message, 'warning');
    }
    watchdog('warning', $message);
  }
  return $response;
}

/**
 * Parser function.
 * Based on xml2array() by Binny V A :
 * http://www.bin-co.com/php/scripts/xml2array/
 */
function _emh_linkedin_parse_fields($contents) {
  if (!$contents) {
    return [];
  }

  if (!function_exists('xml_parser_create')) { // Get the XML parser of PHP - PHP must have this module for the parser to work
    if (variable_get('emh_linkedin_debug_mode', 0) == 1) {
      drupal_set_message(t('Unable to find PHP parser. This module needs php-xml lib'), 'warning');
    }
    return [];
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
  $xml_array = [];
  $parents = [];
  $opened_tags = [];
  $arr = [];

  $current = &$xml_array; // Reference
  // Go through the tags.
  $repeated_tag_index = []; // Multiple tags with same name will be turned into an array
  foreach ($xml_values as $data) {
    unset($attributes, $value); // Remove existing values, or there will be trouble
    // This command will extract these variables into the foreach scope
    // tag(string), type(string), level(int), attributes(array).
    extract($data); // We could use the array by itself, but this cooler.

    $result = [];
    $attributes_data = [];

    if (isset($value)) {
      $result = $value;
    }
    // See tag status and do the needed.
    if ($type == "open") { // The starting of the tag '<tag>'
      $parent[$level - 1] = &$current;
      if (!is_array($current) or (!in_array($tag, array_keys($current)))) { // Insert New tag
        $current[$tag] = $result;
        if ($attributes_data) {
          $current[$tag . '_attr'] = $attributes_data;
        }
        $repeated_tag_index[$tag . '_' . $level] = 1;

        $current = &$current[$tag];
      }
      else { // There was another element with the same tag name
        if (isset($current[$tag][0])) { // If there is a 0th element it is already an array
          $current[$tag][$repeated_tag_index[$tag . '_' . $level]] = $result;
          $repeated_tag_index[$tag . '_' . $level]++;
        }
        else { // This section will make the value an array if multiple tags with the same name appear together
          $current[$tag] = [
            $current[$tag],
            $result,
          ]; // This will combine the existing item and the new item together to make an array
          $repeated_tag_index[$tag . '_' . $level] = 2;

          if (isset($current[$tag . '_attr'])) { // The attribute of the last(0th) tag must be moved as well
            $current[$tag]['0_attr'] = $current[$tag . '_attr'];
            unset($current[$tag . '_attr']);
          }
        }
        $last_item_index = $repeated_tag_index[$tag . '_' . $level] - 1;
        $current = &$current[$tag][$last_item_index];
      }
    }
    elseif ($type == "complete") { // Tags that ends in 1 line '<tag />'
      // See if the key is already taken.
      if (!isset($current[$tag])) { // New Key
        $current[$tag] = $result;
        $repeated_tag_index[$tag . '_' . $level] = 1;
        if ($attributes_data) {
          $current[$tag . '_attr'] = $attributes_data;
        }
      }
      else { // If taken, put all things inside a list(array)
        if (isset($current[$tag][0]) && is_array($current[$tag])) { // If it is already an array...
          // ...push the new element into that array.
          $current[$tag][$repeated_tag_index[$tag . '_' . $level]] = $result;

          $repeated_tag_index[$tag . '_' . $level]++;
        }
        else { // If it is not an array...
          $current[$tag] = [
            $current[$tag],
            $result,
          ]; // ...Make it an array using using the existing value and the new value
          $repeated_tag_index[$tag . '_' . $level] = 2; // 0 and 1 index is already taken
        }
      }
    }
    elseif ($type == 'close') { // End of tag '</tag>'
      $current = &$parent[$level - 1];
    }
  }

  return ($xml_array);
}
