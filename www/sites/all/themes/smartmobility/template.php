<?php

/**
 * Implements hook_preprocess_html().
 */
function smartmobility_preprocess_html(&$variables) {
  if (emh_smartmobility_context() && !arg(1)) {
    $variables['classes_array'][] = 'homepage';
  }
}

/**
 * Implements hook_form_alter().
 */
function smartmobility_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    case 'user_register_form_smartmobility_client':
    case 'user_register_form_smartmobility_expert':
      $form['#groups']['group_account']->label = '';
      $form['emh_baseline'] = array(
        '#markup' => '<p class="emh-title-baseline">' . sprintf(t('Create your account %sfor free in no time%s'), '<strong>', '</strong>') . '</p>',
        '#weight' => '-1000',
      );
      // Add class before & after fields.
      if ($form['field_first_name'] && $form['field_last_name']) {
        $form['field_first_name']['#prefix'] = '<div class="row">';
        $form['field_last_name']['#suffix'] = '</div>';
      }
      // Reduce email description for better Bootstrap display (tooltip)
      $form['account']['mail']['#description'] = t('All e-mails from the system will be sent to this address. The e-mail address will only be used if you wish to receive a new password or certain news or notifications by e-mail.');
      break;
    
    case 'user_login':
    case 'user_login_block':
      $form['hybridauth']['#type'] = '';
      break;
  }
}
