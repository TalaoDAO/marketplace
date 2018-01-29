INTRO
=====

This module integrates Drupal with the Calais Web-Service. The web
service allows automated content term-extraction and tagging. It also 
provides an API in which any contributed module can interact with Calais.

** Important: ARC2 is no longer a required dependency for this module and can
be removed from your Drupal installation if you have it there for this module. **

INSTALLATION
============
1) Place this module directory into your Drupal modules directory.

2) Enable the Calais module in Drupal, at:
   administration -> site configuration -> modules (admin/build/modules)

3) Obtain an Calais API key from their website:
   https://iameui-eagan-prod.thomsonreuters.com/iamui/UI/createUser

4) Add Calais API Key and tune other settings at:
   administration -> configuration -> content authoring -> calais settings

5) Set up tagging on your content types as desired by visiting the opencalais fields
   tab for the content type you wish to apply tags to.

There are some reports that OpenCalais processing can use a lot of memory.
Consider 64MB the minimum PHP memory allocation needed. You may need more 
depending on what you have installed and enabled.

CREDITS
========
Re-factored & Maintained by:
  - Michel R. Bagnall - mrbagnall at icloud dot com  

Initially Authored by
  - Irakli Nadareshvili - irakli at phase2technology dot com
  - Frank Febbraro - frank at phase2technology dot com

Sponsored by
  - ThomsonReuters <http://www.thomsonreuters.com/>
