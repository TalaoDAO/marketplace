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
            // Yes => propose to joinCommunity().
            Drupal.behaviors.ethereum_web3.message('You are an active Freelancer of the Talao DAO, great! Joining this Circle will automatically ask you to sign the corresponding Talao DAO Community, as well.', 'status');
            $('#og-ui-confirm-subscribe').submit(function(e) {
              let form = this;
              e.preventDefault();
              Drupal.behaviors.ethereum_web3.message('Your Ethereum wallet is waiting for you to sign this transaction.', 'warning');
              let communityContract = Drupal.behaviors.ethereum_smartcontract.loadContract(Drupal.settings.emh_circles.contract.machine_name);
              let user = {
                address: Drupal.settings.ethereum_user.user.address.toLowerCase()
              }
              communityContract.methods.joinCommunity()
                .send({from: user.address})
                .on('transactionHash', (tx) => {
                  Drupal.behaviors.ethereum_web3.message('Transaction submitted (<a href="https://etherscan.io/tx/' + tx + '" target="_blank">see the transaction status in live)</a>.', 'status');
                })
                .on('confirmation', (confirmationNumber, receipt) => {
                  if (confirmationNumber === 1) {
                    Drupal.behaviors.ethereum_web3.message('Ethereum network just confirmed that you joined the corresponding Community on the Talao DAO. <a href="' + Drupal.settings.emh_ethereum.dao + '/community/' + Drupal.settings.emh_circles.contract.address + '" target="_blank">See you there!</a>', 'info');
                    // Go on with the submission of the classic form.
                    form.submit();
                  }
                })
                .on('error', (error) => {
                  Drupal.behaviors.ethereum_web3.error(error);
                });
            });
          })
          .catch((error) => {
            Drupal.behaviors.ethereum_web3.error(error);
          });
        }
      });
    }
  }
}(jQuery));
