/**
 * @file
 */

(function ($) {

  Drupal.behaviors.ethereum_registry = {
    attach: function (context, settings) {
      window.addEventListener('load', function () {

        var contract = Drupal.behaviors.ethereum_smartcontract.loadContract('register_drupal');
        var token = Drupal.settings.ethereum_registry.token;

        // Get subscribers.
        contract.getPastEvents('AccountCreatedEvent', {filter: {error: [0]}, fromBlock: 0, toBlock: 'latest'}, function (error, result) {
          if (error) {
            console.log(error);
          }
          else {
            result.forEach(function (event) {

              // Add a row to the table.
              $.getJSON('/admin/config/ethereum/registry/callback/' + event.returnValues.hash + '/' + token, function (json) {
                $('#ethereum_registry_list tr:last').after('<tr><td><a href="/user/' + json.data.uid + '">' + json.data.name + '</a></td><td>' + event.returnValues.from + '</td></tr>');
              });
            });
          }
        });
      });
    }
  }
}(jQuery));
