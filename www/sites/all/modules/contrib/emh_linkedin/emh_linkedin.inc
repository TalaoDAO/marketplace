<?php 

/*
 * @file : LinkedIn API requests related functions
 */

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
function _emh_linkedin_get_profile_fields($uid, $fields = array()) {
	//Get sure library is loaded before doing anything.
	emh_linkedin_init();

	$base_url = "https://api.linkedin.com/v1/people/";

	//$row = db_query("SELECT * FROM {linkedin_token} WHERE uid = :uid AND type = :type", array(':uid' => $uid, ':type' => 'access'))->fetchAssoc();
	$session = _hybridauth_session_load_by_uid($uid);
	$data = unserialize($session['data']);
	
	$row = array(
			'token_key' => unserialize($data['hauth_session.linkedin.token.oauth_token']),
			'token_secret' => unserialize($data['hauth_session.linkedin.token.oauth_token_secret'])
	);
	
	//var_dump($row);
	
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
		//$tokens = db_query("SELECT * FROM {linkedin_token} WHERE uid = :uid AND type = :type", array(':uid' => $user->uid, ':type' => 'access'))->fetchAssoc();
		$session = _hybridauth_session_load_by_uid($uid);
		$data = unserialize($session['data']);
	
		$tokens = array(
				'token_key' => unserialize($data['hauth_session.linkedin.token.oauth_token']),
				'token_secret' => unserialize($data['hauth_session.linkedin.token.oauth_token_secret'])
		);
		
		
		if (!$tokens) {
			//We don't have any LinkedIn account associated with the user viewing the profile.
			//Make the request on the behalf on viewed user and switch to public profile.
			$tokens = $row;
			$append = '~:public';
			$type = 'public';
		}
		else {
			//Fetch profile. Fields returned will depend on the relationships between viewing/viewed users
			//$authname = db_query("SELECT authname FROM {authmap} WHERE uid = :uid AND module = :module", array(':uid' => $uid, ':module' => 'linkedin'))->fetchField();
			$identity = db_select('hybridauth_identity', 'ha_id')
				->fields('ha_id')
				->condition('uid', 4413, '=')
				->execute()
				->fetchAssoc();
			$authname = $identity['provider_identity'];
			
			$append = 'id=' . $authname;
			$type = 'auth';
		}
	}
	$tokens = (array) $tokens;
	$append .= _emh_linkedin_build_fields_request($fields, $type);
	$url = $base_url . $append;
	$response = emh_linkedin_get_fields($url, $tokens);

	if (isset($response['error']['status']) && ($response['error']['status'] == 401 || $response['error']['status'] == 403)) {
		// No relationships between users, switch back to public profile and retry
		$tokens = (array) $row;
		$append = '~:public';
		$append .= _emh_linkedin_build_fields_request($fields, 'public');
		$url = $base_url . $append;
		$response = emh_linkedin_get_fields($url, $tokens);
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
	
	$file = 'people.txt';
	// Une nouvelle personne à ajouter
	$person = "Jean Dupond\n";
	
	file_put_contents($file, $person, FILE_APPEND | LOCK_EX);
	return $response;
}


/*
 * Provides a list of available LinkedIn fields
 * $type : 'public' or 'auth'. Wether we need 'public' or 'standard' fields
 */
function _emh_linkedin_list_fields($type = 'auth') {
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

/*
 * Filter the requested fields to match the type of profile (public or auth)
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
function _emh_linkedin_get_fields($url, $tokens) {
	//Get sure library is loaded before doing anything.
	emh_linkedin_init();
	
	$signature = new OAuthSignatureMethod_HMAC_SHA1();
	//on recupère la key et key secret du module hybridauth pour l'api linkedin
	$consumer_key = variable_get('hybridauth_provider_LinkedIn_keys_key', '');
	$consumer_secret = variable_get('	hybridauth_provider_LinkedIn_keys_secret', '');
	$consumer = new OAuthConsumer($consumer_key, $consumer_secret, NULL);
	$token = new OAuthConsumer($tokens['token_key'], $tokens['token_secret'], 1);
	$request = OAuthRequest::from_consumer_and_token($consumer, $token, "GET", $url);
	$request->sign_request($signature, $consumer, $token);
	$header = $request->to_header("https://api.linkedin.com");
	$response = _emh_linkedin_http_request($url, $header);
	parse_str($response);
	$response = _emh_linkedin_parse_fields($response);
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

function _emh_linkedin_http_request($url, $header, $body = NULL) {

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

function _emh_linkedin_parse_fields($contents) {
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