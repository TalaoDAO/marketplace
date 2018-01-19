(function ($) {

Drupal.behaviors.emindhub = {
  attach: function (context, settings) {
    var node;
    filter =     { acceptNode: function(node) {
      var className = node.parentNode.className;
      if (className == "request-left" || className == 'content submissions-list' || className == 'section user-submission') return( NodeFilter.FILTER_REJECT );
      return( NodeFilter.FILTER_ACCEPT );
      }
    }

    var walker = document.createTreeWalker(document.body, NodeFilter.SHOW_ELEMENT | NodeFilter.SHOW_TEXT, filter, false);

    while (node = walker.nextNode()) {
      if (node.nodeType == Node.TEXT_NODE) { 
        node.nodeValue = node.nodeValue.replace(/credit/, 'token');
        node.nodeValue = node.nodeValue.replace(/Credit/, 'Token');
        node.nodeValue = node.nodeValue.replace(/crédit/, 'token');
        node.nodeValue = node.nodeValue.replace(/Crédit/, 'Token');
      }
    }
  }
};

}(jQuery));
