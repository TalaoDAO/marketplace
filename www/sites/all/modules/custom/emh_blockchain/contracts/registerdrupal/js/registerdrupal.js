(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        getContract = function (address, abi) {
          abi = JSON.parse(ABI);
          contract_holder = web3.eth.contract(abi);
          return contract_holder.at(address);
        }

        // Checking if Web3 has been injected by the browser (Mist/MetaMask).
        if (typeof web3 !== 'undefined') { // Use Mist/MetaMask's provider.
          window.web3 = new Web3(web3.currentProvider);
        } else { // Fallback on local testrpc chain.
          window.web3 = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));
        }
        register_drupal_address = Drupal.settings.emh_blockchain.register_drupal_deployed_contract_address_fallback;
        register_drupal_abi = JSON.parse(Drupal.settings.emh_blockchain.register_drupal_deployed_contract_ABI);
        register_drupal_contract_holder = web3.eth.contract(register_drupal_abi);
        register_drupal_contract = register_drupal_contract_holder.at(register_drupal_address);

        token_emh_address = Drupal.settings.emh_blockchain.token_emh_deployed_contract_address_fallback;
        token_emh_abi = JSON.parse(Drupal.settings.emh_blockchain.token_emh_deployed_contract_ABI);
        token_emh_contract_holder = web3.eth.contract(token_emh_abi);
        token_emh_contract = token_emh_contract_holder.at(token_emh_address);

        //token_emh_contract = getContract(Drupal.settings.emh_blockchain.token_emh_deployed_contract_address_fallback, Drupal.settings.emh_blockchain.token_emh_deployed_contract_ABI);

        hash = Drupal.settings.emh_blockchain.userHash;
        userAddress = register_drupal_contract.validateUserByHash(hash);
        console.log(userAddress);
        /*register_drupal_contract.validateUserByHash.call(hash,
          function (error, result) {
            if (!error) {
              $("#debug").html('user address: '+result.toString());
              console.log(result);
            }
            else {
              console.error(error);
            }
        });*/
        $("#debug").html('user address: '+userAddress.toString());
        balance = token_emh_contract.balanceOf(userAddress.toString()).toFormat();
        console.log(balance);
        $("#debug").html( $("#debug").text()+ ' balance : '+balance);
      });
    }
  }
}(jQuery));
