/**
 * @file
 */

(function ($) {

  Drupal.behaviors.ethereum_smartcontract = {};

  Drupal.behaviors.ethereum_smartcontract.loadContract = function (machine_name) {

    if (typeof web3 === 'undefined') {
      window.web3 = new Web3(new Web3.providers.HttpProvider(Drupal.settings.ethereum_web3.node));
    }

    let abi = JSON.parse(Drupal.settings.ethereum_smartcontract.contracts[machine_name].abi);
    let address = Drupal.settings.ethereum_smartcontract.contracts[machine_name].address;
    let contract = new web3.eth.Contract(abi, address);

    return contract;
  }

}(jQuery));
