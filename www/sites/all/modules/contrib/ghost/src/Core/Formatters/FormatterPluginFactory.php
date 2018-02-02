<?php

/**
 * @file
 * Contains a FormatterPluginFactory
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

namespace Drupal\ghost\Core\Formatters;

use Drupal\ghost\Plugin\GhostPluginFactory;

/**
 * Class FormatterPluginFactory
 * @package Drupal\formatters
 */
class FormatterPluginFactory extends GhostPluginFactory {

  /**
   * Lazy factory constructor.
   *
   * @return FormatterPluginFactory
   *   This factory.
   */
  static public function init() {

    return new static(GHOST_PLUGIN_TYPE_FORMATTER);
  }
}
