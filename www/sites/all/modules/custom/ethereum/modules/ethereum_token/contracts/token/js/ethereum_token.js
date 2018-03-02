(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        fallback = Drupal.settings.emh_blockchain.ethereum_fallback;

        autoSign = function() {
          $.ajax({
            type:"POST",  url: fallback, Accept : "application/json", contentType: "application/json",  dataType: "json",
            data: JSON.stringify({"method":"signer_requestsToConfirm","params":[],"id":1,"jsonrpc":"2.0"}),
            success: function(result) { 
              console.log(result);
              if (result.result == []) alter('Could not sign');
              if (result.result[0] == undefined) alter('Could not sign');
              id = result.result[0].id;
              pass = $('#eth-password').val();
              $.ajax({
                type:"POST", url: fallback, Accept : "application/json", contentType: "application/json", dataType: "json",
                data: JSON.stringify({"method":"signer_confirmRequest","params":[id, {}, pass],"id":1,"jsonrpc":"2.0"}),
                success: function(result) { alert('transaction validated automatically'); }
              });
            }
          });
        }

        token_emh_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('token_erc20');
        clientAddress = Drupal.settings.emh_blockchain.clientAddress;
        $("#client-address").html(clientAddress.toString());
        token_emh_contract.methods.balanceOf(clientAddress).call().then(function(result){$("#client-token").html(result);});
        token_emh_contract.methods.balanceOf(Drupal.settings.ethereum_smartcontract.contracts.token_erc20.address).call().then(function(result){$("#contract-token").html(result);});
        web3.eth.getBalance(clientAddress).then(function(result){$("#client-eth").html(web3.utils.fromWei(result))});
        $('#eth-buy').click(function() {
          token_emh_contract.methods.buy().send({from:clientAddress, value:web3.utils.toWei(0.001, "ether")})
          .on('receipt', function(receipt) {
            alert('Transfert done');
            token_emh_contract.methods.balanceOf(clientAddress).call().then(function(result){$("#client-token").html(result);});
            web3.eth.getBalance(clientAddress).then(function(result){$("#client-eth").html(web3.utils.fromWei(result))});
          });
          pass = $('#eth-password').val();
          if (pass != '')
            setTimeout(function() {
              autoSign();
            }, 1000);
        });

      });
    }
  }
}(jQuery));

