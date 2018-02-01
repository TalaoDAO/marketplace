<?php

/**
 * @file
 * Contains a
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Block\Controller;

use Drupal\ghost\Controller\ControllerInterface;
use Drupal\ghost\Type\Storable\StorableInterface;

/**
 * Class BlockController
 *
 * @package Drupal\ghost\Core\Block\Controller
 */
class BlockController implements ControllerInterface {

  /**
   * Create a new instance.
   *
   * @return static
   *   A new instance of ControllerInterface.
   * @static
   */
  static public function create() {
    return new static();
  }

  /**
   * Insert an item.
   *
   * @param \Drupal\ghost\Type\Storable\StorableInterface $item
   *   The item to insert.
   */
  public function insert(StorableInterface $item) {
    $query = db_insert('block')->fields($this->getFields());
    $query->values($item->getStorableValues());
    $query->execute();
  }

  /**
   * Insert multiple items.
   *
   * @param array $items
   *   An array of StorableInterface items.
   */
  public function insertMany(array $items) {
    if (!empty($items)) {
      $query = db_insert('block')->fields($this->getFields());
      foreach ($items as $insert) {
        /* @var StorableInterface $insert */
        $query->values($insert->getStorableValues());
      }
      $query->execute();
    }
  }

  /**
   * Update an item.
   *
   * @param \Drupal\ghost\Type\Storable\StorableInterface $item
   *   The item to insert.
   */
  public function update(StorableInterface $item) {
    db_update('block')->fields($item->getStorableValues())
      ->condition('bid', $item->getIdentifier())
      ->execute();
  }

  /**
   * Update multiple items.
   *
   * @param array $items
   *   An array of StorableInterface items.
   */
  public function updateMany(array $items) {
    foreach ($items as $update) {
      $this->update($update);;
    }
  }

  /**
   * Delete an item.
   *
   * @param \Drupal\ghost\Type\Storable\StorableInterface $item
   *   The item to delete.
   */
  public function delete(StorableInterface $item) {
    db_delete('block')->condition('bid', $item->getIdentifier())
      ->execute();
  }

  /**
   * Load a single item.
   *
   * @param mixed $identifier
   *   The item to load.
   *
   * @return mixed
   *   The result of the load operation.
   */
  public function load($identifier) {
    $block = db_select('block', 'b')
      ->condition('bid', $identifier)
      ->execute()
      ->fetchAssoc();

    $block['block_name'] = $this->makeBlockName($block);

    return $block;
  }

  /**
   * Load a module by its delta, module and theme.
   *
   * @param string $delta
   *   The delta.
   * @param string $module
   *   The module
   * @param string $theme
   *   The theme
   *
   * @return bool|array
   *   The data, or false.
   */
  public function loadByDelta($delta, $module, $theme) {

    $and = db_and()->condition('theme', $theme)
      ->condition('module', $module)
      ->condition('delta', $delta);

    $block = db_select('block', 'b')
      ->fields('b')
      ->condition($and)
      ->execute()
      ->fetchAssoc();

    if (empty($block)) {
      return FALSE;
    }

    $block['block_name'] = $this->makeBlockName($block);

    return $block;
  }

  /**
   * Load many.
   *
   * @param array $identifiers
   *   An array of identifiers.
   *
   * @return array
   *   An array of items.
   */
  public function loadMany(array $identifiers) {
    // TODO: Implement loadMany() method.
  }

  /**
   * Get all items.
   *
   * @return array
   *   An array items.
   */
  public function fetchAll() {

    $blocks_info = db_select('block', 'b')
      ->fields('b')
      ->execute()
      ->fetchAll();

    if (!empty($blocks_info)) {
      foreach ($blocks_info as $bid => $block_info) {
        $blocks_info[$bid]->block_name = $this->makeBlockName($block_info);
      }
    }

    return $blocks_info;
  }

  /**
   * Get field keys.
   *
   * @return array
   *   Fields for the block
   */
  protected function getFields() {
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

  /**
   * Make a Block name.
   *
   * @param \stdClass|array $block_info
   *   A database record.
   *
   * @return string
   *   A name.
   */
  public function makeBlockName($block_info) {

    $info = (array) $block_info;

    return $info['theme'] . '_' . $info['module'] . '_' . $info['delta'];
  }
}
