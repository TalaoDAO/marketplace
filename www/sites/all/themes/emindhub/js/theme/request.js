(function ($) {
    $(document).ready(function () {
        makeActive();
        $('input[type="radio"]').on('change', function () {
            makeActive();
        });
    });

    function makeActive () {
        $('input[type="radio"]').each(function () {
            if ($(this).prop('checked')) {
                $(this).closest('.form-type-radio').addClass('active');
            } else {
                $(this).closest('.form-type-radio').removeClass('active');
            }
        });
    }
})(jQuery);
