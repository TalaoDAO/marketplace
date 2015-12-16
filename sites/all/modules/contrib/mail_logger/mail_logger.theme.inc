<?php
/**
 * @file
 * Theming functions for the Mail Logger module.
 */

/**
 * Theme function for theme('mail_logger_read_mail').
 *
 * @ingroup themeable
 */
function theme_mail_logger_read_mail($mail) {
  $mail = $mail['mail'];
  $output = '';
  $output .= '<div class="mail_logger_wrapper">';
  $output .= '<div class="mail_type_label">Mail Type: </div><div class="mail_type_data">' . $mail->mailkey . '</div>';
  $output .= '<div class="date_sent_label">Date Sent: </div><div class="date_sent_data">' . format_date($mail->date_sent, 'small') . '</div>';
  $output .= '<div class="mail_from_label">From: </div><div class="mail_from_data">' . check_plain($mail->mailfrom) . '</div>';
  $output .= '<div class="mail_to_label">To: </div><div class="mail_to_data">' . check_plain($mail->mailto) . '</div>';
  $output .= '<div class="mail_subject_label">Subject: </div><div class="mail_subject_data">' . check_plain($mail->subject) . '</div>';
  $output .= '<div class="mail_body_label">Body: </div>';
  if (preg_match('/<html.*?>(.*?)<\/html>/s', $mail->body, $mailbody)) {
    $output .= '<iframe srcdoc="<html>' . htmlspecialchars($mailbody[1], ENT_QUOTES) . '</html>" width="100%" height="500px"></iframe>';
  } else {
    $output .= '<div class="mail_body_label">Body: </div><div class="mail_body_data">' . nl2br(check_plain($mail->body)) . '</div>';
  }
  $output .= '</div>';
  return $output;
}
