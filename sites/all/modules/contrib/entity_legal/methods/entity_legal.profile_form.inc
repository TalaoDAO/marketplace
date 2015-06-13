<?php
/**
 * @file
 * Method include file for 'form_link' and 'form_inline'.
 */

/**
 * Method class for displaying a checkbox on the user register form.
 */
class EntityLegalMethodProfileForm extends EntityLegalMethod {
  /**
   * Get all legal document entities with profile form methods.
   *
   * @return array
   *   All documents that have profile form methods.
   */
  public function getProfileFormMethodDocuments() {
    $documents = $this->getDocumentsForMethod('form_link', ENTITY_LEGAL_USER_ANONYMOUS);
    $documents += $this->getDocumentsForMethod('form_inline', ENTITY_LEGAL_USER_ANONYMOUS);
    return $documents;
  }

  /**
   * Execution method for profile form method.
   *
   * @param array $form
   *   The user register form to affect.
   */
  public function execute(array &$form) {
    $documents = $this->getProfileFormMethodDocuments();

    foreach ($documents as $document) {
      $field_name = 'legal_' . $document->identifier();

      $form[$field_name] = array(
        '#type' => 'checkbox',
        '#title' => $document->getAcceptanceLabel(),
        '#default_value' => $document->userHasAgreed(),
        '#required' => TRUE,
      );

      switch ($document->getAcceptanceDeliveryMethod(TRUE)) {
        case 'form_inline':
          $document_render_array = entity_view(ENTITY_LEGAL_DOCUMENT_ENTITY_NAME, array($document));
          $form[$field_name]['#prefix'] = render($document_render_array);
          break;
      }
    }
  }
}
