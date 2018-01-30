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

global $base_url;

$uid = arg(1);
$account = user_load($uid);
$submission_count = emh_request_submission_get_user_submission_count($uid);
$purchased_count = emh_user_profile_purchase_get_count($account);
$social_networks = (
   field_get_items('user', $account, 'field_link_to_my_blog')
|| field_get_items('user', $account, 'field_linkedin')
|| field_get_items('user', $account, 'field_twitter'));
$countries = country_get_list();
$country_code = $account->field_address[LANGUAGE_NONE]['0']['country'];
$country = isset($countries[$country_code]) ? $countries[$country_code] : '';
?>
<div class="profile"<?php print $attributes; ?>>
  <div class="user-cartouche">
    <div class="cartouche-identity row">
        <span class="user-photo">
          <?php print render($user_profile['field_photo']); ?>
        </span>
      <div class="col-md-4">
        <span class="user-identity">
          <?php print format_username($account); ?>
        </span>
        <span class="user-mail">
          <?php print render($user_profile['field_mail']); ?>
        </span>
        <?php if (!empty($country)) : ?>
          <span class="user-country">
            <?php print $country; ?>
          </span>
        <?php endif; ?>
      </div>

      <?php if (!empty($account->field_address[LANGUAGE_NONE]['0']['phone_number']) || !empty($account->field_address[LANGUAGE_NONE]['0']['mobile_number']) || ($social_networks)) : ?>
      <div class="col-md-3">
        <?php if (!empty($account->field_address[LANGUAGE_NONE]['0']['phone_number'])): ?>
        <span class="user-phone-number">
          <?php print '<span class="glyphicon glyphicon-earphone" aria-hidden="true"></span>&nbsp;' . $account->field_address[LANGUAGE_NONE]['0']['phone_number']; ?>
        </span>
        <?php endif; ?>

        <?php if (!empty($account->field_address[LANGUAGE_NONE]['0']['mobile_number'])): ?>
        <span class="user-mobile-number">
          <?php print '<span class="glyphicon glyphicon-phone" aria-hidden="true"></span>&nbsp;' . $account->field_address[LANGUAGE_NONE]['0']['mobile_number']; ?>
        </span>
        <?php endif; ?>

        <?php if ($social_networks): ?>
        <span class="user-social-networks">
          <?php if (field_get_items('user', $account, 'field_link_to_my_blog')) : ?>
          <?php print l(
              '<span class="glyphicon glyphicon-globe" aria-hidden="true"></span>',
              $account->field_link_to_my_blog[LANGUAGE_NONE]['0']['url'],
              array(
                'attributes' => array(
                  'class' => array('user-website social-network'),
                  'target' => '_blank',
                ),
                'html' => TRUE,
              )
            );
            ?>
          <?php endif; ?>
          <?php if (field_get_items('user', $account, 'field_linkedin')) : ?>
          <?php print l(
              '<img src="' . $base_url . '/' . drupal_get_path('theme', 'emindhub') . '/images/social-networks/linkedin.svg" alt="LinkedIn">',
              $account->field_linkedin[LANGUAGE_NONE]['0']['url'],
              array(
                'attributes' => array(
                  'class' => array('user-website social-network'),
                  'target' => '_blank',
                ),
                'html' => TRUE,
              )
            ); ?>
          <?php endif; ?>
          <?php if (field_get_items('user', $account, 'field_twitter')) : ?>
          <?php print l(
              '<img src="' . $base_url . '/' . drupal_get_path('theme', 'emindhub') . '/images/social-networks/twitter.svg" alt="Twitter">',
              'https://twitter.com/' . $account->field_twitter[LANGUAGE_NONE]['0']['twitter_username'],
              array(
                'attributes' => array(
                  'class' => array('user-website social-network'),
                  'target' => '_blank',
                ),
                'html' => TRUE,
              )
            ); ?>
          <?php endif; ?>
        </span>
        <?php endif; ?>
      </div>
      <?php endif; ?>

      <?php if (!empty($user_profile['field_address'])): ?>
      <div class="col-md-3">
        <span class="user-address">
          <?php print render($user_profile['field_address']); ?>
        </span>
      </div>
      <?php endif; ?>

    </div>
    <div class="cartouche-activity row">
      <div class="col-md-12">
        <span class="user-submission-count" title="<?php print $submission_count . ' ' . t('published answer(s)'); ?>"><?php print $submission_count; ?></span>
        <span class="user-purchased-count" title="<?php print t('Profile purchased !count times', array('!count' => $purchased_count)); ?>"><?php print $purchased_count; ?></span>
      </div>
    </div>
  </div>

  <?php if (
        !empty($user_profile['field_entreprise'])
    ||  !empty($user_profile['field_position'])
    ||  !empty($user_profile['field_working_status'])) : ?>
    <div class="group-organisation profile-section">
      <h2><span><?php print t('Organisation / company'); ?></span></h2>
      <?php print render($user_profile['field_entreprise']); ?>
      <?php print render($user_profile['field_entreprise_description']); ?>
      <?php print render($user_profile['field_position']); ?>
      <?php print render($user_profile['field_titre_metier']); ?>
      <?php print render($user_profile['field_working_status']); ?>
      <?php print render($user_profile['field_activities_linkedin']); ?>
    </div>
  <?php endif; ?>

  <?php if (
        !empty($user_profile['field_domaine'])
    ||  !empty($user_profile['field_skills_set'])
    ||  !empty($user_profile['field_position_list'])
    ||  !empty($user_profile['field_education'])
    ||  !empty($user_profile['field_employment_history'])
    ||  !empty($user_profile['field_cv'])
    ||  !empty($user_profile['field_availability'])) : ?>
    <div class="group-expertise profile-section">
      <h2><span><?php print t('Expertise'); ?></span></h2>
      <?php print render($user_profile['field_domaine']); ?>
      <?php print render($user_profile['field_skills_set']); ?>
      <?php print render($user_profile['field_position_list']); ?>
      <?php print render($user_profile['field_education']); ?>
      <?php print render($user_profile['field_employment_history']); ?>
      <?php print render($user_profile['field_cv']); ?>
      <?php print render($user_profile['field_availability']); ?>
    </div>
  <?php endif; ?>

</div>
