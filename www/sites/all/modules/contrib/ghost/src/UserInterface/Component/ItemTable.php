<?php

namespace Drupal\ghost\UserInterface\Component;


/**
 * Class ItemTable.
 *
 * @package Drupal\ghost\UserInterface\Component
 */
class ItemTable extends BaseComponent {

  /**
   * The items to put in the table.
   *
   * @var array
   */
  public $items;

  /**
   * The columns for the table.
   *
   * @var array
   */
  public $columns;

  /**
   * The empty message.
   *
   * @var string
   */
  public $empty = '';

  /**
   * Lazy constructor.
   *
   * @return static
   *   An instance of ItemTable
   *
   * @static
   */
  static public function init() {

    return new static();
  }

  /**
   * {@inheritdoc}
   */
  public function render() {

    $rows = array();

    if (!empty($this->items)) {
      foreach ($this->items as $item) {
        $row = array();

        foreach (array_keys($this->columns) as $column_name) {
          $row[$column_name] = $item[$column_name];
        }

        $rows[] = $row;
      }
    }

    $vars = array(
      'header' => $this->columns,
      'rows' => $rows,
      'empty' => $this->empty,
    );

    $output = theme('table', $vars);

    return $output;
  }

  /**
   * Setter for items.
   *
   * @param array $items
   *   The value for items.
   */
  public function setItems(array $items) {

    $this->items = $items;
  }

  /**
   * Set an item.
   *
   * @param string $key
   *   Key for the item.
   * @param array $item
   *   The item.
   */
  public function setItem($key, $item) {
    $this->items[$key] = $item;
  }

  /**
   * Setter for columns.
   *
   * @param array $columns
   *   The value for columns.
   */
  public function setColumns(array $columns) {

    $this->columns = $columns;
  }

  /**
   * Setter for empty.
   *
   * @param string $empty
   *   The value for empty.
   */
  public function setEmpty($empty) {

    $this->empty = $empty;
  }

}
