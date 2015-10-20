<div class="row section actions">
  <div class="col-sm-8">
    <?php print render($content['links']['node']); ?>
    <?php print render($content['links']['forward']); ?>
  </div>
  <div class="col-sm-4 text-right">

    <ul class="links list-inline">

      <?php if (node_access('update', $node)) : ?>
      <li class="edit_link"><a href="<?php print base_path(); ?>node/<?php print $node->nid; ?>/edit"><?php print t('Edit'); ?></a>
        </li>
      <?php endif; ?>

      <?php if (function_exists('webform_get_submission_count')) : ?>
      <?php if (webform_get_submission_count($node->nid) > 0) : ?>
      <?php
      $count = webform_get_submission_count($node->nid);
      $count_label = t('answer');
      if ($count > 1) $count_label = t('answers');
      ?>
      <li class="submissions_link"><a href="<?php print base_path(); ?>node/<?php print $node->nid; ?>/webform-results"><?php print $count . '&nbsp;' . $count_label; ?></a>
      </li>
      <?php endif; ?>
      <?php endif; ?>

      <?php if ($comment_count > 0) : ?>
      <?php
      $count_label = t('answer');
      if ($comment_count > 1) $count_label = t('answers');
      ?>
      <li class="comments_link"><a href="<?php print base_path(); ?>node/<?php print $node->nid; ?>/answers" class="btn btn-primary"><?php print t('Select best answers'); ?></a>
      </li>
      <?php endif; ?>

    </ul>

    <?php print render($content['links']['flag']); ?>

  </div>

</div>
