<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      // print render($content);
    ?>
  </div>

  <section class="emh-module press-page container">
      <div><!-- RTE -->

          <div style="text-align: center;">

              <h2>Communiqués de presse :</h2>

              <p>
                  02/03/2015 - Interview Nicolas Muller au ILA Startup Day <a class="pdf-link" href="http://perdu.com/monFichier.pdf">PDF</a><br>
                  21/06/2016 - eMindHub au Bourget 2016 <a class="pdf-link" href="http://perdu.com/monFichier.pdf">PDF</a><br>
                  04/11/2016 - eMindHub au Salon de Zhuhai <a class="pdf-link" href="http://perdu.com/monFichier.pdf">PDF</a>
              </p>

              <h2>Articles de presse :</h2>

              <p>
                  22/12/2015 - eMindHub, le «Meetic» de l'aéronautique - <a href="#">La Dépêche</a> <a class="pdf-link" href="http://perdu.com/monFichier.pdf">PDF</a><br>
                  16/06/2015 - Emindhub, au service de la connaissance - <a href="#">Air Cosmos</a> <a class="pdf-link" href="http://perdu.com/monFichier.pdf">PDF</a><br>
                  04/11/2016 - À Toulouse, Emindhub favorise... et l’aérospatial - <a href="#">Lamelee</a> <a class="pdf-link" href="http://perdu.com/monFichier.pdf">PDF</a><br><br><br>
              </p>


              <p>
                  <a href="/contact" class="button solid">Contactez-nous</a>
              </p>
              <p>
                  <a href="mailto:presse@emindhub.com">presse@emindhub.com</a>
              </p>

              <h2>Ressources à télécharger</h2>

              <a href="#">Dossier de presse</a><br>
              <a href="#">Logo HD fond blanc</a><br>
              <a href="#">Logo GD fond transparent</a><br>
          </div>
      </div>
  </section>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
