<?php

/**
 * @file
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the comment was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->created variable.
 * - $changed: Formatted date and time for when the comment was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->changed variable.
 * - $new: New comment marker.
 * - $permalink: Comment permalink.
 * - $submitted: Submission information created from $author and $created during
 *   template_preprocess_comment().
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - comment: The current template type, i.e., "theming hook".
 *   - comment-by-anonymous: Comment by an unregistered user.
 *   - comment-by-node-author: Comment by the author of the parent node.
 *   - comment-preview: When previewing a new or edited comment.
 *   The following applies only to viewers who are registered users:
 *   - comment-unpublished: An unpublished comment visible only to administrators.
 *   - comment-by-viewer: Comment by the user currently viewing the page.
 *   - comment-new: New comment since last the visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * These two variables are provided for context:
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_comment()
 * @see template_process()
 * @see theme_comment()
 *
 * @ingroup themeable
 */

// echo '<pre>' . print_r($comment, TRUE) . '</pre>';
// echo '<pre>' . print_r($content->field_private_comment_body, TRUE) . '</pre>';

global $base_url;

$comment_author = user_load($comment->uid);
$first_name = field_get_items('user', $comment_author, 'field_first_name');
$last_name = field_get_items('user', $comment_author, 'field_last_name');
$profile_url = $base_url . '/' . drupal_get_path_alias('user/' . $comment->uid);
$flag = flag_get_flag('my_contacts');
?>
<div class="<?php print $classes; ?> clearfix row"<?php print $attributes; ?>>

  <?php if ( (module_exists('emh_access') && emh_access_user_can_see_full_answer($user->uid, $comment->uid, $node->uid)) || !empty($content['comment_body']) ) : ?>

  <div class="col-sm-2 meta">

    <p class="author">
      <?php if ( module_exists('emh_access') && (emh_access_user_can_see_full_user( $user->uid, $comment->uid ) || ($flag && $flag->is_flagged($comment->uid, $GLOBALS['user']->uid))) ) : ?>
      <a href="<?php print $profile_url; ?>">
      <?php endif; ?>

      <?php //print $author; ?>
      <?php //print $picture; ?>
      <span class="author-firstname"><?php print render($first_name[0]['value']); ?></span>&nbsp;<span class="author-lastname"><?php print render($last_name[0]['value']); ?></span>

      <?php if ( module_exists('emh_access') && (emh_access_user_can_see_full_user( $user->uid, $comment->uid ) || ($flag && $flag->is_flagged($comment->uid, $GLOBALS['user']->uid))) ) : ?>
      </a>
      <?php endif; ?>
    </p>

    <span class="submitted"><?php print $created; ?></span>

  </div>

  <div class="col-sm-10 answer <?php print $content_attributes; ?>">

    <?php hide($content['links']); ?>
    <?php print render($content); ?>
    <?php print render($content['links']) ?>

  </div>

  <?php else : ?>

  <span class="submitted"><?php print t('This answer is private.'); ?></span>

  <?php endif; ?>

</div>
