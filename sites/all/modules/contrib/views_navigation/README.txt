
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Limitations
 * Installation
 * Configuration
 * Working

INTRODUCTION
------------

Current Maintainer: Gaël Gosset <ggosset@insite.coop>

This module adds next and previous links on content pages when accessed from a 
view. It is intended for dynamic and/or paged view results, where the result set 
changes according to exposed filters, current user access rights,...

You may need this module if the content which comes after a given content 
depends on context, and more precisely depends on which content list you came 
from.

You may also look at this comparison of next/previous modules:
http://drupal.org/node/1276920

Developed by Insite
www.insite.coop

LIMITATIONS
-----------

Currently only works with the default query plugin or the Search API query
plugin, for node views with the following row styles:
* "fields" (supported content fields : Title, Link, Path and Image)
* "rendered entity", with a title linking to the node page.
Feel free to submit new views handlers based on the code from the existing ones
(it's usually only one class method to override).

INSTALLATION
------------

Follow the usual contrib module installation process:
http://drupal.org/documentation/install/modules-themes/modules-7


CONFIGURATION
-------------

On your view's configuration page, in Advanced, there is a new setting to enable
views navigation.
The links are added to the default node template, but there is also a block 
available if you need.

WORKING
-------

1. When the view is rendered, its query is stored with a unique ID and the 
fields linking to the nodes are rendered with an altered URL, where GET 
parameters are added to pass the stored query ID and the position of the node in 
the result set.
PERFORMANCE FIRST MODE CHOSEN:
2. When the node page is rendered, if these GET parameters are set, next and 
previous links are added accordingly.
3. When the link is clicked, the stored query is executed (with no paging) to 
know which node is the next/previous.
SEO FIRST MODE CHOSEN:
2. When the node page is rendered, if these GET parameters are set, the stored
query is executed (with no paging) to know which node is the next/previous. Next
and previous links are added accordingly.

Of course, these operations are cached for better performances.