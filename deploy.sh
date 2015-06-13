set -x
#Copy sites
cd /var/www
rm -r demo-emindhub
rm -r preview-emindhub

cp -r dev-emindhub/ demo-emindhub
rm -r demo-emindhub/.git
cp -r demo-emindhub/ preview-emindhub

cp ~/settings-dev.php /var/www/dev-emindhub/sites/default/local.settings.php
cp ~/settings-demo.php /var/www/demo-emindhub/sites/default/local.settings.php
cp ~/settings-preview.php /var/www/preview-emindhub/sites/default/local.settings.php

chown -R www-data:www-data /var/www/demo-emindhub/
chown -R www-data:www-data /var/www/preview-emindhub/

############################### DEMO #################################
cd /var/www/demo-emindhub
drush dis -y devel, get_form_id, diff, devel_debug_log, pathinfo, views_maintenance, admin_devel, dbtng_migrator, hacked, masquerade, memcache_admin, module_filter, security_review, seo_checklist, stickynote, switchtheme, unused_modules
drush dis -y entity_legal, eu_cookie_compliance
#drush dis -y admin_menu
drush dis -y user_alert, userpoint

drush vset -y error_level 0
drush vset user_email_verification FALSE ; drush vset user_registrationpassword_registration none
drush sqlq "delete from autoassignrole_page where rid_page_id=3;"
#drush role-remove-perm 'authenticated user' '???'

drush cc all

############################### PREVIEW #################################
cd /var/www/preview-emindhub
drush dis -y devel, get_form_id, diff, devel_debug_log, pathinfo, views_maintenance, admin_devel, dbtng_migrator, hacked, masquerade, memcache_admin, module_filter, security_review, seo_checklist, stickynote, switchtheme, unused_modules
drush en -y entity_legal, eu_cookie_compliance, user_alert
#drush dis -y admin_menu
drush dis -y reroute_email, userpoints
drush vset -y error_level 0
drush vset user_email_verification TRUE ; drush vset user_registrationpassword_registration default
#drush entity-delete node ???
drush sqlq "delete from autoassignrole_page where rid_page_id=2;"
drush sqlq "delete from autoassignrole_page where rid_page_id=1;"
drush cc all
