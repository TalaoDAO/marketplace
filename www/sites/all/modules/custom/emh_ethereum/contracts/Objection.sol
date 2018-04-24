pragma solidity ^0.4.21;

/* Objection : as a user I want to be able to change the value of the DAO parameters
  An objection is a request from an user to change a parameter of the DAO. If no body
  objects for a certain time, then, the value is changed.

  A list of the parameters names and values is stored in the contract
*/
contract Objection {

    // A new objection was created
    event NewObjection(int id, bytes32 variable, int value, string justification);
    // A single user has rejected the objection
    event UserHasRejected(int indexed objection_id, address user);
    // Too many users have rejected the objection : it is canceled
    event Fail(bytes32 varname, int value);
    // The objection succeeded since to few users rejected it in the time scale
    event Succeed(bytes32 varname, int value);

    // Modifier to restrict some function for the contract owner
    address owner;
    modifier onlyOwner {
        require(msg.sender == owner);
        _;
    }

    // Current objection
    // Only one objection at the same time is handled
    enum State { unknown, waiting }
    State status = State.unknown;
    address public currentOwner;
    string public currentJustification;
    int public proposed_value;
    bytes32 public variable_name;
    uint public ending_date;
    address[] hasRejected;
    int public currentObjectionId;

    // Past objections
    struct Values { int value; bool used; }
    mapping(bytes32 => Values) public values;
    bytes32[] public names;

    /* Constructor : initialize 3 default variables */
    function Objection() public {
        owner = msg.sender;
        names.push("objection_duration");
        names.push("objection_threshold");
        names.push("profile_price");
        values["objection_duration"] = Values({value: 2 days, used:true});
        values["objection_threshold"] = Values({value: 2, used:true}); // must at leat have 2 rejections
        values["profile_price"] = Values({value: 222, used:true});
    }

    // Public functions

    // Getter : number of currently stored variables
    function names_length() public view returns (uint) {
        return names.length;
    }

    // Getter : value of variable
    function get_value(bytes32 varname) public view returns (int) {
        return values[varname].value;
    }

    // Getter : current objection variable name
    function get_variable_name() public view returns (string) {
        return bytes32ToStr(variable_name);
    }

    // Getter : current objection future value
    function get_proposed_value() public view returns (int) {
        return proposed_value;
    }

    // Getter : current objection ID
    function currentObjection() public view returns (int) {
        if (ending_date > 0) {
            return currentObjectionId;
        }
    }

    // Launch a new Objection. Ask for a parameter change of value.
    function openObjection(string justification, int value, bytes32 variable) public {
        assert (status != State.waiting);
        currentJustification = justification;
        currentOwner = msg.sender;
        status = State.waiting;
        variable_name = variable;
        proposed_value = value;
        ending_date = now + uint(values["objection_duration"].value);
        currentObjectionId++;
        emit NewObjection(currentObjectionId, variable, value, justification);
    }

    // Vote against the current objection
    function reject() public {
        if (status == State.waiting && (now < ending_date)) {
            hasRejected.push(msg.sender);
            emit UserHasRejected(currentObjectionId, msg.sender);
        }
    }

    // End an objection.
    function endObjection() public returns (bool) {
      if (status == State.waiting && now >= ending_date) {
        // Reject the objection.
        if (hasRejected.length >= uint(values['objection_threshold'].value)) {
          emit Fail(variable_name, proposed_value);
          cleanup();
          return true;
        }
        // Accept the objection and update or set the variable.
        else {
          if (!values[variable_name].used)
            names.push(variable_name);
          values[variable_name] = Values({value:proposed_value, used:true});
          emit Succeed(variable_name, proposed_value);
          cleanup();
          return true;
        }
      }
      return false;
    }

    // Only owner can for ending the current objection (useful for debugging)
    function forceEnd() public onlyOwner {
        ending_date = now;
        endObjection();
    }

    // Internal functions

    // Helper function to handle string / bytes32 conversion
    function bytes32ToStr(bytes32 _bytes32) internal pure returns (string){
        // string memory str = string(_bytes32);
        // TypeError: Explicit type conversion not allowed from "bytes32" to "string storage pointer"
        // thus we should fist convert bytes32 to bytes (to dynamically-sized byte array)

        bytes memory bytesArray = new bytes(32);
        for (uint256 i; i < 32; i++) {
            bytesArray[i] = _bytes32[i];
            }
        return string(bytesArray);
    }

    // Private functions

    // Clean the current objection state
    function cleanup() private {
        status = State.unknown;
        delete hasRejected;
        currentJustification = "";
        proposed_value = 0;
        ending_date = 0;
        variable_name = "";
    }

}
