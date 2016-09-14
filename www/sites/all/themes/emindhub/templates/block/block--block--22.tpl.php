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

      <div class="text">
        <ol>
          <li><?php print t('Post your request, it\'s <strong>free</strong>'); ?></li>
          <li><?php print t('Add options to <strong>get the most from your request</strong> and <strong>ensure confidentiality</strong>'); ?></li>
          <li><?php print t('<strong>Access expert profiles</strong> on the basis of the <strong>quality</strong> of their responses'); ?></li>
        </ol>
      </div>

    </div>

    <?php //print $content; ?>
  </div>

</section> <!-- /.block -->
