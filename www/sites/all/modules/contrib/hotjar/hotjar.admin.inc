<?php
/**
 * @file
 * Administrative page callbacks for the hotjar module.
 */

/**
 * Hotjar settings form.
 */
function hotjar_admin_settings_form($form_state) {
  $form = array();

  $settings = hotjar_get_settings();
  $form['hotjar_account'] = array(
    '#parents' => array('hotjar_settings', 'hotjar_account'),
    '#title' => t('Hotjar ID'),
    '#type' => 'textfield',
    '#default_value' => $settings['hotjar_account'],
    '#size' => 15,
    '#maxlength' => 20,
    '#required' => TRUE,
    '#description' => t('Your Hotjar ID can be found in your tracking code on the line <code>h._hjSettings={hjid:<b>12345</b>,hjsv:5};</code> where <code><b>12345</b></code> is your Hotjar ID'),
  );

  $form['tracking'] = array(
    '#type' => 'vertical_tabs',
  );

  $visibility = $settings['hotjar_visibility_pages'];
  $pages = $settings['hotjar_pages'];

  $form['tracking']['page_track'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pages'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  if ($visibility == 2) {
    $form['tracking']['page_track'] = array();
    $form['tracking']['page_track']['hotjar_visibility_pages'] = array('#type' => 'value', '#value' => 2);
    $form['tracking']['page_track']['hotjar_pages'] = array('#type' => 'value', '#value' => $pages);
  }
  else {
    $options = array(
      t('Every page except the listed pages'),
      t('The listed pages only'),
    );
    $description_args = array(
      '%blog' => 'blog',
      '%blog-wildcard' => 'blog/*',
      '%front' => '<front>',
    );
    $description = t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", $description_args);
    $title = t('Pages');
    $form['tracking']['page_track']['hotjar_visibility_pages'] = array(
      '#parents' => array('hotjar_settings', 'hotjar_visibility_pages'),
      '#type' => 'radios',
      '#title' => t('Add tracking to specific pages'),
      '#options' => $options,
      '#default_value' => $visibility,
    );
    $form['tracking']['page_track']['hotjar_pages'] = array(
      '#parents' => array('hotjar_settings', 'hotjar_pages'),
      '#type' => 'textarea',
      '#title' => $title,
      '#title_display' => 'invisible',
      '#default_value' => $pages,
      '#description' => $description,
      '#rows' => 10,
    );
  }

  // Render the role overview.
  $form['tracking']['role_track'] = array(
    '#type' => 'fieldset',
    '#title' => t('Roles'),
  );

  $form['tracking']['role_track']['hotjar_visibility_roles'] = array(
    '#parents' => array('hotjar_settings', 'hotjar_visibility_roles'),
    '#type' => 'radios',
    '#title' => t('Add tracking for specific roles'),
    '#options' => array(
      t('Add to the selected roles only'),
      t('Add to every role except the selected ones'),
    ),
    '#default_value' => $settings['hotjar_visibility_roles'],
  );

  $role_options = array_map('check_plain', user_roles());
  $form['tracking']['role_track']['hotjar_roles'] = array(
    '#parents' => array('hotjar_settings', 'hotjar_roles'),
    '#type' => 'checkboxes',
    '#title' => t('Roles'),
    '#default_value' => $settings['hotjar_roles'],
    '#options' => $role_options,
    '#description' => t('If none of the roles are selected, all users will be tracked. If a user has any of the roles checked, that user will be tracked (or excluded, depending on the setting above).'),
  );

  return system_settings_form($form);
}
