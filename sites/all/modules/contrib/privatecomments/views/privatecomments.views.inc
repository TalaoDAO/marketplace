<?php

function privatecomments_views_data_alter(&$data) {
  // new comments
  $data['node']['new_comments_user'] = array(
    'title' => t('New comments for current user'),
    'help' => t('The number of new comments on the node for current user.'),
    'field' => array(
      'handler' => 'privatecomments_handler_field_node_new_comments_user',
      'no group by' => TRUE,
    ),
  );
}
