/**
 * @file
 *   Testing a demo of Drupal. The script will log in and check for various
 *   features in Drupal core. This demo was inspired by a similar script for
 *   a Wordpress site. The original script was written by Henrique Vicente.
 *
 * @see https://github.com/henvic/phantom-casper-simple-talk/blob/master/wordpress.js
 */
var config = {
  'host': 'http://gitemindhub/qd/drupal/',
  'form': {
    'name': 'admin',
    'pass': 'admin'
  }
};
 
var nodeContents = {
  'title': 'Hello, World!',
  'body[und][0][value]': 'This content was added by CasperJS!'
};

var fs = require( 'fs' );
var path = fs.absolute( fs.workingDirectory + '/PhantomCSS/phantomcss.js' );
var phantomcss = require( path );
 
casper.test.begin('Testing Drupal demo site', function suite(test) {
 
  phantomcss.init( {
    rebase: casper.cli.get( "rebase" ),
    casper: casper,
    libraryRoot: fs.absolute( fs.workingDirectory + '/PhantomCSS' ),
    screenshotRoot: fs.absolute( fs.workingDirectory + '/screenshots' ),
    failedComparisonsRoot: fs.absolute( fs.workingDirectory + '/demo/failures' ),
    addLabelToFailedImage: false,
  } );

  casper.start(config.host, function() { 
    casper.fill('form#user-login-form', config.form, true);
    this.test.comment('Logging in...');
  });
 
  casper.then(function() {
    this.test.assertHttpStatus(200, "Authentication successful");
    this.test.assertExists('body.logged-in', 'Drupal class for logged-in users was found.');
    phantomcss.screenshot('#content', 'screenshot');
  });

  casper.thenOpen(config.host + 'admin/help').waitForText('Help',
    function then() {
      this.test.assertTextExists('Help topics', 'Help topics');
      this.test.assertDoesntExist('#user-login', 'Login form not present on handbook page');
    },
    function timeout() {
      this.test.assert(false, 'Loaded Online Help for administrator.');
    }
  );
 
  casper.thenOpen(config.host + 'user/logout', function() {  });

  casper.then( function now_check_the_screenshots() {
    phantomcss.compareAll();
  } ); 
 
  casper.run(function () {
    console.log( '\nTHE END.' );
    this.test.done();
  });
});

