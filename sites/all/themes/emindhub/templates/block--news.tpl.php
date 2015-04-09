
<?php if ($block->subject): ?>
    <div class="row paddingUD">
        <div class="col-md-5 col-xs-12 light-blue-text bold news">
            <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
        </div>
        <div class="col-md-4 col-xs-6"><hr class="hr-light"></div>
        <div class="col-md-3 col-xs-4">
            <img src="<?php print getImgSrc('menuIcon.png'); ?>">
            <img src="<?php print getImgSrc('fluxIcon.png'); ?>">
        </div>
    </div>
<?php endif;?>
<?php if ($content): ?>
    <?php print $content; ?>
<?php endif;?>