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


function emindhub_form_alter(&$form, &$form_state, $form_id) {

  echo '<pre>' . print_r($form_id, TRUE) . '</pre>';
  // echo '<pre>' . print_r(element_children($form), TRUE) . '</pre>';

  $form['actions']['#prefix'] = '<div class="form-row">';
  $form['actions']['#prefix'] .= '<div class="form-actions">';

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
	) as $action ) {
	  $form['actions'][$action]['#weight'] = $i++;
	}

  // Actions classes
  if ($form_id != 'search_block_form') {
    $form['actions']['cancel']['#attributes']['class'][] = 'btn-default';
    $form['actions']['delete']['#attributes']['class'][] = 'btn-danger';
    $form['actions']['preview_changes']['#attributes']['class'][] = 'btn-primary';
    $form['actions']['draft']['#attributes']['class'][] = 'btn-primary';
    $form['actions']['preview']['#attributes']['class'][] = 'btn-primary';
    $form['actions']['submit']['#attributes']['class'] = array('btn-submit');
  }

  $form['actions']['#suffix'] = '</div> <!-- END .form-actions -->';

  // Add required legend if minimum one field is required
  if ( emindhub_form_has_required($form) == TRUE ) {
  	$form['actions']['#suffix'] .= '
  		<div class="form-mandatory">
  			<span class="form-required">*</span>&nbsp;' . t('Required fields') . '
  		</div> <!-- END .form-mandatory -->';
  }
  $form['actions']['#suffix'] .= '</div> <!-- END .row -->';


  // Hide "Show row weights" for regular users
  global $user;
  if (!(in_array('webmaster', $user->roles) || in_array('administrator', $user->roles) )) {
  	$form['#attached']['js'] = array(
  	  drupal_get_path('theme', 'emindhub') . '/js/disable_show_row_weights.js',
  	);
  }

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';

}


function emindhub_form_user_profile_form_alter(&$form, &$form_state, $form_id) {

  // echo '<pre>' . print_r($form['field_needs_for_expertise']['#attributes'], TRUE) . '</pre>';

  $element_info = element_info('password_confirm');
  $process = $element_info['#process'];
  $process[] = 'emindhub_form_process_password_confirm';
  $form['account']['pass']['#process'] = $process;

  // Add class to fieldset
  // $form['#groups']['group_complement']->format_settings['instance_settings']['classes'] .= ' form-group-2col';

  // Profile
  $form['field_first_name']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_last_name']['#suffix'] = '</div>';

  $form['account']['name']['#prefix'] = '<div class="form-group-2col row">';
  $form['account']['mail']['#weight'] = -9;
  $form['account']['mail']['#suffix'] = '</div>';

  unset($form['account']['current_pass']);
  unset($form['account']['current_pass_required_values']);
  $form['#validate'] = array_diff($form['#validate'], array('user_validate_current_pass'));

  // Contact
  $form['field_address']['und'][0]['#type'] = 'div';
  $form['field_address']['und'][0]['street_block']['thoroughfare']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_address']['und'][0]['street_block']['premise']['#suffix'] = '</div>';

  $form['field_address']['und'][0]['locality_block']['postal_code']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_address']['und'][0]['locality_block']['locality']['#suffix'] = '</div>';

  $form['field_telephone']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_link_to_my_blog']['#suffix'] = '</div>';

  // Organisation
  $form['field_position']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_working_status']['#suffix'] = '</div>';

  // Needs
  $form['field_needs_for_expertise']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_needs_for_expertise']['und']['#title'] = $form['field_needs_for_expertise']['und']['#title'] . ' ' . t('(choose one or several fields)');
  $form['field_specific_skills3']['und']['#title'] = $form['field_specific_skills3']['und']['#title'] . ' ' . t('(using keywords or tags)');
  $form['field_specific_skills3']['#suffix'] = '</div>';

  // Skills & background
  $form['field_titre_metier']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_domaine']['#suffix'] = '</div>';

  // Sponsorship
  $form['field_sponsorship']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_sponsor1']['#suffix'] = '</div>';

  // Complement
  $form['field_notification_frequency']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_known_specific']['#suffix'] = '</div>';

  $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';

  // FIXME : fait buguer la prévisualisation des portraits
  // $form['field_photo']['und'][0]['#process'][] = 'emindhub_my_file_element_process';
  $form['field_cv']['und'][0]['#process'][] = 'emindhub_my_file_element_process';

  // echo '<pre>' . print_r($form['account'], TRUE) . '</pre>';
  // echo '<pre>' . print_r($form['field_cv'], TRUE) . '</pre>';
  // echo '<pre>' . print_r($form['field_notification_frequency'], TRUE) . '</pre>';
  // echo '<pre>' . print_r($form['field_needs_for_expertise']['und']['#title'], TRUE) . '</pre>';

}


function emindhub_form_process_password_confirm($element) {

  // echo '<pre>' . print_r($element, TRUE) . '</pre>';
  $element['pass1']['#title'] = t('New password');
  $element['pass2']['#title'] = t('Confirm new password');
  return $element;

}


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
  $form['hybridauth']['#weight'] = 9;

  $markup = l(t('Forgot your password?'), 'user/password', array('attributes' => array('title' => t('Request new password via e-mail.'))));
  $markup = '<ul class="login-links">' . $markup . '</ul>';
  $form['links']['#markup'] = $markup;
  $form['links']['#weight'] = 10;

}

// Check if form and fields are required
// https://www.drupal.org/node/72197#comment-6000064
function emindhub_form_has_required($form) {
  if (isset($form['#required']) && $form['#required']) {
	   return TRUE;
  }
  foreach (element_children($form) as $key) {
  	if (emindhub_form_has_required($form[$key])) {
  	  return TRUE;
  	}
  }
}


/**
* hook_form_FORM_ID_alter
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

  $form['#theme_wrappers'] = array();

  // echo '<pre>' . print_r($form['search_block_form'], TRUE) . '</pre>'; die;

}


function emindhub_form_user_register_form_alter(&$form, &$form_state, $form_id) {

  $form['emh_baseline'] = array(
    '#markup' => '<p class="emh-title-baseline">' . sprintf(t('Create your account %sfor free in no time%s'), '<strong>', '</strong>') . '</p>',
    '#weight' => '-1000', // First !
  );

  /*$form['emh_content'] = array(
    '#markup' => '<p>' . t('You can directly login with your LinkedIn account or complete the form below to create your account.') . '</p>',
    '#weight' => '-999',
  );*/

  // Add class before & after fields
  $form['field_first_name']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_last_name']['#suffix'] = '</div>';

  $form['account']['name']['#prefix'] = '<div class="form-group-2col row">';
  $form['account']['current_pass']['#suffix'] = '</div>';

  $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';
}


function emindhub_form_comment_form_alter(&$form, &$form_state, $form_id) {

  $form['author']['#access'] = 0;
  $form['subject']['#access'] = 0;

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';

  return $form;

}


function emindhub_views_bulk_operations_form_alter(&$form) {
  // Only when we want it.
  $view = arg(2);
  if (!empty($view) && ($view == 'answers' || $view == 'webform-answers')) {
    $form['select']['action::emh_points_arrange_node_points']['#attributes']['class'][] = 'btn-submit';
  }
}
