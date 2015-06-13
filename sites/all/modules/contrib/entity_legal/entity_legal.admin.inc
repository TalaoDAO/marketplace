<?php
/**
 * @file
 * Administration hooks and helpers for entity_legal module.
 */

/**
 * Generates the profile type editing form.
 */
function entity_legal_document_form($form, &$form_state, EntityLegalDocument $entity, $op = 'edit', $entity_type = NULL) {
  $form['label'] = array(
    '#title' => t('Administrative label'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->label) ? $entity->label : '',
    '#required' => TRUE,
  );

  $form['name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine-readable name'),
    '#required' => TRUE,
    '#default_value' => isset($entity->name) ? $entity->name : '',
    '#machine_name' => array(
      'exists' => 'entity_legal_document_name_exists',
      'source' => array('label'),
    ),
    '#access' => $op == 'add' || $op == 'clone',
    '#maxlength' => 32,
  );

  if (!in_array($op, array('add', 'clone'))) {
    $versions = $entity->getAllVersions();
    if ($op == 'edit' && empty($versions)) {
      drupal_set_message(t('No versions for this document have been found. !add_link to use this document.', array(
        '!add_link' => l(t('Add a version'), $_GET['q'] . '/add'),
      )), 'warning');
    }

    $header = array(
      'title' => t('Title'),
      'created' => t('Created'),
      'updated' => t('Updated'),
      'operations' => t('Operations'),
    );
    $options = array();

    foreach ($versions as $document_version_entity) {
      // Use the default uri if this version is the current published version.
      if ($entity->getPublishedVersion() && $entity->getPublishedVersion()
          ->identifier() == $document_version_entity->identifier()
      ) {
        $entity_uri = $entity->uri();
        $path = $entity_uri['path'];
      }
      else {
        $path = 'legal/document/' . $entity->identifier() . '/' . $document_version_entity->identifier();
      }

      $options[$document_version_entity->identifier()] = array(
        'title' => l($document_version_entity->label(TRUE), $path),
        'created' => $document_version_entity->getFormattedDate('created'),
        'updated' => $document_version_entity->getFormattedDate('updated'),
        'operations' => l(t('Edit'), 'admin/structure/legal/manage/' . $entity->identifier() . '/manage/' . $document_version_entity->identifier()),
      );
    }

    // By default just show a simple overview for all entities.
    $form['versions'] = array(
      '#type' => 'fieldset',
      '#title' => t('Current version'),
      '#description' => t('The current version users must agree to. If requiring existing users to accept, those users will be prompted if they have not accepted this particular version in the past.'),
      '#tree' => FALSE,
    );
    $form['versions']['published_version'] = array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $options,
      '#empty' => t('Create a document version to set up a default'),
      '#multiple' => FALSE,
      '#default_value' => isset($entity->published_version) ? $entity->published_version : '',
    );
  }

  $form['settings'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 27,
    '#tree' => TRUE,
  );

  $form['settings']['new_users'] = array(
    '#title' => t('New users'),
    '#description' => t('Visit the !permissions page to ensure that users can view the document.', array(
      '!permissions' => l(t('permissions'), 'admin/people/permissions'),
    )),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form['settings']['new_users']['require'] = array(
    '#title' => t('Require new users to accept this agreement on signup'),
    '#type' => 'checkbox',
    '#default_value' => isset($entity->require_signup) ? $entity->require_signup : 0,
  );

  $form['settings']['new_users']['require_method'] = array(
    '#title' => t('Present to user as'),
    '#type' => 'select',
    '#options' => _entity_legal_document_methods('new_users'),
    '#default_value' => $entity->getAcceptanceDeliveryMethod(TRUE),
    '#states' => array(
      'visible' => array(
        ':input[name="settings[new_users][require]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['settings']['existing_users'] = array(
    '#title' => t('Existing users'),
    '#description' => t('Visit the !permissions page to configure which existing users these settings apply to.', array(
      '!permissions' => l(t('permissions'), 'admin/people/permissions'),
    )),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form['settings']['existing_users']['require'] = array(
    '#title' => t('Require existing users to accept this agreement'),
    '#type' => 'checkbox',
    '#default_value' => isset($entity->require_existing) ? $entity->require_existing : 0,
  );
  $form['settings']['existing_users']['require_method'] = array(
    '#title' => t('Present to user as'),
    '#type' => 'select',
    '#options' => _entity_legal_document_methods('existing_users'),
    '#default_value' => $entity->getAcceptanceDeliveryMethod(),
    '#states' => array(
      'visible' => array(
        ':input[name="settings[existing_users][require]"]' => array('checked' => TRUE),
      ),
    ),
  );

  _entity_legal_document_form_add_path_settings($form, $form_state, $entity, $op);

  $form['actions'] = array(
    '#type' => 'actions',
    '#weight' => 28,
  );

  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => $op == 'add' ? t('Next') : t('Save'),
    '#weight' => 1,
  );

  // Remove unnecessary Entity API validation and submit handlers.
  $form['#validate'] = array();
  $form['#submit'] = array('entity_legal_document_form_submit');

  return $form;
}

/**
 * Add path and pathauto settings to an existing legal document form.
 */
function _entity_legal_document_form_add_path_settings(&$form, &$form_state, EntityLegalDocument $entity, $op) {
  if (!module_exists('path')) {
    return;
  }

  $path = array();

  if (!in_array($op, array('add', 'clone'))) {
    $default_uri = $entity->uri();
    $conditions = array('source' => $default_uri['path']);
    $path = path_load($conditions);
    if ($path === FALSE) {
      $path = array();
    }
  }

  $path += array(
    'pid' => NULL,
    'source' => isset($form['#node']->nid) ? 'node/' . $form['#node']->nid : NULL,
    'alias' => '',
  );

  $form['path'] = array(
    '#type' => 'fieldset',
    '#title' => t('URL path settings'),
    '#collapsible' => TRUE,
    '#collapsed' => empty($path['alias']),
    '#group' => 'settings',
    '#attributes' => array(
      'class' => array('path-form'),
    ),
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'path') . '/path.js'),
    ),
    '#access' => user_access('create url aliases') || user_access('administer url aliases'),
    '#weight' => 5,
    '#tree' => TRUE,
    '#element_validate' => array('path_form_element_validate'),
  );
  $form['path']['alias'] = array(
    '#type' => 'textfield',
    '#title' => t('URL alias'),
    '#default_value' => $path['alias'],
    '#maxlength' => 255,
    '#description' => t('Optionally specify an alternative URL by which this content can be accessed. For example, type "about" when writing an about page. Use a relative path and don\'t add a trailing slash or the URL alias won\'t work.'),
  );
  $form['path']['pid'] = array('#type' => 'value', '#value' => $path['pid']);
  $form['path']['source'] = array(
    '#type' => 'value',
    '#value' => $path['source']
  );
}

/**
 * Form submit handler for saving a legal document revision.
 */
function entity_legal_document_form_submit(&$form, &$form_state) {
  $form_state['values']['require_signup'] = $form_state['values']['settings']['new_users']['require'];
  $form_state['values']['require_existing'] = $form_state['values']['settings']['existing_users']['require'];
  $document_entity = entity_ui_form_submit_build_entity($form, $form_state);

  // If it's a new document, redirect to the versions page.
  if (!empty($document_entity->is_new)) {
    $form_state['redirect'] = 'admin/structure/legal/manage/' . $document_entity->identifier() . '/add';
  }

  $document_entity->save();

  if (!empty($form_state['values']['path']) && !empty($form_state['values']['path']['alias'])) {
    $path = $form_state['values']['path'];
    $path['alias'] = trim($path['alias']);

    // Delete old alias if user erased it.
    if (!empty($path['pid']) && empty($path['alias'])) {
      path_delete($path['pid']);
    }

    $default_uri = $document_entity->uri();
    $path['source'] = $default_uri['path'];
    path_save($path);
  }
}

/**
 * Generates the profile type editing form.
 */
function entity_legal_document_version_form($form, &$form_state, EntityLegalDocumentVersion $entity, $op = 'edit', $entity_type = NULL) {
  $form['label'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->label) ? $entity->label : '',
    '#required' => TRUE,
  );

  $form['name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine-readable name'),
    '#required' => TRUE,
    '#default_value' => isset($entity->name) ? $entity->name : $entity->document_name . '_' . time(),
    '#machine_name' => array(
      'exists' => 'entity_legal_document_version_name_exists',
    ),
    '#access' => $op == 'add' || $op == 'clone',
    '#maxlength' => 64,
  );

  field_attach_form(ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME, $entity, $form, $form_state);

  $form['acceptance_label'] = array(
    '#title' => t('Acceptance label'),
    '#type' => 'textfield',
    '#description' => t('e.g. I agree to the terms and conditions, use tokens to provide a link to the document.'),
    '#weight' => 50,
  );

  if (isset($entity->acceptance_label)) {
    $form['acceptance_label']['#default_value'] = $entity->acceptance_label;
  }
  else {
    $form['acceptance_label']['#default_value'] = t('I agree to the <a href="!token_url">@document_label</a> document', array(
      '!token_url' => '[entity_legal_document:url]',
      '@document_label' => $entity->getDocument()->label(TRUE),
    ));
  }

  $form['token_help'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('entity_legal_document'),
    '#weight' => 51
  );

  $form['actions'] = array(
    '#type' => 'actions',
    '#weight' => 52,
  );

  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 1,
  );

  // Remove unnecessary Entity API validation and submit handlers.
  $form['#validate'] = array();
  $form['#submit'] = array('entity_legal_document_version_form_submit');

  return $form;
}

/**
 * Form submit handler for saving a legal document revision.
 */
function entity_legal_document_version_form_submit(&$form, &$form_state) {
  $version_entity = entity_ui_form_submit_build_entity($form, $form_state);
  $version_entity->updated = time();
  $version_entity->save();

  $entity_legal_document = entity_load_single(ENTITY_LEGAL_DOCUMENT_ENTITY_NAME, $version_entity->document_name);
  if (!$entity_legal_document->getPublishedVersion()) {
    $entity_legal_document->setPublishedVersion($version_entity);
    $entity_legal_document->save();
  }

  $form_state['redirect'] = 'admin/structure/legal/manage/' . $version_entity->document_name;
}

/**
 * Check to see whether an entity legal document with the given name exists.
 *
 * @param string $document_name
 *   The machine name to check.
 *
 * @return bool
 *   Whether or not the machine name exists.
 */
function entity_legal_document_name_exists($document_name) {
  $existing_entity = entity_load_single(ENTITY_LEGAL_DOCUMENT_ENTITY_NAME, $document_name);

  return !empty($existing_entity);
}

/**
 * Check to see whether an legal document version with the given name exists.
 *
 * @param string $document_version_name
 *   The machine name to check.
 *
 * @return bool
 *   Whether or not the machine name exists.
 */
function entity_legal_document_version_name_exists($document_version_name) {
  $existing_entity = entity_load_single(ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME, $document_version_name);

  return !empty($existing_entity);
}


/**
 * Overrides entity_ui_get_form() to include bundles.
 */
function entity_legal_document_version_ui_get_form($entity, $bundle, $op = 'edit', $form_state = array()) {
  if ($op == 'add') {
    $entity = entity_create(ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME, array(
      'document_name' => $bundle,
    ));
  }

  return entity_ui_get_form(ENTITY_LEGAL_DOCUMENT_VERSION_ENTITY_NAME, $entity, $op, $form_state);
}
