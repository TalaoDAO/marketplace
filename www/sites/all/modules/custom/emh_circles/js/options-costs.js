(function($) {

    Drupal.behaviors.emhCirclesOptionsCosts = {
      attach: function(context, settings) {

        var $circlesField = $('#edit-og-group-ref', context);
        var $optionsField = $('#edit-field-options', context);


        function selectCosts(circles) {
          var costs = {};

          // Returns an empty object if the array expected
          // as parameter is not valid
          if (!circles || circles.length == 0) {
            return costs;
          }

          // Selects the highest cost (from circles) for each option
          for (var i = 0; i < circles.length; i++) {
            var circleId = Number(circles[i]);
            var circleCosts = settings.circlesOptionsCosts.circles[circleId];

            for (var j in circleCosts) {
              if (typeof costs[j] == 'undefined' || costs[j] < circleCosts[j]) {
                costs[j] = Number(circleCosts[j]);
              }
            }
          }

          // Completes the costs array with the default costs
          // when there isn't yet a cost for an option
          for (var k in settings.circlesOptionsCosts.default) {
            if (typeof costs[k] == 'undefined') {
              costs[k] = Number(settings.circlesOptionsCosts.default[k]);
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

