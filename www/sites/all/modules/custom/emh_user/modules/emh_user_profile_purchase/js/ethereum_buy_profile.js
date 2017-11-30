(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        getContract = function (address, abiJSON) {
          abi = JSON.parse(abiJSON);
          contract_holder = new web3.eth.Contract(abi, address);
          return contract_holder;
        }
        // Checking if Web3 has been injected by the browser (Mist/MetaMask).
        if (typeof web3 !== 'undefined') { // Use Mist/MetaMask's provider.
          window.web3 = new Web3(web3.currentProvider);
        } else { // Fallback on local testrpc chain.
          window.web3 = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));
        }
        token_emh_contract = getContract(Drupal.settings.emh_blockchain.token_emh_deployed_contract_address_fallback, Drupal.settings.emh_blockchain.token_emh_deployed_contract_ABI);
        clientAddress = Drupal.settings.emh_blockchain.clientAddress;
        expertAddress = Drupal.settings.emh_blockchain.expertAddress;
        //console.log(clientAddress);
        //console.log(expertAddress);
        token_emh_contract.methods.balanceOf(clientAddress).call().then(function(result){console.log(result);});
        token_emh_contract.methods.balanceOf(expertAddress).call().then(function(result){console.log(result);});
        validated = false;
        $('#edit-submit', context).on('click', function(){
           if (validated) return true;
           result = token_emh_contract.methods.transfer(expertAddress, 1).send({from:clientAddress})
            .then( receipt => {validated = true; $('#edit-submit', context).click(); })
            .catch(error => alert('Request rejected') );
           console.log(result);
           return false;
        });
      });
    }
  }
}(jQuery));

