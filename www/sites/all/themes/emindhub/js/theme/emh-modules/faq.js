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
