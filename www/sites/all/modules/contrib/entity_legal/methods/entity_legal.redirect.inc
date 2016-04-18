<?php
/**
 * @file
 * Method include file for 'redirect'.
 */

/**
 * Method class for redirecting existing users to accept a legal document.
 */
class EntityLegalMethodRedirect extends EntityLegalMethod {
  /**
   * Execution method for redirect method.
   */
  public function execute($method = 'redirect') {
    $documents = $this->getDocumentsForMethod($method, ENTITY_LEGAL_USER_EXISTING);

    foreach ($documents as $document) {
      $entity_uri = $document->uri();

      // Only redirect if the legal document isn't currently being viewed.
      if (current_path() == $entity_uri['path']) {
        return;
      }

      // Do not redirect user logout.
      if (current_path() == 'user/logout') {
        return;
      }

      drupal_set_message(t('You must accept this agreement before continuing.'), 'warning');
      drupal_goto($entity_uri['path'], array(
        'query' => drupal_get_destination(),
      ));
    }
  }
}
