<?php
  
  

/**
* @file
* Template file for LinkedIn "Position" item as displayed on user page
* Copy it to your theme's folder if you want to override it.
*
* Be sure to check and comply to  http://developer.linkedin.com/docs/DOC-1091 before tweaking.
*/
$position == $variables['position'];
?>
<div class="linkedin-position<?php ($position['is-current'] == TRUE) ? print ' linkedin-position-current' : ''; ?>">

  <h6>
    <?php ($position['is-current'] == TRUE) ? print t('Currently') . ' ' : ''; ?>
    <?php if ($position['title']) : ?>
    <?php print $position['title']; ?>
    <?php endif; ?>
    <?php if ($position['company']['name']) : ?>
    <?php ($position['is-current'] == TRUE) ? print t('at') . ' ' : print t('At') . ' '; ?>
    <?php print $position['company']['name'] ?>
    <?php endif; ?>
  </h6>

<p>
  <?php if ($position['start-date']['year']) : ?>
  <?php if ($position['end-date']['year']) : ?>
  <?php print t('From') . ' '; ?>
  <?php else : ?>
  <?php print t('Since') . ' '; ?>
  <?php endif; ?>
  <?php if ($position['start-date']['month']) : ?>
  <?php print $position['start-date']['month'] . '/'; ?>
  <?php endif; ?>
  <?php print $position['start-date']['year']; ?>
  <?php endif; ?>
  <?php if ($position['end-date']['year']) : ?>
  <?php if ($position['start-date']['year']) : ?>
  <?php print ' ' . t('to') . ' '; ?>
  <?php else : ?>
  <?php t('Until') . ' '; ?>
  <?php endif; ?>
  <?php if ($position['end-date']['month']) : ?>
  <?php print $position['end-date']['month'] . '/'; ?>  
  <?php endif; ?>
  <?php print $position['end-date']['year']; ?>
  <?php endif; ?>
</p>

<?php if ($position['summary']) : ?>
<div class="linkedin-position-summary">
  <?php print $position['summary']; ?>
</div>
<?php endif; ?>

</div>


