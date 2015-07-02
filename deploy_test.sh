set -x
#Copy sites
date +"%T"
cd /var/www
rm -r test-emindhub

cp -r dev-emindhub/ test-emindhub
rm -r test-emindhub/.git

cp ~/settings-test.php /var/www/test-emindhub/sites/default/local.settings.php

chown -R www-data:www-data /var/www/test-emindhub/

echo 'flush_all' | nc -q 2 localhost 11211

############################### DEMO #################################
cd /var/www/test-emindhub
drush cc all

