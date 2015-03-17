<?php
/**
 * @file
 * Default theme implementation for profiles.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) profile type label.
 * - $url: The URL to view the current profile.
 * - $page: TRUE if this is the main view page $url points too.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-profile
 *   - profile-{TYPE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */



/*
//GENERAL
$form['group_account']['field_first_name']['und'][0]
$form['group_account']['field_last_name']['und'][0]
$form['group_account']['account']['name']
$form['group_account']['account']['mail']
$form['group_account']['account']['pass']
    $form['group_account']['account']['pass']['pass1']
    $form['group_account']['account']['pass']['pass2']
    $form['group_account']['account']['pass']['#element_validate']

$form['group_account']['field_name_visibility']['und']
$form['group_account']['field_profile_visibility']['und']

//EXPERT
    //PERSONNAL
        //ADDR
            $form['profile_expert']['field_address']
                $form['profile_expert']['field_address']['und'][0]['street_block']
                    $form['profile_expert']['field_address']['und'][0]['street_block']['thoroughfare']
                    $form['profile_expert']['field_address']['und'][0]['street_block']['premise']
                $form['profile_expert']['field_address']['und'][0]['locality_block']
                    $form['profile_expert']['field_address']['und'][0]['locality_block']['postal_code']
                    $form['profile_expert']['field_address']['und'][0]['locality_block']['dependent_locality']
                    $form['profile_expert']['field_address']['und'][0]['locality_block']['locality']
                    $form['profile_expert']['field_address']['und'][0]['locality_block']['administrative_area']
                $form['profile_expert']['field_address']['und'][0]['country']
                    $form['profile_expert']['field_address']['und'][0]['country']['#element_validate']

        //BLOG LINKS
            $form['profile_expert']['field_link_to_my_blog']['und'][0]['title']
            $form['profile_expert']['field_link_to_my_blog']['und'][0]['url']
        //PROFESSIONNAL
            $form['profile_expert']['field_titre_metier']['und'][0]
            $form['profile_expert']['field_working_status']['und']
            $form['profile_expert']['field_entreprise_visibility']['und']
            $form['profile_expert']['field_entreprise']['und'][0]
        //SPONSOR
            $form['profile_expert']['field_sponsor']['und'][0]
            $form['profile_expert']['field_sponsorship']['und']
        //SKILLS
            $form['profile_expert']['field_domaine']['und']
            $form['profile_expert']['field_interests']['und']
            $form['profile_expert']['field_skills_visibility']['und']
            $form['profile_expert']['field_skills_set']['und'][0]
            $form['profile_expert']['field_employment_history']['und'][0]
        //COMPLEMENT
            $form['profile_expert']['field_notification_frequency']['und']
            $form['profile_expert']['field_known_how']['und']
            $form['profile_expert']['field_known_specific']['und'][0]

*/

//GENERAL
$fieldFirstName = $form['group_account']['field_first_name'][LANGUAGE_NONE][0];
$fieldLastName = $form['group_account']['field_last_name'][LANGUAGE_NONE][0];
$fieldUsername = $form['group_account']['account']['name'];
$fieldMail = $form['group_account']['account']['mail'];
$fieldPass = $form['group_account']['account']['pass'];
$fieldPass_pass1 = $form['group_account']['account']['pass']['pass1'];
$fieldPass_pass2 = $form['group_account']['account']['pass']['pass2'];
    //$form['group_account']['account']['pass']['#element_validate']
$fieldNameVisibility = $form['group_account']['field_name_visibility'][LANGUAGE_NONE];
$fieldProfileVisibility = $form['group_account']['field_profile_visibility'][LANGUAGE_NONE];


//EXPERT
if (isset($form['profile_expert'])) {
    //PERSONNAL
    $fieldAddress = $form['profile_expert']['field_address'];
    $fieldAddress_street = $form['profile_expert']['field_address'][LANGUAGE_NONE][0]['street_block'];
    $fieldAddress_street_line1 = $form['profile_expert']['field_address'][LANGUAGE_NONE][0]['street_block']['thoroughfare'];
    $fieldAddress_street_line2 = $form['profile_expert']['field_address'][LANGUAGE_NONE][0]['street_block']['premise'];
    $fieldAddress_locality = $form['profile_expert']['field_address'][LANGUAGE_NONE][0]['locality_block'];
    $fieldAddress_locality_postalCode = $form['profile_expert']['field_address'][LANGUAGE_NONE][0]['locality_block']['postal_code'];
    $fieldAddress_locality_dependentLocality = $form['profile_expert']['field_address'][LANGUAGE_NONE][0]['locality_block']['dependent_locality'];
    $fieldAddress_locality_locality = $form['profile_expert']['field_address'][LANGUAGE_NONE][0]['locality_block']['locality'];
    $fieldAddress_locality_administrativeArea = $form['profile_expert']['field_address'][LANGUAGE_NONE][0]['locality_block']['administrative_area'];
    $fieldAddress_country = $form['profile_expert']['field_address'][LANGUAGE_NONE][0]['country'];
    //$fieldAddress =                     $form['profile_expert']['field_address'][LANGUAGE_NONE][0]['country']['#element_validate'];

    $fieldBlogBlockTitle = $form['profile_expert']['field_link_to_my_blog'][LANGUAGE_NONE]['#title'];
    $fieldBlogTitle = $form['profile_expert']['field_link_to_my_blog'][LANGUAGE_NONE][0]['title'];
    $fieldBlogUrl = $form['profile_expert']['field_link_to_my_blog'][LANGUAGE_NONE][0]['url'];

    //PROFESSIONNAL
    $fieldProfileTitle = $form['profile_expert']['field_titre_metier'][LANGUAGE_NONE][0];
    $fieldWorkingStatus = $form['profile_expert']['field_working_status'][LANGUAGE_NONE];
    $fieldEntrepriseVisibility = $form['profile_expert']['field_entreprise_visibility'][LANGUAGE_NONE];
    $fieldEntreprise = $form['profile_expert']['field_entreprise'][LANGUAGE_NONE][0];

    //SPONSOR
    $fieldSponsor = $form['profile_expert']['field_sponsor'][LANGUAGE_NONE][0];
    $fieldSponsorShip = $form['profile_expert']['field_sponsorship'][LANGUAGE_NONE];

    //SKILLS
    $fieldDomains = $form['profile_expert']['field_domaine'][LANGUAGE_NONE];
    $fieldInterests = $form['profile_expert']['field_interests'][LANGUAGE_NONE];
    $fieldSkillsVisibility = $form['profile_expert']['field_skills_visibility'][LANGUAGE_NONE];
    $fieldSkillsSet = $form['profile_expert']['field_skills_set'][LANGUAGE_NONE][0];
    $fieldEmployementHistory = $form['profile_expert']['field_employment_history'][LANGUAGE_NONE][0];



}
?>
<div class="registration-form">
    <div class="sub-title paddingD"><?php print t("Register form to Emindhub :"); ?></div>

    <div class="row paddingD">
        <div class="col-md-6 name-field"><?php print render($fieldFirstName); ?></div>
        <div class="col-md-6 name-field"><?php print render($fieldLastName); ?></div>
    </div>
    <div class="row">
        <div class="col-md-6 name-field"><?php print render($fieldUsername); ?></div>
        <!--<div class="col-md-6 name-field"><?php //print render($form['profile_main']['field_corporation']); ?></div>-->
    </div>


    <hr class="hr-light-grey-dashed">

    <div class="row paddingD">
        <div class="col-md-3">
            <label for="<?php print $fieldMail['#id']; ?>">
                <?php print $fieldMail['#title'];
                if ($fieldMail['#required']): ?> <span class="required">*</span><?php endif; ?>
            </label>
        </div>
        <div class="col-md-6 mail">
            <?php
            $tmp = array(
              '#type' => 'textfield',
              '#id' => 'edit-mail',
              '#name' => 'mail',
              '#required' => TRUE,
              '#value' => '',
              '#theme' => 'textfield',
              '#themes_wrapper' => array(),
            );
            print drupal_render($tmp); ?>
        </div>
    </div>

    <!--
    <div class="paddingD">
        <div class="row">
            <div class="col-md-3">
                <label for="<?php
                /*$description = $fieldPass_pass1['#description'];
                $fieldPass_pass1['#description'] = "";
                print $fieldPass_pass1['#id']; ?>">
                    <?php print $fieldPass_pass1['#title'];
                    if ($fieldPass_pass1['#required']): ?> <span class="required">*</span><?php endif; ?>
                </label>
            </div>
            <div class="col-md-6 hide-field-label"><?php print render($fieldPass_pass1); ?></div>
        </div>
        <?php if (isset($description)): ?>
            <div class="row">
                <div class="col-md-12 description-custom"><?php print $description; unset($description); ?></div>
            </div>
        <?php endif; ?>
    </div>
    <div class="paddingD">
        <div class="row">
            <div class="col-md-3">
                <label for="<?php
                $description = $fieldPass_pass2['#description'];
                $fieldPass_pass2['#description'] = "";
                print $fieldPass_pass2['#id']; ?>">
                    <?php print $fieldPass_pass2['#title'];
                    if ($fieldPass_pass2['#required']): ?> <span class="required">*</span><?php endif; ?>
                </label>
            </div>
            <div class="col-md-6 hide-field-label"><?php print render($fieldPass_pass2); ?></div>
        </div>
        <?php if (isset($description)): ?>
            <div class="row">
                <div class="col-md-12 description-custom"><?php print $description; unset($description); ?></div>
            </div>
        <?php endif; */?>
    </div>
    -->

   <?php
   print render($fieldPass);
   ?>


    <hr class="hr-light-grey-dashed">
    <div class="visibility-checkboxes">
    <?php
    print render($fieldNameVisibility);
    print render($fieldProfileVisibility);
    ?>
    </div>
    <hr class="hr-light-grey-dashed">
    <?php if (isset($form['profile_expert']) && FALSE): ?>
        <div class="address-block">
            <div class="row">
                <div class="col-md-2">
                    <?php $fieldAddress_country['#title_display'] = "invisible"; ?>
                    <label for="<?php $fieldAddress_country['#id']; ?>">
                        <?php print $fieldAddress_country['#title'];
                        if ($fieldAddress_country['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-9">
                    <?php print render($fieldAddress_country); ?>
                </div>
            </div>

            <div class="row">
                <div class="col-md-2">
                    <?php $fieldAddress_street_line1['#title_display'] = "invisible"; ?>
                    <label for="<?php print $fieldAddress_street_line1['#id']; ?>">
                        <?php print $fieldAddress_street_line1['#title'];
                        if ($fieldAddress_street_line1['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-9 street-line">
                    <?php print render($fieldAddress_street_line1); ?>
                </div>
            </div>
            <div class="row">
                <div class="col-md-2">
                    <?php $fieldAddress_street_line2['#title_display'] = "invisible"; ?>
                    <label for="<?php print $fieldAddress_street_line2['#id']; ?>">
                        <?php print $fieldAddress_street_line2['#title'];
                        if ($fieldAddress_street_line2['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-9 street-line">
                    <?php print render($fieldAddress_street_line2); ?>
                </div>
            </div>
            <div class="row">
                 <div class="col-md-2">
                     <?php $fieldAddress_locality_postalCode['#title_display'] = "invisible"; ?>
                     <label for="<?php print $fieldAddress_locality_postalCode['#id']; ?>">
                         <?php print $fieldAddress_locality_postalCode['#title'];
                         if ($fieldAddress_locality_postalCode['#required']): ?> <span class="required">*</span><?php endif; ?>
                     </label>
                 </div>
                 <div class="col-md-3"><?php print render($fieldAddress_locality_postalCode); ?></div>
                <div class="col-md-2">
                    <?php $fieldAddress_locality_locality['#title_display'] = "invisible"; ?>
                    <label for="<?php print $fieldAddress_locality_locality['#id']; ?>">
                        <?php print $fieldAddress_locality_locality['#title'];
                        if ($fieldAddress_locality_locality['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-3"><?php print render($fieldAddress_locality_locality); ?></div>
            </div>
            <?php
            $fieldAddress_locality_dependentLocality['#title_display'] = "invisible";
            $fieldAddress_locality_administrativeArea['#title_display'] = "invisible";
            if ($fieldAddress_locality_dependentLocality['#access'] && $fieldAddress_locality_administrativeArea['#access']):
            ?>
            <div class="row">
                <?php if ($fieldAddress_locality_dependentLocality['#access']): ?>
                <div class="col-md-2">
                    <label for="<?php print $fieldAddress_locality_dependentLocality['#id']; ?>">
                        <?php print $fieldAddress_locality_dependentLocality['#title'];
                        if ($fieldAddress_locality_dependentLocality['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-3"><?php print render($fieldAddress_locality_dependentLocality); ?></div>
                <?php endif; ?>
                <?php if ($fieldAddress_locality_administrativeArea['#access']): ?>
                <div class="col-md-2">
                    <label for="<?php print $fieldAddress_locality_administrativeArea['#id']; ?>">
                        <?php print $fieldAddress_locality_administrativeArea['#title'];
                        if ($fieldAddress_locality_administrativeArea['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-3"><?php print render($fieldAddress_locality_administrativeArea); ?></div>
                <?php endif; ?>
            </div>
            <?php endif;
            /*$field = $form['profile_expert']['field_tel'][LANGUAGE_NONE][0];
            $field['#title_display'] = "invisible";
            $description = $field['#description'];
            $field['#description'] = "";*/
            ?>
            <!--<div class="row noPadding">
                <div class="col-md-2">
                    <label for="<?php //print $field['#id']; ?>">
                        <?php /*print $field['#title'];
                        if ($field['#required']): ?> <span class="required">*</span><?php endif;*/ ?>
                    </label>
                </div>
                <div class="col-md-3 phone-field"><?php// print render($field); ?></div>
            </div>
            <?php// if (isset($description)): ?>
            <div class="row">
                <div class="col-md-12 description-custom"><?php //print $description; unset($description); ?></div>
            </div>-->
            <?php //endif; ?>
        </div>
        <div class="row blog-block-titles">
            <div class="col-md-12 bold"><?php print $fieldBlogBlockTitle; ?></div>
        </div>
        <div class="row blog-block-titles">
            <?php
            $fieldBlogTitle['#title_display'] = "invisible";
            $description = $fieldBlogTitle['#description'];
            $fieldBlogTitle['#description'] = "";
            $fieldBlogUrl['#title_display'] = "invisible";
            ?>
            <div class="col-md-4">
                <label for="<?php print $fieldBlogTitle['#id']; ?>">
                    <?php print $fieldBlogTitle['#title'];
                    if ($fieldBlogTitle['#required']): ?> <span class="required">*</span><?php endif; ?>
                </label>
            </div>
            <div class="col-md-8">
                <label for="<?php print $fieldBlogUrl['#id']; ?>">
                    <?php print $fieldBlogUrl['#title'];
                    if ($fieldBlogUrl['#required']): ?> <span class="required">*</span><?php endif; ?>
                </label></div>
        </div>
        <div class="row blog-block">
            <div class="col-md-4"><?php print render($fieldBlogTitle); ?></div>
            <div class="col-md-8"><?php print render($fieldBlogUrl); ?></div>
        </div>
        <?php if (isset($description)): ?>
            <div class="row">
                <div class="col-md-12 description-custom"><?php print $description; unset($description); ?></div>
            </div>
        <?php endif; ?>


        <hr class="hr-light-grey-dashed">
        <?php
        $fieldProfileTitle['#title_display'] = "invisible";
        $description = $fieldProfileTitle['#description'];
        $fieldProfileTitle['#description'] = "";
        ?>
        <div class="paddingD">
            <div class="row">
                <div class="col-md-2">
                    <label for="<?php print $fieldProfileTitle['#id']; ?>">
                        <?php print $fieldProfileTitle['#title'];
                        if ($fieldProfileTitle['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-5 hide-field-label"><?php print render($fieldProfileTitle); ?></div>
            </div>
            <?php if (isset($description)): ?>
                <div class="row">
                    <div class="col-md-12 description-custom"><?php print $description; unset($description); ?></div>
                </div>
            <?php endif; ?>
        </div>
        <?php
        $fieldWorkingStatus['#title_display'] = "invisible";
        $description = $fieldWorkingStatus['#description'];
        $fieldWorkingStatus['#description'] = "";
        ?>
        <div class="paddingD">
            <div class="row">
                <div class="col-md-2">
                    <label for="<?php print $fieldWorkingStatus['#id']; ?>">
                        <?php print $fieldWorkingStatus['#title'];
                        if ($fieldWorkingStatus['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-5 hide-field-label"><?php print render($fieldWorkingStatus); ?></div>
            </div>
            <?php if (isset($description)): ?>
                <div class="row">
                    <div class="col-md-12 description-custom"><?php print $description; unset($description); ?></div>
                </div>
            <?php endif; ?>
        </div>
        <?php print render($fieldEntrepriseVisibility);

        $fieldEntreprise['#title_display'] = "invisible";
        $description = $fieldEntreprise['#description'];
        $fieldEntreprise['#description'] = "";
        ?>
        <div class="paddingD">
            <div class="row">
                <div class="col-md-2">
                    <label for="<?php print $fieldEntreprise['#id']; ?>">
                        <?php print $fieldEntreprise['#title'];
                        if ($fieldEntreprise['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-5 hide-field-label"><?php print render($fieldEntreprise); ?></div>
            </div>
            <?php if (isset($description)): ?>
                <div class="row">
                    <div class="col-md-12 description-custom"><?php print $description; unset($description); ?></div>
                </div>
            <?php endif; ?>
        </div>

        <hr class="hr-light-grey-dashed">
        <?php
        print render($fieldSponsorShip);
        print render($fieldSponsor ); ?>
        <hr class="hr-light-grey-dashed">
        <hr class="hr-light-grey-dashed">
        <hr class="hr-light-grey-dashed">

        <hr class="hr-light">
        <div class="row domain-select">
            <div class="col-md-2">
                <label for="<?php
                $fieldDomains['#title_display'] = 'invisible';
                print $fieldDomains['#id']; ?>">
                    <?php print $fieldDomains['#title'];
                    if ($fieldDomains['#required']): ?> <span class="required">*</span><?php endif; ?>
                </label>
            </div>
            <div class="col-md-6">
                <?php print render($fieldDomains); ?>
            </div>
        </div>
        <div class="row interest-select">
            <div class="col-md-2">
                <label for="<?php
                $fieldInterests['#title_display'] = 'invisible';
                print $fieldInterests['#id']; ?>">
                    <?php print $fieldInterests['#title'];
                    if ($fieldInterests['#required']): ?> <span class="required">*</span><?php endif; ?>
                </label>
            </div>
            <div class="col-md-6">
                <?php print render($fieldInterests); ?>
            </div>
        </div>
        <hr class="hr-light">
        <?php
        //print render($fieldInterests);
        print render($fieldSkillsVisibility);
        print render($fieldSkillsSet);
        print render($fieldEmployementHistory);
        ?>
        <hr class="hr-light-grey-dashed">
        <hr class="hr-light-grey-dashed">
        <hr class="hr-light-grey-dashed">
        <?php
        /*

        */
        print render($form['profile_expert']['field_area_of_interest']);
        print render($form['profile_expert']['field_employment_history']);
        print render($form['profile_expert']['field_cv']);
        print render($form['profile_expert']['field_referent']);
        print render($form['profile_expert']['field_testimony']);
        ?>

        <hr class="hr-light-grey-dashed">

        <?php
        print render($form['profile_expert']['field_domaine']);
        print render($form['profile_expert']['field_skills_visibility']);
        ?>
        <div class="skills-set-container">
        <?php
        print render($form['profile_expert']['field_skills_set']);
        ?>
        </div>
        <hr class="hr-light-grey-dashed">
        <div class="register-complement">
            <?php $field = $form['profile_expert']['field_notification_frequency'][LANGUAGE_NONE];
            $field['#title_display'] = "invisible"; ?>
            <div class="row paddingD">
                <div class="col-md-3">
                    <label for="<?php $field['#id']; ?>">
                        <?php print $field['#title'];
                        if ($field['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-9">
                    <?php print render($field); ?>
                </div>
            </div>
            <?php $field = $form['profile_expert']['field_known_how'][LANGUAGE_NONE];
            $field['#title_display'] = "invisible"; ?>
            <div class="row paddingD">
                <div class="col-md-3">
                    <label for="<?php $field['#id']; ?>">
                        <?php print $field['#title'];
                        if ($field['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-9">
                    <?php print render($field); ?>
                </div>
            </div>
            <?php $field = $form['profile_expert']['field_known_specific'][LANGUAGE_NONE][0];
            $field['#title_display'] = "invisible"; ?>
            <div class="row paddingD">
                <div class="col-md-3">
                    <label for="<?php $field['#id']; ?>">
                        <?php print $field['#title'];
                        if ($field['#required']): ?> <span class="required">*</span><?php endif; ?>
                    </label>
                </div>
                <div class="col-md-9 known-specific">
                    <?php print render($field); ?>
                </div>
            </div>
        </div>
    <?php endif; ?>
    <?php if (isset($form['profile_business']) && FALSE): ?>
        <?php $field = $form['profile_business']['field_known_how'][LANGUAGE_NONE];
        $field['#title_display'] = "invisible"; ?>
        <div class="row paddingD">
            <div class="col-md-3">
                <label for="<?php $field['#id']; ?>">
                    <?php print $field['#title'];
                    if ($field['#required']): ?> <span class="required">*</span><?php endif; ?>
                </label>
            </div>
            <div class="col-md-9">
                <?php print render($field); ?>
            </div>
        </div>
        <?php $field = $form['profile_business']['field_known_specific'][LANGUAGE_NONE][0];
        $field['#title_display'] = "invisible"; ?>
        <div class="row paddingD">
            <div class="col-md-3">
                <label for="<?php $field['#id']; ?>">
                    <?php print $field['#title'];
                    if ($field['#required']): ?> <span class="required">*</span><?php endif; ?>
                </label>
            </div>
            <div class="col-md-9 known-specific">
                <?php print render($field); ?>
            </div>
        </div>
    <?php endif; ?>
    <div class="validate-btn-container">
        <?php print drupal_render($form['actions']); ?>
    </div>
</div>

