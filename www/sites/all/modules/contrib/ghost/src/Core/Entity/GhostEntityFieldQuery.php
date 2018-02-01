<?php

/**
 * @file
 * Contains a GhostEntityFieldQuery
 */

namespace Drupal\ghost\Core\Entity;

use EntityFieldQuery;

/**
 * Class GhostEntityFieldQuery
 * @package Drupal\ghost\Entity
 */
class GhostEntityFieldQuery extends \EntityFieldQuery {

  /**
   * The result.
   *
   * @var array
   */
  public $result;

  /**
   * The entity.
   *
   * @var
   */
  public $entity;

  /**
   * The added fields.
   *
   * @var array
   */
  protected $addedFields = array();

  /**
   * Lazy constructor.
   *
   * @return GhostEntityFieldQuery
   *   An EntityFieldQuery.
   */
  static public function init() {
    return new static();
  }

  /**
   * Set the entity type.
   *
   * @param string $type
   *   A valid entity type.
   *
   * @return GhostEntityFieldQuery
   *   This query object.
   */
  public function type($type) {

    return $this->entityCondition('entity_type', $type);
  }

  /**
   * Set the bundle type.
   *
   * @param string|array $bundle
   *   The bundle or an array of bundles.
   *
   * @return GhostEntityFieldQuery
   *   This query object.
   */
  public function bundle($bundle) {

    if (is_array($bundle)) {
      return $this->entityCondition('bundle', $bundle, 'IN');
    }

    return $this->entityCondition('bundle', $bundle);
  }

  /**
   * {@inheritdoc}
   */
  public function execute() {

    $this->result = parent::execute();

    return $this;
  }

  /**
   * Get any result items.
   *
   * @return array
   *   An array of result items.
   */
  public function getResultItems() {
    if (isset($this->result)) {

      $entity_type = $this->entityConditions['entity_type']['value'];

      if (isset($this->result[$entity_type])) {
        return $this->result[$entity_type];
      }
    }

    return array();
  }

  /**
   * Finishes the query.
   *
   * Adds tags, metaData, range and returns the requested list or count.
   *
   * @param \SelectQuery $select_query
   *   A SelectQuery which has entity_type, entity_id, revision_id and bundle
   *   fields added.
   * @param string $id_key
   *   Which field's values to use as the returned array keys.
   *
   * @return array
   *   The query result.
   * See EntityFieldQuery::execute().
   */
  public function finishQuery($select_query, $id_key = 'entity_id') {
    // http://drupal.org/node/1226622#comment-6809826 - adds support for IS NULL
    // Iterate through all fields.  If the query is trying to fetch results
    // where a field is null, then alter the query to use a LEFT OUTER join.
    // Otherwise the query will always return 0 results.
    $tables =& $select_query->getTables();
    foreach ($this->fieldConditions as $key => $field_condition) {
      if ($field_condition['operator'] == 'IS NULL' && isset($this->fields[$key]['storage']['details']['sql'][FIELD_LOAD_CURRENT])) {
        $keys = array_keys($this->fields[$key]['storage']['details']['sql'][FIELD_LOAD_CURRENT]);
        $sql_table = reset($keys);
        foreach ($tables as $table_id => $table) {
          if ($table['table'] == $sql_table) {
            $tables[$table_id]['join type'] = 'LEFT OUTER';
          }
        }
      }
    }

    foreach ($this->tags as $tag) {
      $select_query->addTag($tag);
    }
    foreach ($this->metaData as $key => $object) {
      $select_query->addMetaData($key, $object);
    }
    $select_query->addMetaData('entity_field_query', $this);
    if ($this->range) {
      $select_query->range($this->range['start'], $this->range['length']);
    }
    if ($this->count) {
      return $select_query->countQuery()->execute()->fetchField();
    }
    $return = array();

    foreach ($this->addedFields as $added_field) {
      $fields = $select_query->getFields();

      if (!empty($added_field['field_name'])) {
        $tables = $select_query->getTables();
        $clean_tables = $this->cleanTables($tables);
        // Hardcoded as it is also hardcoded in the fields module.
        $table = 'field_data_' . $added_field['field_name'];

        // Get our alias for the selected field.
        if (isset($clean_tables[$table])) {
          $added_field['table'] = $clean_tables[$table]['alias'];
        }

        // Set our name and alias.
        $column = $added_field['field_name'] . '_' . $added_field['column'];
        $column_alias = $added_field['field_name'] . '_' . $added_field['column_alias'];
      }
      else {
        // Not from a field, so probably a direct entity property.
        $column = $added_field['column'];
        $column_alias = $added_field['column_alias'];
      }
      if (!empty($added_field['table'])) {
        // If we know the exact table, set it.
        $select_query->addField($added_field['table'], $column, $column_alias);
      }
      else {
        // If not, use the main selected table to fetch the extra field from.
        $select_query->addField($fields['entity_id']['table'], $column, $column_alias);
      }
    }

    foreach ($select_query->execute() as $partial_entity) {
      $bundle = isset($partial_entity->bundle) ? $partial_entity->bundle : NULL;
      $entity = entity_create_stub_entity($partial_entity->entity_type, array(
        $partial_entity->entity_id,
        $partial_entity->revision_id,
        $bundle,
        ));
      $entity->entity = $partial_entity;

      // If the id already exists, merge the data in a smart way. This
      // is completely based on the assumption that we expect a similar entity.
      if (isset($return[$partial_entity->entity_type][$partial_entity->$id_key])) {
        $previous_entity = $return[$partial_entity->entity_type][$partial_entity->$id_key];
        foreach ($previous_entity->entity as $id => $child) {
          // Found a distinct value, make it into an array.
          if (!is_array($previous_entity->entity->{$id})) {
            if ($entity->entity->{$id} != $previous_entity->entity->{$id}) {
              $entity->entity->{$id} = array($previous_entity->entity->{$id}, $entity->entity->{$id});
            }
          }
          // Found more distinct values. Append to the array. Avoid duplicates.
          else {
            if (!in_array($entity->entity->{$id}, $previous_entity->entity->{$id})) {
              $previous_entity->entity->{$id}[] = $entity->entity->{$id};
              $entity->entity->{$id} = $previous_entity->entity->{$id};
            }
          }
        }
      }

      // Add the entity to the result set to return.
      $return[$partial_entity->entity_type][$partial_entity->$id_key] = $entity;
      $this->ordered_results[] = $partial_entity;
    }
    return $return;
  }

  /**
   * Add the given field with an INNER JOIN and add a select statement.
   *
   * For the requested field
   *
   * @param string $field_name
   *   Name of the field
   * @param string $column
   *   Name of the column
   * @param string $column_alias
   *   The column alias
   * @param string $table
   *   The table
   *
   * @return GhostEntityFieldQuery
   *   An instance of GhostEntityFieldQuery
   */
  public function addExtraField($field_name, $column, $column_alias = NULL, $table = NULL) {
    if (!empty($field_name) && !$this->checkFieldExists($field_name)) {
      // Add the field as a condition, so we generate the join.
      $this->fieldCondition($field_name);
    }

    $this->addedFields[] = array(
      'field_name' => $field_name,
      'column' => $column,
      'column_alias' => $column_alias,
      'table' => $table,
    );

    return $this;
  }

  /**
   * Clean tables.
   *
   * Give the values in the array the name of the real table instead of the
   * alias, so we can look up the alias quicker.
   *
   * @param array $tables
   *   Tables.
   *
   * @return array
   *   Tables.
   */
  protected function cleanTables($tables) {
    if (!is_array($tables)) {
      return array();
    }
    foreach ($tables as $table_id => $table) {
      if ($table['join type'] == 'INNER') {
        $tables[$table['table']] = $table;
        unset($tables[$table_id]);
      }
    }
    return $tables;
  }

  /**
   * Check if the field already has a table that does a join.
   *
   * @param string $field_name
   *   The field name.
   *
   * @return bool
   *   TRUE or FALSE.
   */
  protected function checkFieldExists($field_name) {
    $fields = $this->fields;
    foreach ($fields as $field) {
      if (isset($field['field_name']) && $field['field_name'] == $field_name) {
        return TRUE;
      }
    }
    return FALSE;
  }
}
