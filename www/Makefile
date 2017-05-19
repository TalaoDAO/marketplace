project_name = EMindHub

#
# Main tasks
#

install:
	make reset

deploy:
	make themes-deploy

reset:
	make mysql-import
	make drupal-update
	make drupal-cache-disable
	make drupal-emails-setup
	make drupal-emails-update
	make mysql-sanitize
	make drupal-rules-disable
	make drupal-watchdog-cleanup
	make smartmobility-install


#
# MYSQL
#
mysql-import:
	test -f tmp/emh.sql && drush sql-drop -y && drush sql-cli < tmp/emh.sql

mysql-sanitize:
	drush watchdog-delete all -y
	drush sqlsan --sanitize-password="test" --sanitize-email="emindhub.test+%uid@gmail.com" -y
	drush upwd --password="admin" admin


#
# Drupal
#
drupal-update:
	drush php-eval "views_invalidate_cache();"
	drush rr
	drush updb -y
	drush fra -y
	drush cc all

drupal-emails-setup:
	drush vset --format=json mail_system '{"default-system":"DevelMailLog"}'

drupal-emails-update:
	drush vset reroute_email_address emindhub.test@gmail.com
	drush vset mimemail_mail emindhub.test@gmail.com
	drush vset webform_default_from_address emindhub.test@gmail.com
	drush vset site_mail emindhub.test@gmail.com

drupal-cache-disable:
	drush vset preprocess_css 0
	drush vset preprocess_js 0
	drush vset cache 0
	drush vset page_cache_maximum_age 0
	drush vset cache_lifetime 0
	drush vset views_skip_cache TRUE

drupal-watchdog-cleanup:
	drush watchdog-delete all -y

drupal-rules-disable:
	drush rules-disable _emh_request_notification_moderate_mail
	drush rules-disable _emh_request_notification_notify_mail


#
# Smart Mobility
#
smartmobility-install:
	drush vset emh_smartmobility_base_url "http://smartmob.box.local"

#
# Building themes
#
themes-deploy:
	$(MAKE) -C ./sites/all/themes/emindhub/ deploy
	$(MAKE) -C ./sites/all/themes/smartmobility/ deploy
