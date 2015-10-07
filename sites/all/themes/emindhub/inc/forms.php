<?php

// LTH : add bootstrap class to field markup
function emindhub_form_element($variables) {
  $element = &$variables ['element'];
  // echo '<pre>' . print $element['#name'] . '</pre>';
  // if ($element['#name'] == 'current_pass') {
  //   echo 'BAM'; die;
  // }

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


/**
 * Display the text associated with a static star display.
 *
 * Note that passing in explicit data types is extremely important when using
 * this function. A NULL value will exclude the value entirely from display,
 * while a 0 value indicates that the text should be shown but it has no value
 * yet.
 *
 * All ratings are from 0 to 100.
 *
 * @param $user_rating
 *   The current user's rating.
 * @param $average
 *   The average rating.
 * @param $votes
 *   The total number of votes.
 * @param $stars
 *   The number of stars being displayed.
 * @return
 *   A themed HTML string representing the star widget.
 */
function emindhub_fivestar_summary($variables) {
  $microdata = $variables['microdata'];
  extract($variables, EXTR_SKIP);
  $output = '';
  $div_class = '';
  $average_rating_microdata = '';
  $rating_count_microdata = '';
  if (isset($user_rating)) {
    $div_class = isset($votes) ? 'user-count' : 'user';
    $user_stars = round(($user_rating * $stars) / 100, 1);
    $output .= '<span class=\'user-rating\'>' . t('Your rating: <span>!stars</span>', array('!stars' => $user_rating ? $user_stars : t('None'))) . '</span>';
  }
  if (isset($user_rating) && isset($average_rating)) {
    $output .= ' ';
  }
  if (isset($average_rating)) {
    if (isset($user_rating)) {
      $div_class = 'combo';
    }
    else {
      $div_class = isset($votes) ? 'average-count' : 'average';
    }

    $average_stars = round(($average_rating * $stars) / 100, 1);
    if (!empty($microdata['average_rating']['#attributes'])) {
      $average_rating_microdata = drupal_attributes($microdata['average_rating']['#attributes']);
    }
    $output .= '<span class=\'average-rating\'>' . t('Average: !stars',
      array('!stars' => "<span $average_rating_microdata>$average_stars</span>")) . '</span>';
  }

  if (isset($votes)) {
    if (!isset($user_rating) && !isset($average_rating)) {
      $div_class = 'count';
    }
    if ($votes === 0) {
      $output = '<span class=\'empty\'>'. t('No votes yet') .'</span>';
    }
    else {
      if (!empty($microdata['rating_count']['#attributes'])) {
        $rating_count_microdata = drupal_attributes($microdata['rating_count']['#attributes']);
      }
      // We don't directly substitute $votes (i.e. use '@count') in format_plural,
      // because it has a span around it which is not translatable.
      $votes_str = format_plural($votes, '!cnt vote', '!cnt votes', array(
        '!cnt' => '<span ' . $rating_count_microdata . '>' . intval($votes) . '</span>'));
      if (isset($user_rating) || isset($average_rating)) {
        $output .= ' <span class=\'total-votes\'>(' . $votes_str . ')</span>';
      }
      else {
        $output .= ' <span class=\'total-votes\'>' . $votes_str . '</span>';
      }
    }
  }

  $output = '<div class=\'fivestar-summary fivestar-summary-' . $div_class . '\'>' . $output . '</div>';
  // We hide public profile legend : there's only one vote, user's one
  // return $output;
}


// WYSIWYG : Cacher les types de format, peut-être trop ??
// function emindhub_element_info_alter(&$type) {
//   // if ( !isAdminUser() || !isWebmasterUser() ) {
//   	if (isset($type['text_format']['#process'])) {
//   		foreach ($type['text_format']['#process'] as &$callback) {
//   			if ($callback === 'filter_process_format') {
//   				$callback = 'emindhub_process_format';
//   			}
//   		}
//   	}
//   // }
// }


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

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';
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

  // echo '<pre>' . print_r($form['field_address']['und'][0], TRUE) . '</pre>';

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
  $form['account']['mail']['#weight'] = -9;
  $form['account']['mail']['#suffix'] = '</div>';

  unset($form['account']['current_pass']);
  unset($form['account']['current_pass_required_values']);
  $form['#validate'] = array_diff($form['#validate'], array('user_validate_current_pass'));

  $form['field_address']['und'][0]['#type'] = 'div';
  $form['field_address']['und'][0]['street_block']['thoroughfare']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_address']['und'][0]['street_block']['premise']['#suffix'] = '</div>';

  $form['field_address']['und'][0]['locality_block']['postal_code']['#prefix'] = '<div class="form-group-2col row">';
  $form['field_address']['und'][0]['locality_block']['locality']['#suffix'] = '</div>';

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

  // $form['field_photo']['und'][0]['#process'][] = 'emindhub_my_file_element_process';
  $form['field_cv']['und'][0]['#process'][] = 'emindhub_my_file_element_process';

  // echo '<pre>' . print_r($form['account'], TRUE) . '</pre>';
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
    '#markup' => '<p class="emh-title-baseline">' . t('Create your account <strong>for free in no time</strong>') . '</p>',
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

  // echo '<pre>' . print_r($form, TRUE) . '</pre>'; die;
}


// Bootstrap compliance : design select
function emindhub_preprocess_select_as_checkboxes(&$variables) {
  $element = &$variables['element'];
  // Remove form-control class added to original "select" element
  if (($key = array_search('form-control', $element['#attributes']['class'])) !== false) {
    unset($element['#attributes']['class'][$key]);
  }
}


function emindhub_form_comment_form_alter(&$form, &$form_state, $form_id) {

  // $form['author']['#access'] = 0;
  // $form['subject']['#access'] = 0;

  // echo '<pre>' . print_r($form, TRUE) . '</pre>';

  return $form;

}
