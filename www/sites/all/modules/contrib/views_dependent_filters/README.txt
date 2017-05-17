Views Dependent Filters
=======================

This module allows the presence of exposed filters on a view to be controlled by values in another exposed filter.

Dependent filters are hidden when not relevant, and their values are not considered when the exposed form is submitted.

The module is compatible with both the Views basic and the Better Exposed Filters form plugins.

Example
-------

Suppose you had a view showing several kinds of products, such as cake, bicycles, and books, and an exposed filter on product type that lets the user refine the listing to one or more types.

With this module you could add the following filters:
  - cake flavour, such as lemon, chocolate, coffee
  - bicycle size
  - book genre
and each filter will only show when the type it relates to is selected in the filter for product type.

The user experience is thus:

1. Load the page.
2. Select 'cake'. The cake flavour filter now appears in the exposed filter area.
3. Select 'chocolate'.
4. Submit the form to apply the filters.
5. In the refined view result, the user can unselect 'cake' and the cake flavour filter will disappear. Submitting the form at this point will take them back to the original, unfiltered view. Alternatively, selecting another type of product will let them select bicycle size or book genre accordingly.

Note that selecting *both* 'cake' and 'bicycle' will cause both the dependent filters to show, but due to the nature of Views queries, selecting values in both will not show any results! (Unless you stock a chocolate-flavoured bicycle with a 19" frame.)

Usage
----

1. Add a filter of type 'Global: Dependent filter' to your view. It should be positioned after the controlling filter and before the dependent filter(s).
2. In the first settings form, choose the controller filter. Only filters prior to this one in the filter order are available.
3. In the second settings form, choose the values on the controller filter that allow the dependent filters, and choose which filters are dependent.

Note that you can have multiple instances of the Dependent filter handler; indeed the above example would require one for each product type.
