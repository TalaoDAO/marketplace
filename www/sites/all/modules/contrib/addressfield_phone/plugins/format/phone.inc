<?php

/**
 * @file
 * The default format for adresses.
 */

$plugin = array(
  'title' => t('Phone number and extension'),
  'format callback' => 'addressfield_format_phone_generate',
  'type' => 'phone',
  'weight' => -99,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_phone_generate(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form' && !empty($address['country'])) {
    $format['phone_block'] = array(
      '#type' => 'addressfield_container',
      '#attributes' => array('class' => array('custom-block')),
      '#weight' => 200,
    );
    $format['phone_block']['phone_number'] = array(
      '#type' => 'addressfield_container',
      '#attributes' => array('class' => array('addressfield-container-inline')),
    );

    if (isset($context['instance']['widget']['settings']['phone_number_fields'])) {
      $settings = array_filter($context['instance']['widget']['settings']['phone_number_fields']);
    }
    else {
      $settings = array();
    }

    if (!$settings || isset($settings['phone'])) {
      $format['phone_block']['phone_number']['phone_number'] = array(
        '#title' => t('Contact Phone'),
        '#size' => 15,
        '#attributes' => array('class' => array('phone-number')),
        '#type' => 'textfield',
        '#tag' => 'span',
        '#default_value' => isset($address['phone_number']) ? $address['phone_number'] : '',
      );
    }
    if (!$settings || isset($settings['extension'])) {
      $format['phone_block']['phone_number']['phone_number_extension'] = array(
        '#title' => t('Phone Extension'),
        '#size' => 10,
        '#attributes' => array('class' => array('phone-extension')),
        '#type' => 'textfield',
        '#tag' => 'span',
        '#default_value' => isset($address['phone_number_extension']) ? $address['phone_number_extension'] : '',
      );
    }
    if (!$settings || isset($settings['mobile'])) {
      $format['phone_block']['mobile_number'] = array(
        '#title' => t('Mobile Number'),
        '#size' => 15,
        '#attributes' => array('class' => array('phone-number')),
        '#type' => 'textfield',
        '#tag' => 'div',
        '#default_value' => isset($address['mobile_number']) ? $address['mobile_number'] : '',
      );
    }
    if (!$settings || $settings['fax']) {
      $format['phone_block']['fax_number'] = array(
        '#title' => t('Fax Number'),
        '#size' => 15,
        '#attributes' => array('class' => array('phone-number')),
        '#type' => 'textfield',
        '#tag' => 'div',
        '#default_value' => isset($address['fax_number']) ? $address['fax_number'] : '',
      );
    }
  }
  else {
    // Add our own render callback for the format view
    $format['#pre_render'][] = '_addressfield_phone_render_address';
  }
}

