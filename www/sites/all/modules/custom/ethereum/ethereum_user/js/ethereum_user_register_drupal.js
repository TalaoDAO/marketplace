/**
 * @file
 */

(function ($) {

  Drupal.behaviors.ethereum_user_register_drupal = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        // Checking if Web3.js has been injected by the browser (Mist/MetaMask).
        // NOTE: MetaMask does not support Web3 1.0.0 yet, this won't work, check the metamask branch. It should (maybe) work when Metamask updates to 1.0.0.
        if (typeof web3 !== 'undefined') {
          window.web3 = new Web3(web3.currentProvider);
          var accounts = web3.eth.getAccounts(function (error, accounts) {
            if (error) {
              console.log(error);
            }
          });
          var user_address = accounts[0];
          if (user_address != Drupal.settings.ethereum_user.user.address.toLowerCase()) {
            console.log('Current active Ethereum address:' + user_address + ' - Registred Ethereum address on this site:' + Drupal.settings.ethereum_user.user.address + ' - They should be the same.');
          }
        }
        // Else try to use a locally injected Web3.js.
        else {
          window.web3 = new Web3(new Web3.providers.HttpProvider(Drupal.settings.ethereum_user.node));
          var user_address = Drupal.settings.ethereum_user.user.address.toLowerCase();
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
          else if (result.toLowerCase() == user_address) {
            $('#ethereum_user_registry_wait').toggle('fast');
            $('#ethereum_user_registry_validated').toggle('fast');
          }
          else {
            $('#ethereum_user_registry_wait').toggle('fast');
            $('#ethereum_user_registry_sign').toggle('fast');
            $('#ethereum_user_registry_sign a').click(function () {
              $('#ethereum_user_registry_sign').html('<p>Your Ethereum wallet is waiting for you to sign this transaction.</p>');

              // TODO: handle the error if the user rejects the transaction.
              contract.methods.newUser(user_hash).send({from: user_address})
              .on('transactionHash', function (transactionHash) {
                $('#ethereum_user_registry_sign').html('<p>Please wait between 10 seconds and a few minutes for the transaction to be mined on the Ethereum network. You can reload this page at any time to see if the transaction is confirmed. Or you can <a href="https://etherscan.io/tx/' + transactionHash + '" target="_blank">see the transaction status in live</a>.</p>');
              })
              .on('error', function (error) {
                // 0 is "success error" in RegisterDrupal.sol.
                if (error != 0) {
                  console.error;
                }
              })
              .on('confirmation', function (confirmationNumber, receipt) {
                // Should be 0 because there's no block after this transaction yet.
                console.log('Number of confirmation blocks: ' + confirmationNumber);
              })
              .then(function (receipt) {
                // Fires once the receipt is mined.
                $('#ethereum_user_registry_sign').html('<p>Congratulations! Ethereum network just confirmed your signature of our user registry. You can now use Ethereum features with this site.');
              });
            });
          }
        });
      });
    }
  }
}(jQuery));
