/**
 * @file
 */

(function ($) {

  Drupal.behaviors.ethereum_user = {
    attach: (context, settings) => {

      window.web3.eth.getAccounts().then(accounts => {
        if (accounts[0].toLowerCase() != Drupal.settings.ethereum_user.user.address.toLowerCase()) {
          Drupal.behaviors.ethereum_web3.message('Your active Ethereum account provided by your browser is different than the Ethereum address you specified in your profile. Please switch to the correct account in your browser or update your profile. Active: <em>' + accounts[0].toLowerCase() + '</em> / Profile: <em>' + Drupal.settings.ethereum_user.user.address.toLowerCase() + '</em>', 'error');
        }
      });
    }
  }

}(jQuery));
