<?php

/**
 * @file
 * Examples for the Ghost Logger.
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

/**
 * How to use the Ghost logger.
 */
function ghost_examples_logger() {

  $some_var = 'Foo';

  $logger = Drupal\ghost\Logger\Logger::init('ghost');

  $logger->setMessage('Things are broken: %my_thing');
  $logger->setVar('%my_thing', $some_var);
  $logger->setSeverity(WATCHDOG_ERROR);

  $logger->log();
}

/**
 * Class MyGhostCustomLogger
 *
 * How to extend the Logger.
 */
class MyGhostCustomLogger extends \Drupal\ghost\Logger\Logger {

  /**
   * Implements LoggerInterface::logWrite().
   */
  public function logWrite() {

    // Fire up a custom log writer and send the log somehwere!
    MyLogWriter::writeSomeLog($this->getMessage(), $this->getSeverity());
  }

}
