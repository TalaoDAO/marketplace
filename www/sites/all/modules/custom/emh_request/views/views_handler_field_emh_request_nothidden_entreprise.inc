<?php

class views_handler_field_emh_request_nothidden_entreprise extends views_handler_field {

  /**
   * Add additional fields.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  /**
   * Define our additional configuration setting.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Renders our field, displays the request type.
   */
  function render($values) {
    if (isset($values->{$this->aliases['nid']})) {
      $nid = $values->{$this->aliases['nid']};
    }
    else {
      return 0;
    }
    global $user;
    $uid1 = $user->uid;

    $node = node_load($nid);
    $uid2 = $node->uid;
    $u2_account = user_load($uid2);

    $organisation = t('Anonymous');
    if (
          (!(emh_request_has_option($node, 'anonymous')))
      ||  ((emh_request_has_option($node, 'anonymous') && ($node->field_hide_organisation[LANGUAGE_NONE][0]['value'] == FALSE)))
    ) {
      $oitem = field_get_items('user', $u2_account, 'field_entreprise');
      $organisation = field_view_value('user', $u2_account, 'field_entreprise', $oitem[0]);
    }

    return $organisation;
  }

  /**
   * Only display the column for users with the appropriate permission.
   */
  function access() {
    return TRUE;
  }

  /**
   * Just do some basic checks.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

}
