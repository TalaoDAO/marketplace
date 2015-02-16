
VIEWS FILTER HARMONIZER
=======================
This module solves an operational foible with the Views module regarding
filtering. It allows you to have a contextual filter argument apply only when
there is no regular (exposed) filter value present. For intuitive visual
feedback of the underlying process, the module will also fill out the exposed 
filter form with the contextual filter value(s) used.
Once the visitor changes the value for the exposed filter, the module makes sure
that the corresponding contextual filter does not interfere.
This module works for all Views displays (page, attachment etc.) with AJAX on
as well as off.

INSTALLATION
------------
Install and enable like any module.

If you do not wish to see any debug info, visit admin/people/permissions and
untick the boxes under Views Filter Harmonizer, option View info/debug messages.

The only addition you'll see in the Views UI is an extra check box for each
contextual filter field that has a companion exposed filter. It is called
"Ignore this contextual filter after initial page load, when the user applies
this same field's exposed filter." It lives under the heading "WHEN THE FILTER
VALUE IS IN THE URL OR A DEFAULT IS PROVIDED" on the contextual filter config
popup. You get to this popup via the "Advanced" fieldset, located in the upper
right corner of the main Views UI page.
For convenience the same check box is repeated on the Views regular filter
configuration popup form, if a companion contextual filter was configured first.

You can globally enable the above behaviour for ALL fields that have both
contextual and a regular (exposed) filters, via the check box on the
Administration >> Configuration >> Content Authoring >> Views Filter Harmonizer
page. When you do this the checkboxes on the Views UI regular and contextual
filter forms will no longer appear.

USE
---
As mentioned above, the contextual filters kick in upon visiting a "new" page.
What is considered a "new" page?
If your view is located at yoursite.com/worldcup with an optional contextual
country filter/argument, then starting from yoursite.com/worldcup any page OTHER
than yoursite.com/worldcup with or without any optional query string, i.e.
yoursite.com/worldcup?bla=bluh, is a NEW page.
So yoursite.com/worldcup/germany is a new page and the contextual filter
"germany" will be honoured, provided the default exposed filter value is empty.
Staying on this URL, but changing any exposed filter widget, possibly resulting
in a query string being appended, is NOT considered a "new" page. In other
words, the module will ignore the contextual filter "germany" and obey the
exposed filter selection instead.

SPECIAL BEHAVIOUR: MULTI-VALUED EXPOSED FILTERS
-----------------------------------------------
Exposed filters, grouped or single, that have the "Allow multiple selections"
box ticked will have their default values MERGED with the contextual filter
argument(s) upon initial page load.
After initial page load the exposed filter selection will be applied, as per
normal.
Note: on Views that use a pager as well as a multi-valued exposed filter,
harmonization, i.e. the merging of contextual and exposed filter values, will
occur on every page of the pager.

SPACES IN CONTEXTUAL FILTER ARGUMENTS
-------------------------------------
If you tick "Allow multiple values" on the contextual filter configuration panel
you must NOT tick "Transform dashes to spaces". Then append your contextual
arguments to the base URL with spaces replaced by dashes. Alternatively for
view pages with harmonization turned on, you may use the | (pipe symbol) to
OR contextual filter arguments. This will allow multiple contextual values,
with or without spaces, without you having to tick the "Allow multiple values"
box.

KEEP IN MIND
------------
For a Grouped filter with "Allow multiple selections" ticked the user selections
are ANDed together by default. If you use an accompanying contextual filter and
intend to string together multiple values via plus signs in the URL, then you
may want to pair that up in your exposed filter with a likewise OR.
To do this, click under Filter Criteria the down-arrow next to "Add", followed
by "Add/Or, Rearrange". Then select the OR operator on the next panel and Apply.

BLOCKS
------
Note that Views that are displayed in blocks will not receive any contextual
arguments appended to the URL, unless you provide a default value, i.e.
through a PHP code snippet like:

  return arg(1);

This extracts the first contextual argument, assuming the View path has only one
component.
With this in place you can then use the "ignore" check box just as you do for
page and attachment displays.
Remember: for exposed filters to appear with Views block displays, AJAX must be
ON.

CACHING ENGINES
---------------
By default the module uses the $_SESSION variable to store the previously
visited path (including contextual filter arguments). If you use a caching
engine or web accelerator like Varnish, this may be undesirable. In that case
install http://drupal.org/project/session_cache so that this info is
transparently stored on an alternative medium, e.g. a cookie (with page
exclusion strategy) or the database (using a suitable session id). See the
Session Cache API documentation for details.

GEOFIELD
--------
For Views Filter Harmonizer to work with the Geofield module, the Geofield
Exposed Proximity Filter needs to have its Source of Origin Point set to
"Geocoded Location", not "Contextual Geofield Proximity Filter".
At the same time to display distances the Geofield Proximity Field needs to
have its Source or Origin Point set to "Exposed Geofield Proximity Filter", so
that the distances displayed reflect the filter origin entered.

                                    * * *
