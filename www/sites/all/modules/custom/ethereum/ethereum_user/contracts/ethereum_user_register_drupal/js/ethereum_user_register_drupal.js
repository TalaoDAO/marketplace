/**
 * @file
 */

(function ($) {

  Drupal.behaviors.ethereum_user_register_drupal = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        // Checking if Web3.js has been injected by the browser (Mist/MetaMask).
        // TODO: factor for general use.
        if (typeof web3 !== 'undefined') {
          window.web3 = new Web3(web3.currentProvider);
        }
        // Else fallback on a locally injected Web3.js.
        else {
          window.web3 = new Web3(new Web3.providers.HttpProvider(Drupal.settings.ethereum_user.ethereum_user_register_drupal_fallback_node));
        }

        // Helper function to get a contract.
        // TODO: factor for general use.
        getContract = function (address, abiJSON) {
          abi = JSON.parse(abiJSON);
          contract_holder = web3.eth.contract(abi);
          return contract_holder.at(address);
        }

        // Main code.
          contract = getContract(Drupal.settings.ethereum_user.ethereum_user_register_drupal_deployed_contract_address, Drupal.settings.ethereum_user.ethereum_user_register_drupal_deployed_contract_abi);
          console.log(Drupal.settings.ethereum_user.ethereum_user_register_drupal_deployed_contract_address);
          console.log(Drupal.settings.ethereum_user.ethereum_user_register_drupal_deployed_contract_abi);
          hash = Drupal.settings.ethereum_user.ethereum_user_register_drupal_user_hash;
          console.log(hash);
        $('#ethereum_user_register_drupal_trigger').click(function () {
          userAddress = Drupal.settings.ethereum_user.ethereum_user_register_drupal_user_address;
          console.log(userAddress);
          contract.newUser(hash, {from : userAddress});
          // TODO: listen to transaction receipt and update #ethereum_user_register_drupal_trigger HTML.
          // TODO: then, Ajax / Drupal service callback to assign the 'registered ethereum user' role to the user.
        });
          address = contract.validateUserByHash(hash);
          console.log(address);
      });
    }
  }
}(jQuery));
