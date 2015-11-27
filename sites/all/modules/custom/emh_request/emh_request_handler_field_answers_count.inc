<?php


class emh_request_handler_field_answers_count extends views_handler_field {

  function construct() {
    parent::construct();
    //$this->count_type = $this->definition['count_type'];

//    if ($this->count_type == 'node') {
      $this->additional_fields['nid'] = 'nid';
      $this->additional_fields['type'] = 'type';
//    }
//    elseif ($this->count_type == 'users') {
//      $this->additional_fields['uid'] = 'uid';
//    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['label'] = array('default' => '# of answers', 'translatable' => TRUE);
    return $options;
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $output = db_select('emh_answer')
      ->condition('request_id', $values->{$this->aliases['nid']})
      //->condition('uid', $values->{$this->aliases['uid']})
      ->countQuery()->execute()->fetchField();

    return $output;
  }

}
