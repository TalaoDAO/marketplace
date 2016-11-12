Drupal.behaviors.requests = {
    attach: function (context, settings) {
        jQuery('.requests-slider', context).once().each(function () {
            var $slider = jQuery(this);

            var requestsSliderOptions = {
                arrows: false,
                dots: true,
                slidesToShow: 2,
                slidesToScroll: 2,
                infinite: true,
                appendDots: $slider.siblings('.emh-dots'),
                responsive: [
                    {
                        breakpoint: 600,
                        settings: {
                            slidesToShow: 1,
                            slidesToScroll: 1
                        }
                    }
                ]
            };

            /**
             * Debounce postpone execution on event trigger stop
             * then enable slider only if width <= 800
             */
            var checkRequestsSlick = debounce(function () {
                if (document.body.clientWidth > 800) {
                    $slider.find('.row.slick-initialized').slick('unslick');
                } else {
                    $slider.find('.row:not(.slick-initialized)').slick(requestsSliderOptions);
                }
            }, 300);

            checkRequestsSlick();
            window.addEventListener('resize', checkRequestsSlick);
        });
    }
};
