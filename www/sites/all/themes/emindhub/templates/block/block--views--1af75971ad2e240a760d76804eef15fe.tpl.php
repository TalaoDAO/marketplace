<?php
/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see bootstrap_preprocess_block()
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see bootstrap_process_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
$node = menu_get_object();
?>
<?php //TODO: if (($node->uid == $user->uid) || !emh_request_has_option($node, 'private')) : ?>
<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix section submissions"<?php print $attributes; ?>>
  <span id="request-submissions"></span>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="row submissions-title">
      <div class="col-sm-8">
        <h2<?php print $title_attributes; ?>><span class="submission-title"><?php print $title; ?></span>&nbsp;<span class="submission-count">(<?php print webform_get_submission_count($node->nid); ?>)</span></h2>
      </div>
      <?php if ($node->uid == $user->uid && emh_request_has_option($node, 'private')) : ?>
        <div class="col-sm-4 text-right submissions-private-info">
          <span class="submission-private"><?php print t('Submissions are only visible by you.'); ?></span>
        </div>
      <?php endif; ?>
    </div>
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <?php if ($content): ?>
    <div class="content submissions-list">
      <?php print $content; ?>
    </div>
  <?php endif;?>

</section> <!-- /.block -->
<?php //endif; ?>
