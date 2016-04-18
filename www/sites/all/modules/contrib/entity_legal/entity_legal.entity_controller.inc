<?php
/**
 * @file
 * Entity API controller classes for entity_legal module.
 */

/**
 * Entity Legal Document controller class.
 */
class EntityLegalDocumentController extends EntityAPIControllerExportable {
  /**
   * {@inheritdoc}
   */
  public function save($entity) {
    // When creating a new legal document, add the document text to the bundle.
    if (!empty($entity->is_new)) {
      $instance = array(
        'field_name' => 'entity_legal_document_text',
        'entity_type' => ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME,
        'bundle' => $entity->identifier(),
        'label' => 'Document text',
        'widget' => array(
          'type' => 'text_textarea_with_summary',
          'weight' => 1,
        ),
        'settings' => array('display_summary' => TRUE),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'text_default',
          ),
          'teaser' => array(
            'label' => 'hidden',
            'type' => 'text_summary_or_trimmed',
          ),
        ),
      );
      field_create_instance($instance);
    }

    $success = parent::save($entity);

    // Flush the entity info cache to allow the new bundle to be registered.
    entity_info_cache_clear();

    return $success;
  }

  /**
   * {@inheritdoc}
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    // Delete all associated versions.
    foreach ($ids as $document_name) {
      $version_query = new EntityFieldQuery();
      $version_query->entityCondition('entity_type', ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME)
        ->propertyCondition('document_name', $document_name);

      $version_result = $version_query->execute();

      if (!empty($version_result) && !empty($version_result[ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME])) {
        foreach (array_keys($version_result[ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME]) as $version_name) {
          entity_delete(ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME, $version_name);
        }
      }

      // Delete field instance.
      $instances = field_read_instances(array(
        'entity_type' => 'entity_legal_document_version',
        'bundle' => $document_name,
      ), array(
        'include_inactive' => FALSE,
        'include_deleted' => FALSE,
      ));

      foreach ($instances as $instance) {
        field_delete_instance($instance, FALSE);
      }
    }

    parent::delete($ids, $transaction);
  }

  /**
   * Get all versions of a legal document entity.
   *
   * @param EntityLegalDocument $entity
   *   The legal document entity to get versions of.
   *
   * @return array
   *   All versions of this legal document entity.
   */
  public function getAllVersions(EntityLegalDocument $entity) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME)
      ->propertyCondition('document_name', $entity->identifier());

    $results = $query->execute();
    if (!empty($results)) {
      return entity_load(ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME, array_keys($results[ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME]));
    }
    else {
      return array();
    }
  }

  /**
   * Override the document view to instead output the version view.
   */
  public function view($entities, $view_mode = 'full', $langcode = NULL, $page = NULL) {
    $entities = entity_key_array_by_property($entities, $this->idKey);

    $view = array();
    foreach ($entities as $entity) {
      $published_version = $entity->getPublishedVersion();
      if ($published_version) {
        $key = isset($entity->{$this->idKey}) ? $entity->{$this->idKey} : NULL;
        $view[$this->entityType][$key] = $published_version->view('full', NULL, TRUE);
      }
    }

    return $view;
  }
}

/**
 * Legal document version exportable controller.
 */
class EntityLegalDocumentVersionController extends EntityAPIControllerExportable {
  /**
   * {@inheritdoc}
   */
  public function create(array $values = array()) {
    global $user;

    if (empty($values['uid'])) {
      $values['uid'] = $user->uid;
    }
    if (empty($values['created'])) {
      $values['created'] = time();
    }

    return parent::create($values);
  }

  /**
   * {@inheritdoc}
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (!empty($entity->is_new)) {
      $entity->created = time();
      $entity->updated = time();
    }

    return parent::save($entity, $transaction);
  }

  /**
   * Get acceptances for the given version of this document.
   *
   * @param EntityLegalDocumentVersion $legal_document_entity_version
   *   The legal document entity to get the acceptances of.
   * @param bool|object $account
   *   The account the acceptance belongs to, or all accounts if not set.
   *
   * @return array
   *   The acceptances associated with this legal document entity and account.
   */
  public function getAcceptances(EntityLegalDocumentVersion $legal_document_entity_version, $account = FALSE) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', ENTITY_LEGAL_DOCUMENT_ACCEPTANCE_ENTITY_NAME)
      ->propertyCondition('document_version_name', $legal_document_entity_version->name);

    if ($account) {
      $query->propertyCondition('uid', $account->uid);
    }

    $results = $query->execute();
    if (!empty($results)) {
      $results = entity_load(ENTITY_LEGAL_DOCUMENT_ACCEPTANCE_ENTITY_NAME, array_keys($results[ENTITY_LEGAL_DOCUMENT_ACCEPTANCE_ENTITY_NAME]));
    }

    return $results;
  }
}

/**
 * Entity controller for legal document acceptance entity.
 */
class EntityLegalDocumentAcceptanceController extends EntityAPIController {
  /**
   * {@inheritdoc}
   *
   * Adds legal document identifier and revision values to the acceptance
   * entity.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    // Dump all available data from the current users browsing session.
    $entity->data = $_SERVER;

    return parent::save($entity, $transaction);
  }

  /**
   * {@inheritdoc}
   */
  public function create(array $values = array()) {
    if (empty($values['document_version_name'])) {
      throw new EntityFieldQueryException(t('Acceptance does not have a valid associated document version name'));
    }

    if (!isset($values['uid'])) {
      global $user;
      $values['uid'] = $user->uid;
    }

    $values['acceptance_date'] = time();

    return parent::create($values);
  }
}
