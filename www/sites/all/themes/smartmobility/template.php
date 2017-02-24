<?php

/**
 * Implements hook_preprocess_html().
 */
function smartmobility_preprocess_html(&$variables) {
  if (arg(0) == EMH_SMARTMOBILITY_BASE_URL && !arg(1)) {
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
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function smartmobility_form_user_register_form_smartmobility_expert_alter(&$form, &$form_state, $form_id) {
  $form['emh_content'] = array(
    '#markup' => '<p class="emh-title-baseline">' . t('You can directly login with your LinkedIn account or complete the form below to create your account.') . '</p>',
    '#weight' => '-999',
  );
}
