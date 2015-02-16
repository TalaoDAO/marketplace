(function ($) {
  // Overwrite the jgrowl "close all" text to enable it for translation.
  $.jGrowl.defaults.closerTemplate = '<div>' + Drupal.t('close all') + '</div>';

  // Creating our own namespace for the module
  Drupal.pmGrowl = {};

  // This is an array to keep track of messages coming it which have already been displayed on the page.
  Drupal.pmGrowl.alreadyGrowled = new Array();

  Drupal.behaviors.pmGrowl = {
    attach: function (context) {
    /**
     * Check for new private messages and alert the user if there are new
     * messages available.
     */
    var pmGrowlCheckNew = function() {

      // Make the request to check for new messages and provide callback for
      // request.
      $.getJSON(Drupal.settings.basePath + 'messages/pmgrowl_json', function(data) {
        $(data).each(function(entryIndex, entry) {
          // For reach entry that comes back, check if it's a new message and
          // set newMessage accordingly.
          var newMessage = true;
          $(Drupal.pmGrowl.alreadyGrowled).each(function(index, mid) {
            if(entry['mid'] == mid) {
              newMessage = false;
            }
          });

          // Now if it is a new message, display the Growl notification, and add
          // this message to array of messages already displayed.
          if(newMessage == true) {
            $.jGrowl(entry['body'],
              {
                sticky: true,
                header: entry['subject'],
                open:	function(e,m,o) {
                  Drupal.attachBehaviors(m);
                },
                beforeClose : function(e, m) {
                  $.post(Drupal.settings.basePath + 'messages/pmgrowl_close', { mid : entry['mid'] });
                }
              }
            );
            Drupal.pmGrowl.alreadyGrowled.push(entry['mid']);
          }
        });
      });
    }

    // Make the initial call on page load.
    pmGrowlCheckNew();

    // Set the timer to check for new messages on a given interval.
    if (Drupal.settings.pmGrowlInterval != 0) {
      var messageTimer = setInterval(pmGrowlCheckNew, Drupal.settings.pmGrowlInterval);
    }
  }};
})(jQuery);
