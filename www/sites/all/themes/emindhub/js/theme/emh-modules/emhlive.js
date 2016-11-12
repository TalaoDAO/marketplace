Drupal.behaviors.expertise = {
    attach: function (context, settings) {
        jQuery('.emhlive-slider', context).once().each(function () {
            var $slider = jQuery(this);

            $slider.slick({
                infinite: false,
                slidesToShow: 3,
                slidesToScroll: 1,
                appendArrows: $slider.siblings('.emhlive-arrows'),
                dots: true,
                appendDots: $slider.siblings('.emh-dots.above'),
                responsive: [{
                    breakpoint: 992,
                    settings: {
                        slidesToShow: 2
                        // appendDots: '.emhlive-dots.below',
                    }
                }, {
                    breakpoint: 600,
                    settings: {
                        slidesToShow: 1,
                        appendDots: $slider.siblings('.emh-dots.below')
                    }
                }]
            });
        });
    }
};
