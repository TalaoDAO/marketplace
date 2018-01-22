<?php

function emindhub_preprocess_html(&$variables) {

  drupal_add_js(drupal_get_path('theme', 'emindhub'). '/js/token-hack.js', ['group' => JS_THEME]);

  drupal_add_css('https://fonts.googleapis.com/css?family=Lato:300,300i,400,400i,700,700i' , array('type' => 'external'));

  drupal_add_css('https://fonts.googleapis.com/css?family=Open+Sans:300,400,700' , array('type' => 'external'));
  drupal_add_css('https://fonts.googleapis.com/css?family=Open+Sans:300i,400i,600,600i,700i' , array('type' => 'external'));

  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/slick-carousel/1.6.0/slick.min.js', 'external');
  drupal_add_css('https://cdnjs.cloudflare.com/ajax/libs/slick-carousel/1.6.0/slick.min.css', 'external');

  global $user;
  foreach ( $user->roles as $role_id => $role ) {
    // $variables['classes_array'][] = 'role-id-' . $role_id;
    $variables['classes_array'][] = 'role-' . strtolower(drupal_clean_css_identifier($role));
  }
	// $variables['classes_array'][] = 'user-uid-' . $user->uid;

  global $language;
	if (!empty($language)) {
    $variables['classes_array'][] = 'lang-' . $language->language;
  }

	// 403 + 404
	$headers = drupal_get_http_header();
	if (isset($headers['status']) && $headers['status'] == '403 Forbidden') {
    $variables['classes_array'][] = 'page-403';
  }
  if (isset($headers['status']) && $headers['status'] == '404 Not Found') {
    $variables['classes_array'][] = 'page-404';
  }
}
