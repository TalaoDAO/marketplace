<?php


class emh_merged_request_handler_field_generic extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['answer_id'] = 'answer_id';
    $this->additional_fields['request_id'] = 'request_id';
    $this->additional_fields['ref_entity_type'] = 'ref_entity_type';
    $this->additional_fields['ref_entity_id'] = 'ref_entity_id';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['label'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $answer_type = $values->{$this->aliases['ref_entity_type']};
    $request = node_load($values->{$this->aliases['request_id']});

    if ($answer_type == 'comment') {
      $answer = comment_load($values->{$this->aliases['ref_entity_id']});
    } else {
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      $answer = webform_get_submission($request->nid, $values->{$this->aliases['ref_entity_id']});
    }

    $user = user_load($answer->uid);

    switch ($this->real_field) {
      case 'request_type':
        return $request->type;

      case 'request_title':
        return $request->title;

      case 'creation_date':
        $date = ($answer_type == 'comment') ? $answer->created : $answer->completed;
        return format_date($date);

      case 'body':
        return ($answer_type == 'comment') ? $answer->subject : '';
    }
  }

}
