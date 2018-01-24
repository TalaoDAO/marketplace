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

      $('.hp-testimonies').slick({
        dots: true,
        speed: 500,
        autoplay: true,
        slidesToShow: 1,
        infinite: true,
        responsive: [{
          breakpoint: 769,
          settings: {
            slidesToShow: 1,
            dots: false
          }
        }]
      });

      /**
       * need expertise
       */
      $('.field-name-field-hp-how-need-slides .field-collection-container').slick({
        slidesToShow: 4,
        autoplay: true,
        dots: false,
        arrows: false,
        infinite: true,
        responsive: [{
          breakpoint: 767,
          settings: {
            slidesToShow: 1,
            slidesToScroll: 1,
            centerMode: true,
            centerPadding: '5%'
          }
        }]
      });
      /**
       * have expertise
       */
      $('.field-name-field-hp-how-have-slides .field-collection-container').slick({
        slidesToShow: 4,
        autoplay: true,
        dots: false,
        arrows: false,
        infinite: true,
        responsive: [{
          breakpoint: 767,
          settings: {
            slidesToShow: 1,
            slidesToScroll: 1,
            centerMode: true,
            centerPadding: '5%'
          }
        }]
      });
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
