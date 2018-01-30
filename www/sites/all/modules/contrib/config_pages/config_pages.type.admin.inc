<?php

/**
 * @file
 * ConfigPages type editing UI.
 */

/**
 * UI controller.
 */
class ConfigPagesTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage config_pages entity types, including adding and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the config_pages type editing form.
 */
function config_pages_type_form($form, &$form_state, $config_pages_type, $op = 'edit') {

  if ($op == 'clone') {
    $config_pages_type->label .= ' (cloned)';
    $config_pages_type->type = '';
  }
  $form['#config_pages_type'] = $config_pages_type;
  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $config_pages_type->label,
    '#description' => t('The human-readable name of this config_pages page.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($config_pages_type->type) ? $config_pages_type->type : '',
    '#maxlength' => 32,
    '#disabled' => !empty($config_pages_type->type),
    '#machine_name' => array(
      'exists' => 'config_pages_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this config_pages page. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;

  // Menu configuration.
  $form['data']['menu'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu settings'),
    '#collapsible' => TRUE,
  );

  $form['data']['menu']['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Drupal path to this config'),
    '#default_value' => !empty($config_pages_type->data['menu']['path']) ? $config_pages_type->data['menu']['path'] : '',
    '#required' => TRUE,
  );

  $options = array(
    MENU_NORMAL_ITEM => t('Normal'),
    MENU_DEFAULT_LOCAL_TASK => t('Root Task'),
    MENU_LOCAL_TASK => t('Local Task'),
  );
  $form['data']['menu']['type'] = array(
    '#type' => 'select',
    '#title' => t('Page type'),
    '#options' => $options,
    '#default_value' => !empty($config_pages_type->data['menu']['type']) ? $config_pages_type->data['menu']['type'] : MENU_NORMAL_ITEM,
    '#required' => TRUE,
  );

  // Context.
  $form['data']['context'] = array(
    '#type' => 'fieldset',
    '#title' => t('Context'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $options = config_pages_context_groups();
  $form['data']['context']['group'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Consider following context for this configuration'),
    '#options' => $options,
    '#default_value' => !empty($config_pages_type->data['context']['group']) ? $config_pages_type->data['context']['group'] : array(),
    '#required' => FALSE,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Config Page'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function config_pages_type_form_submit(&$form, &$form_state) {
  $config_pages_type = entity_ui_form_submit_build_entity($form, $form_state);
  $config_pages_type->save();
  drupal_set_message(t('Page settings saved'));
}

/**
 * Form API submit callback for the delete button.
 */
function config_pages_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/config_pages_types/manage/' . $form_state['config_pages_type']->type . '/delete';
}
