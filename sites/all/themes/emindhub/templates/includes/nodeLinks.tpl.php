<div class="row section actions">
  <div class="col-sm-6">
    <?php print render($content['links']['node']); ?>
  </div>
  <div class="col-sm-2">
    <?php print render($content['links']['forward']); ?>
  </div>
  <div class="col-sm-2">
    <?php print render($content['links']['flag']); ?>
  </div>

  <div class="col-sm-2 text-right">

    <?php if (function_exists('webform_get_submission_count')) : ?>
    <?php if (webform_get_submission_count($node->nid) > 0) : ?>
    <?php
    $count = webform_get_submission_count($node->nid);
    $count_label = t('response');
    if ($count > 1) $count_label = t('responses');
    ?>
      <ul class="links list-inline">
        <li class="submissions_link first last"><a href="<?php print base_path(); ?>node/<?php print $node->nid; ?>/webform-results"><?php print $count . '&nbsp;' . $count_label; ?></a>
        </li>
      </ul>
    <?php endif; ?>
    <?php endif; ?>

    <?php if ($comment_count > 0) : ?>
    <?php
    $count_label = t('response');
    if ($comment_count > 1) $count_label = t('responses');
    ?>
    <ul class="links list-inline">
      <li class="comments_link first last"><a href="<?php print base_path(); ?>node/<?php print $node->nid; ?>/answers"><?php print $comment_count . '&nbsp;' . $count_label; ?></a>
      </li>
    </ul>
    <?php endif; ?>

  </div>

</div>
