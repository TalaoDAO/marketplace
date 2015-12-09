<div id="progress-tracker-wrapper">
  <?php if (module_exists('emh_request')) : ?><div class="pt-status"><?php print emh_request_get_status(arg(1)); ?></div><?php endif; ?>
  <div class="pt-steps"><?php print $steps; ?></div>
</div>
