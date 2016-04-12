# ua-parser
In order to use this module you will have to download [ua-parser](https://github.com/tobie/ua-parser).

I used composer to solve this:

<code>
cd sites/default/modules/safari_cache_hotifx  
composer require 'tobie/ua-parser:*@dev'  
cd vendor/tobie/ua-parser/php  
php bin/uaparser.php ua-parser:update  
</code>

If you plan to check in all the files in git, make sure to delete `vendor/tobie/ua-parser/.git*` and `vendor/tobie/ua-parser/php/resources/.gitignore`.

# Composer Installation OSX
<code>
curl -s https://getcomposer.org/installer | php  
sudo mv composer.phar /usr/local/bin/composer
</code>