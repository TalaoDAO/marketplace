<?php

/**
 * @file
 * Template.
 *
 * $content => access all fields values.
 * render($content) => renders all fields.
 * $content['field_hp_hero_title'] => access all hp hero title fields.
 * render($content['field_hp_hero_title']) => renders the hp hero title fields.
 */
?>

<div class="container-fluid hp-hero">
  <div class="container">
    <?php print render($content['field_hp_hero_title']); ?>
    <?php print render($content['field_hp_hero_link']); ?>
    <?php print render($content['field_hp_hero_experts']); ?>
  </div>
</div>

<div class="container-fluid hp-domains">
  <div class="container">
    <?php print render($content['field_hp_domains_title']); ?>
    <?php print render($content['field_hp_domains']); ?>
    <?php print render($content['field_hp_domains_link']); ?>
  </div>
</div>

<div class="container-fluid hp-clients">
  <?php print render($content['field_hp_clients']); ?>
</div>

<div class="container-fluid hp-solutions">
  <div class="container">
    <div class="row">
      <div class="col-xs-12">
        <?php print render($content['field_hp_solutions_title']); ?>
      </div>
    </div>
    <div class="row">
      <div class="col-xs-12 col-sm-9">
        <?php print render($content['field_hp_solutions_slides_blue']); ?>
        <?php print render($content['field_hp_solutions_link']); ?>
      </div>
      <div class="col-xs-12 col-sm-3">
        <?php print render($content['field_hp_solutions_slides_orange']); ?>
      </div>
    </div>
  </div>
</div>

<div class="container-fluid hp-testimonies">
  <?php print render($content['field_hp_testimonies']); ?>
</div>

<div class="container-fluid hp-why">
  <div class="container">
    <?php print render($content['field_hp_why_title']); ?>
    <ul class="nav nav-tabs" role="tablist">
      <li role="presentation" class="active"><a href="#why-need" aria-controls="why-need" role="tab" data-toggle="tab"><?php print t('You need expertise'); ?></a></li>
      <li role="presentation"><a href="#why-have" aria-controls="why-have" role="tab" data-toggle="tab"><?php print t('You have expertise'); ?></a></li>
    </ul>
    <div class="tab-content">
      <div role="tabpanel" class="tab-pane active" id="why-need">
        <?php print render($content['field_hp_why_need_slides']); ?>
      </div>
      <div role="tabpanel" class="tab-pane" id="why-have">
        <?php print render($content['field_hp_why_have_slides']); ?>
      </div>
    </div>
  </div>
</div>

<div class="container-fluid hp-how">
  <div class="container">
    <?php print render($content['field_hp_how_title']); ?>
    <ul class="nav nav-tabs" role="tablist">
      <li role="presentation" class="active"><a href="#how-need" aria-controls="how-need" role="tab" data-toggle="tab"><?php print t('You need expertise'); ?></a></li>
      <li role="presentation"><a href="#how-have" aria-controls="how-have" role="tab" data-toggle="tab"><?php print t('You have expertise'); ?></a></li>
    </ul>
    <div class="tab-content">
      <div role="tabpanel" class="tab-pane active" id="how-need">
        <?php print render($content['field_hp_how_need_slides']); ?>
      </div>
      <div role="tabpanel" class="tab-pane" id="how-have">
        <?php print render($content['field_hp_how_have_slides']); ?>
        <?php print render($content['field_hp_how_have_text']); ?>
      </div>
    </div>
  </div>
</div>
