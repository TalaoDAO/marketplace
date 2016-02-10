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

<div class="progress">
  <div class="progress-bar progress-bar-asphalt" role="progressbar" aria-valuenow="<?php print $current_percent; ?>" aria-valuemin="0" aria-valuemax="100" style="min-width: <?php print $current_percent; ?>em; width: <?php print $current_percent; ?>%;">
    <?php print $current_percent; ?>%
  </div>
</div>

<?php if (isset($nextfield_name) && isset($next_percent)) { ?>
  <p><?php print t('Filling out <em>!empty-field</em> will bring your profile to !complete% complete and will allow you to <strong>access to requests</strong>.', array('!empty-field' => l($nextfield_title, $next_path, $field_link_option), '!complete' => $next_percent)); ?></p>
  <a class="btn btn-asphalt" href="<?php print $next_path; ?>"><?php print t('Update your profile'); ?></a>
<?php } ?>
