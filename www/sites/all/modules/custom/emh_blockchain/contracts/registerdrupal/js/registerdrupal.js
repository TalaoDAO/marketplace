(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {
        // Checking if Web3 has been injected by the browser (Mist/MetaMask).
        if (typeof web3 !== 'undefined') {
          // Use Mist/MetaMask's provider.
          window.web3 = new Web3(web3.currentProvider);
          var register_drupal_deployed_contract_address = Drupal.settings.emh_blockchain.register_drupal_deployed_contract_address;
        }
        else {
          // Fallback on local testrpc chain.
          window.web3 = new Web3(new Web3.providers.HttpProvider("http://ethdev:8545"));
          var register_drupal_deployed_contract_address = Drupal.settings.emh_blockchain.register_drupal_deployed_contract_address_fallback;
        }
        abi = JSON.parse(Drupal.settings.emh_blockchain.register_drupal_deployed_contract_ABI);
        hash = Drupal.settings.emh_blockchain.userHash.toUpperCase();
        console.log(hash);
        Contract = web3.eth.contract(abi);
        contractInstance = Contract.at(register_drupal_deployed_contract_address);
        console.log(contractInstance);
        userAddress = contractInstance.validateUserByHash(hash);
        console.log(userAddress);
        contractInstance.validateUserByHash.call(hash,
          function (error, result) {
            if (!error) {
              $("#debug").html(result.toString());
              console.log('done '+result);
            }
            else {
              console.error(error);
            }
          });
      });
    }
  }
}(jQuery));
