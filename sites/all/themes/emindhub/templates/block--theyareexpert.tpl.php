<?php if ($block->subject): ?>
    <div class="row paddingUD">
        <div class="col-md-8 light-blue-text bold">
            <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
        </div>
        <div class="col-md-3"><hr class="hr-light"></div>
        <div class="col-md-1 noPaddingL">
            <img src="<?php print getImgSrc('fluxIcon.png'); ?>">
        </div>
    </div>
<?php endif;
if ($content):
    print $content;
endif; ?>