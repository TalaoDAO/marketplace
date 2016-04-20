<?php if (!empty($variables['linkBack']) || !empty($variables['linkPrev']) || !empty($variables['linkNext']) || !empty($variables['flag_my_selection'])) : ?>
<div id="request-nav">

  <div id="nav-back">
    <?php if (!empty($variables['linkBack'])) : ?>
    <a href="<?php print base_path() . $variables['linkBack']['href']; ?>" <?php print drupal_attributes($variables['linkBack']['attributes']); ?>>
      <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span> <?php print $variables['linkBack']['title']; ?>
    </a>
    <?php endif; ?>
  </div>

  <div id="nav-previous">
    <?php if (!empty($variables['linkPrev'])) : ?>
    <a href="<?php print base_path() . $variables['linkPrev']['href']; ?>" <?php print drupal_attributes($variables['linkPrev']['attributes']); ?>>
      <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span> <?php print $variables['linkPrev']['title']; ?>
    </a>
    <?php endif; ?>
  </div>

  <div id="nav-next">
    <?php if (!empty($variables['linkNext'])) : ?>
    <a href="<?php print base_path() . $variables['linkNext']['href']; ?>" <?php print drupal_attributes($variables['linkNext']['attributes']); ?>>
      <?php print $variables['linkNext']['title']; ?> <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
    </a>
    <?php endif; ?>
  </div>

  <div id="flag-selection">
    <?php if (!empty($variables['flag_my_selection'])) : ?>
    <?php print $variables['flag_my_selection']['title']; ?>
    <?php endif; ?>
  </div>

</div>
<?php endif; ?>
