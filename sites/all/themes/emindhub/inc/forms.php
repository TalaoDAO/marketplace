<?php

// LTH : add bootstrap class to field markup
function emindhub_form_element($variables) {
  $element = &$variables ['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
	  '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element ['#markup']) && !empty($element ['#id'])) {
	  $attributes ['id'] = $element ['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  // $attributes ['class'] = array('form-item');
  $attributes ['class'] = array('form-group');
  if (!empty($element ['#type'])) {
	  $attributes ['class'][] = 'form-type-' . strtr($element ['#type'], '_', '-');
  }
  if (!empty($element ['#name'])) {
	  $attributes ['class'][] = 'form-item-' . strtr($element ['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element ['#attributes']['disabled'])) {
	  $attributes ['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element ['#title'])) {
	  $element ['#title_display'] = 'none';
  }
  $prefix = isset($element ['#field_prefix']) ? '<span class="field-prefix">' . $element ['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element ['#field_suffix']) ? ' <span class="field-suffix">' . $element ['#field_suffix'] . '</span>' : '';

  $description = '';
  if (!empty($element ['#description'])) {
  	// LTH : use Bootstrap badge + tooltip for field description
  	// $description .= $element ["#description"];
  	$description .= '<span class="badge help-tip" data-toggle="tooltip" data-placement="bottom" data-html="true" title="' . $element ["#description"] . '">?</span>';
  }

  switch ($element ['#title_display']) {
	case 'before':
	case 'invisible':
	  $output .= ' ' . theme('form_element_label', $variables);
	  $output .= ' ' . $description; // LTH
	  $output .= ' ' . $prefix . $element ['#children'] . $suffix . "\n";
	  break;

	case 'after':
	  $output .= ' ' . $prefix . $element ['#children'] . $suffix;
	  $output .= ' ' . theme('form_element_label', $variables) . "\n";
	  $output .= ' ' . $description; // LTH
	  break;

	case 'none':
	case 'attribute':
	  // Output no label and no required marker, only the children.
	  $output .= ' ' . $description; // LTH
	  $output .= ' ' . $prefix . $element ['#children'] . $suffix . "\n";
	  break;
  }

  $output .= "</div>\n";

  return $output;
}

// Cacher les icônes de mise en page + types de format, peut-être trop ??
function emindhub_element_info_alter(&$type) {
  if (!isAdminUser()) {
  	if (isset($type['text_format']['#process'])) {
  		foreach ($type['text_format']['#process'] as &$callback) {
  			if ($callback === 'filter_process_format') {
  				$callback = 'emindhub_process_format';
  			}
  		}
  	}
  }
}



function emindhub_date_combo($variables) {
  // Retourne le champ date de manière simplifiée
  return theme('form_element', $variables);
}


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

  // echo '<pre>' . print_r($form, TRUE) . '</pre>'; die;
  // echo '<pre>' . print_r(element_children($form), TRUE) . '</pre>';

  // $form['body']['und'][0]['#format'] = '<div class="form-row">';
  // $form['body']['und'][0]['#format']['format']['#access'] = FALSE;
  // $form[LANGUAGE_NONE][0]['format']['format']['#access'] = FALSE;

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


function emindhub_form_contact_site_form_alter(&$form, &$form_state, $form_id) {

  $form['emh_baseline'] = array(
    '#markup' => '<p class="emh-title-baseline">' . c_szHaveQuestion . '<br />' . c_szLearnMore . '<br /><strong>' . c_szLeaveMsg . '</strong></p>',
    '#weight' => '-1000', // First !
  );

  $form['civility']['#title_display'] = "invisible";
  $form['civility']['#attributes']['placeholder'] = $form['civility']['#title'];

  $form['lastname']['#title_display'] = "invisible";
  $form['lastname']['#attributes']['placeholder'] = $form['lastname']['#title'];

  $form['firstname']['#title_display'] = "invisible";
  $form['firstname']['#attributes']['placeholder'] = $form['firstname']['#title'];

  $form['entreprise']['#title_display'] = "invisible";
  $form['entreprise']['#attributes']['placeholder'] = $form['entreprise']['#title'];

  $form['phone']['#title_display'] = "invisible";
  $form['phone']['#attributes']['placeholder'] = $form['phone']['#title'];

  $form['mail']['#title_display'] = "invisible";
  $form['mail']['#attributes']['placeholder'] = $form['mail']['#title'];

  $form['message']['#title_display'] = "invisible";
  $form['message']['#attributes']['placeholder'] = $form['message']['#title'];

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';
}


function emindhub_form_user_profile_form_alter(&$form, &$form_state, $form_id) {

  $element_info = element_info('password_confirm');
  $process = $element_info['#process'];
  $process[] = 'emindhub_form_process_password_confirm';
  $form['account']['pass']['#process'] = $process;

  // Add class to fieldset
  // $form['#groups']['group_complement']->format_settings['instance_settings']['classes'] .= ' form-group-2col';

  // Add class before & after fields
  $form['field_first_name']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_last_name']['#suffix'] = '</div>';

  $form['account']['name']['#prefix'] = '<div class="form-group-2col row">';
  $form['account']['current_pass']['#suffix'] = '</div>';

  $form['field_address']['und'][0]['street_block']['thoroughfare']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_address']['und'][0]['street_block']['premise']['#suffix'] = '</div>';

  $form['field_address']['und'][0]['locality_block']['postal_code']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_address']['und'][0]['locality_block']['locality']['#suffix'] = '</div>';

  // $form['field_address']['thoroughfare']['#prefix'] = '<div class="form-group-2col row">';
  // $form['field_address']['premise']['#suffix'] = '</div>';

  $form['field_working_status']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_position']['#suffix'] = '</div>';

  $form['field_employment_history']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_other_areas']['#suffix'] = '</div>';

  $form['field_sponsorship']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_sponsor1']['#suffix'] = '</div>';

  $form['field_titre_metier']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_domaine']['#suffix'] = '</div>';

  $form['field_notification_frequency']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_known_specific']['#suffix'] = '</div>';

  $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';

  $form['field_photo']['und'][0]['#process'][] = 'emindhub_my_file_element_process';
  $form['field_cv']['und'][0]['#process'][] = 'emindhub_my_file_element_process';

  // echo '<pre>' . print_r($form['field_cv'], TRUE) . '</pre>';
  // echo '<pre>' . print_r($form['field_notification_frequency'], TRUE) . '</pre>';

}

function emindhub_my_file_element_process(&$element, &$form_state, $form) {
  $element = file_managed_file_process($element, $form_state, $form);

  $element['upload_button']['#attributes']['class'][] = 'btn-info';
  // $element['upload_button']['#access'] = FALSE;
  // echo '<pre>' . print_r($element, TRUE) . '</pre>';
  return $element;
}

function emindhub_form_process_password_confirm($element) {

  $element['pass1']['#title'] = t('New password');
  $element['pass2']['#title'] = t('Confirm password');
  return $element;

}


function emindhub_form_lang_dropdown_form_alter(&$form, &$form_state, $form_id) {

  $form['#attributes']['class'][] = 'navbar-form';
  $form['#attributes']['class'][] = 'navbar-right';

}


function emindhub_form_user_login_block_alter(&$form, &$form_state, $form_id) {

  // echo '<pre>' . print_r($form['actions']['#prefix'], TRUE) . '</pre>';
  // $form['actions']['#prefix'] = '';

  $form['name']['#size'] = 30;
  $form['name']['#title_display'] = 'invisible';
  $form['name']['#attributes']['placeholder'] = t('Email');

  $form['pass']['#size'] = 30;
  $form['pass']['#title_display'] = 'invisible';
  $form['pass']['#attributes']['placeholder'] = $form['pass']['#title'];

  $form['actions']['#weight'] = 9;

  $markup = l(t('Forgot your password?'), 'user/password', array('attributes' => array('title' => t('Request new password via e-mail.'))));

  $markup = '<div class="clearfix login-links">' . $markup . '</div>';
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

  // $form['actions']['#attributes']['class'][] = 'element-invisible';

  // $form['search_block_form']['#attributes']['class'][] = 'navbar-form';
  // $form['search_block_form']['#attributes']['class'][] = 'navbar-left';

  $form['search_block_form']['#title'] = c_szSearch; // Change the text on the label element
  $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibility
  $form['search_block_form']['#size'] = 40;  // define size of the textfield
  // $form['actions']['submit']['#value'] = c_szGo; // Change the text on the submit button
  // $form['actions']['submit']['#attributes']['class'][] = 'element-invisible';

  // Add extra attributes to the text box
  // $form['search_block_form']['#attributes']['class'] = array('search-input', 'form-control');
  $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search';}";
  $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == 'Search') {this.value = '';}";
  // Prevent user from searching the default text
  $form['search_block_form']['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search'){ alert('Please enter a search'); return false; }";

  // Alternative (HTML5) placeholder attribute instead of using the javascript
  $form['search_block_form']['#attributes']['placeholder'] = c_szYourSearch;

  $form['#theme_wrappers'] = array();

  // echo '<pre>' . print_r($form['search_block_form'], TRUE) . '</pre>'; die;

}

/**
* Changes the search form to use the "search" input element of HTML5.
*/
function emindhub_preprocess_search_block_form(&$vars) {
  // $vars['search_form'] = str_replace('type="text"', 'type="search"', $vars['search_form']);
}



// function emindhub_form_user_register_form_alter(&$vars) {
function emindhub_form_user_register_form_alter(&$form, &$form_state, $form_id) {
  // $vars['field_first_name']['#access'] = TRUE; // OLD
  // $vars['field_last_name']['#access'] = TRUE; // OLD

  $form['emh_baseline'] = array(
    '#markup' => '<p class="emh-title-baseline">' . t('Create your account <strong>for free in no time</strong>') . '</p>',
    '#weight' => '-1000', // First !
  );

  // Add class before & after fields
  $form['field_first_name']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_last_name']['#suffix'] = '</div>';

  $form['account']['name']['#prefix'] = '<div class="form-group-2col row">';
  $form['account']['current_pass']['#suffix'] = '</div>';

  $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';
}


function emindhub_preprocess_select_as_checkboxes(&$variables) {
  $element = &$variables['element'];
  // Remove form-control class added to original "select" element
  if (($key = array_search('form-control', $element['#attributes']['class'])) !== false) {
    unset($element['#attributes']['class'][$key]);
  }
}


function emindhub_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  // echo '<pre>' . print_r($form, TRUE) . '</pre>';
}
