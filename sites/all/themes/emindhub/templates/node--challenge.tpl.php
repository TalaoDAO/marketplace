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
<?php if (!$variables['teaser']): ?>
    <div class="row">
        <div class="col-md-4 challenge-title"><?php echo t("Answer to a challenge"); ?></div>
        <div class="col-md-8"><hr class="hr-light"></div>
    </div>
    <div class="row light-grey-background paddingUD title-wrapper">
        <div class="col-md-3">
            <div class="challenge-to-list">
                <a><?php print t("Back to challenges"); ?></a>
            </div>
        </div>
        <div class="col-md-3 col-md-offset-3">
            <div class="challenge-previous">
                <a>Previous challenge</a>
            </div>
        </div>
        <div class="col-md-3">
            <div class="challenge-next">
                <a>Next challenge</a>
            </div>
        </div>
    </div>

    <!--<div class="row light-grey-background paddingUD title-wrapper challenge-state-row">
    <div class="col-md-4 challenge-state-selected"><a><?php print t("Open"); ?></a></div>
    <div class="col-md-4 challenge-state"><a><?php print t("Selection"); ?></a></div>
    <div class="col-md-4 challenge-state"><a><?php print t("Closed"); ?></a></div>
</div>-->

    <div class="row paddingLR challenge-container">
        <div class="col-md-12">
            <h2><?php print $title; ?></h2>
            <br />
            <div class="row">
                <div class="col-md-5">
                    <div><?php print t("Domain(s):"); ?></div>
                    <div class="challenge-domain softPaddingUD paddingL"><?php print $field_domaine[0]['taxonomy_term']->name; ?></div>
                    <div><?php print t("Submitted by:"); ?></div>
                    <div class="dark-blue-text bold"><?php print $variables['name']; ?></div>
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
                        <div class="col-md-6"><?php print t("Deadline:"); ?></div>
                        <div class="col-md-6  bold"><?php print $content['field_expiration_date']['#items'][0]['value']; ?></div>
                    </div>
                    <div class="row">
                        <div class="col-md-6"><?php print t("Number of responses:"); ?></div>
                        <div class="col-md-6  bold"><?php print $comment_count; ?></div>
                    </div>
                    <div class="row">
                        <div class="col-md-6"><?php print t("Award:"); ?></div>
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
            <div>
                <?php print t("Company description:"); ?>
            </div>
            <div class="challenge-company-description">
                <?php
                if (false && isset($field_use_my_entreprise) && $field_use_my_entreprise[0]['value']) {
                    print $field_entreprise_description[0]['value'];
                } else {
                    print $company_description; //emindhub_preprocess_node__challenge
                }
                ?>
            </div>
            <div class="challenge-tag-container">
                <?php
                foreach ($variables['elements']['field_tags']['#items'] as $tag) {
                    print sprintf('<span class="challenge-tag">%s</span>', $tag['taxonomy_term']->name);
                } ?>
            </div>
            <hr class="hr-light-grey">
            <div class="challenge-detail">
                <?php if ($body && $body[0]): ?>
                    <?php print $body[0]['safe_value']; ?>
                <?php endif; ?>
            </div>
            <!--<div ><?php print render($content['field_reward']); ?> </div>
        <h2><?php echo $content['field_reward']['#object']->title ;?></h2>
        <?php print "=====================================================================================================================<br>"; ?>
        <?php print render($content); ?>-->
        </div>
    </div>

    <div class="row light-grey-background paddingUD title-wrapper challenge-state-row">
        <div class="col-md-4"><?php print $elements['links']['flag']['#links']['flag-my_selection']['title']; ?></div>
        <div class="col-md-4"><?php print l(t("Create a working group"), "node/add/working-group", array('attributes' => array('class' => array('btn', 'btn-primary', 'btn-workgroup')))); ?></div>
        <?php $linkAddComment = $elements['links']['comment']['#links']['comment-add']; ?>
        <div class="col-md-4"><?php print l($linkAddComment['title'], $linkAddComment['href'], array('attributes' => array('class' => array('btn', 'btn-primary', 'btn-expert')))); ?></div>
    </div>
<?php endif; ?>
