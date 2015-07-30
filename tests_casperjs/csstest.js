/**
 * @file
 *   Testing a demo of Drupal. The script will log in and check for various
 *   features in Drupal core. This demo was inspired by a similar script for
 *   a Wordpress site. The original script was written by Henrique Vicente.
 *
 * @see https://github.com/henvic/phantom-casper-simple-talk/blob/master/wordpress.js
 */


// Load plugins
var fs = require( 'fs' );
var path = fs.absolute( fs.workingDirectory + '/node_modules/phantomcss/phantomcss.js' );
var phantomcss = require( path );

var config = {
  'host': 'http://localhost/emindhub.com/www/',
};


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
  config.host + 'about-us',           // About us
  config.host + 'expert/register',    // Expert registration
  config.host + 'business/register',  // Business registration
];

var profiles = [
  {
    'name': 'Anonymous',
    // 'login': {  },
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
    'login': { 'name': 'expert1', 'pass': 'expert1' },
    'urls': [
      config.host,                            // Homepage
      config.host + 'user/2/drafts',          // My drafts
      config.host + 'content/my-responses-0', // My responses
      config.host + 'user',
      config.host + 'user/2/edit',
      config.host + 'messages',
      config.host + 'my-selections',
    ],
    // 'areas': [
    //   'name': 'Burger menu',
    //   'selector':
    // ],
  },
  {
    'name': 'Business',
    'login': { 'name': 'business1', 'pass': 'business1' },
    'urls': [
      config.host,                        // Homepage
      config.host + 'user/4/drafts',      // My drafts
      config.host + 'content/my-responses-0',
      config.host + 'user',
      config.host + 'user/4/edit',
      config.host + 'messages',
      config.host + 'my-circles',
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
} );

// IT'S WORKING !
// casper.test.begin('Testing Anonymous environnement', function suite(test) {
//
//   casper.start().each(anonymousURLs, function(self, link) {
//     self.thenOpen(link, function() {
//       console.log('Current location is "' + this.getTitle() + '" (' + this.getCurrentUrl() + ')');
//       casper.each(viewports, function(casper, viewport) {
//         casper.then(function() {
//           this.viewport(viewport.viewport.width, viewport.viewport.height);
//           console.log('Screenshot for ' + viewport.name + ' (' + viewport.viewport.width + 'x' + viewport.viewport.height + ')');
//           phantomcss.screenshot( 'body', profiles.profile.name + '_' + this.getTitle() + '_' + viewport.name + '-' + viewport.viewport.width + 'x' + viewport.viewport.height );
//         });
//       });
//     });
//   });
//
//   casper.then( function now_check_the_screenshots() {
//     phantomcss.compareAll();
//   } );
//
//   casper.run(function () {
//     console.log( '\nTHE END.' );
//     casper.test.done();
//   });
//
// });


casper.test.begin('Testing roles environnement', function suite(test) {

  casper.start( config.host, function() {

    casper.each(profiles, function( casper, profile ) {

      casper.then( function() {

        casper.test.comment( 'The current profile is ' + profile.name );

        casper.then(function() {
          casper.thenOpen(config.host + 'user/logout', function() {
            casper.test.comment( 'Logging out... just in case' );
          });
        });

        if ( profile.name === 'Anonymous' ) {

          casper.then(function() {
            casper.test.assertExists('body.not-logged-in', 'Drupal class for not logged-in users was found.');
          });

        } else {

          casper.thenOpen(config.host, function() {
            casper.test.comment( 'Going back to homepage... just in case' );
            casper.fill('form#user-login-form', profile.login, true);
            casper.test.comment( 'Logging in...' );
          });

          casper.then(function() {
            casper.test.assertHttpStatus(200, "Authentication successful");
            casper.test.assertExists('body.logged-in', 'Drupal class for logged-in users was found.');
          });

          // Burger menu
          casper.then( function () {
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
          } );

          casper.then( function () {
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
          } );

        }

        casper.then(function() {

          casper.each(profile.urls, function(self, link) {

            self.thenOpen(link, function() {

              casper.test.comment( 'This is the location "' + this.getTitle() + '" (' + this.getCurrentUrl() + ')' );

              casper.each(viewports, function(casper, viewport) {

                casper.then(function() {

                  this.viewport(viewport.viewport.width, viewport.viewport.height);
                  casper.test.comment( 'Taking a screenshot for ' + viewport.name + ' (' + viewport.viewport.width + 'x' + viewport.viewport.height + ')' );
                  phantomcss.screenshot( 'body', profile.name + '_' + this.getTitle() + '_' + viewport.name + '-' + viewport.viewport.width + 'x' + viewport.viewport.height );

                });

              }); // END each viewports

            });

          }); // END each profile urls

        });

      });

    }); // END each profiles

  }); // END start

  casper.then( function now_check_the_screenshots() {
    phantomcss.compareAll();
  } );

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
