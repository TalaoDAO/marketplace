<?php

/**
 * @file
 * Views field handler for the views_system module.
 */

class views_extra_handlers_handler_field_query_alter extends views_handler_field {

 function query() {
  if(!empty($this->options['veh_join']['veh_table'])){
   $def = $this->definition;
   $def['table'] = $this->options['veh_join']['veh_table'];
   $def['field'] = $this->options['veh_join']['veh_column'];
   $def['left_table'] = $this->options['veh_join']['veh_left_table'];
   $def['left_field'] = $this->options['veh_join']['veh_left_column'];
   $def['type'] = $this->options['veh_join']['veh_join_type'];
   if(!empty($this->options['veh_join']['veh_join_condition'])){
     $def['left_query'] = $this->options['veh_join']['veh_join_condition'];
   }else{
     $def['left_query'] = $this->options['veh_join']['veh_left_table'] . "." . $this->options['veh_join']['veh_left_column'];
   }
 
   if (!empty($def['join_handler']) && class_exists($def['join_handler'])) {
    $join = new $def['join_handler'];
   }
   else {
    $join = new views_join_subquery();
   }
 
   $join->definition = $def;
   $join->construct();
   $join->adjusted = TRUE;
 
   // use a short alias for this:
   $alias = $this->options['veh_join']['veh_table_alias'];
 
  // $this->alias = $this->query->add_relationship($alias, $join, $this->definition['base']);
   $this->alias = $this->query->add_relationship($alias, $join, NULL); 
  }
  if(!empty($this->options['veh_field']['veh_table'])){  
    $this->field_alias = $this->query->add_field($this->options['veh_field']['veh_table'], $this->options['veh_field']['veh_column'], '');
  }
  if(!empty($this->options['veh_where']['veh_table'])){  
    $condition_type = db_condition($this->options['veh_where']['veh_where_type']);
    //***CURRENT_ARG_1***
    $where_field_value = $this->options['veh_where']['veh_value'];
    if(veh_startsWith($where_field_value, "***CURRENT_ARG_") && veh_endsWith($where_field_value, "***")){
      $argument_pos = substr($where_field_value,15,strlen($where_field_value)-15-3);
    	$where_field_value = arg($argument_pos);
    }
	  $condition = $condition_type->condition($this->options['veh_where']['veh_table'].'.'.$this->options['veh_where']['veh_column'], $where_field_value, $this->options['veh_where']['veh_where_operator']);
	  $this->query->add_where(0, $condition);  
  }
 }

 function option_definition() {
  $options = parent::option_definition();
  $options['veh_field']['veh_table'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_field']['veh_column'] = array('default' => '', 'translatable' => FALSE);
  
  $options['veh_where']['veh_where_type'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_where']['veh_table'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_where']['veh_column'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_where']['veh_value'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_where']['veh_where_operator'] = array('default' => '', 'translatable' => FALSE);


  $options['veh_join']['veh_table'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_join']['veh_table_alias'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_join']['veh_column'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_join']['veh_join_type'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_join']['veh_join_condition'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_join']['veh_left_table'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_join']['veh_left_column'] = array('default' => '', 'translatable' => FALSE);
  
  $options['veh_groupby']['veh_add'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_groupby']['veh_remove'] = array('default' => '', 'translatable' => FALSE);
  
  $options['veh_union']['veh_union_view_name'] = array('default' => '', 'translatable' => FALSE);
  $options['veh_union']['veh_union_view_display'] = array('default' => '', 'translatable' => FALSE);
  
  $options['veh_orderby']['veh_orderby_date'] = array('default' => '', 'translatable' => FALSE);
  
  return $options;
 }

 function options_form(&$form, &$form_state) {
  parent::options_form($form, $form_state);
  $form['veh_field'] = array(
    '#type' => 'fieldset',
    '#title' => t('Field'),
    '#collapsible' => TRUE,
  );
  $form['veh_field']['veh_table'] = array(
    '#type' => 'textfield',
    '#title' => t('Table'),
    '#default_value' => $this->options['veh_field']['veh_table'],
  );
  $form['veh_field']['veh_column'] = array(
    '#type' => 'textfield',
    '#title' => t('Field'),
    '#default_value' => $this->options['veh_field']['veh_column'],
  );
  
  $form['veh_where'] = array(
    '#type' => 'fieldset',
    '#title' => t('Where'),
    '#collapsible' => TRUE,
  );
  $form['veh_where']['veh_where_type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array(
      'AND' => t('AND'),
      'OR' => t('OR'),
    ),
    '#default_value' => $this->options['veh_where']['veh_where_type'],
    '#description' => t('Type of Condition.'),
  );
  $form['veh_where']['veh_table'] = array(
    '#type' => 'textfield',
    '#title' => t('Where Table'),
    '#default_value' => $this->options['veh_where']['veh_table'],
  );
  $form['veh_where']['veh_column'] = array(
    '#type' => 'textfield',
    '#title' => t('Where Field'),
    '#default_value' => $this->options['veh_where']['veh_column'],
  );
  $form['veh_where']['veh_value'] = array(
    '#type' => 'textfield',
    '#title' => t('Field Value'),
    '#default_value' => $this->options['veh_where']['veh_value'],
  );
  $form['veh_where']['veh_where_operator'] = array(
    '#type' => 'select',
    '#title' => t('Operator'),
    '#options' => array(
      '=' => t('='),
      'LIKE' => t('LIKE'),
    ),
    '#default_value' => $this->options['veh_where']['veh_where_operator'],
    '#description' => t('Operator'),
  );

  $form['veh_join'] = array(
    '#type' => 'fieldset',
    '#title' => t('Join'),
    '#collapsible' => TRUE,
  );
  $form['veh_join']['veh_join_type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array(
      'INNER' => t('INNER'),
      'LEFT' => t('LEFT'),
      'RIGHT' => t('RIGHT'),
    ),
    '#default_value' => $this->options['veh_join']['veh_join_type'],
    '#description' => t('Type of Join.'),
  );
  $form['veh_join']['veh_table'] = array(
    '#type' => 'textfield',
    '#title' => t('Join Table'),
    '#default_value' => $this->options['veh_join']['veh_table'],
  );
  $form['veh_join']['veh_table_alias'] = array(
    '#type' => 'textfield',
    '#title' => t('Join Table Alias'),
    '#default_value' => $this->options['veh_join']['veh_table_alias'],
  );
  $form['veh_join']['veh_column'] = array(
    '#type' => 'textfield',
    '#title' => t('Join Field'),
    '#default_value' => $this->options['veh_join']['veh_column'],
  );
  $form['veh_join']['veh_join_condition'] = array(
    '#type' => 'textfield',
    '#title' => t('Join Condition'),
    '#default_value' => $this->options['veh_join']['veh_join_condition'],
    '#description' => t('If this is emplty, "Left Table"."Left Field" will be used as condition.'),
  ); 
  $form['veh_join']['veh_left_table'] = array(
    '#type' => 'textfield',
    '#title' => t('Left Table'),
    '#default_value' => $this->options['veh_join']['veh_left_table'],
  );
  $form['veh_join']['veh_left_column'] = array(
    '#type' => 'textfield',
    '#title' => t('Left Field'),
    '#default_value' => $this->options['veh_join']['veh_left_column'],
  );
  
  $form['veh_groupby'] = array(
    '#type' => 'fieldset',
    '#title' => t('Groupby'),
    '#collapsible' => TRUE,
  );
  $form['veh_groupby']['veh_add'] = array(
    '#type' => 'textarea',
    '#title' => t('Add'),
    '#default_value' => $this->options['veh_groupby']['veh_add'],
    '#rows' => 2,
    '#description' => t('Seperate multiple entries by ,'),    
  );
  $form['veh_groupby']['veh_remove'] = array(
    '#type' => 'textarea',
    '#title' => t('Remove'),
    '#default_value' => $this->options['veh_groupby']['veh_remove'],
    '#rows' => 2,
    '#description' => t('Seperate multiple entries by ,'),
  );
  
  $form['veh_orderby'] = array(
    '#type' => 'fieldset',
    '#title' => t('Orderby'),
    '#collapsible' => TRUE,
  );
  $form['veh_orderby']['veh_orderby_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Alias name of the date field to be Sorted by Current Date.'),
    '#default_value' => $this->options['veh_orderby']['veh_orderby_date'],
    '#description' => t('Upcoming posts will be at the top sorted by ascending order. Past posts will be below Upcoming posts sorted by descending order.'),
  );
  $form['veh_orderby']['veh_orderby_custom'] = array(
    '#type' => 'textarea',
    '#title' => t('Sort by Custom query'),
    '#default_value' => $this->options['veh_orderby']['veh_orderby_custom'],
    '#rows' => 2,
    '#description' => t('Example query: (CASE WHEN node.created < CURRENT_TIMESTAMP THEN node.created END)'), 
  );
  $form['veh_orderby']['veh_orderby_direction'] = array(
    '#type' => 'select',
    '#title' => t('Direction'),
    '#options' => array(
      'ASC' => t('ASC'),
      'DESC' => t('DESC'),
    ),
    '#default_value' => $this->options['veh_orderby']['veh_orderby_direction'],
    '#description' => t('Sort in Ascending or Descending order?'),
  );
  
  $form['veh_union'] = array(
    '#type' => 'fieldset',
    '#title' => t('Union'),
    '#collapsible' => TRUE,
  );
  $form['veh_union']['veh_union_view_name'] = array(
    '#type' => 'textfield',
    '#title' => t('View id'),
    '#default_value' => $this->options['veh_union']['veh_union_view_name'],
  );
  $form['veh_union']['veh_union_view_display'] = array(
    '#type' => 'textfield',
    '#title' => t('View display id'),
    '#default_value' => $this->options['veh_union']['veh_union_view_display'],
  );
}
 /*
  function options_submit(&$form, &$form_state) {
 $form_state['values']['options']['format'] = $form_state['values']['options']['content']['format'];
 $form_state['values']['options']['content'] = $form_state['values']['options']['content']['value'];
 parent::options_submit($form, $form_state);
 }
 */
 function render($values) {
  $data = '';
  if(isset($this->field_alias) && !empty($this->field_alias) && $this->field_alias != "unknown"){
    $data = $values->{$this->field_alias};
  }
  return $data;
 }
}