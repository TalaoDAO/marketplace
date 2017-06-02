/*(function ($) {
    $(document).ready(function () {
      /* Check if we are in safari */
        var isSafari = /^((?!chrome|android).)*safari/i.test(navigator.userAgent);
        if (isSafari) {
            return;
        }

        if ($('.js-affix').length) {
            $('.js-affix').affix({
                offset: {
                    top: $('.view-query-list').offset().top,
                    bottom: ($('.more-link').outerHeight(true) + $('#block-views-news-thread-publications-block').outerHeight(true) + $('footer').outerHeight(true)) + 40
                }
            });
        }
    });
})(jQuery);*/
