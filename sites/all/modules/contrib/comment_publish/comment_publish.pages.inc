<?php
// $Id: comment_publish.pages.inc,v 1.1.2.2.2.3 2011/01/31 04:42:46 elliottf Exp $

/**
 * @file
 *
 * Page callbacks for the comment_publish module.
 *
 * @author: Elliott Foster
 * @copyright: NewMBC 2010
 */

/**
 * Returns a form to (un)publish a comment.
 */
function comment_publish_publish_form($form, $form_state, $node, $comment) {

  $form['nid'] = array('#type' => 'value', '#value' => $node->nid);
  $form['cid'] = array('#type' => 'value', '#value' => $comment->cid);
  $form['action'] = array('#type' => 'value');

  if ($comment->status) {
    $action = 'unpublish';
    $form['action']['#value'] = 0;
  }
  else {
    $action = 'publish';
    $form['action']['#value'] = 1;
  }

  $dest = array('path' => 'node/' . $node->nid, 'fragment' => 'comment-' . $comment->cid);
  if (isset($_GET['destination'])) {
    $dest = $_GET['destination'];
  }

  $form = confirm_form(
    $form,
    t('Are you sure you want to @action this comment?', array('@action' => $action)),
    $dest,
    t(
      'Submitting this form will @action this comment, making it @visibility to users on the site.',
      array('@action' => $action, '@visibility' => ($comment->status ? 'unavailable' : 'available'))
    ),
    t('@action', array('@action' => ucwords($action)))
  );

  return $form;
}

function comment_publish_publish_form_submit($form, &$form_state) {
  $comment = comment_load($form_state['values']['cid']);
  $comment->status = $form_state['values']['action'];
  comment_save($comment);

  if (!isset($_GET['destination'])) {
    $form_state['redirect'] = 'node/' . $form_state['values']['nid'];
  }
}

/**
 * (un)publishes a comment using AJAX.
 */
function comment_publish_js($node, $comment, $format, $reverse = 0) {
  global $user;

  $ostatus = $comment->status;
  if ($comment->status) {
    $action = t('unpublished');
    $eaction = t('unpublishing');
    $comment->status = 0;
    $foutput = t('publish');
    $ofoutput = t('unpublish');
    switch ($format) {
      case COMMENT_PUBLISH_PUBLISHED_UNPUBLISHED:
        $ofoutput = t('unpublished');
        $foutput = t('published');
        break; 
      case COMMENT_PUBLISH_YES_NO:
        $ofoutput = t('no');
        $foutput = t('yes');
        break;
    }
  }
  else {
    $action = t('published');
    $eaction = t('publishing');
    $comment->status = 1;
    $ofoutput = t('publish');
    $foutput = t('unpublish');
    switch ($format) {
      case COMMENT_PUBLISH_PUBLISHED_UNPUBLISHED:
        $ofoutput = t('published');
        $foutput = t('unpublished');
        break; 
      case COMMENT_PUBLISH_YES_NO:
        $ofoutput = t('yes');
        $foutput = t('no');
        break;
    }
  }

  if ($reverse) {
    $t = $ofoutput;
    $ofoutput = $foutput;
    $foutput = $t;
  }

  comment_save($comment);
  $saved = comment_load($comment->cid);
  $success = ($saved->status == $comment->status);
  if ($success) {
    watchdog('comment_publish', '@name @action comment @cid', array('@name' => $user->name, '@action' => $action, '@cid' => $comment->cid));
    return drupal_json_output(array('status' => $success, 'data' => array('status' => $comment->status, 'format' => $foutput)));
  }
  else {
    // This shouldn't happen...
    watchdog('comment_publish', '@name had an aerror @action comment @cid', array('@name' => $user->name, '@action' => $eaction, '@cid' => $comment->cid), WATCHDOG_ERROR);
    return drupal_json_output(array('status' => $success, 'data' => array('status' => $ostatus, 'format' => $ofoutput)));
  }
}

