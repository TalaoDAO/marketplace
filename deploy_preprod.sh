date +"%T"
set -x
#Copy sites
cd /var/www
rm -r preprod-emindhub
cp -r dev-emindhub/ preprod-emindhub
rm -r preprod-emindhub/sites/default/files
cp -r preview-emindhub/sites/default/files preprod-emindhub/sites/default

cp ~/settings-preprod.php /var/www/preprod-emindhub/sites/default/local.settings.php

chown -R www-data:www-data /var/www/preprod-emindhub/

echo 'flush_all' | nc -q 2 localhost 11211

############################### PREVIEW #################################
cd /var/www/preprod-emindhub
drush fra -y
drush updatedb
drush cc all
