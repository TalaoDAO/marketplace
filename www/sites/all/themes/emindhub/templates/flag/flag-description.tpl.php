<?php if (!empty($short) || !empty($long)) : ?>
  <span class="submission-flag-description">
    <?php print $short; ?><?php if (!empty($short) && !empty($long)) : ?>&nbsp;<?php endif; ?><?php print $long; ?>
  </span>
<?php endif; ?>
