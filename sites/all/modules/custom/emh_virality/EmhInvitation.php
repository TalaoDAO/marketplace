<?php
/**
 * @file
 * Invitation entity class.
 */


/**
 * Class for eMindHub invitations.
 */
class EmhInvitation extends Entity {

  const PENDING   = 0;
  const VALIDATED = 1;
  const MISSED    = 2;


  public function __construct($values = array()) {
    parent::__construct($values, 'emh_invitation');
  }

  public function defaultLabel() {
    return t('Invitation');
  }

  public function getReferrer() {
    return isset($this->referrer_id) ? user_load($this->referrer_id) : NULL;
  }

  public function getReferral() {
    return isset($this->referral_id) ? user_load($this->referral_id) : NULL;
  }

  public function isPending() {
    return ($this->status == self::PENDING);
  }

  public function isValidated() {
    return ($this->status == self::VALIDATED);
  }

  public function isMissed() {
    return ($this->status == self::MISSED);
  }

}
