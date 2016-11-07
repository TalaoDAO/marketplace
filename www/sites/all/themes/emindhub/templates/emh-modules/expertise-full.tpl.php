<section class="emh-module expertise-full">
  <div class="emh-title">
    <?php print t('CHANGEME Domaine d\'expertise'); ?>
  </div>
  <div class="emh-subtitle">
    <?php print t('CHANGEME Consultez les domaines où client et experts se retrouvent'); ?>
  </div>

  <div class="expertise-list">

    <?php $expertiseLoop = 4; while ($expertiseLoop--): ?>
    <div class="expertise-list-item">
      <div class="domain">
        <?php print t('Produits'); ?>
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
      </div>

    </div>
  <?php endwhile; ?>

</section>
