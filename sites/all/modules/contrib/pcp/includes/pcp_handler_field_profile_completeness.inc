<?php

/**
 * @file pcp_handler_profile_completeness.inc
 *
 * Handler for the 'Profile: completeness' field.
 * This is for Profile2 profiles.
 */

class pcp_handler_field_profile_completeness extends views_handler_field {

  public function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
  }

  public function option_definition() {
    $options = parent::option_definition();
    $options['bundle'] = array('default' => '');
    return $options;
  }

  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $options = array();
    $profile2_entity = entity_get_info('profile2');
    if (!empty($profile2_entity['bundles'])) {
      foreach ($profile2_entity['bundles'] as $bundle => $bundle_data) {
        $options[$bundle] = $bundle_data['label'];
      }
    }
    $form['bundle'] = array(
      '#type' => 'select',
      '#title' => t('Profile type'),
      '#options' => $options,
      '#default_value' => $this->options['bundle'],
      '#description' => t('Select the profile type for which completeness is to be calculated.'),
    );
  }

  /**
   * Check access. Use the Profile2 permissions.
   */
  public function access() {
    $bundle = $this->options['bundle'];
    return user_access('administer profiles') || user_access("view any $bundle profile");
  }

  /**
   * Help build the query.
   */
  public function query() {
    // Not calling parent::query() as it will treat 'completeness' as a real
    // db field.
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render data. 
   */
  public function render($values) {
    $profile2_entity = entity_get_info('profile2');
    $bundle = empty($this->options['bundle']) ? key($profile2_entity['bundles']) : $this->options['bundle'];
    if (!empty($profile2_entity['bundles'][$bundle])) {
      $user = new stdClass();
      $user->uid = $values->{$this->aliases['uid']};
      $data = pcp_get_complete_percentage_data('profile2', $bundle, $user);
      return $data['current_percent'];
    }
    return '?';
  }
}
