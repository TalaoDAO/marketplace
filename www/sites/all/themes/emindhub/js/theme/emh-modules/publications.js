Drupal.behaviors.publications = {
    attach: function (context, settings) {
        jQuery('.publications-slider', context).once().each(function () {
            var $slider = jQuery(this);

            $slider.slick({
                arrows: false,
                dots: true,
                slidesToShow: 5,
                slidesToScroll: 1,
                infinite: false,
                appendDots: $slider.siblings('.emh-dots'),
                responsive: [
                    {
                        breakpoint: 992,
                        settings: {
                            slidesToShow: 4
                        }
                    },
                    {
                        breakpoint: 768,
                        settings: {
                            slidesToShow: 3
                        }
                    },
                    {
                        breakpoint: 600,
                        settings: {
                            slidesToShow: 2
                        }
                    },
                    {
                        breakpoint: 480,
                        settings: {
                            slidesToShow: 1
                        }
                    }
                ]
            });
        });
    }
};
