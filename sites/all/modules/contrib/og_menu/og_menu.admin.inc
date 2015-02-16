<?php

/**
 * Form callback for OG Menu configuration.
 */
function og_menu_config_form($form, &$form_state) {

  $form['og_menu_block_links'] = array(
    '#type' => 'checkbox',
    '#title' => t('Convert OG Menu block titles into links'),
    '#default_value' => variable_get('og_menu_block_links', FALSE),
    '#description' => t('If enabled, OG Menu block titles will link to the groupnode.'),
  );

  $form['og_menu_max_menus_per_group'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of menus per group'),
    '#default_value' => variable_get('og_menu_max_menus_per_group', 1),
    '#size' => 20,
    '#maxlength' => 5,
    '#required' => TRUE,
    '#description' => t("Enter 0 for no limit. Users with the 'administer menu' permission will be able to bypass this."),
  );

  // Performance related settings.
  $form['performance'] = array(
    '#type' => 'fieldset',
    '#title' => t('Performance related settings'),
  );

  $form['performance']['og_menu_context_limit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Limit available menus to provided context'),
    '#default_value' => variable_get('og_menu_context_limit', FALSE),
    '#description' => t('If enabled, instead of loading all available menus on node creation or editing, og menu will only load menus associated with the current context. On sites with a lot of (group) menus this can greatly improve page performance.'),
  );

  $form['performance']['og_menu_assignment'] = array(
    '#type' => 'radios',
    '#options' => array(
      'select' => t('Select list'),
      'autocomplete' => t('Textbox with autocomplete'),
    ),
    '#title' => t('Group assignment field on menu admin page'),
    '#default_value' => variable_get('og_menu_assignment', 'autocomplete'),
    '#required' => 'TRUE',
    '#description' => t('Autocomplete is recommended when you have a lot of organic groups.'),
  );

  // Automatic menu creation.
  $form['auto'] = array(
    '#type' => 'fieldset',
    '#title' => t('Automatic menu creation'),
  );

  $form['auto']['og_menu_create_by_default'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically create menu for new Organic Group'),
    '#default_value' => variable_get('og_menu_create_by_default', FALSE),
    '#description' => t('If enabled, an OG Menu will be created by default when a new Organic Group node is created.'),
  );

  $form['auto']['og_menu_hide_create_option'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide "Enable menu for this group"'),
    '#default_value' => variable_get('og_menu_hide_create_option', FALSE),
    '#description' => t('If enabled, "Enable menu for this group" will be hidden in the node edit form.'),
    '#states' => array(
      'visible' => array(
        ':input[name=og_menu_create_by_default]' => array('checked' => TRUE),
      ),
    ),
  );

  // Visibility setting to hide OG Menus on selected pages.
  $form['hiding'] = array(
    '#type' => 'fieldset',
    '#title' => t('Admin page visibility'),
    '#description' => t("On sites with multiple OG Menus it might be preferable to hide them in places where you don't need them."),
  );

  $form['hiding']['og_menu_show_blocks'] = array(
    '#type' => 'checkbox',
    '#title' => t("Show blocks for individual OG Menus"),
    '#default_value' => variable_get('og_menu_show_blocks', FALSE),
    '#description' => t("If disabled, blocks for OG Menus will be hidden from the block administration page."),
  );

  $form['hiding']['og_menu_show_nodetype'] = array(
    '#type' => 'checkbox',
    '#title' => t("Include OG Menus in node type menu settings"),
    '#default_value' => variable_get('og_menu_show_nodetype', FALSE),
    '#description' => t("If disabled, OG Menus will be hidden from the node type config page."),
  );

  if (module_exists('menu_position')) {
    $form['hiding']['og_menu_show_menuposition'] = array(
      '#type' => 'checkbox',
      '#title' => t("Show as available parent in menu position rules."),
      '#default_value' => variable_get('og_menu_show_menuposition', FALSE),
      '#description' => t("If disabled, OG Menus will be hidden from the menu position parent selection dropdown."),
    );
  }

  if (module_exists('homebox')) {
    $form['hiding']['og_menu_show_homebox'] = array(
      '#type' => 'checkbox',
      '#title' => t("Show blocks in Homebox admin page"),
      '#default_value' => variable_get('og_menu_show_homebox', FALSE),
      '#description' => t("If disabled, blocks for OG Menus will be hidden from the homebox administration page."),
    );
  }

  if (module_exists('block')) {
    // Visibility setting to hide help.
    $form['help'] = array(
      '#type' => 'fieldset',
      '#title' => t('Help visibility'),
      '#description' => t("On sites it might be preferable to hide help."),
    );
    $form['help']['og_menu_hide_help'] = array(
      '#type' => 'checkbox',
      '#title' => t("Disable module specific help."),
      '#default_value' => variable_get('og_menu_show_help', FALSE),
      '#description' => t("If enabled, help will not display on the site."),
    );
  }

  return system_settings_form($form);
}

/**
 * Validation for OG Menu config form.
 */
function og_menu_config_form_validate($form, &$form_state) {
  $max_num = $form_state['values']['og_menu_max_menus_per_group'];
  if (!is_numeric($max_num)) {
    form_set_error('og_menu_max_menus_per_group', t('You must enter an integer for the maximum number of menus per group.'));
  }
  elseif ($max_num < 0) {
    form_set_error('og_menu_max_menus_per_group', t('Maximum number of menus per group must be positive.'));
  }
}
