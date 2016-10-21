<?php

/**
 * @file
 * Definition of addressfield_phone_handler_field_address_phone_nr.
 */

/**
 * Provides diferent phone number display options for addres entity(field).
 * @ingroup views_field_handlers
 */
class addressfield_phone_handler_field_address_phone_nr extends views_handler_field {

  /**
   * Option to address phone field.
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['selected_phone_type'] = array('default' => 3);

    return $options;
  }

  /**
   * Link to Addressfiels phone fileld option form.
   */
  public function options_form(&$form, &$form_state) {
    $form['selected_phone_type'] = array(
        '#type' => 'select',
        '#title' => t('Phone nr type'),
        '#options' => array(
            1 => t('phone_number'),
            2 => t('phone_number_extension'),
            3 => t('mobile_number'),
            4 => t('fax_number'),
        ),
        '#default_value' => $this->options['selected_phone_type'],
        '#description' => t('Address field contain phone numbers. Have to select one from them.'),
    );

    parent::options_form($form, $form_state);
  }

  /**
   * Render the addresfields phone field.
   */
  public function render($values) {
    $phoneNrs = unserialize($this->get_value($values))
      + array(
        'phone_number' => '',
        'phone_number_extension' => '',
        'mobile_number' => '',
        'fax_number' => '',
      );
    switch ($this->options['selected_phone_type']) {
      case 1:
        return $phoneNrs['phone_number'];
        break;
      case 2:
        return $phoneNrs['phone_number_extension'];
        break;
      case 3:
        return $phoneNrs['mobile_number'];
        break;
      case 4:
        return $phoneNrs['fax_number'];
        break;
    }
  }

}
