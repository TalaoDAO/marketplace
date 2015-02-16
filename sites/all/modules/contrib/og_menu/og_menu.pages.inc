<?php
/**
 * @file
 * Contains page callbacks for og_menu
 */

/**
 * Menu callback.
 *
 * Shows an overview page of all the custom menus in a user's group and along
 * with their description.
 */
function og_menu_overview_page($group_type, $gid) {
  // Set the title of the page.
  $entity_wrapper = entity_metadata_wrapper($group_type, $gid);
  $entity_label = $entity_wrapper->label() ? $entity_wrapper->label() : $group_type . ' ' . $gid;
  drupal_set_title(t('List menus for %title', array('%title' => $entity_label)), PASS_THROUGH);
  // Set the breadcrumb.
  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));

  $header = array(t('Title'), array('data' => t('Operations'), 'colspan' => '3'));
  $rows = array();
  foreach (og_menu_get_menus($group_type, $gid) as $menu) {
    $row = array(
      theme('menu_admin_overview', array(
        'title' => $menu->title,
        'name' => $menu->menu_name,
        'description' => $menu->description,
      )),
    );
    $row[] = array('data' => l(t('list links'), 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu->menu_name));
    $row[] = array('data' => l(t('edit menu'), 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu->menu_name . '/edit'));
    $row[] = array('data' => l(t('add link'), 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu->menu_name . '/add'));
    $rows[] = $row;
  }

  if (empty($rows)) {
    return t('There are currently no menus.');
  }
  else {
    return theme('table', array('header' => $header, 'rows' => $rows));
  }
}

/**
 * Menu callback.
 *
 * Build the form that handles the adding/editing of a custom menu.
 */
function og_menu_edit_menu_form($form, &$form_state, $type, $group_type, $gid, $menu = array()) {
  module_load_include('inc', 'menu', 'menu.admin');
  $entity_wrapper = entity_metadata_wrapper($group_type, $gid);
  $label = $entity_wrapper->label();
  // Set the breadcrumb.
  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));

  // Set the title of the page.
  switch ($type) {
    case 'add': drupal_set_title(t('Add menu for @title', array('@title' => $label)), PASS_THROUGH);
      break;

    case 'edit': drupal_set_title(t('Edit menu for @title', array('@title' => $label)), PASS_THROUGH);
      break;
  }

  // Build the form.
  $form = array();
  $form = menu_edit_menu($form, $form_state, $type, $menu);
  $form['og_menu_group_type'] = array(
    '#type' => 'value',
    '#value' => $group_type,
  );
  $form['og_menu_gid'] = array(
    '#type' => 'value',
    '#value' => $gid,
  );
  if ($type == 'edit') {
    $form['og_menu_name'] = array(
      '#type' => 'value',
      '#value' => $menu['menu_name'],
    );
  }
  // Add submit handlers.
  $form['#submit'][] = 'menu_edit_menu_submit';
  $form['#submit'][] = 'og_menu_edit_menu_form_submit';
  $form['#submit'][] = 'og_menu_edit_menu_form_submit_redirect';
  $form['actions']['delete']['#submit'][0] = 'og_menu_delete_menu_form_submit';
  return $form;
}

/**
 * Submit handler for og_menu_edit_menu_form().
 */
function og_menu_delete_menu_form_submit($form, &$form_state) {
  $group_type = $form['og_menu_group_type']['#value'];
  $gid = $form['og_menu_gid']['#value'];
  $menu_name = $form['og_menu_name']['#value'];
  $form_state['redirect'] = 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu_name . '/delete';
}

/**
 * Submit handler which handles redirection for og_menu_edit_menu_form form.
 */
function og_menu_edit_menu_form_submit_redirect($form, &$form_state) {
  $group_type = $form['og_menu_group_type']['#value'];
  $gid = $form['og_menu_gid']['#value'];
  $menu_name = $form['#insert'] ? $menu_name = 'menu-' . $form['menu_name']['#value'] : $form['og_menu_name']['#value'];
  $form_state['redirect'] = 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu_name;
}

/**
 * Form callback which shows an entire menu tree at once.
 */
function og_menu_overview_form($form, &$form_state, $group_type, $gid, $menu) {
  module_load_include('inc', 'menu', 'menu.admin');
  drupal_set_title(t('List items for menu !mtitle', array('!mtitle' => $menu['title'])), PASS_THROUGH);
  // Set the breadcrumb.
  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));
  $b = drupal_get_breadcrumb();
  $b[] = l(t('Menus'), 'group/' . $group_type . '/' . $gid . '/admin/menus');
  drupal_set_breadcrumb($b);
  $form = menu_overview_form($form, $form_state, $menu);

  $form['#theme'] = 'menu_overview_form';
  $form['#empty_text'] = t('There are no menu links yet.') . ' ' . l(t('Add link'), 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu['menu_name'] . '/add');

  foreach (element_children($form) as $mlid) {
    if (strstr($mlid, 'mlid:')) {
      $item = $form[$mlid]['#item'];
      $operations = array();
      $operations['edit'] = array(
        '#type' => 'link',
        '#title' => t('edit'),
        '#href' => 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu['menu_name'] . '/item/' . $item['mlid'] . '/edit',
      );

      if ($item['module'] == 'menu' || $item['updated'] == 1) {
        $operations['delete'] = array(
          '#type' => 'link',
          '#title' => t('delete'),
          '#href' => 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu['menu_name'] . '/item/' . $item['mlid'] . '/delete',
        );
      }
      $form[$mlid]['operations'] = $operations;
    }
  }
  return $form;
}

/**
 * Submit function; does the same as the normal menu_overview_form_submit.
 */
function og_menu_overview_form_submit($form, &$form_state) {
  menu_overview_form_submit($form, $form_state);
}

/**
 * Form callback for node/%node/admin/menus/%menu/delete.
 */
function og_menu_delete_menu_confirm($form, &$form_state, $menu, $group_type, $gid) {
  module_load_include('inc', 'menu', 'menu.admin');
  $form = menu_delete_menu_confirm($form, $form_state, $menu);
  $form['og_menu_group_type'] = array(
    '#type' => 'value',
    '#value' => $group_type,
  );
  $form['og_menu_gid'] = array(
    '#type' => 'value',
    '#value' => $gid,
  );
  $form['actions']['cancel']['#href'] = 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu['menu_name'];
  $form['#submit'][] = 'menu_delete_menu_confirm_submit';
  $form['#submit'][] = 'og_menu_delete_menu_confirm_submit';
  $form['#submit'][] = 'og_menu_delete_menu_confirm_submit_redirect';
  return $form;
}

/**
 * Form callback; Build the menu link editing form.
 */
function og_menu_edit_item_form($form, &$form_state, $type, $group_type, $gid, $menu, $item = array()) {
  module_load_include('inc', 'menu', 'menu.admin');
  $form = menu_edit_item($form, $form_state, $type, $item, $menu);
  // Set the breadcrumb now to override menu_edit_item() breadcrumb.
  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));
  $b = drupal_get_breadcrumb();
  $b[] = l(t('Menus'), 'group/' . $group_type . '/' . $gid . '/admin/menus');
  $b[] = l($menu['title'], 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu['menu_name']);
  drupal_set_breadcrumb($b);
  $list = array();
  $menus = og_menu_get_group_menus(array($group_type => array(0 => $gid)));
  foreach ($menus as $option) {
    $list[$option['menu_name']] = $option['title'];
  }

  // Set the title of the page.
  drupal_set_title(t('Add item into menu !mtitle', array('!mtitle' => $menu['title'])), PASS_THROUGH);


  // Build the form.
  $form['parent']['#options'] = menu_parent_options($list, array('mlid' => 0));
  $form['og_menu_group_type'] = array(
    '#type' => 'value',
    '#value' => $group_type,
  );
  $form['og_menu_gid'] = array(
    '#type' => 'value',
    '#value' => $gid,
  );
  $form['og_menu_name'] = array(
    '#type' => 'value',
    '#value' => $menu['menu_name'],
  );
  $form['#submit'][] = 'menu_edit_item_submit';
  $form['#submit'][] = 'og_menu_redirect';
  $form['#validate'][] = 'menu_edit_item_validate';
  if (!empty($item)) {
    $form['actions']['delete'] = array(
      '#type' => 'link',
      '#title' => 'Delete',
      '#href' => 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu['menu_name'] . '/item/' . $item['mlid'] . '/delete',
      '#weight' => 10,
    );
  }

  // Integrate with Menu Attributes if installed.
  if (module_exists('menu_attributes') && function_exists('_menu_attributes_form_alter')) {
    $item = $form['original_item']['#value'];
    _menu_attributes_form_alter($form, $item, $form);
  }

  // Integrate with Multi Path Autocomplete (mpac) if installed.
  if (module_exists('mpac')) {
     mpac_form_menu_edit_item_alter($form, $form_state);
  }

  return $form;
}

/**
 * Form callback for node/%node/og_menu/%menu/item/%menu_link/delete page.
 */
function og_menu_delete_item_form($form, &$form_state, $item, $group_type, $gid, $menu) {
  module_load_include('inc', 'menu', 'menu.admin');
  $form = menu_item_delete_form($form, $form_state, $item);
  $form_state['values']['link_path'] = $form['#item']['link_path'];
  $form['og_menu_group_type'] = array(
    '#type' => 'value',
    '#value' => $group_type,
  );
  $form['og_menu_gid'] = array(
    '#type' => 'value',
    '#value' => $gid,
  );
  $form['og_menu_name'] = array(
    '#type' => 'value',
    '#value' => $menu['menu_name'],
  );
  $form['#submit'][] = 'menu_item_delete_form_submit';
  $form['#submit'][] = 'og_menu_redirect';
  $form['actions']['cancel']['#href'] = 'group/' . $group_type . '/' . $gid . '/admin/menus/' . $menu['menu_name'];
  return $form;
}

/**
 * Callback for admin/structure/og_menu.
 *
 * Just duplicates the standard menu list, but only displays those created
 * through og_menu.
 */
function og_admin_menu_overview_form($form, $form_state) {
  $session = isset($_SESSION['og_menu_filter']) ? $_SESSION['og_menu_filter'] : array();

  // Get filter value from $_SESSION variable.
  foreach ($session as $filter) {
    list($type, $value) = $filter;
  }

  $form['filters'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => (isset($type)) ? FALSE : TRUE,
    '#title' => 'Filter',
    '#description' => 'Filter on the title of the OG menu.',
  );

  $form['filters']['og_menu_filter'] = array(
    '#type' => 'textfield',
    '#title' => t('Filter this out'),
    '#required' => FALSE,
    '#size' => 20,
    '#default_value' => isset($type) ? $value : '',
  );

  $form['filters']['og_menu_actions'] = array(
    '#type' => 'actions',
    '#attributes' => array('class' => array('container-inline')),
  );
  $form['filters']['og_menu_actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );
  if (count($session)) {
    $form['filters']['og_menu_actions']['reset'] = array('#type' => 'submit', '#value' => t('Reset'));
  }

  $header = array(
    'title' => array('data' => 'Title', 'field' => 'title', 'sort' => 'asc'),
    'type' => array('data' => 'Group Type', 'field' => 'group_type'),
    'list' => array('data' => 'Operations'),
    'edit' => array('data' => ''),
    'add' => array('data' => ''),
    'view' => array('data' => ''),
  );

  // Build Query (extend for paging and sorting).
  $query = db_select('menu_custom', 'mc')->extend('PagerDefault')->limit(20);
  // Pager Extender.
  $query->join('og_menu', 'om', 'mc.menu_name = om.menu_name');
  $query->fields('mc')
    ->fields('om')
    ->orderBy('title')
    ->extend('TableSort')
    ->orderByHeader($header);

  // Add conditional filter if enter by user.
  if (isset($type)) {
    $query->condition('title', '%' . $value . '%', 'LIKE');
  }

  $result = $query->execute();

  // Build table.
  $options = array();
  foreach ($result as $menu) {
    $options[$menu->menu_name] = array(
      'title' => array(
        'data' => theme('menu_admin_overview', array(
          'title' => $menu->title,
          'name' => $menu->menu_name,
          'description' => $menu->description,
        )),
      ),
      'type' => array('data' => $menu->group_type),
      'list' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('list links'),
          '#href' => 'admin/structure/menu/manage/' . $menu->menu_name,
        ),
      ),
      'edit' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('edit menu'),
          '#href' => 'admin/structure/menu/manage/' . $menu->menu_name . '/edit',
        ),
      ),
      'add' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('add link'),
          '#href' => 'admin/structure/menu/manage/' . $menu->menu_name . '/add',
        ),
      ),
      'view' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('view group'),
          '#href' => 'node/' . $menu->gid,
        ),
      ),
    );
  }

  $tableselect = array_sum(module_invoke_all('og_menu_admin_menu_overview_form_tableselect'));

  if ($tableselect) {
    $form['og_menu_menu_list'] = array(
      '#type' => 'tableselect',
      '#title' => t('Results'),
      '#header' => $header,
      '#options' => $options,
      '#empty' => 'Nothing to see',
      '#suffix' => theme('pager'),
    );
  }
  else {
    $output = theme('table', array('header' => $header, 'rows' => $options)) . theme('pager');
    $form['og_menu_menu_list'] = array(
      '#type' => 'markup',
      '#title' => t('Results'),
      '#markup' => $output,
    );
  }

  return $form;
}

/**
 * Process result from OG Menu administration filter form.
 */
function og_admin_menu_overview_form_submit($form, &$form_state) {
  switch ($form_state['clicked_button']['#id']) {
    case 'edit-submit':
      if (isset($form_state['values']['og_menu_filter']) && $form_state['values']['og_menu_filter'] != '') {
        $_SESSION['og_menu_filter'][] = array('og_menu_filter', $form_state['values']['og_menu_filter']);
      }
      break;

    case 'edit-reset':
      $_SESSION['og_menu_filter'] = array();
      break;
  }
}
