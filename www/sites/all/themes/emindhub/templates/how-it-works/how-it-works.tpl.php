<?php global $base_url; ?>

<?php if (isset($block_html_id)) : ?>
<section id="<?php print $block_html_id; ?>" class="emh-module container how-it-works hiw <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php else : ?>
<section class="emh-module how-it-works hiw">
<?php endif; ?>

  <?php if (isset($block_html_id)) : ?>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="emh-title">
      <?php print t('How it works?'); ?>
    </div>
  <?php endif;?>
  <?php print render($title_suffix); ?>
  <div class="emh-subtitle">
    <?php print t('Simple, free, and in 3 easy steps…'); ?>
  </div>
  <?php endif; ?>

  <ul class="hiw-tabs">
    <li><button type="button" name="button" data-tab="hiw-customer" class="hiw-tab emh-button customer"><?php print t('You need expertise'); ?></button></li>
    <li><button type="button" name="button" data-tab="hiw-expert" class="hiw-tab emh-button expert"><?php print t('You have expertise'); ?></button></li>
  </ul>

  <?php include_once(drupal_get_path('theme','emindhub').'/templates/how-it-works/how-it-works_client.tpl.php'); ?>

  <?php include_once(drupal_get_path('theme','emindhub').'/templates/how-it-works/how-it-works_expert.tpl.php'); ?>

</section>
