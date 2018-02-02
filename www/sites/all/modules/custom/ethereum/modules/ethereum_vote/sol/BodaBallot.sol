/** Implementation of the Borda winner
 *
 * When voters must choose between more than two alternatives, classic majority
 * voting presents drawbacks. // todo list them
 *   - ...
 *   - ...
 *
 * ELecting the Borda winner has some advantages. // todo list them again
 * Voters provide a ranking of all the (n) options ; each of the latter is
 * awarded points according to their spot on the ranking:
 *   - The preferred gets n points,
 *   - The second gets n-1 points,
 *   - ...
 *   - The last gets 1 point.
 *
 * This contract can be inherited to implement a vote weighting mechanism
 * through the `ensureWeight` method.
 */

pragma solidity ^0.4.18;

import "./BallotBase.sol";


contract BordaBallot is RankedBallotBase, Deadlined, WeightedBallotBase {
    /* STATE */
    struct Proposal {
        bytes32 name;
        uint8 id;  // index in the vote matrix
    }

    // list of proposals
    Proposal[] public proposals;

    // vote vector, winner id
    mapping(uint8 => uint) public relations;
    uint private winner;  // no meaning unless ended

    // weighting token contract address
    address token;

    /* EVENTS */
    event Vote(uint8[] indexed id, address indexed voter);
    event Election(bytes32 name, uint8 id);

    /* METHODS */
    function BordaBallot(bytes32[] names, uint length) public {
        deadline = now + length;  // calculate end date

        require(names.length < 2**8);  // id is of type uint8
        // assign ids to names and populate proposals
        for (uint8 i = 0; i < names.length; i++) {
            proposals.push(Proposal({name: names[i], id: i}));
        }
    }

    // a ranking should be a permutation of range(proposals.length)
    function _isLegal(uint8[] ranking) internal view returns (bool) {
        if (ranking.length != proposals.length)
           return false;

        bool[] memory counter = new bool[](ranking.length);
        for (uint i = 0; i < ranking.length; i++) {
            if (ranking[i] >= ranking.length || counter[ranking[i]])
                return false;
            counter[i] = true;
        }

        return true;
    }

    function vote(uint8[] ranking) onlyBefore public {
        // voters may only vote once to prevent strategic voting
        // votes are weighed according to some token allowance
        require(weights[msg.sender] == 0);
        uint weight = ensureWeight(msg.sender);
        require(_isLegal(ranking));

        // update vote vector
        uint len = proposals.length;
        for (uint8 i = 0; i < proposals.length; i++) {
            relations[ranking[i]] += weight * (len - i);
        }

        // log voting event
        Vote(ranking, msg.sender);
    }

    function elect() onlyAfter public returns (uint) {
        if (!ended) {
            uint8 argmax;
            uint max = 0;
            for (uint8 i = 0; i < proposals.length; i++) {
                if (relations[i] > max)
                    argmax = i;
            }

            winner = uint(proposals[argmax].id);
            Election(proposals[argmax].name, uint8(winner));
        }

        return winner;
    }
}
