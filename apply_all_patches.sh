drush up
git apply -v patchs/drupal-7.x-Issue-2028713-by-axel.rutz__0.patch
git apply -v patchs/bartick-menu-images.patch
git apply -v patchs/mb_custom-settings-permission_2264913-1.patch --directory=sites/all/modules/contrib
git apply -v patchs/entityreference_fields_do_not_validate-2249261-10.patch --directory=sites/all/modules/og/
git apply -v patchs/schema-1850196-autoslave_incompatibility-4.patch --directory=sites/all/modules/debug/schema
git apply -v patchs/field_collection-remove_button_broken-1675522-12.patch --directory=sites/all/modules/contrib/field_collection
git apply -v patchs/legal-text_format-445308-37.patch  --directory=sites/all/modules/contrib/legal/
