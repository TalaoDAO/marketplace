ADVANCED FORM
===============================================================================
A UI tweak to /hide/ certain features or the form interface from normal use,
but still have them available on the page for validation and quick access.

This slims down the UI to make things seem simpler, without overloading the
maintenance tasks with layers of permissions, or removing any control from the
user.

USAGE
-------------------------------------------------------------------------------
When enabled, any configured form can have elements hidden (by css) for
normal use, and a small client-side button [Advanced] can be pressed to reveal
the rest of the form as needed.

CONFIGURATION
-------------------------------------------------------------------------------
The syntax for defining which form elements are 'hidden' is based entirely on 
css selectors, with some shortcuts.
node-form:[#revision-information]
- will hide the revision information fieldset on node forms.
block-admin-configure:[#user-specific-visibility-settings]
- will remove a seldom-used option from block admin pages.

Use firebug or similar to find the correct selectors to choose your target form 
elements.

A number of additional css classes are inserted into the form element for 
additional, specific control. 
Taxonomy terms selected on node forms are also set as context classes, so it's 
possible to define rules that only apply when a certain term is selected in the 
form.
More instructions are on the config page, which can be found at 
'/admin/settings/advancedform'

To debug the css or see how it works, look at the path '/advancedform_css'

SEE ALSO
-------------------------------------------------------------------------------
Written with reference to formfilter.module which does a similar job through
access restrictions, whereas I want to trust my users, but avoid confusing
them. And clean up my own admin edit interface.
http://drupal.org/project/formfilter
This module is intended to be more lightweight than formfilter, 
and does not have such an extensive admin UI.

vertical_tabs.module is excellent, and takes a different approach at minimizing 
the screen size and hiding unwanted elements.
*This module has not been tested with and may not work well with vertical_tabs*

OTHERS:
nodeformsettings http://drupal.org/project/nodeformsettings 
- a set of custom UI tweaks, half of which can now be done by this module.
compact forms http://drupal.org/project/compact_forms
- marginally tidies up some forms on the client side.
form defaults http://drupal.org/project/formdefaults
- advertises a UI for form_alter type operations. Untested

BACKGROUND
-------------------------------------------------------------------------------
This is more useful for in-house development with a set of trusted content
editors. It was built for tutoring, where I needed to be able to demonstrate
the functionality of the site as editors would see it, yet still have access
to admin functions without messing around with switchuser etc.
So I switched off the clutter.
Collapsed fieldsets are a good start, but there's still too many of them by
the time we start with ecommerce products etc.

Note this 'permission' isn't actually secure - the full form is still
available to browser hacks - like disable css or js

CSS-hide trick for context-sensitive forms developed by dman 2006

