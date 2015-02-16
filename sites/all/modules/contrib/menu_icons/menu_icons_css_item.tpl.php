<?php

/**
 * @file
 *
 * Template file for generating the CSS file used for the menu-items
 */

/**
 * Variables:
 * $mlid
 * $path
 */
?>
a.menu-<?php print $mlid ?>, ul.links li.menu-<?php print $mlid ?> a {
  background-image: url(<?php print $path ?>);
  padding-<?php print "$pos:$size"?>px;
  background-repeat: no-repeat;
  background-position: <?php print $pos?>;
  height: <?php print $height?>px;
}

