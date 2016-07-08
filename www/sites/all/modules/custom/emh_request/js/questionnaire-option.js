(function($) {

    Drupal.behaviors.emhRequestQuestionnaireOption = {
      attach: function(context, settings) {
        var $draftButton = $('#edit-draft', context);
        var $optionCheckbox = $('#edit-field-options [data-emh-option="questionnaire"] input[type="checkbox"]', context);

        if ($draftButton.length && $optionCheckbox.length) {
          function updateDraftButton() {
            if ($optionCheckbox.is(':checked')) {
              $draftButton.text(Drupal.t("Save and continue"));
            } else {
              $draftButton.text(Drupal.t("Save draft"));
            }
          }

          updateDraftButton();

          $optionCheckbox.change(updateDraftButton);
        }
      }
    };

}(jQuery));


