<?php
//$form['#action'] = /business/register
//$form['#action'] = /expert/register
/**
 * @file
 * Default theme implementation for profiles.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) profile type label.
 * - $url: The URL to view the current profile.
 * - $page: TRUE if this is the main view page $url points too.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-profile
 *   - profile-{TYPE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>

<h1>Testing that this is my own user registration form</h1>
<?php /*print render($form['form_id']); ?>
<?php print render($form['form_build_id']);*/ ?>
<?php
print render ($form['field_firstname']);
print render ($form['field_lastname']);

/*
 * print render ($form['field_dob']);
 * print render ($form['name']);
 * print render ($form['mail']);
 * print render ($form['pass']);
 * print render ($form['timezone']);
 * print render ($form['form_token']);
 */
print drupal_render($form['actions']); ?>