/**
 * @file opencalais.node.js
 *    This file contains all javascript associated with the Node edit screens.
 */
(function ($) {

Drupal.behaviors.opencalaisNodeEdit = {
  attach: function(context) {
  	$('label.suggestion', context).each(function(){
  	  if(!this.opencalais_processed){
  	    this.opencalais_processed = true;
    	  $(this).click(function(e) {
        
      		var tags = $('#' + $(this).attr('for'));
      		var keyword = $(this).text();
      		
      		if($(this).hasClass('suggestion_selected')) {
      			Drupal.opencalais.removeKeyword(tags, keyword);
      			$(this).removeClass('suggestion_selected');
      		}
      		else {
      			Drupal.opencalais.addKeyword(tags, keyword);
      			$(this).addClass('suggestion_selected');
      		}
    		});
  		}
  	});
    
  	$('label.suggestion', context).each( function() {
  		var tags = $('#' + $(this).attr('for'));
  		var keyword = $(this).text();
  		
  		if (tags.val().indexOf(keyword) != -1) {
  			$(this).addClass('suggestion_selected');
  		}		
  	});     
  }
};

Drupal.opencalais = Drupal.opencalais || {};

/**
 * Insert keyword, adding a comma if necessary
 */
Drupal.opencalais.addKeyword = function(tags, keyword) {
  keyword = Drupal.opencalais.cleanKeyword(keyword);
	var current = $.trim(tags.val());
  var regexp = Drupal.opencalais.keywordRegexp(keyword);

	if(!regexp.test(current)) {
		if(current == '') {
			tags.val(keyword);				
		}
		else{
			tags.val(current + ',' + keyword);
		}				
	}
}

/**
 * Remove the keyword and cleanup any comma nonsense
 */
Drupal.opencalais.removeKeyword = function(tags, keyword) {
  keyword = Drupal.opencalais.cleanKeyword(keyword);
	var current = $.trim(tags.val());
	var regexp = Drupal.opencalais.keywordRegexp(keyword);
	
	if(regexp.test(current)) {
		current = current.replace(regexp, '$1$2');
		
		// Deal with a remaining extra comma
		current = current.replace(/^\s*,/, '');
		current = current.replace(/,\s*$/, '');
		current = current.replace(/,\s*,/, ',');
		tags.val(current);
	}
}

/**
 * Get a regular expression that matches a WHOLE term and not a term within another term.
 * Example: United Refugee Rights and Refugee Rights
 *
 * A whole term will:
 *    - start with either the beginning of the line (^) or a comma
 *    - end with either a comma or the end of the line ($)
 *    - it can also be padded with whitespace
 */
Drupal.opencalais.keywordRegexp = function(keyword) {
  return new RegExp('(^|,)\\s*' + keyword + '\\s*(,|$)');
}


/**
 * Perform any necessary functions to cleanup the keyword
 */
Drupal.opencalais.cleanKeyword = function(keyword) {
  // If it has a comma IN it, surround with quotes
	if(keyword.indexOf(',') != -1) {
    keyword = '"' + keyword + '"'
	}
  return keyword;
}

})(jQuery);
