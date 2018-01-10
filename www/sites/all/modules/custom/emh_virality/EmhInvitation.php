<?php
/**
 * @file
 * Invitation entity class.
 */


/**
 * Class for eMindHub invitations.
 */
class EmhInvitation extends Entity {

  /**
   * Sent status: the invited person isn't registered yet.
   */
  const STATUS_SENT         = 0;
  /**
   * Registered status: the invited person is registered.
   */
  const STATUS_REGISTERED   = 1;
  /**
   * Waiting status: the invited person is registered but hasn't been selected
   * by a business user for one of its answers.
   */
  const STATUS_WAITING      = 2;
  /**
   * Validated status: the invited person has been selected
   * by a business user for one of its answers.
   */
  const STATUS_VALIDATED    = 3;


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

  public function isSent() {
    return ($this->status == self::STATUS_SENT);
  }

  public function isRegistered() {
    return ($this->status == self::STATUS_REGISTERED);
  }

  public function isWaiting() {
    return ($this->status == self::STATUS_WAITING);
  }

  public function isValidated() {
    return ($this->status == self::STATUS_VALIDATED);
  }

  public function save() {
    $this->updated_at = time();
    parent::save();
  }

}
