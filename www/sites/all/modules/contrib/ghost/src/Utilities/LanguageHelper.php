<?php

/**
 * @file
 * Contains a LanguageHelper.
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Utilities;

use Drupal\ghost\Traits\InitialiserTrait;

/**
 * Class LanguageHelper
 *
 * @package Drupal\ghost\Utilities
 */
class LanguageHelper {

  use InitialiserTrait;

  /***
   * Get an entity's language.
   *
   * @param string $entity_type
   *   The type of entity
   * @param object $entity
   *   An entity.
   *
   * @return string
   *   The entity language or the default language.
   */
  public function getEntityLanguage($entity_type, $entity) {
    $lang = entity_language('paragraphs_item', $entity);
    if (empty($lang)) {
      $lang = LANGUAGE_NONE;
    }

    return $lang;
  }
}
