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
 *
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function _emh_linkedin_get_profile_fields($uid, $fields = array()) {
	// Get sure library is loaded before doing anything.
	emh_linkedin_init ();
	
	$base_url = "https://api.linkedin.com/v1/people/";
	
	// $row = db_query("SELECT * FROM {linkedin_token} WHERE uid = :uid AND type = :type", array(':uid' => $uid, ':type' => 'access'))->fetchAssoc();
	$session = _hybridauth_session_load_by_uid ( $uid );
	$data_session = hybridauth_get_instance ()->getSessionData ();
	$data = unserialize ( $session ['data'] );
	
	$row = array (
			'token_key' => unserialize ( $data ['hauth_session.linkedin.token.access_token'] ),
			'token_secret' => unserialize ( $data ['hauth_session.linkedin.token.access_token_secret'] ) 
	);
	
	if (! $row || empty ( $row )) {
		// This account does not have any LinkedIn account associated with.
		$response = array (
				'status' => '401',
				'error-code' => 'custom',
				'message' => 'No LinkedIn account is associated with this user' 
		);
		if (variable_get ( 'linkedin_debug_mode', 0 ) == 1) {
			drupal_set_message ( t ( 'Linkedin debug 1 : @status : @message', array (
					'@status' => $response ['status'],
					'@message' => $response ['message'] 
			) ) );
		}
		return $response;
	}
	
	// $tokens = db_query("SELECT * FROM {linkedin_token} WHERE uid = :uid AND type = :type", array(':uid' => $user->uid, ':type' => 'access'))->fetchAssoc();
	$session = _hybridauth_session_load_by_uid ( $uid );
	$data = unserialize ( $session ['data'] );
	
	$tokens = array (
			'token_key' => unserialize ( $data ['hauth_session.linkedin.token.access_token'] ),
			'token_secret' => unserialize ( $data ['hauth_session.linkedin.token.access_token_secret'] ) 
	);
	
	if (! $tokens) {
		// We don't have any LinkedIn account associated with the user viewing the profile.
		// Make the request on the behalf on viewed user and switch to public profile.
		$tokens = $row;
		$append = '~:public';
		$type = 'public';
	} else {
		// Fetch profile. Fields returned will depend on the relationships between viewing/viewed users
		// $authname = db_query("SELECT authname FROM {authmap} WHERE uid = :uid AND module = :module", array(':uid' => $uid, ':module' => 'linkedin'))->fetchField();
		$identity = db_select ( 'hybridauth_identity', 'ha_id' )->fields ( 'ha_id' )->condition ( 'uid', $uid, '=' )->execute ()->fetchAssoc ();
		$authname = $identity ['provider_identifier'];
		
		$append = 'id=' . $authname;
		$type = 'auth';
	}
	
	$tokens = ( array ) $tokens;
	$append .= _emh_linkedin_build_fields_request ( $fields, $type );
	$url = $base_url . $append;
	$response = emh_linkedin_get_fields ( $url, $tokens );
	
	if (isset ( $response ['error'] ['status'] ) && ($response ['error'] ['status'] == 401 || $response ['error'] ['status'] == 403)) {
		// No relationships between users, switch back to public profile and retry
		
		$tokens = ( array ) $row;
		$append = '~:public';
		$append .= _emh_linkedin_build_fields_request ( $fields, 'public' );
		$url = $base_url . $append;
		$response = emh_linkedin_get_fields ( $url, $tokens );
	}
	if (isset ( $response ['person'] )) {
		$response = $response ['person'];
	} else {
		$response = $response ['error'];
	}
	if (variable_get ( 'linkedin_debug_mode', 0 ) == 1) {
		if (isset ( $response ['error-code'] )) {
			drupal_set_message ( t ( 'Linkedin debug 2 : LinkedIn.com answered "@status : @message', array (
					'@status' => $response ['status'],
					'@message' => $response ['message'] 
			) ) );
		}
	}
	return $response;
}

/**
 * List of LinkedIn fields to complet user profile
 * 
 * @return string[]
 */
function _emh_linkedin_fields_build_profile() {
	// Basic Profile LinkedIn Fields
	$fields = array (
			'first-name',
			'last-name',
			'location',
			'num-connections',
			'summary',
			'positions',
			'picture-url',
			'email-address',
			'public-profile-url',
			'headline' 
	);
	
	return $fields;
}
function _emh_linkedin_fields_user_update() {
	// Basic Profile LinkedIn Fields
	$fields = array (
			'location',
			'summary',
			'positions',
			'picture-url',
			'email-address',
			'public-profile-url',
			'headline' 
	);
	
	return $fields;
}
function _emh_linkedin_get_user_fields($user) {
	$user_fields = $user->data ['emh_linkedin_fields'];
	ddl ( $user_fields, 'user fields !!' );
	$fields = array ();
	foreach ( $user_fields as $key => $value ) {
		if ($value)
			$fields [] = $key;
	}
	
	return $fields;
}
function _emh_linkedin_fields_default_user_update() {
	// Basic Profile LinkedIn Fields
	$fields = array (
			'first-name',
			'last-name',
			'num-connections' 
	);
	
	return $fields;
}

/**
 * Return boolean if user can to update profile to linkedin.
 * 
 * @param unknown $user        	
 * @return unknown|boolean
 */
function _emh_linkedin_update_user($user) {
	if (isset ( $user->data ['emh_linkedin_update'] )) {
		return $user->data ['emh_linkedin_update'];
	}
	return FALSE;
}
function _emh_linkedin_fields_to_user_fields($field, $user) {
	if (isset ( $field ['value'] )) {
		$item = $field ['value'];
		
		switch ($field ['name']) {
			
			case 'location' :
				
				$country_code = strtoupper ( $item ['country'] ['code'] );
				$country = country_get_list () [$country_code];
				
				$city = $item ['name'];
				
				$city = substr ( $city, 0, strrpos ( $city, ',' ) );
				$city = substr ( $city, 0, strrpos ( $city, ' ' ) );
				
				if (empty ( $user->field_address )) {
					
					if (strcmp ( $country, $item ['name'] ) != 0) {
						$user->field_address ['und'] [0] ['locality'] = $city;
					}
					
					$user->field_address ['und'] [0] ['country'] = $country_code;
				} else {
					// maj
					if (strcmp ( $user->field_address ['und'] [0] ['locality'], $item ['name'] ) != 0) {
						if (strcmp ( $country, $item ['name'] ) != 0) {
							$user->field_address ['und'] [0] ['locality'] = $city;
						}
					}
					if (strcmp ( $user->field_address ['und'] [0] ['country'], $country_code ) != 0) {
						$user->field_address ['und'] [0] ['country'] = $country_code;
					}
				}
				break;
			
			case 'num-connections' :
				
				if (empty ( $user->field_nb_contacts_linkedin )) {
					$user->field_nb_contacts_linkedin ['und'] [0] ['value'] = $item;
				} else {
					// maj
					if (strcmp ( $user->field_nb_contacts_linkedin ['und'] [0] ['value'], $item ) != 0) {
						$user->field_nb_contacts_linkedin ['und'] [0] ['value'] = $item;
					}
				}
				break;
			
			case 'summary' :
				if (empty ( $user->field_employment_history )) {
					$user->field_employment_history ['und'] [0] ['value'] = $item;
				} else {
					// maj
					if (strcmp ( $user->field_employment_history ['und'] [0] ['value'], $item ) != 0) {
						$user->field_employment_history ['und'] [0] ['value'] = $item;
					}
				}
				break;
			
			case 'positions' :
				
				$multiple = false;
				// pour savoir si l'utilisateur a plusieurs "position"
				if (array_key_exists ( 0, $item ['position'] )) {
					$taille = count ( $item ['position'] );
					$multiple = true;
				} else {
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
				 * _emh_maj_position($user, $position,$i);
				 * }
				 */
				if ($multiple) {
					$position = $item ['position'] [0];
				} else {
					$position = $item ['position'];
				}
				
				$user = _emh_maj_position ( $user, $position, 0 );
				
				break;
			
			case 'picture-url' :
				
				// on télécharge maintenant l'image du profile linkdedin
				$nom_img = $user->name . ".jpg";
				$dir_name = "sites/default/files/linkedin_profile_image";
				$path = $dir_name . "/" . $nom_img;
				
				$drupal_uri = "public://linkedin_profile_image/" . $nom_img;
				
				// si le dossier n'existe pas, on le crée
				if (! is_dir ( $dir_name )) {
					mkdir ( $dir_name );
				}
				
				if (! file_exists ( $path )) {
					
					$url = $item;
					$fp = fopen ( $path, 'w' );
					
					$ch = curl_init ( $url );
					curl_setopt ( $ch, CURLOPT_FILE, $fp );
					$data = curl_exec ( $ch );
					$curl_errno = curl_errno ( $ch );
					$curl_error = curl_error ( $ch );
					curl_close ( $ch );
					fclose ( $fp );
					
					if ($curl_errno > 0) {
						unlink ( $path );
						watchdog ( 'emh_linkedin', "cURL Error ($curl_errno): $curl_error\n" );
					} else {
						
						if (file_exists ( $path )) {
							
							$handle = fopen ( $path, 'r' );
							$file = file_save_data ( $handle, $drupal_uri );
							$user->field_linkedin_image ['und'] [0] ['fid'] = $file->fid;
							fclose ( $handle );
						}
					}
				}
				break;
			
			case 'public-profile-url' :
				$profileURL = $item;
				
				if (empty ( $user->field_linkedin ['und'] [0] ['url'] )) {
					$user->field_linkedin ['und'] [0] ['url'] = $profileURL;
				} else {
					// maj
					if (strcmp ( $user->field_linkedin ['und'] [0] ['url'], $profileURL ) != 0) {
						$user->field_linkedin ['und'] [0] ['url'] = $profileURL;
					}
				}
				break;
			
			case 'headline' :
				
				if (empty ( $user->field_titre_metier ['und'] [0] ['value'] )) {
					$user->field_titre_metier ['und'] [0] ['value'] = $item;
				} else {
					// maj
					if (strcmp ( $user->field_titre_metier ['und'] [0] ['value'], $item ) != 0) {
						$user->field_titre_metier ['und'] [0] ['value'] = $item;
					}
				}
				break;
		}
	}
	
	return $user;
}
function _emh_maj_position($user, $position, $i) {
	
	// field_position
	$title = $position ['title'];
	
	if (! empty ( $title )) {
		
		$vocab = taxonomy_vocabulary_machine_name_load ( 'position' );
		
		if (empty ( $term = taxonomy_get_term_by_name ( $title, $vocab->machine_name ) )) {
			// add a new term
			$new_term = ( object ) array (
					'name' => $title,
					'description' => $title,
					'vid' => $vocab->vid 
			);
			
			taxonomy_term_save ( $new_term );
			$term = taxonomy_get_term_by_name ( $title, $vocab->machine_name );
		}
		// maj
		$term_tmp = $term;
		$term = array_shift ( $term_tmp );
		
		if (empty ( $user->field_position )) {
			$user->field_position ['und'] [$i] ['tid'] = $term->tid;
		} else {
			// maj
			if (strcmp ( $user->field_position ['und'] [$i] ['tid'], $term->tid ) != 0) {
				$user->field_position ['und'] [$i] ['tid'] = $term->tid;
			}
		}
	}
	
	// field_entreprise
	$company_name = $position ['company'] ['name'];
	$node_name = 'corporate';
	
	if (! empty ( $company_name )) {
		
		$company_name = emh_suppr_accents ( $company_name, 'ISO-8859-1' );
		
		$query = new EntityFieldQuery ();
		$query->entityCondition ( 'entity_type', 'node' )->entityCondition ( 'bundle', $node_name )->propertyCondition ( 'title', $company_name, 'like' );
		$result = $query->execute ();
		
		if (isset ( $result ['node'] )) {
			$company = array_shift ( $result ['node'] );
		} else {
			// add a new company
			$company = new stdClass ();
			$company->title = $position ['company'] ['name'];
			$company->type = "corporate";
			node_object_prepare ( $company ); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
			$company->language = 'und'; // Or e.g. 'en' if locale is enabled
			$company->uid = $user->uid;
			$company->status = 1; // (1 or 0): published or not
			$company->promote = 1; // (1 or 0): promoted to front page
			$company->comment = 0; // 0 = comments disabled, 1 = read only, 2 = read/write
			
			$company = node_submit ( $company ); // Prepare node for saving
			node_save ( $company );
		}
		
		if (empty ( $user->field_entreprise )) {
			$user->field_entreprise ['und'] [$i] ['target_id'] = $company->nid;
		} else {
			// maj
			if (strcmp ( $user->field_entreprise ['und'] [$i] ['target_id'], $company->nid ) != 0) {
				$user->field_entreprise ['und'] [$i] ['target_id'] = $company->nid;
			}
		}
	}
	
	// field_description_actiities
	if (empty ( $user->field_description_activities )) {
		if (isset ( $position ['summary'] )) {
			$user->field_description_activities ['und'] [$i] ['value'] = $position ['summary'];
		}
	} else {
		// maj
		if (strcmp ( $user->field_description_activities ['und'] [$i] ['value'], $position ['summary'] ) != 0) {
			if (isset ( $position ['summary'] )) {
				$user->field_description_activities ['und'] [$i] ['value'] = $position ['summary'];
			}
		}
	}
	return $user;
}

/*
 * Provides a list of available LinkedIn fields
 * $type : 'public' or 'auth'. Wether we need 'public' or 'standard' fields
 */
function _emh_linkedin_list_fields($type = 'auth') {
	$fields = array (
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
			'current-share' 
		// @TODO // 'site-standard-profile-request', // 'api-standard-profile-request', // 'api-public-profile-request', Deprecated ? // 'site-public-profile-request', Deprecated ? // 'member-url', // Deprecated ?
	);
	if ($type == 'auth') {
		$standard_fields = array (
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
				'main-address' 
			// @TODO // 'relation-to-viewer', // 'proposal-comments', // 'recommendations-received',
		);
		$fields = array_merge ( $fields, $standard_fields );
	}
	return $fields;
}

/*
 * Filter the requested fields to match the type of profile (public or auth)
 */
function _emh_linkedin_build_fields_request($fields, $type = 'auth') {
	if (! empty ( $fields ) || is_array ( $fields )) {
		$fieldslist = _emh_linkedin_list_fields ( $type );
		$requested = '';
		foreach ( $fields as $field ) {
			if (in_array ( $field, $fieldslist )) {
				$requested .= $field . ',';
			}
		}
		$request = ':(' . trim ( $requested, ',' ) . ')';
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
 *
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function _emh_linkedin_get_fields($url, $tokens) {
	// Get sure library is loaded before doing anything.
	emh_linkedin_init ();
	
	$signature = new OAuthSignatureMethod_HMAC_SHA1 ();
	// on recupère la key et key secret du module hybridauth pour l'api linkedin
	$consumer_key = variable_get ( 'hybridauth_provider_LinkedIn_keys_key', '' );
	$consumer_secret = variable_get ( 'hybridauth_provider_LinkedIn_keys_secret', '' );
	$consumer = new OAuthConsumer ( $consumer_key, $consumer_secret, NULL );
	$token = new OAuthConsumer ( $tokens ['token_key'], $tokens ['token_secret'], 1 );
	$request = OAuthRequest::from_consumer_and_token ( $consumer, $token, "GET", $url );
	$request->sign_request ( $signature, $consumer, $token );
	$header = $request->to_header ( "https://api.linkedin.com" );
	$response = _emh_linkedin_http_request ( $url, $header );
	parse_str ( $response );
	$response = _emh_linkedin_parse_fields ( $response );
	if (isset ( $response ['error-code'] )) {
		$message = t ( 'Linkedin debug 3 : LinkedIn.com answered "@status : @message', array (
				'@status' => $response ['status'],
				'@message' => $response ['message'] 
		) );
		if (variable_get ( 'linkedin_debug_mode', 0 ) == 1) {
			drupal_set_message ( $message, 'warning' );
		}
		watchdog ( 'warning', $message );
	}
	return $response;
}

/*
 * Some internal helper functions...
 */
function _emh_linkedin_http_request($url, $header, $body = NULL) {
	$ch = curl_init ();
	
	curl_setopt ( $ch, CURLOPT_RETURNTRANSFER, 1 );
	curl_setopt ( $ch, CURLOPT_SSL_VERIFYPEER, 1 );
	curl_setopt ( $ch, CURLOPT_HTTPHEADER, array (
			$header 
	) );
	curl_setopt ( $ch, CURLOPT_URL, $url );
	
	if ($body) {
		curl_setopt ( $ch, CURLOPT_POST, 1 );
		if ($body == 'token_request') {
			curl_setopt ( $ch, CURLOPT_POSTFIELDS, '' );
		} else {
			curl_setopt ( $ch, CURLOPT_POSTFIELDS, $body );
			curl_setopt ( $ch, CURLOPT_HTTPHEADER, array (
					$header,
					'Content-Type: text/xml;charset=utf-8' 
			) );
			curl_setopt ( $ch, CURLOPT_POST, 1 );
			curl_setopt ( $ch, CURLOPT_CUSTOMREQUEST, 'POST' );
		}
	}
	
	$output = curl_exec ( $ch );
	curl_close ( $ch );
	return $output;
}

/*
 * Parser function. Based on xml2array() by Binny V A : http://www.bin-co.com/php/scripts/xml2array/
 */
function _emh_linkedin_parse_fields($contents) {
	if (! $contents) {
		return array ();
	}
	
	if (! function_exists ( 'xml_parser_create' )) { // Get the XML parser of PHP - PHP must have this module for the parser to work
		if (variable_get ( 'linkedin_debug_mode', 0 ) == 1) {
			drupal_set_message ( t ( 'Unable to find PHP parser. This module needs php-xml lib' ), 'warning' );
		}
		return array ();
	}
	
	$parser = xml_parser_create ( '' );
	xml_parser_set_option ( $parser, XML_OPTION_TARGET_ENCODING, "UTF-8" ); // http://minutillo.com/steve/weblog/2004/6/17/php-xml-and-character-encodings-a-tale-of-sadness-rage-and-data-loss
	xml_parser_set_option ( $parser, XML_OPTION_CASE_FOLDING, 0 );
	xml_parser_set_option ( $parser, XML_OPTION_SKIP_WHITE, 1 );
	xml_parse_into_struct ( $parser, trim ( $contents ), $xml_values );
	xml_parser_free ( $parser );
	
	if (! $xml_values) {
		return;
	}
	$xml_array = array ();
	$parents = array ();
	$opened_tags = array ();
	$arr = array ();
	
	$current = &$xml_array; // Reference
	                        // Go through the tags.
	$repeated_tag_index = array (); // Multiple tags with same name will be turned into an array
	foreach ( $xml_values as $data ) {
		unset ( $attributes, $value ); // Remove existing values, or there will be trouble
		                            // This command will extract these variables into the foreach scope
		                            // tag(string), type(string), level(int), attributes(array).
		extract ( $data ); // We could use the array by itself, but this cooler.
		
		$result = array ();
		$attributes_data = array ();
		
		if (isset ( $value )) {
			$result = $value;
		}
		// See tag status and do the needed.
		if ($type == "open") { // The starting of the tag '<tag>'
			$parent [$level - 1] = &$current;
			if (! is_array ( $current ) or (! in_array ( $tag, array_keys ( $current ) ))) { // Insert New tag
				$current [$tag] = $result;
				if ($attributes_data) {
					$current [$tag . '_attr'] = $attributes_data;
				}
				$repeated_tag_index [$tag . '_' . $level] = 1;
				
				$current = &$current [$tag];
			} else { // There was another element with the same tag name
				if (isset ( $current [$tag] [0] )) { // If there is a 0th element it is already an array
					$current [$tag] [$repeated_tag_index [$tag . '_' . $level]] = $result;
					$repeated_tag_index [$tag . '_' . $level] ++;
				} else { // This section will make the value an array if multiple tags with the same name appear together
					$current [$tag] = array (
							$current [$tag],
							$result 
					); // This will combine the existing item and the new item together to make an array
					$repeated_tag_index [$tag . '_' . $level] = 2;
					
					if (isset ( $current [$tag . '_attr'] )) { // The attribute of the last(0th) tag must be moved as well
						$current [$tag] ['0_attr'] = $current [$tag . '_attr'];
						unset ( $current [$tag . '_attr'] );
					}
				}
				$last_item_index = $repeated_tag_index [$tag . '_' . $level] - 1;
				$current = &$current [$tag] [$last_item_index];
			}
		} elseif ($type == "complete") { // Tags that ends in 1 line '<tag />'
		                               // See if the key is already taken.
			if (! isset ( $current [$tag] )) { // New Key
				$current [$tag] = $result;
				$repeated_tag_index [$tag . '_' . $level] = 1;
				if ($attributes_data) {
					$current [$tag . '_attr'] = $attributes_data;
				}
			} else { // If taken, put all things inside a list(array)
				if (isset ( $current [$tag] [0] ) && is_array ( $current [$tag] )) { // If it is already an array...
				                                                            // ...push the new element into that array.
					$current [$tag] [$repeated_tag_index [$tag . '_' . $level]] = $result;
					
					$repeated_tag_index [$tag . '_' . $level] ++;
				} else { // If it is not an array...
					$current [$tag] = array (
							$current [$tag],
							$result 
					); // ...Make it an array using using the existing value and the new value
					$repeated_tag_index [$tag . '_' . $level] = 2; // 0 and 1 index is already taken
				}
			}
		} elseif ($type == 'close') { // End of tag '</tag>'
			$current = &$parent [$level - 1];
		}
	}
	
	return ($xml_array);
}

/*
function emh_linkedin_access_token($account) {
	//Get sure library is loaded before doing anything.
	emh_linkedin_init();
	
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
	$consumer_key = variable_get('hybridauth_provider_LinkedIn_keys_key', '');
	$consumer_secret = variable_get('hybridauth_provider_LinkedIn_keys_secret', '');
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
}*/