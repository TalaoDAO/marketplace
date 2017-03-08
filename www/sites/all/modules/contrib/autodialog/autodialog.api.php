<?php

/**
 * Implements hook_autodialog_commands_alter().
 */
function hook_autodialog_commands_alter(&$commands) {
  $commands[0]['title'] = 'New dialog title';
}
