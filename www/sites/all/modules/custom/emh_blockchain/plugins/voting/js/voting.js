/**
 * @file
 */

(function ($) {

  Drupal.behaviors.emhBlockchain = {
    attach: function (context, settings) {

      function voteForCandidate() {
        candidateName = $("#candidate").val();
        contractInstance.voteForCandidate(candidateName, {from: web3.eth.accounts[0]}, function () {
          let div_id = candidates[candidateName];
          $("#" + div_id).html(contractInstance.totalVotesFor.call(candidateName).toString());
        });
      }

      web3 = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));
      abi = JSON.parse('[{"constant":false,"inputs":[{"name":"candidate","type":"bytes32"}],"name":"totalVotesFor","outputs":[{"name":"","type":"uint8"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"candidate","type":"bytes32"}],"name":"validCandidate","outputs":[{"name":"","type":"bool"}],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"","type":"bytes32"}],"name":"votesReceived","outputs":[{"name":"","type":"uint8"}],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"x","type":"bytes32"}],"name":"bytes32ToString","outputs":[{"name":"","type":"string"}],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"","type":"uint256"}],"name":"candidateList","outputs":[{"name":"","type":"bytes32"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"candidate","type":"bytes32"}],"name":"voteForCandidate","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"contractOwner","outputs":[{"name":"","type":"address"}],"payable":false,"type":"function"},{"inputs":[{"name":"candidateNames","type":"bytes32[]"}],"payable":false,"type":"constructor"}]')
      VotingContract = web3.eth.contract(abi);
      contractInstance = VotingContract.at('0x72bd8ea3223080f4a85459f3d5d299c081595256');
      candidates = {"Captain America": "candidate-1", "Charles Xavier": "candidate-2", "Ironman": "candidate-3"}

      candidateNames = Object.keys(candidates);
      for (var i = 0; i < candidateNames.length; i++) {
        let name = candidateNames[i];
        let val = contractInstance.totalVotesFor.call(name).toString()
        $("#" + candidates[name]).html(val);
      }

      $('#submit').click(function () {
        voteForCandidate();
      });
    }
  }
}(jQuery));
