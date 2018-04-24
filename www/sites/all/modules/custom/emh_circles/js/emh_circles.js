/**
 * @file
 */

(function ($) {

  Drupal.behaviors.emh_circles = {
    attach: (context, settings) => {
      window.addEventListener('load', () => {
        if (Drupal.settings.ethereum_user !== undefined) {
          // Check if the user is an active Freelancer on Talao DAO and if he joined from the Marketplace.
          Drupal.behaviors.emh_ethereum_Freelancer.isActiveOnMarketplace()
          .then((isActiveOnMarketplace) => {
            if (isActiveOnMarketplace) {
              // Yes.
              Drupal.behaviors.ethereum_web3.message('You are an active member of the Talao DAO, great! Joining a Circle on this Marketplace will automatically ask you to sign the corresponding Talao community, as well.', 'status');
            }
            // No.
            else {
              Drupal.behaviors.ethereum_web3.message('Please check your <a href="/user/ethereum">Ethereum settings</a> if you want to join the corresponding Community on Talao DAO, when joining a Circle.', 'warning');
            }
          })
          .catch((error) => {
            Drupal.behaviors.ethereum_web3.error(error);
          });
        }
      });
    }
  }
}(jQuery));
