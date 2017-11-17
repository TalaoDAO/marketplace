<?php
/**
 * @file
 * ft_field_base.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ft_field_base_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'.
  $field_bases['body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'comment_body'.
  $field_bases['comment_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'comment',
    ),
    'field_name' => 'comment_body',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'entity_legal_document_text'.
  $field_bases['entity_legal_document_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'entity_legal_document_version',
    ),
    'field_name' => 'entity_legal_document_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_address'.
  $field_bases['field_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_address',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'addressfield',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'addressfield',
  );

  // Exported field_base: 'field_anonymous'.
  $field_bases['field_anonymous'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_anonymous',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Display my full name',
        1 => 'Hide my full name',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_autoref'.
  $field_bases['field_autoref'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_autoref',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'serial',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'serial',
  );

  // Exported field_base: 'field_availability'.
  $field_bases['field_availability'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_availability',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_background'.
  $field_bases['field_background'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_background',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_call_question'.
  $field_bases['field_call_question'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_call_question',
    'field_permissions' => array(
      'owner_field' => '',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_context_of_the_mission'.
  $field_bases['field_context_of_the_mission'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_context_of_the_mission',
    'field_permissions' => array(
      'owner_field' => '',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_cv'.
  $field_bases['field_cv'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cv',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_description'.
  $field_bases['field_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_description',
    'field_permissions' => array(
      'owner_field' => '',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => 0,
    ),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_description_activities'.
  $field_bases['field_description_activities'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_description_activities',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_document'.
  $field_bases['field_document'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_document',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'profile2_private' => FALSE,
      'uri_scheme' => 'private',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_domain_lead_experts'.
  $field_bases['field_domain_lead_experts'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_domain_lead_experts',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'circle' => 'circle',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_domain_state'.
  $field_bases['field_domain_state'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_domain_state',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Inactive',
        1 => 'Active',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_domaine'.
  $field_bases['field_domaine'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_domaine',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'domaine',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_duration_of_the_mission'.
  $field_bases['field_duration_of_the_mission'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_duration_of_the_mission',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_education'.
  $field_bases['field_education'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_education',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_emh_usage'.
  $field_bases['field_emh_usage'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_emh_usage',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'questions' => 'I want to ask questions',
        'expert_mission' => 'I\'m looking for an expert for a mission',
        'expert_talk' => 'I want to talk to an expert',
        'candidates' => 'I\'m looking for candidates',
        'documents' => 'I\'m looking for documents',
        'survey' => 'I want to make a survey',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_employment_history'.
  $field_bases['field_employment_history'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_employment_history',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_entreprise'.
  $field_bases['field_entreprise'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_entreprise',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'corporate' => 'corporate',
        ),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'node',
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_entreprise_description'.
  $field_bases['field_entreprise_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_entreprise_description',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_expertise'.
  $field_bases['field_expertise'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_expertise',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'expertise',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_expiration_date'.
  $field_bases['field_expiration_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_expiration_date',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'entity_translation_sync' => FALSE,
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'profile2_private' => FALSE,
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_first_name'.
  $field_bases['field_first_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_first_name',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_force_public_answer'.
  $field_bases['field_force_public_answer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_force_public_answer',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 2,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_general_information'.
  $field_bases['field_general_information'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_general_information',
    'field_permissions' => array(
      'owner_field' => '',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_image'.
  $field_bases['field_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_image',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_interests'.
  $field_bases['field_interests'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_interests',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'domaine',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 4,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 8,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_is_partner'.
  $field_bases['field_is_partner'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_is_partner',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 2,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Is not a partner',
        1 => 'Is a partner',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_is_promoted'.
  $field_bases['field_is_promoted'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_is_promoted',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 2,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Is not promoted',
        1 => 'Is promoted to front page',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_is_sponsor'.
  $field_bases['field_is_sponsor'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_is_sponsor',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 2,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Is not a sponsor',
        1 => 'Is a sponsor',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_known_how'.
  $field_bases['field_known_how'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_known_how',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'known_how',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_known_specific'.
  $field_bases['field_known_specific'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_known_specific',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 75,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_last_name'.
  $field_bases['field_last_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_last_name',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_link_to_my_blog'.
  $field_bases['field_link_to_my_blog'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_link_to_my_blog',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_linkedin'.
  $field_bases['field_linkedin'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_linkedin',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_logo'.
  $field_bases['field_logo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_logo',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_mail'.
  $field_bases['field_mail'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_mail',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'user_role_field' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_nb_contacts_linkedin'.
  $field_bases['field_nb_contacts_linkedin'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_nb_contacts_linkedin',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_needs_for_expertise'.
  $field_bases['field_needs_for_expertise'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_needs_for_expertise',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'domaine',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_notification_frequency'.
  $field_bases['field_notification_frequency'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_notification_frequency',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'notification_frequencies',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_options_costs'.
  $field_bases['field_options_costs'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_options_costs',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'emh_circles',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'emh_option_cost_modifier',
  );

  // Exported field_base: 'field_other_areas'.
  $field_bases['field_other_areas'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_other_areas',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_partner_why'.
  $field_bases['field_partner_why'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_partner_why',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_photo'.
  $field_bases['field_photo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_photo',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'imagefield_crop',
    'settings' => array(
      'default_image' => 507,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'imagefield_crop',
  );

  // Exported field_base: 'field_position'.
  $field_bases['field_position'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_position',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'position',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_position_list'.
  $field_bases['field_position_list'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_position_list',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_blank_items' => 1,
      'path' => '',
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_private'.
  $field_bases['field_private'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_private',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 3,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_private_comment'.
  $field_bases['field_private_comment'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_private_comment',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'My answer will be visible by all experts',
        1 => 'My answer will be visible only by the client',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_private_comment_body'.
  $field_bases['field_private_comment_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_private_comment_body',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_profile_purchased'.
  $field_bases['field_profile_purchased'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_profile_purchased',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 2,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_referent'.
  $field_bases['field_referent'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_referent',
    'field_permissions' => array(
      'owner_field' => '',
      'type' => 2,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Not referent',
        1 => 'Referent',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_request_circle'.
  $field_bases['field_request_circle'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_request_circle',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 2,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Choose yourself one or several circles of experts',
        1 => 'Request the domain\'s Lead Expert to accredit a list of experts',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_reward'.
  $field_bases['field_reward'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_reward',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_show_entreprise'.
  $field_bases['field_show_entreprise'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_show_entreprise',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Display the name',
        1 => 'Hide the name',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_skill2'.
  $field_bases['field_skill2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_skill2',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'skill' => 'skill',
        ),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'taxonomy_term',
      'user_role_field' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 5,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 9,
      ),
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_skill_autoeval'.
  $field_bases['field_skill_autoeval'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_skill_autoeval',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'fivestar',
    'settings' => array(
      'axis' => 'vote',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'fivestar',
  );

  // Exported field_base: 'field_skills_set'.
  $field_bases['field_skills_set'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_skills_set',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_blank_items' => 1,
      'path' => '',
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_specific_skills3'.
  $field_bases['field_specific_skills3'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_specific_skills3',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'skill',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_sponsor'.
  $field_bases['field_sponsor'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sponsor',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'uid' => array(
        0 => 'uid',
      ),
    ),
    'locked' => 0,
    'module' => 'user_reference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
      'referenceable_roles' => array(
        2 => 0,
        3 => 0,
        4 => 4,
        5 => 0,
        6 => 0,
        7 => 7,
        8 => 8,
        9 => 0,
      ),
      'referenceable_status' => array(
        0 => 0,
        1 => 1,
      ),
      'user_role_field' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 4,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 8,
        9 => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'user_reference',
  );

  // Exported field_base: 'field_sponsor1'.
  $field_bases['field_sponsor1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sponsor1',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'views',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'view' => array(
          'args' => array(),
          'display_name' => 'entityreference_1',
          'view_name' => 'users_list',
        ),
      ),
      'target_type' => 'user',
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_sponsor_why'.
  $field_bases['field_sponsor_why'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sponsor_why',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_sponsorship'.
  $field_bases['field_sponsorship'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sponsorship',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'I don\'t have a sponsor',
        1 => 'I have a sponsor',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_start_date'.
  $field_bases['field_start_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_start_date',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'entity_translation_sync' => FALSE,
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'profile2_private' => FALSE,
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_tags'.
  $field_bases['field_tags'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tags',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'tags',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_telephone'.
  $field_bases['field_telephone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_telephone',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'phone',
    'settings' => array(
      'country' => 'fr',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'phone',
  );

  // Exported field_base: 'field_testimony'.
  $field_bases['field_testimony'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_testimony',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_titre_metier'.
  $field_bases['field_titre_metier'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_titre_metier',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_tracking_key'.
  $field_bases['field_tracking_key'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tracking_key',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 2,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'user_role_field' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_tracking_referer'.
  $field_bases['field_tracking_referer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tracking_referer',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 2,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_role_field' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_twitter'.
  $field_bases['field_twitter'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_twitter',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'twitter_username',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 16,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'twitter_username',
  );

  // Exported field_base: 'field_type_entreprise'.
  $field_bases['field_type_entreprise'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_type_entreprise',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Entreprise',
        1 => 'Collectivité',
        2 => 'Association',
        3 => 'Autre',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_use_my_entreprise'.
  $field_bases['field_use_my_entreprise'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_use_my_entreprise',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Display',
        1 => 'Hide',
        2 => 'Customize',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_working_status'.
  $field_bases['field_working_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_working_status',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Independant' => 'Freelancer',
        'Employee' => 'Employee',
        'Student' => 'Student',
        'Retired' => 'Other',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
      'user_role_field' => array(
        1 => 0,
        2 => 2,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_year_of_experiences'.
  $field_bases['field_year_of_experiences'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_year_of_experiences',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'group_access'.
  $field_bases['group_access'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'group_access',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'no_ui' => TRUE,
    'settings' => array(
      'allowed_values' => array(
        0 => 'Public',
        1 => 'Private',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'group_content_access'.
  $field_bases['group_content_access'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'group_content_access',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'no_ui' => TRUE,
    'settings' => array(
      'allowed_values' => array(
        0 => 'Use group defaults',
        1 => 'Public - accessible to all site users',
        2 => 'Private - accessible only to group members',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'group_group'.
  $field_bases['group_group'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'group_group',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Not a group',
        1 => 'Group',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'name_field'.
  $field_bases['name_field'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'name_field',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 1,
    'type' => 'text',
  );

  // Exported field_base: 'og_group_ref'.
  $field_bases['og_group_ref'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'og_group_ref',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'og',
      'handler_settings' => array(
        'behaviors' => array(
          'og_behavior' => array(
            'status' => TRUE,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'membership_type' => 'og_membership_type_default',
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'circle' => 'circle',
        ),
      ),
      'handler_submit' => 'Change handler',
      'profile2_private' => FALSE,
      'target_type' => 'node',
    ),
    'target_type' => 'node',
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'og_membership_request'.
  $field_bases['og_membership_request'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'og_membership',
    ),
    'field_name' => 'og_membership_request',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'og_user_node'.
  $field_bases['og_user_node'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'og_user_node',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'og',
      'handler_settings' => array(
        'behaviors' => array(
          'og_behavior' => array(
            'status' => TRUE,
          ),
        ),
        'membership_type' => 'og_membership_type_default',
        'target_bundles' => array(),
      ),
      'handler_submit' => 'Change handler',
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'title_field'.
  $field_bases['title_field'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'title_field',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 1,
    'type' => 'text',
  );

  return $field_bases;
}
