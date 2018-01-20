<?php

/**
 * @file
 * Contains a Log utility
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

namespace Drupal\ghost\Utilities;

/**
 * Class Log
 *
 * @package Drupal\dnsw_product_search\Utilities
 */
class LogMessage {

  /**
   * Log.
   *
   * @param string $module
   *   The module calling the Log function.
   * @param string $message
   *   The message to log.
   * @param array $vars
   *   (Optional) Variables to substitute into the message.
   * @param int $severity
   *   (Optional) A Watchdog severity level. Defaults to WATCHDOG_NOTICE.
   */
  static public function logMessage($module, $message, $vars = array(), $severity = WATCHDOG_NOTICE, $message_area = FALSE) {

    if (variable_get('ghost_logging_enabled', TRUE) == TRUE) {
      watchdog(check_plain($module), $message, $vars, $severity);

      if ($message_area == TRUE) {

        $dsm_severity = 'status';
        if (in_array($severity, array(
          WATCHDOG_ERROR,
          WATCHDOG_ALERT,
          WATCHDOG_CRITICAL,
          WATCHDOG_EMERGENCY,
        ))) {
          $dsm_severity = 'error';
        }
        elseif (in_array($severity, array(WATCHDOG_WARNING))) {
          $dsm_severity = 'warning';
        }

        drupal_set_message(format_string($message, $vars), $dsm_severity, FALSE);
      }
    }
  }

}
