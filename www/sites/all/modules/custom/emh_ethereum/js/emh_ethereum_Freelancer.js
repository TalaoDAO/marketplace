/**
 * @file
 */

(function ($) {

  Drupal.behaviors.emh_ethereum_Freelancer = {};

  Drupal.behaviors.emh_ethereum_Freelancer.freelancerIsActive = function () {
    return new Promise((resolve, reject) => {
      let freelancerContract = Drupal.behaviors.ethereum_smartcontract.loadContract('freelancer');
      let user = {
        address: Drupal.settings.ethereum_user.user.address.toLowerCase()
      }
      // Check if the user already did joinDao() and is active.
      freelancerContract.methods.isFreelancerActive(user.address)
      .call()
      .then((isActive) => {
        // Yes.
        if (isActive) {
          resolve(true);
        }
        // No.
        else {
          resolve(false);
        }
      })
      .catch((error) => {
        reject(error);
      });
    });
  }

  Drupal.behaviors.emh_ethereum_Freelancer.freelancerJoinedFromMarketplace = function () {
    return new Promise((resolve, reject) => {
      let freelancerContract = Drupal.behaviors.ethereum_smartcontract.loadContract('freelancer');
      let user = {
        address: Drupal.settings.ethereum_user.user.address.toLowerCase(),
        hash: '0x' + Drupal.settings.ethereum_user.user.hash
      }
      // Check if the user already did joinDaoFromMarketplace().
      freelancerContract.methods.marketplacesAccounts(user.hash)
      .call()
      .then((result) => {
        // Yes.
        if (result.toLowerCase() == user.address) {
          resolve(true);
        }
        // No.
        else {
          resolve(false);
        }
      })
      .catch((error) => {
        reject(error);
      });
    });
  }

  Drupal.behaviors.emh_ethereum_Freelancer.isActiveOnMarketplace = function (
    user = {
      address: Drupal.settings.ethereum_user.user.address.toLowerCase(),
      hash: '0x' + Drupal.settings.ethereum_user.user.hash
    }) {
    return new Promise((resolve, reject) => {
      let freelancerContract = Drupal.behaviors.ethereum_smartcontract.loadContract('freelancer');
      // Check if the user already did joinDao().
      freelancerContract.methods.isFreelancerActive(user.address)
      .call()
      .then((isActive) => {
        if (isActive) {
          // Check if the Freelancer joined from this Marketplace.
          freelancerContract.methods.marketplacesAccounts(user.hash)
          .call()
          .then((result) => {
            // Yes.
            if (result.toLowerCase() == user.address) {
              resolve(true);
            }
            // No.
            else {
              resolve(false);
            }
          })
          .catch((error) => {
            reject(error);
          });
        }
        // No.
        else {
          resolve(false);
        }
      })
      .catch((error) => {
        reject(error);
      });
    });
  }

}(jQuery));
