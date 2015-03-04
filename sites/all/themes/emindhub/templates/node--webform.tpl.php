<?php if ($variables['teaser']): ?>
    <?php if ($variables['first']): ?>
        <div class="row paddingUD">
            <div class="col-md-3 light-blue-text bold">
                <h2><?php print t("My expert calls"); ?></h2>
            </div>
            <div class="col-md-9"><hr class="hr-light"></div>
        </div>
    <?php endif; ?>
    <div class="row table-content table-expert">
        <div class="col-md-1"><img src="<?php echo file_create_url($field_picto['und'][0]['uri']); ?>" /></div>
        <!--<div class="col-md-3"><?php print $variables['title']; ?></div>-->
        <div class="col-md-3"><?php print l($variables['title'], '.'.$variables['node_url']); ?></div>
        <div class="col-md-2"><?php print $variables['date']; ?></div>
        <div class="col-md-2">
            <?php if (isset($variables['field_duration_of_the_mission'][0])): ?>
                <?php print $variables['field_duration_of_the_mission'][0]['value']; ?>
            <?php endif; ?>
        </div>
        <div class="col-md-2">Nom du cercle</div>
        <div class="col-md-1">
            <?php if (isset($variables['field_reward'][0])): ?>
                <?php print $variables['field_reward'][0]['value']; ?>
            <?php endif; ?>
        </div>
        <div class="col-md-1">12</div>
    </div>
<?php endif; ?>
<?php if (!$variables['teaser']): ?>
<div class="paddingLR">
    <div class="row">
        <div class="col-md-4 challenge-title"><?php echo t("Answer to an expert call"); ?></div>
        <div class="col-md-8"><hr class="hr-light"></div>
    </div>

    <div class="row light-grey-background paddingUD title-wrapper">
        <div class="col-md-3">
            <div class="challenge-to-list">
                <a><?php print t("Back to calls"); ?></a>
            </div>
        </div>
        <div class="col-md-3 col-md-offset-3">
            <div class="challenge-previous">
                <a><?php print t("Previous call"); ?></a>
            </div>
        </div>
        <div class="col-md-3">
            <div class="challenge-next"><a><?php print t("Next call"); ?></a></div>
        </div>
    </div>
</div>

<div class="paddingLR challenge-container">
    <div class="row">
        <div class="col-md-12">
            <h2><?php print $title; ?></h2>
            <br />
        </div>
    </div>
    <div class="row">
        <div class="col-md-4">
            <?php print t("Submitted by:"); ?>
            <div class="row">
                <div class="col-md-3 profile-picture"><?php print $variables['user_picture']; ?></div>
                <div class="col-md-9">
                    <div class="bold"><?php //print $variables['user_name']; ?></div>
                    <div class="bold"><?php print $variables['name']; ?></div>
                    <div class="bold light-blue-text">Nom Entreprise</div>
                </div>
            </div>
        </div>
        <div class="col-md-4">
            <?php print t("Domain(s):"); ?>
            <div class="challenge-domain softPaddingUD paddingL">
                <?php if (isset($field_domaine[0]['taxonomy_term']->name)): ?>
                    <?php print $field_domaine[0]['taxonomy_term']->name; ?>
                <?php endif; ?>
            </div>
        </div>
        <div class="col-md-4">
            <div class="row">
                <div class="col-md-6"><?php print t("Expert call Ref:"); ?></div>
                <div class="col-md-6  bold"></div>
            </div>
            <div class="row">
                <div class="col-md-6"><?php print t("Publication date:"); ?></div>
                <div class="bold">
                    <?php if (isset($elements['#node']->created)): ?>
                        <?php print $elements['#node']->created; ?>
                    <?php endif; ?>
                </div>
            </div>
            <div class="row">
                <div class="col-md-6"><?php print t("Desired starting date:"); ?></div>
                <div class="bold"><?php print $field_start_date[0]['value']; ?></div>
            </div>
            <div class="row">
                <div class="col-md-6"><?php print t("Number of responses:"); ?></div>
                <div class="bold"></div>
            </div>
            <div class="row">
                <div class="col-md-6"><?php print t("Mission duration:"); ?></div>
                <div class="bold"><?php print $field_reward[0]['safe_value']; ?></div>
            </div>
            <div class="row">
                <div class="col-md-6"><?php print t("Mission remuneration:"); ?></div>
                <div class="bold"></div>
            </div>
        </div>
    </div>
    <div class="row">
        <div class="col-md-3 bold paddingU"><?php print t("Company description:"); ?></div>
    </div>
    <div class="row">
        <div class="col-md-3 bold paddingU"><?php print t("Mission context description:"); ?></div>
    </div>
    <br>
    <div class="row">
        <div class="col-md-3 bold paddingU"><?php print t("Mission purpose:"); ?></div>
    </div>
    <div><?php print t("Keywords:"); ?></div>
    <div class="challenge-tag-container">
        <span class="challenge-tag">Interactions Homme Système</span>
        <span class="challenge-tag">Tags</span>
        <span class="challenge-tag">Tags</span>
        <span class="challenge-tag">Nuage de tag</span>
    </div>
    <div class="row paddingUD">
        <div class="col-md-4">
            <button class="btn btn-star"><?php print t("Save in my selection"); ?></button>
        </div>
        <div class="col-md-3 col-md-offset-5">
            <button class="btn btn-expert"><?php print t("Answer"); ?></button>
        </div>
    </div>
</div>
<?php endif; ?>
<!--
=====================================================================================<br>
<?php print render($content); ?>-->