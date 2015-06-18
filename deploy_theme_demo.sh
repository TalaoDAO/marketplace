set -x
rm -r /var/www/demo-emindhub/sites/all/themes/emindhub
cp -r /var/www/dev-emindhub/sites/all/themes/emindhub /var/www/demo-emindhub/sites/all/themes/
drush @demo cc theme-registry
