<?php

/**
 * @file
 * Views data and handlers for the views_system module.
 */

/**
 * Implements hook_views_data()
 */
function views_extra_handlers_views_data() {

 // Define the base group of this table. Fields that don't
 // have a group defined will go into this field by default.
 $data['node_type']['table']['group']  = t('Node Type');

 // Advertise this table as a possible base table
 $data['node_type']['table']['base'] = array(
   'field' => 'type',
   'title' => t('Node Type'),
   'help' => t("Node Types."),
 );

 // ----------------------------------------------------------------
 // Fields

 // title
 $data['node_type']['type'] = array(
   'title' => t('type'), // The item it appears as on the UI,
   'help' => t('The type of the node.'),
   // Information for displaying a title as a field
   'field' => array(
     'handler' => 'views_handler_field',
     'click sortable' => TRUE,
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
   // Information for accepting a title as a filter
   'filter' => array(
     'handler' => 'views_handler_filter_node_type',
   ),
 );

 // name
 $data['node_type']['name'] = array(
   'title' => t('name'), // The item it appears as on the UI,
   'help' => t('The name of the type.'),
   // Information for displaying a title as a field
   'field' => array(
     'handler' => 'views_handler_field',
     'click sortable' => TRUE,
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
   // Information for accepting a title as a filter
   'filter' => array(
     'handler' => 'views_handler_filter_string',
   ),
 );


 // feed body
 $data['node_type']['description'] = array(
   'title' => t('Body'), // The item it appears as on the UI,
   'help' => t('The actual content of the imported item.'),
   // Information for displaying a title as a field
   'field' => array(
     'handler' => 'views_handler_field_xss',
     'click sortable' => FALSE,
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
   // Information for accepting a title as a filter
   'filter' => array(
     'handler' => 'views_handler_filter_string',
   ),
 );

 ////////////////////////////////////////////////////////
 //fields info per node type
 // have a group defined will go into this field by default.
 $data['field_config_instance']['table']['group']  = t('Fields');

 // Advertise this table as a possible base table
 $data['field_config_instance']['table']['base'] = array(
   'field' => 'id',
   'title' => t('Fields'),
   'help' => t("Fields Info."),
 );

 // ----------------------------------------------------------------
 // Fields

 // item id.
 $data['field_config_instance']['id'] = array(
   'title' => t('ID'),
   'help' => t('The unique ID of the Field.'),
   'field' => array(
     'handler' => 'views_handler_field_numeric',
     'click sortable' => TRUE,
   ),
   'argument' => array(
     'handler' => 'views_handler_argument_numeric',
     'numeric' => TRUE,
   ),
   'filter' => array(
     'handler' => 'views_handler_filter_numeric',
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
 );

 // field_id.
 $data['field_config_instance']['field_id'] = array(
   'title' => t('field_id'),
   'help' => t('The field_id of the Field.'),
   'field' => array(
     'handler' => 'views_handler_field_numeric',
     'click sortable' => TRUE,
   ),
   'argument' => array(
     'handler' => 'views_handler_argument_numeric',
     'numeric' => TRUE,
   ),
   'filter' => array(
     'handler' => 'views_handler_filter_numeric',
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
 );

 // title
 $data['field_config_instance']['field_name'] = array(
   'title' => t('field_name'), // The item it appears as on the UI,
   'help' => t('The field_name of the field.'),
   // Information for displaying a title as a field
   'field' => array(
     'handler' => 'views_handler_field',
     'click sortable' => TRUE,
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
   // Information for accepting a title as a filter
   'filter' => array(
     'handler' => 'views_handler_filter_string',
   ),
 );

 // name
 $data['field_config_instance']['entity_type'] = array(
   'title' => t('entity_type'), // The item it appears as on the UI,
   'help' => t('The entity_type of the field.'),
   // Information for displaying a title as a field
   'field' => array(
     'handler' => 'views_handler_field',
     'click sortable' => TRUE,
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
   // Information for accepting a title as a filter
   'filter' => array(
     'handler' => 'views_handler_filter_string',
   ),
 );

 // bundle
 $data['field_config_instance']['bundle'] = array(
   'title' => t('bundle'), // The item it appears as on the UI,
   'help' => t('The bundle of the field.'),
   // Information for displaying a title as a field
   'field' => array(
     'handler' => 'views_handler_field',
     'click sortable' => TRUE,
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
   // Information for accepting a title as a filter
   'filter' => array(
     'handler' => 'views_handler_filter_string',
   ),
 );

 // Table field: system.info
 $data['field_config_instance']['data'] = array(
   'title' => t('Data'),
   'help' => t('A serialized array containing information.'),
   'field' => array(
     'handler' => 'views_handler_field_serialized',
   ),
   'argument' => array(
     'handler' => 'views_handler_argument_string',
     'name field' => 'info',
   ),
   'filter' => array(
     'handler' => 'views_handler_filter_string',
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
 );

 $data['field_config_instance']['data_widget'] = array(
   'real field' => 'data',
   'title' => t('Widget'),
   'help' => t('The Widget of the field.'),
   'field' => array(
     'handler' => 'views_extra_handlers_handler_field_field_config_instance_data_widget',
   ),
   'filter' => array(
     'handler' => 'views_extra_handlers_handler_filter_field_config_instance_data_widget',
     'label' => t('Widget'),
   ),
 );

 // nid
 $data['node_revision']['promote'] = array(
   'title' => t('Revision Promoted to front page'),
   'help' => t('Whether or not the revision is promoted to the front page.'),
   'field' => array(
     'handler' => 'views_handler_field_boolean',
     'click sortable' => TRUE,
     'output formats' => array(
       'promoted-notpromoted' => array(t('Promoted'), t('Not promoted')),
     ),
   ),
   'filter' => array(
     'handler' => 'views_handler_filter_boolean_operator',
     'label' => t('Revision Promoted to front page'),
     'type' => 'yes-no',
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
 );

 $data['node_revision']['status'] = array(
   'title' => t('Revision Publish Status'),
   'help' => t('Whether or not the revision is published.'),
   'field' => array(
     'handler' => 'views_handler_field_boolean',
     'click sortable' => TRUE,
     'output formats' => array(
       'published-notpublished' => array(t('Published'), t('Not published')),
     ),
   ),
   'filter' => array(
     'handler' => 'views_handler_filter_boolean_operator',
     'label' => t('Revision Published'),
     'type' => 'yes-no',
   ),
   'sort' => array(
     'handler' => 'views_handler_sort',
   ),
 );
 $data['views']['query_alter'] = array(
   'title' => t('Query Alter'),
   'help' => t('Alter Query.'),
   'field' => array(
     'handler' => 'views_extra_handlers_handler_field_query_alter',
   ),
 );
 return $data;
}