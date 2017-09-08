module.exports = function(casper, scenario, vp) {
//  casper.thenOpen(scenario.base_url+'/user/logout', function(){  });
  casper.thenOpen(scenario.base_url+'/user/login', function(){
     if (this.exists('form#user-login-form')) {
       this.fill('form#user-login-form',{
          'name': 'ybabel',
          'pass': 'ybabel'
       }, true);
       console.log('logged ybabel');
     } else {
       if (this.exists('#system-user-menu') )
         console.log('=============== Already logged as '+this.fetchText('li#tour-profile > span'));
       else
         console.log('******* WARNING could not log ybabel');
     }
  });
  casper.waitForSelector('li#tour-profile > span',
    function pass () {  },
    function fail () {
        console.log("******** ERROR : did not found log box");
    },
    20000
  );
};
