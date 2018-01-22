(function ($) {

Drupal.behaviors.emindhub = {
  attach: function (context, settings) {
    var node;
    filter =     { acceptNode: function(node) {
      var className = node.parentNode.className;
      if (className == "request-left" // request main content
        || className == 'views-field views-field-emh-answer' // submissions by all users
        || className == 'section user-submission' // user own submission
      ) return( NodeFilter.FILTER_REJECT );
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
