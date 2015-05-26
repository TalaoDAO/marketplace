<div class="row">
    <div class="col-md-4 challenge-title"><?php echo c_szAnswerChallenge; ?></div>
    <div class="col-md-8"><hr class="hr-light"></div>
</div>
<?php

if (isset($variables['elements']['links']['views_navigation'])) {
    $linkBack = $variables['elements']['links']['views_navigation']['#links']['back'];
    $linkPrev = $variables['elements']['links']['views_navigation']['#links']['previous'];
    $linkNext = $variables['elements']['links']['views_navigation']['#links']['next'];
}
if (isset($linkBack) && isset($linkPrev) && isset($linkNext)) { ?>
    <div>
        <div class="row light-grey-background paddingUD paddingLR title-wrapper">
            <div class="col-sm-3">
                <div class="challenge-to-list">
                    <?php
                    print "<a href='" . base_path().$linkBack['href'] . "' " . drupal_attributes($linkBack['attributes']) . ">" . $linkBack['title']."</a>";
                    ?>
                </div>
            </div>
            <div class="col-sm-3 col-sm-offset-3">
                <div class="challenge-previous">
                    <?php
                    print "<a href='" . base_path().$linkPrev['href'] . "' " . drupal_attributes($linkPrev['attributes']) . ">" . $linkPrev['title']."</a>";
                    ?>
                </div>
            </div>
            <div class="col-sm-3">
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
                <div class="row">
                    <div class="col-md-12 col-sm-6">
                        <div><?php print $elements['field_domaine']['#title']; ?></div>
                        <div class="challenge-domain softPaddingUD paddingL">
                            <?php if (isset($field_domaine)):
                                foreach ($field_domaine as $domain) {
                                    print $domain['taxonomy_term']->name . "<br>";
                                }
                            endif; ?>
                        </div>
                    </div>
                    <div class="col-md-12 col-sm-6 user-informations">
                        <?php require_once __DIR__ . '/includes/userInformations.tpl.php'; ?>
                    </div>
                </div>
            </div>
            <div class="col-md-4 col-sm-7">
                <div class="row">
                    <div class="col-xs-7"><?php print $content['field_autoref']['#title']; ?></div>
                    <div class="col-xs-5  bold"><?php print $content['field_autoref']['#items'][0]['value']; ?></div>
                </div>
                <div class="row">
                    <div class="col-xs-7"><?php print c_szPublicationDt; ?></div>
                    <!--<div class="col-md-6  bold"><?php //print format_date($elements['#node']->created, 'custom', 'm/d/Y'); ?></div>-->
                    <div class="col-xs-5  bold"><?php print format_date($elements['#node']->created, 'custom', 'm/d/Y'); ?></div>
                </div>
                <div class="row">
                    <div class="col-xs-7"><?php print $content['field_expiration_date']['#title']; ?></div>
                    <div class="col-xs-5  bold"><?php
                        print date('m/d/Y', strtotime($content['field_expiration_date']['#items'][0]['value'])); ?></div>
                </div>
                <div class="row">
                    <div class="col-xs-7"><?php print c_szNumResponses; ?></div>
                    <div class="col-xs-5  bold"><?php print $comment_count; ?></div>
                </div>
                <div class="row">
                    <div class="col-xs-7"><?php print $content['field_reward']['#title']; ?></div>
                    <div class="col-xs-5 bold"><?php print $content['field_reward']['#items'][0]['value']; ?></div>

                </div>
            </div>
            <div class="col-md-3">
                <?php if (isset($node->field_image)) { ?>
                    <?php
//                    ddl(get_defined_vars());
                    $img_url = $node->field_image[LANGUAGE_NONE][0]['uri'];  // the orig image uri
                    $style = 'medium';  // or any other custom image style you've created via /admin/config/media/image-styles
                    ?>
                    <img src="<?php print image_style_url($style, $img_url); ?>" />

                <?php
                }  ?>
            </div>
        </div>
        <?php require_once __DIR__ . '/includes/companyDescription.tpl.php'; ?>
        <?php require_once __DIR__ . '/includes/tagsField.tpl.php'; ?>
        <hr class="hr-light-grey">
        <div class="challenge-detail">
            <?php if ($body && $body[0]): ?>
                <?php print $body[0]['value']; ?>
            <?php endif; ?>
        </div>
    </div>
</div>

<div class="row light-grey-background paddingUD title-wrapper challenge-state-row">
    <div class="col-sm-4 my-selection"><?php print $elements['links']['flag']['#links']['flag-my_selection']['title']; ?></div>
    <div class="col-sm-3 create-workgroup"><?php print l(c_szCreateWorkgroup, "node/add/working-group", array('attributes' => array('class' => array('btn', 'btn-primary', 'btn-workgroup')))); ?></div>
    <?php $linkAddComment = $elements['links']['comment']['#links']['comment-add'];
    if ($linkAddComment) { ?>
        <div class="col-sm-3 col-sm-offset-2"><?php print l($linkAddComment['title'], $linkAddComment['href'], array('attributes' => array('class' => array('btn', 'btn-primary', 'btn-expert')))); ?></div>
    <?php } ?>
</div>