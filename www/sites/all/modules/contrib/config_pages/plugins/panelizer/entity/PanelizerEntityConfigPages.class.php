<?php
/**
 * @file
 * Class definition.
 */

/**
 * Panelizer class for config pages.
 */
class PanelizerEntityConfigPages extends PanelizerEntityDefault {
  /**
   * {@inheritdoc}
   */
  public function entity_access($op, $entity) {
    return entity_access($op, $this->entity_type, $entity);
  }

  /**
   * {@inheritdoc}
   */
  public function entity_save($entity) {
    entity_save($this->entity_type, $entity);
  }

  /**
   * {@inheritdoc}
   */
  public function entity_identifier($entity) {
    return t('This Cpnfig Page');
  }

  /**
   * {@inheritdoc}
   */
  public function entity_bundle_label() {
    return t('Config Page');
  }

  /**
   * {@inheritdoc}
   */
  function get_default_display($bundle, $view_mode) {
    // For now we just go with the empty display.
    // @todo come up with a better default display.
    return parent::get_default_display($bundle, $view_mode);
  }

  /**
   * Implements hook_field_attach_form().
   */
  public function hook_field_attach_form($entity, &$form, &$form_state, $langcode) {
    parent::hook_field_attach_form($entity, $form, $form_state, $langcode);

    // Remove '#group' property, so panelizer settings won't be merged into
    // vertical tabs on node forms.
    if (isset($form['panelizer']['#group'])) {
      $form['panelizer']['#group'] = NULL;
    }
  }

  /**
   * Implements hook_field_attach_submit().
   */
  public function hook_field_attach_submit($entity, &$form, &$form_state) {
    // Save paragraph item panelizer settings.
    if (!empty($form_state['panelizer has choice'])) {
      list($entity_id, $revision_id, $bundle) = entity_extract_ids($this->entity_type, $entity);
      foreach ($this->plugin['view modes'] as $view_mode => $view_mode_info) {
        if (isset($form['#parents']) && drupal_array_nested_key_exists($form_state['values'], $form['#parents'])) {
          $values = drupal_array_get_nested_value($form_state['values'], $form['#parents']);
          if (isset($values['panelizer'][$view_mode]['name'])) {
            $entity->panelizer[$view_mode] = clone $this->get_default_panelizer_object($bundle . '.' . $view_mode, $values['panelizer'][$view_mode]['name']);
            if (!empty($entity->panelizer[$view_mode])) {
              $entity->panelizer[$view_mode]->did = NULL;

              // Ensure original values are maintained, if they exist.
              if (isset($form['panelizer'][$view_mode]['name'])) {
                $entity->panelizer[$view_mode]->entity_id = $form['panelizer'][$view_mode]['name']['#entity_id'];
                $entity->panelizer[$view_mode]->revision_id = $form['panelizer'][$view_mode]['name']['#revision_id'];
              }
            }
          }
        }
      }
    }
  }

  /**
   * Implements hook_form_alter().
   */
  public function hook_form_alter(&$form, &$form_state, $form_id) {
    if ($form_id == 'config_pages_type_form' && module_exists('panels_ipe')) {
      $config_pages_type = $form['#config_pages_type'];

      if (isset($form['#config_pages_type']) && !empty($form['#config_pages_type']->type)) {
        $bundle = $form['#config_pages_type']->type;

        // Workaround for non-existant bundle value on updates.
        $form['panelizer_bundle'] = array(
          '#type' => 'value',
          '#value' => $bundle,
        );

        $this->add_bundle_setting_form($form, $form_state, $bundle, array(empty($form_state['values']['locked']) && empty($bundle) ? 'bundle' : 'panelizer_bundle'));
        if (!empty($form['panelizer'])) {
          $form['panelizer']['#description'] = t('EXPERIMENTAL! Allows to panelize Default view mode with IPE.');
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function add_bundle_setting_form(&$form, &$form_state, $bundle, $type_location) {
    // Call parent.
    parent::add_bundle_setting_form($form, $form_state, $bundle, $type_location);

    // Move panelizer submit handler to the end.
    $submit_handler = 'panelizer_entity_default_bundle_form_submit';
    if (($index = array_search($submit_handler, $form['#submit'])) !== FALSE) {
      unset($form['#submit'][$index]);
      $form['#submit'][] = $submit_handler;
    }
  }
}
