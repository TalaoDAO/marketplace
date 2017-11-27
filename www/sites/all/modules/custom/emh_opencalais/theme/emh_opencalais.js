/**
 * @file emh_opencalais.js
 * Show or hide button to suggest tags
 */
(function($) {
  Drupal.behaviors.emhOpencalais = {
    attach: function(context, settings) {
      $("#edit-language").change(function () {		   
        if($('#edit-language').val() == 'fr') {
          $('.emh_opencalais_button_holder').hide();
        } else {
          $('.emh_opencalais_button_holder').show();
        }
      }).change();
    }
  }
})(jQuery);
