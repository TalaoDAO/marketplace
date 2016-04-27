<?php

$databases = array();
$databases['default']['default'] = array(
     'driver' => '__DB_DRIVER__',
     'database' => '__DB_NAME__',
     'username' => '__DB_USERNAME__',
     'password' => '__DB_PASSWORD__',
     'host' => '__DB_HOST__',
     'prefix' => '__DB_PREFIX__',
   );

$update_free_access = FALSE;

$drupal_hash_salt = '__SALT__';

$base_url = '__PROTO__://__DOMAIN__';  // NO trailing slash!

# File paths
$conf['file_directory_path'] = 'sites/default/files';
$conf['file_public_path'] = $conf['file_directory_path'];
# www/sites/default/settings.php
$conf['file_private_path'] = '__PRIVATE_PATH__';
$conf['file_temporary_path'] = '__TMP_PATH__';
$conf['file_directory_temp'] = $conf['file_temporary_path'];

ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';
$conf['allow_authorize_operations'] = FALSE;

include_once('./includes/cache.inc');
include_once('./sites/all/modules/contrib/memcache/memcache.inc');
$conf['cache_default_class'] = 'MemCacheDrupal';
$conf['memcache_key_prefix'] = '__MEMCACHE_PREFIX__';

