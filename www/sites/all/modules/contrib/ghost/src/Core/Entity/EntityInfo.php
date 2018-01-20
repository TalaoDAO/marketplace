<?php

/**
 * @file
 * Contains an EntityInfo
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Entity;


/**
 * Class EntityInfo
 * @package Drupal\ghost\Entity
 *
 * Provides information about entity types.
 */
class EntityInfo {

  /**
   * Init.
   *
   * @return static
   *   This.
   * @static
   */
  static public function init() {

    return new static();
  }

  /**
   * Get a bundle key.
   *
   * @param string $entity_type
   *   The entity type.
   *
   * @return string
   *   A key.
   */
  public function bundleKey($entity_type) {

    $info = entity_get_info($entity_type);

    if (!empty($info['entity keys']['bundle'])) {

      return $info['entity keys']['bundle'];
    }
    else {

      return $entity_type;
    }
  }

  /**
   * Get an ID key.
   *
   * @param string $entity_type
   *   The entity type.
   *
   * @return string
   *   A key.
   */
  public function idKey($entity_type) {

    $info = entity_get_info($entity_type);

    return $info['entity keys']['id'];
  }

  /**
   * Get revision key.
   *
   * @param string $entity_type
   *   The entity type.
   *
   * @return string
   *   A key.
   */
  public function revisionKey($entity_type) {

    $info = entity_get_info($entity_type);

    return $info['entity keys']['revision'];
  }
}
