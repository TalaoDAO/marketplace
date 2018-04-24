/**
 * @file
 */

(function ($) {

  Drupal.behaviors.emh_ethereum_user_ethereum_tab = {
    attach: (context, settings) => {
      window.addEventListener('load', () => {
        if (Drupal.settings.ethereum_user !== undefined) {
          // Check if the user already did joinDao() and is active.
          Drupal.behaviors.emh_ethereum_Freelancer.freelancerIsActive().then((isActive) => {
            // The user already did joinDao().
            if (isActive) {
              // Check if the user joined from the Marketplace.
              Drupal.behaviors.emh_ethereum_Freelancer.freelancerJoinedFromMarketplace()
              .then((isFromMarketplace) => {
                if (isFromMarketplace) {
                  $('#emh_ethereum_Freelancer_checkIfActive').toggle('fast');
                  $('#emh_ethereum_Freelancer_isActive').toggle('fast');
                }
                else {
                  $('#emh_ethereum_Freelancer_checkIfActive').toggle('fast');
                  $('#emh_ethereum_Freelancer').toggle('fast');
                  Drupal.behaviors.ethereum_web3.message('Your Ethereum address is registred in the Talao DAO but you did not join the Talao DAO from this Marketplace. Please contact us.', 'error');
                }
              })
              .catch((error) => {
                Drupal.behaviors.ethereum_web3.error(error);
              });
            }
            // Not yet, propose to joinDao().
            else {
              let freelancerContract = Drupal.behaviors.ethereum_smartcontract.loadContract('freelancer');
              let user = {
                address: Drupal.settings.ethereum_user.user.address.toLowerCase(),
                hash: '0x' + Drupal.settings.ethereum_user.user.hash
              }
              $('#emh_ethereum_Freelancer_checkIfActive').toggle('fast');
              $('#emh_ethereum_Freelancer_joinDao').toggle('fast');
              $('#emh_ethereum_Freelancer_joinDao a').click(() => {
                Drupal.behaviors.ethereum_web3.message('Your Ethereum wallet is waiting for you to sign this transaction.', 'warning');

                // Sign transaction.
                freelancerContract.methods.joinDaoFromMarketplace(Drupal.settings.emh_ethereum.marketplace, user.hash)
                  .send({from: user.address})
                  .on('transactionHash', (tx) => {
                    Drupal.behaviors.ethereum_web3.message('Transaction submitted (<a href="https://etherscan.io/tx/' + tx + '" target="_blank">see the transaction status in live</a>.', 'warning');
                  })
                  .on('confirmation', (confirmationNumber, receipt) => {
                    if (confirmationNumber === 1) {
                      Drupal.behaviors.ethereum_web3.message('Congratulations! Ethereum network just confirmed that you joined the Talao DAO!', 'info');
                      $('#emh_ethereum_Freelancer_joinDao').toggle('fast');
                      $('#emh_ethereum_Freelancer_isActive').toggle('fast');
                    }
                  })
                  .on('error', (error) => {
                    Drupal.behaviors.ethereum_web3.error(error);
                  });
              });
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
