<?php global $base_url; ?>

<div class="emh-module customer-emh-expert container">

    <div class="cee-customer cee-block">
        <div class="title">
            <?php print t('Clients') ?>
        </div>
        <ul class="cee-items">
            <li><?php print t('Managers'); ?></li>
            <li><?php print t('Project leaders'); ?></li>
            <li><?php print t('Engineers'); ?></li>
            <li><?php print t('Consultants'); ?></li>
        </ul>
    </div>

    <div class="cee-emh cee-block">
        <div class="title">
            <img class="horizontal" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/logo/logo-h.svg" alt="eMindHub" />
            <img class="vertical"   src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/logo/logo-v.svg" alt="eMindHub" />
        </div>
        <ul class="cee-items">
            <li><?php print t('Content'); ?></li>
            <li><?php print t('Advice'); ?></li>
            <li><?php print t('Projects'); ?></li>
        </ul>
    </div>

    <div class="cee-expert cee-block">
        <div class="title">
            <?php print t('Experts') ?>
        </div>
        <ul class="cee-items">
            <li><?php print t('Employed'); ?></li>
            <li><?php print t('Freelancers'); ?></li>
            <li><?php print t('Retirees'); ?></li>
        </ul>
    </div>

</div>
