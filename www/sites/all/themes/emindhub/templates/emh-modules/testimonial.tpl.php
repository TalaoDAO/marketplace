<section class="emh-module testimonial container">

    <ul class="testimonial-tabs">
        <li class="active"><?php print t('Salariés'); ?></li>
        <li><?php print t('Freelances'); ?></li>
        <li><?php print t('Retraités'); ?></li>
    </ul>

    <ul class="testimonial-slider">
        <li class="testimonial-slider-item">
            <div class="content">

                <div class="logo">
                    <img src="https://dummyimage.com/200x100/000/fff.jpg" alt="" />
                </div>

                <div class="person"><!-- identique à ceux du module person-list -->
                    <div class="picture"><img src="https://dummyimage.com/100/000/fff.jpg" alt="" /></div>
                    <div class="content">
                        <div class="name">Prénom nom</div>
                        <div class="position">Lorem ipsum dolor sit amet.</div>
                    </div>
                </div>

                <blockquote>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore<!--   magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. -->
                </blockquote>

            </div>

        </li>

        <li class="testimonial-slider-item">
            <div class="content">

                <div class="logo">
                    <img src="https://dummyimage.com/200x100/000/fff.jpg" alt="" />
                </div>

                <div class="person"><!-- identique à ceux du module person-list -->
                    <div class="picture"><img src="https://dummyimage.com/100/000/fff.jpg" alt="" /></div>
                    <div class="content">
                        <div class="name">Prénom nom</div>
                        <div class="position">Lorem ipsum dolor sit amet.</div>
                    </div>
                </div>

                <blockquote>
                    Lorem ipsum dolor sit amet,<!--  consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. -->
                </blockquote>

            </div>

        </li>

        <li class="testimonial-slider-item">
            <div class="content">

                <div class="logo">
                    <img src="https://dummyimage.com/200x100/000/fff.jpg" alt="" />
                </div>

                <div class="person"><!-- identique à ceux du module person-list -->
                    <div class="picture"><img src="https://dummyimage.com/100/000/fff.jpg" alt="" /></div>
                    <div class="content">
                        <div class="name">Prénom nom</div>
                        <div class="position">Lorem ipsum dolor sit amet.</div>
                    </div>
                </div>

                <blockquote>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
                </blockquote>

            </div>

        </li>
    </ul>

    <script type="text/javascript">
      /**
       * https://github.com/kenwheeler/slick/
       */
      jQuery('.testimonial-slider').slick({
        infinite: false,
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: false,
        dots: false,
        vertical: true
      });

      window.addEventListener('resize', debounce(function () {
          jQuery('.testimonial-slider.slick-initialized').slick('refresh');
      }, 300));

      jQuery('.testimonial-tabs').on('click', 'li', function (e) {
          var $this = jQuery(this);
          jQuery('.testimonial-slider').slick('slickGoTo', $this.index());
          $this.addClass('active').siblings().removeClass('active');
      });

    </script>
</section>
