<?php global $base_url; ?>
<section id="<?php print $block_html_id; ?>" class="emh-module expertise <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="emh-title">
    <?php print t('Expert domains'); ?>
  </div>
  <div class="emh-subtitle">
    <?php print t('Explore the expert domains'); ?>
  </div>

  <div class="expertise-slider">

    <div class="expertise-slider-item">
      <div class="background" style="background-image: url('<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub') . '/images/content/block/emindhub_domains_products.jpg'; ?>')"></div>
      <svg class="picture" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
        viewBox="0 0 113.4 113.4" style="enable-background:new 0 0 113.4 113.4;" xml:space="preserve">
        <g id="produits">
          <path class="st0" d="M103.4,9.9c-3.7-3.7-16.7,3.3-21,7.5L68.8,31.1L24.8,19.9c-4.2-1.4-8.6-0.6-11.4,2.2l-4.5,4.5l43.3,21
            c-0.5,0.5-3.9,3.9-5.1,5.1c-0.8,0.8-1.6,1.8-2.4,2.7L29.7,75.9L16.9,74l-5.1,4.9l6.9,6.9l8.5,8.5l6.9,6.9l4.9-4.9l-1.9-12.7
            l20.3-15.1c0.9-0.7,1.9-1.5,2.7-2.4c1.2-1.2,4.6-4.5,5.1-5.1l21,43.3l4.5-4.5c2.8-2.8,3.7-7.2,2.2-11.4L82,44.7L95.6,31
            C100.1,26.6,107.2,13.6,103.4,9.9z"/>
        </g>
      </svg>
      <div class="domain">
        <?php print t('Products'); ?>
      </div>
      <ul class="subdomains">
        <li><?php print t('Airports'); ?></li>
        <li><?php print t('Aircraft'); ?></li>
        <li><?php print t('Drones'); ?></li>
        <li><?php print t('Equipments'); ?></li>
        <li><?php print t('Helicopters'); ?></li>
        <li><?php print t('Launchers'); ?></li>
        <li><?php print t('Satellites'); ?></li>
      </ul>
      <a class="emh-button" href="<?php print url('domains'); ?>"><?php print t('Learn more'); ?></a>
    </div>

    <div class="expertise-slider-item">
      <div class="background" style="background-image: url('<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub') . '/images/content/block/emindhub_domains_discipline.jpg'; ?>')"></div>
      <svg class="picture" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
      	 viewBox="0 0 113.4 113.4" style="enable-background:new 0 0 113.4 113.4;" xml:space="preserve">
        <g id="disciplines">
        	<path class="st0" d="M31.2,7.4l-2.4,8.2c-2.1,0.6-4.2,1.4-6,2.5L15.4,14l-6.6,6.6l4.1,7.4c-1.1,1.9-1.9,3.9-2.5,6l-8.2,2.4l0,9.4
        		l8.2,2.4c0.6,2.1,1.4,4.2,2.5,6l-4.1,7.4l6.6,6.6l7.4-4.1c1.9,1.1,3.9,1.9,6,2.5l2.4,8.2h9.4l2.4-8.2c2.1-0.6,4.2-1.4,6-2.5
        		l7.4,4.1l6.6-6.6L59,54.2c1.1-1.9,1.9-3.9,2.5-6l8.2-2.4l0-9.4l-8.2-2.4C60.9,32,60,29.9,59,28l4.1-7.4L56.4,14L49,18.1
        		c-1.9-1.1-3.9-1.9-6-2.5l-2.4-8.2L31.2,7.4z M35.9,26.9c7.9,0,14.3,6.4,14.3,14.3c0,7.9-6.4,14.3-14.3,14.3
        		c-7.9,0-14.3-6.4-14.3-14.3C21.7,33.3,28.1,26.9,35.9,26.9z M84.5,59.3L83,65c-1.5,0.4-2.9,1-4.2,1.7l-5.2-2.9L69,68.4l2.9,5.2
        		c-0.7,1.3-1.3,2.7-1.7,4.2l-5.7,1.6v6.6l5.7,1.6c0.4,1.5,1,2.9,1.7,4.2L69,96.9l4.6,4.6l5.2-2.9c1.3,0.7,2.7,1.3,4.2,1.7l1.6,5.7
        		h6.6l1.6-5.7c1.5-0.4,2.9-1,4.2-1.7l5.2,2.9l4.6-4.6l-2.9-5.2c0.7-1.3,1.3-2.7,1.7-4.2l5.7-1.6l0-6.6l-5.7-1.6
        		c-0.4-1.5-1-2.9-1.7-4.2l2.9-5.2l-4.6-4.6l-5.2,2.9c-1.3-0.7-2.7-1.3-4.2-1.7l-1.6-5.7H84.5z M87.8,74.8c4.3,0,7.8,3.5,7.8,7.8
        		c0,4.3-3.5,7.8-7.8,7.8c-4.3,0-7.8-3.5-7.8-7.8C80,78.3,83.5,74.8,87.8,74.8z"/>
        </g>
      </svg>
      <div class="domain">
        <?php print t('Discipline'); ?>
      </div>
      <ul class="subdomains">
        <li><?php print t('Certification & Regulation'); ?></li>
        <li><?php print t('Energy'); ?></li>
        <li><?php print t('Human factors'); ?></li>
        <li><?php print t('Maintenance'); ?></li>
        <li><?php print t('Engines & propulsion'); ?></li>
        <li><?php print t('Navigation, Telecom & Observation'); ?></li>
        <li><?php print t('Airline operations'); ?></li>
        <li><?php print t('Structures & Materials'); ?></li>
        <li><?php print t('Supply chain'); ?></li>
        <li><?php print t('Safety & Security'); ?></li>
        <li><?php print t('Embedded Systems'); ?></li>
      </ul>
      <a class="emh-button" href="<?php print url('domains'); ?>"><?php print t('Learn more'); ?></a>
    </div>

    <div class="expertise-slider-item">
      <div class="background" style="background-image: url('<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub') . '/images/content/block/emindhub_domains_technology.jpg'; ?>')"></div>
      <svg class="picture" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
      	 viewBox="0 0 113.4 113.4" style="enable-background:new 0 0 113.4 113.4;" xml:space="preserve">
        <g id="technologies">
        	<path class="st0" d="M69.7,96.5c11.1-4.3,18.9-15.1,18.9-27.6c0-6.7-2.3-12.9-6.1-17.9c0.8-1.7,1.3-3.7,1.3-5.7
        		c0-7.3-6-13.2-13.3-13.2c-0.1,0-0.2,0-0.2,0l7.1-12l-2.5-1.4L80,9.8l-7.7-4.4l-5.2,8.9l-2.6-1.5L40.9,52.5L35,49.2l-5.3,9.1
        		l24.2,13.9l5.3-9.1l-5.4-3.1l5-8.4c2.2,4.2,6.7,7.1,11.8,7.1c1.1,0,2.1-0.1,3.1-0.4c2.3,3,3.6,6.8,3.6,10.8
        		c0,10.1-8.2,18.3-18.4,18.3c-3.2,0-6.2-0.8-8.8-2.3h5.3l0-7H19.4l0,7h14.3c3.4,5.2,8.3,9.2,14.1,11.5h-27l0,11.5l73.1,0l0-11.5
        		L69.7,96.5z M70.6,52.3c-3.9,0-7-3.1-7-7c0-3.8,3.1-7,7-7c3.9,0,7,3.1,7,7C77.6,49.1,74.5,52.3,70.6,52.3z"/>
        </g>
      </svg>
      <div class="domain">
        <?php print t('Technology'); ?>
      </div>
      <ul class="subdomains">
        <li><?php print t('Air Traffic Management'); ?></li>
        <li><?php print t('Big Data'); ?></li>
        <li><?php print t('Connectivity'); ?></li>
        <li><?php print t('Cybersecurity'); ?></li>
        <li><?php print t('Additive layer manufacturing'); ?></li>
        <li><?php print t('A/C modifications'); ?></li>
        <li><?php print t('Factory of the Future'); ?></li>
      </ul>
      <a class="emh-button" href="<?php print url('domains'); ?>"><?php print t('Learn more'); ?></a>
    </div>

    <div class="expertise-slider-item">
      <div class="background" style="background-image: url('<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub') . '/images/content/block/emindhub_domains_cross-discipline.jpg'; ?>')"></div>
      <svg class="picture" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
      	 viewBox="0 0 113.4 113.4" style="enable-background:new 0 0 113.4 113.4;" xml:space="preserve">
        <g id="transverse">
        	<path class="st0" d="M31.6,81.8c-13.8-13.8-13.8-36.4,0-50.2l7.4,7.4V16.8H16.8l8.6,8.6C8,42.6,8,70.8,25.3,88.1
        		C36.3,99,51.5,103,65.6,100.1V91C53.8,94.1,40.8,91,31.6,81.8z M88,25.4c-10.9-10.9-26.1-15-40.2-12.1v9.1c11.8-3.1,24.8,0,34,9.2
        		c13.8,13.8,13.8,36.4,0,50.2l-7.4-7.4v22.2h22.2l-8.6-8.6C105.4,70.8,105.4,42.6,88,25.4z"/>
        </g>
      </svg>
      <div class="domain">
        <?php print t('Cross discipline'); ?>
      </div>
      <ul class="subdomains">
        <li><?php print t('Finance & Legal'); ?></li>
        <li><?php print t('Knowledge transfer & Training'); ?></li>
        <li><?php print t('Configuration management'); ?></li>
        <li><?php print t('PLM'); ?></li>
        <li><?php print t('Project management'); ?></li>
        <li><?php print t('Quality & Methods'); ?></li>
        <li><?php print t('Strategy & Development'); ?></li>
        <li><?php print t('IT systems'); ?></li>
      </ul>
      <a class="emh-button" href="<?php print url('domains'); ?>"><?php print t('Learn more'); ?></a>
    </div>

  </div>

  <div class="emh-dots emh-dots-alt"></div>

</section>
