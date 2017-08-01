var casper = require('casper').create({
  pageSettings: {
    loadImages: false,//The script is much faster when this field is set to false
    loadPlugins: false,
    userAgent: 'My User Agent String'
  }
});

var loginUrl = casper.cli.args[0];
if (typeof loginUrl === 'undefined') {
  casper.exit(1);
}

// Create cookie manager object. Cookies will be saved in file called cookies.txt.
var cookiesManager = require('./DCookieManagement').create("./backstop_data/cookies/cookies.txt");
// Cookie file exists, try to read it.
if (cookiesManager.cookieFileExists()){
  // If file exists, nothing to do.
  casper.exit(0);
}

// First step is to open the site and instantiate cookiemanager.
casper.start().thenOpen(loginUrl, function() {
  console.log("Website opened");
});

// Wait to be redirected to the Home page, and then save cookies.
casper.then(function(){
  console.log("Save cookies.");
  cookiesManager.loadCookies(phantom.cookies);
  cookiesManager.saveCookies();
});

casper.run();
