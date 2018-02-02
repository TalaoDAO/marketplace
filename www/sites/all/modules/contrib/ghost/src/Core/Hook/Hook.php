<?php

/**
 * @file
 * Contains a HookCaller
 */

namespace Drupal\ghost\Core\Hook;


/**
 * Class Hook
 * @package Drupal\ghost\Hook
 */
class Hook {

  /**
   * Lazy loader.
   *
   * @return Hook
   *   This.
   */
  static public function init() {
    return new static();
  }

  /**
   * Determines which modules are implementing a hook.
   *
   * @param string $hook
   *   The name of the hook (e.g. "help" or "menu").
   * @param bool $sort
   *   By default, modules are ordered by weight and filename, settings this
   *   option to TRUE, module list will be ordered by module name.
   * @param bool $reset
   *   For internal use only: Whether to force the stored list of hook
   *   implementations to be regenerated (such as after enabling a new module,
   *   before processing hook_enable).
   *
   * @return array
   *   An array with the names of the modules which are implementing this hook.
   *
   * @see module_implements_write_cache()
   */
  public function moduleImplements($hook, $sort = FALSE, $reset = FALSE) {

    return module_implements($hook, $sort = FALSE, $reset = FALSE);
  }

  /**
   * Invokes a hook in a particular module.
   *
   * All arguments are passed by value. Use drupal_alter() if you need to pass
   * arguments by reference.
   *
   * @param string $module
   *   The name of the module (without the .module extension).
   * @param string $hook
   *   The name of the hook to invoke.
   * @param ...
   *   Arguments to pass to the hook implementation.
   *
   * @return mixed
   *   The return value of the hook implementation.
   *
   * @see drupal_alter()
   */
  public function invoke($module, $hook) {
    $args = func_get_args();
    // Remove $module and $hook from the arguments.
    unset($args[0], $args[1]);
    if (module_hook($module, $hook)) {
      return call_user_func_array($module . '_' . $hook, $args);
    }
  }

  /**
   * Invokes a hook in all enabled modules that implement it.
   *
   * All arguments are passed by value. Use drupal_alter() if you need to pass
   * arguments by reference.
   *
   * @param string $hook
   *   The name of the hook to invoke.
   * @param ...
   *   Arguments to pass to the hook.
   *
   * @return array
   *   An array of return values of the hook implementations. If modules return
   *   arrays from their implementations, those are merged into one array.
   *
   * @see drupal_alter()
   */
  public function invokeAll($hook) {
    $args = func_get_args();
    // Remove $hook from the arguments.
    unset($args[0]);
    $return = array();
    foreach ($this->moduleImplements($hook) as $module) {
      $function = $module . '_' . $hook;
      if (function_exists($function)) {
        $result = call_user_func_array($function, $args);
        if (isset($result) && is_array($result)) {
          $return = array_merge_recursive($return, $result);
        }
        elseif (isset($result)) {
          $return[] = $result;
        }
      }
    }

    return $return;
  }

}
