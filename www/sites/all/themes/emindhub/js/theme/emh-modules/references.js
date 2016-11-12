Drupal.behaviors.references = {
    attach: function (context, settings) {
        jQuery('.references-list', context).once().each(function () {
            var $slider = jQuery(this);

            $slider.slick({
                arrows: false,
                dots: true,
                slidesToShow: 5,
                slidesToScroll: 1,
                infinite: false,
                appendDots: $slider.siblings('emh-dots'),
                responsive: [{
                    breakpoint: 768,
                    settings: {
                        slidesToShow: 2,
                        slidesToScroll: 1
                    }
                }, {
                    breakpoint: 480,
                    settings: {
                        infinite: true,
                        slidesToShow: 1,
                        slidesToScroll: 1
                    }
                }]
            });
        });
    }
};
