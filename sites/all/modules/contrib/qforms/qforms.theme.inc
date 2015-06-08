<?php

/**
 * @file
 * Theme functions.
 */

function theme_qforms_submission_author($vars) {
  $output = '<div class="qforms-submission-author">';
  $output .= theme('user_picture', array('account' => $vars['account']));
  $output .= '<div class="username">' . t('Submitted by !username', array('!username' => theme('username', array('account' => $vars['account'])))) . '</div>';
  $output .= '<div class="time">' . format_date($vars['submission']->time, 'long') . '</div>';
  $output .= '<div class="ip">' . $vars['submission']->ip . '</div>';
  $output .= '</div>';
  return $output;
}

function theme_qforms_select($vars) {
  $key = $vars['element']['#key'] . '_other';
  $vars['element'][$key]['#value'] = $vars['element'][$key]['#default_value'];
  return $vars['element']['#children'] . drupal_render($vars['element'][$key]);
}

function theme_qforms_form_actions() {
  return '<div id="qforms-form-actions">' .
    '<a class="qforms-button qforms-form-open" title="' . t('Close all form elements') . '" href="#"></a>' .
    '<a class="qforms-button qforms-form-close" title="' . t('Open all form elements') . '" href="#"></a>' .
    '</div>';
}
