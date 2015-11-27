<?php
/**
 * @file
 * Contains an abstraction class for all kinds of answer.
 */


/**
 * Class for eMindHub answers.
 */
class EmhAnswer extends Entity {

  protected $_referencedEntity = NULL;

  public function __construct($values = array()) {
    parent::__construct($values, 'emh_answer');
  }

  public function defaultLabel() {
    return t('Answer');
  }

  public function getReferencedEntity() {
    
  }

  public function getRequest() {

  }

  public function getUser() {

  }

  public function getPoints() {
    return $this->points;
  }

}