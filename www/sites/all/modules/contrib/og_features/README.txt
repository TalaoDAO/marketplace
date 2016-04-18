OVERVIEW
-------------------------------------------
OG Features aims to allow group owners and site administrators to disable 
certain Features within a given group without the use of the Spaces module.

What is a feature? A feature can either be a normal feature created by
the Features module, or it can be a module that bundles existing components
of your site; so, OG Features, does not require the Features module. A 
Feature or Module can provide one or many OG Features. 

If a user has adequate permissions, when clicking on the "Group" tab as
you view a group-type entity, you'll see a link for the group's "Features".
From there, you can view the available features and enable or disable them.


HOW IT WORKS
-------------------------------------------
og_features uses a number of hooks and alters to effectively disable the
components specified in each toggleable feature. hook_menu_alter() hijacks 
the access callback for every single menu item, and passes all relevant 
menu information into the custom access callback used to analyze each item. 
The custom access callback then attempts to detect the current group context, 
determines which features have been disabled for that group, and will deny 
access if the page originates from a component in any of the disabled features. 
If there is no group, or if the the request is not from a denied feature, 
the original access callback will be invoked to determine access. Other 
hooks used to prevent access to certain components:

* hook_context_load_alter()
 - To remove contexts from disabled features
* hook_panels_pre_render() 
 - To remove views and panel panes from panels
* hook_block_view_alter()
 - Removes view blocks
* hook_node_validate()
 - Prevents disabled content types from being posted into groups
 
And some more...


WHAT IS SUPPORTED
-------------------------------------------
* Node types
 - Will deny access when trying to add a disabled node type to a group
* Views
 - Blocks and pages
* Context
* Panel panes
* Page paths
 - For example, some modules add a tab to group home page. You can specify 
   the path for OG Features to disable within the group
 - OG Features will also automatically disable any custom page callbacks 
   implemented inside the feature itself
 

ADMIN SETTINGS
-------------------------------------------
Navigate to the OG features admin page inside the OG admin menu. From there,
you can set global settings for each OG feature, for each group type. The
available options for each OG feature, for each node type, are "toggle"
(group admins can toggle the feature), "always enabled", or "always 
disabled". If the feature is not set to "toggle", it won't show on the
group "Features" tab.


WHAT IS MISSING
-------------------------------------------
Ability to make feature customizations, not just disable/enable (possible?)


UPGRADING FROM DRUPAL/OG-6.x TO 7.x
-------------------------------------------
1. Upgrade your site using the Drupal.org upgrade guide
2. Make sure OG7.x is installed and fully-updated using update.php
3. Follow OG7 migration instructions, which involves using the Migrate module.
4. Install og_ui and og_context.
5. Re-enable og_features, and run update.php


HOOKS/API (INTEGRATION)
-------------------------------------------
See og_features.api.php


OTHER USEFUL FUNCTIONS
-------------------------------------------
og_features has some other useful functions that other modules and features 
might find useful.

* og_features_feature_is_disabled($feature, $group = NULL)
 - Determine if a feature is disabled for a given group, or the current 
   group if group is omitted.
 - This could be useful for features/module that add links to the og_links 
   block
* og_features_component_is_disabled($type, $name, $group = NULL)
 - Determine if a certain feature component is disabled
 - Example: og_features_component_is_disabled('node', 'discussion');
* og_features_in_feature($feature, $type, $name)
 - Determine if a feature component is part of a certain feature 
   (applies only to what is supplied in hook_og_features())
 - Example: og_features_in_feature('document_feature', 'views', 'og_tab_document');
