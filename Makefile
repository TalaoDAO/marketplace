project_name = EMindHub

#
# Main tasks
#
install:
	make install-drupal
	make install-behat

install-drupal:
	$(MAKE) -C ./www/ install

install-behat:
	$(MAKE) -C ./bdd/ install
