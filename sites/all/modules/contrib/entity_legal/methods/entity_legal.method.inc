<?php
/**
 * @file
 * Method include file for common base class.
 */

/**
 * Base class for entity_legal methods.
 *
 * Provides helper functions for methods to use.
 */
abstract class EntityLegalMethod {
  /**
   * Get all Entity Legal Documents for a given user type and method.
   *
   * @param string $method
   *   The name of the method to find entity legal documents for.
   * @param string $user_type
   *   The type of user, existing or signup.
   *
   * @return array
   *   All published entity legal documents required for the given user type.
   */
  public function getDocumentsForMethod($method, $user_type = ENTITY_LEGAL_USER_EXISTING) {
    // Entity Legal administrators should never be forced to accept documents.
    if (user_access('administer legal documents')) {
      return array();
    }

    // Don't run method for anonymous users.
    if ($user_type == ENTITY_LEGAL_USER_EXISTING && user_is_anonymous()) {
      return array();
    }

    // Get all active documents that must be agreed to by existing users.
    $documents = entity_legal_get_all_documents(TRUE, $user_type);

    // Remove any documents from the array set that don't use the given
    // acceptance method.
    foreach ($documents as $name => $document) {
      $agreed = !$document->userMustAgree($user_type == ENTITY_LEGAL_USER_ANONYMOUS) || $document->userHasAgreed();
      $is_method = $document->getAcceptanceDeliveryMethod($user_type == ENTITY_LEGAL_USER_ANONYMOUS) == $method;

      if ($agreed || !$is_method) {
        unset($documents[$name]);
      }
    }

    return $documents;
  }
}
