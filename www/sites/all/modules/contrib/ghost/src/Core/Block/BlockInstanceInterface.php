<?php

/**
 * @file
 * Contains a BlockInstanceInterface
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Block;

use Drupal\ghost\Type\Storable\StorableInterface;

/**
 * Interface BlockInstanceInterface
 *
 * @package Drupal\ghost\Core\Block
 */
interface BlockInstanceInterface extends StorableInterface {

  /**
   * Create a new block with defaults pre-filled.
   *
   * @return BlockInstanceInterface
   *   An instance of BlockInstanceInterface
   * @static
   */
  public static function create();

  /**
   * Getter for bid.
   *
   * @return int
   *   The BID
   */
  public function getBid();

  /**
   * Setter for bid.
   *
   * @param int $bid
   *   The value for bid.
   */
  public function setBid($bid);

  /**
   * Getter for module.
   *
   * @return string
   *   The module name
   */
  public function getModule();

  /**
   * Setter for module.
   *
   * @param string $module
   *   The value for module.
   */
  public function setModule($module);

  /**
   * Getter for delta.
   *
   * @return string
   *   The delta
   */
  public function getDelta();

  /**
   * Setter for delta.
   *
   * @param string $delta
   *   The value for delta.
   */
  public function setDelta($delta);

  /**
   * Getter for theme.
   *
   * @return string
   *   The theme name
   */
  public function getTheme();

  /**
   * Setter for theme.
   *
   * @param string $theme
   *   The value for theme.
   */
  public function setTheme($theme);

  /**
   * Getter for status.
   *
   * @return int
   *   The status
   */
  public function getStatus();

  /**
   * Setter for status.
   *
   * @param int $status
   *   The value for status.
   */
  public function setStatus($status);

  /**
   * Getter for weight.
   *
   * @return int
   *   The weight
   */
  public function getWeight();

  /**
   * Setter for weight.
   *
   * @param int $weight
   *   The value for weight.
   */
  public function setWeight($weight);

  /**
   * Getter for region.
   *
   * @return string
   *   The region
   */
  public function getRegion();

  /**
   * Setter for region.
   *
   * @param string $region
   *   The value for region.
   */
  public function setRegion($region);

  /**
   * Getter for custom.
   *
   * @return int
   *   The custom value
   */
  public function getCustom();

  /**
   * Setter for custom.
   *
   * @param int $custom
   *   The value for custom.
   */
  public function setCustom($custom);

  /**
   * Getter for visibility.
   *
   * @return int
   *   The visibility
   */
  public function getVisibility();

  /**
   * Setter for visibility.
   *
   * @param int $visibility
   *   The value for visibility.
   */
  public function setVisibility($visibility);

  /**
   * Getter for pages.
   *
   * @return string
   *   The pages value.
   */
  public function getPages();

  /**
   * Setter for pages.
   *
   * @param string $pages
   *   The value for pages.
   */
  public function setPages($pages);

  /**
   * Getter for title.
   *
   * @return string
   *   The title
   */
  public function getTitle();

  /**
   * Setter for title.
   *
   * @param string $title
   *   The value for title.
   */
  public function setTitle($title);

  /**
   * Getter for cache.
   *
   * @return int
   *   The cache value.
   */
  public function getCache();

  /**
   * Setter for cache.
   *
   * @param mixed $cache
   *   The value for cache.
   */
  public function setCache($cache);

  /**
   * Get the Block Name.
   *
   * @return string
   *   Unique name of the block.
   */
  public function getBlockName();
}
