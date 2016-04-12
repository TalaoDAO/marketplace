<!--<div class="they-are-expert-block">-->
<!--    <div id="views_slideshow_controls_text_users_list-block_2" class="views-slideshow-controls-text views_slideshow_controls_text">-->
<!--        <span id="views_slideshow_controls_text_previous_users_list-block_2" class="views-slideshow-controls-text-previous views_slideshow_controls_text_previous"><a href="#"></a></span>-->
<!--    </div>-->
<!--    <div class="they-are-expert-container">-->
<!--        --><?php //print $slideshow; ?>
<!--    </div>-->
<!--    <div id="views_slideshow_controls_text_users_list-block_2" class="views-slideshow-controls-text views_slideshow_controls_text">-->
<!--        <span id="views_slideshow_controls_text_next_users_list-block_2" class="views-slideshow-controls-text-next views_slideshow_controls_text_next"><a href="#"></a></span>-->
<!--    </div>-->
<!--</div>-->

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
    <div class="skin-<?php print $skin; ?>">
        <?php if (!empty($top_widget_rendered)): ?>
            <div class="views-slideshow-controls-top clearfix">
                <?php print $top_widget_rendered; ?>
            </div>
        <?php endif; ?>

        <?php print $slideshow; ?>

        <?php if (!empty($bottom_widget_rendered)): ?>
            <div class="views-slideshow-controls-bottom clearfix">
                <?php print $bottom_widget_rendered; ?>
            </div>
        <?php endif; ?>
    </div>
<?php endif; ?>
