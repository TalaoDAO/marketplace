<?php

/**
 * @file
 * Builds replacement tokens for Profile Complete Percentage.
 */

/**
 * Implements hook_token_info().
 */
function pcp_token_info() {
  $info = array();

  // Declare a token type. We could use 'pcp' instead of 'pcp-user', but maybe
  // some day we will add bundle tokens, and then we can use 'pcp-bundle' for
  // those.
  $info['types']['pcp-user'] = array(
    'name' => t('PCP user tokens'),
    'description' => t('Custom user tokens for the Profile Complete Percentage module.'),
  );

  // Declare tokens [pcp-user] and [pcp-profile2:?] that can be chained after
  // any token that provides a user object, such as [site:current-user].
  $info['tokens']['pcp-user']['pcp-user'] = array(
    'name' => t('Profile percent complete'),
    'description' => t("The user's core Profile Completed Percentage."),
    'needs-data' => 'user',
  );
  $info['tokens']['pcp-user']['pcp-profile2'] = array(
    'name' => t('Profile2 percent complete'),
    'description' => t("The user's Profile Completed Percentage for the profile type ?."),
    'needs-data' => 'user',
    'dynamic' => TRUE,
  );

  return $info;
}

/**
 * Implements hook_tokens().
 *
 * Provide a user token for the Profile Completed Percentage.
 * See system.api.php and token.tokens.inc for good examples.
 */
function pcp_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  switch ($type) {

    case 'pcp-user':
      if (empty($data['user'])) {
        break;
      }
      $account = $data['user'];

      // If $original == '[site:current-user:pcp-user]', $name == 'pcp-user'.
      foreach ($tokens as $name => $original) {
        switch ($name) {
          case 'pcp-user':
            $data = pcp_get_complete_percentage_data('user', 'user', $account);
            $replacements[$original] = $data['current_percent'];
            break;
        }
      }

      if ($profile2_tokens = token_find_with_prefix($tokens, 'pcp-profile2')) {
        foreach ($profile2_tokens as $name => $original) {
          // If $original == '[site:current-user:pcp-profile2:foo]', then
          // $name == 'foo'.
          $data = pcp_get_complete_percentage_data('profile2', $name, $account);
          $replacements[$original] = $data['current_percent'];
        }
      }
      break;
  }

  return $replacements;
}
