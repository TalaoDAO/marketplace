(function($) {
  jQuery(document).ready(function () { 		
    $("#edit-language").change(function () {		   
      if($('#edit-language').val() == 'fr') {
        $('.emh_opencalais_button_holder').hide();
      } else {
        $('.emh_opencalais_button_holder').show();
      }
    }).change();	
  });
})(jQuery);
