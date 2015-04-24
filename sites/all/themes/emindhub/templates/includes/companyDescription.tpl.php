<?php
if (isset($field_anonymous[0]['value']) && $field_anonymous[0]['value'] == 0) { ?>
    <div class="row">
        <div class="col-md-3 bold paddingU"><?php
            if ($elements['field_entreprise_description']) {
                print $elements['field_entreprise_description']['#title'];
            }
            ?></div>
    </div>
    <div class="row">
        <div class="col-md-12">
            <?php
            if (isset($field_use_my_entreprise) && $field_use_my_entreprise[0]['value'] != 0) {
                print $field_entreprise_description[0]['value'];
            } else {
                print $company_description; //emindhub_preprocess_node__webform
            }
            ?>
        </div>
    </div>
<?php } ?>