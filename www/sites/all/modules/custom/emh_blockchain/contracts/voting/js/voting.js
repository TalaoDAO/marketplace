(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {

      function voteForCandidate() {

        candidateName = $("#candidate").val();

        contractInstance.voteForCandidate(candidateName, {from: web3.eth.accounts[0]}, function () {
          let div_id = candidates[candidateName];
          contractInstance.totalVotesFor.call(candidateName, function (error, result) {
            if (!error) {
              $("#" + div_id).html(result.toString());
            }
            else {
              console.error(error);
            }
          });
        })
      }

      window.addEventListener('load', function () {

        // Checking if Web3 has been injected by the browser (Mist/MetaMask).
        if (typeof web3 !== 'undefined') {

          // Use Mist/MetaMask's provider.
          window.web3 = new Web3(web3.currentProvider);
          var voting_deployed_contract_address = Drupal.settings.emh_blockchain.voting_deployed_contract_address;
        }
        else {
          // Fallback on local testrpc chain.
          window.web3 = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));
          var voting_deployed_contract_address = Drupal.settings.emh_blockchain.voting_deployed_contract_address_fallback;
        }

        abi = JSON.parse('[{"constant":false,"inputs":[{"name":"candidate","type":"bytes32"}],"name":"totalVotesFor","outputs":[{"name":"","type":"uint8"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"candidate","type":"bytes32"}],"name":"validCandidate","outputs":[{"name":"","type":"bool"}],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"","type":"bytes32"}],"name":"votesReceived","outputs":[{"name":"","type":"uint8"}],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"x","type":"bytes32"}],"name":"bytes32ToString","outputs":[{"name":"","type":"string"}],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"","type":"uint256"}],"name":"candidateList","outputs":[{"name":"","type":"bytes32"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"candidate","type":"bytes32"}],"name":"voteForCandidate","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"contractOwner","outputs":[{"name":"","type":"address"}],"payable":false,"type":"function"},{"inputs":[{"name":"candidateNames","type":"bytes32[]"}],"payable":false,"type":"constructor"}]')
        VotingContract = web3.eth.contract(abi);
        contractInstance = VotingContract.at(voting_deployed_contract_address);
        candidates = {"Captain America": "candidate-1", "Charles Xavier": "candidate-2", "Ironman": "candidate-3"}
        candidateNames = Object.keys(candidates);

        for (var i = 0; i < candidateNames.length; i++) {
          let name = candidateNames[i];
          let val = contractInstance.totalVotesFor.call(name, function (error, result) {
            if (!error) {
              $("#" + candidates[name]).html(result.toString());
            }
            else {
              console.error(error);
            }
          })
        }

        $('#submit').click(function () {
          voteForCandidate();
        });
      });
    }
  }
}(jQuery));
