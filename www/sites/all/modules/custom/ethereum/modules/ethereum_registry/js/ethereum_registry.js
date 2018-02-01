/**
 * @file
 */

(function ($) {

  Drupal.behaviors.ethereum_registry = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        var contract = Drupal.behaviors.ethereum_smartcontract.loadContract('register_drupal');
        var user_address = Drupal.settings.ethereum_user.user.address.toLowerCase();
        var user_hash = Drupal.settings.ethereum_user.user.hash;

        // Check if the user already signed the contract.
        contract.methods.validateUserByHash(user_hash).call(function (error, result) {
          if (error) {
            console.log(error);
          }
          else if (result.toLowerCase() == user_address) {
            $('#ethereum_registry_wait').toggle('fast');
            $('#ethereum_registry_validated').toggle('fast');
          }
          else {
            $('#ethereum_registry_wait').toggle('fast');
            $('#ethereum_registry_sign').toggle('fast');
            $('#ethereum_registry_sign a').click(function () {
              $('#ethereum_registry_sign').html('<p>Your Ethereum wallet is waiting for you to sign this transaction.</p>');

              // TODO: handle the error if the user rejects the transaction.
              contract.methods.newUser(user_hash).send({from: user_address})
              .on('transactionHash', function (transactionHash) {
                $('#ethereum_registry_sign').html('<p>Please wait between 10 seconds and a few minutes for the transaction to be mined on the Ethereum network. You can reload this page at any time to see if the transaction is confirmed. Or you can <a href="https://etherscan.io/tx/' + transactionHash + '" target="_blank">see the transaction status in live</a>.</p>');
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
                $('#ethereum_registry_sign').html('<p>Congratulations! Ethereum network just confirmed your signature of our user registry. You can now use Ethereum features with this site.');
              });
            });
          }
        });
      });
    }
  }
}(jQuery));
