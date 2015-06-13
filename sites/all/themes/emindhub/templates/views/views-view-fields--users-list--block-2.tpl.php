<div class="row paddingU">

        <?php
        if ($fields['field_photo']) { ?>
        <div class="col-xs-6">
            <?php
            if ($fields['field_photo']) {
                print $fields['field_photo']->content;
            }
            ?>
        </div>
        <div class="col-xs-6">
            <?php }
            else { ?>
            <div class="col-md-12">
                <?php } ?>
                <div class="light-blue-text">
                    <?php print $fields['field_first_name']->content; ?>
                </div>
                <div class="light-blue-text bold">
                    <?php //print $fields['field_last_name']->content; ?>
                </div>
                <?php print $fields['field_titre_metier']->content; ?>
            </div>
        </div>
