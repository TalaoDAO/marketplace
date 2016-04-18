<?php

/**
 * @file
 * Views field handler for the views_system module.
 */

class views_extra_handlers_handler_field_field_config_instance_data_widget extends views_handler_field {

  function render($values) {
    $data = unserialize($values->{$this->field_alias});
		if(isset($data['widget'])){
			return $data['widget']['type'];
		}else{
			return '';
		}
    //return isset($info['engine']) ? $info['engine'] : '';
  }
}