One-time login is a small utility module which allows you to e-mail one-time
login links to selected users, and can also generate a CSV of one-time login
URLs for selected users.

Once enabled, this module adds two operations to the Administration >> People
page at admin/people: "Send one-time login link to the selected users" and
"Download CSV of one-time login URLs for the selected users".

The CSV has the following columns in this order:

[ user ID | user name | user e-mail address | one-time login URL |
  expiration date (if any) of the one-time login URL | user status ]

One-time login URLs have an expiration date only if the user has previously
logged in to the account.

This module also provides a Views field handler for one-time login URL and a
"Send one-time login link to user" action for use with Views Bulk Operations.
