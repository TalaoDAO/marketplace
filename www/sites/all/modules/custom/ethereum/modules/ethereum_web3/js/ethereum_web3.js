/**
 * @file
 */

(function ($) {

  Drupal.behaviors.ethereum_web3 = {
    attach: (context, settings) => {

      // If the browser has injected Web3.js
      if (window.web3) {
        // Then backup the good old injected Web3, sometimes it's usefull:
        window.web3old = window.web3;
        // And replace the old injected version by the local Web3.JS version 1.0.0-beta.N
        window.web3 = new Web3(window.web3.currentProvider);
        window.web3.eth.getAccounts().then(_accounts => {
          if (_accounts.length == 0) {
            Drupal.behaviors.ethereum_web3.message('Your browser is Ethereum-capable, but not account is available. You probably need to click the Metamask extension button and log in.', 'error');
          }
        });
        // Detect the network.
        window.web3.eth.net.getNetworkType().then(_network => {
          if (_network != Drupal.settings.ethereum_web3.network) {
            Drupal.behaviors.ethereum_web3.message('You must switch to ' + Drupal.settings.ethereum_web3.network + ' Ethereum network in your browser/extension.', 'error');
          }
        });
      }
      // No Web3.js means no accounts => 2 solutions:
      // 1) Some modules tried to use Ethereum features without _ethereum_user_ready().
      // 2) This time, the user did not enable a Web3 provider like Metamask.
      else {
        Drupal.behaviors.ethereum_web3.message('Your account is linked with Ethereum. You need to use an Ethereum-capable browser or Metamask. Or you can <a href="/user/ethereum">disable Ethereum features by deleting your Ethereum address in your account</a>.', 'error');
      }
    }
  }

  Drupal.behaviors.ethereum_web3.message = function (_message, _type) {

    let className;
    if (_type == 'warning') {
      className = Drupal.settings.ethereum_web3.messages_warning;
    }
    else if (_type == 'error') {
      className = Drupal.settings.ethereum_web3.messages_error;
    }
    else {
      className = Drupal.settings.ethereum_web3.messages_status;
    }
    $(Drupal.settings.ethereum_web3.messages_selector).attr('class', Drupal.settings.ethereum_web3.messages_base);
    $(Drupal.settings.ethereum_web3.messages_selector).addClass(className);
    $(Drupal.settings.ethereum_web3.messages_selector).html(_message);
  }

  Drupal.behaviors.ethereum_web3.error = function (error) {
    Drupal.behaviors.ethereum_web3.message('There was an error. Check your Ethereum wallet and/or the Javascript console (F12).', 'error');
    console.log(error);
  }

}(jQuery));
