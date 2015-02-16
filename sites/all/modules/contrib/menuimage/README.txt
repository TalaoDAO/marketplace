Module: 'menuimage'
kris@o3world.com
march 16 '13

When editing a menu link, this module provides a file field
to upload an image to associate with a menu item. In the
array returned by menu_link_load, the fid of the image file
is contained in [options][content][image]. This may may be
passed as a parameter to file_load to obtain its public:// uri,
and further used with either file_build_uri or image_style_url
to populate the src= attribute of an <img>.
