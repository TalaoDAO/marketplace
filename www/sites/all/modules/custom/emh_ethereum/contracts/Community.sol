pragma solidity ^0.4.21;

import '../ownership/Ownable.sol';
import '../TalaoToken.sol';
import '../freelancer/Freelancer.sol';

/**
 * @title Community
 * @dev This contract details a TALAO community.
 * @author Talao
 */
contract Community is Ownable {

    // Talao token.
    TalaoToken public talaotoken;

    // Freelancer.
    Freelancer public freelancerContract;

    // Community name.
    string public communityName;

    // Active community?
    bool public communityIsActive;

    // Private community?
    bool public communityIsPrivate;

    // Sponsor address if private community.
    address public communitySponsor;

    // Token percentage balance to vote in community (10 = 10% token, 90% reputation). From 1 to 100.
    uint public communityBalanceToVote;

    // Minimum tokens to vote in community. From 1 to 100.
    uint public communityMinimumTokensToVote;

    // Minimum reputation to vote in community. From 1 to 100.
    uint public communityMinimumReputationToVote;

    // (Community commission on job) / 100. 100 means 1%. From 0 to 10000.
    uint public communityJobCommission;

    // Fee to join community.
    uint public communityJoinFee;

    // Community members.
    mapping(address => bool) public communityMembers;

    // For test purposes.
    uint256 public communityTokenBalance;

    // Event: a freelancer joined a community.
    event CommunitySubscription(address indexed _freelancerAddress, address indexed _communityAddress);

    /**
    * @dev Community.
    * @param _token address The address of the Talao token smart contract.
    * @param _freelancerContractAddress address The address of the Freelancer smart contract.
    * @param _name string Community name.
    * @param _isprivate bool Private community?
    * @param _sponsor address Sponsor address if private community.
    * @param _balancetovote uint Token percentage balance to vote in community (10 = 10% token, 90% reputation). From 1 to 100.
    * @param _mintokens uint Minimum tokens to vote in community. > 0
    * @param _minreputation uint Minimum reputation to vote in community. From 1 to 100.
    * @param _jobcommission uint (Community commission on job) / 100. 100 means 1%. From 0 to 10000.
    * @param _joinfee uint Fee to join community.
    **/
    function Community(
        address _token,
        address _freelancerContractAddress,
        string _name,
        bool _isprivate,
        address _sponsor,
        uint _balancetovote,
        uint _mintokens,
        uint _minreputation,
        uint _jobcommission,
        uint _joinfee
    )
        public
    {
        // By default, new communities are active.
        communityIsActive = true;

        // Load smart contract depencencies.
        talaotoken = TalaoToken(_token);
        freelancerContract = Freelancer(_freelancerContractAddress);

        // Community params.
        communityName = _name;
        communityIsPrivate = _isprivate;
        communitySponsor = _sponsor;
        communityBalanceToVote = _balancetovote;
        communityMinimumTokensToVote = _mintokens;
        communityMinimumReputationToVote = _minreputation;
        communityJobCommission = _jobcommission;
        communityJoinFee = _joinfee;

        // For test purposes.
        communityTokenBalance = talaotoken.balanceOf(this);
    }

    /**
    * @dev Community voting rules.
    * @param _balancetovote uint Token percentage balance for voting in community (10 = 10% token, 90% reputation). From 1 to 100.
    * @param _mintokens uint Minimum tokens to vote in community. From 1 to 100.
    * @param _minreputation uint Minimum reputation to vote in community (1 to 100)
    **/
    function setupVotingRules(uint _balancetovote, uint _mintokens, uint _minreputation)
        public onlyOwner
    {
        require (_balancetovote > 0 && _balancetovote <= 100);
        require (_mintokens > 0);
        require (_minreputation > 0 && _minreputation <= 100);
        communityBalanceToVote = _balancetovote;
        communityMinimumTokensToVote = _mintokens;
        communityMinimumReputationToVote = _minreputation;
    }

    /**
    * @dev Join a community.
    **/
    function joinCommunity()
        public
    {
        // To join a community, freelancers must have registred in the DAO.
        require(freelancerContract.isFreelancerActive(msg.sender) == true);

        communityMembers[msg.sender] = true;

        emit CommunitySubscription(msg.sender, this);
    }

    /**
    * @dev Leave a community.
    **/
    function leaveCommunity()
        public
    {
        // Revert if not a member.
        if (!communityMembers[msg.sender]) {
            revert();
        }
        communityMembers[msg.sender] = false;
    }

    /**
    * @dev Transfers tokens from the Community.
    * @param _to address Address to send the tokens to.
    * @param _amount uint256 Amount of tokens to transfer.
    **/
    function transferFunds(address _to, uint256 _amount)
        public onlyOwner
        returns (bool)
    {
        require (_amount <= talaotoken.balanceOf(this));
        talaotoken.transfer(_to, _amount);
        return true;
    }
}
