<?php
/**
 * @file
 * Admin ui controllers for entity_legal entities.
 */

/**
 * Legal Document entity ui controller.
 */
class EntityLegalDocumentUIController extends EntityDefaultUIController {
  /**
   * {@inheritdoc}
   */
  public function hook_menu() {
    $items = parent::hook_menu();

    // Remove title callbacks that cause bundle notices.
    foreach ($items as &$item) {
      if (isset($item['title callback']) && $item['title callback'] == 'entity_ui_get_action_title') {
        unset($item['title callback']);
        $item['title'] = ucfirst($item['title arguments'][0]);
      }
    }

    return $items;
  }
  /**
   * Returns the operation count for calculating colspans.
   */
  protected function operationCount() {
    return 4;
  }

  /**
   * {@inheritdoc}
   */
  protected function overviewTableRow($conditions, $id, $entity, $additional_cols = array()) {
    $entity_uri = entity_uri($this->entityType, $entity);

    $row[] = array(
      'data' => array(
        '#theme' => 'entity_ui_overview_item',
        '#label' => check_plain(entity_label($this->entityType, $entity)),
        '#name' => !empty($this->entityInfo['exportable']) ? entity_id($this->entityType, $entity) : FALSE,
        '#url' => $entity_uri ? $entity_uri : FALSE,
        '#entity_type' => $this->entityType,
      ),
    );

    // Add a row for the exportable status.
    $row[] = array(
      'data' => array(
        '#theme' => 'entity_status',
        '#status' => $entity->{$this->statusKey},
      ),
    );

    // Add operations depending on the status.
    if (entity_has_status($this->entityType, $entity, ENTITY_FIXED)) {
      $row[] = array(
        'data' => l(t('clone'), $this->path . '/manage/' . $id . '/clone'),
        'colspan' => $this->operationCount(),
      );
    }
    else {
      $row[] = l(t('edit'), $this->path . '/manage/' . $id);
      $row[] = l(t('clone'), $this->path . '/manage/' . $id . '/clone');

      if (empty($this->entityInfo['exportable']) || !entity_has_status($this->entityType, $entity, ENTITY_IN_CODE)) {
        $row[] = l(t('delete'), $this->path . '/manage/' . $id . '/delete', array('query' => drupal_get_destination()));
      }
      elseif (entity_has_status($this->entityType, $entity, ENTITY_OVERRIDDEN)) {
        $row[] = l(t('revert'), $this->path . '/manage/' . $id . '/revert', array('query' => drupal_get_destination()));
      }
      else {
        $row[] = '';
      }
    }
    $row[] = l(t('export'), $this->path . '/manage/' . $id . '/export');

    return $row;
  }

  /**
   * {@inheritdoc}
   */
  public function hook_forms() {
    $forms = parent::hook_forms();

    // Rewrite form ids to include the module name as a prefix.
    $forms[$this->entityType . '_form']['callback'] = 'entity_legal_document_form';

    return $forms;
  }
}

/**
 * Legal Document Version entity ui controller.
 */
class EntityLegalDocumentVersionUIController extends EntityDefaultUIController {
  /**
   * {@inheritdoc}
   */
  public function hook_menu() {
    $items = parent::hook_menu();

    // Remove title callbacks that cause bundle notices.
    foreach ($items as &$item) {
      if (isset($item['title callback']) && $item['title callback'] == 'entity_ui_get_action_title') {
        unset($item['title callback']);
        $item['title'] = ucfirst($item['title arguments'][0]);
      }
    }

    // Remove the overview path.
    unset($items[$this->path]);
    unset($items[$this->path . '/list']);

    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%entity_object';
    $this->id_count = count(explode('/', $this->path));

    $bundle_argument = 4;

    // Add bundle to add form.
    $items[$this->path . '/add']['title'] = 'Add new version';
    $items[$this->path . '/add']['page callback'] = 'entity_legal_document_version_ui_get_form';
    $items[$this->path . '/add']['page arguments'] = array(
      NULL,
      $bundle_argument,
      'add',
    );

    // Add bundle to edit form.
    $items[$this->path . '/manage/' . $wildcard]['page callback'] = 'entity_legal_document_version_ui_get_form';
    $items[$this->path . '/manage/' . $wildcard]['page arguments'] = array(
      $this->id_count + 1,
      $bundle_argument,
      'edit',
    );

    // Add bundle to edit form.
    $items[$this->path . '/manage/' . $wildcard . '/edit']['page callback'] = 'entity_legal_document_version_ui_get_form';
    $items[$this->path . '/manage/' . $wildcard . '/edit']['page arguments'] = array(
      $this->id_count + 1,
      $bundle_argument,
      'edit',
    );

    return $items;
  }

  /**
   * {@inheritdoc}
   */
  public function hook_forms() {
    $forms = parent::hook_forms();

    // Rewrite form ids to include the module name as a prefix.
    if (!(count($this->entityInfo['bundles']) == 1 && isset($this->entityInfo['bundles'][$this->entityType]))) {
      foreach ($this->entityInfo['bundles'] as $bundle => $bundle_info) {
        $forms[$this->entityType . '_edit_' . $bundle . '_form']['callback'] = 'entity_legal_document_version_form';
      }
    }
    return $forms;
  }
}
