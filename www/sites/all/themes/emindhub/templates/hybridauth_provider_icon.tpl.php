<?php
global $base_url;
$provider = preg_replace('/[^A-Za-z0-9\-]/', '', strtolower($provider_name));
?>
<img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/<?php print $provider; ?>.svg" alt="<?php print $provider_name; ?>" width="30" height="30" />
<span class="<?php print $icon_pack_classes; ?>" title="<?php print $provider_name; ?>">
  <?php print t('Continue with '); ?><?php print $provider_name; ?>
</span>
