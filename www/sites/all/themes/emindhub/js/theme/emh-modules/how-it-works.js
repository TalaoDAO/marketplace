Drupal.behaviors.hiwTabs = {
    attach: function (context, settings) {
        jQuery('.hiw-tabs', context).once().on('click', 'button', function (e) {
            var $this = jQuery(this);
            jQuery('.' + $this.data('tab')).removeClass('hiw-hidden').siblings('.hiw-tab-content').addClass('hiw-hidden');
            jQuery('.hiw-tabs .active').removeClass('active');
            $this.addClass('active');
        });

        jQuery('.hiw-tabs', context).find('button').first().trigger('click');
    }
};
