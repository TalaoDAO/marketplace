/**
 * @file
 */

(function ($) {

  Drupal.behaviors.ethereum_user_register_drupal = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        // Checking if Web3.js has been injected by the browser (Mist/MetaMask).
        // TODO: check that Mist also sets web3.eth.accounts[0]
        if (typeof web3 !== 'undefined') {
          window.web3 = new Web3(web3.currentProvider);
          var user_address = web3.eth.accounts[0];
        }
        // Else fallback on a locally injected Web3.js.
        else {
          window.web3 = new Web3(new Web3.providers.HttpProvider(Drupal.settings.ethereum_user.fallback_node));
          var user_address = Drupal.settings.ethereum_user.user.address;
        }

        // Get contract object.
        var contract_abi = JSON.parse(Drupal.settings.ethereum_user.contract.abi);
        var contract_address = Drupal.settings.ethereum_user.contract.address;
        var contract = new web3.eth.Contract(contract_abi, contract_address);

        // User hash.
        var user_hash = Drupal.settings.ethereum_user.user.hash;

        // Check if the user already signed the contract.
        contract.methods.validateUserByHash(user_hash).call({from: user_address}, function (error, result) {
          if (error) {
            console.log(error);
          }
          else if (result.toLowerCase() == user_address.toLowerCase()) {
            console.log(user_address);
            $('#ethereum_user_registry_wait').toggle('fast');
            $('#ethereum_user_registry_validated').toggle('fast');
          }
          else {
            $('#ethereum_user_registry_wait').toggle('fast');
            $('#ethereum_user_registry_sign').toggle('fast');
            $('#ethereum_user_registry_sign a').click(function () {
              $('#ethereum_user_registry_sign').html('<p>Your Ethereum wallet is waiting for you to sign this transaction.</p>');
              contract.methods.newUser(user_hash).send({from: user_address}, function (error, transactionHash) {
                if (error) {
                  console.log(error);
                }
                else {
                  $('#ethereum_user_registry_sign').html('<p>Please wait between 10 seconds and a few minutes for the transaction to be mined on the Ethereum network. You can reload this page at any time to see if the transaction is confirmed. Or you can <a href="https://etherscan.io/tx/' + transactionHash + '" target="_blank">see the transaction status in live</a>.</p>');
                }
              });
            });
          }
        });
      });
    }
  }
}(jQuery));
