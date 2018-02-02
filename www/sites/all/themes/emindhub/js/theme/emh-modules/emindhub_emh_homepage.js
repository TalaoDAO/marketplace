/**
 * @file
 */

(function ($) {

  Drupal.behaviors.emindhub_emh_homepage = {
    attach: function (context, settings) {

      // Hero > Particles.
      particlesJS.load('particles-js', 'sites/all/themes/emindhub/particles.json');

      // Hero > Experts popups.
      $('.hp-expert-image', context).once('emindhub_emh_homepage', function () {
        $(this).click(function () {
          $('.hp-expert-popup').click().hide();
        });
      });
      var experts = $('.hp-expert-popup');
      $('.hp-expert-image').css('cursor','pointer').click(function () {
        event.stopPropagation();
        var expert = $(this).next('.hp-expert-popup').stop(true).slideToggle(100);
        experts.not(expert).filter(':visible').stop(true).slideUp();
      });

      // Domains.
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

      // Clients.
      $('.hp-clients .field-items').slick({
        speed: 500,
        autoplaySpeed: 1500,
        autoplay: true,
        infinite: true,
        slidesToShow: 7,
        responsive: [
          {
            breakpoint: 9999,
            settings: "unslick"
          },
          {
            breakpoint: 768,
            settings: {
              slidesToShow: 1,
            }
          }
        ]
      });

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
            dots: true
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
        infinite: false,
        responsive: [{
          breakpoint: 767,
          settings: {
            slidesToShow: 1,
            slidesToScroll: 1,
            centerMode: true,
            centerPadding: '5%',
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
        infinite: false,
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

      // Change some classes.
      $('.hp-solutions .col-sm-9 .col-sm-3') .removeClass('col-sm-3').addClass('col-sm-4');
      $('.hp-solutions .col-sm-3 .col-sm-3') .removeClass('col-sm-3');
      $('.private .col-xs-12') .addClass('no-padding radius');

		/**
		 * juste au dessus du footer le dernier texte less ligne 653
		 */
		$( "<div class='container lastWrapper'><p>48 hours a typical cycles</p></div>" ).insertAfter( ".hp-how .container .tab-content" );
  	}
  }
}(jQuery));
