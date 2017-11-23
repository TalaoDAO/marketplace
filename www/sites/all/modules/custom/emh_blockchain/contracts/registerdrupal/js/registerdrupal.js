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
        register_drupal_contract = getContract(Drupal.settings.emh_blockchain.register_drupal_deployed_contract_address_fallback, Drupal.settings.emh_blockchain.register_drupal_deployed_contract_ABI);
        token_emh_contract = getContract(Drupal.settings.emh_blockchain.token_emh_deployed_contract_address_fallback, Drupal.settings.emh_blockchain.token_emh_deployed_contract_ABI);

        hash = Drupal.settings.emh_blockchain.adminHash;
        adminAddress = register_drupal_contract.validateUserByHash(hash);
        console.log(adminAddress);
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
        $("#debug").html('user address: '+adminAddress.toString());
        balance = token_emh_contract.balanceOf(adminAddress.toString()).toFormat();
        console.log(balance);
        $("#debug").html( $("#debug").text()+ ' balance : '+balance);

        hash = Drupal.settings.emh_blockchain.clientHash;
        clientAddress = register_drupal_contract.validateUserByHash(hash);
        balance = token_emh_contract.balanceOf(clientAddress.toString()).toFormat();
        console.log(token_emh_contract);
        $("#debug").html( $("#debug").text()+ '<br> balance YBA : '+balance + ' client address :'+clientAddress.toString());

        $("#debug").html( $("#debug").text()+ ' balance eth: '+web3.fromWei(web3.eth.getBalance(clientAddress)));

        var buyHash;
        $('#buyYBA').click(function() {
          //alert('test');
          //1st metho : 2 transactions, insecure
          /*buyHash = web3.eth.sendTransaction({from: clientAddress.toString(), to: adminAddress.toString(), value: web3.toWei(1, "ether")});
          tstatus = web3.eth.getTransactionReceipt(buyHash);
          console.log(tstatus);
          console.log(token_emh_contract.balanceOf(clientAddress.toString()).toFormat());
          token_emh_contract.transfer.sendTransaction(clientAddress.toString(), 1, {from: web3.eth.accounts[0]});*/

          //2nd method : 1 transaction, secure
          // You have to : set but and sell price to : 1000000000000000
          // unit : 1
          // mine token for contract
          // have enough ether on client
          token_emh_contract.buy.sendTransaction({from:clientAddress, value:web3.toWei(0.001, "ether")}); // buy one token
          //token_emh_contract.buy.sendTransaction({from:web3.eth.accounts[3], value: web3.toWei(1, "ether")})
        });
      });
    }
  }
}(jQuery));
