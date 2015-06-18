set -x
rm -r /var/www/preview-emindhub/sites/all/themes/emindhub
cp -r /var/www/dev-emindhub/sites/all/themes/emindhub /var/www/preview-emindhub/sites/all/themes/
drush @preview cc theme-registry
