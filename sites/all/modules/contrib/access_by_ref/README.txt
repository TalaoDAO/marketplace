Access By Reference

There are several modules with similar functionality, and one of them may serve your needs better.  This one gives several tools for providing access to edit a node.

To use, on the configuration page, provide sets of content_type|field_machine_name. It provides access in one of three ways:
 1.  The user that can edit a referenced node can edit the subject node.
 2.  The user has a profile value equal to a field value. (User should not be able to edit that profile element)
 3.  The user is referenced in the identified field. 

Then, grant permission to a class of users to edit when referenced.

Note that for option 2, it only works at present with text and number values, not entity references.