
/*
 * @file : hide the textfield on user posting form until enabled by checkbox.
 */
Drupal.behaviors.linkedin_status = function(context) {

  if (!$("#linkedin-status-posting").attr("checked")) {
    $("#linkedin-status-textfield-wrapper").hide();
  }
  $("#linkedin-status-posting").bind("click", function() {
    if ($("#linkedin-status-posting").attr("checked")) {
      $("#linkedin-status-textfield-wrapper").show();      
    }
    else {
      $("#linkedin-status-textfield-wrapper").hide();
    }
  });
}
