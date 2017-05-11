(function ($) {
    $(document).ready(function () {
        $('.js-affix').affix({
            offset: {
                top: $('.view-query-list').offset().top,
                bottom: ($('.more-link').outerHeight(true) + $('#block-views-news-thread-publications-block').outerHeight(true) + $('footer').outerHeight(true)) + 40
            }
        });
    });
})(jQuery);
