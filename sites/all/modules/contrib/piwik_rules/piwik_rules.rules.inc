<?php
/**
 * @file
 * Piwik rules actions
 */
function piwik_rules_rules_action_info() {
  return array(
    'piwik_rules_trackgoal' => array(
      'label' => t('Track a goal'), 
      'parameter' => array(
        'idgoal' => array(
          'type' => 'integer',
          'label' => t('Goal ID'),
          'description' => t('Please ask your piwik server administrator for the goal ID.'),
        ),
        'revenue' => array(
          'type' => 'decimal',
          'label' => t('Revenue'),
          'optional' => true,
        ),
      ), 
      'group' => t('Piwik'), 
    ),
  );
}
function piwik_rules_trackgoal($idgoal, $revenue, $token_auth) {
  require_once(variable_get('piwik_rules_piwiktracker',''));
  $piwik_url = variable_get('piwik_url_http','');
  $idsite = variable_get('piwik_site_id','');
  $token_auth = variable_get('piwik_rules_token_auth','');
  $t = new PiwikTracker($idsite, $piwik_url);
  if (!empty($token_auth)) {
    $visitorId = ($t->getVisitorId());
    $t->setTokenAuth($token_auth);
    $t->setVisitorId($visitorId);
  }
  if ($revenue > 0) {
    $t->doTrackGoal($idgoal, round($revenue));
  }
  else {
    $t->doTrackGoal($idgoal);
  }
}

