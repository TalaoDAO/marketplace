<?php
/**
 * A mail sending implementation that captures sent messages to a variable.
 *
 * This class is for running tests or for development.
 */
class EMHMailSystem extends DefaultMailSystem implements MailSystemInterface {
  /**
   * Accept an e-mail message and store it in a variable.
   *
   * @param $message
   *   An e-mail message.
   */
  public function mail(array $message) {
    unset($message['params']['context']['state']);
    unset($message['params']['context']['action']);
    $captured_emails = variable_get('drupal_test_email_collector', array());
    $captured_emails[] = $message;
    variable_set('drupal_test_email_collector', $captured_emails);
    return TRUE;
  }
}

