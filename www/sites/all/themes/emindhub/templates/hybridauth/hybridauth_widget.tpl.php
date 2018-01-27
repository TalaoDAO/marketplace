<p class="reg-option">
  <span class="content">
    <span><?php print t('or'); ?></span>
  </span>
  <span class="line-wrapper">
    <span class="line"></span>
  </span>
</p>
<div class="hybridauth-widget-wrapper"><?php
  print theme('item_list',
    array(
      'items' => $providers,
      // 'title' => $element['#title'],
      'type' => 'ul',
      'attributes' => array('class' => array('hybridauth-widget social-links')),
    )
  );
?></div>
