<?php
/**
 * @file
 * Method include file for 'message'.
 */

/**
 * Method class for alerting existing users via Drupal set message.
 */
class EntityLegalMethodMessage extends EntityLegalMethod {
  /**
   * Execution method for message method.
   */
  public function execute($method = 'message') {
    $documents = $this->getDocumentsForMethod($method, ENTITY_LEGAL_USER_EXISTING);

    foreach ($documents as $document) {
      $entity_uri = $document->uri();
      $message = t('Please accept the !document_name.', array(
        '!document_name' => l(entity_legal_document_title($document), $entity_uri['path']),
      ));

      drupal_set_message($message, 'warning', FALSE);
    }
  }
}
