<?php if ($block->title) { ?>
    <div class="title-wrapper">
        <div class="row">
            <div class="col-md-4">
                <hr class="hr-dark" />
            </div>
            <div  class="col-md-4 title"><?php print $block->title ?></div>
            <div class="col-md-4">
                <hr class="hr-dark" />
            </div>
        </div>
    </div>
<?php } else { ?>
    <div class="title-wrapper"></div>
<?php }
print $content ?>