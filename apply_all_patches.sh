drush up

curl https://www.drupal.org/files/issues/field_collection.array_filter_0.patch | git apply -v --directory=sites/all/modules/contrib/field_collection #https://www.drupal.org/node/2630088
curl https://www.drupal.org/files/issues/multilanguage-support-2727733-7.patch | git apply -v --directory=sites/all/modules/contrib/pet #https://www.drupal.org/node/2727733
