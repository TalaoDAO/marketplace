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


      $('#main-nav.navbar-emh').after($('<div class="inverse" id="navbar-height-col"></div>'));
      $('#main-nav.navbar-default').after($('<div id="navbar-height-col"></div>'));

      var slidewidth = '20%';
      var navbarneg = '-' + slidewidth;

      if ($(window).width() < 767) {
        $('#navbar-height-col').css("width", slidewidth);
        $('#navbar-height-col').css("left", navbarneg);
        $('#slide-nav #slidemenu').css("width", slidewidth);
        $('#slide-nav #slidemenu').css("left", navbarneg);
      }

      $("#slide-nav").on("click", '.navbar-toggle', function(e) {

        // slider is active
        var selected = $(this).hasClass('slide-active');

        // set slidemenu width
        $('#slidemenu').stop().animate({
          left: selected ? navbarneg : '0px'
        });

        // set navbar width
        $('#navbar-height-col').stop().animate({
          left: selected ? navbarneg : '0px'
        });

        // set content let
        $('#page-content').stop().animate({
          left: selected ? '0px' : slidewidth
        });

        // set navbar left
        $('.navbar-header').stop().animate({
          left: selected ? '0px' : slidewidth
        });

        $(this).toggleClass('slide-active', !selected);
        $('#slidemenu').toggleClass('slide-active');

        $('#page-content, .navbar, body, .navbar-header').toggleClass('slide-active');
      });

      var selected = '#slidemenu, #page-content, body, .navbar, .navbar-header';

      $(window).on("resize", function() {
        if ($(window).width() > 767 && $('.navbar-toggle').is(':hidden')) {
          $(selected).removeClass('slide-active');
        }
      });





    }
  }
}(jQuery));
