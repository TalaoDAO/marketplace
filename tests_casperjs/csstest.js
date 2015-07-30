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
      config.host,
      config.host + 'user/2/drafts',
      config.host + 'content/my-responses-0',
      config.host + 'user',
      config.host + 'user/2/edit',
      config.host + 'messages',
      config.host + 'my-selections',
    ],
  },
  {
    'name': 'Business',
    'login': { 'name': 'business1', 'pass': 'business1' },
    'urls': [
      config.host,
      config.host + 'user/4/drafts',
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

// var nodeContents = {
//   'title': 'Hello, World!',
//   'body[und][0][value]': 'This content was added by CasperJS!'
// };

// TODO
// var screenshotName = profiles.profile.name + '_' + this.getTitle() + '_' + viewport.name + '-' + viewport.viewport.width + 'x' + viewport.viewport.height;

phantomcss.init( {
  rebase: casper.cli.get( "rebase" ),
  casper: casper,
  libraryRoot: fs.absolute( fs.workingDirectory + '/node_modules/phantomcss' ),
  screenshotRoot: fs.absolute( fs.workingDirectory + '/screenshots' ),
  failedComparisonsRoot: fs.absolute( fs.workingDirectory + '/failures' ),
  comparisonResultRoot: '/results',
  addLabelToFailedImage: false,
} );

// IT'S WORKING !
// casper.test.begin('Testing Anonymous environnement', function suite(test) {
//
//   casper.start().each(anonymousURLs, function(self, link) {
//     self.thenOpen(link, function() {
//       console.log('Current location is "' + this.getTitle() + '" (' + this.getCurrentUrl() + ')');
//       casper.each(viewports, function(casper, viewport) {
//         this.then(function() {
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
//     this.test.done();
//   });
//
// });


casper.test.begin('Testing roles environnement', function suite(test) {

  casper.start( config.host );

  casper.then().each(profiles, function() {

    if (profiles.profile.name !== 'anonymous') {
      // casper.then(function() {
        casper.fill('form#user-login-form', profiles.profile.login.name, true);
        this.test.comment('Logging in...');
      // });

      // casper.then(function() {
        this.test.assertHttpStatus(200, "Authentication successful");
        this.test.assertExists('body.logged-in', 'Drupal class for logged-in users was found.');
        phantomcss.screenshot('body', 'Expert Homepage Body');
      // });
    });

    this.then().each(urls, function(self, link) {
      self.thenOpen(link, function() {
        console.log('Current location is "' + this.getTitle() + '" (' + this.getCurrentUrl() + ')');
        casper.each(viewports, function(casper, viewport) {
          this.then(function() {
            this.viewport(viewport.viewport.width, viewport.viewport.height);
            console.log('Screenshot for ' + viewport.name + ' (' + viewport.viewport.width + 'x' + viewport.viewport.height + ')');
            phantomcss.screenshot( 'body', profiles.profile.name + '_' + this.getTitle() + '_' + viewport.name + '-' + viewport.viewport.width + 'x' + viewport.viewport.height );
          });
        });
      });
    });

    this.thenOpen(config.host + 'user/logout', function() {  });

  });

  casper.then( function now_check_the_screenshots() {
    phantomcss.compareAll();
  } );

  casper.run(function () {
    console.log( '\nTHE END.' );
    this.test.done();
  });

  // casper.start(config.host, function() {
  //   casper.fill('form#user-login-form', profiles.profile.expert.login, true);
  //   this.test.comment('Logging in...');
  // });
  //
  // casper.then(function() {
  //   this.test.assertHttpStatus(200, "Authentication successful");
  //   this.test.assertExists('body.logged-in', 'Drupal class for logged-in users was found.');
  //   phantomcss.screenshot('body', 'Expert Homepage Body');
  // });

  // casper.thenOpen(config.host + 'admin/help', function() {
  //   phantomcss.screenshot('body', 'Expert Homepage Body');
  // });

  // casper.thenOpen(config.host + 'admin/help').waitForText('Help',
  //   function then() {
  //     this.test.assertTextExists('Help topics', 'Help topics');
  //     this.test.assertDoesntExist('#user-login', 'Login form not present on handbook page');
  //   },
  //   function timeout() {
  //     this.test.assert(false, 'Loaded Online Help for administrator.');
  //   }
  // );

  // casper.thenOpen(config.host + 'user/logout', function() {  });
  //
  // casper.then( function now_check_the_screenshots() {
  //   phantomcss.compareAll();
  // } );
  //
  // casper.run(function () {
  //   console.log( '\nTHE END.' );
  //   this.test.done();
  // });

});


function pad(number) {
  var r = String(number);
  if ( r.length === 1 ) {
    r = '0' + r;
  }
  return r;
}
