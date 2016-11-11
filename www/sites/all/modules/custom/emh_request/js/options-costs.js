(function($) {

    Drupal.behaviors.emhRequestOptionsCosts = {
      attach: function(context, settings) {
        var $optionsField = $('#edit-field-options', context);


        function updateOptionCost(optionId) {
          var $option = $optionsField.find('[data-emh-option="' + optionId + '"]');
          var cost = $option.find('input[type="hidden"]').val();

          $option.find('.cost').text(getFormattedCost(cost));
        }


        function updateTotalCost() {
          var total = 0;

          $optionsField.find(':checked').each(function() {
            var cost = $(this).parents('[data-emh-option]').children('input[type="hidden"]').val();
            total += Number(cost);
          });

          $optionsField.find('.total').text(getFormattedCost(total))
        }


        function getFormattedCost(cost) {
          if (Number(cost) == 0) {
            return Drupal.t("Free");
          }
          return Drupal.t("!amount credits", { '!amount': cost });
        }


        if ($optionsField) {
          $optionsField.find('input[type="hidden"]').change(function() {
            var optionId = $(this).parents('[data-emh-option]').attr('data-emh-option');
            updateOptionCost(optionId);
            updateTotalCost();
          });

          $optionsField.find('input[type="checkbox"]').change(function() {
            updateTotalCost();
          });
        }

        updateTotalCost();
      }
    };

}(jQuery));
