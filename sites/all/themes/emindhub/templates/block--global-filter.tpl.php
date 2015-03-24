<?php if ($content): ?>
    <?php print $content; ?>
<?php endif;?>

<script type='text/javascript'>
(function ($) {
var global_filter   = $('#global-filter-1');
var all_checkbox    = global_filter.find('#edit-field-domaine-'); // all checkbox input
var checkboxes;
all_checkbox.change(function () {
  if($(this).is(':checked')) {
    checkboxes = global_filter.find('#edit-field-domaine .form-item input:not(:checked)'); // all checkboxes
    checkboxes.attr('checked', true);
  }
});

}(jQuery));
</script>
