/**
 * @file
 */

(function ($) {

  Drupal.behaviors.emh_circles = {
    attach: (context, settings) => {
      window.addEventListener('load', () => {
        if (Drupal.settings.ethereum_user !== undefined && Drupal.settings.emh_circles !== undefined) {
          // Check if the user is an active Freelancer on Talao DAO and if he joined from the Marketplace.
          Drupal.behaviors.emh_ethereum_Freelancer
          .isActiveOnMarketplace()
          .then((isActiveOnMarketplace) => {
            // The user is an active Freelancer on Talao DAO and if he joined from the Marketplace.
            if (isActiveOnMarketplace) {
              Drupal.behaviors.ethereum_web3.message('You are an active Freelancer of the Talao DAO, great! Joining this Circle will automatically ask you to sign the corresponding Talao DAO Community, as well.', 'status');
              // Is the Freelancer member of the DAO Community?
              let communityContract = Drupal.behaviors.ethereum_smartcontract.loadContract(Drupal.settings.emh_circles.contract.machine_name);
              let user = {
                address: Drupal.settings.ethereum_user.user.address.toLowerCase(),
                hash: Drupal.settings.ethereum_user.user.hash
              }
              communityContract.methods.communityMembers(user.address)
              .call()
              .then(belongsCommunity => {
                if (belongsCommunity) {
                  Drupal.behaviors.ethereum_web3.message('You belong to the corresponding Talao DAO Community! <a href="' + Drupal.settings.emh_ethereum.dao + '/community/' + Drupal.settings.emh_circles.contract.address + '" target="_blank">Check the Community page on Talao DAO!!!</a>', 'status');
                }
                else {
                  Drupal.behaviors.ethereum_web3.message('You do not belong to the corresponding Talao DAO Community yet. <a href="#" id="joinCommunity">joinCommunity() now !!!</a>', 'status');
                  // Propose to joinCommunity().
                  $('#joinCommunity').click(() => {
                    Drupal.behaviors.ethereum_web3.message('Your Ethereum wallet is waiting for you to sign this transaction.', 'warning');
                    communityContract.methods.joinCommunity()
                      .send({from: user.address})
                      .on('transactionHash', (tx) => {
                        Drupal.behaviors.ethereum_web3.message('Transaction submitted (<a href="https://etherscan.io/tx/' + tx + '" target="_blank">see the transaction status in live</a>.', 'status');
                      })
                      .on('confirmation', (confirmationNumber, receipt) => {
                        if (confirmationNumber === 1) {
                          Drupal.behaviors.ethereum_web3.message('Ethereum network just confirmed that you joined the corresponding Community on the Talao DAO. <a href="' + Drupal.settings.emh_ethereum.dao + '/community/' + Drupal.settings.emh_circles.contract.address + '" target="_blank">See you there!</a>', 'info');
                        }
                      })
                      .on('error', (error) => {
                        Drupal.behaviors.ethereum_web3.error();
                      });
                  });
                }
              })
              .catch((error) => {
                Drupal.behaviors.ethereum_web3.error(error);
              });
            }
            // If not active on Marketplace
            else {
              Drupal.behaviors.ethereum_web3.message('You are not an active Freelancer of the Talao DAO, yet. If you join the Talao DAO, joining this Circle will allow you to join the corresponding Talao DAO community, as well. <a href="/user/ethereum" target="_blank">JoinDAO() now!!!</a>', 'warning');
            }
          })
          .catch((error) => {
            Drupal.behaviors.ethereum_web3.error(error);
          });
        }
      });
    }
  }

}(jQuery));
