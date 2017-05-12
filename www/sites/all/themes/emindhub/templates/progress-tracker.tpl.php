<div id="progress-tracker-wrapper">
  <?php $nid = arg(1); if ( !empty($nid) &&  module_exists('emh_request') ) : ?>
  <div class="pt-status">
    <?php $workflow = emh_request_workflow_get_status($nid); ?>
    <span class="emh-status <?php print $workflow['status']; ?>"><?php print $workflow['label']; ?></span>
  </div>
  <?php endif; ?>
  <div class="pt-steps"><?php print $steps; ?></div>
</div>
