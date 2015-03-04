<?php if ($variables['teaser']): ?>
    <!-- $variables['zebra'] even/odd -->
    <?php if ($variables['first']): ?>
        <div class="row paddingUD">
            <div class="col-md-3 light-blue-text bold">
                <h2><?php print l(t("My articles"), "./my-articles"); ?></h2>
            </div>
            <div class="col-md-9"><hr class="hr-light"></div>
        </div>
    <?php endif; ?>
    <div class="row table-content table-expert">
        <div class="col-md-1">
            <?php if (isset($field_picto) && isset($field_picto['und'][0]['uri']) ): ?>
                <img src="<?php echo file_create_url($field_picto['und'][0]['uri']); ?>" />
            <?php else: ?>
                <img style="height: 20px; width: 20px;" src="<?php echo url(imagePath("blogPostIcon.png")); ?>" />
            <?php endif; ?>
        </div>

        <!--<div class="col-md-3"><?php print $variables['title']; ?></div>-->
        <div class="col-md-3"><?php print l($variables['title'], '.'.$variables['node_url']); ?></div>
        <!--<div class="col-md-3"><a href="<?php print url('.'.$variables['node_url']); ?>"><?php print $variables['title']; ?></a></div>-->
        <div class="col-md-2"><?php print $variables['date']; ?></div>
        <div class="col-md-2">
            <?php if (isset($variables['field_expiration_date']['und'][0])): ?>
                <?php print $variables['field_expiration_date']['und'][0]['value']; ?>
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
    <?php print render($content); ?>
<?php endif; ?>
