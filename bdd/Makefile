COMPOSER_BIN ?= ./bin/composer.phar

#
# Main tasks
#

install:
	make composer-install


#
# Librairies
#
composer-install:
	cd ./bin/ && curl -s https://getcomposer.org/installer | php
	$(COMPOSER_BIN) install --no-interaction --no-dev
