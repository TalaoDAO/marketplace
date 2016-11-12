Drupal.behaviors.testimonials = {
    attach: function (context, settings) {
        /**
         * Manage each slider individualy
         */
        jQuery('.testimonial-slider', context).once().each(function () {
            var $slider = jQuery(this);

            /**
             * Init slider
             */
            $slider.slick({
                infinite: false,
                slidesToShow: 1,
                slidesToScroll: 1,
                arrows: false,
                dots: false,
                vertical: true
            });

            /**
             * Refresh slider on window resize
             */
            window.addEventListener('resize', debounce(function () {
                $slider.slick('refresh');
            }, 300));

            /**
             * Switch slider active item when using tabs
             */
            $slider.siblings('.testimonial-tabs').on('click', 'li', function (e) {
                var $this = jQuery(this);
                $slider.slick('slickGoTo', $this.index());
                $this.addClass('active').siblings().removeClass('active');
            });
        });
    }
};
