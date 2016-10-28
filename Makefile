project_name = eMindHub

#
# Main tasks
#
init: install

install: install-theme

reset:
	cd www/
	drush sql-drop -y && drush sql-cli < emh.sql
	drush php-eval "views_invalidate_cache();" && drush rr && drush updb -y && drush fra -y && drush cc all
	drush vset preprocess_css 0 && drush vset preprocess_js 0 && drush vset cache 0 && drush vset page_cache_maximum_age 0 && drush vset cache_lifetime 0 && drush vset views_skip_cache TRUE
	drush vset maintenance_mode 0
	drush vset reroute_email_address emindhub.test@gmail.com && drush vset mimemail_mail emindhub.test@gmail.com && drush vset webform_default_from_address emindhub.test@gmail.com && drush vset site_mail emindhub.test@gmail.com
	drush watchdog-delete all -y
	drush sqlsan --sanitize-password="test" --sanitize-email="emindhub.test+%uid@gmail.com" -y && drush upwd --password="admin" admin
	drush rules-disable rules_emh_request_send_notification_email

#
# Building themes
#
install-theme:
	$(MAKE) -C ./www/sites/all/themes/emindhub/ init
