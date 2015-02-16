<?php

/**
 * @file
 * Administration pages for Comment Permissions module.
 */

/**
 * Menu callback; presents the comment_perm settings page.
 */
function comment_perm_admin_settings() {
  $form = array();
  $form['help'] = array(
    '#prefix' => '<p>',
    '#value' => t('Enable the extended comment permissions for certain content
      types here. Then go to !administer_permissions to configure which roles
      can post comments for these content types.', array('!administer_permissions' => l('administer permissions', 'admin/user/permissions'))),
    '#suffix' => '</p>',
  );

  // get node types
  $node_types = node_type_get_types();
  foreach ($node_types as $type => $obj) {
    switch (variable_get('comment_' . $type, COMMENT_NODE_OPEN)) {
      case COMMENT_NODE_CLOSED:
        $status = '<em> (comments are currently read only)</em>';
        break;
      case COMMENT_NODE_OPEN:
        $status = '';
        break;
      case COMMENT_NODE_HIDDEN:
        $status = '<em>  (comments are currently disabled)</em>';
        break;
    }
    $types[$type] = $obj->name . $status;
  }

  $form['comment_perm_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enable comment permissions by role for these content types'),
    '#default_value' => variable_get('comment_perm_node_types', array()),
    '#options' => $types,
  );

  $form['comment_perm_hide_comments'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide comments entirely'),
    '#default_value' => variable_get('comment_perm_hide_comments', 0),
    '#description' => t('Comments will be hidden entirely for users without permission to post comments.  If unchecked, the messages set below will be shown instead.'),
  );

  $form['comment_perm_message_anon'] = array(
    '#type' => 'textfield',
    '#disabled' => 'disabled',
    '#title' => t('Commenting denied message for anonymous users'),
    '#default_value' => variable_get('comment_perm_message_anon', t('Login or register to post comments!')),
    '#description' => t('This setting is no longer used.  Comment Permissions now uses the theme function provided by core, see <a href="http://api.drupal.org/api/function/theme_comment_post_forbidden/6">theme_comment_post_forbidden()</a> to override this message. Ideally commentting will be invisible to those without permission to post.'),
  );

  $form['comment_perm_message_reg'] = array(
    '#type' => 'textfield',
    '#title' => t('Commenting denied message for registered users'),
    '#default_value' => variable_get('comment_perm_message_reg', t("We're sorry, but you can't post comments here!")),
    '#description' => t('Ideally commentting will be invisible to those without permission to post, but
                         just in case you can specify the message they will see.'),
  );

  return system_settings_form($form);
}
