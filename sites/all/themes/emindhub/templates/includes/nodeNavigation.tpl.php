<?php if (!empty($variables['linkBack']) || !empty($variables['linkPrev']) || !empty($variables['linkNext'])) : ?>
<div class="row section">

  <?php if (!empty($variables['linkBack'])) : ?>
  <div class="col-sm-3 nav-back">
    <a href="<?php print base_path() . $variables['linkBack']['href']; ?>" <?php print drupal_attributes($variables['linkBack']['attributes']); ?>>
      <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span> <?php print $variables['linkBack']['title']; ?>
    </a>
  </div>
  <?php endif; ?>

  <?php if (!empty($variables['linkPrev'])) : ?>
  <div class="col-sm-3 col-sm-offset-3 col-xs-6 nav-previous text-right">
    <a href="<?php print base_path() . $variables['linkPrev']['href']; ?>" <?php print drupal_attributes($variables['linkPrev']['attributes']); ?>>
      <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span> <?php print $variables['linkPrev']['title']; ?>
    </a>
  </div>
  <?php endif; ?>

  <?php if (!empty($variables['linkNext'])) : ?>
  <div class="col-sm-3 col-xs-6 nav-next pull-right">
    <a href="<?php print base_path() . $variables['linkNext']['href']; ?>" <?php print drupal_attributes($variables['linkNext']['attributes']); ?>>
      <?php print $variables['linkNext']['title']; ?> <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
    </a>
  </div>
  <?php endif; ?>

</div>
<?php endif; ?>
