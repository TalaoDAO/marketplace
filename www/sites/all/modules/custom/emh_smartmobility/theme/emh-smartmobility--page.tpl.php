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
          <h3 class="question">
          Comment suis-je informé des nouvelles demandes me concernant ?</h3>

          <div class="answer">
            <p>Pour chaque nouvelle demande vous recevez un email de notification, avec le titre de la demande. Cela vous permet de décider très rapidement si vous pouvez être intéressé par cette demande, soit à titre personnel, soit pour un expert de votre réseau que vous pourriez recommander.</p>
            <p>Vous pouvez également choisir de ne recevoir des notifications que pour les demandes correspondant au domaine de compétence que vous avez renseigné dans votre profil (champs «&nbsp;domains&nbsp;»).</p>
          </div>
        </div>
        <div>
          <h3 class="question">
          A quoi je m'engage en m'inscrivant sur eMindHub ?</h3>

          <div class="answer">
            <p>L'inscription sur eMindHub est libre et gratuite. Vous vous engagez uniquement à utiliser le service conformément aux Conditions Générales d'Utilisation. Il n'y a pas de clause d'exclusivité et vous n'êtes pas tenu d'avoir une activité minimale.</p>
          </div>
        </div>
        <div>
          <h3 class="question">
          Qui peut voir mon profil quand je m'inscris sur eMindHub ?</h3>

          <div class="answer">
            <p>De façon générale, les profils des experts eMindHub ne sont pas publics. Seul un client qui a sélectionné votre réponse à une de ses demandes pourra avoir accès à votre profil. Ainsi, tant que vous n'êtes pas actif, vous resterez anonyme.</p>
            <p>Lorsque vous faites parti d'un cercle privé (association, ancien d'une école ou d'une entreprise), l'ensemble des membres de ce cercle peut accéder à votre profil.</p>
          </div>
        </div>
        <div>
          <h3 class="question">
          Pourquoi renseigner mon profil ?</h3>

          <div class="answer">
            <p>Lorsqu'un utilisateur choisit une de vos réponses, il accède à votre profil, avec vos coordonnées et l'ensemble des informations sur vos compétences. En renseignant votre profil de façon précise et exhaustive vous renforcez vos chances d'être contacté par un demandeur et de vous voir confié une mission.</p>
            <p>Un profil bien renseigné améliorera aussi la pertinence des notifications vous informant de nouvelles demandes.</p>
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
          <h3 class="question question-alt">
            Qui peut voir les réponses à mes demandes ?</h3>

          <div class="answer">
            <p>Vous êtes le seul à pouvoir lire les réponses à votre demande en choisissant l'option «&nbsp;réponse privée&nbsp;».</p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt">
        Comment puis-je solliciter la communauté des experts eMindHub ?</h3>

          <div class="answer">
            <p>Vous pouvez solliciter la communauté des experts de trois façons différentes&nbsp;:</p>
            <ul>
              <li>En posant une question pour avoir des avis, des retours d'expériences, des idées.</li>
              <li>En publiant une annonce pour une mission d'expertise ponctuelle via un questionnaire qui vous permet de pré-qualifier les experts les plus pertinents.</li>
              <li>En publiant un appel d'offre ou un challenge d'innovation pour obtenir directement des propositions de services.</li>
            </ul>
          </div>
        </div>
        <div>
          <h3 class="question question-alt">
        Comment garantissez-vous la confidentialité des informations ?</h3>

          <div class="answer">
            <p>Lorsque vous faites une demande, vous pouvez choisir d'être anonyme et de cacher votre nom et/ou celui de votre entreprise. Il est toutefois recommandé de mettre un bref descriptif de votre activité pour accroitre la pertinence des réponses des experts.</p>
            <p>Nous préparons également une option qui permettra de faire signer un NDA en ligne aux experts qui souhaiteraient assister à votre demande.</p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt">
        Combien ça coûte de poster des demandes ?</h3>

          <div class="answer">
            <p>Vous pouvez poster vos demandes et lire les réponses des experts gratuitement. En revanche pour accéder aux profils des experts il vous faudra acheter des crédits. Ces crédits vous serviront également à personnaliser vos demandes via les options.</p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt">
        Qui a accès à ma demande ?</h3>

          <div class="answer">
            <p>Lors de la publication de votre demande, vous devez choisir le cercle d'experts pouvant y accéder (par défaut&nbsp;: all experts).</p>
            <p>Vous pouvez également choisir un de vos cercles privés&nbsp;:</p>
            <ul>
              <li>Soit un cercle correspondant à une de vos associations (alumni par exemple), clusters ou groupements d'entreprises qui utilisent eMindHub pour gérer les échanges entre leurs membres.</li>
              <li>Soit un cercle que nous pouvons vous créer sur mesure, composé d'experts de votre connaissance (anciens de votre entreprise, partenaires dans le cadre de votre entreprise étendue, etc.)</li>
            </ul>
          </div>
        </div>

    </section>

  </div>

</section>
