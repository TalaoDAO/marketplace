<?php


function hacked_reports_hacked_diff($project, $file) {

  if (!module_exists('diff')) {
    return t('The diff module is required to use this feature.');
  }

  $project->identify_project();

  // Find a better way to do this:
  $breadcrumb = array(
    l('Home', '<front>'),
    l('Administer', 'admin'),
    l('Reports', 'admin/reports'),
    l('Hacked', 'admin/reports/hacked'),
    l($project->title(), 'admin/reports/hacked/' . $project->name),
  );
  drupal_set_breadcrumb($breadcrumb);

  if ($project->file_is_diffable($file)) {
    return hacked_diff_changed($project, $file);
  }
  return t('Cannot hash binary file or file not found: %file', array('%file' => $file));
}

function hacked_diff_changed($project, $file) {
  $original_file = $project->file_get_location('remote', $file);
  $installed_file = $project->file_get_location('local', $file);

  $output = theme('table', array(
                  'header' => array(t('Orignal'), '', t('Current'), ''),
                  'rows' => diff_get_rows(file_get_contents($original_file), file_get_contents($installed_file), TRUE)));
  return $output;
}
