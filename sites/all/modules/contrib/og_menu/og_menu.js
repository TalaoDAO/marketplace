/**
 * @file
 * Javascript magic. Shows the eligible menu options when switching groups.
 */
(function ($) {

Drupal.ogMenu = Drupal.ogMenu || {};

Drupal.behaviors.ogMenuGroupswitch = {
  attach: function(context) {
    // Initialize variables and form.
    Drupal.ogMenu.originalParent = $('.menu-parent-select').val(); // Get original parent. We'll use this shortly.
    Drupal.ogMenu.selected = []; // Create Variable to hold selected groups
    Drupal.ogMenu.bindEvents(); // Bind events to group audience fields.
    Drupal.ogMenu.setSelected(); // Get all currently selected.
    Drupal.ogMenu.populateParentSelect(); // Populate

    // Make sure the originalParent is set on page load.
    $('.menu-parent-select').val(Drupal.ogMenu.originalParent);
  }
};

/**
 * Bind the needed events to all group audience reference fields.
 */
Drupal.ogMenu.bindEvents = function() {
  var selector = '';
  $.each(Drupal.settings.ogMenu.group_audience_fields, function (index, value) {
    // Only bind events to visible fields.
    if (value.visibility === true) {
      selector = Drupal.ogMenu.buildSelector(index, value.normal, value.cardinality, value.normal_selector);
      Drupal.ogMenu.bindEvent(value.normal, selector);
      if (Drupal.settings.ogMenu.administer_group === true && value.admin !== undefined) {
        selector = Drupal.ogMenu.buildSelector(index, value.admin, value.cardinality, value.admin_selector);
        Drupal.ogMenu.bindEvent(value.admin, selector);
      }
    }
  });
};

/**
 * Helper to bind individual events
 */
Drupal.ogMenu.bindEvent = function(type, selector) {
  // Autocomplete events can be tricky and need specific logic.
  if (type == 'entityreference_autocomplete') {
    // Selecting with the mouse will trigger blur.
    $(selector).blur( function() {
      Drupal.ogMenu.setSelected();
      Drupal.ogMenu.populateParentSelect();
    });
    // Selecting with arrows needs more advanced logic.
    $(selector).keyup( function() {
      if (event.keyCode == 13) { // Enter key.
        Drupal.ogMenu.setSelected();
        Drupal.ogMenu.populateParentSelect();
      }
    });
  }
  // Other fields are simpler.
  else {
    $(selector).change( function() {
      Drupal.ogMenu.setSelected();
      Drupal.ogMenu.populateParentSelect();
    });
  }
};

/**
 * Get selectors of all possible fields.
 */
Drupal.ogMenu.getSelectors = function() {
  var fields =  Drupal.settings.ogMenu.group_audience_fields;
  var selectors = [];
  $.each(fields, function (index, value) {
    selectors.push(Drupal.ogMenu.buildSelector(index, value.normal, value.cardinality, value.normal_selector));
    if (Drupal.settings.ogMenu.administer_group === true  && value.admin !== undefined) {
      selectors.push(Drupal.ogMenu.buildSelector(index, value.admin, value.cardinality, value.admin_selector));
    }
  });
  return selectors;
};

/**
 * Build a selector for a given field.
 */
Drupal.ogMenu.buildSelector = function(name, type, cardinality, base_selector) {
  var selector = '';
  if (type == 'options_buttons') {
    if (cardinality == 1) { // singular value, radio elements.
      selector += 'input[type="radio"][name^="' + base_selector + '"]';
    }
    else { // plural values, checkbox elements.
      selector += 'input[type="checkbox"][name^="' + base_selector + '"]';
    }
  }
  else if (type == 'options_select') {
    selector += 'select[name^="' + base_selector + '"]';
  }
  else if (type == 'entityreference_autocomplete') {
    selector += 'input[type="text"][name^="' + base_selector + '"].form-autocomplete';
  }
  return selector;
};

/**
 * Build a selector for a given field.
 */
Drupal.ogMenu.getGroupRefVal = function(name, type, cardinality, base_selector) {
  var val = [];
  var selector = '';
  if (type == 'options_buttons') {
    if (cardinality == 1) { // singular value, radio elements.
      selector = 'input[type="radio"][name^="' + base_selector + '"]:checked';
      val.push($(selector).val());
    }
    else { // plural values, checkbox elements.
      selector = 'input[type="checkbox"][name^="' + base_selector + '"]:checked';
      $(selector).each(function(i) {
        val.push($(this).val());
      });
    }
  }
  else if (type == 'options_select') {  // Handle Selects
    selector = 'select[name^="' + base_selector + '"]';
    if (cardinality == 1) {
      val.push($(selector).val());
    }
    else {
      $(selector).each(function(i) {
        if ($(this).val() !== null) {
          $.merge(val, $(this).val());
        }
      });
    }
  }
  else if (type == 'entityreference_autocomplete') { // Handle Autocompletes
    selector = 'input[type="text"][name^="' + base_selector + '"].form-autocomplete';
    $(selector).each(function(i) {
      var str = $(this).val();
      // @TODO Replace with regex for multiple items in Autocomplete (Tags style)?
      str = str.substring(str.lastIndexOf('(') + 1, str.lastIndexOf(')'));
      if (str !== '') {
        val.push(str);
      }
    });
  }
  return val;
};

/**
 * Adds all group reference values to selected array.
 */
Drupal.ogMenu.setSelected = function() {
  Drupal.ogMenu.selected = []; // Clear previous values.
  var fields =  Drupal.settings.ogMenu.group_audience_fields;
  $.each(fields, function (index, value) {
    // When dealing with visible fields, get the value from DOM.
    if (value.visibility === true) {
      Drupal.ogMenu.addSelected(
        Drupal.ogMenu.getGroupRefVal(index, value.normal, value.cardinality, value.normal_selector)
      );
      if (Drupal.settings.ogMenu.administer_group === true && value.admin !== undefined) {
        Drupal.ogMenu.addSelected(
          Drupal.ogMenu.getGroupRefVal(index, value.admin, value.cardinality, value.admin_selector)
        );
      }
    }
    // When fields are invisible, a context has been previously set.
    else {
      Drupal.ogMenu.addSelected(value.visibility);
    }
  });
};

/**
 * Helper to add items to Drupal.ogMenu.selected without duplicates
 * Handles arrays as well as single values.
 * Recursive function.
 */
Drupal.ogMenu.addSelected = function(val) {
  if (val instanceof Array) {
    $.each(val, function (index, value) {
      Drupal.ogMenu.addSelected(value);
    });
  }
  else {
    if (val != '_none' && val !== '' && val !== null && val !== undefined) {
      val = parseInt(val, 10);
      if ($.inArray(val, Drupal.ogMenu.selected) == -1) {
        Drupal.ogMenu.selected.push(val);
      }
    }
  }
};


/**
 * Populate the .menu-parent-select select with all available menus and og_menus.
 * This also sets as active the first menu for the first selected group.
 */
Drupal.ogMenu.populateParentSelect = function() {
  // Remove all options from the select to rebuild it.
  $('.menu-parent-select option').remove();

  // Add any non og_menus to the menu-parent-select menu.
  $.each(Drupal.settings.ogMenu.standard_parent_options, function(key, val) {
    $('.menu-parent-select').append($("<option>", {value: key, text: val}));
  });

  var parentToSetActive = Drupal.ogMenu.selected[0];
  var activeIsSet = Drupal.ogMenu.originalParent;

  // Add any og_menus to the menu-parent-select menu
  $.each(Drupal.settings.ogMenu.menus, function(menu_name, gid) {
    if ($.inArray(parseInt(gid, 10), Drupal.ogMenu.selected) >= 0)  {
      $.each(Drupal.settings.ogMenu.parent_options, function(key,val) {
        var parts = key.split(':');

        if (parts[0] === menu_name) {
          if (gid == parentToSetActive && activeIsSet === 0) {
            // Add option to Select and set as selected.
            $('.menu-parent-select').append($("<option>", {value: key, text: val, selected: 'selected'}));
            activeIsSet = 1;
          }
          else if (Drupal.settings.ogMenu.mlid !== 0 && Drupal.settings.ogMenu.mlid == parts[1]) {
            $('.menu-parent-select').append($("<option>", {value: key, text: val + ' [Current Menu Position]', disabled: 'disabled'}));
            // Don't add this item to parent list...
            // Set the parent so we don't lose our place.
            $('.menu-parent-select').val(activeIsSet);
          }
          else {
            // Add option to select.
            $('.menu-parent-select').append($("<option>", {value: key, text: val}));
          }
        }

      });
    }
  });
};

}(jQuery));