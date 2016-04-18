<?php
/**
 * @file
 * API documentation for entity_legal module.
 */

/**
 * Alter available user notification methods.
 *
 * @param array $methods
 *   Available methods.
 */
function hook_entity_legal_document_method_alter(array $methods) {
  $methods['existing_users']['email'] = t('Email all users');
}

/**
 * Alter the published version name of a document before it's loaded.
 *
 * @note
 * This value will not be exported and is useful for bypassing features exported
 * values.
 *
 * @param string $published_version_name
 *   The entity name of the Legal Document Version.
 * @param EntityLegalDocument $legal_document
 *   The Legal Document the version is being loaded for.
 */
function hook_entity_legal_published_version_alter(&$published_version_name, EntityLegalDocument $legal_document) {
  if ($legal_document->identifier() == 'foo') {
    $published_version_name = 'bar';
  }
}
