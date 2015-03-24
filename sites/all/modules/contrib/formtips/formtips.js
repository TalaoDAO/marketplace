(function ($) {

Drupal.behaviors.formtips = {
  attach: function (context) {
    var settings = Drupal.settings.formtips,
        selectors = $.isArray(settings.selectors) ? settings.selectors.join(', ') : settings.selectors;

    $('.form-item .description')
      .not(selectors).not('.formtips-processed')
        .addClass('formtips-processed').each(function(index) {

          var description = $(this),
              item = $(this).closest('.form-item'),
              label = item.find('label:first');

          description.hide();
          item.css('position', 'relative');
          label.wrap('<div class="formtips-wrapper clear-block"/>').append('<a class="formtip"></a>');

          if (settings.trigger_action == 'click') {
            item.find('.formtip').click(function(e) {
              description.toggle('fast');
              e.preventDefault();
            });
          }
          else {
            item.find('.formtip').hoverIntent({
              sensitivity: settings.sensitivity,
              interval: settings.interval,
              over: function () {
                description.show('fast');
              },
              timeout: settings.timeout,
              out: function () {
                description.hide('fast');
              }
            });
          };
    });
    $('.form-item .description.formtips-processed').css('max-width', settings.maxWidth);
  }
};

})(jQuery);
