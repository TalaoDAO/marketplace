
Private comments
http://drupal.org/project/privatecomments

A node author can see all of the comments and replies, but comment authors
can only see the comments they've posted and any replies to their comments.

A node author can't post the comments firstly. Firstly must add the comment
other user, and after that the node author can respond on it.

For example: the module could be useful for using in freelance like sites.
Where freelancers can comment a job and can't see comments each other, but
a job poster can see all comments.

INSTALLATION

1. Install as usual

2. In admin menu go to Structure -> Content types -> select an appropriate
content type and enable "Private comments". Also can be used two options:
"Hide a comment reply link" - if enabled than a comment reply link will be hided;
"Show a reply form after every thread" - if enabled a comment reply form
will be shown after every thread. An option "Show reply form on the same
page as comments" in "Comment settings" must be enabled.

3. Set appropriate user permissions (/admin/people/permissions).
A user with a "Content type: View all privatecomments" permission will be
able to see all comments. Before using that permission, could be created
a new "user role" (/admin/people/permissions/roles).
