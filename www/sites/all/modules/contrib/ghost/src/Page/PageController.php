<?php

/**
 * @file
 * Contains a PageController.
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

namespace Drupal\ghost\Page;

use Drupal\ghost\Exception\InvalidControllerException;

/**
 * Class PageController
 *
 * @package Drupal\ghost\Page
 */
class PageController implements PageControllerInterface {

  /**
   * Static factory function.
   */
  static public function createPage() {

    $args = func_get_args();
    $controller_name = array_shift($args);
    $method = array_shift($args);

    if (class_exists($controller_name)) {
      $controller = new $controller_name();

      if ($controller instanceof PageControllerInterface) {
        if (method_exists($controller_name, $method)) {
          return call_user_func_array(array($controller, $method), $args);
        }
      }
    }

    throw new InvalidControllerException(sprintf('Invalid Page Controller %s', $controller_name));
  }
}
