<?php

function emindhub_preprocess_html(&$variables) {
	drupal_add_css('http://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic' , array('type' => 'external'));

  global $user;
  foreach ( $user->roles as $role_id => $role ) {
    // $variables['classes_array'][] = 'role-id-' . $role_id;
    $variables['classes_array'][] = 'role-' . strtolower(drupal_clean_css_identifier($role));
  }
  // $variables['classes_array'][] = 'user-uid-' . $user->uid;
}
