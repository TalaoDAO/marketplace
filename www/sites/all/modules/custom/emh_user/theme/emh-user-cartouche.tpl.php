<?php if ($user_profile_link) : ?>
  <a href="<?php print $user_profile_link; ?>">
    <?php print $photo; ?>
  </a>
<?php else : ?>
  <?php print $photo; ?>
<?php endif; ?>

<?php if ($user_profile_link) : ?>
  <a href="<?php print $user_profile_link; ?>">
    <?php print $identity; ?>
  </a>
<?php else : ?>
  <?php print $identity; ?>
<?php endif; ?>

<?php if ($organisation) : ?>
  <?php print render($organisation); ?>
<?php endif; ?>

<?php if ($activity) : ?>
  <?php print render($activity); ?>
<?php endif; ?>

<?php if ($address) : ?>
  <?php print render($address); ?>
<?php endif; ?>

<?php if ($mail) : ?>
  <?php print render($mail); ?>
<?php endif; ?>

<?php if ($user_purchase_link) : ?>
<a href="<?php print $user_purchase_link; ?>">
  <?php print t('Access profile for !amount credits', array('!amount' => $amount)); ?>
</a>
<?php endif; ?>

<?php print $submission_count; ?>

<?php print $purchased_count; ?>
