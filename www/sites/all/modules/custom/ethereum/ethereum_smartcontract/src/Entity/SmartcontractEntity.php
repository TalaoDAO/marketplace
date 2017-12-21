<?php

/**
 * @file
 * Smartcontract entity class.
 */

/**
 * Smartcontract entity class extending the Entity class.
 */
class SmartcontractEntity extends Entity {

  /**
   * Change the default URI from default/id to smartcontract/id.
   */
  protected function defaultUri() {
    return array('path' => 'admin/config/ethereum/smartcontract/view/' . $this->identifier());
  }

}
