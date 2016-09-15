<?php
global $base_url;
$front_theme = path_to_theme();
$front_theme = $base_url . '/' . $front_theme;
?>
<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="container">

    <div class="row">

      <div class="image">
        <img alt="<?php print t('Services to communities'); ?>" class="center-block" src="<?php print $front_theme; ?>/images/content/block/eMindHub_Services-to_communities.jpg" />
      </div>

      <div class="steps">
        <p class="step">
          <span class="numbering"><span>1</span></span>
          <span class="text"><?php print t('Post your <strong>request</strong>, it\'s <strong>free</strong>'); ?></span>
        </p>
        <p class="step">
          <span class="numbering"><span>2</span></span>
          <span class="text"><?php print t('Add <strong>options</strong> to get the <strong>most</strong> from your request and ensure <strong>confidentiality</strong>'); ?></span>
        </p>
        <p class="step">
          <span class="numbering"><span>3</span></span>
          <span class="text"><?php print t('<strong>Access expert profiles</strong> on the basis of the <strong>quality</strong> of their responses'); ?></span>
        </p>
      </div>

    </div>

    <?php //print $content; ?>
  </div>

</section> <!-- /.block -->
