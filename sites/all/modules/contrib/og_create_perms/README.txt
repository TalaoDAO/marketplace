This is (currently) a rough module to manage create permissions for OG in D7. 
When users have no global commit rights, the node add page must contain the group context in the url. 

This is a basic framework for managing local content creation 
permissions for OG in D7.




Current Functionality 

* Validate the group field on node submission
   - Prevent content from being written to a group that the current 
     user is not a member of.

* Define a new set of OG permissions for content creation
   - Handle the following situations:
     - Global permission but no OG permission
     - Local permission but no global permission
        - Alter menu to allow access to node/add/x in the case of local only perms



 