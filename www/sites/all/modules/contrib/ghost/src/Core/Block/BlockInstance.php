<?php

/**
 * @file
 * Contains a BlockInstance
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Block;

use Drupal\ghost\Type\Storable\Storable;

/**
 * Class BlockInstance
 *
 * @package Drupal\ghost\Core\Block
 */
class BlockInstance extends Storable implements BlockInstanceInterface {

  /**
   * The Block ID
   *
   * @var int
   */
  public $bid;

  /**
   * The module from which the block originates.
   *
   * For example, ’user’ for the Who’s Online block, and
   * ’block’ for any custom blocks.
   *
   * @var string
   */
  public $module;

  /**
   * Unique ID for block within a module.
   *
   * @var string
   */
  public $delta;

  /**
   * The theme under which the block settings apply.
   *
   * @var string
   */
  public $theme;

  /**
   * Block enabled status.
   *
   * 1 = enabled, 0 = disabled.
   *
   * @var int
   */
  public $status;

  /**
   * Block weight within region.
   *
   * @var int
   */
  public $weight;

  /**
   * Theme region within which the block is set.
   *
   * @var string
   */
  public $region;

  /**
   * Flag to indicate how users may control visibility of the block.
   *
   * 0 = Users cannot control,
   * 1 = On by default, but can be hidden,
   * 2 = Hidden by default, but can be shown
   *
   * @var int
   */
  public $custom;

  /**
   * Flag to indicate how to show blocks on pages.
   *
   * 0 = Show on all pages except listed pages.
   * 1 = Show only on listed pages.
   * 2 = Use custom PHP code to determine visibility.
   *
   * @var int
   */
  public $visibility;

  /**
   * Contents of the "Pages" block.
   *
   * Contains either a list of paths on which to include/exclude the block
   * or PHP code, depending on "visibility" setting.
   *
   * @var string
   */
  public $pages;

  /**
   * Custom title for the block.
   *
   * Empty string will use block default title, <none> will remove the title,
   * text will cause block to use specified title.
   *
   * @var string
   */
  public $title;

  /**
   * Binary flag to indicate block cache mode.
   *
   * -2: Custom cache,
   * -1: Do not cache,
   * 1: Cache per role,
   * 2: Cache per user,
   * 4: Cache per page,
   * 8: Block cache global)
   *
   * See DRUPAL_CACHE_* constants in ../includes/common.inc
   * for more detailed information.
   *
   * @var int
   */
  public $cache;

  /**
   * Create a new block with defaults pre-filled.
   *
   * @return BlockInstanceInterface
   *   An instance of BlockInstanceInterface
   * @static
   */
  static public function create() {
    $block = new static();

    $block->region = BLOCK_REGION_NONE;
    $block->weight = 0;
    $block->visibility = BLOCK_VISIBILITY_NOTLISTED;
    $block->title = '';
    $block->pages = '';
    $block->cache = DRUPAL_NO_CACHE;

    return $block;
  }

  /**
   * Constructor.
   */
  public function __construct() {
  }

  /**
   * Get the unique identifier.
   *
   * @return mixed
   *   The key for storage.
   */
  public function getIdentifier() {

    return $this->getBid();
  }

  /**
   * Get the Block Name.
   *
   * @return string
   *   Unique name of the block.
   */
  public function getBlockName() {

    return $this->getTheme() . '_' . $this->getModule() . '_' . $this->getDelta();
  }

  /**
   * Getter for bid.
   *
   * @return int
   *   The BID
   */
  public function getBid() {

    return $this->bid;
  }

  /**
   * Setter for bid.
   *
   * @param int $bid
   *   The value for bid.
   */
  public function setBid($bid) {

    $this->bid = $bid;
  }

  /**
   * Getter for module.
   *
   * @return string
   *   The module name
   */
  public function getModule() {

    return $this->module;
  }

  /**
   * Setter for module.
   *
   * @param string $module
   *   The value for module.
   */
  public function setModule($module) {

    $this->module = $module;
  }

  /**
   * Getter for delta.
   *
   * @return string
   *   The delta
   */
  public function getDelta() {

    return $this->delta;
  }

  /**
   * Setter for delta.
   *
   * @param string $delta
   *   The value for delta.
   */
  public function setDelta($delta) {

    $this->delta = $delta;
  }

  /**
   * Getter for theme.
   *
   * @return string
   *   The theme name
   */
  public function getTheme() {

    if (empty($this->theme)) {
      $this->theme = variable_get('theme_default', 'bartik');
    }

    return $this->theme;
  }

  /**
   * Setter for theme.
   *
   * @param string $theme
   *   The value for theme.
   */
  public function setTheme($theme) {

    $this->theme = $theme;
  }

  /**
   * Getter for status.
   *
   * @return int
   *   The status
   */
  public function getStatus() {

    return (int) ($this->getRegion() != BLOCK_REGION_NONE);
  }

  /**
   * Setter for status.
   *
   * @param int $status
   *   The value for status.
   */
  public function setStatus($status) {

    $this->status = $status;
  }

  /**
   * Getter for weight.
   *
   * @return int
   *   The weight
   */
  public function getWeight() {

    return $this->weight;
  }

  /**
   * Setter for weight.
   *
   * @param int $weight
   *   The value for weight.
   */
  public function setWeight($weight) {

    $this->weight = $weight;
  }

  /**
   * Getter for region.
   *
   * @return string
   *   The region
   */
  public function getRegion() {

    return $this->region;
  }

  /**
   * Setter for region.
   *
   * @param string $region
   *   The value for region.
   */
  public function setRegion($region) {

    $this->region = $region;
  }

  /**
   * Getter for custom.
   *
   * @return int
   *   The custom value
   */
  public function getCustom() {

    return $this->custom;
  }

  /**
   * Setter for custom.
   *
   * @param int $custom
   *   The value for custom.
   */
  public function setCustom($custom) {

    $this->custom = $custom;
  }

  /**
   * Getter for visibility.
   *
   * @return int
   *   The visibility
   */
  public function getVisibility() {

    return $this->visibility;
  }

  /**
   * Setter for visibility.
   *
   * @param int $visibility
   *   The value for visibility.
   */
  public function setVisibility($visibility) {

    $this->visibility = $visibility;
  }

  /**
   * Getter for pages.
   *
   * @return string
   *   The pages value.
   */
  public function getPages() {

    return $this->pages;
  }

  /**
   * Setter for pages.
   *
   * @param string $pages
   *   The value for pages.
   */
  public function setPages($pages) {

    $this->pages = $pages;
  }

  /**
   * Getter for title.
   *
   * @return string
   *   The title
   */
  public function getTitle() {

    return $this->title;
  }

  /**
   * Setter for title.
   *
   * @param string $title
   *   The value for title.
   */
  public function setTitle($title) {

    $this->title = $title;
  }

  /**
   * Getter for cache.
   *
   * @return int
   *   The cache value.
   */
  public function getCache() {

    return $this->cache;
  }

  /**
   * Setter for cache.
   *
   * @param mixed $cache
   *   The value for cache.
   */
  public function setCache($cache) {

    $this->cache = $cache;
  }

  /**
   * Get database write values for this block.
   *
   * @return array
   *   An array suitable for database writes.
   */
  public function getStorableValues() {
    $block_array = (array) $this;

    $field_names = $this->getFieldNames();

    $block_array['weight'] = (int) $this->getWeight();
    $block_array['visibility'] = (int) $this->getVisibility();
    $block_array['status'] = (int) $this->getStatus();

    $block_array = array_intersect_key($block_array, array_flip($field_names));

    return $block_array;
  }

  /**
   * Get field names.
   *
   * @todo refactor this into the Interface
   *
   * @return array
   *   An array of valid field names.
   */
  public function getFieldNames() {
    return array(
      'visibility',
      'pages',
      'module',
      'theme',
      'status',
      'weight',
      'delta',
      'cache',
      'region',
      'title',
    );
  }
}
