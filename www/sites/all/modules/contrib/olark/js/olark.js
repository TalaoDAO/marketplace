/*jslint browser: true*/
/*global jQuery, Drupal */

/**
 * @file
 * Attaches behaviors for Olark iOS and users.
 */

(function (Drupal, olark, navigator) {

  'use strict';

  /**
   * Olark behavior.
   * @type {Drupal~behavior}
   */
  Drupal.behaviors.olark = {
    attach: function (context, settings) {
      if (olark === undefined) {
        return;
      }

      // Providing user details to the Olark API.
      if (settings.olark.uid !== undefined) {
        olark('api.visitor.getDetails', function (details) {
          olark('api.chat.updateVisitorNickname', {
            snippet: settings.olark.name,
            hidesDefault: true
          });

          olark('api.chat.updateVisitorStatus', {
            snippet: settings.olark.mail + ' | ' + settings.olark.userpage
          });

          olark('api.visitor.updateFullName', { fullName: settings.olark.name });
          olark('api.visitor.updateEmailAddress', { emailAddress: settings.olark.mail });
        });
      }

      // Hides Olark box if agent is iPod, iPad, iPhone.
      if (settings.olark.disable_ios && settings.olark.enabled) {
        olark('api.box.onShow', function () {
          var agent = navigator.userAgent.toLowerCase();
          if (agent.match(/iP(hone|ad)/i)) {
            olark('api.box.hide');
          }
        });
      }
    }
  };
}(Drupal, olark, navigator));
