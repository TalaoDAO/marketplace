<?php
$node = menu_get_object();
?>
<?php if (emh_request_submission_list_access_callback($node)) : ?>
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
          <span class="submission-private"><?php print t('Answers to your request are only visible by you.'); ?></span>
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
<?php endif; ?>
