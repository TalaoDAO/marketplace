<?php
/**
 * @file
 * Serial (Fields Helper).
 */

/**
 * Class SerialFields.
 */
class SerialFields {

  private $fields = array();
  private $instances = array();

  /**
   * Set field definitions.
   *
   * @param array[] $fields
   *   An associative array where keys - field names and values - definition.
   */
  public function __construct(array $fields) {
    $this->fields = $fields;
  }

  /**
   * Create fields.
   *
   * @return self
   *   Object instance.
   *
   * @throws \FieldException
   *   When cannot create a field.
   */
  public function create() {
    foreach ($this->fields as $name => $data) {
      if (!db_table_exists("field_data_$name")) {
        field_create_field($data + array(
          'default' => '',
          'not null' => TRUE,
          'field_name' => $name,
        ));
      }
    }

    return $this;
  }

  /**
   * Completely delete fields.
   *
   * This function deletes tables: "field_data_NAME" and "field_revision_NAME"
   * and entries in "field_config" and "field_config_instances".
   *
   * @return self
   *   Object instance.
   */
  public function delete() {
    foreach (array_keys($this->fields) as $name) {
      // Delete tables.
      foreach (array('data', 'revision') as $table_type) {
        $table = "field_{$table_type}_{$name}";

        if (db_table_exists($table)) {
          db_drop_table($table);
        }
      }

      // Delete entries.
      foreach (array('config', 'config_instance') as $table_type) {
        db_delete("field_$table_type")
          ->condition('field_name', $name)
          ->execute();
      }
    }

    return $this;
  }

  /**
   * Attach existing fields into entity.
   *
   * @param string $entity_type
   *   Entity machine name.
   * @param string $bundle_name
   *   Entity bundle name.
   *
   * @return self
   *   Object instance.
   *
   * @throws \FieldException
   *   When instance cannot be created.
   */
  public function attach($entity_type, $bundle_name) {
    $attached_fields = field_info_instances($entity_type, $bundle_name);

    foreach ($this->fields as $field_name => $data) {
      if (empty($attached_fields[$field_name]) && field_info_field($field_name)) {
        // Provide a possibility to specify field weight, depending on
        // another one.
        //
        // @code
        // $fields = array(
        //   'field_title' => array(
        //     'type' => 'text',
        //     'label' => 'Title',
        //     'widget' => array(
        //       'weight' => 10,
        //     ),
        //   ),
        //   'field_description' => array(
        //     'type' => 'text',
        //     'label' => 'Description',
        //     'widget' => array(
        //       // Weight of this field will be "9".
        //       'weight' => array('field_title', -1),
        //     ),
        //   ),
        // );
        // @endcode
        if (isset($data['widget']['weight']) && is_array($data['widget']['weight'])) {
          list($dependent, $calc) = $data['widget']['weight'];

          $dependent = field_info_instance($entity_type, $dependent, $bundle_name);

          if (!empty($dependent)) {
            $data['widget']['weight'] = $dependent['widget']['weight'] + $calc;
          }
        }

        field_create_instance($data + array(
          'bundle' => $bundle_name,
          'field_name' => $field_name,
          'entity_type' => $entity_type,
        ));
      }
    }

    return $this;
  }

  /**
   * Get field instances.
   *
   * @return array[]
   *   Field instances.
   */
  public function &getInstances() {
    if (empty($this->instances)) {
      $query = db_select('field_config_instance', 'fci')
        ->fields('fci', array('field_name', 'data'))
        ->condition('field_name', array_keys($this->fields))
        ->execute()
        ->fetchAllKeyed();

      $this->instances = array_map('unserialize', $query);
    }

    return $this->instances;
  }

  /**
   * Field definitions getter.
   *
   * @return array[]
   *   Field definitions.
   */
  public function getFields() {
    return $this->fields;
  }

  /**
   * Save field instances.
   *
   * @return self
   *   Object instance.
   *
   * @throws \Exception
   * @throws \InvalidMergeQueryException
   */
  public function saveInstances() {
    foreach ($this->instances as $field_name => $data) {
      db_merge('field_config_instance')
        ->fields(array('data' => serialize($data)))
        ->condition('field_name', $field_name)
        ->execute();
    }

    return $this;
  }

}
