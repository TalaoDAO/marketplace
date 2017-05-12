// Do some initial setup.
jQuery(document).ready(function() {
  var version = Drupal.settings.mixpanel.library_version,
      uid     = Drupal.settings.mixpanel.defaults.uid;

  // Calls Mixpanel functions in a version independent way.
  function wrapper(args) {
    var func = args[0];
    if (version === '1.0') {
      mpq.push(args);
    }
    else {
      mixpanel[func].apply(mixpanel, args.slice(1));
    }
  }

  // Uniquely identify the user.
  if (uid) {
    wrapper(["identify", uid]);
  }

  // Register properties about the user.
  wrapper(["register", Drupal.settings.mixpanel.defaults]);

  // Only supported in version 2!
  if (version === '2.0' && uid) {
    // Super basic support for 'People'.
    mixpanel.people.identify(Drupal.settings.mixpanel.defaults.uid);
    mixpanel.people.set(Drupal.settings.mixpanel.people);
  }
});
