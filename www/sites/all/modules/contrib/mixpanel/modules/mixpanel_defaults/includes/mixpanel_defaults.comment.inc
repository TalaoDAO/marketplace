<?php

/**
 * @file
 * Sends events related to comments to Mixpanel.
 */

/**
 * Implements hook_comment_publish().
 */
function mixpanel_defaults_comment_publish($comment) {
  $node = node_load($comment->nid);

  $values = array(
    'node-id' => $comment->nid,
    'node-title' => $node->title,
    'node-type' => $node->type,
    'comment-id' => $comment->cid,
  );

  if (!empty($node->og_groups)) {
    $values['group-id'] = array_pop(array_values($node->og_groups));
  }

  mixpanel_track("comment-created", $values);
}
