INTRODUCTION
------------
The User hash module allows you to create an individual hash for each user.

You can use the hash as a light weight user identification where you do not want
to use the Drupal login credentials, e.g. as an individual API Key for reading
insensitive content. The module does not implement such functionality. However,
it implements a function to compare hashes preventing from timing attacks.

INSTALLATION
------------
Install as you would normally install a contributed Drupal module. See:
https://drupal.org/documentation/install/modules-themes/modules-7
for further information.

CONFIGURATION
-------------
In Administration > Configuration > People > User hash
(admin/config/people/user_hash) configure which PHP hash algorithm to use
(default is sha256) and how many characters for the random string
(default is 32) when generating hashes.

HASH GENERATION
---------------
The user hash module adds update options on the user list page in
Administration > People (admin/people) for generating and deleting user hashes.

A new user hash will replace an existing one. No need to delete the old one
first.

DISPLAY
-------
The user hash is displayed read-only on the user edit form in
Administration > People > edit (user/%user/edit).
The hash is also displayed on the user profile if the user has administer user
permission or if it is his own account.

The display and position of the hash can be configured in Administration >
Configuration > People > Account settings > Manage fields and > Manage display
if the Field UI module is enabled.

HASH COMPARISON
---------------
The module provides user_hash_compare(), a function to compare hashes using a
constant-time algorithm in order to prevent from timing attacks. With PHP >= 5.6
you can use hash_equals() instead:
http://php.net/manual/en/function.hash-equals.php

MAINTAINERS
-----------
Current maintainers:
 * Richard Papp (boromino) - https://drupal.org/user/859722
