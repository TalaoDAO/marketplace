/**
 * @file
 */

(function ($) {

  Drupal.behaviors.emindhub_emh_homepage = {
    attach: function (context, settings) {
      // Normal JS in here. Use $() instead of jQuery(), like:
      $('.emh-popup-closed').hide();

      // Sliders.
      $('.slick-how-need').slick();
      $('.slick-how-have').slick();

      // Animated Gif on hover.
      $(function () {
        $('.vocabulary-domaine img').each(function () {
          var src = $(this).attr('src');
          var gif = $(this).parent().attr("data-src");
          $(this).hover(function () {
            $(this).attr('src', gif);
          }, function () {
            $(this).attr('src', src);
          });
        });
      });
      /**
       * ajout des classes bootstrap sur hp-domains
       * TODO
       */
      $('.field-name-field-hp-domains .field-items .field-item') .addClass('col-xs-6 col-sm-3');

      /**
       * ajout des classe boobtstrap sur hp-solutions
       * TODO
       */
      $('.hp-solutions .field-name-field-hp-solutions-slides-blue') .addClass('col-xs-12 col-sm-8');
      $('.hp-solutions .field-name-field-hp-solutions-slides-orange') .addClass('col-xs-12 col-sm-4');
    }
  }
}(jQuery));
