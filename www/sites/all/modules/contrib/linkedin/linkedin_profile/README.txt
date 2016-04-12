=== LINKEDIN INTEGRATION ===

Maintainers:  Pascal Morin (bellesmanieres) Greg Harvey (greg.harvey) David
Landry (davad) Kyle Mathews (kyle_mathews)

see http://drupal.org/node/919598

/*********************************************
Installation/initial configuration

   See http://drupal.org/node/919412.


/*********************************************
Configuration/Usage

After enabling the module, go to admin/config/services/linkedin. You can choose to
display LinkedIn profile data as a tab, as a block, or inside the user profile
page. If you choose to use the block display, you still have to enable it at
admin/build/block. There is also a "hidden" display, which will output nothing
but keep the data available under $profile->linkedin in user-profile.tpl.php if
you need more control on the output. You can choose what fields to retrieve by
using the checkboxes (see http://developer.linkedin.com/docs/DOC-1061 for the
meaning of each), but keep in mind not all fields will output nicely by default
and you will need some theming work to display some of them. (This feature is
still in dev, and a few fields are missing.)  Also beware that the amount of
information returned depends on the relationship (in LinkedIn.com) between the
viewing and the viewed user. There is currently no ability to map individual
fields to standard core "profile" module fields

Be sure to check users have the permission to display this data. Users have to
link their LinkedIn account to their local Drupal account and to opt-in for
displaying these info from their preferences at user/%user/edit/linkedin .



/*********************************************
Theming

The module provides the following templates :

    * linkedin-user-page.tpl.php : main data output.
    * linkedin-user-page-positions.tpl.php : renders the LinkedIn "positions" 
      items 
    * linkedin-user-page-position-item.tpl.php : renders individual LinkedIn 
      "position" item 
    * linkedin-user-page-educations.tpl.php : renders the LinkedIn "educations" 
      items 
    * linkedin-user-page-education-item.tpl.php : renders individual LinkedIn 
      "education" item

You can also use the following function, which outputs each individual field item
<?php theme_linkedin_profile_user_page_item($item) ?>
