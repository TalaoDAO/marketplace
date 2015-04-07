<?php if ($block->subject): ?>
    <div class="row paddingUD">
        <div class="col-md-5 col-xs-12 light-blue-text bold">
            <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
        </div>
        <div class="col-md-6 col-xs-6"><hr class="hr-light"></div>
        <!--<div class="col-md-1 col-xs-1 noPaddingL">
            <img src="<?php /*print getImgSrc('fluxIcon.png'); */?>">
        </div>-->
    </div>
<?php endif;
if ($content):
    print $content;
endif; ?>