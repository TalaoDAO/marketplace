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
        // Else fallback on a locally injected Web3.js.
        else {
          window.web3 = new Web3(new Web3.providers.HttpProvider(Drupal.settings.ethereum_user.fallback_node));
          //var user_address = Drupal.settings.ethereum_user.user.address.toLowerCase();
        }

        // Get contract object.
        var contract_abi = JSON.parse(Drupal.settings.ethereum_user.contract.abi);
        var contract_address = Drupal.settings.ethereum_user.contract.address;
        var contract = new web3.eth.Contract(contract_abi, contract_address);

        // Get subscribers.
        contract.getPastEvents('AccountCreatedEvent', {fromBlock: 0, toBlock: 'latest'}, function (error, result) {
          if (error) {
            console.log(error);
          }
          else {
            result.forEach(function (event) {
              // Add a row to the table.
              $('#ethereum_user_registry_list tr:last').after('<tr><td>' + event.returnValues.from + '</td><td>' + event.returnValues.hash + '</td><td></td></tr>');
            });
          }
        });
      });
    }
  }
}(jQuery));
