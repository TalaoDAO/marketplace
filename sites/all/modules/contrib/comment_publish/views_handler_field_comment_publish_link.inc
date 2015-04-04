<?php
// $Id: views_handler_field_comment_publish_link.inc,v 1.1.2.2.2.1 2010/10/13 14:56:40 elliottf Exp $

/** 
 * @file
 *
 * Views handler for the comment_publish link.
 *
 * @author: Elliott Foster
 * @copyright: NewMBC 2010
 */

class views_handler_field_comment_publish_link extends views_handler_field {
  function construct() {
    parent::construct();

    // Add the fields that the comment_publish link will need..
    $this->additional_fields['nid'] = array(
      'table' => 'comment',
      'field' => 'nid',
    );
    $this->additional_fields['cid'] = array(
      'table' => 'comment',
      'field' => 'cid',
    );
  }

  /**
   * Default options definition
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['comment_publish_use_ajax'] = array(
      'default' => FALSE,
      'bool' => TRUE
    );
    $options['comment_publish_format'] = array(
      'default' => COMMENT_PUBLISH_PUBLISH_UNPUBLISH,
      'translatable' => TRUE
    );
    $options['comment_publish_format_reverse'] = array(
      'default' => FALSE,
      'bool' => TRUE
    );

    return $options;
  }

  /**
   * Allow the link to use AJAX.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['comment_publish_use_ajax'] = array(
      '#title' => t('Use AJAX'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['comment_publish_use_ajax']),
      '#description' => t('The comment (un)publishing will happen with AJAX and will not require a page redirect'),
    );
    $form['comment_publish_format'] = array(
      '#title' => t('Output format'),
      '#type' => 'select',
      '#options' => array(
        COMMENT_PUBLISH_PUBLISH_UNPUBLISH => t('publish/unpublish'),
        COMMENT_PUBLISH_PUBLISHED_UNPUBLISHED => t('published/unpublished'),
        COMMENT_PUBLISH_YES_NO => t('yes/no')
      ),
      '#default_value' => $this->options['comment_publish_format'],
    );
    $form['comment_publish_format_reverse'] = array(
      '#title' => t('Reverse format'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['comment_publish_format_reverse']),
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $node = node_load($values->{$this->aliases['nid']});
    $comment = comment_load($values->{$this->aliases['cid']});
    if (comment_publish_access($node, $comment)) {
      return comment_publish_get_link(
        $node->nid,
        $comment->cid,
        $this->options['comment_publish_use_ajax'],
        $this->options['comment_publish_format'],
        $this->options['comment_publish_format_reverse']
      );
    }

    return '';
  }
}

