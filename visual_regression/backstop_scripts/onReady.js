module.exports = function (casper, scenario, vp) {
  if ( !(casper.exists('.footer-credits') || casper.exists('#main-nav') || casper.exists('#admin-menu-wrapper')) ) 
    console.log('******* WARNING : signature not found on page');
  //casper.evaluate(function () {  });
  //console.log('onReady.js has run for: ', vp.name);
};
