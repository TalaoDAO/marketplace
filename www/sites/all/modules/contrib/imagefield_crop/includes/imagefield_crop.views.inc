<?php

function imagefield_crop_field_views_data($field) {
  $data = field_views_field_default_views_data($field);
  foreach ($data as $table_name => $table_data) {
    // Add the relationship only on the fid field.
    $data[$table_name][$field['field_name'] . '_fid']['relationship'] = array(
      'handler' => 'views_handler_relationship',
      'base' => 'file_managed',
      'base field' => 'fid',
      'label' => t('image from !field_name', array('!field_name' => $field['field_name'])),
    );
  }

  return $data;
}
