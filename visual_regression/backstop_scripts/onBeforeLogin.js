module.exports = function (casper, scenario, vp) {
  // Create cookie manager object. Cookies will be saved in file called cookies.txt.
  var cookiesManager = require('./DCookieManagement').create("./backstop_data/cookies/cookies.txt");
  // Cookie file exists, try to read it.
  if (cookiesManager.cookieFileExists()) {
    cookiesManager.readCookies();
    phantom.cookies = cookiesManager.getCookies();
    casper.page.cookies = cookiesManager.getCookies();
    console.log('onBeforeLogin.js has succeeded for '+ vp.name + '.');
  } else
    console.log('onBeforeLogin.js has fail to login for '+ vp.name + '.');
};
