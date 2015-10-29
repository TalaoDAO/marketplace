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


function emindhub_my_file_element_process(&$element, &$form_state, $form) {
  $element = file_managed_file_process($element, $form_state, $form);

  $element['upload_button']['#attributes']['class'][] = 'btn-info';
  // $element['upload_button']['#access'] = FALSE;
  // echo '<pre>' . print_r($element, TRUE) . '</pre>';
  return $element;
}


// Bootstrap compliance : design select
function emindhub_preprocess_select_as_checkboxes(&$variables) {
  $element = &$variables['element'];
  // Remove form-control class added to original "select" element
  if (($key = array_search('form-control', $element['#attributes']['class'])) !== false) {
    unset($element['#attributes']['class'][$key]);
  }
}
