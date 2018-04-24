/**
 * @file
 */

(function ($) {

  Drupal.behaviors.emh_ethereum_Freelancer_list = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        var contract = Drupal.behaviors.ethereum_smartcontract.loadContract('freelancer');
        var token = Drupal.settings.emh_ethereum_Freelancer_list.token;

        // Get DAO active members that belong to this Marketplace.
        contract.getPastEvents(
          'FreelancerSubscribedFromMarketPlace',
          {
            filter: {
              _marketplaceAddress: Drupal.settings.emh_ethereum_Freelancer_list.marketplace
            },
            fromBlock: 0
          },
          (error, events) => {
            if (error) {
              console.log(error);
            }
            else {
              events.forEach((event) => {
                // Add a row to the table.
                $.getJSON('/admin/people/freelancer/callback/' + event.returnValues._marketplaceUserHash + '/' + token, (json) => {
                  $('#emh_ethereum_Freelancer_list tr:last').after('<tr><td><a href="/user/' + json.data.uid + '">' + json.data.name + '</a></td><td><a href="' + Drupal.settings.emh_ethereum.dao + '/freelancers/' + event.returnValues._freelancerAddress + '" target="_blank">' + event.returnValues._freelancerAddress + '</a></td></tr>');
                });
              });
            }
        });
      });
    }
  }
}(jQuery));
