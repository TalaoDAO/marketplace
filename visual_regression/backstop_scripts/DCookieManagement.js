/**
 * This prototype is used to manage cookies
 * Author: Amir Duran
 */
var DCookieManagement = function(cookiesFileName){
    this.fileManagement = require('fs');
    this.phantomCookies=null;//Original cookies from PhantomJS
    this.cookiesFileName=cookiesFileName;//set cookies file name

    DCookieManagement.prototype.loadCookies = function (cookies){
        this.phantomCookies = cookies;
    };

    DCookieManagement.prototype.saveCookies = function(){
        if(this.phantomCookies != null)
            this.fileManagement.write(this.cookiesFileName, JSON.stringify(this.phantomCookies), "w");
    };
    DCookieManagement.prototype.readCookies = function () {
        if(this.cookieFileExists())
            this.loadCookies(JSON.parse(this.fileManagement.read(this.cookiesFileName)));
    };
    DCookieManagement.prototype.cookieFileExists = function(){
        return this.fileManagement.isFile(this.cookiesFileName);
    };
    DCookieManagement.prototype.getCookies = function(){
        return this.phantomCookies;
    };

    DCookieManagement.prototype.removePreviousCookies = function(){
        this.fileManagement.remove(this.cookiesFileName);
    };

};

exports.create = function(cookiesFileName){
    return new DCookieManagement(cookiesFileName);
};
