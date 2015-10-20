/**
 * @file
 *   Testing a demo of Drupal. The script will log in and check for various
 *   features in Drupal core. This demo was inspired by a similar script for
 *   a Wordpress site. The original script was written by Henrique Vicente.
 *
 * @see https://github.com/henvic/phantom-casper-simple-talk/blob/master/wordpress.js
 */


// Config & environment
var config = {
  //'host': 'http://localhost/emindhub.com/www/',
  'host': 'http://gitemindhub/dev-emindhub/',
};


// Load plugins
var fs = require( 'fs' );
    phantomcss = require( fs.absolute( fs.workingDirectory + '/node_modules/phantomcss/phantomcss.js' ) );


// Responsive viewports
var screenshotNow = new Date(),
    screenshotDateTime = screenshotNow.getFullYear() + pad(screenshotNow.getMonth() + 1) + pad(screenshotNow.getDate()) + '-' + pad(screenshotNow.getHours()) + pad(screenshotNow.getMinutes()) + pad(screenshotNow.getSeconds()),
    viewports = [
      {
        'name': 'smartphone-portrait',
        'viewport': { width: 320, height: 480 }
      },
      {
        'name': 'smartphone-landscape',
        'viewport': { width: 480, height: 320 }
      },
      {
        'name': 'tablet-portrait',
        'viewport': { width: 768, height: 1024 }
      },
      {
        'name': 'tablet-landscape',
        'viewport': { width: 1024, height: 768 }
      },
      {
        'name': 'desktop-standard',
        'viewport': { width: 1280, height: 1024 }
      }
    ];

// Anonymous
var anonymousURLs = [
  config.host,                        // Homepage
  config.host + 'our-services',       // Our services
  config.host + 'fields-of-expertise',// Field of expertise
  config.host + 'about-us',           // About us
  config.host + 'expert/register',    // Expert registration
  config.host + 'business/register',  // Business registration
];

var profiles = [
  {
    'name': 'Anonymous',
    'urls': [
      config.host,                        // Homepage
      config.host + 'our-services',       // Our services
      config.host + 'about-us',           // About us
      config.host + 'expert/register',    // Expert registration
      config.host + 'business/register',  // Business registration
    ],
  },
  {
    'name': 'Expert',
    'login': { 'name': 'expert0', 'pass': 'expert0' },
    'urls': [
      config.host,                            // Homepage
      config.host + 'user/2/drafts',          // My drafts
      config.host + 'my-responses',           // My responses
      config.host + 'user',                   // My public profile
      config.host + 'user/2/edit',            // My account
      config.host + 'messages',               // Messages
      config.host + 'my-selections',          // My selections
    ],
  },
  {
    'name': 'Business',
    'login': { 'name': 'business1', 'pass': 'business1' },
    'urls': [
      config.host,                            // Homepage
      config.host + 'user/4/drafts',          // My drafts
      config.host + 'my-responses',           // My responses
      config.host + 'user',                   // My public profile
      config.host + 'user/4/edit',            // My account
      config.host + 'messages',               // Messages
      config.host + 'my-circles',             // My circles
      config.host + 'node/add/question1',
      config.host + 'node/add/challenge',
      config.host + 'node/add/webform',
    ],
  }
];

phantomcss.init( {
  rebase: casper.cli.get( "rebase" ),
  casper: casper,
  libraryRoot: fs.absolute( fs.workingDirectory + '/node_modules/phantomcss' ),
  screenshotRoot: fs.absolute( fs.workingDirectory + '/screenshots' ),
  failedComparisonsRoot: fs.absolute( fs.workingDirectory + '/failures' ),
  comparisonResultRoot: fs.absolute( fs.workingDirectory + '/results' ),
  addLabelToFailedImage: false,

  // Resemble.js overrides
  outputSettings: {
    largeImageThreshold: 0 /*default : 1200px*/
  }
});


casper.test.begin('Testing roles environnement', function suite(test) {

  casper.start( config.host, function() {

    casper.each(profiles, function( casper, profile ) {

      casper.then(function() {
        casper.thenOpen(config.host + 'user/logout', function() {
          casper.test.comment( 'Logging out... just in case' );
        });
      });

      casper.then(function() {
        casper.thenOpen(config.host, function() {
          casper.test.comment( 'Going back to homepage... just in case' );
        });
      });

      // BEGIN User profile
      casper.then(function() {

        casper.test.comment( 'The current user profile is ' + profile.name );

        if ( profile.name === 'Anonymous' ) {

          casper.then(function() {
            casper.test.assertExists('body.not-logged-in', 'Drupal class for not logged-in users was found.');
          });

        } else {

          // Login
          casper.then(function() {
            casper.fill('form#user-login-form', profile.login, true);
            casper.test.comment( 'Logging in...' );
          });

          // Confirm authentification
          casper.then(function() {
            casper.test.assertHttpStatus(200, "Authentication successful");
            casper.test.assertExists('body.logged-in', 'Drupal class for logged-in users was found.');
          });

        }

      }); // END enter user profile

      // Regular screenshots
      casper.then(function() {

        casper.each(profile.urls, function(self, link) {

          self.thenOpen(link, function() {

            casper.test.comment( 'This is the location "' + this.getTitle() + '" (' + this.getCurrentUrl() + ')' );

            casper.each(viewports, function(casper, viewport) {

              // Body
              casper.then(function() {
                this.viewport(viewport.viewport.width, viewport.viewport.height);
                casper.test.comment( 'Taking a screenshot for ' + viewport.name + ' (' + viewport.viewport.width + 'x' + viewport.viewport.height + ')' );
                phantomcss.screenshot( 'body', profile.name + '_' + this.getTitle() + '_' + viewport.name + '-' + viewport.viewport.width + 'x' + viewport.viewport.height );
              });

            }); // END each viewports

          });

        }); // END each profile urls

      });

    }); // END each profiles

  }); // END start

  casper.then(function now_check_the_screenshots() {
    phantomcss.compareAll();
  });

  casper.run(function () {
    console.log( '\nTHE END.' );
    casper.test.done();
  });

});


function pad(number) {
  var r = String(number);
  if ( r.length === 1 ) {
    r = '0' + r;
  }
  return r;
}
