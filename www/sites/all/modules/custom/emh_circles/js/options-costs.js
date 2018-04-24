(function($) {

    Drupal.behaviors.emhCirclesOptionsCosts = {
      attach: function(context, settings) {

        var $circlesField = $('#edit-og-group-ref', context);
        var $optionsField = $('#edit-field-options', context);
        var objection_contract = undefined;
        async function selectCosts(circles) {
          var costs = {};
          if ($.isArray(circles) && circles.length > 0) {
            // Selects the highest cost (from circles) for each option
            for (var i = 0; i < circles.length; i++) {
              var circleId = Number(circles[i]);
              var circleName = settings.circlesOptionsCosts.circles_id[circleId];
              if (circleName == undefined) continue;
              circleName = circleName.replace(/\s+/g, '-').toLowerCase();
              var circleCosts = settings.circlesOptionsCosts.circles[circleId];

              for (var j in circleCosts) {
                if (typeof Drupal.settings.ethereum_web3 !== 'undefined') {
                  cost = await objection_contract.methods.get_value(web3.utils.padRight(web3.utils.stringToHex(circleName+'_'+j), 64)).call();
                  if (cost != -1) circleCosts[j] = cost; // ethereum supercedes the price
                }
                if (typeof costs[j] == 'undefined' || costs[j] < circleCosts[j]) {
                  costs[j] = Number(circleCosts[j]);
                  // try to get the ethereum token value of the circle
                }
              }
            }
          }
          // Completes the costs array with the default costs
          // when there isn't yet a cost for an option
          for (var k in settings.circlesOptionsCosts.default) {
            if (typeof costs[k] == 'undefined') {
              costs[k] = Number(settings.circlesOptionsCosts.default[k]);
            }
          }
          //setTimeout(function (){}, 2000);
          return costs;
        }
        $circlesField.find('select').change(function() {
          var circles = $(this).val();
          selectCosts(circles).then(costs => {

            for (var id in costs) {
              $optionsField
                .find('[data-emh-option="' + id + '"] input[type="hidden"]')
                .val(costs[id])
                .trigger('change');
              // We have to manually trigger the change event
              // because the val() method doesn't do it.
              // http://stackoverflow.com/questions/3179385/val-doesnt-trigger-change-in-jquery
            }
          });
        });
        $circlesField.find('select').trigger("change"); //force change in case field has default value

        window.addEventListener('load', () => {
          if (Drupal.settings.ethereum_user !== undefined) {
            // Check if the user is an active Freelancer on Talao DAO and if he joined from the Marketplace.
            Drupal.behaviors.emh_ethereum_Freelancer.isActiveOnMarketplace()
            .then((isActiveOnMarketplace) => {
              if (isActiveOnMarketplace) {
                function logInfo(text) {
                  $('#ethereum-info').append('<br>'+text);
                }
                token_emh_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('talaotoken');
                user_register_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('freelancer');
                objection_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('objection');
                clientAddress = Drupal.settings.emh_blockchain.clientAddress;
                clientName = Drupal.settings.emh_blockchain.clientName;
                clientHash = Drupal.settings.emh_blockchain.clientHash;
                expertAddress = Drupal.settings.emh_blockchain.expertAddress;
                expertName = Drupal.settings.emh_blockchain.expertName;
                expertHash = Drupal.settings.emh_blockchain.expertHash;
                validated = false;
                $('#edit-submit', context).on('click', function(){
                   var price = Number($optionsField.find('.total-num').text());
                   if (validated) return true;
                     alert('Waiting for validation, check your wallet');
                     Drupal.behaviors.ethereum_web3.message('Your Ethereum wallet is waiting for you to sign this transaction.', 'warning');
                     token_emh_contract.methods.transfer(expertAddress, price).send({from:clientAddress})
                       .then( receipt => {
                         $('input[name="tx"]').val(receipt.transactionHash);
                         $('input[name="price"]').val(price);
                         validated = true;
                         $('#edit-submit', context).click();
                       })
                       .catch(error => {
                         alert('Request rejected');
                         Drupal.behaviors.ethereum_web3.error(error);
                       });
                   return false;
                });
              }
            })
            .catch((error) => {
              Drupal.behaviors.ethereum_web3.error(error);
            });
          }

        });
      }
    };

}(jQuery));
