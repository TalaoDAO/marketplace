<section class="emh-module container expertise-full">
  <div class="emh-title">
    <?php print t('CHANGEME Domaine d\'expertise'); ?>
  </div>
  <div class="emh-subtitle">
    <?php print t('CHANGEME Consultez les domaines où client et experts se retrouvent'); ?>
  </div>

  <div class="expertise-list">

    <?php $expertise = ['transverse', 'technologies', 'disciplines', 'produits']; $expertiseLoop = 4; while ($expertiseLoop--): ?>
    <div class="expertise-list-item expertise-<?php print $expertise[$expertiseLoop]; ?>">
      <div class="domain">
        <div class="domain-name">
          <?php print t('Produits'); ?>
        </div>
      </div>
      <ul class="subdomains">
        <li><?php print t('Air traffic Management'); ?></li>
        <li><?php print t('Big Data'); ?></li>
        <li><?php print t('Connectivité'); ?></li>
        <li><?php print t('Cybersécurité'); ?></li>
        <li><?php print t('Fabrication additive'); ?></li>
        <li><?php print t('Usine du futur'); ?></li>
      </ul>
      <div class="description">
        Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

        <div class="links">
          <a class="request" href="#"><?php print t('CHANGEME Poster une demande'); ?></a>
          <a class="expertise" href="#"><?php print t('CHANGEME Proposer une expertise'); ?></a>
        </div>
      </div>

    </div>
  <?php endwhile; ?>

</section>
