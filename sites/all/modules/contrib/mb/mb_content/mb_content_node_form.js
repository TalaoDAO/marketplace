// $Id: mb_content_node_form.js,v 1.1.2.1 2010/11/27 13:30:52 quiptime Exp $

(function ($) {

Drupal.behaviors.mbContentFieldsetSummaries = {
  attach: function (context) {
    // Provide the summary for the content type form.
    $('fieldset#edit-node-buttons', context).drupalSetSummary(function(context) {
      var vals = [];

      // Cancel button.
      var cancel = $("select[name='mb_content_cancel'] option:selected", context).text();
      cancel = Drupal.t('Cancel button') + ": " + cancel;
      vals.push(cancel);

      // Save and continue button.
      var sac = $("select[name='mb_content_sac'] option:selected", context).text();
      sac = Drupal.t('Save and continue button') + ": " + sac;
      vals.push(sac);

      // Create new tab.
      var tabcn = $("input[name='mb_content_tabcn']:checked", context).next('label').text();
      if (tabcn) {
        tabcn = Drupal.t('Create new tab') + ": " + tabcn;
      }
      else {
        tabcn = Drupal.t('Create new tab') + ": " + Drupal.t('No tab');
      }
      vals.push(tabcn);

      return Drupal.checkPlain(vals.join(', '));
    });
  }
};

})(jQuery);
