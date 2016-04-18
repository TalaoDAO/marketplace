<?php

/**
 * @file
 * Default views template for displaying a slideshow.
 *
 * - $view: The View object.
 * - $options: Settings for the active style.
 * - $rows: The rows output from the View.
 * - $title: The title of this group of rows. May be empty.
 *
 * @ingroup views_templates
 */
?>

<?php if (!empty($slideshow)): ?>
  <!-- <div class="skin-<?php print $skin; ?> row"> -->
  <div class="skin-<?php print $skin; ?> carousel slide" data-ride="carousel">
    <?php if (!empty($top_widget_rendered)): ?>
      <?php print $top_widget_rendered; ?>
    <?php endif; ?>

    <!-- <div class="col-sm-8 col-sm-push-2"> -->
    <!-- Wrapper for slides -->
    <div class="carousel-inner" role="listbox">
      <?php print $slideshow; ?>
    </div>
    <!-- </div> -->

    <?php if (!empty($bottom_widget_rendered)): ?>
      <?php print $bottom_widget_rendered; ?>
    <?php endif; ?>
  </div>
<?php endif; ?>
