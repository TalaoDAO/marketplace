<?php
/**
 * @file
 * Default theme implementation for PCP block
 *
 * Available variables:
 *  $uid: Current user ID.
 *  $current_percent: From 0 to 100% of how much the profile is complete.
 *  $next_percent: The percent if the user filled the next field.
 *  $completed: How many fields the user has filled.
 *  $incomplete: The inverse of $completed, how many empty fields left.
 *  $total: Total number of fields in profile.
 *  $nextfield_title: The name of the suggested next field to fill (human readable name).
 *  $nextfield_name: The name of the suggested next field to fill (machine name).
 *
 * @see template_preprocess_pcp_profile_percent_complete()
 */
?>
<style type="text/css">
  .pcp-percent-bar.<?php print $entity_type . '-' . $bundle; ?> { width: <?php print $current_percent; ?>%; }
</style>

<div class="pcp-wrapper <?php print 'pcp-' . $entity_type;?> <?php print 'pcp-' . $bundle; ?>">
  <?php print t('!complete% Complete', array('!complete' => $current_percent)); ?>

  <div class="pcp-percent-bar-wrapper">
    <div class="pcp-percent-bar <?php print $entity_type . '-' . $bundle; ?>"></div>
  </div>
</div>

<?php
  if (isset($nextfield_name) && isset($next_percent)) {
    print t('Filling out <em>!empty-field</em> will bring your profile to !complete% complete', array('!empty-field' => l($nextfield_title, $next_path, $field_link_option), '!complete' => $next_percent));
  }
?>
