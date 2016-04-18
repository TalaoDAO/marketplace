<?php


class emh_merged_request_handler_field_last_answer_user extends views_handler_field {

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
    $options['label'] = array('default' => 'Who', 'translatable' => TRUE);
    return $options;
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    if ($values->{$this->aliases['type']} == 'webform') {
      $query = db_select('emh_answer', 'a');
      $query->join('webform_submissions', 'ws', 'a.request_id = ws.nid');
      $query->join('users', 'u', 'ws.uid = u.uid');
      $query->fields('a', array());
      $query->fields('ws', array());
      $query->fields('u', array());
      $query->condition('request_id', $values->{$this->aliases['nid']});
      $query->orderBy('ws.modified', 'DESC');
      $query->range(0, 1);

      $data = $query->execute()->fetchAssoc();

      return $data['name'];
    }
    else {
      $query = db_select('emh_answer', 'a');
      $query->join('comment', 'c', 'a.request_id = c.nid');
      $query->join('users', 'u', 'c.uid = u.uid');
      $query->fields('a', array());
      $query->fields('c', array());
      $query->fields('u', array());
      $query->condition('request_id', $values->{$this->aliases['nid']});
      $query->orderBy('c.changed', 'DESC');
      $query->range(0, 1);

      $data = $query->execute()->fetchAssoc();

      return $data['name'];
    }
  }

}
