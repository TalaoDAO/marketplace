(function ($) {

  Drupal.behaviors.exampleModule = {
    attach: function (context, settings) {

      $(document).ready(function(){
        //break apart url to get anchor
        var url = document.location.toString();
        if (url.match('#')) {
          var anchor = '#' + url.split('#')[1];
          $(anchor + " input:not('.form-submit')", context).addClass('error');

          /* this waits until all of the other jQuery has loaded, e.g., vertical tabs */
          $(window).load(function(){ 
            $('html, body', context).animate({ scrollTop: $(anchor).offset().top }, 2000);
          });
        }
      });

    }
  };

})(jQuery);