/** Implementation of the Majority winner
 *
 * This contract can be inherited to implement a vote weighting mechanism
 * through the `ensureWeight` method.
 */

pragma solidity ^0.4.18;

import "./BallotBase.sol";


contract TokenMajorityBallot is BinaryBallotBase, Deadlined, WeightedBallotBase {
    /* STATE */
    // proposal's name & counters
    bytes32 public proposal;
    uint public yea;
    uint public nay;

    /* EVENTS */
    event Vote(address indexed voter, bool indexed approval, uint weight);
    event Election(uint yea, uint nay);

    /* METHODS */
    function TokenMajorityBallot(bytes32 _proposal, uint length) public {
        proposal = _proposal;
        deadline = now + length;
    }

    function vote(bool approval) public onlyBefore {
        uint weight = ensureWeight(msg.sender);
        if (approval) {yea += weight;} else {nay += weight;}

        Vote(msg.sender, approval, weight);
    }

    // send out election event
    function elect() public onlyAfter returns (bool) {
        if (!ended) {
            Election(yea, nay);
            ended = true;
        }
        return yea > nay;
    }
}
