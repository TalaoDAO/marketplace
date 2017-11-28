(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        getContract = function (address, abiJSON) {
          abi = JSON.parse(abiJSON);
          contract_holder = new web3.eth.Contract(abi, address);
          return contract_holder;
        }

        autoSign = function() {
          $.ajax({
            type:"POST",  url: "http://ethdev:8545", Accept : "application/json", contentType: "application/json",  dataType: "json",
            data: JSON.stringify({"method":"signer_requestsToConfirm","params":[],"id":1,"jsonrpc":"2.0"}),
            success: function(result) { 
              console.log(result);
              if (result.result == []) alter('Could not sign');
              if (result.result[0] == undefined) alter('Could not sign');
              id = result.result[0].id;
              pass = $('#eth-password').val();
              $.ajax({
                type:"POST", url: "http://ethdev:8545", Accept : "application/json", contentType: "application/json", dataType: "json",
                data: JSON.stringify({"method":"signer_confirmRequest","params":[id, {}, pass],"id":1,"jsonrpc":"2.0"}),
                success: function(result) { alert('transaction validated automatically'); }
              });
            }
          });
        }

        // Checking if Web3 has been injected by the browser (Mist/MetaMask).
        if (typeof web3 !== 'undefined') { // Use Mist/MetaMask's provider.
          window.web3 = new Web3(web3.currentProvider);
        } else { // Fallback on local testrpc chain.
          window.web3 = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));
        }

        token_emh_contract = getContract(Drupal.settings.emh_blockchain.token_emh_deployed_contract_address_fallback, Drupal.settings.emh_blockchain.token_emh_deployed_contract_ABI);
        clientAddress = Drupal.settings.emh_blockchain.clientAddress;
        $("#client-address").html(clientAddress.toString());
        token_emh_contract.methods.balanceOf(clientAddress).call().then(function(result){$("#client-token").html(result);});
        web3.eth.getBalance(clientAddress).then(function(result){$("#client-eth").html(web3.utils.fromWei(result))});
        $('#eth-buy').click(function() {
          token_emh_contract.methods.buy().send({from:clientAddress, value:web3.utils.toWei(0.001, "ether")})
          .on('receipt', function(receipt) {
            alert('Transfert done');
            token_emh_contract.methods.balanceOf(clientAddress).call().then(function(result){$("#client-token").html(result);});
            web3.eth.getBalance(clientAddress).then(function(result){$("#client-eth").html(web3.utils.fromWei(result))});
          });
          setTimeout(function() {
            autoSign();
          }, 1000);
        });

      });
    }
  }
}(jQuery));

