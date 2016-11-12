Drupal.behaviors.expertise = {
    attach: function (context, settings) {
        jQuery('.expertise-slider', context).once().each(function () {
            var $slider = jQuery(this);

            $slider.slick({
                infinite: false,
                arrows: false,
                slidesToShow: 4,
                slidesToScroll: 1,
                dots: true,
                appendDots: $slider.siblings('.emh-dots'),
                responsive: [{
                    breakpoint: 1200,
                    settings: {
                        slidesToShow: 3
                    }
                }, {
                    breakpoint: 992,
                    settings: {
                        slidesToShow: 2
                    }
                }, {
                    breakpoint: 767,
                    settings: {
                        slidesToShow: 2
                    }
                }, {
                    breakpoint: 600,
                    settings: {
                        slidesToShow: 1
                    }
                }]
            });
        });
    }
};
