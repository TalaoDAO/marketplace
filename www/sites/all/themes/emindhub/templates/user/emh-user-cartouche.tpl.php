<div class="user-cartouche">
  <div class="cartouche-identity">
    <span class="user-identity">
      <?php if ($user_profile_link) : ?>
      <a href="<?php print $user_profile_link; ?>">
        <?php print $identity; ?>
      </a>
      <?php else : ?>
        <?php print $identity; ?>
      <?php endif; ?>
    </span>

    <span class="user-badge">
      <?php if ($user_profile_link) : ?>
      <a href="<?php print $user_profile_link; ?>">
        <?php print $photo; ?>
      </a>
      <?php else : ?>
        <?php print $photo; ?>
      <?php endif; ?>
    </span>

    <?php if ($organisation) : ?>
    <span class="user-organisation">
      <?php print render($organisation); ?>
    </span>
    <?php endif; ?>

    <?php if ($activity) : ?>
    <span class="user-activity">
      <?php print render($activity); ?>
    </span>
    <?php endif; ?>

    <?php if ($address) : ?>
    <span class="user-address">
      <?php print render($address); ?>
    </span>
    <?php endif; ?>

    <?php if ($mail) : ?>
    <span class="user-mail">
      <?php print render($mail); ?>
    </span>
    <?php endif; ?>

    <?php if ($user_purchase_link) : ?>
    <a href="<?php print $user_purchase_link; ?>" class="user-buy-access">
      <?php print t('Access profile for !amount credits', array('!amount' => $amount)); ?>
    </a>
    <?php endif; ?>
  </div>

  <div class="cartouche-activity">
    <span class="user-submission-count" title="<?php print t('!count published answer(s)', array('!count' => $submission_count)); ?>">
      <?php print $submission_count; ?>
    </span>

    <span class="user-purchased-count" title="<?php print t('Profile purchased !count times', array('!count' => $purchased_count)); ?>">
      <?php print $purchased_count; ?>
    </span>
  </div>
</div>
