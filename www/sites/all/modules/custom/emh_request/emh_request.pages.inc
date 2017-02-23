<?php

/**
 * @file
 * Code of the eMindHub request pages feature.
 */

function emh_request_publication_page($request) {
  // Redirects if the request is already published.
  if ($request->status == NODE_PUBLISHED) {
    drupal_set_message(t("This request is already published."), 'warning');
    drupal_goto('node/' . $request->nid);
  }

  $page = array();

  $page['message'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => t("You're about to publish your request, please check the information below:"),
    '#attributes' => array(
      'class' => 'alert alert-block alert-warning',
    ),
  );

  $page['node'] = node_view($request, 'summary');

  if ($options = field_get_items('node', $request, 'field_options')) {
    $page['notice_options'] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' => t("Please check chosen options and validate your request:"),
      '#attributes' => array(
        'class' => 'alert alert-block alert-warning',
      ),
    );

    $rows = array();
    $total = 0;

    $info = emh_request_get_options();
    $costs = emh_request_get_options_costs($request);

    foreach ($options as $option) {
      $id = $option['option'];
      $rows[] = array($info[$id]['label'], emh_request_format_cost($costs[$id]));
      $total += (int) $costs[$id];
    }

    $page['options'] = array(
      '#theme' => 'table',
      '#header' => array(t("Option(s)"), t("Cost")),
      '#rows' => $rows,
    );

    $page['total'] = array(
      '#markup' => '<span class="total-label">' . t("Total:") . '</span> '
        . '<span class="total">' . emh_request_format_cost($total) . '</span>',
      '#prefix' => '<div class="total-wrapper">',
      '#suffix' => '</div>',
    );
  }

  $page['form'] = drupal_get_form('emh_request_publication_form', $request);

  return $page;
}
