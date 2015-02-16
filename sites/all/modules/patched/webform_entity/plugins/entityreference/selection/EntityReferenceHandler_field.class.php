<?php

/**
 * A generic Entity handler.
 *
 * The generic base implementation has a variety of overrides to workaround
 * core's largely deficient entity handling.
 */
class EntityReferenceHandler_field extends EntityReference_SelectionHandler_Generic {

  // This is generic and reusable except for the fact that we want to
  // do something with the uid, as a result, we can only work with our
  // entity type.
  const TYPE = 'webform_submission_entity';

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $form = parent::settingsForm($field, $instance);

    $field_options = array();
    if (isset($field['settings']['target_type'])) {
      foreach (field_info_instances($field['settings']['target_type']) as $bundle_name => $bundle_instances) {
        if (!empty($field['settings']['handler_settings']['target_bundles'])) {
          // If the target bundles are selected, filter the results.
          if (!in_array($bundle_name, $field['settings']['handler_settings']['target_bundles'])) {
            continue;
          }
        }
        foreach ($bundle_instances as $field_name => $field_instance) {
          $field_options[$field_name] = $field_instance['label'];
        }
      }
    }

    // TODO: Load the fields for the selected bundles via some kind of ajaxy hotness.
    $form['title_field'] = array(
      '#type' => 'select',
      '#default_value' => isset($field['settings']['handler_settings']['title_field']) ? $field['settings']['handler_settings']['title_field'] : '',
      '#title' => t('Field to use'),
      '#options' => $field_options,
      '#description' => t('This should be the machine name of the field that you are referencing.'),
      '#required' => TRUE,
    );
    $form['author_only'] = array(
      '#title' => t('Limit the available options to only this users own webform submissions'),
      '#type' => 'checkbox',
      '#default_value' => isset($field['settings']['handler_settings']['author_only']) ? $field['settings']['handler_settings']['author_only'] : TRUE,
    );
    return $form;
  }

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance) {
    $entity_type = isset($field['settings']['target_type']) ? $field['settings']['target_type'] : 'none';
    $title_field = isset($field['settings']['handler_settings']['title_field']) ? $field['settings']['handler_settings']['title_field'] : 'none';

    $instance = ($entity_type == self::TYPE) ? new EntityReferenceHandler_field($field, $instance) : EntityReference_SelectionHandler_Broken::getInstance($field, $instance);

    if ($entity_type != self::TYPE) {
      // Return the broken handler.
      $tokens = array('%type' => $entity_type);
      $message = t('The webform field handler should be used only by webform submission entities but it was used with %type instead.', $tokens);
    }
    if (field_info_field($title_field) == NULL) {
      $tokens = array('%field' => $title_field);
      $message = t('The webform field handler should be used only with existing fields, %field instead does not exist.', $tokens);
    }

    if (isset($message)) {
      drupal_set_message($message, 'error');
      watchdog('webform_entity', $message, $tokens, WATCHDOG_ERROR);
    }

    return $instance;
  }

  /**
   * Build an EntityFieldQuery to get referencable entities.
   */
  protected function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    $query = parent::buildEntityFieldQuery();
    $settings = $this->field['settings']['handler_settings'];

    if (isset($match)) {
      // If we are performing an autocomplete, match the text entered.
      $entity_info = entity_get_info(self::TYPE);
      $search_field = $settings['title_field'];
      $query->fieldCondition($search_field, 'value', $match, $match_operator);
    }
    else {
      // If we are not performing an autocomplete, make sure this field is populated.
      $search_field = $settings['title_field'];
      $query->fieldCondition($search_field, 'value', '%', 'like');
    }

    if (isset($settings['author_only']) && $settings['author_only']) {
      global $user;
      $query->propertyCondition('uid', $user->uid, '=');
    }

    return $query;
  }

  /**
   * Implements EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    if (empty($this->field['settings']['handler_settings']['title_field'])) {
      return parent::getLabel($entity);
    }

    $wrapper = entity_metadata_wrapper($this->field['settings']['target_type'], $entity);
    $search_field = $this->field['settings']['handler_settings']['title_field'];
    return $wrapper->{$search_field}->value();
  }
}
