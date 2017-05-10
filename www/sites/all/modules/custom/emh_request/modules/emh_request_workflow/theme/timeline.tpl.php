<div class="created">
  <?php print $created; ?>
</div>
<div class="progress">
  <span class="timeleft"><?php print $left; ?></span>
  <div class="progress-bar progress-bar-<?php print $class; ?>" role="progressbar" aria-valuenow="<?php print $progression; ?>" aria-valuemin="0" aria-valuemax="100" style="width: <?php print $progression; ?>%;">
  </div>
</div>
<div class="deadline">
  <?php print $deadline; ?>
</div>
