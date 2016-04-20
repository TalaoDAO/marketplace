<?php

function emindhub_preprocess_node(&$variables, $hook) {
	if (isset($variables['node']->type)) {

		switch ($variables['node']->type) {
			case 'question1':
			case 'webform':
			case 'challenge':

				// Views navigation between nodes
				if (!empty($variables['elements']['links']['views_navigation']['#links']['back'])) {
					$variables['linkBack'] = '';
					$variables['linkBack'] = $variables['elements']['links']['views_navigation']['#links']['back'];
				}
				if (!empty($variables['elements']['links']['views_navigation']['#links']['previous'])) {
					$variables['linkPrev'] = '';
					$variables['linkPrev'] = $variables['elements']['links']['views_navigation']['#links']['previous'];
				}
				if (!empty($variables['elements']['links']['views_navigation']['#links']['next'])) {
					$variables['linkNext'] = '';
					$variables['linkNext'] = $variables['elements']['links']['views_navigation']['#links']['next'];
				}

				// Flags
				if (!empty($variables['elements']['links']['flag']['#links']['flag-my_selection'])) {
					$variables['flag_my_selection'] = '';
					$variables['flag_my_selection'] = $variables['elements']['links']['flag']['#links']['flag-my_selection'];
				}

				// Request status
				$nid = arg(1);
				$variables['request_status'] = '';
				if ( (!empty($nid)) && module_exists('emh_request') ) $variables['request_status'] = emh_request_get_status($nid);
				
				break;

			default:
				break;
		}
	}

}

function emindhub_node_view_alter( &$build ) {
  // remove "add comment" link from node teaser mode display
  unset($build['links']['comment']['#links']['comment-add']);
  // and if logged out this will cause another list item to appear, so let's get rid of that
  unset($build['links']['comment']['#links']['comment_forbidden']);
}

// function emindhub_comment_view_alter( &$build ) {
//
// 	// echo '<pre>' . print_r($build['links'], TRUE) . '</pre>';
//   // if ($build['#view_mode'] == 'teaser') {
//     // remove "add comment" link from node teaser mode display
//     unset($build['links']['comment']['#links']['comment-add']);
//     // and if logged out this will cause another list item to appear, so let's get rid of that
//     unset($build['links']['comment']['#links']['comment_forbidden']);
//   // }
//
// }
