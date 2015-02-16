(function ($) {
  Drupal.behaviors.menuimageUpload = {
    attach: function (context, settings) {
      $('.form-item-menuimage .form-managed-file').ajaxComplete(function (event, request, settings) {
        var submitButton = $(event.target).find("input[type=submit]");
        var previewImage = $(event.target).parents(".fieldset-wrapper").find("img");
        var uploadedImage = $(event.target).find("span a");
        $(uploadedImage).click(function (event) {event.preventDefault();});
        if (submitButton.length != 0 && previewImage.length != 0) {
          switch (submitButton[0].value) {
            case "Remove":
              $($(previewImage[0])).attr("src", $(uploadedImage).attr("href")).attr("height", 75).removeAttr("width");
              break;

            case "Upload":
              $($(previewImage[0])).attr("src", Drupal.settings.menuimageBlank).attr({'width': 75, 'height': 75});
              break;

          }
        }
      });
    }
  };
  $(document).ready(function () {
    $('.form-item-menuimage .form-managed-file span a').click(function (event) {event.preventDefault();});
  });
}) (jQuery);
