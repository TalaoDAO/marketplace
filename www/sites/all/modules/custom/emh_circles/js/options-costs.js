(function($) {

    Drupal.behaviors.emhCirclesOptionsCosts = {
      attach: function(context, settings) {


        if (typeof Drupal.settings.ethereum_web3 !== 'undefined') { // TODO : use better test
          function logInfo(text) {
            $('#ethereum-info').append('<br>'+text);
          }
          token_emh_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('token_erc20');
          user_register_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('register_drupal');
          var objection_contract = Drupal.behaviors.ethereum_smartcontract.loadContract('objection');
          clientAddress = Drupal.settings.emh_blockchain.clientAddress;
          clientName = Drupal.settings.emh_blockchain.clientName;
          clientHash = Drupal.settings.emh_blockchain.clientHash;
          expertAddress = Drupal.settings.emh_blockchain.expertAddress;                                                                                                       
          expertName = Drupal.settings.emh_blockchain.expertName;                                                                                                            
          expertHash = Drupal.settings.emh_blockchain.expertHash; 

          user_register_contract.methods.validateUserByHash(clientHash).call({from:clientAddress}).then(
            () => { logInfo('You are a registered ethereum user.'); clientRegistered = true;}, () => logInfo('You are not registered in ethereum : Ethereum buy via token disabled')
          );
          user_register_contract.methods.validateUserByHash(expertHash).call({from:expertAddress}).then(
            () => { logInfo('The destination is a registered ethereum user.'); expertRegistered = true;}, () => logInfo('The destination is not registered in ehtereum : Ethereum buy via token disabled')
          );

        }

        var $circlesField = $('#edit-og-group-ref', context);
        var $optionsField = $('#edit-field-options', context);

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
  
        if (typeof Drupal.settings.ethereum_web3 !== 'undefined') {
          validated = false;
          $('#edit-submit', context).on('click', function(){
             var price = Number($optionsField.find('.total-num').text());
             if (!clientRegistered || !expertRegistered) { alert('Using normal buy (no ethereum)'); return true;}
             if (validated) return true;
               alert('Waiting for validation, check your wallet');
               token_emh_contract.methods.transfer(expertAddress, price).send({from:clientAddress})
                 .then( receipt => {
                   $('input[name="tx"]').val(receipt.transactionHash);
                   $('input[name="price"]').val(price);
                   validated = true; $('#edit-submit', context).click();
                 })
                 .catch(error => alert('Request rejected') );
             return false;
          });
        }

      }
    };

}(jQuery));

