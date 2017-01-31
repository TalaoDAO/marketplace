project_name = eMindHub

#
# Main tasks
#

reset: mysql-import drupal-update drupal-cache drupal-emails mysql-sanitize drupal-rules


#
# MYSQL
#
mysql-import:
	test -f emh.sql && drush sql-drop -y && drush sql-cli < emh.sql

mysql-sanitize:
	drush watchdog-delete all -y
	drush sqlsan --sanitize-password="test" --sanitize-email="emindhub.test+%uid@gmail.com" -y && drush upwd --password="admin" admin


#
# Drupal
#
drupal-update:
	drush php-eval "views_invalidate_cache();" && drush rr && drush updb -y && drush fra -y && drush cc all

drupal-emails:
	drush vset reroute_email_address emindhub.test@gmail.com && drush vset mimemail_mail emindhub.test@gmail.com && drush vset webform_default_from_address emindhub.test@gmail.com && drush vset site_mail emindhub.test@gmail.com

drupal-cache:
	drush vset preprocess_css 0 && drush vset preprocess_js 0 && drush vset cache 0 && drush vset page_cache_maximum_age 0 && drush vset cache_lifetime 0 && drush vset views_skip_cache TRUE

drupal-rules:
	drush rules-disable rules_emh_request_send_notification_email
