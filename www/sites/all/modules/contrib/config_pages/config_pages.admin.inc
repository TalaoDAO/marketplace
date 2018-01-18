<?php
/**
 * @file
 * ConfigPages editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

/**
 * UI controller.
 */
class ConfigPagesUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = array();

    // Add menu items to each different type of entity.
    foreach (config_pages_get_types() as $type) {

      // For default local tasks we need to create a root element + local task.
      if ($type->data['menu']['type'] == MENU_DEFAULT_LOCAL_TASK) {
        $parts = explode('/', $type->data['menu']['path']);
        $items[$type->data['menu']['path'] . '/' . array_pop($parts)] = array(
          'title' => $type->label,
          'type' => $type->data['menu']['type'],
          'weight' => -10,
        );

        // This will create actual page later.
        $type->data['menu']['type'] = MENU_NORMAL_ITEM;
      }

      // Create base item.
      $items[$type->data['menu']['path']] = array(
        'title' => $type->label,
        'page callback' => 'config_pages_form_wrapper',
        'page arguments' => array($type->type),
        'access callback' => 'config_pages_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 'config_pages.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module']),
        'type' => $type->data['menu']['type'],
      );
    }
    return $items;
  }

  /**
   * Create the markup for the add ConfigPages Entities page within the class
   * so it can easily be extended/overriden.
   */
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }

    return theme('config_pages_add_list', array('content' => $content));
  }

}

/**
 * Form callback wrapper: create or edit a config_pages.
 *
 * @param $config_pages
 *   The config_pages object being edited by this form.
 *
 * @see config_pages_edit_form()
 */
function config_pages_form_wrapper($type) {

  $config_pages = config_pages_create(array('type' => $type));

  // Add the breadcrumb for the form's location.
  config_pages_set_breadcrumb();

  // Check if config type exists.
  $config_type = config_pages_get_types($config_pages->type);
  if (empty($config_type)) {
    drupal_set_message(t('Config type @type no longer exists', array('@type' => $config_pages->type)), 'error');
    return '';
  }

  // Show context message.
  if (!empty($config_pages->context) && empty($_POST)) {
    $label = config_pages_context_label($config_pages->context);
    drupal_set_message(t('Please note that this Page is context sensitive, current context is %label', array(
      '%label' => $label,
    )), 'warning');
  }

  // Load config of specified type for current context.
  $current_config = config_pages_load_entity($type, $config_pages->context);
  if (!empty($current_config)) {
    $config_pages = $current_config;
  }

  // Return configuration form.
  $form_content = drupal_get_form('config_pages_edit_form', $config_pages);
  $content = drupal_render($form_content);

  // If this config uses context we show context import form.
  if ($config_pages->context && empty($form_content['confirm'])) {
    $form_content = drupal_get_form('config_pages_import_form', $config_pages);
    $content .= drupal_render($form_content);
  }
  return $content;
}

/**
 * Import form callback.
 */
function config_pages_import_form($form, &$form_state, $config_pages) {
  $form['#config_pages'] = $config_pages;

  // List all existing entities of this type.
  $list = entity_load('config_pages', FALSE, array(
    'type' => $config_pages->type,
  ));
  foreach ($list as $item) {
    if ($item->context != $config_pages->context) {
      $options_context[$item->context] = config_pages_context_label($item->context);
    }
  }
  // Allow copy settings from another context.
  if (!empty($options_context)) {
    $form['import_context'] = array(
      '#type' => 'fieldset',
      '#title' => t('Import From Another Context'),
      '#description' => t('This action can not be undone!'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['import_context']['destination'] = array(
      '#type' => 'item',
      '#title' => t('Import To (current)'),
      '#markup' => config_pages_context_label($config_pages->context),
    );
    $form['import_context']['source'] = array(
      '#type' => 'select',
      '#title' => t('Import From'),
      '#options' => $options_context,
      '#default_value' => '',
    );
    $form['import_context']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Import'),
    );
  }

  return $form;
}

/**
 * Duplicate entity.
 */
function config_pages_import_update($entity_type, $bundle, $import, $entity) {

  // Load field structure and prepare import object.
  $fields = field_info_instances($entity_type, $bundle);
  $import = get_object_vars($import);

  // Update dest with data from source.
  foreach ($import as $key => $value) {
    // Embedded field collections have special treatement.
    if (!empty($fields[$key]) && ($fields[$key]['widget']['type'] == 'field_collection_embed') && !empty($value)) {

      // Nullify current field state.
      $entity->{$key}[LANGUAGE_NONE] = array();
      foreach ($import[$key][LANGUAGE_NONE] as $delta => $fcitem) {
        // Load source FCI.
        $source_collection_item = field_collection_item_load($fcitem['value']);

        // Create new field collection.
        $dest_collection_item = entity_create('field_collection_item', array('field_name' => $key));
        $dest_collection_item->setHostEntity($entity_type, $entity);

        // Duplicate fields from field collection.
        $fields2 = field_info_instances('field_collection_item', $key);
        $import_collection_item = (object) array();
        foreach ($fields2 as $field_name => $field_info) {
          $import_collection_item->{$field_name} = $source_collection_item->{$field_name};
        }
        $dest_collection_item = config_pages_import_update('field_collection_item', $key, $import_collection_item, $dest_collection_item);
        $dest_collection_item->save();
      }
    }
    else {
      $entity->{$key} = $value;
    }
  }

  return $entity;
}

/**
 * config_pages_import_form submit handler.
 */
function config_pages_import_form_submit(&$form, &$form_state) {

  // Load source config.
  $source_context = $form_state['values']['source'];
  $source_config = config_pages_load_entity($form['#config_pages']->type, $source_context);
  if (empty($source_config)) {
    drupal_set_message(t('Can not import config from context %context, as it is no longer available.', array(
      '%context' => config_pages_context_label($source_context),
    )), 'error');
    return;
  }

  $config = $form['#config_pages'];

  // Copy all data from source to dest.
  $exclude = array('config_pages_id', 'created', 'changed', 'language', 'context');
  foreach ($exclude as $key) {
    if (isset($source_config->{$key})) {
      unset($source_config->{$key});
    }
  }

  $config = config_pages_import_update('config_pages', $config->type, $source_config, $config);

  config_pages_save($config);
}

/**
 * Form callback wrapper: delete a config_pages.
 *
 * @param $config_pages
 *   The config_pages object being edited by this form.
 *
 * @see config_pages_edit_form()
 */
function config_pages_delete_form_wrapper($config_pages) {
  return drupal_get_form('config_pages_delete_form', $config_pages);
}

/**
 * Form callback: create or edit a config_pages.
 *
 * @param $config_pages
 *   The config_pages object to edit or for a create form an empty config_pages object
 *     with only a config_pages type defined.
 */
function config_pages_edit_form($form, &$form_state, $config_pages) {

  // Context field.
  $form['context'] = array(
    '#type' => 'value',
    '#value' => $config_pages->context,
  );
  $form['#config_pages'] = $config_pages;

  // Process confirmation form.
  if (!empty($form_state['storage']['delete_confirmation'])) {
    $question = 'Are you sure you want to clear this configuration page?';
    $path = $_GET['q'];
    $form = confirm_form($form, $question, $path, NULL, t('Yes'));
    $form['actions']['submit']['#submit'] = array('config_pages_form_submit_delete');
    return $form;
  }

  $groups = config_pages_context_groups($config_pages->type);
  $context_links = array();
  foreach ($groups as $group => $title) {
    list($module, $key) = explode(':', $group);
    $context_links = module_invoke($module, 'config_pages_context_list', $key, TRUE);
    if (!empty($context_links)) {
      // Get current value of this context.
      $value = module_invoke($module, 'config_pages_context_value', $key);

      // Create form elements to select another context.
      $form['context_selection_' . $key] = array(
        '#type' => 'fieldset',
        '#title' => t('Choose @name context', array('@name' => $title)),
        '#weight' => -100,
      );
      foreach ($context_links as $pos => $link) {
        if ($link['value'] == $value) {
          $link['title'] = '<strong>' . $link['title'] . '</strong>';
        }
        $form['context_selection_' . $key][$link['value']] = array(
          '#type' => 'link',
          '#href' => $link['href'],
          '#title' => $link['title'],
          '#prefix' => ($pos > 0) ? ' | ' : '',
          '#options' => array('html' => TRUE),
        );
      }
    }
  }

  // Add the field related form elements.
  $form_state['config_pages'] = $config_pages;
  field_attach_form('config_pages', $config_pages, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => $submit + array('config_pages_edit_form_submit'),
  );

  if (!empty($config_pages->config_pages_id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Clear'),
      '#submit' => array('config_pages_form_submit_delete'),
      '#weight' => 45,
    );

    // Add panelize button.
    if (module_exists('panels_ipe') && function_exists('panelizer_entity_plugin_get_handler')) {
      $handler = panelizer_entity_plugin_get_handler('config_pages');
      if ($handler && $handler->is_panelized($config_pages->type . '.default')) {
        if (empty($config_pages->panelizer['default'])) {
          $form['actions']['panelize'] = array(
            '#type' => 'submit',
            '#value' => t('Panelize Default View Mode with IPE'),
            '#submit' => array('config_pages_form_submit_panelize'),
            '#weight' => 46,
          );
        }
        else {
          $form['actions']['panelize'] = array(
            '#type' => 'markup',
            '#markup' => t('[ Default View Mode Already panelized with IPE ]'),
            '#weight' => 46,
          );
        }
      }
    }
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'config_pages_edit_form_validate';
  return $form;


}

/**
 * Form API validate callback for the config_pages form
 */
function config_pages_edit_form_validate(&$form, &$form_state) {
  $config_pages = $form_state['config_pages'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('config_pages', $config_pages, $form, $form_state);
}

/**
 * Form API submit callback for the config_pages form.
 *
 * @todo remove hard-coded link
 */
function config_pages_edit_form_submit(&$form, &$form_state) {

  $config_pages = entity_ui_controller('config_pages')->entityFormSubmitBuildEntity($form, $form_state);

  // Add in created and changed times.
  if ($config_pages->is_new = isset($config_pages->is_new) ? $config_pages->is_new : 0) {
    $config_pages->created = time();
  }

  $config_pages->changed = time();

  $config_pages->save();

  drupal_set_message(t('Configuration saved'));

}

/**
 * Form API submit callback for the delete button.
 */
function config_pages_form_submit_delete(&$form, &$form_state) {
  if (empty($form_state['storage']['delete_confirmation'])) {
    $form_state['rebuild'] = TRUE;
    $form_state['storage']['delete_confirmation'] = TRUE;
  }
  else {
    unset($form_state['storage']['delete_confirmation']);
    if (empty($form_state['storage'])) {
      unset($form_state['storage']);
      drupal_set_message(t('Configuration page was cleared.'));
    }
    entity_delete('config_pages', $form['#config_pages']->config_pages_id);
  }
}

/**
 * Submit callback to panelize config page.
 */
function config_pages_form_submit_panelize(&$form, &$form_state) {
  $config = $form['#config_pages'];
  $view_mode = 'default';
  if (empty($config->panelizer[$view_mode])) {
    $config->panelizer[$view_mode] = _config_pages_get_internal_default_panelizer($config->type, $view_mode);
    $config->panelizer[$view_mode]->pipeline = 'ipe';
    $config->panelizer[$view_mode]->display_is_modified = TRUE;
    $config->panelizer[$view_mode]->name = implode(':', array('config_pages', $config->type, 'default'));
    entity_save('config_pages', $config);
    $form['#config_pages'] = config_pages_load_entity($type, $context);
    drupal_set_message(t('Config Page Panelized'));
  }
}

/**
 * Form callback: confirmation form for deleting a config_pages.
 *
 * @param $config_pages
 *   The config_pages to delete
 *
 * @see confirm_form()
 */
function config_pages_delete_form($form, &$form_state, $config_pages) {
  $form_state['config_pages'] = $config_pages;

  $form['#submit'][] = 'config_pages_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete config_pages %name?', array('%name' => $config_pages->name)),
    CONFIG_PAGES_PATH_MANAGE_TYPES,
    '<p>' . t('This action can not be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for config_pages_delete_form
 */
function config_pages_delete_form_submit($form, &$form_state) {
  $config_pages = $form_state['config_pages'];

  config_pages_delete($config_pages);

  drupal_set_message(t('The config page %name has been deleted.', array('%name' => $config_pages->name)));
  watchdog('config_pages', 'Deleted config page %name.', array('%name' => $config_pages->name));
}

/**
 * Page to add ConfigPages Entities.
 *
 * @todo Pass this through a proper theme function
 */
function config_pages_add_page() {
  $controller = entity_ui_controller('config_pages');
  return $controller->addPage();
}

/**
 * Displays the list of available config_pages types for config_pages creation.
 *
 * @ingroup themeable
 */
function theme_config_pages_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="config_pages-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer config_pages types')) {
      $output = '<p>' . t('ConfigPages Entities cannot be added because you have not created any config_pages types yet. Go to the <a href="@create-config_pages-type">config_pages type creation page</a> to add a new config_pages type.', array('@create-config_pages-type' => url('admin/structure/config_pages_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No config_pages types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative config_pages pages.
 */
function config_pages_set_breadcrumb() {
  $breadcrumb = array();

  // Generate breadcrumb item for each step of the path.
  $parts = explode('/', $_GET['q']);
  while (!empty($parts)) {
    $path = implode('/', $parts);
    $item = menu_get_item($path);
    if (!empty($item['access'])) {
      array_unshift($breadcrumb, l($item['title'], $path));
    }
    array_pop($parts);
  }

  // Add home link and theme BC.
  array_unshift($breadcrumb, l(t('Home'), '<front>'));
  drupal_set_breadcrumb($breadcrumb);
}
