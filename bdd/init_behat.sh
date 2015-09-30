curl -s https://getcomposer.org/installer | php
php composer.phar install
bin/behat --init
mv FeatureContext.php features/bootstrap
mv *.feature features
