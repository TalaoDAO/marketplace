/**
 * @file
 * Provides JavaScript functionality for qforms form builder handling.
 */

(function ($) {

Drupal.behaviors.qforms = {
  attach: function (context) {
    // Bind qfroms behaviors to all qforms elements in form builder.
    $('.qforms-element:not(.qforms-processed)', context).addClass('qforms-processed').each(function () {
      var $this = $(this);

      // If we are in ajax add element event then scroll to this element.
      if ($this.css('opacity') == '0') {
        if ($.scrollTo) {
          $.scrollTo(this, 800, {
            'over': -0.3
          });
        }
      }

      // Hide element weight textfield.
      $this.find('.qforms-element-weight').parent().hide();

      // Element collapsing - open/close.
      $this.find('.qforms-action-collapse').click(function() {
        var action;
        var $this = $(this);

        if($this.hasClass('qforms-form-close')) {
          $this.removeClass('qforms-form-close').addClass('qforms-form-open').attr('title', Drupal.t('Show'));
          action = 'hide';
        }
        else {
          $this.removeClass('qforms-form-open').addClass('qforms-form-close').attr('title', Drupal.t('Close'));
          action = 'show';
        }

        $this.closest('.qforms-element').find('.qforms-element-data').animate({
          opacity: action,
          height: action
        }, 'slow');

        return false;
      });

      // On element title change auto refresh header element title.
      $this.find('.qforms-element-data').find('input.qforms-element-title').keyup(function() {
        var title = $(this).val();
        $this.find('.qforms-element-header').find('.qforms-element-live-title').text(title);
      });
      
    });
  }
}

$('document').ready(function () {

  // Open and close all elements.
  $('#qforms-form-actions a.qforms-form-close').click(function() {
    $("#qforms-elements").find('.qforms-form-open').click();
    return false;
  });
  $('#qforms-form-actions a.qforms-form-open').click(function() {
    $("#qforms-elements").find('.qforms-form-close').click();
    return false;
  });

  // Return select option to 'Add new element...' on change event.
  $('#edit-qforms-add-element').change(function () {
    $(this).val('');
  });

  // Drag&drop support.
  $("#qforms-elements").sortable({
    axis: 'y',
    cursor: 'move',
    forcePlaceholderSize: true,
    handle: '.qforms-action-move',
    opacity: 0.6,
    placeholder: 'ui-state-highlight',
    stop: function(event, ui) {
      $("#qforms-elements").find('.qforms-element').find('.qforms-element-weight').each(function(index, element) {
        $(element).val(index + 1);
      });
    }
  });

  // Sort qform elements just in case they are out of order.
  // Why? For now drag&drop ordering is not using ajax for form rebuilding. It
  // will only change element weight field value. That means that if we do form
  // submission that will fail on validation we will get old order of elements
  // (but weight values will be correct).
  // One way to solve this is to sort elements with jquery, this is faster
  // because we don't need to trigger ajax form rebuilding.
  var $elements = $('#qforms-elements');
  var listElements = $elements.children('.qforms-element').get();
  listElements.sort(function(a, b) {
     return $(a).find('.qforms-element-weight').val() < $(b).find('.qforms-element-weight').val() ? -1 : 1;
  })
  $.each(listElements, function(index, element) {$elements.append(element);});

});

})(jQuery);
