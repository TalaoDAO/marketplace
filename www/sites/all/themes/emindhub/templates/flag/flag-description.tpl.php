<?php if (!empty($short) || !empty($message)) : ?>
  <span class="submission-flag-description">
    <?php print $short; ?><?php if (!empty($short) && !empty($message)) : ?>&nbsp;<?php endif; ?><?php print $message; ?>
  </span>
<?php endif; ?>
