<div class="testimony-wrapper">
    <div class="testimony">
        <?php
        if ($fields['field_testimony']) {
            print $fields['field_testimony']->content;
        } ?>
    </div>
</div>

<div class="row paddingU ">
    <?php
    if ($fields['field_photo']) { ?>
    <div class="col-md-6">
        <?php
        if ($fields['field_photo']) {
            print $fields['field_photo']->content;
        }
        ?>
    </div>
    <div class="col-md-6">
        <?php }
        else { ?>
        <div class="col-md-12">
            <?php } ?>
            <div class="light-blue-text">
                <?php print $fields['field_first_name']->content; ?>
            </div>
            <div class="light-blue-text bold">
                <?php print $fields['field_last_name']->content; ?>
            </div>
            <?php print $fields['title']->content; ?>
        </div>
    </div>