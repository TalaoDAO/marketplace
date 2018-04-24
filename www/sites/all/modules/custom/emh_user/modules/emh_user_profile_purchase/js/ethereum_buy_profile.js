(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {
        if (Drupal.settings.ethereum_user !== undefined) {

          token_emh_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('talaotoken');
          objection_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('objection');
          clientAddress = Drupal.settings.emh_user_profile_purchase.clientAddress;
          expertAddress = Drupal.settings.emh_user_profile_purchase.expertAddress;
          clientName = Drupal.settings.emh_user_profile_purchase.clientName;
          expertName = Drupal.settings.emh_user_profile_purchase.expertName;
          clientHash = Drupal.settings.emh_user_profile_purchase.clientHash;
          expertHash = Drupal.settings.emh_user_profile_purchase.expertHash;
          let expert = {
            address: expertAddress.toLowerCase(),
            hash: '0x' + expertHash
          }

          // Check if the Client (= current user) and the Expert are active on Talao DAO and joined from Marketplace.
          // Client.
          Drupal.behaviors.emh_ethereum_Freelancer.isActiveOnMarketplace()
          .then((clientIsActiveOnMarketplace) => {
            if (clientIsActiveOnMarketplace) {
              // Expert.
              Drupal.behaviors.emh_ethereum_Freelancer.isActiveOnMarketplace(expert)
              .then((expertIsActiveOnMarketplace) => {
                if (expertIsActiveOnMarketplace) {

                  // Buy profile.
                  var price = 1;
                  objection_contract.methods.get_value(web3.utils.padRight(web3.utils.stringToHex('profile_price'), 64)).call().then(value => {
                    price = value;
                    token_emh_contract.methods.balanceOf(clientAddress).call().then(balanceWei => {
                      let balance = web3.utils.fromWei(balanceWei);
                      $('#buy-title').html('Access ' + expertName + '\'s profile for <b> '+value+' talao Token</b>. Your current balance is :'+ balance)
                    });
                  });
                  validated = false;
                  $('#edit-submit', context).on('click', function(){
                     if (validated) return true;
                     //var pass = prompt("Please enter your private key (keep empty to validate transaction with your wallet) for "+price+" tokens", "");
                     //if (pass == '') {
                       Drupal.behaviors.ethereum_web3.message('Your Ethereum wallet is waiting for you to sign this transaction.', 'warning');
                       token_emh_contract.methods.transfer(expertAddress, price).send({from:clientAddress})
                         .then( receipt => {
                           //console.log(receipt);
                           //alert('validated');
                           //alert(receipt.transactionHash);
                           $('input[name="tx"]').val(receipt.transactionHash);
                           $('input[name="price"]').val(price);
                           validated = true; $('#edit-submit', context).click();
                         })
                         .catch((error) => {
                           Drupal.behaviors.ethereum_web3.error(error);
                         });
                     /*} else {
                       try {
                         logInfo('<b>Transaction send, waiting for (automatic) validation ...<b>');
                         autosign(pass, ()=>{
                           validated = true; $('#edit-submit').click();
                         });
                       } catch (err) { console.log(err); alert('There was an error'); }
                     }*/
                     return false;
                  });
                }
                else {
                  Drupal.behaviors.ethereum_web3.message('This Freelancer is not active on this Talao Marketplace. You can not buy his profile with Talao tokens.', 'error');
                }
              })
              .catch((error) => {
                Drupal.behaviors.ethereum_web3.error(error);
              });
            }
            else {
              Drupal.behaviors.ethereum_web3.message('Please check your <a href="/user/ethereum">Ethereum settings</a> if you want to buy Freelancers profiles with Talao tokens.', 'error');
            }
          })
          .catch((error) => {
            Drupal.behaviors.ethereum_web3.error(error);
          });
        }
      });
    }
  }
  // inspired from https://forum.ethereum.org/discussion/5039/how-to-use-web3-js-to-sign-a-contract-call
  autosign = function (pass, onreceipt) {
    var walletContractAddress = Drupal.settings.ethereum_smartcontract.contracts.talaotoken.address;
    var ABI = Drupal.settings.ethereum_smartcontract.contracts.talaotoken.abi;
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
}(jQuery));
