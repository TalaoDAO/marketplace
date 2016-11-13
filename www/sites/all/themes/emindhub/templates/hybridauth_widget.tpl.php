<p class="reg-option">
  <span class="line-wrapper">
    <span class="line"></span>
  </span>
  <span class="content">
    <span><?php print t('or'); ?></span>
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
