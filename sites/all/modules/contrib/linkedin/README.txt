=== LINKEDIN INTEGRATION ===

Maintainers:  Pascal Morin (bellesmanieres) Greg Harvey (greg.harvey) David
Landry (davad) Kyle Mathews (kyle_mathews)

see http://drupal.org/node/919412

/*********************************************
Installation/initial configuration

   1. LinkedIn Integration requires the OAuth.php library. You can either :
          * install the Oauth module from http://drupal.org/project/oauth (7.x-3.x). You don't need to
            activate it, the module only uses the library it provides.
          * download the OAuth.php library from http://code.google.com/p/oauth/ and
            specify the full path on the module admin interface
   2. Enable the base Linkedin module as usual.
   3. Request an API key by registering at
https://www.linkedin.com/secure/developer and creating a new application. Fill
the required fields (name, etc) and pay attention to
          * provide an "Integration URL" : this field must match the URL of your
            server. This means you'll need a separate key for each stage or
            development server.[@todo : is this still true ?]
          * leave the "Callback URL" blank, the module takes care of this.
   4. Configuration : go to admin/config/services/linkedin and fill the "API key" and
"Secret key" fields with the keys you got from
https://www.linkedin.com/secure/developer. If you downloaded the library
directly from http://code.google.com/p/oauth/, you should see an additional
"OAuth library full path" field above : don't forget to include the filename.
   5. Usage : Users will have to associate their LinkedIn account with their local
Drupal account (at user/%user/edit/linkedin) to use any functionality provided
by submodules.


/*********************************************
Troubleshooting

If you encounter problems, please check the following points :

    * Integration URL : integration url you gave at
      https://www.linkedin.com/secure/developer is the actual one from which you
      are issuing the request.
    * Callback URL : do not specifiy a callback url at
      https://www.linkedin.com/secure/developer.
    * Server time : an out of sync server will issue a wrong timestamp. Linkedin.com
      requires that the timestamp must be within 5 minutes of accurate.
    * Permissions : make sure users have the right to use the features provided by
      the submodule you are trying to use.

Also, the module offers a "debug mode" (see admin/config/services/linkedin) that will
try to give useful info.


/*********************************************
Developer use

If you want to implement you own module, you can use the following :

<?php linkedin_get_profile_fields($uid, $fields = array ()) ?>
Fetch fields from a LinkedIn profile. Copes with public/private LinkedIn profile
depending on the currently logged in user.
Parameters :
 $uid : the uid of the Drupal user.
 $fields : an array of field's names to retrieve (see
http://developer.linkedin.com/docs/DOC-1061 for a extensive list)
Return value : A structured array of fields and their values (or the error message
received from the API as an array)

<?php linkedin_get_fields($url, $tokens) ?>
Fetch fields from a LinkedIn profile.
Parameters :
 $url : full request url to a LinkedIn API ressource (see
API doc for syntax)
 $tokens : the user tokens, as an array containing keys 'token_key' and
 'token_secret' with their value
Return value : A structured array of fields and their values (or the error message
received from the API as an array)

<?php linkedin_put_profile_field($uid, $body, $field = 'current-status') ?>
Let us 'put' data into user profile.
Parameters :
 $uid : the uid of the user we want to access
 $body : The content to be sent.
 $field : the field we want to update. Currently, only 'current-status' is
 available from the API.
Return value : http answer from the API (or the error message as an array)

<?php hook_linkedin_user_settings_page($form_state, $account) ?>
Let modules add their form elements to the user preferences edit form at
user/%user/edit/linkedin. Must return an array of form elements.

<?php hook_linkedin_admin_page() ?>
Let modules add their form elements to the admin settings at admin/config/services/linkedin.
Must return an array of form elements.

<?php hook_linkedin_user_edit_perms() ?>
Mainly useful only if you don't use any of the bundled sub-modules. This function
is called from the access callback at user/%user/edit/linkedin to check if the user
has the right to access his own LinkedIn setting! It returns an array of permissions,
typically the return would be the same as the one from your hook_perm().
Note that user is granted access if he has any permission implemented by a module using
this hook. That means you cannot deny access through this function and must make checks
in hook_linkedin_user_settings_page if you want to be selective on what to display
to the user.
