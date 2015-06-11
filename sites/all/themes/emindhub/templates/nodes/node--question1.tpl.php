   <?php if (!user_has_role(5)): ?>
<div class="row expert-display">
    <div class="col-md-4 challenge-title"><?php echo c_szAnswerQuestion; ?></div>
    <div class="col-md-8"><hr class="hr-light"></div>
</div>
   <?php endif; ?>
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
    </div>
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
<div class="row paddingLR paddingUD challenge-container">
    <div class="row">
        <div class="col-md-4 col-sm-6">
            <?php require_once drupal_get_path('theme', 'emindhub').'/templates/includes/userInformations.tpl.php'; ?>
        </div>
        <div class="col-md-4 col-sm-6">
            <div class="bold"><?php if (isset($elements['field_domaine'])) print $elements['field_domaine']['#title']; ?></div>
            <div class="challenge-domain softPaddingUD paddingL">
                <?php if (isset($field_domaine)):
                    foreach ($field_domaine as $domain) {
                        if (isset($domain['taxonomy_term'])) print $domain['taxonomy_term']->name . "<br>";
                    }
                endif; ?>
            </div>&nbsp;
            <?php require_once drupal_get_path('theme', 'emindhub').'/templates/includes/tagsField.tpl.php'; ?>
        </div>
        <div class="col-md-4 col-sm-6">
            <div class="row">
                <div class="col-xs-7"><?php print c_szPublicationDt; ?></div>
                <div class="col-xs-5 bold">
                    <?php if (isset($elements['#node']->created)) {
                        print format_date($elements['#node']->created, 'short_date');
                    } ?>
                </div>
            </div>
            <div class="row">
                <div class="col-xs-7"><?php print $elements['field_expiration_date']['#title']; ?></div>
                <div class="col-xs-5 bold">
                    <?php if (isset($field_expiration_date[0]['value'])) {
                        print date('m/d/Y', strtotime($field_expiration_date[0]['value']));
                    } ?>
                </div>
            </div>
            <div class="row">
                <div class="col-xs-7"><?php print c_szNumResponses; ?></div>
                <div class="col-xs-5 bold"><?php print $comment_count; ?></div>
            </div>
            <div class="row">
                <div class="col-xs-7"><?php if ($elements['field_reward']) { print $elements['field_reward']['#title']; } ?></div>
                <div class="col-xs-5 bold">
                    <?php
                    if (isset($field_reward[0]['value'])): ?>
                        <?php print $field_reward[0]['value']; ?>
                    <?php endif; ?>
                </div>
            </div>
        </div>
    </div>
    <?php require_once drupal_get_path('theme', 'emindhub').'/templates/includes/companyDescription.tpl.php'; ?>
    <div class="paddingUD">
        <?php print $elements['links']['flag']['#links']['flag-my_selection']['title']; ?>
       &nbsp;&nbsp; <?php if (node_access('update',$node)) print l(t('Edit'),'node/'.$node->nid.'/edit', array('attributes' => array('class' => array('btn','btn-primary','btn-expert'))) ); ?>

    </div>
</div>
&nbsp;
<div class="row paddingLR challenge-container">
    <div class="row">
        <div class="col-md-12">
            <?php
            $formId = $elements['comments']['comment_form']['#form_id'];
            $formAction = $elements['comments']['comment_form']['#action'];
            $formMethod = $elements['comments']['comment_form']['#method'];
            ?>
            <form id="<?php print $formId; ?>" action="<?php print $formAction; ?>" method="<?php print $formMethod; ?>">
                <?php
                print render($elements['comments']['comment_form']['field_private_comment']);
                print render($element['comments']['comment_form']['subject']);
                print render($elements['comments']['comment_form']['comment_body']);
                print render($elements['comments']['comment_form']['field_private_comment_body']);
                $commentActions = $elements['comments']['comment_form']['actions'];
                $commentActions['submit']['#attributes']['class'][] = 'btn';
                $commentActions['submit']['#attributes']['class'][] = 'btn-send';
                $commentActions['draft']['#attributes']['class'][] = 'btn';
                $commentActions['draft']['#attributes']['class'][] = 'btn-draft';
                print render($commentActions);
                print render($elements['comments']['comment_form']['form_build_id']);
                print render($elements['comments']['comment_form']['form_token']);
                print render($elements['comments']['comment_form']['form_id']);
                unset($commentActions);
                unset($formId);
                unset($formAction);
                unset($formMethod);
                ?>
            </form>
        </div>
    </div>
    <div class="row">
        <div class="col-md-12">
            <?php
            print render($elements['comments']['comments']);
            ?>
        </div>
    </div>
</div>
<div class="paddingUD">
    <!--<div class="inline paddingR"><button class="btn btn-cancel"><?php //print t("Cancel"); ?></button></div>
    <div class="inline paddingR"><button class="btn btn-draft"><?php //print t("Save draft"); ?></button></div>-->
    <div class="inline">
        <?php /*$linkAddComment = $elements['links']['comment']['#links']['comment-add'];
        print l($linkAddComment['title'], $linkAddComment['href'], array('attributes' => array('class' => array('btn', 'btn-send'))));*/
        //print $elements['links']['comment']['#links']['comment-add']['title']; ?>
        <!--<button class="btn btn-send"><?php //print t("Send"); ?></button>-->
    </div>
</div>
