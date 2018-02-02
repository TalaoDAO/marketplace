<?php

/**
 * @file
 * Contains a RandomNameGenerator
 */

namespace Drupal\ghost\Utilities;


/**
 * Class RandomNameGenerator
 * @package Drupal\ghost\Utilities
 */
class RandomNameGenerator {

  /**
   * Return a random name.
   *
   * @return string
   *   A randomly generated name.
   */
  static public function randomName() {

    $chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    $str = '';

    $size = strlen($chars);
    for ($i = 0; $i < 10; $i++) {
      $str .= $chars[rand(0, $size - 1)];
    }

    return $str;
  }
}
