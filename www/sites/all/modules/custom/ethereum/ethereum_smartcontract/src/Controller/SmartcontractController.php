<?php

/**
 * @file
 * Smartcontract entity API controller.
 */

/**
 * Extending the EntityAPIController for the Smartcontract entity.
 */
class SmartcontractEntityController extends EntityAPIController {

  /**
   * TODO: Build it for real use of Smart Contract, not just view it.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {

    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    return $build;

  }

}
