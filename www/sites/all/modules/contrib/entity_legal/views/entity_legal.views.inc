<?php
/**
 * @file
 * Views hooks for the Entity Legal module.
 */

/**
 * Implements hook_views_data_alter().
 */
function entity_legal_views_data_alter(&$data) {
  $data[ENTITY_LEGAL_DOCUMENT_ENTITY_NAME]['published_version']['relationship'] = array(
    'base' => ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME,
    'base field' => 'name',
    'handler' => 'views_handler_relationship',
    'label' => t('Published version'),
    'title' => t('The legal document version currently published'),
  );

  $data[ENTITY_LEGAL_DOCUMENT_ACCEPTANCE_ENTITY_NAME]['document_version_name']['relationship'] = array(
    'base' => ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME,
    'base field' => 'name',
    'handler' => 'views_handler_relationship',
    'label' => t('Legal document version'),
    'title' => t('Entity legal document version'),
    'help' => t('The legal document version associated with the acceptance'),
  );
  $data[ENTITY_LEGAL_DOCUMENT_ACCEPTANCE_ENTITY_NAME]['created']['field']['handler'] = 'views_handler_field_date';
  $data[ENTITY_LEGAL_DOCUMENT_ACCEPTANCE_ENTITY_NAME]['updated']['field']['handler'] = 'views_handler_field_date';
  $data[ENTITY_LEGAL_DOCUMENT_ACCEPTANCE_ENTITY_NAME]['uid']['relationship'] = array(
    'base' => 'users',
    'base field' => 'uid',
    'handler' => 'views_handler_relationship',
    'label' => t('User'),
    'title' => t('The user who accepted'),
  );

  $data[ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME]['document_name']['relationship'] = array(
    'base' => ENTITY_LEGAL_DOCUMENT_ENTITY_NAME,
    'base field' => 'name',
    'handler' => 'views_handler_relationship',
    'label' => t('Legal document'),
    'title' => t('The document associated with the version'),
  );
  $data[ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME]['uid']['relationship'] = array(
    'base' => 'users',
    'base field' => 'uid',
    'handler' => 'views_handler_relationship',
    'label' => t('User'),
    'title' => t('The user who created the version'),
  );
  $data[ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME]['created']['field']['handler'] = 'views_handler_field_date';
  $data[ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME]['updated']['field']['handler'] = 'views_handler_field_date';
}
