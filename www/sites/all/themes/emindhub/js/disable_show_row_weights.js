(function ($) {
  // based on http://drupal.stackexchange.com/questions/62662/
  // Copy hideColumns() method
  if (Drupal.tableDrag) {
    var hideColumns = Drupal.tableDrag.prototype.hideColumns;
    Drupal.tableDrag.prototype.hideColumns = function() {
      // Call the original hideColumns() method
      hideColumns.call(this);
      // Remove the 'Show row weights' string
      $('.tabledrag-toggle-weight').text('');
    }

    // Copy showColumns() method
    var showColumns = Drupal.tableDrag.prototype.showColumns;
    Drupal.tableDrag.prototype.showColumns = function () {
      // Call the original showColumns() method
      showColumns.call(this);
      // Remove the 'Hide row weights' string
      $('.tabledrag-toggle-weight').text('');
    }
  }
})(jQuery);
