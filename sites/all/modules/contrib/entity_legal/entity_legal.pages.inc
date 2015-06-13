<?php
/**
 * @file
 * Page callbacks for entity_legal module.
 */

/**
 * The page view for the entity legal document.
 *
 * @param EntityLegalDocument $entity_legal_document
 *   The entity object for the document.
 *
 * @return string
 *   The page markup.
 */
function entity_legal_document_page(EntityLegalDocument $entity_legal_document, EntityLegalDocumentVersion $entity_legal_document_version = NULL) {
  // If a specific version is specified, load it.
  if ($entity_legal_document_version) {
    if ($entity_legal_document_version->identifier() != $entity_legal_document->getPublishedVersion()->identifier()) {
      drupal_set_message('You are viewing an unpublished version of this legal document.', 'warning');
    }
    $entity_legal_document->setPublishedVersion($entity_legal_document_version);
  }

  return entity_view(ENTITY_LEGAL_DOCUMENT_ENTITY_NAME, array($entity_legal_document));
}
