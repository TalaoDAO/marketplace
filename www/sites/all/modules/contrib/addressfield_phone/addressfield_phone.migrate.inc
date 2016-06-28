<?php
/**
 * Implements hook_migrate_api().
 */
function addressfield_phone_migrate_api() {
  $api = array(
    'api' => 2,
    'field handlers' => array('MigrateAddressPhoneFieldHandler'),
  );
  return $api;
}

/**
 * A Field Handler class that makes address_phone subfield destination for migate api.
 *
 * Arguments are used to specify all phone related values:
 *   'phone_number',
 *   'phone_number_extension',
 *   'mobile_number',
 *   'fax_number',
 */
class MigrateAddressPhoneFieldHandler extends MigrateAddressFieldHandler {
  public function __construct() {
    parent::__construct();
  }
  /**
   * Provide subfields for the addressfield columns.
   */
  public function fields() {
    // Declare our arguments to also be available as subfields.
    $fields = array(
      'phone_number' => t('Phone Number'),
      'phone_number_extension' => t('extension'),
      'mobile_number' => t('Mobile Number'),
      'fax_number' => t('Fax Number'),
    );
    return $fields;
  }

  /**
   * Implements MigrateFieldHandler::prepare().
   *
   * @param $entity
   * @param array $field_info
   * @param array $instance
    * @param array $values
   *
   * @return null
   */
  public function prepare($entity, array $field_info, array $instance, array $values) {
    $arguments = array();
    if (isset($values['arguments'])) {
      $arguments = array_filter($values['arguments']);
      unset($values['arguments']);
    }
    $language = $this->getFieldLanguage($entity, $field_info, $arguments);

    return isset($return) ? $return : NULL;
  }
}
