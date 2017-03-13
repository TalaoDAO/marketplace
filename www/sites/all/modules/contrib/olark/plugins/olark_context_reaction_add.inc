<?php
/**
 * @file
 * Adds a Context module reaction for the Olark module.
 */

/**
 * Add Olark code to the page.
 */
class olark_context_reaction_add extends context_reaction {

  function options_form($context) {
    return array(
      'add' => array('#type' => 'value', '#value' => TRUE),
      'note' => array('#type' => 'markup', '#value' => t('Olark chat code will be added to the page.')),
    );
  }

  function options_form_submit($values) {
    return array('add' => 1);
  }

  function execute() {
    $contexts = $this->get_contexts();
    foreach ($contexts as $context) {
      if (!empty($context->reactions[$this->plugin])) {
        return TRUE;
      }
    }
  }
}
