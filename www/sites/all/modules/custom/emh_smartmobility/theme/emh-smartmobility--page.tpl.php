<?php

global $base_url, $language;
?>

<section class="emh-module how-it-works hiw">

  <ul class="hiw-tabs">
    <li><button type="button" name="button" data-tab="hiw-customer" class="hiw-tab emh-button customer"><?php print t('Vous recherchez des talents'); ?></button></li>
    <li><button type="button" name="button" data-tab="hiw-expert" class="hiw-tab emh-button expert"><?php print t('Vous êtes salarié Airbus'); ?></button></li>
  </ul>

  <!-- PARTNER -->
  <div class="hiw-tab-content hiw-customer emh-module">

    <div class="emh-subtitle">
      <?php echo sprintf(t('Pourquoi %sSmart Mobility%s ?'), '<span class="smartmobility-title">', '</span>'); ?>
    </div>

    <section class="emh-module smartmobility-why">

      <div class="row">
        <div class="col-md-4 col-md-offset-2">
          <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/community.svg" alt="" width="150" />
          <p>Communiquer sur vos offres auprès de candidats qualifiés dans le secteur de l'aéronautique</p>
        </div>
        <div class="col-md-4">
          <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/responses.svg" alt="" width="150" />
          <p>Choisir les profils avec lesquels vous souhaitez échanger à partir de questionnaires spécifiques, des profils de compétences et des CV</p>
        </div>
      </div>

    </section>

    <section class="emh-module smartmobility-how">

      <div class="emh-subtitle"><?php echo t('Comment ça marche ?') ?></div>

      <div class="row container">
        <div class="col-md-3">
          <p><span>1.</span> Vous publiez vos annonces : recrutements ou missions</p>
        </div>
        <div class="col-md-3">
          <p><span>2.</span> Des candidats vous répondent via un questionnaire en complément de leur profil et CV</p>
        </div>
        <div class="col-md-3">
          <p><span>3.</span> Vous analysez les candidatures</p>
        </div>
        <div class="col-md-3">
          <p><span>4.</span> Vous sélectionnez les profils que vous souhaitez rencontrer</p>
        </div>
      </div>
    </section>

    <div class="emh-action">
      <a class="emh-button solid" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Je m\'inscris'); ?></a>
    </div>

    <section class="emh-module faq hiw-faq">

        <div class="emh-subtitle"><?php echo t('Questions les plus fréquentes') ?></div>

        <div>
          <h3 class="question">Qui peut voir les réponses à mes annonces ?</h3>

          <div class="answer">
            <p>Vous seul pouvez consulter les réponses à votre annonce en choisissant l'option «&nbsp;private answer&nbsp;».</p>
          </div>
        </div>
        <div>
          <h3 class="question">Comment garantissez-vous la confidentialité des informations ?</h3>

          <div class="answer">
            <p>Lorsque vous publiez une annonce, vous pouvez choisir d'être anonyme et de cacher votre nom et/ou celui de votre entreprise, en choisissant l'option «&nbsp;anonymous". Il est toutefois recommandé de mettre un bref descriptif de votre activité pour accroitre la pertinence des réponses des candidats.</p>
          </div>
        </div>
        <div>
          <h3 class="question">Qui a accès à mes annonces ?</h3>

          <div class="answer">
            <p>Lorsque vous publiez une annonce de recrutement, vous devez choisir le cercle «&nbsp;Smart Mobility&nbsp;» pour que seuls les salariés Airbus puissent y accéder de façon exclusive.</p>
          </div>
        </div>
        <div>
          <h3 class="question">Pourquoi associer un questionnaire à mon annonce ?</h3>

          <div class="answer">
            <p>Le questionnaire permet de pré-qualifier les candidats sur la base de leurs réponses. Nous vous recommandons de ne pas poser plus de 7 à 8 questions. Lorsque vous choisissez le type «&nbsp;Recruitment Smart Mobility&nbsp;» à la création de votre annonce, nous vous proposons quelques questions type :</p>
            <ul>
              <li>Quelles sont vos motivations pour ce poste / cette mission ?</li>
              <li>Quelles sont vos réalisations pertinentes en relation avec ce poste / cette mission ?</li>
              <li>etc.</li>
            </ul>
          </div>
        </div>

    </section>

  </div>

  <!-- EMPLOYEE -->
  <div class="hiw-tab-content hiw-expert emh-module">

    <div class="emh-subtitle">
      <?php echo sprintf(t('Pourquoi %sSmart Mobility%s ?'), '<span class="smartmobility-title">', '</span>'); ?>
    </div>

    <section class="emh-module smartmobility-why">

      <div class="row">
        <div class="col-md-4 col-md-offset-2">
          <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/community-alt.svg" alt="" width="150" />
          <p>Identifier des opportunités dans le secteur aéronautique, principalement en région parisienne</p>
        </div>
        <div class="col-md-4">
          <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/responses-alt.svg" alt="" width="150" />
          <p>Valoriser vos compétences en renseignant votre profil et en répondant aux questionnaires spécifiques à chaque besoin</p>
        </div>
      </div>

    </section>

    <section class="emh-module smartmobility-how smartmobility-how-alt">

      <div class="emh-subtitle"><?php echo t('Comment ça marche ?') ?></div>

      <div class="row container">
        <div class="col-md-3">
          <p><span>1.</span> Vous vous inscrivez et vous renseignez votre profil</p>
        </div>
        <div class="col-md-3">
          <p><span>2.</span> Vous êtes informé par email dès qu'une nouvelle offre est publiée</p>
        </div>
        <div class="col-md-3">
          <p><span>3.</span> Vous postulez en répondant au questionnaire spécifique à chaque offre</p>
        </div>
        <div class="col-md-3">
          <p><span>4.</span> Vous êtes contacté directement par les demandeurs qui auront sélectionné votre profil</p>
        </div>
      </div>
    </section>

    <div class="emh-action">
      <a class="emh-button solid-alt" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Je m\'inscris'); ?></a>
    </div>

    <section class="emh-module faq hiw-faq">

        <div class="emh-subtitle"><?php echo t('Questions les plus fréquentes') ?></div>

        <div>
          <h3 class="question question-alt">Comment suis-je informé des nouvelles annonces publiées sur Smart Mobility ?</h3>

          <div class="answer">
            <p>Pour chaque nouvelle demande, vous recevez un email de notification avec le titre de l'annonce. Cela vous permet de décider très rapidement si vous pouvez être intéressé par cette demande. En cliquant sur le lien, vous accédez à la demande.</p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt">Qui a accès aux annonces publiées sur Smart Mobility ?</h3>

          <div class="answer">
            <p>Seules les personnes inscrites dans le cercle «&nbsp;Smart Mobility&nbsp;» peuvent accéder aux annonces, donc les annonceurs et les salariés d'Airbus.</p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt">Qui peut consulter mon profil ?</h3>

          <div class="answer">
            <p>Seules les personnes inscrites dans le cercle «&nbsp;Smart Mobility&nbsp;» peuvent accéder au profil des salariés d'Airbus, donc les annonceurs et les autres salariés d'Airbus.</p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt">Pourquoi renseigner mon profil ?</h3>

          <div class="answer">
            <p>Il est recommandé de renseigner son profil le plus précisément possible. Les annonceurs peuvent en effet pré-sélectionner les candidats sur la base des réponses au questionnaire associé à chaque offre, mais aussi du profil détaillé du candidat.</p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt">Comment répondre à une annonce ?</h3>

          <div class="answer">
            <p>Pour répondre à une annonce, il suffit de répondre aux questions associées aux offres qui vous intéressent. Les annonceurs sont automatiquement informés de vos réponses.</p>
          </div>
        </div>

    </section>

  </div>

</section>
