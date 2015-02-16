<?php
/**
 * @file
 * Administrative interface for block group module.
 */

/**
 * Form constructor for the add block form.
 *
 * Leverage block_admin_configure from block.module to actually build the form.
 * Customization is supplied via hook_block_configure().
 *
 * @see blockgroup_add_form_validate()
 * @see blockgroup_add_form_submit()
 * @ingroup forms
 */
function blockgroup_add_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'block', 'block.admin');
  return block_admin_configure($form, $form_state, 'blockgroup', NULL);
}


/**
 * Form validation handler for blockgrop_add_form().
 *
 * @see blockgrop_add_form()
 * @see blockgrop_add_form_submit()
 */
function blockgroup_add_form_validate($form, &$form_state) {
  $form_state['values']['delta'] = $form_state['values']['machine_name'];
  return block_admin_configure_validate($form, $form_state);
}


/**
 * Form submission handler for blockgrop_add_form().
 *
 * Construct new block group.
 *
 * @see blockgrop_add_form()
 * @see blockgrop_add_form_validate()
 */
function blockgroup_add_form_submit($form, &$form_state) {
  $blockgroup = (object) array(
    'title' => $form_state['values']['title'],
    'delta' => $form_state['values']['delta'],
  );

  blockgroup_add($blockgroup);

  // Call through to the block administration handler in order to save all the
  // settings.
  block_admin_configure_submit($form, $form_state);
}


/**
 * Form constructor for the custom block deletion form.
 *
 * @param object $blockgroup
 *   The block group object which should be deleted.
 *
 * @see blockgroup_delete_confirm_submit()
 */
function blockgroup_delete_confirm($form, &$form_state, $blockgroup) {
  $form_state['blockgroup'] = $blockgroup;

  return confirm_form($form, t('Are you sure you want to delete the block group %title?', array('%title' => $blockgroup->title)), 'admin/structure/block', '', t('Delete'), t('Cancel'));
}


/**
 * Form submission handler for blockgroup_delete_confirm().
 *
 * @see blockgroup_delete_confirm()
 */
function blockgroup_delete_confirm_submit($form, &$form_state) {
  $blockgroup = $form_state['blockgroup'];
  blockgroup_delete($blockgroup);

  drupal_set_message(t('The block group %title has been removed.', array('%title' => $blockgroup->title)));
  $form_state['redirect'] = 'admin/structure/block';
}
