<?php

/**
 * @file
 * Administrative settings and configurations.
 */

/**
 * Settings for the API including the server address and API key.
 */
function opencalais_admin_api_settings($form, &$form_state) {
  $form = array();
  $form['opencalais_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('OpenCalais API Key'),
    '#default_value' => variable_get('opencalais_api_key', NULL),
    '#size' => 60,
    '#description' => 'Required to utilize the Calais service. ' . l(t('Click here to get one.'), 'https://iameui-eagan-prod.thomsonreuters.com/iamui/UI/createUser?app_id=Bold&realm=Bold'),
  );
  $form['opencalais_api_server'] = array(
    '#type' => 'textfield',
    '#title' => t('OpenCalais Server'),
    '#default_value' => variable_get('opencalais_api_server', 'api.thomsonreuters.com'),
    '#size' => 60,
    '#description' => t('The domain name for the server to use.  Typically you will not have to change this unless you want to test beta functionality.'),
  );
  $form['help_text'] = array(
    '#markup' => '<div class="messages status">' . t('To configure tagging visit an individual content type\'s edit area and click the OpenCalais Fields tab.') .
      '<br /><br />' . l(t('Content Types Edit Screen'), 'admin/structure/types') .
      '</div>'
  );
  $form = system_settings_form($form);
  return $form;
}

/**
 * Form callback for configuration options.
 */
function opencalais_admin_general_settings($form, &$form_state) {
  $form['opencalais_tags_in_verticaltab']  = array(
    '#type' => 'checkbox',
    '#title' => t('Collect Tags into Vertical Tab'),
    '#description' => t('This will move all of the OpenCalais related Tag fields on the edit form into a Vertical Tab toward the bottom of the form entitled "Show OpenCalais Tags"'),
    '#default_value' => variable_get('opencalais_tags_in_verticaltab', 1),
  );
  $form['opencalais_bulk'] = array(
    '#type' => 'fieldset',
    '#title' => 'Bulk Processing Options',
  );
  $form['opencalais_bulk']['opencalais_bulk_processing_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Bulk Processing on Cron'),
    '#description' => t('Enable bulk processing of nodes for content types with auto tagging enabled.  This processing will happen in batches during cron runs until complete.'),
    '#default_value' => variable_get('opencalais_bulk_processing_enabled', FALSE)
  );
  $form['opencalais_bulk']['opencalais_bulk_processing_count'] = array(
    '#type' => 'textfield',
    '#maxlength' => 4,
    '#size' => 4,
    '#title' => t('Number of nodes to bulk process on every cron run.'),
    '#default_value' => variable_get('opencalais_bulk_processing_count', 25),
    '#states' => array(
      'visible' => array(
        ':input[name="opencalais_bulk_processing_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['help_text'] = array(
    '#markup' => '<div class="messages status">' . t('To configure tagging visit an individual content type\'s edit area and click the OpenCalais Fields tab.') .
      '<br /><br />' . l(t('Content Types Edit Screen'), 'admin/structure/types') .
      '</div>'
  );

  return system_settings_form($form);
}

/**
 * A form to add the fields necessary for OpenCalais to a content type.
 *
 * @param string $content_type
 *   The node (or content type) we are working with.
 */
function opencalais_add_fields_form($form, &$form_state, $content_type) {
  // Handle any errors on the form
  if (!empty($_POST) && form_get_errors()) {
    drupal_set_message(t('The fields have not been created.'), 'error');
  }

  // Convert the content type from our URL structure to the machine name so Drupal can
  // handle it.
  $content_type = str_ireplace('-', '_', $content_type);
  if (!isset($content_type)) {
    drupal_set_message(t('An error has occured, no content type was specified'), 'error');
    return array();
  }

  $form = array();

  $opencalais_entities = opencalais_get_all_entities();
  _opencalais_make_keys($opencalais_entities);

  $existing = opencalais_get_fields_for_content_type($content_type);

  $form['content_type'] = array(
    '#type' => 'hidden',
    '#value' => $content_type,
  );

  $auto = variable_get('opencalais_autotagging', array());
  $auto = (isset($auto[$content_type]) ? $auto[$content_type] : 0);

  // Settings for auto tagging.
  $form[$content_type . '_autotagging'] = array(
    '#type' => 'select',
    '#title' => t('Tagging method'),
    '#description' => t('How should OpenCalais manage the tagging?'),
    '#default_value' => $auto,
    '#options' => array( 0 => t('Manual Tagging'), 1 => t('Automatic Tagging'), 2 => t('Automatic & Manual Tagging'))
  );

  // Settings for mapping node fields
  $nf = variable_get('opencalais_nodefields', array());
  $nf = (!empty($nf[$content_type])) ? $nf[$content_type] : FALSE;
  
  $form[$content_type . '_nodefields'] = array(
    '#type' => 'checkbox',
    '#title' => t('Index all node text fields'),
    '#description' => t('Index all textfields/textarea on the content type including the title.'),
    '#default_value' => $nf,
  );  

  $form['info']['config'] = array('#tree' => TRUE);
  $form['info']['config']['entities'] = array('#tree' => TRUE);

  $entities = $opencalais_entities;
  sort($entities);

  $entity_defaults = isset($item->config['entities']) ? $item->config['entities'] : array('enabled' => FALSE, 'threshold' => 0.0);

  foreach ($entities as $entity) {
    $machine_name = _opencalais_make_machine_name($entity);
    $defaults = isset($entity_defaults[$entity]) ? $entity_defaults[$entity] : $entity_defaults;
    // Load in defaults for existing fields.
    $defaults['enabled'] = isset($existing[$machine_name]) ? TRUE : FALSE;
    $defaults['threshold'] = isset($existing[$machine_name]) ? $existing[$machine_name]['threshold'] : $defaults['threshold'];

    $form['info']['config']['entities'][$entity]['existing'] = array(
      '#type' => 'hidden',
      '#value' => isset($existing[$machine_name]) ? TRUE : FALSE
    );

    $form['info']['config']['entities'][$entity]['enabled'] = array(
      '#type' => 'checkbox',
      '#title' => t('Create'),
      '#title_display' => 'invisible',
      '#default_value' => $defaults['enabled'],
      '#description' => t('Should this content type be tagged with this category'),
    );
    $form['info']['config']['entities'][$entity]['threshold'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Minimum suggested tag relevancy'),
      '#title_display' => 'invisible',
      '#default_value' => $defaults['threshold'],
      '#description' => t('Determine how relevant a term must be in order for Calais to suggest it for a particular node.  Based on a 0.00-1.00 scale, with 0.00 being least relevant (i.e. many terms appear).'),
      '#attributes' => array('class' => array('threshold_slider')),
    );
  }

  $form['info']['#theme'] = 'opencalais_add_fields_entities';
  // Create the buttons and submit handlers and such.
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
   '#type' => 'submit',
   '#value' => t('Save Fields'),
  );

  // This is to create a help block to explain some things about the form

  $help_text  = 'This form will allow you to create taxonomy term references on your content type that correspond to ';
  $help_text .= 'OpenCalais categories (<em>taxonomy vocabularies</em>).';

  $usage_text  = 'Simply select the categories that apply to your content by checking their checkbox and then use the slider to set ';
  $usage_text .= 'the relevancy threshold which a term must meet to be applied.';

  $notes_text = 'Note: When saving with already existing fields, a message will appear that the field(s) have been successfully updated.  Each field is always resaved so this is normal.';

  $form['help'] = array(
    '#type' => 'item',
    '#title' => t('OpenCalais Fields Help'),
    '#description' => t('Help with this form'),
    '#markup' => '<br/><p>' . t($help_text) . '</p><br/><p>' . t($usage_text) . '</p><br/><p><em>' . t($notes_text) . '</em></p>',
    '#prefix' => '<div class="">',
    '#suffix' => '</div>'
  );

  $form['#submit'][] = 'opencalais_add_fields_submit';

  $form['#theme'] = 'system_settings_form';

  return $form;
}
