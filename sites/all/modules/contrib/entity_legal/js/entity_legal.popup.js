/**
 * @file
 * Drupal behaviors for Entity Legal popup acceptance method.
 */

/*global Drupal, window, jQuery*/

(function ($) {
  "use strict";
  /**
   * Modal popup for Entity Legal module.
   *
   * Executed using core jQuery ui dialog with modifications to prevent user
   * from closing the popup.
   */
  Drupal.behaviors.entityLegalPopup = {
    attach: function (context, settings) {
      $.each(settings.entityLegalPopup, function (index, value) {
        var $popup = $('<div />').html(value.popupContent);
        $popup.dialog({
          autoOpen: true,
          closeOnEscape: false,
          modal: true,
          draggable: false,
          title: value.popupTitle,
          width: '80%',
          beforeClose: function(event, ui) {
            // Prevent closing of modal window.
            return false;
          },
          open: function(event, ui) {
            // Remove close button from titlebar when opening.
            $popup.closest('.ui-dialog').find('.ui-dialog-titlebar-close').remove();
          }
        })
      });
    }
  };
}(jQuery));
