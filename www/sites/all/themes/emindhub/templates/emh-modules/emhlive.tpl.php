<section class="emh-module emhlive container">

  <div class="emhlive-title">
    <?php print t('EMH live'); ?>
  </div>

  <div class="emhlive-arrows"></div>
  <div class="emh-dots above"></div>

  <div class="emhlive-slider">

    <?php
    /**
     * @TODO
     * La variabe $itemClass et la boucle while sont temporaire
     * en attendant que l'ensemble soit dynamisé.
     */
      $itemClass = [
        'emhlive-style-default',
        'emhlive-style-alpha',
        'emhlive-style-beta'
      ];
      $fakeItems = 5;
    ?>

    <?php while($fakeItems--): ?>
      <article class="emhlive-item <?php print $itemClass[(5 - $fakeItems) % 3]; ?>">

        <div class="emhlive-item-title">
          Titre de la publication <?php echo (5 - $fakeItems); ?>
        </div>

        <div>
          <span class="emhlive-item-meta emhlive-item-date">25 oct. 2016</span>
          |
          <span class="emhlive-item-meta emhlive-item-category"><a href="#">Category</a></span>
        </div>

        <div class="emhlive-item-text">
          Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
        </div>
        <a href="#" class="emh-read-more"><?php print t('Read more'); ?></a>

      </article>
    <?php endwhile; ?>

  </div>

  <div class="emh-dots emh-dots-alt below"></div>

</section><!-- /.emhlive -->
