<div class="paddingLR">
    <div class="row">
        <div class="col-md-4 challenge-title"><?php echo t("Answer to an expert call"); ?></div>
        <div class="col-md-8">
            <hr class="hr-light">
        </div>
    </div>
    <?php
    if (isset($variables['elements']['links']['views_navigation'])) {
        $linkBack = $variables['elements']['links']['views_navigation']['#links']['back'];
        $linkPrev = $variables['elements']['links']['views_navigation']['#links']['previous'];
        $linkNext = $variables['elements']['links']['views_navigation']['#links']['next'];
    }
    if (isset($linkBack) && isset($linkPrev) && isset($linkNext)) { ?>
        <div class="paddingLR">
            <div class="row light-grey-background paddingUD paddingLR title-wrapper">
                <div class="col-md-3">
                    <div class="challenge-to-list">
                        <?php
                        print "<a href='" . base_path().$linkBack['href'] . "' " . drupal_attributes($linkBack['attributes']) . ">" . $linkBack['title']."</a>";
                        ?>
                    </div>
                </div>
                <div class="col-md-3 col-md-offset-3">
                    <div class="challenge-previous">
                        <?php
                        print "<a href='" . base_path().$linkPrev['href'] . "' " . drupal_attributes($linkPrev['attributes']) . ">" . $linkPrev['title']."</a>";
                        ?>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="challenge-next">
                        <?php
                        print "<a href='" . base_path().$linkNext['href'] . "' " . drupal_attributes($linkNext['attributes']) . ">" . $linkNext['title']."</a>";
                        ?>
                </div>
            </div>
        </div>
    </div>
<?php } ?>
<div class="paddingLR challenge-container">
    <div class="row">
        <div class="col-md-12">
            <h2><?php print $title; ?></h2>
            <br/>
        </div>
    </div>

    <div class="row">
        <div class="col-md-9">
            <div class="row">
                <div class="col-md-6">
                    <div class="row paddingD">
                        <div class="col-md-12">
                            <?php print $elements['field_domaine']['#title']; ?>
                            <div class="challenge-domain softPaddingUD paddingL">
                                <?php if (isset($field_domaine)):
                                    foreach ($field_domaine as $domain) {
                                        print $domain['taxonomy_term']->name . "<br>";
                                    }
                                endif; ?>
                            </div>
                        </div>
                    </div>
                    <?php require_once __DIR__ . '/includes/userInformations.tpl.php'; ?>
                </div>
                <div class="col-md-6">
                    <div class="row">
                        <div class="col-md-6"><?php print $elements['field_autoref']['#title']; ?></div>
                        <div class="col-md-6  bold"><?php print $elements['field_autoref'][0]['#markup']; ?></div>
                    </div>
                    <div class="row">
                        <div class="col-md-6"><?php print t("Publication date:"); ?></div>
                        <div class="col-md-6 bold">
                            <?php if (isset($elements['#node']->created)) {
                                print format_date($elements['#node']->created, 'short');
                            } ?>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-md-6"><?php print $elements['field_start_date']['#title']; ?></div>
                        <div class="col-md-6 bold"><?php print $elements['field_start_date'][0]['#markup']; ?></div>
                    </div>
                    <div class="row">
                        <div class="col-md-6"><?php print t("Number of responses:"); ?></div>
                        <div class="col-md-6 bold">
                            <?php
                                if (!function_exists("webform_get_submission_count")) {
                                    include_once(drupal_get_path('module', 'webform')."/includes/webform.submissions.inc");
                                }
                                print webform_get_submission_count($node->nid);
                            ?>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-md-6"><?php print $elements['field_duration_of_the_mission']['#title']; ?></div>
                        <div class="col-md-6 bold"><?php print $elements['field_duration_of_the_mission'][0]['#markup']; ?></div>
                    </div>
                    <?php if (isset($field_has_salary[0]['value']) && $field_has_salary[0]['value'] == 1) { ?>
                        <div class="row">
                            <div class="col-md-6"><?php print $elements['field_salary_range']['#title']; ?></div>
                            <div class="col-md-6 bold"><?php print $elements['field_salary_range'][0]['#markup']; ?></div>
                        </div>
                    <?php } ?>
                </div>
            </div>
        </div>
        <div class="col-md-3">
            <?php if (isset($field_image)) {
                $img_url = $field_image[0]['uri'];  // the orig image uri
                $style = 'medium';  // or any other custom image style you've created via /admin/config/media/image-styles
                ?>
                <img src="<?php print image_style_url($style, $img_url); ?>"/>
            <?php
            } ?>
        </div>
    </div>
    <?php require_once __DIR__ . '/includes/companyDescription.tpl.php'; ?>
    <?php/*
        if (isset($field_anonymous[0]['value']) && $field_anonymous[0]['value'] == 1) { ?>
        <div class="row">
            <div class="col-md-3 bold paddingU"><?php print $elements['field_entreprise_description']['#title']; ?></div>
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
    <? }*/ ?>
    <div class="row">
        <div class="col-md-3 bold paddingU"><?php print $elements['body']['#title']; ?></div>
    </div>
    <div class="row">
        <div class="col-md-12"><?php print $elements['body'][0]['#markup']; ?></div>
    </div>
    <div class="row">
        <div class="col-md-3 bold paddingU"><?php print $elements['field_object_of_the_mission']['#title']; ?></div>
    </div>
    <div class="row">
        <div class="col-md-12"><?php print $elements['field_object_of_the_mission'][0]['#markup']; ?></div>
    </div>
    <?php require_once __DIR__ . '/includes/tagsField.tpl.php'; ?>
    <div class="row paddingUD">
        <div class="col-md-4">
            <?php print $elements['links']['flag']['#links']['flag-my_selection']['title']; ?>
        </div>
    </div>
    <div>
        <form action="$elements['webform']['#form']['#action']" method="$elements['webform']['#form']['#method']">
            <?php
            $form = $elements['webform']['#form'];
            $formFields = $form['submitted'];
            foreach ($node->webform['components'] as $componnent) {
                $formItem = $formFields[$componnent['form_key']];
                $formItem['#title_display'] = "invisible";
                $formItem['#required'];
                $requireSpan = "";
                if ($formItem['#required']){
                    $requireSpan = '&nbsp;<span class="required">*</span>';
                }
                print sprintf("<div class='bold'>%s%s</div><div>%s</div>", $formItem['#title'], $requireSpan, render($formItem));
            }
            print render($form['form_build_id']);
            print render($form['form_id']);
            print render($form['form_token']);
            print render($form['details']);
            print render($form['actions']);
            unset($form);
            unset($formFields);
            unset($formItem);
            unset($requireSpan);
            ?>
        </form>
    </div>
</div>