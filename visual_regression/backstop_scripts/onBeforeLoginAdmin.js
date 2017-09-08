module.exports = function(casper, scenario, vp) {
//  casper.thenOpen(scenario.base_url+'/user/logout', function(){  });
  casper.thenOpen(scenario.base_url+'/user/login', function(){
     if (this.exists('form#user-login-form')) {
       this.fill('form#user-login-form',{
          'name': 'admin',
          'pass': 'admin'
       }, true);
       console.log('logged admin');
     } else {
       if (this.exists('#admin-menu-wrapper') )
         console.log('=============== Already logged as '+this.fetchText('ul#admin-menu-account li.admin-menu-action.admin-menu-account.expandable > a > strong'));
       else
         console.log('******* WARNING could not log admin');
     }
  });
  casper.waitForSelector('ul#admin-menu-account li.admin-menu-action.admin-menu-account.expandable > a > strong',
    function pass () {  },
    function fail () {
        console.log("******** ERROR : did not found log box");
    },
    20000
  );
};
