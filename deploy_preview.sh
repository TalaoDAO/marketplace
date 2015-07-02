exit 0
date +"%T"
set -x
#Copy sites
cd /var/www
rm -r preview-emindhub

cp -r dev-emindhub/ preview-emindhub
rm -r preview-emindhub/.git

cp ~/settings-preview.php /var/www/preview-emindhub/sites/default/local.settings.php
cp ~/htaccess_noauth /var/www/preview-emindhub/.htaccess

chown -R www-data:www-data /var/www/preview-emindhub/

echo 'flush_all' | nc -q 2 localhost 11211

############################### PREVIEW #################################
cd /var/www/preview-emindhub
drush dis -y devel, get_form_id, diff, devel_debug_log, pathinfo, views_maintenance, admin_devel, dbtng_migrator, hacked, masquerade, memcache_admin, module_filter, security_review, seo_checklist, stickynote, switchtheme, unused_modules, robotstxt
drush en -y entity_legal, user_alert, piwik
drush dis -y admin_menu, reroute_email, userpoints
drush vset -y error_level 0
drush vset preprocess_js 1 --yes
drush vset preprocess_css 1 --yes
drush vset drush vset user_registrationpassword_registration with-pass ; drush vset user_mail_register_pending_approval_notify FALSE ; drush vset user_mail_register_no_approval_required_notify FALSE 
drush sqlq "delete from autoassignrole_page where rid_page_id=2;"
drush sqlq "delete from autoassignrole_page where rid_page_id=1;"

drush delete-all challenge
drush delete-all webform
drush delete-all question1

drush cc all
