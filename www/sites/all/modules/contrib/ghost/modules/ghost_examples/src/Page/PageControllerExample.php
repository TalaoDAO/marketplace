<?php
/**
 * @file
 * Contains an example PageController.
 */

namespace Drupal\ghost_examples\Page;

use Drupal\ghost\Page\PageController;

/**
 * Class ExampleController
 *
 * @package Drupal\page_controller\Example
 */
class PageControllerExample extends PageController {

  /**
   * Example view callback.
   */
  public function myPageControllerViewCallback($arg1, $arg2) {
    // Do something with $args.

    return 'Some output';
  }
}
