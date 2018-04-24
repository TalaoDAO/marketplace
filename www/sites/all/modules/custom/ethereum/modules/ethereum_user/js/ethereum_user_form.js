/**
 * @file
 */

(function ($) {

  Drupal.behaviors.ethereum_user_form = {
    attach: function (context, settings) {
      // Hide and show field to change Ethereum address.
      $('#ethereum_user_address_trigger').click(function () {
        $('#ethereum-user-form').toggle('fast');
      });
      // If Web3 is not available, warn the user.
      if (window.web3 === undefined) {
        $('#ethereum_user_address').append('<p><strong>You must use an Ethereum compatible browser or an extension when you have an Ethereum address in your account. Please do so or remove the Ethereum address in your account to come back to the classic experience without Ethereum. If you do not fix this, errors will occur.</strong></p>')
      }
    }
  }
}(jQuery));
