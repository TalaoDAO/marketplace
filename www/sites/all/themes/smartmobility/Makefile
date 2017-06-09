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

#
# Building apps
#
install-npm:
	npm install

gulp:
	$(GULP_BIN)
