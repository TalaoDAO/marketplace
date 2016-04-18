=== LINKEDIN INTEGRATION ===

Maintainers:  Pascal Morin (bellesmanieres) Greg Harvey (greg.harvey) David
Landry (davad) Kyle Mathews (kyle_mathews)

see http://drupal.org/node/919550

/*********************************************
Installation/initial configuration

   See http://drupal.org/node/919412.


/*********************************************
Configuration/Usage

After enabling the module, go to admin/settings/linkedin. You can display the
"Login with LinkedIn" link under the standard login form page, under the
standard login form block, or as a stand-alone block. Note that if you choose
the stand-alone block, you still got to enable it at admin/build/block.  Users
have to link their LinkedIn account to their local Drupal account from their
preferences at user/%user/edit/linkedin. If a visitor click on the link without
having tied the two accounts together, he will be asked to either login or
register as new user and redirected accordingly.


/*********************************************
Theming

It provides the following theme function for the "Login with LinkedIn" link :
<?php theme_linkedin_auth_display_login_block_button($display = NULL, $path =
'linkedin/login/0', $text = 'Log in using LinkedIn') ?> $display will be either
'drupal_login_page' 'drupal_login_block' 'linkedin_login_block', respectively
for standard login form page, standard login form block, and stand-alone block.
