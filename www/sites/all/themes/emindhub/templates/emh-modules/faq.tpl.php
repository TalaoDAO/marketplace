<section class="emh-module faq container">

    <div class="emh-subtitle"><?php echo t('Frequently asked questions') ?></div>

    <h3 class="question">[Experts] 1. I do not consider myself an expert, why register on eMindHub?</h3>
    <div class="answer">
        <p>Those that can bring value are experts on eMindHub. There are 2 options:</p>
        <ul>
            <li>By responding directly to a request because it matches your expertise and your experience</li>
            <li>By recommending an expert from your network who can reply to the request because it corresponds to his or her know-how and experience</li>
        </ul>
        <p>In other words, eMindhub considers as experts both those who know and those who know people who know.</p>
    </div>


    <h3 class="question question-alt">[Experts] 3. How does the credits system work?</h3>
    <div class="answer">
        <p>eMindHub makes you earn monetizable credits. There are two ways to earn points:</p>
        <ul>
            <li>As soon as a requester purchase&nbsp;your profile.</li>
            <li>By sponsoring an expert fom your network and whose profile is purchased by the requester.</li>
        </ul>
        <p>You earn credits whenever you recognizably add value to a requester.</p>
    </div>

    <h3 class="question">[Experts] 2. How will I be informed of new requests within my field of interest?</h3>
    <div class="answer">
        <p>You receive an email notification with the title of the request for each new request. This enables you to immediately decide whether you are interested in the request for yourself or for an expert in your network.</p>
        <p>You can choose to receive notifications only for those requests that correspond to the area of ​​expertise that you have filled in your profile ("domains" field).</p>
    </div>


    <div class="emh-actions">

      <div class="emh-action">
        <?php print t('CHANGEME Vous êtes expert en aéronautique ? Répondez aux demandes et gagnez des crédits'); ?> <a class="emh-button solid-alt" href="#"><?php print t('CHANGEME Proposer une expertise'); ?></a>
      </div>

    </div>

    <script type="text/javascript">
        Drupal.behaviors.faq = {
            attach: function (context, settings) {
                jQuery('.emh-module.faq', context).once(function (e) {
                    var $this = jQuery(this);

                    /**
                     * Initialy close all answers
                     */
                    $this.find('.answer').hide();

                    /**
                     * Add click event to questions
                     */
                    $this.find('.question').on('click', function () {
                        jQuery(this).next().slideToggle().siblings('.answer').slideUp();
                        jQuery(this).toggleClass('active').siblings('.question').removeClass('active');
                    });
                });
            }
        };
    </script>
</section>
