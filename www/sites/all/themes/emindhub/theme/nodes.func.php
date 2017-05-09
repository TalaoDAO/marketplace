<?php

function emindhub_preprocess_node(&$variables, $hook) {
  global $user;
  $node = $variables['node'];

	if (isset($node->type)) {
    // Adds a theme hook suggestion for the view mode
    $variables['theme_hook_suggestions'][] = 'node__' . $node->type . '__' . $variables['view_mode'];

		switch ($node->type) {
      case 'request':

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
				if (module_exists('emh_request_workflow')) {
          $variables['request_status'] = emh_request_workflow_get_status($node->nid);
        }

        // Submission status
        module_load_include('inc', 'webform', 'includes/webform.submissions');
        $variables['submissions'] = webform_get_submissions(array('nid' => $node->nid));
        foreach ($variables['submissions'] as $submission) {
          if ($submission->uid == $user->uid) {
            $variables['user_submission'] = $submission;
            $variables['submission_status'] = emh_request_submission_get_status($submission);
            break;
          }
        }

        $variables['hidden_name'] = false;
        if ($hide_name = field_get_items('node', $node, 'field_hide_name')) {
          $variables['hidden_name'] = $hide_name[0]['value'];
        }

        $variables['hidden_organisation'] = false;
        if ($hide_organisation = field_get_items('node', $node, 'field_hide_organisation')) {
          $variables['hidden_organisation'] = $hide_organisation[0]['value'];
        }

				break;

      default:
        break;
		}
	}
}

function emindhub_node_view_alter(&$build) {
  // remove "add comment" link from node teaser mode display
  unset($build['links']['comment']['#links']['comment-add']);
  // and if logged out this will cause another list item to appear, so let's get rid of that
  unset($build['links']['comment']['#links']['comment_forbidden']);
}

// function emindhub_comment_view_alter(&$build) {
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
