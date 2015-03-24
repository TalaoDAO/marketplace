// $Id: README.txt,v 1.1.2.2 2010/11/27 13:30:52 quiptime Exp $

The More Buttons (MB) module allows to use additional buttons with Drupal.
MB is a suite of several modules:

  - More Buttons
  - More Buttons Content
  - More Buttons Comment
  - More Buttons User
  - More Buttons Extra


Requirements
--------------------------------------------------------------------------------
The MB modules are written for Drupal 7.0+.


Installation
--------------------------------------------------------------------------------
Copy the MB module folder, complete with all sub modules, to your module
directory and then enable the modules on the admin modules page.


Documentation
--------------------------------------------------------------------------------
- More Buttons (MB)

  You can interact with the MB module. You can use the button and tab values,
  defined by the MB module.
  For more informations please read the code included comments of the function
  mb_get_values() in the mb.module file.

  Example to get the "Save and continue" button value:

  $value = module_invoke('mb', 'get_values', 'mb', 'sac');

  Use the t() function to display the value.


Module developers
--------------------------------------------------------------------------------

Please read the documentation hints for the MB module.


Maintainer
--------------------------------------------------------------------------------
Quiptime Group
Siegfried Neumann
www.quiptime.com
quiptime [ at ] gmail [ dot ] com

