<?php


/*
 * @file Overridable theme functions
 */

/*
 * Renders the timestamp as a date for status update time
 */

function theme_linkedin_profile_user_page_item($variables) {
  $item = $variables['item'];
  switch ($item['name']) {

    case 'current-status-timestamp':
      $item['value'] = format_date($item['value'] / 1000);
      break;

    case 'location':
      $item['value'] = $item['value']['name'];
      break;

    case 'relation-to-viewer':
      $item['value'] = $item['value']['distance'];
      break;

    case 'member-url-resources':
      if ($item['value']['member-url']['0']) {
        $urls = '<ul>';
        for ($i = 0; $i < count($item['value']['member-url']); $i++) {
          $urls .= '<li>' . l($item['value']['member-url'][$i]['name'], $item['value']['member-url'][$i]['url']) . '</li>';
        }
        $urls .= '</ul>';
        $item['value'] = $urls;
      }
      else {
        $item['value'] = l($item['value']['member-url']['name'], $item['value']['member-url']['url']);
      }
      break;

    case 'phone-numbers':
      if ($item['value']['phone-number']['0']) {
        $phones = '<ul>';
        for ($i = 0; $i < count($item['value']['phone-number']); $i++) {
          $phones .= '<li>' . $item['value']['phone-number'][$i]['phone-type'] . ': ' . $item['value']['member-url'][$i]['phone-number'] . '</li>';
        }
        $phones .= '</ul>';
        $item['value'] = $phones;
      }
      else {
        $item['value'] = $item['value']['phone-number']['phone-type'] . ': ' . $item['value']['phone-number']['phone-number'];
      }
      break;
  }
  $item['name'] = ucwords(str_replace('-', ' ', $item['name']));
  return $item;
}
