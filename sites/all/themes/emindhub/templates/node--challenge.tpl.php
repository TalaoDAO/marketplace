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
            <img src="<?php echo file_create_url($field_picto['und'][0]['uri']); ?>" />
        </div>
        <div class="col-md-3"><?php print l($variables['title'], '.'.$variables['node_url']); ?></div>
        <!--<div class="col-md-3"><?php print $variables['title']; ?></div>-->
        <div class="col-md-2"><?php print $variables['date']; ?></div>
        <div class="col-md-2">
            <?php if (isset($variables['field_expiration_date']['und'][0])): ?>
                <?php print $variables['field_expiration_date']['und'][0]['value']; ?>
            <?php endif; ?>
        </div>
        <div class="col-md-2">Nom du cercle</div>
        <div class="col-md-1">
            <?php if (isset($variables['field_reward']['und'][0]['value'])): ?>
                <?php print $variables['field_reward']['und'][0]['value']; ?>
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
                    <div class="col-md-6"><?php print t("Challenge Ref:"); ?></div>
                    <div class="col-md-6  bold"></div>
                </div>
                <div class="row">
                    <div class="col-md-6"><?php print t("Publication date:"); ?></div>
                    <div class="col-md-6  bold"><?php print $elements['#node']->created; ?></div>
                </div>
                <div class="row">
                    <div class="col-md-6"><?php print t("Deadline:"); ?></div>
                    <div class="col-md-6  bold"><?php print $content['field_expiration_date']['#items'][0]['value']; ?></div>
                </div>
                <div class="row">
                    <div class="col-md-6"><?php print t("Number of responses:"); ?></div>
                    <div class="col-md-6  bold"></div>
                </div>
                <div class="row">
                    <div class="col-md-6"><?php print t("Award:"); ?></div>
                    <div class="col-md-6 bold"><?php print $content['field_reward']['#items'][0]['value']; ?></div>

                </div>
            </div>
            <div class="col-md-3">
                <div style="border: 1px red solid; background-color: blue; height:214px; width: 214px;"></div>
            </div>
        </div>
        <div>
            <?php print t("Company description:"); ?>
        </div>
        <div class="challenge-company-description">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean euismod bibendum laoreet. Proin gravida dolor sit amet lacus accumsan et viverra justo commodo. Proin sodales pulvinar tempor. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Nam fermentum, nulla luctus pharetra vulputate, felis tellus mollis orci, sed rhoncus sapien nunc eget odio.</div>
        <div class="challenge-tag-container">
            <span class="challenge-tag">Interactions Homme Système</span>
            <span class="challenge-tag">Tags</span>
            <span class="challenge-tag">Tags</span>
            <span class="challenge-tag">Nuage de tag</span>
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
    <div class="col-md-4"><button class="btn btn-star">Sauvegarder dans mes sélections</button></div>
    <div class="col-md-4"><button class="btn btn-workgroup">Créer un groupe de travail</button></div>
    <div class="col-md-4 text-right"><button class="btn btn-expert">Répondre</button></div>
</div>
<?php endif; ?>
