<?php

function emh_circles_reset_views() {
  module_load_include('inc', 'emh_circles', 'views/emh_circles.views_default');
  $default_views = emh_circles_views_default_views();
  foreach($default_views as $name => $view) {
    views_revert_view($view);
  }
}
