<?php

/**
 * @file
 * EMH Footer template.
 *
 * Available variables:
 * - @string $partners_title.
 * - @array $partners.
 */

print $partners_title;
foreach ($partners as $partner) {
  print_r($partner);
}
?>
