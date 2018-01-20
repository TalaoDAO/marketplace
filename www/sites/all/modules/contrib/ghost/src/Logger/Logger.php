<?php

/**
 * @file
 * Contains a Logger
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

namespace Drupal\ghost\Logger;

/**
 * Class Logger
 * @package Drupal\ghost\Utilities
 */
class Logger implements LoggerInterface {

  /**
   * The module logging.
   *
   * @var string
   */
  protected $caller;

  /**
   * The message to log.
   *
   * @var string
   */
  public $message;

  /**
   * Variables to substitute into the message.
   *
   * @var array
   */
  public $vars = array();

  /**
   * Whether to also send to the message area.
   *
   * @var bool
   */
  public $useMessageArea = FALSE;

  /**
   * The severity
   *
   * @var int
   */
  public $severity;

  /**
   * Constructor.
   *
   * @param string $module
   *   The module logging.
   */
  protected function __construct($module) {

    $this->caller = $module;
  }

  /**
   * Constructor.
   *
   * @param string $caller
   *   The module calling the Log function.
   * @param string $message
   *   The message to log.
   * @param array $vars
   *   (Optional) Variables to substitute into the message.
   * @param int $severity
   *   (Optional) A Watchdog severity level. Defaults to WATCHDOG_NOTICE.
   * @param bool $message_area
   *   (Optional) Whether to log to drupal_set_message as well. Defaults to
   *   FALSE.
   *
   * @return Logger
   *   This Logger
   */
  static public function init($caller, $message = NULL, $vars = array(), $severity = WATCHDOG_NOTICE, $message_area = FALSE) {

    $logger = new static($caller);
    $logger->setMessage($message);
    $logger->setVars($vars);
    $logger->setSeverity($severity);
    $logger->useMessageArea = $message_area;

    return $logger;
  }

  /**
   * Log the message.
   */
  public function log() {

    $this->logWrite();
    $this->logMessage();
  }

  /**
   * Log the message using drupal_set_message().
   */
  public function logMessage() {
    if ($this->isUseMessageArea() == TRUE) {

      $dsm_severity = 'status';
      if (in_array($this->getSeverity(), array(
        WATCHDOG_ERROR,
        WATCHDOG_ALERT,
        WATCHDOG_CRITICAL,
        WATCHDOG_EMERGENCY,
      ))) {
        $dsm_severity = 'error';
      }
      elseif (in_array($this->getSeverity(), array(WATCHDOG_WARNING))) {
        $dsm_severity = 'warning';
      }

      drupal_set_message(format_string($this->getMessage(), $this->getVars()), $dsm_severity, FALSE);
    }
  }

  /**
   * Getter for module.
   *
   * @return string
   *   The module name.
   */
  public function getCaller() {

    return check_plain($this->caller);
  }

  /**
   * Getter for message.
   *
   * @return string
   *   The message.
   */
  public function getMessage() {

    return $this->message;
  }

  /**
   * Setter for message.
   *
   * @param string $message
   *   The value for message.
   *
   * @return Logger
   *   An instance of the Logger
   */
  public function setMessage($message) {

    $this->message = $message;

    return $this;
  }

  /**
   * Getter for severity.
   *
   * @return int
   *   The severity.
   */
  public function getSeverity() {

    return $this->severity;
  }

  /**
   * Setter for severity.
   *
   * @param int $severity
   *   The value for severity.
   *
   * @return Logger
   *   An instance of this Logger
   */
  public function setSeverity($severity) {

    $this->severity = $severity;

    return $this;
  }

  /**
   * Getter for vars.
   *
   * @return array
   *   The vars.
   */
  public function getVars() {

    return $this->vars;
  }

  /**
   * Setter for vars.
   *
   * @param array $vars
   *   The value for vars.
   */
  public function setVars($vars) {

    $this->vars = $vars;
  }

  /**
   * Getter for vars.
   *
   * @param string $key
   *   Key of the var to return.
   *
   * @return array
   *   The vars.
   */
  public function getVar($key) {

    if (isset($this->vars[$key])) {
      return $this->vars[$key];
    }

    return NULL;
  }

  /**
   * Setter for vars.
   *
   * @param string $key
   *   The key to set.
   * @param mixed $value
   *   The value for vars.
   *
   * @return Logger
   *   An instance of Logger
   */
  public function setVar($key, $value) {

    $this->vars[$key] = $value;

    return $this;
  }

  /**
   * Tell the logger to use the message area.
   */
  public function useMessageArea() {
    $this->useMessageArea = TRUE;

    return $this;
  }

  /**
   * Should this be sent to the message area.
   *
   * @return bool
   *   TRUE if it should
   */
  public function isUseMessageArea() {

    return $this->useMessageArea;
  }

  /**
   * Write the log message.
   *
   * This is part of the LogInterface and should be implemented by Logger
   * implementations, but should not be called by users.
   *
   * @see log()
   */
  public function logWrite() {

    watchdog($this->getCaller(), $this->getMessage(), $this->getVars(), $this->getSeverity());
  }
}
