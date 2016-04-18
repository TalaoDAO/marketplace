<?php
/**
 * @file
 * Views handler to display the number of submissions in a webform.
 */


/**
 * Field handler to present the submission count of a webform to the user.
 */
class emh_mission_handler_field_submission_count extends webform_handler_field_submission_count {

  public function render($values) {
    global $user;

    if ($this->count_type == 'node'
      && variable_get('webform_node_' . $values->{$this->aliases['type']}, FALSE)
      && in_array('expert', $user->roles)) {

      module_load_include('inc', 'webform', 'includes/webform.submissions');
      $node = node_load($values->{$this->aliases['nid']});
      return webform_get_submission_count($node->nid);
    }

    return parent::render($values);
  }

}
