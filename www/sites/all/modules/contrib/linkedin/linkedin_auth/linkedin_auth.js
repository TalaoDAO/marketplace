
Drupal.behaviors.linkedin_status = function (context) {
  var $loginElements = $("#edit-name-wrapper, #edit-pass-wrapper, li.linkedin_auth-link");
  var $linkedin_authElements = $("#edit-linkedin_auth-identifier-wrapper, li.user-link");

  // This behavior attaches by ID, so is only valid once on a page.
  if (!$("#edit-linkedin_auth-identifier.linkedin_auth-processed").size() && $("#edit-linkedin_auth-identifier").val()) {
    $("#edit-linkedin_auth-identifier").addClass('linkedin_auth-processed');
    $loginElements.hide();
    // Use .css("display", "block") instead of .show() to be Konqueror friendly.
    $linkedin_authElements.css("display", "block");
  }
  $("li.linkedin_auth-link:not(.linkedin_auth-processed)", context)
    .addClass('linkedin_auth-processed')
    .click( function() {
       $loginElements.hide();
       $linkedin_authElements.css("display", "block");
      // Remove possible error message.
      $("#edit-name, #edit-pass").removeClass("error");
      $("div.messages.error").hide();
      // Set focus on linkedin_auth Identifier field.
      $("#edit-linkedin_auth-identifier")[0].focus();
      return false;
    });
  $("li.user-link:not(.linkedin_auth-processed)", context)
    .addClass('linkedin_auth-processed')
    .click(function() {
       $linkedin_authElements.hide();
       $loginElements.css("display", "block");
      // Clear linkedin_auth Identifier field and remove possible error message.
      $("#edit-linkedin_auth-identifier").val('').removeClass("error");
      $("div.messages.error").css("display", "block");
      // Set focus on username field.
      $("#edit-name")[0].focus();
      return false;
    });
};
