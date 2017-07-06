<?php

global $base_url, $language;
?>

<section class="emh-module how-it-works hiw">

  <ul class="hiw-tabs">
    <li><button type="button" name="button" data-tab="hiw-customer" class="hiw-tab emh-button customer"><?php print t('Looking for talent'); ?></button></li>
    <li><button type="button" name="button" data-tab="hiw-expert" class="hiw-tab emh-button expert"><?php print t('I am an employee of Airbus'); ?></button></li>
  </ul>

  <!-- PARTNER -->
  <div class="hiw-tab-content hiw-customer emh-module">

    <div class="emh-subtitle">
      <?php echo sprintf(t('Why %sSmart Mobility%s?'), '<span class="smartmobility-title">', '</span>'); ?>
    </div>

    <section class="emh-module smartmobility-why">

      <div class="row">
        <div class="col-md-4 col-md-offset-2">
          <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/community.svg" alt="" width="150" />
          <p><?php print t('Announce your job offers to qualified candidates in the aerospace sector'); ?></p>
        </div>
        <div class="col-md-4">
          <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/responses.svg" alt="" width="150" />
          <p><?php print t('Choose the profiles which you want to share specific questionnaires, competency profiles and CVs with'); ?></p>
        </div>
      </div>

    </section>

    <section class="emh-module smartmobility-how">

      <div class="emh-subtitle"><?php print t('How does it work?') ?></div>

      <div class="row">
        <div class="col-md-3">
          <p><span>1.</span> <?php print t('Publish your offer: recruitment or mission'); ?></p>
        </div>
        <div class="col-md-3">
          <p><span>2.</span> <?php print t('Candidates respond via a questionnaire and provide their profile and CV'); ?></p>
        </div>
        <div class="col-md-3">
          <p><span>3.</span> <?php print t('Analyze candidate responses'); ?></p>
        </div>
        <div class="col-md-3">
          <p><span>4.</span> <?php print t('Select the profiles you\'d like to meet'); ?></p>
        </div>
      </div>
    </section>

    <section class="emh-module hiw-video">
      <div class="embed-responsive embed-responsive-16by9">
        <iframe class="embed-responsive-item" src="https://www.youtube.com/embed/VAXPojC8KLU"></iframe>
      </div>
    </section>

    <div class="emh-actions">
      <div class="emh-action">
        <a class="emh-button solid" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Register'); ?></a>
      </div>
    </div>

    <section class="emh-module faq hiw-faq">

        <div class="emh-subtitle"><?php print t('Frequently Asked Questions') ?></div>

        <div>
          <h3 class="question"><?php print t('Who can see the responses to my offers?'); ?></h3>

          <div class="answer">
            <p><?php print t('Only you can see the responses to your job offer by choosing the option «&nbsp;private answer&nbsp;».'); ?></p>
          </div>
        </div>
        <div>
          <h3 class="question"><?php print t('How can you guarantee the confidentiality of the information submitted?'); ?></h3>

          <div class="answer">
            <p><?php print t('When you place an offer, you can choose to be anonymous and hide your name and/or that of your company, by choosing the option «&nbsp;anonymous&nbsp;». It is recommended that you include a brief description of your activity in order to increase the relevance of the candidate responses.'); ?></p>
          </div>
        </div>
        <div>
          <h3 class="question"><?php print t('Who can access my offers?'); ?></h3>

          <div class="answer">
            <p><?php print t('When you publish a job offer, you must choose the «&nbsp;Smart Mobility&nbsp;» circle to ensure only Airbus employees have exclusive access.'); ?></p>
          </div>
        </div>
        <div>
          <h3 class="question"><?php print t('Why include a questionnaire with my job offer?'); ?></h3>

          <div class="answer">
            <p><?php print t('The questionnaire allows you to pre-qualify candidates on the basis of their answers. We recommend that you have no more than 8 questions. When you choose the option «&nbsp;Recruitment Smart Mobility&nbsp;» in the creation of your offer, we offer some standard questions. As an example:'); ?></p>
            <ul>
              <li><?php print t('What are your motivations for this job / mission?'); ?></li>
              <li><?php print t('What are your relevant achievements in relation to this job / mission?'); ?></li>
              <li><?php print t('etc'); ?>.</li>
            </ul>
          </div>
        </div>

    </section>

  </div>

  <!-- EMPLOYEE -->
  <div class="hiw-tab-content hiw-expert emh-module">

    <div class="emh-subtitle">
      <?php echo sprintf(t('Why %sSmart Mobility%s?'), '<span class="smartmobility-title">', '</span>'); ?>
    </div>

    <section class="emh-module smartmobility-why">

      <div class="row">
        <div class="col-md-4 col-md-offset-2">
          <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/community-alt.svg" alt="" width="150" />
          <p><?php print t('Identify opportunities in the aerospace industry, primarily within the Paris region'); ?></p>
        </div>
        <div class="col-md-4">
          <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/responses-alt.svg" alt="" width="150" />
          <p><?php print t('Demonstrate your competences by completing your profile and responding to specific offers via the related questionnaires'); ?></p>
        </div>
      </div>

    </section>

    <section class="emh-module smartmobility-how smartmobility-how-alt">

      <div class="emh-subtitle"><?php print t('How does it work?') ?></div>

      <div class="row">
        <div class="col-md-3">
          <p><span>1.</span> <?php print t('Register and complete your profile'); ?></p>
        </div>
        <div class="col-md-3">
          <p><span>2.</span> <?php print t('You receive an email once a new offer is published'); ?></p>
        </div>
        <div class="col-md-3">
          <p><span>3.</span> <?php print t('Apply by responding to the questionnaire relating to the job offer'); ?></p>
        </div>
        <div class="col-md-3">
          <p><span>4.</span> <?php print t('You will be contacted directly by requesters who have selected your profile'); ?></p>
        </div>
      </div>
    </section>

    <section class="emh-module hiw-video">
      <div class="embed-responsive embed-responsive-16by9">
        <iframe class="embed-responsive-item" src="https://www.youtube.com/embed/Vi2bkPyqyCs"></iframe>
      </div>
    </section>

    <div class="emh-actions">
      <div class="emh-action">
        <a class="emh-button solid-alt" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Register'); ?></a>
      </div>
    </div>

    <section class="emh-module faq hiw-faq">

        <div class="emh-subtitle"><?php print t('Frequently Asked Questions') ?></div>

        <div>
          <h3 class="question question-alt"><?php print t('How will I be informed of new offers on Smart Mobility?'); ?></h3>

          <div class="answer">
            <p><?php print t('For each new request, you will receive an email notification with the title of the offer. By clicking on the link in the email, you can access the full detail of the offer.'); ?></p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt"><?php print t('Who can access the offers published on Smart Mobility?'); ?></h3>

          <div class="answer">
            <p><?php print t('Only those who are registered in the «&nbsp;Smart Mobility&nbsp;» circle can access offers, this includes requesters and employees of Airbus.'); ?></p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt"><?php print t('Who can access my profile?'); ?></h3>

          <div class="answer">
            <p><?php print t('Only those who are registered in the «&nbsp;Smart Mobility&nbsp;» circle can access the profiles of employees of Airbus.'); ?></p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt"><?php print t('Why fill up my profile?'); ?></h3>

          <div class="answer">
            <p><?php print t('It is recommended that you complete your profile as precisely as possible. Job requesters can pre-select candidates on the basis of responses to the questionnaire associated with the offer, as well as the detail provided in the candidate profile.'); ?></p>
          </div>
        </div>
        <div>
          <h3 class="question question-alt"><?php print t('How do I respond to an offer?'); ?></h3>

          <div class="answer">
            <p><?php print t('To respond to an offer, simply answer the questions associated with the request. The requester will automatically be informed of your response.'); ?></p>
          </div>
        </div>

    </section>

  </div>

</section>
