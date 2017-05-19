BOWER_BIN ?= ./node_modules/.bin/bower
GULP_BIN ?= ./node_modules/.bin/gulp

#
# Main tasks
#
init:
	make install

install:
	make install-vendors
	make gulp

deploy:
	make gulp

#
# Librairies
#
install-vendors:
	make install-npm
	# make install-bower

#
# Building apps
#
install-npm:
	npm install

install-bower:
	$(BOWER_BIN) install --allow-root

gulp:
	$(GULP_BIN)
