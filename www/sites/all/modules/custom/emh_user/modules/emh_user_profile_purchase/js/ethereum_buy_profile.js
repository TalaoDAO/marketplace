(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {
        fallback = Drupal.settings.emh_blockchain.ethereum_fallback;
        // Checking if Web3 has been injected by the browser (Mist/MetaMask).
        if (typeof web3 !== 'undefined') { // Use Mist/MetaMask's provider.
          window.web3 = new Web3(web3.currentProvider);
        } else { // Fallback on local testrpc chain.
          window.web3 = new Web3(new Web3.providers.HttpProvider(fallback));
        }

        token_emh_contract = new web3.eth.Contract(JSON.parse(Drupal.settings.emh_blockchain.token_emh_deployed_contract_ABI), Drupal.settings.emh_blockchain.token_emh_deployed_contract_address_fallback);
        user_register_contract = new web3.eth.Contract(JSON.parse(Drupal.settings.emh_blockchain.user_register_deployed_contract_ABI), Drupal.settings.emh_blockchain.user_register_deployed_contract_address_fallback);
        clientAddress = Drupal.settings.emh_blockchain.clientAddress;
        expertAddress = Drupal.settings.emh_blockchain.expertAddress;
        clientName = Drupal.settings.emh_blockchain.clientName;
        expertName = Drupal.settings.emh_blockchain.expertName;
        clientHash = Drupal.settings.emh_blockchain.clientHash;
        expertHash = Drupal.settings.emh_blockchain.expertHash;

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
               //autosign('');
               logInfo('<b>Transaction send, waiting for validation ...<b>');
               Window.profile_buy(clientAddress, expertAddress,pass, Drupal.settings.emh_blockchain.token_emh_deployed_contract_address_fallback, JSON.parse(Drupal.settings.emh_blockchain.token_emh_deployed_contract_ABI), ()=>{validated = true; $('#edit-submit').click();}, fallback);
             } catch (err) { console.log(err); alert('There was an error'); }
           }
           return false;
        });
      });
    }
  }
}(jQuery));

/*
        autosign = function () {

var walletContractAddress = Drupal.settings.emh_blockchain.token_emh_deployed_contract_address_fallback;
var privateKey = new buffer.Buffer('0d5308fb0ece80dbbabd01e6e106f5cab581066e29d1c407b2b5197cf44bb3ec', 'hex');
//var privateKey = new Buffer(pass, 'hex');
var toAccount = expertAddress;
var fromAccount = clientAddress;
console.log(privateKey);
var solidityFunction = new SolidityFunction('', _.find(ABI, { name: 'transfer' }), '');
console.log('This shows what toPayload expects as an object');
console.log(solidityFunction);
var payloadData = solidityFunction.toPayload([toAccount, 1]).data;
gasPrice = web3.eth.gasPrice;
gasPriceHex = web3.toHex(gasPrice);
gasLimitHex = web3.toHex(300000);
nonce =  web3.eth.getTransactionCount(fromAccount) ;
nonceHex = web3.toHex(nonce);
console.log('nonce (transaction count on fromAccount): ' + nonce + '(' + nonceHex + ')');

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
web3.eth.sendSignedTransaction('0x' + serializedTx.toString('hex')).on('receipt', console.log);

        }
*/
