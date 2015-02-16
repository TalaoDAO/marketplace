(function($){


var storage = {
  hasStorage: window.localStorage ? true : false,
  curFile: '',
  setCursor: function(pos) {
    if (!this.hasStorage)
      return;
    localStorage.livecss_row = pos.row + 1;
    localStorage.livecss_column = pos.column;
  },
  getCursor: function(pos) {
    if (!this.hasStorage)
      return {row: 0, column: 0};
    
    return {
      row: localStorage.livecss_row || 0,
      column: localStorage.livecss_column || 0
    };
  },
  setFile: function(file) {
    if (!this.hasStorage)
      return;
    
    if (localStorage.livecss_file == file)
      return;
    
    localStorage.livecss_file = file;
    localStorage.livecss_row = 0;
    localStorage.livecss_column = 0;
  },
  getFile: function() {
    if (!this.hasStorage)
      return '';
    else
      return localStorage.livecss_file;
  }
};
$(document).ready(function() {
  storage.hasStorage = storage.hasStorage && Drupal.settings.live_css.storage;
});


//main css styler management object
window.styler = {
    html: "<div class='controls'><select class='stylelist' /><div class='save'>Save</div><div class='close'>Close</div><div class='dock'>&#x2B07;</div><div class='clear:both'></div></div>",
    styleObjs: {},
    sList: [],
    init: function(){
        
        //create ui
        $('#csidebar').append(this.html);
        
        var self = this;
        $('#csidebar .stylelist').change(function(){
            self.selectStyle($(this).val(), function(css){
                editor.setText(css);
            });
            storage.setFile($(this).val());
        });
        $('#csidebar .save').click(function(){
            $(this).html('...');
            self.saveCSS(); 
        });
        $('#csidebar .close').click(function(){
            sidebar.remove();
        });
        
        $('#csidebar .dock').html((sidebar.dock == 'right') ? '&#x2B07;' : '&#x2B06;');
        
        $('#csidebar .dock').click(function() {
          sidebar.dock = sidebar.dock == 'right' ? 'bottom' : 'right';
          sidebar.dock = sidebar.dock;
          sidebar.remove();
          sidebar.show();
          $('#csstab').css('display', 'none');
          styler.init();
        });
        
        
        this.loadStyleSheets();
        
        function refresh(styleObj, css) {
          styleObj.setStyle(css);
        }
        
        //check if storage file is in our list
        
        
        self.selectStyle($('#csidebar .stylelist').val(), function(css){
            //create the editor
            editor.init({
                css: css,
                change: function(){
                  if(self.styleObjs[self.curStyle] != null)
                    refresh(self.styleObjs[self.curStyle], editor.getText());
                },
                setCursor: function(pos) {
                  storage.setCursor(pos); 
                },
                startPos: storage.getCursor()
            });
        });
        
        

    },
    loadStyleSheets: function(){
        var addItem = function(item){
            //remove query string
            var title = item.split('?')[0];    
            //remove http
            title = title.replace(/http:\/\//, '');
        
            //normalise path to base url
            var parts = title.split('/');
            title = '';
            var rootIndex = Drupal.settings.basePath.split('/').length - 1;
            for(var i = rootIndex; i < parts.length; i++){
                title = title + parts[i] + '/';
            }
            title = title.substr(0, title.length - 1);
            
            //limit to just theme css if necessary
            if(Drupal.settings.live_css.hidemodules){
                if(!title.match(/sites\/[A-Za-z0-9.]+\/themes\//))
                    return;
            }
            
            //ignore google fonts
            //nb this should be generalised to ignore all external styles as they are not editable
            if (title.match(/googleapis/))
              return;
            
            //only enable less stylesheets if less is enabled
            if (!Drupal.settings.live_css.less)
              if (title.match(/\.less/))
                return;
            
            //item = item.replace(/http:\/\/.*/i, '');
            if (item == storage.getFile())
              $('#csidebar .stylelist').append('<option selected="selected" value="' + item + '">' + title + '</option>');
            else
              $('#csidebar .stylelist').append('<option value="' + item + '">' + title + '</option>');
        }
        if(this.sList.length == 0){
            var self = this;
            
            //add links
            $('link').each(function(){
                if(this.type == 'text/css' || this.rel == 'stylesheet'){
                    addItem(this.href);
                    self.sList.push(this.href);
                }
                
            });
            //add styles
            $('style').each(function(){
                var styles = $(this).html().match(/@import url\(['"](.*)['"]\)/gi);
                if (styles)
                  for (var i = 0; i < styles.length; i++) {
                      var item = styles[i].substring(13, styles[i].length - 2);
                      addItem(item);
                      self.sList.push(item);
                  }
            });
        }
        else{
            for(var i = 0; i < this.sList.length; i++)
                addItem(this.sList[i]);
        }
    },
    saveCSS: function(){
      $('#csidebar .save').html('...');
        var css = editor.getText();
        var href = this.curStyle;
        //post css up
        $.ajax({
            type: 'POST',
            url: Drupal.settings.live_css.savepath,
            data: {
                css: css,
                href: this.curStyle
            },
            dataType: "json",
            success: function(data){
                if(data.result == 'success'){
                    $('#csidebar .save').html('Save');
                }
                else{
                    alert(data.msg);
                    $('#csidebar .save').html('Save');
                }
            },
            error: function(data){
              var msg = data.msg ? data.msg : data;
              if(msg){
                alert(msg);
                $('#csidebar .save').html('Save');
              }
            }
        });
    },
    selectStyle: function(href, complete){
        //update selected
        this.curStyle = href;
        if(this.styleObjs[href] == null){
          
          if (!!window.less && href.match(/\.less/i)) {
            //remove the less styles
            var parts = href.split('/');
            var lessId = [];
            for (var i = 3; i < parts.length; i++)
              lessId.push(parts[i]);
            
            lessId = lessId.join('-');
            lessId = 'less:' + lessId.substring(0, lessId.length - 5);
            $('style[id="' + lessId + '"]').remove();
            
            //store the less code
          }
          
          this.styleObjs[href] = new style(href, complete);
        }
        else{
            complete(this.styleObjs[href].getStyle());
        }
    }
};

//sidebar ui setup
window.sidebar = {
    html: "<div id='csidebar'></div>",
    dock: 'right',
    init: function(){
        //edit button
        var edittab = $("<div id='csstab'><div class='box'>Edit CSS</div></div>");
        //add tab to open
        $(document.body).append(edittab);
        
        var self = this;
        
        edittab.click(function(){
            self.show();    
            edittab.css('display', 'none');
            styler.init();
        });
    },
    show: function(){
        
        $(document.body).parent().append(this.html);
        var self = this;
        
        //disable typical scrollbars
        $(document.body).parent().css('overflow', 'hidden');
        
        $(document.body).css({
            position: 'relative',
            overflow: 'scroll',
            'min-width': 0
        });
        
        $('#csidebar').addClass(sidebar.dock);

        //hide admin menu
        if($('#toolbar, #admin-menu').length > 0 && Drupal.settings.live_css.hideadmin == 1){
            $('#toolbar, #admin-menu').css('display', 'none');
            $(document.body).removeClass('toolbar admin-menu');
            if(Drupal.settings.live_css.menumargin == 1) {
              $(document.body).css('margin-top', '');
            }
        }
        
        var size = function(){
            h = $(window).height();
            w = $(window).width();
            
            
            if (sidebar.dock == 'right') {
              //set the body size
              $(document.body).css('width', w - 500);
              $(document.body).css('height', h - parseInt($(document.body).css('paddingTop')) - parseInt($(document.body).css('marginTop')));
              
              //set the sidebar size
              $('#csidebar').css('height', h);
              
              //editor size
              editor.height(h);
              editor.width(494);
            }
            else if (sidebar.dock == 'bottom') {
              $(document.body).css('width', w - parseInt($(document.body).css('paddingLeft')) - parseInt($(document.body).css('marginTop')));
              $(document.body).css('height', h - 300);
              
              $('#csidebar').css('width', w);
              
              //editor size
              editor.height(300);
              editor.width(w - 6);
            }
        };
        $(window).resize(size);
        size();
    },
    remove: function(){
        $('#csidebar').remove();
        $(document.body).parent().css('overflow', 'auto');
        $(document.body).css({
            position: 'static',
            overflow: 'visible',
            width: 'auto',
            height: 'auto'
        });
        
        $(window).unbind('resize');
        
        $('#csstab').css('display', 'block');
        
        // put the admin_menu back
        if($('#toolbar, #admin-menu').length > 0){
            $('#toolbar, #admin-menu').css('display', 'block');
            $(document.body).addClass('toolbar admin-menu');
            if(Drupal.settings.live_css.menumargin == 1) {
              $(document.body).css('margin-top', '29px');
            }
        }
    }
};

//class for generating stylesheet hooks from a style url

var urlRegEx = /@import\s*("([^"]*)"|'([^']*)')|url\s*\(\s*(\s*"([^"]*)"|'([^']*)'|[^\)]*\s*)\s*\)/ig;

window.style = function(href, complete){
    this.href = href;
    var self = this;
    
    if (!!window.less) {
      if (window.style.lessParser == undefined) {
        /*options = {
          optimization: ...,
          paths: [],
          mime: ...
        }*/
        window.style.lessParser = new less.Parser();
      }
    }
    var hideLess = function(href) {
      var parts = href.split('/');
      var idStr = '';
      for (var i = 3; i < parts.length - 1; i++)
        idStr += parts[i] + '-';
      
      idStr += parts[parts.length - 1].split('.')[0];
      idStr = 'less:' + idStr;
      
      var lessEl = $('style[id="' + idStr + '"]');
      
      lessEl.remove();
    }
    
    //given an href, attach the style and return the getter and setter
    
    //full uri conversion for css asset loading
    this.fullUri = function(css){
        var href = self.href;
        var parts = href.split('/');
        var baseURI = [];
        var dots = '';
        while(parts.pop()){
            baseURI.push(parts.join('/'));

            var result;
            while (result = urlRegEx.exec(css)) {
              url = result[3] || result[2] || result[5] || result[6] || result[4];
              
              if (dots.length ? url.substr(0, dots.length) == dots : url.substr(0, 1) != '/') {
                var quoteLen = result[5] || result[6] ? 1 : 0;
                var newUrl = parts.join('/') + '/' + url.substr(dots.length);
                css = css.substr(0, urlRegEx.lastIndex - url.length - quoteLen - 1) + newUrl + css.substr(urlRegEx.lastIndex - quoteLen - 1);
                urlRegEx.lastIndex = urlRegEx.lastIndex + (newUrl.length - url.length);
              }
            }

            dots += '../';
        }
        return css;
    }
    
    //short uri backwards conversion for css asset loading
    this.shortUri = function(css){
        var href = self.href;
        var parts = href.split('/');
        var baseURI = [];
        var dots = '';
        while(parts.pop()){
            baseURI.push(parts.join('/'));

            var result;
            while (result = urlRegEx.exec(css)) {
              url = result[3] || result[2] || result[5] || result[6] || result[4];

              var partPrefix = parts.join('/') + '/';

              if (url.substr(0, partPrefix.length) == partPrefix) {
                var quoteLen = result[5] || result[6] ? 1 : 0;
                var newUrl = dots + url.substr(partPrefix.length);
                css = css.substr(0, urlRegEx.lastIndex - url.length - quoteLen - 1) + newUrl + css.substr(urlRegEx.lastIndex - quoteLen - 1);
                urlRegEx.lastIndex = urlRegEx.lastIndex + (newUrl.length - url.length);
              }
            }

            css = css.replace(new RegExp('url\\(' + parts.join('/') + '/', 'gi'), 'url(' + dots);
            dots += '../';
        }
        return css;
    }
    
    //check the links and styles
    $('link, style').each(function(){
        var element = this;
        
        //for link elements
        if(this.href == href){
            //insert this new stylesheet after the link element
            self.link = $("<style type='text/css'/>");
            self.link.type = "text/css";
            $(this).after(self.link);
            
            //load the stylesheet data and insert it into the new style element
            $.get(href, function(data){
                self.setStyle(data);
                complete(data);
            });
            
            self.setStyle = function(css){
              
                if (!!window.style.lessParser && this.href.match(/\.less/i)) {
                  hideLess(this.href);
                  this.less = css;
                  try {
                    window.style.lessParser.parse(css, function(e, tree) {
                      css = tree.toCSS();
                    });
                  }
                  catch (e) {}
                }
              
                self.link.html(self.fullUri(css));
            };
            self.getStyle = function(){
                if (this.href.match(/\.less$/i) && this.less != undefined)
                  return this.less;
                else
                  return self.shortUri(self.link.html());
            };
            
            //leave the loop
            return false;
        }
        
        //for style elements
        var html = $(this).html();
        if(html.indexOf(href) >= 0){
          
            self.setStyle = function(css) {
                var href = self.href;
                href = href.replace(/\./g, '\\.');
                href = href.replace(/\//g, '\\/');
                href = href.replace(/\?/g, '\\?');
                var exp = new RegExp("\\/\\*\\+" + href + "\\*\\/(.|\\n|\\r)*\\/\\*\\-" + href + "\\*\\/");
                
                if (!!window.style.lessParser && this.href.match(/\.less/i)) {
                  hideLess(this.href);
                  this.less = css;
                  try {
                    window.style.lessParser.parse(css, function(e, tree) {
                      css = tree.toCSS();
                    });
                  }
                  catch (e) {}
                }
                
                $(element).html($(element).html().replace(exp, '/*+' + self.href + '*/' + self.fullUri(css) + '/*-' + self.href + '*/'));
            };
            
            self.getStyle = function(){
              if (this.href.match(/\.less/i) && this.less != undefined)
                return this.less;
              
                var href = self.href;
                href = href.replace(/\./g, '\\.');
                href = href.replace(/\//g, '\\/');
                href = href.replace(/\?/g, '\\?');
                var exp = new RegExp("\\/\\*\\+" + href + "\\*\\/(.|\\n|\\r)*\\/\\*\\-" + href + "\\*\\/");
                
                var style = $(element).html().match(exp)[0];
                return self.shortUri(style.substring(self.href.length + 5, style.length - self.href.length - 5));
            };
          
            if(html.indexOf('@import') >= 0){
                var html = $(this).html();
                
                //extract the full import list
                var files = html.match(/@import url\(['"]((.|\n|\r)*?)['"]\);/gi);
                
                //replace the @import codes with comment markers
                $(this).html(html.replace(/@import url\(['"]((.|\n|\r)*?)['"]\);/gi, '/*+$1*//*-$1*/\n\r'));
                
                //download all the import files for replacement into the markers
                $(files).each(function(){
                    var filename = this.substring(13, this.length - 3);
                    $.get(filename, function(data){
                        var href = filename;
                        href = href.replace(/\./g, '\\.');
                        href = href.replace(/\//g, '\\/');
                        href = href.replace(/\?/g, '\\?');
                        
                        var exp = new RegExp("\\/\\*\\+" + href + "\\*\\/(.|\\n|\\r)*\\/\\*\\-" + href + "\\*\\/");
                        $(element).html($(element).html().replace(exp, '/*+' + filename + '*/' + data + '/*-' + filename + '*/'));
                        
                        //run the complete function when we replace the one we wanted
                        if(filename == self.href){
                          complete(data);
                        }
                    });
                });
            }
            else{
              //styles already loaded
              complete(self.getStyle());
            }
            
            return false;
        }
        
        return true;
    });
  
    
};

//bespin editor wrapper class
window.editor = {
    html: "<div id='cedit'></div>",
    startLine: 0,
    startCol: 0,
    editor: null,
    change: null,
    init: function(o){
        $('#csidebar').append(this.html);
        
        $('#cedit').css('height', $(window).height() - ($('#cedit').offset().top - $('#csidebar').offset().top));
        
        var self = this;
        
        $('#cedit').html(o.css);
        
        var editor = ace.edit('cedit');
        var CSSMode = require("ace/mode/css").Mode;
        if(Drupal.settings.live_css.theme)
            editor.setTheme("ace/theme/" + Drupal.settings.live_css.theme);
        editor.getSession().setMode(new CSSMode());
        
        editor.setShowPrintMargin(false);
        editor.setHighlightActiveLine(false);
        editor.getSession().setTabSize(Drupal.settings.live_css.tabsize);
        editor.getSession().setUseSoftTabs(Drupal.settings.live_css.softtabs);
        $('#cedit').css('font-size', Drupal.settings.live_css.fontsize);
        
        
        // Fake-Save, works from the editor and the command line.
        editor.commands.addCommand({
          name: "save",
          bindKey: {
            win: "Ctrl-S",
            mac: "Command-S",
            sender: "editor|cli"
          },
          exec: function() {
            styler.saveCSS();
          }
        });
        
        var row = o.startPos.row;
        var column = o.startPos.column;
        setTimeout(function() {
          editor.gotoLine(row, column);
        }, 100);
        
        //add the change event
        if(o.change)
            editor.getSession().on('change', o.change);
        
        //save cursor position to local storage
        editor.getSession().selection.on('changeCursor', function() {
          var pos = editor.getSession().getSelection().getCursor();
          o.setCursor(pos);
        });
        
        this.editor = editor;
        
        //by setting the width of the second canvas element to the window width, we avoid the flickering when resizing
        //$('#cedit canvas')[1].width = $(window).width();
        //$('#cedit canvas')[1].height = $(window).height();
    },
    width: function(sWidth){
        //set editor width
        $('#cedit').css('width', sWidth);
    },
    height: function(sHeight){
      if (sidebar.dock == 'right')
        $('#cedit').css('height', sHeight - 65);
      else
        $('#cedit').css('height', sHeight - 40);
        //if(this.editor)
        //    this.editor.dimensionsChanged();
    },
    getText: function(){
        return this.editor.getSession().getValue();
    },
    setText: function(css){
        this.editor.getSession().setValue(css);
        //set the line number
        var self = this;
        setTimeout(function(){
            self.editor.gotoLine(0);
        }, 100);
    }
};

$(document).ready(function(){
    sidebar.init();
});

})(jQuery);
