<?php

/**
 * @file
 * Template file for LinkedIn "Positions" items as displayed on user page
 * Copy it to your theme's folder if you want to override it.
 *
 * Be sure to check and comply to  http://developer.linkedin.com/docs/DOC-1091 before tweaking.
 */
$positions == $variables['positions'];
?>
<div class="linkedin-positions">
  <ul>
<?php foreach ($positions as $position) : ?>
      <li><?php print $position; ?></li>
<?php endforeach; ?>
  </ul>
</div>

