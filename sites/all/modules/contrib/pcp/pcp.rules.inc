<?php
/**
 * Implements hook_rules_condition_info() on behalf of the pcp module.
 */
function pcp_rules_condition_info() {
  $conditions = array();

  $conditions['pcp_profile_is_completed'] = array(
    'label' => t('User profile is completed'),
    'parameter' => array(
      'account' => array(
        'label' => t('User'),
        'type' => 'user',
      ),
    ),
    'group' => t('User'),
    'callbacks' => array(
      'execute' => 'pcp_rules_profile_is_completed',
    ),
  );

  return $conditions;
}

/**
 * Helper function for the condition 'User profile is completed'
 */
function pcp_rules_profile_is_completed($account) {
  if ($pcpinfo = pcp_get_complete_percentage_data('user', 'user', $account)) {
    return ($pcpinfo['current_percent'] == 100) ? TRUE : FALSE;
  }
  else {
    return FALSE;
  }
}
