<?php if (isset($field_use_my_entreprise[0]['value']) && $field_use_my_entreprise[0]['value'] != 0) { ?>

  <?php if (isset($elements['field_entreprise_description'])) : ?>
    <?php print $elements['field_entreprise_description']['#title']; ?>
  <?php endif; ?>

  <?php if (isset($field_use_my_entreprise) && $field_use_my_entreprise[0]['value'] == 2) { ?>
    <?php print $field_entreprise_description[0]['value']; ?>
  <?php } else { ?>
  <?php print $company_description; //emindhub_preprocess_node__webform ?>
  <?php } ?>

<?php } ?>
