// $Id: comment_publish.js,v 1.1.2.2.2.1 2010/10/13 14:56:40 elliottf Exp $

/**
 * @file
 * 
 * JavaScript for changing comment states with AJAX
 *
 * @author: Elliott Foster
 * @copyright: NewMBC 2010
 */

(function($) {
Drupal.behaviors.comment_publish = {
  attach: function(context, settings) {
    $('.comment-publish-link:not(comment-publish-link-processed)', context).addClass('comment-publish-link-processed').click(function() {
      var class_ary = this.id.split('_');
      var nid = '';
      var cid = '';
      nid = class_ary[1];
      cid = class_ary[2];
      format = class_ary[3];
      reverse = class_ary[4];

      $(this).after(
        '<div id="comment-publish-working_' + nid + '_' + cid + '_' + format + '_' + reverse + '" class="ajax-progress ajax-progress-throbber"><div class="throbber">&nbsp;</div></div>'
      );

      var url = Drupal.settings.basePath + 'comment_publish/js/' + nid + '/' + cid + '/' + format + '/' + reverse;
      $.getJSON(
        url,
        function(data) {
          $('#comment-publish-working_' + nid + '_' + cid + '_' + format + '_' + reverse).empty();
          $('#comment-publish-link_' + nid + '_' + cid + '_' + format + '_' + reverse).html(data.data.format);
        }
      );
      return false; // prevent nav
    });
  }
}
})(jQuery);
