<?php
if (isset($field_anonymous[0]['value']) && $field_anonymous[0]['value'] == 1) { ?>
    <div class="row">
        <div class="col-md-3 bold paddingU"><?php ddl(get_defined_vars()); print $elements['field_entreprise_description']['#title']; ?></div>
    </div>
    <div class="row">
        <div class="col-md-12 bold">
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