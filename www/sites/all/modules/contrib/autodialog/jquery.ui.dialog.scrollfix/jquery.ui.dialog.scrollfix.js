(function($) {
  var jQueryUiVersion = $.ui.version.split('.');
  if (!(parseInt(jQueryUiVersion[0]) >= 1 && parseInt(jQueryUiVersion[1]) >= 10 && parseInt(jQueryUiVersion[2]) >= 2)) {
    console.log('jQuery UI version too old. Minumum 1.10.2.');
    return;
  }

  $.widget('ui.dialog', $.ui.dialog, {
    /**
     * Extend _createOverlay().
     */
    _createOverlay: function() {
      this._superApply(arguments);

      if (!this.options.modal) {
        return;
      }

      this.uiDialog.appendTo(this.overlay);

      this._off(this.overlay, 'mousedown');
      this.overlay.addClass('ui-widget-overlay-scrollfix');

      if ($.ui.dialog.overlayInstances == 1) {
        var $body = $('body');
        var windowHasScrollbar = $body.get(0).scrollHeight > $body.height();
        var windowWidth = $(window).width();
        var dialogHeightLessViewport = this.uiDialog.outerHeight() < $(window).height();

        $body.addClass('ui-helper-disable-scrolling');
        if (windowHasScrollbar) {
          if (dialogHeightLessViewport) {
            this.overlay.addClass('ui-helper-vertical-scroll');
          }
          $body.width(windowWidth);
        }

        this._position();
      }
    },

    /**
     * Override _destroyOverlay().
     */
    _destroyOverlay: function() {
      if (!this.options.modal || !this.overlay) {
        return;
      }

      this.uiDialog.unwrap();
      this.overlay = null;

      $.ui.dialog.overlayInstances--;
      if (!$.ui.dialog.overlayInstances) {
        this.document.unbind('focusin.dialog');

        $('body')
          .removeClass('ui-helper-disable-scrolling')
          .removeClass('ui-helper-vertical-scroll')
          .css({
            'top': '',
            'width': ''
          });
      }
    },

    /**
     * Override _moveToTop().
     */
    _moveToTop: function(event, silent) {
      var element = (this.options.modal && this.overlay) ? this.overlay : this.uiDialog;
      var moved = !!element.nextAll(':visible').insertBefore(element).length;
      if (moved && !silent) {
        this._trigger('focus', event);
      }
      return moved;
    },
  });
})(jQuery);
