<?php
/**
 * @file
 * Method include file for 'popup'.
 */

/**
 * Method class for alerting existing users via a jQuery UI popup window.
 */
class EntityLegalMethodPopup extends EntityLegalMethod {
  /**
   * Execution method for popup method.
   */
  public function execute($method = 'popup') {
    $documents = $this->getDocumentsForMethod($method, ENTITY_LEGAL_USER_EXISTING);

    foreach ($documents as $document) {
      $document_markup = $document->view();

      drupal_add_library('system', 'ui.dialog');
      drupal_add_js(array(
        'entityLegalPopup' => array(
          array(
            'popupTitle' => $document->getVersionLabel(),
            'popupContent' => render($document_markup),
          ),
        ),
      ), 'setting');
      drupal_add_js(drupal_get_path('module', 'entity_legal') . '/js/entity_legal.popup.js', array(
        'every_page' => FALSE,
      ));
    }
  }
}
