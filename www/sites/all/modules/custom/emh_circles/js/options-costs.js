(function($) {

    Drupal.behaviors.emhCirclesOptionsCosts = {
      attach: function(context, settings) {

        var $circlesField = $('#edit-og-group-ref', context);
        var $optionsField = $('#edit-field-options', context);


        function selectCosts(circles) {
          // We always start from the default costs, then we clone them
          var costs = jQuery.extend(true, {}, settings.circlesOptionsCosts.default);

          for (var i = 0; i < circles.length; i++) {
            var circleId = Number(circles[i]);
            var circleCosts = settings.circlesOptionsCosts.circles[circleId];

            for (var id in circleCosts) {
              if (i > 0 && costs[id] < circleCosts[id]) {
                costs[id] = Number(circleCosts[id]);
              } else {
                costs[id] = Number(circleCosts[id]);
              }
            }
          }

          return costs;
        }


        $circlesField.find('select').change(function() {
          var circles = $(this).val();
          var costs = selectCosts(circles);

          for (var id in costs) {
            $optionsField
              .find('[data-emh-option="' + id + '"] input[type="hidden"]')
              .val(costs[id])
              .trigger('change');
            // We have to manually trigger the change event
            // because the val() method doesn't do it.
            // http://stackoverflow.com/questions/3179385/val-doesnt-trigger-change-in-jquery
          }
        });
      }
    };

}(jQuery));

