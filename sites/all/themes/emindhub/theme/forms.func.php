<?php


function emindhub_process_format($element) {
	// array of field names to restrict (add more here as needed)
	$fields = array(
		'body',
		'field_textarea',
		'comment_body',
	);

	$element = filter_process_format($element);

	// Hide the 'text format' pane below certain text area fields.
	if (isset($element['#field_name']) && in_array($element['#field_name'], $fields)){
		$element['format']['#access'] = FALSE;
	}
	return $element;
}


/**
 * Implements hook_form_alter().
 */
function emindhub_form_alter(&$form, &$form_state, $form_id) {

  // echo '<pre>' . print_r($form_id, TRUE) . '</pre>';
  // echo '<pre>' . print_r(element_children($form), TRUE) . '</pre>';

	if (!empty($form['actions'])) {

		// Actions order
	  $i = 0;
	  foreach (
		array(
		  'cancel',
		  'delete',
		  'preview_changes',
		  'draft',
		  'preview',
		  'submit',
			'save',
		  'publish',
		) as $action ) {
			if (!empty($form['actions'][$action])) {
				$form['actions'][$action]['#weight'] = $i++;
			}
		}

		// Bootstrap buttons group
		$secondary_actions = array(
		  'cancel'	=> array(),
		  'delete'	=> array(),
		);
		emindhub_beautiful_form_actions($form, $secondary_actions, 'secondary');
		$primary_actions = array(
			'preview_changes'	=> array(),
		  'draft'						=> array(),
		  'preview'					=> array(),
		  'submit'					=> array(),
			'save'						=> array(),
		  'publish'					=> array(),
		);
		emindhub_beautiful_form_actions($form, $primary_actions);

	}

  // Add required legend if minimum one field is required
  if (emindhub_form_has_required($form, $form_id)) {
  	$form['actions']['#suffix'] = '
  		<div class="form-mandatory">
  			<span class="form-required">*</span>&nbsp;' . t('Required fields') . '
  		</div> <!-- END .form-mandatory -->';
  }


  // Hide "Show row weights" for regular users
  global $user;
  if (!(in_array('webmaster', $user->roles) || in_array('administrator', $user->roles) )) {
  	$form['#attached']['js'] = array(
  	  drupal_get_path('theme', 'emindhub') . '/js/disable_show_row_weights.js',
  	);
  }

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';

}


/**
 * Implements hook_form_alter().
 */
function emindhub_form_user_profile_form_alter(&$form, &$form_state, $form_id) {

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';

  $element_info = element_info('password_confirm');
  $process = $element_info['#process'];
  $process[] = 'emindhub_form_process_password_confirm';
  $form['account']['pass']['#process'] = $process;

  // Add class to fieldset
  // $form['#groups']['group_complement']->format_settings['instance_settings']['classes'] .= ' form-group-2col';

  // Profile
  $form['field_first_name']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_last_name']['#suffix'] = '</div>';

	// Reduce email description for better Bootstrap display (tooltip)
  $form['account']['mail']['#description'] = t('All e-mails from the system will be sent to this address. The e-mail address will only be used if you wish to receive a new password or certain news or notifications by e-mail.');

  // Contact
  $form['field_address'][LANGUAGE_NONE][0]['#type'] = 'div';
  $form['field_address'][LANGUAGE_NONE][0]['street_block']['thoroughfare']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_address'][LANGUAGE_NONE][0]['street_block']['premise']['#suffix'] = '</div>';

  $form['field_address'][LANGUAGE_NONE][0]['locality_block']['postal_code']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_address'][LANGUAGE_NONE][0]['locality_block']['locality']['#suffix'] = '</div>';

  $form['field_telephone']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_link_to_my_blog']['#suffix'] = '</div>';

  // Organisation
  $form['field_position']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_working_status']['#suffix'] = '</div>';

  // Needs
  $form['field_needs_for_expertise']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_needs_for_expertise'][LANGUAGE_NONE]['#title'] = $form['field_needs_for_expertise'][LANGUAGE_NONE]['#title'] . ' ' . t('(choose one or several fields)');
  $form['field_specific_skills3'][LANGUAGE_NONE]['#title'] = $form['field_specific_skills3'][LANGUAGE_NONE]['#title'] . ' ' . t('(using keywords or tags)');
  $form['field_specific_skills3']['#suffix'] = '</div>';

  // Skills & background
  $form['field_titre_metier']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_domaine']['#suffix'] = '</div>';

  // Sponsorship
  $form['field_sponsorship']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_sponsor1']['#suffix'] = '</div>';

  // Complement
  $form['field_notification_frequency']['#prefix'] = '<div class="form-group-2col row">';
	if (user_access('create question1 content') || user_access('create webform content') || user_access('create challenge content')) {
		$form['field_notification_frequency'][LANGUAGE_NONE]['#description'] = t('How often do you want to receive eMindHub\'s notifications about new answers to your requests ?');
	}
	if (user_access('question1: comment on any question1 content') || user_access('edit own webform submissions') || user_access('challenge: comment on any challenge content')) {
		$form['field_notification_frequency'][LANGUAGE_NONE]['#description'] = t('How often do you want to receive eMindHub\'s notifications about new requests ?');
	}
  $form['field_known_specific']['#suffix'] = '</div>';

  $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';

  // FIXME : fait buguer la prévisualisation des portraits
  // $form['field_photo'][LANGUAGE_NONE][0]['#process'][] = 'emindhub_my_file_element_process';
  $form['field_cv'][LANGUAGE_NONE][0]['#process'][] = 'emindhub_my_file_element_process';

}


function emindhub_form_process_password_confirm($element) {

  // echo '<pre>' . print_r($element, TRUE) . '</pre>';
  $element['pass1']['#title'] = t('New password');
  $element['pass2']['#title'] = t('Confirm new password');
  return $element;

}


/**
 * Implements hook_form_alter().
 */
function emindhub_form_emh_profile_complete_get_required_empty_profile_form_alter(&$form, &$form_state, $form_id) {

	$form['field_entreprise']['#prefix'] = '<div class="form-group-3col row">';
	$form['field_entreprise']['#weight'] = '1';
	$form['field_working_status']['#weight'] = '2';
	$form['field_domaine']['#weight'] = '3';
	$form['field_domaine']['#suffix'] = '</div>';

	$form['actions']['#weight'] = '100';
	$form['actions']['submit']['#attributes']['class'][] = 'btn-asphalt';
	$form['actions']['#suffix'] = '';

}


/**
 * Implements hook_form_alter().
 */
function emindhub_form_lang_dropdown_form_alter(&$form, &$form_state, $form_id) {

  $form['#attributes']['class'][] = 'navbar-form';
  $form['#attributes']['class'][] = 'navbar-right';

}


function emindhub_form_user_login_block_alter(&$form, &$form_state, $form_id) {

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';

  $form['name']['#size'] = 30;
  $form['name']['#title_display'] = 'invisible';
  $form['name']['#attributes']['placeholder'] = t('Email');

  $form['pass']['#size'] = 30;
  $form['pass']['#title_display'] = 'invisible';
  $form['pass']['#attributes']['placeholder'] = $form['pass']['#title'];

  $form['actions']['#weight'] = 8;

  // $form['linkedin_auth_links']['#weight'] = 9;
  $form['hybridauth']['#weight'] = 10;

  $markup = l(t('Forgot your password?'), 'user/password', array('attributes' => array('title' => t('Request new password via e-mail.'))));
  $markup = '<ul class="login-links">' . $markup . '</ul>';
  $form['links']['#markup'] = $markup;
  $form['links']['#weight'] = 9;

}

// Check if form and fields are required
// https://www.drupal.org/node/72197#comment-6000064
function emindhub_form_has_required($form, $form_id) {

	if ($form_id != 'user_login_block') {
		if (!empty($form['#required'])) {
		  return TRUE;
	  }
	  foreach (element_children($form) as $key) {
	  	if (emindhub_form_has_required($form[$key], $form_id)) {
	  	  return TRUE;
	  	}
	  }
	}

}


/**
 * Implements hook_form_alter().
 */
function emindhub_form_search_block_form_alter(&$form, &$form_state, $form_id) {

  $form['search_block_form']['#title'] = t('Search'); // Change the text on the label element
  $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibility
  $form['search_block_form']['#size'] = 40;  // define size of the textfield

  // Add extra attributes to the text box
  $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search';}";
  $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == 'Search') {this.value = '';}";
  // Prevent user from searching the default text
  $form['search_block_form']['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search'){ alert('Please enter a search'); return false; }";

  // Alternative (HTML5) placeholder attribute instead of using the javascript
  $form['search_block_form']['#attributes']['placeholder'] = t('Type your search, keywords...');

  // echo '<pre>' . print_r($form['search_block_form'], TRUE) . '</pre>'; die;

}


/**
 * Implements hook_form_alter().
 */
function emindhub_form_user_register_form_alter(&$form, &$form_state, $form_id) {

  $form['emh_baseline'] = array(
    '#markup' => '<p class="emh-title-baseline">' . sprintf(t('Create your account %sfor free in no time%s'), '<strong>', '</strong>') . '</p>',
    '#weight' => '-1000', // First !
  );

  $form['emh_content'] = array(
    '#markup' => '<p class="emh-title-baseline">' . t('You can directly login with your LinkedIn account or complete the form below to create your account.') . '</p>',
    '#weight' => '-999',
  );

  // Add class before & after fields
  $form['field_first_name']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_last_name']['#suffix'] = '</div>';

	// Reduce email description for better Bootstrap display (tooltip)
  $form['account']['mail']['#description'] = t('All e-mails from the system will be sent to this address. The e-mail address will only be used if you wish to receive a new password or certain news or notifications by e-mail.');

}

/**
 * Implementation of hook_element_info_alter().
 */
function emindhub_element_info_alter(&$type) {
	if (isset($type['password_confirm'])) {
		$type['password_confirm']['#process'][] = 'emindhub_process_password_confirm';
	}
}

/**
 * Function emindhub_process_password_confirm() for editing label.
 */
function emindhub_process_password_confirm($element) {
	if ($element['#array_parents'][0] == 'account') {
		$element['pass1']['#prefix'] = '<div class="form-group-2col row">';
		$element['pass2']['#suffix'] = '</div>';
	}
	return $element;
}


/**
 * Implements hook_form_alter().
 */
function emindhub_form_comment_form_alter(&$form, &$form_state, $form_id) {

  $form['author']['#access'] = 0;
  $form['subject']['#access'] = 0;

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';

  return $form;

}


/**
 * Implements hook_form_alter().
 */
function emindhub_views_bulk_operations_form_alter(&$form) {
  // Only when we want it.
  $view = arg(2);
  if (!empty($view) && ($view == 'answers' || $view == 'results')) {
    $form['select']['action::emh_points_arrange_node_points']['#attributes']['class'][] = 'btn-submit';
  }
}


/**
 * Implements hook_form_alter().
 */
function emindhub_form_emh_points_arrange_form_alter(&$form, &$form_state, $type_source) {
  $form['submit']['#attributes']['class'][] = 'btn-submit';
}


/**
 * Implements hook_form_alter().
 */
function emindhub_form_change_pwd_page_form_alter(&$form, &$form_state, $form_id) {

	// echo '<pre>' . print_r($form, TRUE) . '</pre>';

	$form['account']['pass']['#title'] = t('Enter your new password');

	$form['submit']['#value'] = t('Change my password');
	$form['submit']['#attributes']['class'][] = 'btn-submit';

	return $form;

}


/**
 * Implements hook_form_alter().
 * node/add/webform
 * node/$ID/edit
 */
function emindhub_form_webform_node_form_alter(&$form, &$form_state, $form_id) {

	// Add class before & after fields
  $form['field_duration_of_the_mission']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_start_date']['#suffix'] = '</div>';

  $form['field_document']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_image']['#suffix'] = '</div>';

  $form['field_domaine']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_tags']['#suffix'] = '</div>';

  $form['field_anonymous']['#prefix'] = '<div class="form-group-3col row">';
  $form['field_use_my_entreprise']['#suffix'] = '</div>';

  $form['field_expiration_date']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_reward']['#suffix'] = '</div>';

	// $webform = $form['#node'];
  // if (!empty($webform->nid)) {
  //   $form['actions']['goquestions']['#markup'] = t('<a href="@url" class="btn btn-default pull-right" id="edit-back">Questions <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span></a>', array('@url' => url('node/' . $webform->nid . '/webform')));
  // }

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';

}


/**
 * Implements hook_form_alter().
 * node/$ID/webform
 * node/$ID/webform/components
 */
function emindhub_form_webform_components_form_alter(&$form, &$form_state, $form_id) {

	// echo '<pre>' . print_r($form, TRUE) . '</pre>';
	// echo '<pre>' . print_r($form_state, TRUE) . '</pre>';

	// $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';

	// $webform_id = $form['#node']->nid;
	// $form['actions']['goback']['#markup'] = t('<a href="@url" class="btn btn-default pull-right" id="edit-back"><span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span> Edit</a>', array('@url' => url('node/' . $webform_id . '/edit')));

}


/**
 * Implements hook_form_alter().
 * node/add/challenge
 * node/$ID/edit
 */
function emindhub_form_challenge_node_form_alter(&$form, &$form_state, $form_id) {

	// echo '<pre>' . print_r($form, TRUE) . '</pre>';
	// echo '<pre>' . print_r($form_state, TRUE) . '</pre>';

	// Add class before & after fields
  $form['field_document']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_image']['#suffix'] = '</div>';

  $form['field_domaine']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_tags']['#suffix'] = '</div>';

  $form['field_anonymous']['#prefix'] = '<div class="form-group-3col row">';
  $form['field_use_my_entreprise']['#suffix'] = '</div>';

  $form['field_expiration_date']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_reward']['#suffix'] = '</div>';

}


/**
 * Implements hook_form_alter().
 * node/add/question1
 * node/$ID/edit
 */
function emindhub_form_question1_node_form_alter(&$form, &$form_state, $form_id) {

	// echo '<pre>' . print_r($form, TRUE) . '</pre>';
	// echo '<pre>' . print_r($form_state, TRUE) . '</pre>';

	// Add class before & after fields
  $form['field_domaine']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_tags']['#suffix'] = '</div>';

  $form['field_anonymous']['#prefix'] = '<div class="form-group-3col row">';
  $form['field_use_my_entreprise']['#suffix'] = '</div>';

  $form['field_expiration_date']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_reward']['#suffix'] = '</div>';

}
