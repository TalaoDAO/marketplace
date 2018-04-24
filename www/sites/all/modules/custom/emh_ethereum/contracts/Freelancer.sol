pragma solidity ^0.4.21;

import '../ownership/Ownable.sol';
import '../math/SafeMath.sol';

/**
 * @title Freelancer
 * @dev This contract details a TALAO freelancer.
 * @author Talao
 */
contract Freelancer is Ownable {
    using SafeMath for uint256;

    struct FreelancerInformation {
        // Active freelancer?
        bool isActive;
        // Blocked freelancer?
        bool isBlocked;
    }

    struct FreelancerCommunityReputation {
        // Ratings by the clients within a community.
        uint[4] clientsRatings;
        // Clients ratings weights within a community.
        uint[4] clientsRatingsWeights;
        // Pointer to loop through clients ratings and always keep 4. From 0 to 3.
        uint clientsRatingsPointer;
        // Community contribution score of the freelancer.
        // uint is needed, int functions not yet in SafeMath
        // @see https://github.com/OpenZeppelin/zeppelin-solidity/pull/835
        uint contributionScore;
        // Block number of the latest community contribution score update, to compute decay (reputation decreases with time).
        uint lastContributionBlock;
    }

    // Owner of the contract.
    address owner;
    // Number of blocks in a Quarter.
    uint blocksPerQuarter;
    // Freelancers information.
    mapping(address => FreelancerInformation) private freelancerInformation;
    // Freelancers reputation by community. Freelancer address => (Community address => Reputation).
    mapping(address => mapping(address => FreelancerCommunityReputation)) private freelancerCommunityReputation;
    // Mapping of Marketplace user hashes => Freelancer Ethereum addresses.
    mapping(bytes32 => address) public marketplacesAccounts;

    // Event: a freelancer subscribed.
    event FreelancerSubscribed(address indexed _freelancerAddress);
    // Event: a freelancer subscribed from a Marketplace.
    event FreelancerSubscribedFromMarketPlace(
        address indexed _freelancerAddress,
        address indexed _marketplaceAddress,
        bytes32 indexed _marketplaceUserHash
    );
    // Event: a freelancer has a new client rating, within a community.
    event FreelancerNewClientRating(
        address indexed _freelancerAddress,
        address indexed _communityAddress,
        uint _clientRating,
        uint _clientRatingWeight
    );
    event FreelancerNewContribution(
        address indexed _freelancerAddress,
        address indexed _communityAddress,
        uint _contributionValue
    );

    /**
    * @dev Init owner and delay for decay calculation.
    **/
    function Freelancer()
        public
    {
        // Owner = contract creator.
        owner = msg.sender;
        // 60s / 15blocks * 60min * 24h * 30d * 3months = 518400 blocks / quarter.
        blocksPerQuarter = 518400;
    }

    /**
    * @dev Join the DAO.
    **/
    function joinDao()
        public
    {
        // The user Ethereum address must not exist in the registry.
        require(freelancerInformation[msg.sender].isActive == false);
        // The user Ethereum address must not be blocked in the registry.
        require(freelancerInformation[msg.sender].isBlocked == false);

        freelancerInformation[msg.sender].isActive = true;

        emit FreelancerSubscribed(msg.sender);
    }

    /**
    * @dev Join the DAO from a Marketplace.
    * @param _marketplaceAddress The Marketplace Ethereum address.
    * @param _marketplaceUserHash The Marketplace can submit a unique hash by user.
    **/
    function joinDaoFromMarketplace(address _marketplaceAddress, bytes32 _marketplaceUserHash)
        public
    {
        // Marketplace Ethereum address can't be empty.
        require (_marketplaceAddress != address(0x0));
        // Marketplace user hash must be 32 bytes.
        require (_marketplaceUserHash.length == 32);
        // Marketplace user hash must not already exist.
        require(marketplacesAccounts[_marketplaceUserHash] == 0);

        joinDao();

        marketplacesAccounts[_marketplaceUserHash] = msg.sender;

        emit FreelancerSubscribedFromMarketPlace(msg.sender, _marketplaceAddress, _marketplaceUserHash);
    }

    /**
    * @dev Register a client rating for the freelancer, within a community.
    * @param _freelancerAddress address The freelancer Ethereum address.
    * @param _communityAddress address The community Ethereum address.
    * @param _clientRating uint The client rating. From 1 to 50.
    * @param _clientRatingWeight uint The client rating weight. From 1 to 5.
    **/
    function registerClientRating(
        address _freelancerAddress,
        address _communityAddress,
        uint _clientRating,
        uint _clientRatingWeight
    )
        public
    {
        // Freelancer must be active.
        require(freelancerInformation[_freelancerAddress].isActive == true);
        // Community Ethereum address can't be empty.
        require (_communityAddress != address(0x0));
        // Client rating must be between 1 and 50.
        require(_clientRating > 0 && _clientRating <= 50);
        // Client rating weight must be between 1 and 5.
        require(_clientRatingWeight > 0 && _clientRatingWeight <= 5);

        FreelancerCommunityReputation storage reputation = freelancerCommunityReputation[_freelancerAddress][_communityAddress];

        reputation.clientsRatings[reputation.clientsRatingsPointer] = _clientRating;
        reputation.clientsRatingsWeights[reputation.clientsRatingsPointer] = _clientRatingWeight;

        // 4 client Ratings by freelancer & community at maximum. If more, we replace the older ones.
        if (reputation.clientsRatingsPointer == 3) {
          reputation.clientsRatingsPointer = 0;
        }
        // Increase pointer for the next client rating.
        else {
          reputation.clientsRatingsPointer.add(1);
        }

        emit FreelancerNewClientRating(_freelancerAddress, _communityAddress, _clientRating, _clientRatingWeight);
    }

    /**
    * @dev Register a community contribution for the freelancer.
    * @param _freelancerAddress address The freelancer Ethereum address.
    * @param _communityAddress address The community Ethereum address.
    * @param _contributionValue uint The contribution value. From 1 (least important) to 10 (most important).
    **/
    function registerCommunityContribution(
        address _freelancerAddress,
        address _communityAddress,
        uint _contributionValue
    )
        public
    {
        // Freelancer must be active.
        require(freelancerInformation[_freelancerAddress].isActive == true);
        // Community Ethereum address can't be empty.
        require (_communityAddress != address(0x0));
        // Contribution value must be between 1 (least important) to 10 (most important).
        require(_contributionValue > 0 && _contributionValue <= 10);

        FreelancerCommunityReputation storage reputation = freelancerCommunityReputation[_freelancerAddress][_communityAddress];

        // Decay of the contribution score with time (basic implementation).
        // For now, in a Quarter without any new contribution registration, the freelance loses all his previous contribution score.
        // It is gradual, but can be abused in different ways, so this needs more work.
        uint blocksSinceLastCommunityContributionRegistration = (block.number).sub(reputation.lastContributionBlock);
        // We can't store floating numbers, so before dividing, we multiply by 100 temporarily.
        uint blocksSinceLastCommunityContributionRegistrationMultipliedByOneHundred = blocksSinceLastCommunityContributionRegistration.mul(100);
        uint decayMultipliedByOneHundred = blocksSinceLastCommunityContributionRegistrationMultipliedByOneHundred.div(blocksPerQuarter);
        uint lostContributionScoreMultipliedByOneHundred = (reputation.contributionScore).mul(decayMultipliedByOneHundred);
        // Final lost contribution score.
        uint lostContributionScore = lostContributionScoreMultipliedByOneHundred.div(100);
        // If more than one Quarter elapsed, loose all (to avoid negative results).
        if (lostContributionScore > reputation.contributionScore) {
          reputation.contributionScore = 0;
        }
        // Else loose just the lost contribution score.
        else {
          (reputation.contributionScore).sub(lostContributionScore);
        }

        // Add new contribution value to the contribution score.
        reputation.contributionScore = (reputation.contributionScore).add(_contributionValue);
        // Max contribution score is 50.
        if (reputation.contributionScore > 50) {
            reputation.contributionScore = 50;
        }

        // Update the last contribution block number, to compute the decay in the next contribution registration.
        reputation.lastContributionBlock = block.number;

        emit FreelancerNewContribution(_freelancerAddress, _communityAddress, _contributionValue);
    }

    /**
    * @dev Checks if the freelancer is active in the DAO.
    * @param _freelancerAddress address Address of the freelance.
    **/
    function isFreelancerActive(address _freelancerAddress)
        constant
        public
        returns (bool freelancerIsActive)
    {
        freelancerIsActive = freelancerInformation[_freelancerAddress].isActive;
    }

    /**
    * @dev Get infos on the freelancer to compute his vote weight within one community.
    * @param _freelancerAddress address Address of the freelance.
    * @param _communityAddress uint256 Address of the community.
    **/
    function getFreelancerVoteWeight(address _freelancerAddress, address _communityAddress)
        constant
        public
        returns (bool freelancerIsActive, uint freelancerContributionRating, uint freelancerClientsRatings)
    {
        freelancerIsActive = freelancerInformation[_freelancerAddress].isActive;
        if (freelancerIsActive == false) {
            return (false, 0, 0);
        }
        FreelancerCommunityReputation memory reputation = freelancerCommunityReputation[_freelancerAddress][_communityAddress];
        freelancerContributionRating = reputation.contributionScore;
        for (uint i = 0; i < reputation.clientsRatings.length; i++) {
            uint freelancerClientRating = (reputation.clientsRatingsWeights[i]).mul(reputation.clientsRatings[i]);
            freelancerClientsRatings = freelancerClientsRatings.add(freelancerClientRating);
        }
    }

    /**
    * @dev Block a Freelancer Ethereum address.
    * @param _freelancerAddress address The freelancer Ethereum address to block.
    **/
    function blockFreelancer(address _freelancerAddress)
        public
        onlyOwner
    {
        // User must be active.
        require(freelancerInformation[_freelancerAddress].isActive == true);
        // User must not be blocked.
        require(freelancerInformation[_freelancerAddress].isBlocked == false);

        freelancerInformation[_freelancerAddress].isActive = false;
        freelancerInformation[_freelancerAddress].isBlocked = true;
    }

    /**
    * @dev Unblock a Freelancer Ethereum address.
    * @param _freelancerAddress address The freelancer Ethereum address to unblock.
    **/
    function unblockFreelancer(address _freelancerAddress)
        public
        onlyOwner
    {
        // User must not be active.
        require(freelancerInformation[_freelancerAddress].isActive == false);
        // User must be blocked.
        require(freelancerInformation[_freelancerAddress].isBlocked == true);

        freelancerInformation[_freelancerAddress].isActive = true;
        freelancerInformation[_freelancerAddress].isBlocked = false;
    }
}
