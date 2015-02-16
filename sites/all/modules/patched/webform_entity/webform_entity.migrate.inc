<?php


/**
 * Provides a migration destination for webform submission entities.
 *
 * Fields from field.module are named field_* and webform.module's components
 * are named data_*.
 */
class MigrateDestinationWebformSubmissionEntity extends MigrateDestinationEntity {
  static public function getKeySchema() {
    return array(
      'sid' => array(
        'type' => 'int',
        'not null' => TRUE,
        'unsigned' => TRUE,
      ),
    );
  }

  /**
   * The webform of the destination.
   *
   * In some cases this may be a class with only type and webform properties.
   * This is useful when you're doing a migration that creates submissions for
   * multiple webforms of the same type. Of course when you don't have
   * individual webforms you can't map fields to components.
   *
   * @var object
   */
  protected $node;
  public function getWebform() {
    return $this->node;
  }

  /**
   * An array mapping our custom names to component ids.
   *
   * @var array
   */
  protected $component_cids;

  /**
   * Constructs a destination for a given webform node.
   *
   * @param $node_or_type
   *   A node object or string that indicates the node type that's has been
   *   enabled for webform use.
   * @param $options
   *   Array of options passed to MigrateDestinationEntity's constructor.
   */
  public function __construct($node_or_type, array $options = array()) {
    if (is_string($node_or_type)) {
      // If they specified a type build a little, mock node.
      $this->node = (object) array(
        'type' => $node_or_type,
        'webform' => array(),
      );
    }
    else if (is_object($node_or_type) && !empty($node_or_type->type)) {
      $this->node = $node_or_type;
    }

    // Make sure the node type is on webform's list.
    $types = webform_variable_get('webform_node_types');
    if (!in_array($this->node->type, $types)) {
      throw new Exception(t("You need to provide either a node object or string node type that is configured to accept webform submissions. We found %type wanting.", array('%type' => $this->node->type)));
    }

    parent::__construct('webform_submission_entity', $this->node->type, $options);

    // Webform expects the component values to be keyed by cid, so we need a
    // hash to map prefixed field names to cid.
    $this->component_cids = array();
    if (isset($this->node->webform['components'])) {
      foreach ($this->node->webform['components'] as $component) {
        $this->component_cids['data_' . $component['form_key']] = $component['cid'];
      }
    }

    // We use the functions in this file in import() but load it here so we
    // only do it once.
    module_load_include('inc', 'webform', 'includes/webform.submissions');
  }

  public function __toString() {
    if (empty($this->node->nid)) {
      return t('Submissions to the <a href="!link">%type</a> webforms', array(
        '!link' => url('admin/config/content/webform/entities/' . strtr($this->node->type, array('_' => '-')) . '/fields'),
        '%type' => node_type_get_name($this->node->type),
      ));
    }
    return t('Submissions to the <a href="!link">%title</a> webform', array(
      '!link' => url('node/' . $this->node->nid),
      '%title' => $this->node->title,
    ));
  }

  /**
   * Returns a list of fields available to be mapped.
   *
   * @return array
   *   Keys: machine names of the fields (to be passed to addFieldMapping)
   *   Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    // Fields defined by the schema.
    $fields = array(
      'sid' => t('The unique identifier for this submission.'),
      'uid' => t('The id of the user that completed this submission.'),
      'is_draft' => t('Is this a draft of the submission?'),
      'submitted' => t('Timestamp of when the form was submitted.'),
      'remote_addr' => t('The IP address of the user that submitted the form.'),
    );
    // The nid is omitted when we can load it from from $this->node.
    if (empty($this->node->nid)) {
      $fields['nid'] = t('The webform node id.');
    }

    // Create a field for each component on the webform.
    if (isset($this->node->webform['components'])) {
      foreach ($this->node->webform['components'] as $component) {
        // TODO: Seems like we should skip over page break components.
        $fields['data_' . $component['form_key']] = t('@type: @name', array('@type' => $component['type'], '@name' => $component['name']));
      }
    }

    // Then add in anything provided by handlers.
    $fields += migrate_handler_invoke_all('WebformSubmission', 'fields', $this->node);
    $fields += migrate_handler_invoke_all('Entity', 'fields', $this->entityType, $this->bundle);

    return $fields;
  }

  /**
   * Import a record.
   *
   * @param $entity
   *   Webform submission object to build. This is the complete object after
   *   saving.
   * @param $source_row
   *   Raw source data object - passed through to complete handlers.
   */
  public function import(stdClass $entity, stdClass $row) {
    // Updating previously-migrated content?
    $migration = Migration::currentMigration();
    if (isset($row->migrate_map_destid1)) {
      if (isset($entity->sid) && $entity->sid != $row->migrate_map_destid1) {
        throw new MigrateException(t("Incoming sid !sid and map destination sid !destid1 don't match",
          array('!sid' => $entity->sid, '!destid1' => $row->migrate_map_destid1)));
      }
      else {
        $entity->sid = $row->migrate_map_destid1;
      }
    }

    $entity->bundle = $this->bundle;
    if (empty($this->node->nid)) {
      $entity->data = array();
    }
    else {
      // Hard code the node id so it doesn't need to be set via mapping.
      $entity->nid = $this->node->nid;

      // Move the data from our custom keys back to webform's component ids.
      $data = array();
      foreach ($this->component_cids as $field_name => $cid) {
        if (isset($entity->$field_name)) {
          // Move the arguments out and kill any extraneous wrapper arrays.
          $value = $entity->$field_name;
          $arguments = array();
          if (is_array($value) && isset($value['arguments'])) {
            $arguments = (array) $value['arguments'];
            unset($value['arguments']);
            $value = count($value) ? reset($value) : $value;
          }
          // Avoid a warning if they passed in an empty array.
          $arguments += array('source_type' => 'key');

          // By default passed to select components are assumed to be the
          // key. If the key should be looked up use the add a
          // array('source_type' => 'value') argument to the field mapping.
          $component = $this->node->webform['components'][$cid];
          if ($component['type'] == 'select' && $arguments['source_type'] == 'value') {
            module_load_include('inc', 'webform', 'components/select.inc');
            $options = _webform_select_options($component);
            $id = array_search($value, $options);
            $data[$cid] = ($id === FALSE) ? NULL : $id;
          }
          else {
            $data[$cid] = $value;
          }
          unset($entity->$field_name);
        }
      }
      $entity->data = webform_submission_data($this->node, $data);
    }

    // Invoke migration prepare handlers.
    $this->prepare($entity, $row);

    // We've done what we can without a webform but now have to have one, if
    // it hasn't been set by now bail.
    $webform = empty($this->node->nid) ? node_load($entity->nid) : $this->node;
    if (empty($webform)) {
      // Cannot create a submission with out a webform node id.
      return FALSE;
    }

    migrate_instrument_start('webform_submission_update/insert');
    // Determine if it's an insert or update.
    if (empty($entity->sid)) {
      if (empty($entity->data)) {
        $entity->data[] = array(
          array(
            'value' => '',
          ),
        );
      }
      $updating = FALSE;
      $sid = webform_submission_insert($webform, $entity);
    }
    else {
      // If the sid was specified but doesn't exist we'll need to stick an
      // empty record in so webform's update has something to stick to.
      $status = db_merge('webform_submissions')
        ->key(array(
          'sid' => $entity->sid,
        ))
        ->insertFields(array(
          'sid' => $entity->sid,
          'nid' => $entity->nid,
          'submitted' => $entity->submitted,
          'remote_addr' => $entity->remote_addr,
          'is_draft' => $entity->is_draft,
          'bundle' => $entity->bundle,
        ))
        ->execute();
        // If db_merge() makes no changes $status is NULL so make a less
        // elegant comparison.
      $updating = MergeQuery::STATUS_INSERT !== $status;
      $sid = webform_submission_update($webform, $entity);
    }
    migrate_instrument_stop('webform_submission_update/insert');

    if (isset($sid)) {
      $entity->sid = $sid;

      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
      $return = array($sid);
    }
    else {
      $return = FALSE;
    }

    // Invoke migration complete handlers
    $this->complete($entity, $row);

    return $return;
  }

  /**
   * Delete a batch of submissions at once.
   *
   * @param $sids
   *   Array of submission IDs to be deleted.
   */
  public function bulkRollback(array $sids) {
    migrate_instrument_start(__METHOD__);
    $this->prepareRollback($sids);
    foreach (webform_get_submissions(array('sid' => $sids)) as $submission) {
      // Gotta have a webform.
      $webform = empty($this->node->nid) ? node_load($submission->nid) : $this->node;
      webform_submission_delete($webform, $submission);
    }
    $this->completeRollback($sids);
    migrate_instrument_stop(__METHOD__);
  }
}
