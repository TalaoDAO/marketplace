/**
 * @file
 *   Testing visual regressions in emindhub site with phantomcss
 *
 * @see https://github.com/henvic/phantom-casper-simple-talk/blob/master/wordpress.js
 */


// Config & environment
var config = {
  'host': 'http://emh.box.local/',
};


// Load plugins
var fs = require( 'fs' );
    phantomcss = require( fs.absolute( fs.workingDirectory + '/node_modules/phantomcss/phantomcss.js' ) );


// Responsive viewports
var screenshotNow = new Date(),
    screenshotDateTime = screenshotNow.getFullYear() + pad(screenshotNow.getMonth() + 1) + pad(screenshotNow.getDate()) + '-' + pad(screenshotNow.getHours()) + pad(screenshotNow.getMinutes()) + pad(screenshotNow.getSeconds()),
    viewports = [
      /*{
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
      },*/
      {
        'name': 'desktop-standard',
        'viewport': { width: 1280, height: 1024 }
      }
    ];

// Anonymous
var anonymousURLs = [
  config.host,                        // Homepage
  config.host + 'open-requests',       // Our services
  config.host + 'domains',// Field of expertise
  config.host + 'about-us',           // About us
  config.host + 'expert/register',    // Expert registration
  config.host + 'client/register',  // Business registration
];

var profiles = [
  /*{
    'name': 'Anonymous',
    'urls': [
      config.host,                        // Homepage
      config.host + 'open-requests',       // Our services
      config.host + 'domains',       // Our services
      config.host + 'about-us',           // About us
      config.host + 'expert/register',    // Expert registration
      config.host + 'client/register',  // Business registration
    ],
  },*/
  {
    'name': 'Expert',
    'login': { 'name': 'ybabel', 'pass': 'ybabel' },
    'urls': [
      config.host,                            // Homepage
      config.host + 'answers/my',                // My responses
      config.host + 'user',                   // My public profile
      config.host + 'user/3/edit',            // My account
      config.host + 'circles',               // Join circles
      config.host + 'requests/selection',          // My selections
    ],
  },
  {
    'name': 'Business',
    'login': { 'name': 'business1', 'pass': 'business1' },
    'urls': [
      config.host,                            // Homepage
      config.host + 'answers/my',           // My responses
      config.host + 'user',                   // My public profile
      config.host + 'user/4/edit',            // My account
      config.host + 'requests/manage',               // My requests
      config.host + 'circles',             // My circles
      config.host + 'node/add/request',       // Create new request
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

          casper.thenOpen(config.host + 'user');
          casper.waitForText('Log in');
          phantomcss.screenshot( 'body', 'debug1' );
          casper.then(function() {
            casper.fill('form#user-login-form', profile.login, true);
            casper.test.comment( 'Logging in...' );
          });
          phantomcss.screenshot( 'body', 'debug2' );
          // Confirm authentification
          casper.then(function() {
            casper.test.assertHttpStatus(200, "Authentication successful");
            casper.test.assertExists('body.logged-in', 'Drupal class for logged-in users was found.');
          });
          casper.thenOpen(config.host);
          casper.waitForText('Welcome');
          phantomcss.screenshot( 'body', 'debug3' );

        }

      }); // END enter user profile

      /* BEGIN Burger menu : deprecated, burger menu exist only for admin users
      if ( !( profile.name === 'Anonymous' ) ) {

        casper.then(function() {

          casper.then(function () {
            casper.click( '.burger-menu-btn-container' );

            // wait for modal to fade-in
            casper.waitForSelector( '.region.region-burgermenu:not([style*="display: none"])',
              function success() {
                casper.test.comment( 'Hello burger !' );

                casper.each(viewports, function(casper, viewport) {

                  casper.then(function() {

                    this.viewport(viewport.viewport.width, viewport.viewport.height);
                    casper.test.comment( 'Taking a screenshot for ' + viewport.name + ' (' + viewport.viewport.width + 'x' + viewport.viewport.height + ')' );
                    phantomcss.screenshot( '.region.region-burgermenu', profile.name + '_Burger-menu_' + viewport.name + '-' + viewport.viewport.width + 'x' + viewport.viewport.height );

                  });

                }); // END each viewports

              },
              function timeout() {
                casper.test.fail( 'Should see burger menu' );
              }
            );
          });

          casper.then(function () {
            casper.click( '.burgermenu-close-icon' );

            // wait for modal to fade-out
            casper.waitForSelector( '.region.region-burgermenu[style*="display: none"]',
              function success() {
                casper.test.comment( 'Bye bye burger !' );
              },
              function timeout() {
                casper.test.fail( 'Should be able to walk away from the burger menu' );
              }
            );
          });

        });

      } // END Burger menu*/


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
