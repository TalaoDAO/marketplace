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

drush dis -y devel, get_form_id, diff, devel_debug_log, pathinfo, views_maintenance, admin_devel, dbtng_migrator, hacked, masquerade, memcache_admin, module_filter, security_review, seo_checklist, stickynote, switchtheme, unused_modules, views_data_export, robotstxt
drush dis -y entity_legal, eu_cookie_compliance
drush dis -y user_alert, userpoint

drush cc all

