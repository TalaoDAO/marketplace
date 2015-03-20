<?php if ($variables['teaser']): ?>
    <!-- $variables['zebra'] even/odd -->
    <?php if ($variables['first']): ?>
        <div class="row paddingUD">
            <div class="col-md-3 light-blue-text bold">
                <h2><?php print t("My challenges"); ?></h2>
            </div>
            <div class="col-md-9"><hr class="hr-light"></div>
        </div>
    <?php endif; ?>
    <div class="row table-content table-expert">
        <div class="col-md-1">
            <img src="<?php echo file_create_url($field_picto[LANGUAGE_NONE][0]['uri']); ?>" />
        </div>
        <div class="col-md-3"><?php print l($variables['title'], '.'.$variables['node_url']); ?></div>
        <!--<div class="col-md-3"><?php print $variables['title']; ?></div>-->
        <div class="col-md-2"><?php print $variables['date']; ?></div>
        <div class="col-md-2">
            <?php if (isset($variables['field_expiration_date'][LANGUAGE_NONE][0])): ?>
                <?php print $variables['field_expiration_date'][LANGUAGE_NONE][0]['value']; ?>
            <?php endif; ?>
        </div>
        <div class="col-md-2">Nom du cercle</div>
        <div class="col-md-1">
            <?php if (isset($variables['field_reward'][LANGUAGE_NONE][0]['value'])): ?>
                <?php print $variables['field_reward'][LANGUAGE_NONE][0]['value']; ?>
            <?php endif; ?>
        </div>
        <div class="col-md-1">12</div>
    </div>
<?php endif; ?>
<?php if (!$variables['teaser']):
    //ddl($variables['elements']['links']['views_navigation']['#links']);
    ?>
    <div class="row">
        <div class="col-md-4 challenge-title"><?php echo t("Answer to a challenge"); ?></div>
        <div class="col-md-8"><hr class="hr-light"></div>
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

    <div class="row paddingLR challenge-container">
        <div class="col-md-12">
            <h2><?php print $title; ?></h2>
            <br />
            <div class="row">
                <div class="col-md-5">
                    <div><?php print $elements['field_domaine']['#title']; ?></div>
                    <div class="challenge-domain softPaddingUD paddingL">
                        <?php if (isset($field_domaine)):
                            foreach ($field_domaine as $domain) {
                                print $domain['taxonomy_term']->name . "<br>";
                            }
                        endif; ?>
                    </div>
                    <?php if (isset($field_anonymous[0]['value']) && $field_anonymous[0]['value'] == 1) { ?>
                        <div><?php print t("Submitted by:"); ?></div>
                        <div class="dark-blue-text bold"><?php print $variables['name']; ?></div>
                    <?php } ?>
                </div>
                <div class="col-md-4">
                    <div class="row">
                        <div class="col-md-6"><?php print $content['field_autoref']['#title']; ?></div>
                        <div class="col-md-6  bold"><?php print $content['field_autoref']['#items'][0]['value']; ?></div>
                    </div>
                    <div class="row">
                        <div class="col-md-6"><?php print t("Publication date:"); ?></div>
                        <!--<div class="col-md-6  bold"><?php //print format_date($elements['#node']->created, 'custom', 'm/d/Y'); ?></div>-->
                        <div class="col-md-6  bold"><?php print format_date($elements['#node']->created, 'short'); ?></div>
                    </div>
                    <div class="row">
                        <div class="col-md-6"><?php print $content['field_expiration_date']['#title']; ?></div>
                        <div class="col-md-6  bold"><?php
                            print $content['field_expiration_date']['#items'][0]['value']; ?></div>
                    </div>
                    <div class="row">
                        <div class="col-md-6"><?php print t("Number of responses:"); ?></div>
                        <div class="col-md-6  bold"><?php print $comment_count; ?></div>
                    </div>
                    <div class="row">
                        <div class="col-md-6"><?php print $content['field_reward']['#title']; ?></div>
                        <div class="col-md-6 bold"><?php print $content['field_reward']['#items'][0]['value']; ?></div>

                    </div>
                </div>
                <div class="col-md-3">
                    <?php if (isset($field_image)) { ?>
                        <?php
                        $img_url = $node->field_image[LANGUAGE_NONE][0]['uri'];  // the orig image uri
                        $style = 'medium';  // or any other custom image style you've created via /admin/config/media/image-styles
                        ?>
                        <img src="<?php print image_style_url($style, $img_url); ?>" />

                    <?php
                    }  ?>
                </div>
            </div>
            <?php //require_once __DIR__ . '/includes/companyDescription.tpl.php'; ?>
            <?php
            if (isset($field_anonymous[0]['value']) && $field_anonymous[0]['value'] == 1) { ?>
                <div>
                    <?php print $content['field_entreprise_description']['#title']; ?>
                </div>
                <div class="challenge-company-description">
                    <?php
                    if (isset($field_use_my_entreprise) && $field_use_my_entreprise[0]['value'] != 0) {
                        print $field_entreprise_description[0]['value'];
                    } else{
                        print $company_description; //emindhub_preprocess_node__challenge
                    }
                    ?>
                </div>
            <?php } ?>
            <?php require_once __DIR__ . '/includes/tagsField.tpl.php'; ?>
            <hr class="hr-light-grey">
            <div class="challenge-detail">
                <?php if ($body && $body[0]): ?>
                    <?php print $body[0]['safe_value']; ?>
                <?php endif; ?>
            </div>
        </div>
    </div>

    <div class="row light-grey-background paddingUD title-wrapper challenge-state-row">
        <div class="col-md-4"><?php print $elements['links']['flag']['#links']['flag-my_selection']['title']; ?></div>
        <div class="col-md-4"><?php print l(t("Create a working group"), "node/add/working-group", array('attributes' => array('class' => array('btn', 'btn-primary', 'btn-workgroup')))); ?></div>
        <?php $linkAddComment = $elements['links']['comment']['#links']['comment-add']; ?>
        <div class="col-md-4"><?php print l($linkAddComment['title'], $linkAddComment['href'], array('attributes' => array('class' => array('btn', 'btn-primary', 'btn-expert')))); ?></div>
    </div>
<?php endif; ?>
