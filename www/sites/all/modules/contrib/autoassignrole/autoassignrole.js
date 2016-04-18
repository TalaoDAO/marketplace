(function($) {

  Drupal.behaviors.autoassignrole = {
    attach: function (context, settings) {
      if ($('input[name="autoassignrole_user_active"]:checked', context).val() == 0) {
        $('#autoassignrole_user_description_wrapper').hide();
      }
      $('input[name="autoassignrole_user_active"]', context).click(function () {
        if ($(this).val() == 0) {
          $('#autoassignrole_user_description_wrapper').hide();
        } else {
          $('#autoassignrole_user_description_wrapper').show();
        }
      });
    }
  };

})(jQuery);