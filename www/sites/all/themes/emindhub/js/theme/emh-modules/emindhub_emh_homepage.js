/**
 * @file
 */

(function ($) {

  Drupal.behaviors.emindhub_emh_homepage = {
    attach: function (context, settings) {

      // Particles.
      particlesJS.load('particles-js', 'sites/all/themes/emindhub/particles.json', function () {
        console.log('callback - particles.js config loaded');
      });

      // Close closed popups.
      $('.popup-closed').hide();

      // Sliders.
      $('.hp-testimonies').slick();
      // TODO fix tabs and sliders: https://github.com/kenwheeler/slick/issues/619#issuecomment-67228390
      $('.field-name-field-hp-how-need-slides .field-collection-container').slick();
      $('.field-name-field-hp-how-have-slides .field-collection-container').slick();

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

      // Change some classes.
      $('.hp-solutions .col-sm-9 .col-sm-3') .removeClass('col-sm-3').addClass('col-sm-4');
      $('.hp-solutions .col-sm-3 .col-sm-3') .removeClass('col-sm-3');
      $('.private .col-xs-12') .addClass('no-padding radius');
    }
  }
}(jQuery));
