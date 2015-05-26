<?php if ($block->subject): ?>
    <div class="row paddingUD paddingL">
        <div class="col-md-12 col-xs-12 light-blue-text bold noPadding">
<!--            <div class="line">-->
                <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
<!--            </div>-->
        </div>
    </div>
<?php endif;
if ($content):
    print $content;
endif; ?>