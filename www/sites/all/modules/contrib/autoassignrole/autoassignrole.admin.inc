<?php

/**
 * @file
 * Administrative functionality for auto assign role.
 */

/**
 * Provide a single block from the administration menu as a page.
 *
 * This function is often a destination for these blocks.
 * For example, 'admin/structure/types' needs to have a destination to be valid
 * in the Drupal menu system, but too much information there might be
 * hidden, so we supply the contents of the block.
 *
 * @return String
 *   The output HTML.
 */
function autoassignrole_admin_block_page() {
  $item = menu_get_item();
  if ($content = system_admin_menu_block($item)) {
    $output = theme('admin_block_content', array('content' => $content));
  }
  else {
    $output = t('You do not have any administrative items.');
  }
  return $output;
}

/**
 * Form builder; The settings form for automatic role assignment.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function autoassignrole_auto_settings() {
  $form['autoassignrole_auto_active'] = array(
    '#type' => 'radios',
    '#title' => t('Automatic role assignment'),
    '#default_value' => variable_get('autoassignrole_auto_active', 0),
    '#description' => t('Automatic role assignment occurs when the user first logins to the account. This happens without the users knowledge. Set to Enabled to allow this functionality or Disabled to not allow.'),
    '#options' => array(1 => t('Enabled'), 0 => t('Disabled')),
  );

  $form['autoassignrole_admin_active'] = array(
    '#type' => 'radios',
    '#title' => t('Automatic role assignment for admin created accounts'),
    '#default_value' => variable_get('autoassignrole_admin_active', 0),
    '#description' => t('Automatic role assignment occurs when the user first logins to the account. This happens without the users knowledge. Set to Enabled to allow this functionality or Disabled to not allow.'),
    '#options' => array(1 => t('Enabled'), 0 => t('Disabled')),
    '#states' => array(
      'visible' => array(
        ':input[name="autoassignrole_auto_active"]' => array('value' => 1),
      ),
    ),
  );

  // We can disregard the authenticated user role since it is assigned to each
  // user by Drupal.
  $roles = user_roles(TRUE);
  unset($roles[DRUPAL_AUTHENTICATED_RID]);

  if ($roles) {
    $form['autoassignrole_auto_roles'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Roles'),
      '#default_value' => variable_get('autoassignrole_auto_roles', array()),
      '#description' => t('Check the specific roles the user will automatically be assigned to when created by an administrator or through the new user registration process. The Authenticated User role is automatically assigned by Drupal core and can not be edited.'),
      '#options' => $roles,
      '#states' => array(
        'visible' => array(
          ':input[name="autoassignrole_auto_active"]' => array('value' => 1),
        ),
      ),
    );
  }

  return system_settings_form($form);
}

/**
 * Form builder; The settings form for user selectable role assignment.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function autoassignrole_user_settings() {
  $form['autoassignrole_user_active'] = array(
    '#type' => 'radios',
    '#title' => t('User role assignment'),
    '#default_value' => variable_get('autoassignrole_user_active', 0),
    '#description' => t('Toggles allowing end users to select roles when creating their accounts.'),
    '#options' => array(1 => t('Enabled'), 0 => t('Disabled')),
  );

  // We can disregard the authenticated user role since it is assigned to each
  // user by Drupal.
  $roles = user_roles(TRUE);
  unset($roles[DRUPAL_AUTHENTICATED_RID]);

  if ($roles) {
    $form['autoassignrole_user_roles'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Roles'),
      '#default_value' => variable_get('autoassignrole_user_roles', array()),
      '#description' => t('Check the specific roles the user will have the option of choosing. The Authenticated User role is automatically assigned by Drupal core and can not be edited.'),
      '#options' => $roles,
      '#states' => array(
        'visible' => array(
          ':input[name="autoassignrole_user_active"]' => array('value' => 1),
        ),
      ),
    );
  }

  $form['autoassignrole_user_multiple'] = array(
    '#type' => 'radios',
    '#title' => t('User role selection'),
    '#default_value' => variable_get('autoassignrole_user_multiple', 0),
    '#description' => t('Should the end user be allowed to choose a single role or can they choose multiple roles?'),
    '#options' => array(0 => t('Single role'), 1 => t('Multiple roles')),
    '#states' => array(
      'visible' => array(
        ':input[name="autoassignrole_user_active"]' => array('value' => 1),
      ),
    ),
  );

  $form['autoassignrole_user_selection'] = array(
    '#type' => 'radios',
    '#title' => t('Selection method'),
    '#default_value' => variable_get('autoassignrole_user_selection', AUTOASSIGNROLE_ELEMENT_RADIO_CHECKBOX),
    '#description' => t('The type of form elements the end user will be presented with.'),
    '#options' => array(
      AUTOASSIGNROLE_ELEMENT_RADIO_CHECKBOX => t('Radio Buttons/Checkboxes'),
      AUTOASSIGNROLE_ELEMENT_SELECT => t('Selection Box'),
    ),
    '#states' => array(
      'visible' => array(
        ':input[name="autoassignrole_user_active"]' => array('value' => 1),
      ),
    ),
  );

  $form['autoassignrole_user_required'] = array(
    '#type' => 'radios',
    '#title' => t('Required'),
    '#default_value' => variable_get('autoassignrole_user_required', 0),
    '#description' => t('Should the end user be required to choose a role?'),
    '#options' => array(0 => t('No'), 1 => t('Yes')),
    '#states' => array(
      'visible' => array(
        ':input[name="autoassignrole_user_active"]' => array('value' => 1),
      ),
    ),
  );

  $form['autoassignrole_user_sort'] = array(
    '#type' => 'radios',
    '#title' => t('Sorting'),
    '#default_value' => variable_get('autoassignrole_user_sort', 'SORT_ASC'),
    '#description' => t('Default sort order of roles the user will see.'),
    '#options' => array(
      'SORT_ASC' => t('Ascending'),
      'SORT_DESC' => t('Descending'),
      'SORT_WEIGHT' => t('Weight of field'),
    ),
    '#states' => array(
      'visible' => array(
        ':input[name="autoassignrole_user_active"]' => array('value' => 1),
      ),
    ),
  );

  // Set the user description filter format.
  $autoassignrole_user_description = _autoassignrole_get_user_description();

  $form['autoassignrole_user_description'] = array(
    '#type' => 'text_format',
    '#title' => t('User Role Description'),
    '#description' => t('The description displayed to the end user when they are selecting their role during registration.'),
    '#default_value' => $autoassignrole_user_description['value'],
    '#required' => FALSE,
    '#format' => $autoassignrole_user_description['format'],
    '#prefix' => '<div id="autoassignrole_user_description_wrapper">',
    '#suffix' => '</div>',
  );

  $form['autoassignrole_user_fieldset_title'] = array(
    '#type' => 'textfield',
    '#title' => t('User Role Fieldset Title'),
    '#description' => t('The title of the fieldset that contains role options.'),
    '#default_value' => variable_get('autoassignrole_user_fieldset_title', t('User Roles')),
    '#size' => 60,
    '#maxlength' => 128,
    '#states' => array(
      'visible' => array(
        ':input[name="autoassignrole_user_active"]' => array('value' => 1),
      ),
    ),
  );

  $form['autoassignrole_user_title'] = array(
    '#type' => 'textfield',
    '#title' => t('User Role Title'),
    '#description' => t('The title of the field that contains the role options the end user sees during registration.'),
    '#default_value' => variable_get('autoassignrole_user_title', t('Role')),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="autoassignrole_user_active"]' => array('value' => 1),
      ),
    ),
  );

  return system_settings_form($form);
}

/**
 * Implements hook_form().
 *
 * Form to edit or add role-specific pages.
 */
function autoassignrole_page_form($form, &$form_state, $op = 'add', $id = 0) {
  $roles = user_roles(TRUE);
  unset($roles[DRUPAL_AUTHENTICATED_RID]);

  $form = array();

  switch ($op) {
    case 'add':
      $title = t('Add a new role page');
      $submit_value = t('Add');
      break;

    case 'edit':
      $title = t('Edit role page');
      $submit_value = t('Save');
      break;
  }

  $form['rid_page'] = array(
    '#type' => 'fieldset',
    '#title' => $title,
  );

  $form['rid_page']['op_term'] = array(
    '#type' => 'hidden',
    '#value' => $op,
  );

  if ($op == 'edit') {
    $form['rid_page']['id'] = array(
      '#type' => 'hidden',
      '#value' => $id,
    );
    if ($id > 0) {
      $page = autoassignrole_get_page($id);
    }
  }

  $form['rid_page']['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Role'),
    '#description' => t('Select the roles this page will assign'),
    '#options' => $roles,
    '#required' => TRUE,
    '#default_value' => isset($page->rids) ? unserialize($page->rids) : array(),
  );

  $form['rid_page']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Page Title'),
    '#description' => t('Enter the title of the page'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => isset($page->title) ? $page->title : "",
  );

  $form['rid_page']['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Page Path'),
    '#description' => t('Enter the Drupal path for the registration page for this role. This is a relative path based on your Drupal installation.'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => isset($page->path) ? $page->path : "",
  );

  $form['rid_page']['menu'] = array(
    '#type' => 'select',
    '#title' => t('Menu'),
    '#description' => t('Which parent menu item should these pages appear under? This will only apply if you choose the "Standard" display option below.'),
    '#options' => menu_get_menus(),
    '#default_value' => isset($page->menu) ? $page->menu : "",
  );

  $form['rid_page']['display'] = array(
    '#type' => 'select',
    '#title' => t('Display type'),
    '#description' => t('Choose the way you would like these pages to be displayed.<br /><em>Standard</em> is equivalent to the core Drupal log in/ registration form, with tabs along the top.<br /><em>Individual</em> is a separate page without tabs.'),
    '#options' => array(
      AUTOASSIGNROLE_PAGE_DISPLAY_STANDARD => t('Standard'),
      AUTOASSIGNROLE_PAGE_DISPLAY_INDIVIDUAL => t('Individual'),
    ),
    '#default_value' => isset($page->display) ? $page->display : "",
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $submit_value,
  );

  return $form;
}

/**
 * Implements hook_form_validate().
 *
 * Check path to see if page already exists.
 */
function autoassignrole_page_form_validate($form_id, &$form_state) {
  $path = $form_state['values']['path'];

  // @todo need to check if the path already exists.
  if ($path) {
    if (preg_match('/[^A-Za-z0-9\/_-]+/', $path) || strpos(trim($path), '/') === 0) {
      form_set_error('path', '\'' . check_plain($path) . '\' ' . t('is not a valid path'));
    }
    else {
      $query = db_select('menu_links', 'm')
        ->fields('m', array('mlid'))
        ->condition('link_path', $path, 'like');
      $count = $query->countQuery()->execute()->fetchField();
      if (drupal_lookup_path('source', $path) || $count > 0) {
        // The menu item exists so need to check if the path has something other
        // than autoassign_role_path registered otherwise throw an error.
        $menu_item = menu_get_item($path);
        if (!isset($menu_item['page_callback']) && $menu_item['page_callback'] != 'autoassignrole_path') {
          form_set_error('path', '\'' . check_plain($path) . '\' ' . t('is already in use as a path'));
        }
      }
    }
  }
}

/**
 * Implements hook_form_submit().
 */
function autoassignrole_page_form_submit($form_id, &$form_state) {
  $page = array(
    'rids' => serialize($form_state['values']['roles']),
    'path' => $form_state['values']['path'],
    'menu' => $form_state['values']['menu'],
    'title' => $form_state['values']['title'],
    'display' => $form_state['values']['display'],
  );

  $return = FALSE;
  $op = $form_state['values']['op_term'];
  switch ($op) {
    case 'add':
      $return = autoassignrole_add_page($page);
      $operation = 'Created';
      break;

    case 'edit':
      $id = $form_state['values']['id'];
      $return = autoassignrole_update_page($page, $id);
      $operation = 'Updated';
      break;
  }

  if ($return) {
    menu_rebuild();
    drupal_set_message(t('Successfully @operation Page @page', array('@operation' => $operation, '@page' => $page['title'])));
    drupal_goto('admin/config/people/autoassignrole/pages');
  }
  else {
    drupal_set_message(t('Unfortunately there has been an error and this page could not be %op', array('%op' => drupal_strtolower($operation))), 'error');
  }
}

/**
 * Function to add role-specific page.
 *
 * @param array $page
 *   The details of the page to be added.
 *
 * @return bool
 *   Return true if successful | false.
 */
function autoassignrole_add_page($page) {
  $return_value = FALSE;
  try {
    $return_value = db_insert('autoassignrole_page')->fields($page)->execute();
  }
  catch (Exception $e) {
    drupal_set_message(t('db_insert failed. Message = %message, query = %query', array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }
  return $return_value;
}

/**
 * Function to update existing role-specific page.
 *
 * @param array $page
 *   The details of the page to be added.
 * @param int $id
 *   The id of the page to be updated.
 *
 * @return bool
 *   Return true if successful | false.
 */
function autoassignrole_update_page($page, $id) {
  $return_value = FALSE;
  try {
    $return_value = db_update('autoassignrole_page')
      ->fields($page)
      ->condition('rid_page_id', $id)
      ->execute();
  }
  catch (Exception $e) {
    drupal_set_message(t('db_update failed. Message = %message, query = %query', array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }
  return $return_value;
}

/**
 * Function to delete role-specific page.
 */
function autoassignrole_page_delete_confirm($form, &$form_state, $page_id) {
  $page = autoassignrole_get_page($page_id);
  $form['page_id'] = array(
    '#type' => 'value',
    '#value' => $page_id,
  );

  return confirm_form($form, t('Are you sure you want to delete the page %name ?', array('%name' => $page->title)), 'admin/config/people/autoassignrole/pages', t('This action cannot be undone.'), t('Delete'));
}

/**
 * Form submit handler for autoassignrole_page_delete_confirm().
 */
function autoassignrole_page_delete_confirm_submit($form, &$form_state) {
  db_delete('autoassignrole_page')
    ->condition('rid_page_id', (int) $form_state['values']['page_id'])
    ->execute();
  menu_rebuild();
  drupal_set_message(t('Successfully deleted page'));
  $form_state['redirect'] = 'admin/config/people/autoassignrole/pages';
}

/**
 * Function to display list of role-specific pages.
 *
 * @return array
 *   Returns a build array.
 */
function autoassignrole_list_pages() {
  $header = array(
    array('data' => 'Title', 'field' => 'title', 'sort' => 'asc'),
    array('data' => 'Roles', 'field' => 'rids'),
    array('data' => 'Path', 'field' => 'path'),
    array('data' => 'Operations'),
  );

  $query = db_select('autoassignrole_page', 'p')
    ->extend('PagerDefault')
    ->limit(10)
    ->extend('TableSort')
    ->orderByHeader($header)
    ->fields('p', array(
        'rid_page_id',
        'rids',
        'title',
        'path',
        )
      );

  $results = $query->execute();

  $user_roles = user_roles(TRUE);
  $rows = array();
  foreach ($results as $page) {
    $rids = unserialize($page->rids);
    $roles = '';
    $count = 0;
    foreach ($rids as $rid) {
      if (!empty($rid) && array_key_exists($rid, $user_roles)) {
        if ($count != 0) {
          $roles .= ', ';
        }
        $roles .= $user_roles[$rid];
        $count++;
      }
    }
    $edit = l(t('Edit'), 'admin/config/people/autoassignrole/pages/edit/' . $page->rid_page_id);
    $delete = l(t('Delete'), 'admin/config/people/autoassignrole/pages/delete/' . $page->rid_page_id);
    $links = $edit . ' | ' . $delete;
    $rows[] = array(
      'data' => array(
        $page->title,
        $roles,
        $page->path,
        $links,
      ),
    );
  }

  $html = theme('table',
    array(
      'header' => $header,
      'rows' => $rows,
      'sticky' => TRUE,
      'empty' => 'No Auto Assign pages created...',
    )
  );

  $html .= theme('pager', array('tags' => array()));

  return $html;
}
