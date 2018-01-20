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

    }
  }
}(jQuery));
