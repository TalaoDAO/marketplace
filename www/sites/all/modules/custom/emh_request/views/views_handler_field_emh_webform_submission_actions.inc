<?php

class views_handler_field_emh_webform_submission_actions extends views_handler_field {

  /**
   * Add additional fields.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['sid'] = 'sid';
  }

  /**
   * Define our additional configuration setting.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Renders our field, displays the answer.
   */
  function render($values) {
    if (isset($values->{$this->aliases['nid']})) {
      $nid = $values->{$this->aliases['nid']};
    }
    else {
      return 0;
    }
    if (isset($values->{$this->aliases['sid']})) {
      $sid = $values->{$this->aliases['sid']};
    }
    else {
      return 0;
    }

    module_load_include('inc', 'webform', 'includes/webform.submissions');
    $submission = webform_get_submission($nid, $sid);
    $node = node_load($nid);

    $view = ''; $edit = ''; $delete = ''; $flag = '';
    if (webform_submission_access($node, $submission, 'view')) {
      $text = !empty($text) ? $text : t('view');
      $view = l(t('view'), "node/$nid/submission/$sid", array('attributes' => array('class' => array('submission-link', 'view'))));
    }
    if (webform_submission_access($node, $submission, 'edit')) {
      $text = !empty($text) ? $text : t('edit');
      $edit = l($text, "node/$nid/submission/$sid/edit", array('attributes' => array('class' => array('submission-link', 'edit'))));
    }
    if (webform_submission_access($node, $submission, 'delete')) {
      $text = !empty($text) ? $text : t('delete');
      $path = drupal_get_path_alias($_GET['q']);
      $delete = l($text, "node/$nid/submission/$sid/delete", array('attributes' => array('class' => array('submission-link', 'delete')), 'query' => array('destination' => $path)));
    }
    if (!empty(flag_create_link('interesting_answer', $sid))) {
      $flag = flag_create_link('interesting_answer', $sid);
    }

    if (!empty($view) || !empty($edit) || !empty($delete) || !empty($flag)) {
      return '<p>' . $view . $edit . $delete . $flag . '</p>';
    }
  }

  /**
   * Only display the column for users with the appropriate permission.
   */
  function access() {
    return TRUE;
  }

  /**
   * Just do some basic checks.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

}
