<?php
/**
 * @file
 * Configuration form for Form tips module.
 */

/**
 * Admin settings form.
 */
function formtips_setting_form($form) {
  $form['formtips_trigger_action'] = array(
    '#type' => 'select',
    '#title' => t('Trigger action'),
    '#description' => t('Select the action that will trigger the display of tooltips.'),
    '#options' => array(
      'hover' => t('Hover'),
      'click' => t('Click'),
    ),
    '#default_value' => variable_get('formtips_trigger_action', 'hover'),
  );
  $form['formtips_selectors'] = array(
    '#type' => 'textarea',
    '#title' => t('Selectors'),
    '#description' => t("Enter some CSS/XPATH selectors (jQuery compatible) for which you don't want to tigger formtips (one per line)."),
    '#default_value' => variable_get('formtips_selectors', FORMTIPS_SELECTORS),
  );
  $form['formtips_max_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Max-width'),
    '#description' => t('Enter a value for the maximum width of the form description tooltip.'),
    '#default_value' => variable_get('formtips_max_width', FORMTIPS_MAX_WIDTH),
  );

  $form['intent'] = array(
    '#type' => 'fieldset',
    '#title' => t('Hover intent settings'),
    '#description' => t('Settings for controlling the hover intent plugin.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['intent']['formtips_hoverintent'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add hoverIntent plugin'),
    '#description' => t('If the hoverIntent plugin is added by another module or in the theme you can switch this setting off.'),
    '#default_value' => variable_get('formtips_hoverintent', 1),
  );
  $form['intent']['formtips_interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Interval'),
    '#description' => t('The number of milliseconds hoverIntent waits between reading/comparing mouse coordinates. When the user\'s mouse first enters the element its coordinates are recorded. The soonest the "over" function can be called is after a single polling interval. Setting the polling interval higher will increase the delay before the first possible "over" call, but also increases the time to the next point of comparison. Default interval: 100'),
    '#default_value' => variable_get('formtips_interval', FORMTIPS_INTERVAL),
  );
  $form['intent']['formtips_sensitivity'] = array(
    '#type' => 'textfield',
    '#title' => t('Sensitivity'),
    '#description' => t('If the mouse travels fewer than this number of pixels between polling intervals, then the "over" function will be called. With the minimum sensitivity threshold of 1, the mouse must not move between polling intervals. With higher sensitivity thresholds you are more likely to receive a false positive. Default sensitivity: 7'),
    '#default_value' => variable_get('formtips_sensitivity', FORMTIPS_SENSITIVITY),
  );
  $form['intent']['formtips_timeout'] = array(
    '#type' => 'textfield',
    '#title' => t('Timeout'),
    '#description' => t('A simple delay, in milliseconds, before the "out" function is called. If the user mouses back over the element before the timeout has expired the "out" function will not be called (nor will the "over" function be called). This is primarily to protect against sloppy/human mousing trajectories that temporarily (and unintentionally) take the user off of the target element... giving them time to return. Default timeout: 0'),
    '#default_value' => variable_get('formtips_timeout', FORMTIPS_TIMEOUT),
  );

  return system_settings_form($form);
}
