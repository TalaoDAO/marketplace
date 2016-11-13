<?php
/**
 * @file
 * ft_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ft_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ft_blog_image_default_styles() {
  $styles = array();

  // Exported image style: publication_full.
  $styles['publication_full'] = array(
    'label' => 'Publication full',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 790,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: publication_small.
  $styles['publication_small'] = array(
    'label' => 'Publication small',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 190,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
