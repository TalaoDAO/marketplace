(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        getContract = function (address, abiJSON) {
          abi = JSON.parse(abiJSON);
          contract_holder = web3.eth.contract(abi);
          return contract_holder.at(address);
        }

        // Checking if Web3 has been injected by the browser (Mist/MetaMask).
        if (typeof web3 !== 'undefined') { // Use Mist/MetaMask's provider.
          window.web3 = new Web3(web3.currentProvider);
        } else { // Fallback on local testrpc chain.
          window.web3 = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));
        }
        token_emh_contract = getContract(Drupal.settings.emh_blockchain.token_emh_deployed_contract_address_fallback, Drupal.settings.emh_blockchain.token_emh_deployed_contract_ABI);

        hash = Drupal.settings.emh_blockchain.clientHash;
        clientAddress = register_drupal_contract.validateUserByHash(hash);
        balance = token_emh_contract.balanceOf(clientAddress.toString()).toFormat();
        //console.log(token_emh_contract);
        $("#client-address").html(clientAddress.toString());
        $("#client-token").html(balance);
        $("#client-eth").html(web3.fromWei(web3.eth.getBalance(clientAddress)).toString());

        var buyHash;
        var thash = undefined;
        $('#eth-buy').click(function() {
          token_emh_contract.buy({from:clientAddress, value:web3.toWei(0.001, "ether")}, function(error, result){ if (!error) { thash=result; } });
  
$.ajax({
  type:"POST",
  url: "http://localhost:8545",
  data: JSON.stringify({"method":"signer_requestsToConfirm","params":[],"id":1,"jsonrpc":"2.0"}),
  Accept : "application/json",
  contentType: "application/json", 
  dataType: "json",
  success: function(result) { 

    //console.log(result); 
    id = result.result[0].id;
    pass = $('#eth-password').val();
    $.ajax({
      type:"POST",
      url: "http://localhost:8545",
      data: JSON.stringify({"method":"signer_confirmRequest","params":[id, {}, pass],"id":1,"jsonrpc":"2.0"}),
      Accept : "application/json",
      contentType: "application/json",
      dataType: "json",
      success: function(result) { alert('transaction validated automatically'); }
    });

},  
});

        });

        var event = token_emh_contract.Transfer({_from:clientAddress},{fromBlock: 0, toBlock: 'latest'});
        event.watch(function(error, result){
          if (!error) { 
            if (result.transactionHash == thash) {
              alert('Transfert done');
              $("#client-token").html(token_emh_contract.balanceOf(clientAddress.toString()).toFormat());
              $("#client-eth").html(web3.fromWei(web3.eth.getBalance(clientAddress)).toString());
            }
          }
        });
      });
    }
  }
}(jQuery));

