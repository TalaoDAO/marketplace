<?php
/**
 * @file
 * simple-timeline-fields.tpl.php
 * Created by JetBrains PhpStorm.
 * User: alan
 *
 * @var $simple_timeline_image
 * @var $simple_timeline_date
 * @var $simple_timeline_text
 */

$first = true;
foreach ($simple_timeline_date as $date) {
  if (!$first) { $first = false;
  ?>
  </li><li>
  <?php
  }
?>
<div>
  <span class="timeline-image"><?php echo $simple_timeline_image; ?></span>

    <span class="timeline-content">
        <h3 class="timeline-date"><?php echo $date; ?></h3>
        <span class="timeline-text"><?php echo $simple_timeline_text; ?></span>
    </span>
</div>
<?php 
  }
?>
