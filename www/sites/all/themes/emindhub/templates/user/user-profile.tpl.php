<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
$uid = arg(1);
$account = user_load($uid);
$submission_count = emh_request_submission_get_user_submission_count($uid);
$purchased_count = emh_user_profile_purchase_get_count($account);
?>
<div class="profile"<?php print $attributes; ?>>
  <?php //print render($user_profile); ?>

  <div class="user-cartouche">
    <?php if (!empty($user_profile['field_photo']) || !empty($user_profile['field_titre_metier']) || !empty($user_profile['field_entreprise']) || !empty($user_profile['field_address']) || !empty($user_profile['field_mail'])) : ?>
    <div class="cartouche-identity">
      <?php print render($user_profile['field_photo']); ?>
      <?php print render($user_profile['field_titre_metier']); ?>
      <?php print render($user_profile['field_entreprise']); ?>
      <?php print render($user_profile['field_address']); ?>
      <?php print render($user_profile['field_mail']); ?>
    </div>
    <?php endif; ?>
    <div class="cartouche-activity">
      <span class="user-submission-count" title="<?php print $submission_count . ' ' . t('published submission(s)'); ?>"><?php print $submission_count; ?></span>
      <span class="user-purchased-count" title="<?php print t('Profile purchased !count times', array('!count' => $purchased_count)); ?>"><?php print render($purchased_count); ?></span>
    </div>
  </div>

  <?php if (!empty($user_profile['field_position']) || !empty($user_profile['field_working_status'])) : ?>
  <div class="group-organisation profile-section">
    <h2><span><?php print t('Organisation'); ?></span></h2>
    <?php print render($user_profile['field_position']); ?>
    <?php print render($user_profile['field_working_status']); ?>
  </div>
  <?php endif; ?>

  <?php if (!empty($user_profile['field_needs_for_expertise']) || !empty($user_profile['field_specific_skills3'])) : ?>
  <div class="group-needs profile-section">
    <h2><span><?php print t('Needs'); ?></span></h2>
    <?php print render($user_profile['field_needs_for_expertise']); ?>
    <?php print render($user_profile['field_specific_skills3']); ?>
  </div>
  <?php endif; ?>

  <?php if (!empty($user_profile['field_domaine']) || !empty($user_profile['field_skills_set']) || !empty($user_profile['field_position_list']) || !empty($user_profile['field_employment_history']) || !empty($user_profile['field_cv'])) : ?>
  <div class="group-skills profile-section">
    <h2><span><?php print t('Skills & background'); ?></span></h2>
    <?php print render($user_profile['field_domaine']); ?>
    <?php print render($user_profile['field_skills_set']); ?>
    <?php print render($user_profile['field_position_list']); ?>
    <?php print render($user_profile['field_employment_history']); ?>
    <?php print render($user_profile['field_cv']); ?>
  </div>
  <?php endif; ?>

  <?php if (!empty($user_profile['field_other_areas'])) : ?>
  <div class="group-interests profile-section">
    <h2><span><?php print t('Interests'); ?></span></h2>
    <?php print render($user_profile['field_other_areas']); ?>
  </div>
  <?php endif; ?>

</div>
