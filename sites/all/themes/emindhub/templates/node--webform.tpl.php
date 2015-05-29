<div class="paddingLR">
    <div class="row">
   <?php if (!user_has_role(5)): ?>
        <div class="col-md-4 challenge-title"><?php echo c_szAnswerExpertCall; ?></div>
        <div class="col-md-8">
            <hr class="hr-light">
        </div>
   <?php endif; ?>
    </div>
    <?php
    if (isset($variables['elements']['links']['views_navigation'])) {
        $linkBack = $variables['elements']['links']['views_navigation']['#links']['back'];
        $linkPrev = $variables['elements']['links']['views_navigation']['#links']['previous'];
        $linkNext = $variables['elements']['links']['views_navigation']['#links']['next'];
    }
    if (isset($linkBack) && isset($linkPrev) && isset($linkNext)) { ?>
<!--        <div class="paddingLR">-->
            <div class="row light-grey-background paddingUD paddingLR title-wrapper">
                <div class="col-sm-3">
                    <div class="challenge-to-list">
                        <?php
                        print "<a href='" . base_path().$linkBack['href'] . "' " . drupal_attributes($linkBack['attributes']) . ">" . $linkBack['title']."</a>";
                        ?>
                    </div>
                </div>
                <div class="col-sm-3 col-sm-offset-3 col-xs-6">
                    <div class="challenge-previous">
                        <?php
                        print "<a href='" . base_path().$linkPrev['href'] . "' " . drupal_attributes($linkPrev['attributes']) . ">" . $linkPrev['title']."</a>";
                        ?>
                    </div>
                </div>
                <div class="col-sm-3 col-xs-6">
                    <div class="challenge-next">
                        <?php
                        print "<a href='" . base_path().$linkNext['href'] . "' " . drupal_attributes($linkNext['attributes']) . ">" . $linkNext['title']."</a>";
                        ?>
                </div>
            </div>
        </div>
    <!---</div>-->
<?php } ?>

<div class="row paddingLR challenge-container">
    <div class="row">
    <div class="col-md-12">
        <h2><?php print $title; ?></h2>
        <br />
    </div>
    </div>
    <div>
        <?php if (isset($body[0]['value'])): ?>
            <?php print $body[0]['value']; ?>
        <?php endif; ?>
    </div>
</div>
&nbsp;


<div class="challenge-container row paddingLR">
    <div class="row">
        <?php if ($field_image && isset($field_image)) { ?>
            <div class="col-md-9">
        <?php } else { ?>
            <div class="col-md-12">
        <?php }  ?>
            <div class="row">
                <div class="col-sm-6">
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
                <div class="col-sm-6">
                    <div class="row">
                        <div class="col-xs-6"><?php print $elements['field_autoref']['#title']; ?></div>
                        <div class="col-xs-6  bold"><?php print $elements['field_autoref'][0]['#markup']; ?></div>
                    </div>
                    <div class="row">
                        <div class="col-xs-6"><?php print c_szPublicationDt; ?></div>
                        <div class="col-xs-6 bold">
                            <?php if (isset($elements['#node']->created)) {
                                print format_date($elements['#node']->created, 'custom', 'm/d/Y');
                            } ?>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-xs-6"><?php print $elements['field_start_date']['#title']; ?></div>
                        <div class="col-xs-6 bold"><?php
                            print date('m/d/Y', strtotime($node->field_start_date['und'][0]['value']));
                            ?></div>
                    </div>
                    <div class="row">
                        <div class="col-xs-6"><?php print c_szNumResponses; ?></div>
                        <div class="col-xs-6 bold">
                            <?php
                                if (!function_exists("webform_get_submission_count")) {
                                    include_once(drupal_get_path('module', 'webform')."/includes/webform.submissions.inc");
                                }
                                print webform_get_submission_count($node->nid);
                            ?>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-xs-6"><?php print $elements['field_duration_of_the_mission']['#title']; ?></div>
                        <div class="col-xs-6 bold"><?php print $elements['field_duration_of_the_mission'][0]['#markup']; ?></div>
                    </div>
                    <?php if (isset($field_has_salary[0]['value']) && $field_has_salary[0]['value'] == 1) { ?>
                        <div class="row">
                            <div class="col-xs-6"><?php print $elements['field_salary_range']['#title']; ?></div>
                            <div class="col-xs-6 bold"><?php print $elements['field_salary_range'][0]['#markup']; ?></div>
                        </div>
                    <?php } ?>
                </div>
            </div>
        </div>
        <?php if ($field_image && isset($field_image)) { ?>
            <div class="col-md-3">
            <?php $img_url = $field_image[0]['uri'];  // the orig image uri
                $style = 'medium';  // or any other custom image style you've created via /admin/config/media/image-styles
                ?>
                <img src="<?php print image_style_url($style, $img_url); ?>"/>
            </div>
        <?php } ?>
    </div>
    <?php require_once __DIR__ . '/includes/companyDescription.tpl.php'; ?>
    <div class="row">
        <div class="col-md-12"><?php if (isset($elements['field_object_of_the_mission'])) print $elements['field_object_of_the_mission'][0]['#markup']; ?></div>
    </div>
    <?php require_once __DIR__ . '/includes/tagsField.tpl.php'; ?>
    <div class="row paddingUD">
        <div class="col-md-4">
            <?php print $elements['links']['flag']['#links']['flag-my_selection']['title']; ?>
        </div>
<?php if (node_access('update',$node)) print l(t('Edit'),'node/'.$node->nid.'/edit', array('attributes' => array('class' => array('btn','btn-primary','btn-expert'))) ); ?>

&nbsp;  <?php if (node_access('update',$node)) print l(t('Edit questions'),'node/'.$node->nid.'/webform', array('attributes' => array('class' => array('btn','btn-primary','btn-expert'))) ); ?>
&nbsp;  <?php if (node_access('update',$node)) print l(t('View responses'),'node/'.$node->nid.'/webform-results', array('attributes' => array('class' => array('btn','btn-primary','btn-expert'))) ); ?>
    </div>
</div>
&nbsp;
<div class="row paddingLR challenge-container">
    <div>
        <form action="<?=$elements['webform']['#form']['#action']?>" method="<?=$elements['webform']['#form']['#method']?>">
            <?php
            $form = $elements['webform']['#form'];
            $formFields = $form['submitted'];
            foreach ($node->webform['components'] as $componnent) {
                $formItem = $formFields[$componnent['form_key']];
                $formItem['#title_display'] = "invisible";
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
