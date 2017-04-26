Mixpanel
========

This module provides integration with the Mixpanel real-time analytics
service.

Unlike Google Analytics, Mixpanel isn't for tracking aggregate data
about page views. Instead, you send specific events to Mixpanel when
users perform certain actions. This allows you to examine how users
interact with your site in real-time and connects all events to the
individual user who performed them (so you can contact them).

Mixpanel is great for finding ways to improve usability, studying how
existing features are actually used and is especially good for
startups who are trying to refine their MVP (Minimum Viable Product).

Visit this page to learn more about Mixpanel:

  https://mixpanel.com/features

Installing
----------

 1. Install this module in the normal Drupal way

 2. Sign-up for a free account on Mixpanel.com

 3. Obtain your Mixpanel token

 4. Go to Configuration -> Web services -> Mixpanel

 5. Copy your Mixpanel token into the appropriate field and click
    "Save configuration"

See the installation guide for a complete walk-through:

  https://drupal.org/node/2096061

Sending events to Mixpanel
--------------------------

The quickest way to start sending events to Mixpanel, is to simply
enable the "Mixpanel defaults" module. It will send events for:

 * Joining and leaving a group (in Organic groups)
 * Creating, deleting, updating a user
 * User login and logout
 * Creating, updating, and deleting a node
 * Creating a comment

However, the only way to get really powerful insights into how users
are using your application is by sending your own custom events!

You can do this in one of two ways:

 1. Writing a custom module and calling `mixpanel_track()' in PHP or
    `mixpanel.track()` in Javascript:

      https://drupal.org/node/2096069

 2. Using Rules. This is the best option if you want to use Mixpanel
    but you aren't a coder and can't write your own Drupal module:

      https://drupal.org/node/2096071

Documentation
-------------

You can find (and contribute to) the full documentation on Drupal.org:

  https://drupal.org/node/2096053
