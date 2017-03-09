(function ($) {
  Drupal.behaviors.autodialog = {
    attach: function (context, settings) {
      // Process links
      $('.autodialog', context).once('autodialog', function () {
        Drupal.autodialog.processLink(this);
      });

      // Scroll to dialog top
      if ($(context).closest('.autodialog-content').length) {
        Drupal.autodialog.positioningDialog(context);
      }
    }
  };

  Drupal.ajax.prototype.commands.autodialog = function (ajax, response, status) {
    var options = {
      title: response.title,
      width: 500,
      modal: true,
      closeText: Drupal.t('Close'),
      close: function () {
        $(this).dialog('destroy').remove();
      }
    };
    $.extend(options, response.options);

    // Close previous dialog
    if (options.closeprev) {
      $('.autodialog-content').dialog('close');
    }

    // Create dialog content
    var $dialogContent = $('<div id="' + response.dialog_id + '" class="autodialog-content">' + response.content + '</div>').appendTo('body');

    // Open dialog. Not $dialog.dialog() because it causes problems with inline scripts for jQuery 1.4.
    $('#' + response.dialog_id).dialog(options);

    // Remove focus from first tabbable element
    $dialogContent.closest('.ui-dialog').focus();

    // Close dialog when clicked outside
    $('.ui-widget-overlay:last').click(function (event) {
      if ($(event.target).hasClass('ui-widget-overlay')) {
        $dialogContent.dialog('close');
      }
    });

    Drupal.attachBehaviors($dialogContent);
  }

  Drupal.ajax.prototype.commands.autodialogPositioning = function (ajax, response, status) {
    Drupal.autodialog.positioningDialog('#' + response.dialog_id);
  }

  Drupal.autodialog = Drupal.autodialog || {
    marginTop: 20,

    /**
     * Attach click event to link.
     */
    processLink: function (link) {
      var $link = $(link);
      var linkId = $link.attr('id');
      if (!linkId) {
        linkId = Drupal.autodialog.generateId();
        $link.attr('id', linkId);
      }
      var options = Drupal.autodialog.getOptions(link);

      Drupal.ajax[linkId] = new Drupal.ajax(linkId, link, {
        progress: {type: 'throbber'},
        url: $link.attr('href'),
        event: 'click',
        submit: {
          js: true,
          autodialog_link_id: linkId,
          autodialog_options: JSON.stringify(options)
        },
        beforeSerialize: function (xmlhttprequest, options) {
          options.url = $link.attr('href');
          $('body').addClass('autodialog-loading');
          Drupal.ajax.prototype.beforeSerialize.apply(this, arguments);
        },
        success: function (response, status) {
          $('body').removeClass('autodialog-loading');
          Drupal.ajax.prototype.success.apply(this, arguments);
        },
      });
    },

    /**
     * Generate dialog id.
     */
    generateId: function () {
      var index = 1;
      while (1) {
        var id = 'autodialog-' + index++;
        if ($('#' + id).length == 0) {
          return id;
        }
      }
    },

    /**
     * Return dialog options from data-* attributes.
     */
    getOptions: function (element) {
      var options = {};
      $.each($(element).data(), function (key, value) {
        var matches = key.match(/dialog(.+)/);
        if (matches) {
          var optionKey;

          // For jQuery 1.4.4-1.5
          if (matches[1][0] == '-') {
            optionKey = matches[1].substring(1).replace(/-(.)/g, function (str, match) {
              return match.toUpperCase();
            });
          }
          // For jQuery 1.6+
          else {
            optionKey = matches[1].substring(0, 1).toLowerCase() + matches[1].substring(1);
          }

          options[optionKey] = value;
        }
      });
      return options;
    },

    /**
     * Animated move dialog to new top position.
     */
    animatedMove: function (dialogWidget, top) {
      var $dialogWidget = $(dialogWidget);
      $dialogWidget.stop().animate({top: top}, 300);
    },

    /**
     * Animated positioning dialog to center.
     */
    positioningDialog: function (context) {
      if (Drupal.autodialog.positioningDialogTimeoutId) {
        clearTimeout(Drupal.autodialog.positioningDialogTimeoutId);
      }
      Drupal.autodialog.positioningDialogTimeoutId = setTimeout(function () {
        Drupal.autodialog._positioningDialog(context);
      }, 10);
    },

    /**
     * Animated positioning dialog to center.
     */
    _positioningDialog: function (context) {
      var $dialogWidget = $(context).closest('.autodialog-content').dialog('widget');
      var $dialogParent = Drupal.autodialog.getDialogParent($dialogWidget);
      var dialogWidgetHeight = $dialogWidget.outerHeight();
      var dialogWidgetTop = $dialogWidget.position().top;
      var viewportHeight = $(window).height();
      var dialogParentScrollTop = $dialogParent.scrollTop();
      var dialogTopFromViewport = dialogWidgetTop - dialogParentScrollTop;
      var newDialogWidgetTop;

      if (dialogWidgetHeight < viewportHeight) {
        newDialogWidgetTop = dialogParentScrollTop + ((viewportHeight - dialogWidgetHeight) / 2);
      }
      else if (dialogTopFromViewport >= 0) {
        newDialogWidgetTop = dialogParentScrollTop + Drupal.autodialog.marginTop;
      }

      if (newDialogWidgetTop != undefined && Math.abs(dialogWidgetTop - newDialogWidgetTop) >= Drupal.autodialog.marginTop) {
        Drupal.autodialog.animatedMove($dialogWidget, newDialogWidgetTop);
      }
    },

    /**
     * Return dialog parent element.
     */
    getDialogParent: function (dialogWidget) {
      var $dialogParent = $(dialogWidget).offsetParent();
      if ($dialogParent.is('html')) {
        $dialogParent = $(window);
      }
      return $dialogParent;
    }
  };
})(jQuery);
