Drupal collapsiblock.module README.txt
==============================================================================

Makes blocks collapsible.


Theme Support
------------------------------------------------------------------------------

Collapsiblock needs to know the page element in which  block container, block 
titles (subjects) and block contents are enclosed, something that varies by 
theme.

Collapsiblock tries to support out-of-the-box the majority of theme by using
flexible jQuery selector. But for some themes it might not work.

If Collapsiblock doesn't work, go to the /admin/build/themes/settings.
You can set here your own jQuery selector for the different elements in blocks.

More info: http://api.jquery.com/category/selectors/