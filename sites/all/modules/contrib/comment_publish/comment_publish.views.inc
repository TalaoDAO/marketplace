<?php
// $Id: comment_publish.views.inc,v 1.1 2010/09/15 22:45:29 elliottf Exp $

/**
 * @file
 * 
 * Views callbacks for the comment_publish module.
 *
 * @author: Elliott Foster
 * @copyright: NewMBC 2010
 */

/**
 * Implements hook_views_data().
 */
function comment_publish_views_data() {
  $data = array();

  $data['comment_publish']['table']['group'] = t('Comment');
  $data['comment_publish']['table']['join'] = array(
    '#global' => array(),
  );

  $data['comment_publish']['publish_comment'] = array(
    'field' => array(
      'title' => t('Comment (un)publish link'),
      'help' => t('Display a link to (un)publish a comment'),
      'handler' => 'views_handler_field_comment_publish_link',
    ),
  );

  return $data;
}

