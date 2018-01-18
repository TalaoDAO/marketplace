(function ($) {

Drupal.behaviors.emindhub = {
  attach: function (context, settings) {
    var node;
    filter =     { acceptNode: function(node) {
      if (node.parentNode.className == "request-left") return( NodeFilter.FILTER_REJECT );
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
