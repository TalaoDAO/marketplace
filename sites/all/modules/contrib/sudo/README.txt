INSTALLATION

Copy the module's folder into your site's modules directory, and enable the 
module on your site.

ADMINISTRATION

Visit the administration page for the sudo module at /admin/user/sudo, and 
follow the directions for adding users and choosing which roles to toggle for 
their accounts.  Once any user has some roles enabled, a button will appear in 
the lower right corner of every page that user views.

CAVEATS

Sudo functions by removing and adding user roles on the fly.  Any functionality
that relies upon user roles will be affected if those roles are sudo roles for 
any users; for example, an action that sends emails to all users with the 
"administrator" role will fail if the administrator role is a sudo role for some
accounts that are not sudoing when the action is triggered.  To get around this,
you may wish to add a role with no permissions for administrators, and key tasks
that would normally target the "administrator" role to that role instead.

Sudo functionality bypasses Drupal's user_save function, so modules implementing
hook_user will not know about the changes that sudo makes to the users' roles.

THEMING

There are a few options on the administration page for theming the button.  You
can set the button's text when sudoing and not sudoing; these values will NOT be
translated.  To change the look of the button without writing code, check the 
"Use Theme Path" checkbox and follow the directions.  You can also override the
function theme_sudo_switch in a custom theme or module.  Finally, if you want
the button not to be inserted into every page, check "Hide Sudo Button"; you 
will then need to make the button display in your theme.
