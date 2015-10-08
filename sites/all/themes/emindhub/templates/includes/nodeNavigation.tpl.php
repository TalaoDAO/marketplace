<?php if (isset($variables['linkBack']) || isset($variables['linkPrev']) || isset($variables['linkNext'])) : ?>
<div class="row section">

  <?php if (isset($variables['linkBack'])) : ?>
  <div class="col-sm-3 to-list">
    <a href="<?php print base_path() . $variables['linkBack']['href']; ?>" <?php print drupal_attributes($variables['linkBack']['attributes']); ?>>
      <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span> <?php print $variables['linkBack']['title']; ?>
    </a>
  </div>
  <?php endif; ?>

  <?php if ($variables['linkPrev']) : ?>
  <div class="col-sm-3 col-sm-offset-3 col-xs-6 previous text-right">
    <a href="<?php print base_path() . $variables['linkPrev']['href']; ?>" <?php print drupal_attributes($variables['linkPrev']['attributes']); ?>>
      <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span> <?php print $variables['linkPrev']['title']; ?>
    </a>
  </div>
  <?php endif; ?>

  <?php if ($variables['linkNext']) : ?>
  <div class="col-sm-3 col-xs-6 next pull-right">
    <a href="<?php print base_path() . $variables['linkNext']['href']; ?>" <?php print drupal_attributes($variables['linkNext']['attributes']); ?>>
      <?php print $variables['linkNext']['title']; ?> <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
    </a>
  </div>
  <?php endif; ?>

</div>
<?php endif; ?>
