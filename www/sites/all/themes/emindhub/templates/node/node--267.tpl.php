<?php global $base_url; ?>

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

    <section class="emh-module who-we-are container">
      <div class="who-we-are-text">
        <?php
          // We hide the comments and links now so that we can render them later.
          hide($content['comments']);
          hide($content['links']);
          print render($content);
        ?>
      </div>
    </section>

    <section id="who-we-are-team" class="emh-module person-list-wrapper container">
        <h3><?php print t('Our team'); ?></h3>
        <ul class="person-list row">
          <li class="person-wrapper">
              <div class="person ">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_Nicolas-Muller.jpg" alt="Nicolas Muller" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Nicolas Muller
                      </div>
                      <div class="position">
                          CEO
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_Yoann-Babel.jpg" alt="Yoann Babel" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Yoann Babel
                      </div>
                      <div class="position">
                          CTO
                      </div>
                  </div>
              </div>
          </li>
        </ul>
    </section>

    <section id="who-we-are-sponsors" class="emh-module person-list-wrapper container">
        <h3><?php print t('Our sponsors'); ?></h3>
        <ul class="person-list row">
          <li class="person-wrapper">
              <div class="person ">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_sponsor_Anil_Bernard-Dende.jpg" alt="Anil Bernard-Dende" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Anil Bernard-Dende
                      </div>
                      <div class="position">
                          COO Showroomprive.com
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_sponsor_Olivier_Duchmann.jpg" alt="Olivier Duchmann" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Olivier Duchmann
                      </div>
                      <div class="position">
                          CEO Serma Safety & Security
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person ">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_sponsor_Philippe_Dussoulier.jpg" alt="Philippe Dussoulier" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Philippe Dussoulier
                      </div>
                      <div class="position">
                          Business Developement CPA
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_sponsor_Denis_Guyader.jpg" alt="Denis Guyader" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Denis Guyader
                      </div>
                      <div class="position">
                          Aerospace Advisor
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person ">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_sponsor_Alain_Le-Feuvre.jpg" alt="Alain Le Feuvre" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Alain Le Feuvre
                      </div>
                      <div class="position">
                          Aerospace Advisor
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_sponsor_Gerard_Masse.jpg" alt="Gérard Massé" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Gérard Massé
                      </div>
                      <div class="position">
                          Aerospace Advisor
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person ">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_sponsor_Jean-Luc_Monceaux.jpg" alt="Jean-Luc Monceaux" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Jean-Luc Monceaux
                      </div>
                      <div class="position">
                          Legal expert in aerospace
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_sponsor_Pascale_Porteres.jpg" alt="Pascale Porteres" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Pascale Porteres
                      </div>
                      <div class="position">
                          CEO People to people
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person ">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_sponsor_Francois_Ribour.jpg" alt="François Ribour" />
                  </div>
                  <div class="content">
                      <div class="name">
                          François Ribour
                      </div>
                      <div class="position">
                          CTO Ingéliance
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_sponsor_Regis_Trolliet.jpg" alt="Régis Trolliet" />
                  </div>
                  <div class="content">
                      <div class="name">
                          Régis Trolliet
                      </div>
                      <div class="position">
                          Aerospace Advisor
                      </div>
                  </div>
              </div>
          </li>
        </ul>
    </section>

  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
