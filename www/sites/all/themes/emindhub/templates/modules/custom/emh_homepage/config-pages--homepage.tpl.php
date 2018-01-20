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

ddl($content);
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
    <?php print render($content['field_hp_solutions_title']); ?>
    <?php print render($content['field_hp_solutions_slides_blue']); ?>
    <?php print render($content['field_hp_solutions_link']); ?>
    <?php print render($content['field_hp_solutions_slides_orange']); ?>
  </div>
</div>

<div class="container-fluid hp-testimonies">
  <?php print render($content['field_hp_testimonies']); ?>
</div>

<div class="container-fluid hp-why">
  <div class="container">
    <?php print render($content['field_hp_why_title']); ?>
    <?php print render($content['field_hp_why_need']); ?>
    <?php print render($content['field_hp_why_need_slides']); ?>
    <?php print render($content['field_hp_why_have']); ?>
    <?php print render($content['field_hp_why_have_slides']); ?>
  </div>
</div>

<div class="container-fluid hp-how">
  <div class="container">
    <?php print render($content['field_hp_how_title']); ?>
    <?php print render($content['field_hp_how_need']); ?>
    <?php print render($content['field_hp_how_need_slides']); ?>
    <?php print render($content['field_hp_how_have']); ?>
    <?php print render($content['field_hp_how_have_slides']); ?>
    <?php print render($content['field_hp_how_have_text']); ?>
  </div>
</div>
