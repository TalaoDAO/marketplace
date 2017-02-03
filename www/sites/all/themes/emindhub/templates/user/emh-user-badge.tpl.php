<div class="user-badge">
  <span  class="user-photo">
    <?php if ($user_profile_link) : ?>
    <a href="<?php print $user_profile_link; ?>" alt="<?php print $identity; ?>" title="<?php print $identity; ?>">
      <?php print $photo; ?>
    </a>
    <?php else : ?>
      <?php print $photo; ?>
    <?php endif; ?>
  </span>
</div>
