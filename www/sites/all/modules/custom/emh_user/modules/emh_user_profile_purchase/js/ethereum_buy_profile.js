(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        // inspired from https://forum.ethereum.org/discussion/5039/how-to-use-web3-js-to-sign-a-contract-call
        autosign = function (pass, onreceipt) {
          var walletContractAddress = Drupal.settings.ethereum_smartcontract.contracts.token_erc20.address;
          var ABI = Drupal.settings.ethereum_smartcontract.contracts.token_erc20.abi;
          var privateKey = new buffer.Buffer(pass, 'hex');
          var toAccount = expertAddress;
          var fromAccount = clientAddress;
          var signature = _.find(ABI, { name: 'transfer' });
          var payloadData = web3.eth.abi.encodeFunctionCall(signature, [toAccount, 1]);
          gasPrice = web3.eth.gasPrice;
          gasPriceHex = web3.utils.toHex(gasPrice);
          gasLimitHex = web3.utils.toHex(300000);
          web3.eth.getTransactionCount(fromAccount).then((nonce) => {
            nonceHex = web3.utils.toHex(nonce);
            var rawTx = {
              nonce: nonceHex,
              gasPrice: gasPriceHex,
              gasLimit: gasLimitHex,
              to: walletContractAddress,
              from: fromAccount,
              value: '0x00',
              data: payloadData
              };
            var tx = new ethereumjs.Tx(rawTx);
            tx.sign(privateKey);
            var serializedTx = tx.serialize();
            web3.eth.sendSignedTransaction('0x' + serializedTx.toString('hex')).then( () =>{ onreceipt(); return null; } );
            return null;
          });
        }

        token_emh_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('token_erc20');
        user_register_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('register_drupal');
        clientAddress = Drupal.settings.emh_blockchain.clientAddress;
        expertAddress = Drupal.settings.emh_blockchain.expertAddress;
        clientName = Drupal.settings.emh_blockchain.clientName;
        expertName = Drupal.settings.emh_blockchain.expertName;
        clientHash = Drupal.settings.emh_blockchain.clientHash;
        expertHash = Drupal.settings.emh_blockchain.expertHash;

        console.log(expertAddress); console.log(clientAddress);
        console.log(expertHash); console.log(clientHash);
        console.log(expertName); console.log(clientName);

        clientRegistered = false; //async
        expertRegistered = false; //async

        function addText(item, text) {
          $(item).html( $(item).text() +text );
        }
        function logInfo(text) {
          addText('#ethereum-info', '<br>'+text);
        }

        user_register_contract.methods.validateUserByHash(clientHash).call({from:clientAddress}).then(
          () => { logInfo('You are a registered ethereum user.'); clientRegistered = true;}, () => logInfo('You are not registered in ethereum : Ethereum buy via token disabled')
        );
        user_register_contract.methods.validateUserByHash(expertHash).call({from:expertAddress}).then(
          () => { logInfo('The expert is a registered ethereum user.'); expertRegistered = true;}, () => logInfo('The expert is not registered in ehtereum : Ethereum buy via token disabled')
        );
        token_emh_contract.methods.balanceOf(clientAddress).call().then( balance => { addText('#buy-title', '<b> and for 1 ethereum Token</b>. Your current balance is :'+balance)} );

        validated = false;
        $('#edit-submit', context).on('click', function(){
           if (!clientRegistered || !expertRegistered) { alert('Using normal profil buy'); return true;}
           if (validated) return true;
           var pass = prompt("Please enter your private key (keep empty to validate transaction with your wallet)", "");
           if (pass == '') {
             token_emh_contract.methods.transfer(expertAddress, 1).send({from:clientAddress})
               .then( receipt => {validated = true; $('#edit-submit', context).click(); })
               .catch(error => alert('Request rejected') );
           } else {
             try {
               logInfo('<b>Transaction send, waiting for (automatic) validation ...<b>');
               autosign(pass, ()=>{
                 validated = true; $('#edit-submit').click();
               });
             } catch (err) { console.log(err); alert('There was an error'); }
           }
           return false;
        });
      });
    }
  }
}(jQuery));

