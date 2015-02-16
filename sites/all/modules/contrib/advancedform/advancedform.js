(function ($) {
///////////////
  
/**
 * Use a selector to choose which elements get displayed on a page.
 * @author dman dan@coders.co.nz
 */
 
Drupal.behaviors.advancedform = {
  attach: function(context) {
    $('form.advancedform-unfiltered') // to be unobtrusive, we start as normal, then hide.
      .removeClass('advancedform-unfiltered')
      .addClass('advancedform-filtered')
      .css('position', 'relative')
      
    if (Drupal.settings.advancedform.access) {
      $('form.advancedform-filtered').append("<div class='advancedform-toggle' title='Some form elements may be hidden. Switch this form between full and partial detail'>Switch to Advanced</div>")
    }
    $('.advancedform-toggle').click(
      function(){
        if($(this).html() == 'Switch to Advanced') {
          $(this).html('Switch to Filtered');
          var originalBG = $('form').css("background-color"); 
          $('form').removeClass('advancedform-filtered')
            .animate({opacity:.5},300)
            .animate({opacity:1},300)
        }
        else if($(this).html() == 'Switch to Filtered') {
          $('form').addClass('advancedform-filtered')
            .animate({opacity:.5},300)
            .animate({opacity:1},300)
          $(this).html('Switch to Advanced');
        }
      }
    );

    // Also capture any changes on any taxonomy selectors
    // and insert that data into the form top.
    $(".advancedform-filtered .field-type-taxonomy-term-reference select").change(
      function(){
        // remove previous selections
        var previous_selections = $(this).data('advancedform');
        for (selection_id in previous_selections) {
          $('form.advancedform-filtered').removeClass('selected-' + previous_selections[selection_id]);
        }
        // Add selected (and remember them here)
        var selected_values = {}
        $(':selected', this).each(function(i, selected){
          var selected_text = Drupal.advancedform_safe_id($(selected).text());
          selected_values[selected_text] = selected_text;
          $('form.advancedform-filtered').addClass('selected-' + selected_text);
        });
        $(this).data('advancedform', selected_values);
      }
    );
    // Trigger it once to update the current display
    $('.advancedform-filtered .field-type-taxonomy-term-reference select').trigger('change');
  }
}

/**
 * util function
 */
Drupal.advancedform_safe_id = function(string)  {
  var re = new RegExp('[^a-z0-9]', 'gi');
  return string.replace(re, '-').toLowerCase();
}


///////////
})(jQuery);