<?php
/**
 * @file
 * Entity API main classes used by entity_legal module.
 */

/**
 * Legal Document entity with revision support.
 */
class EntityLegalDocument extends Entity {
  /**
   * {@inheritdoc}
   */
  public function __construct(array $values = array(), $entity_type = NULL) {
    Entity::__construct($values, ENTITY_LEGAL_DOCUMENT_ENTITY_NAME);
  }

  /**
   * Get an acceptance form for this legal document.
   *
   * @return array
   *   The drupal acceptance form.
   */
  public function getAcceptanceForm() {
    return drupal_get_form('entity_legal_document_acceptance_form', $this);
  }

  /**
   * Get a version of this document.
   *
   * @param bool $version_name
   *   If set, load the version otherwise load the default version or create
   *   one.
   *
   * @return EntityLegalDocumentVersion
   *   The legal document version.
   */
  public function getVersion($version_name = FALSE) {
    // If a version name is supplied, load it.
    if ($version_name) {
      return entity_load_single(ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME, $version_name);
    }

    // If no version name is supplied but a published version exists, return it.
    $published_version = $this->getPublishedVersion();
    if (!$version_name && $published_version) {
      return $published_version;
    }

    $all_versions = $this->getAllVersions();

    // If no versions exist return a new one.
    if (empty($all_versions) && !$version_name) {
      return $this->getNewVersion();
    }

    // Return the first version.
    if (!$version_name && !$published_version) {
      return array_pop($all_versions);
    }
  }

  /**
   * Get the label of the legal document entity.
   *
   * @param bool $sanitize
   *   Whether or not to sanitize the label, defaults to TRUE.
   *
   * @return string
   *   The label string.
   */
  public function label($sanitize = FALSE) {
    $label_text = isset($this->label) ? $this->label : '';

    if ($sanitize) {
      $label_text = check_plain($label_text);
    }

    return $label_text;
  }

  /**
   * Get a new version of this legal document.
   *
   * @return LegalDocumentVersion
   *   The legal document version entity.
   */
  public function getNewVersion() {
    return entity_create(ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME, array(
      'document_name' => $this->identifier(),
    ));
  }

  /**
   * Get all versions of this legal document entity.
   *
   * @return array
   *   All versions of this legal document entity.
   */
  public function getAllVersions() {
    return entity_get_controller($this->entityType)->getAllVersions($this);
  }

  /**
   * Get the current published version of this document.
   *
   * @return bool|EntityLegalDocumentVersion
   *   The current legal document version or FALSE if none found.
   */
  public function getPublishedVersion() {
    $published_version = FALSE;

    drupal_alter('entity_legal_published_version', $this->published_version, $this);

    if (!empty($this->published_version)) {
      $published_version = entity_load_single(ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME, $this->published_version);
    }

    return $published_version;
  }

  /**
   * Set the published document version.
   *
   * @param EntityLegalDocumentVersion $version_entity
   *   The legal document version to set as the published version.
   *
   * @return bool
   *   Whether or not the published version was set successfully.
   */
  public function setPublishedVersion(EntityLegalDocumentVersion $version_entity) {
    // If the version entity is not of this bundle, fail.
    if ($version_entity->document_name != $this->identifier()) {
      return FALSE;
    }

    $this->published_version = $version_entity->identifier();

    return TRUE;
  }

  /**
   * Get the title of the attached version.
   *
   * @return bool|string
   *   The title of the published version or FALSE if no title found.
   */
  public function getVersionLabel() {
    $version_entity = $this->getPublishedVersion();
    if ($version_entity) {
      return $version_entity->label(TRUE);
    }
    else {
      return FALSE;
    }
  }

  /**
   * Specifies the default uri, which is picked up by uri() by default.
   */
  protected function defaultURI() {
    return array(
      'path' => 'legal/document/' . str_replace('_', '-', $this->identifier()),
    );
  }

  /**
   * Use the entity name as the identifier.
   */
  public function identifier() {
    return $this->name;
  }

  /**
   * URI callback.
   */
  public function uri() {
    return $this->defaultURI();
  }

  /**
   * Get the label to be shown on the acceptance checkbox.
   *
   * @return string
   *   The label to be shown on the acceptance checkbox.
   */
  public function getAcceptanceLabel() {
    $label = '';
    $published_version = $this->getPublishedVersion();

    if ($published_version) {
      $label = $published_version->acceptance_label;
    }

    if (module_exists('token') && module_exists('entity_token')) {
      $label = token_replace($label, array('entity_legal_document' => $this));
    }

    return filter_xss($label);
  }

  /**
   * Get a legal document setting.
   *
   * Functions similar to variable get by allowing default values but differs
   * by checking for a variable keys existence
   *
   * @param string $setting_group
   *   The group of settings the setting belongs to.
   * @param string $setting_key
   *   The settings key within the settings group.
   * @param mixed $default
   *   The default value to return if the setting is not found.
   *
   * @return mixed
   *   The value of hte setting.
   */
  public function getSetting($setting_group, $setting_key, $default = FALSE) {
    if (!isset($this->settings)) {
      return $default;
    }
    if (!isset($this->settings[$setting_group])) {
      return $default;
    }
    if (!isset($this->settings[$setting_group][$setting_key])) {
      return $default;
    }

    return $this->settings[$setting_group][$setting_key];
  }

  /**
   * Checks to see if a given user can agree to this document.
   *
   * @param bool $new_user
   *   Whether or not the user to check is a new user signup or not.
   * @param object $account
   *   The user account to check the access permissions of. Defaults to the
   *   current user if none is provided.
   *
   * @return bool
   *   Can a user agree to this document.
   */
  public function userMustAgree($new_user = FALSE, $account = NULL) {
    // User cannot agree unless there is a published version.
    if (!$this->getPublishedVersion()) {
      return FALSE;
    }

    if ($new_user) {
      return !empty($this->require_signup);
    }
    else {
      return !empty($this->require_existing) && user_access($this->getPermissionExistingUser(), $account);
    }
  }

  /**
   * Check if the given user has agreed to the current version of this document.
   *
   * @param object $account
   *   The Drupal user account to check. Default logged in user if not provided.
   *
   * @return bool
   *   Whether or not the user has agreed to the current version.
   */
  public function userHasAgreed($account = NULL) {
    if (empty($account)) {
      global $user;
      $account = $user;
    }

    return count($this->getAcceptances($account)) > 0;
  }

  /**
   * Get the acceptances for this entity legal document revision.
   *
   * @param bool|object $account
   *   The Drupal user account to check for, or get all acceptances if FALSE.
   * @param bool $published
   *   Get acceptances only for the currently published version.
   *
   * @return array
   *   The acceptance entities keyed by acceptance id.
   */
  public function getAcceptances($account = FALSE, $published = TRUE) {
    $acceptances = array();
    $versions = array();

    if ($published) {
      $versions[] = $this->getPublishedVersion();
    }
    else {
      $versions = $this->getAllVersions();
    }

    foreach ($versions as $version) {
      $acceptances += $version->getAcceptances($account);
    }

    return $acceptances;
  }

  /**
   * Get the permission name for any user viewing this agreement.
   *
   * @return string
   *   The user permission, used with user_access.
   */
  public function getPermissionView() {
    return 'legal view ' . $this->name;
  }

  /**
   * Get the permission name for new users accepting this document.
   *
   * @return string
   *   The user permission, used with user_access.
   */
  public function getPermissionExistingUser() {
    return 'legal re-accept ' . $this->name;
  }

  /**
   * Get the acceptance delivery method for a given user type.
   *
   * @param bool $new_user
   *   Get the method for new signups or existing accounts.
   *
   * @return string
   *   The acceptance delivery method.
   */
  public function getAcceptanceDeliveryMethod($new_user = FALSE) {
    $setting_group = $new_user ? 'new_users' : 'existing_users';

    return $this->getSetting($setting_group, 'require_method');
  }
}

/**
 * Legal Document entity version class.
 */
class EntityLegalDocumentVersion extends Entity {
  /**
   * {@inheritdoc}
   */
  public function __construct(array $values = array(), $entity_type = NULL) {
    Entity::__construct($values, ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME);
  }

  /**
   * Get the label of the legal document version entity.
   *
   * @param bool $sanitize
   *   Whether or not to sanitize the label, defaults to TRUE.
   *
   * @return string
   *   The label string.
   */
  public function label($sanitize = FALSE) {
    $label_text = isset($this->label) ? $this->label : '';

    if ($sanitize) {
      $label_text = check_plain($label_text);
    }

    return $label_text;
  }

  /**
   * Get the date for a given entity property.
   *
   * @param string $type
   *   The type of date to retrieve, updated or created.
   *
   * @return string
   *   The formatted date.
   */
  public function getFormattedDate($type = 'updated') {
    switch ($type) {
      case 'updated':
        return format_date($this->updated);

      case 'created':
        return format_date($this->created);
    }
  }

  /**
   * Get the acceptances for this entity legal document version.
   *
   * @param bool|object $account
   *   The Drupal user account to check for, or get all acceptances if FALSE.
   *
   * @return array
   *   The acceptance entities keyed by acceptance id.
   */
  public function getAcceptances($account = FALSE) {
    return entity_get_controller($this->entityType)->getAcceptances($this, $account);
  }

  /**
   * Get attached document entity.
   *
   * @return EntityLegalDocument
   *   The attached document entity.
   */
  public function getDocument() {
    return entity_load_single(ENTITY_LEGAL_DOCUMENT_ENTITY_NAME, $this->document_name);
  }

  /**
   * Override buildContent() to add the acceptance form.
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    $content = parent::buildContent($view_mode, $langcode);

    // Get acceptance form or information for the current user.
    $document = $this->getDocument();

    if ($document->userMustAgree() && user_is_logged_in() && !$document->userHasAgreed()) {
      $content['acceptance'] = $document->getAcceptanceForm();
    }

    // Move acceptance to the bottom of the agreement.
    $content['acceptance']['#weight'] = 99;

    return $content;
  }

}

/**
 * Legal document user acceptance entity.
 *
 * A user acceptance entity is linked directly with a legal document revision
 * and is used to track which users have accepted which revision.
 */
class EntityLegalDocumentAcceptance extends Entity {
  /**
   * {@inheritdoc}
   */
  public function __construct(array $values = array(), $entity_type = NULL) {
    parent::__construct($values, ENTITY_LEGAL_DOCUMENT_ACCEPTANCE_ENTITY_NAME);
  }

  /**
   * {@inheritdoc}
   */
  public function label() {
    return t('Accepted on @date', array(
      '@date' => format_date($this->acceptance_date),
    ));
  }

  /**
   * {@inheritdoc}
   */
  protected function defaultURI() {
    return NULL;
  }

  /**
   * Get the name of the document this acceptance belongs to.
   *
   * @return string
   *   The name of the document version this acceptance belongs to.
   */
  public function getDocumentVersionName() {
    return $this->document_version_name;
  }

  /**
   * Get the document version this acceptance belongs to.
   *
   * @return EntityLegalDocumentVersion
   *   The version of the document corresponding to this acceptance.
   */
  public function getDocumentVersion() {
    return entity_load_single(ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME, $this->getDocumentVersionName());
  }

  /**
   * Get the date a user created this acceptance.
   *
   * @return string
   *   The date this document was accepted.
   */
  public function getAcceptanceDate() {
    return $this->acceptance_date;
  }
}
