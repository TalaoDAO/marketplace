  /**
 * @file opencalais.admin.js
 *    This file contains all javascript associated with the OpenCalais preset admin screens.
 */
(function ($) {

Drupal.behaviors.opencalaisEntityConfig = {
  attach: function (context) {
    $(".threshold_slider", context).each(function() {
      if(!this.processed){
        
        $(this).parent().addClass('slider_holder');
        $(this).hide();
   
        var threshold = $(this);
        var container = $(this).parent("div");     
        var name = $(this).attr('name');
        
        var id = this.id.substring(0, this.id.indexOf('-threshold')) + '-enabled';

        var slider_name = name + '-slider';
        var slider = $('<div>').attr('id', slider_name).insertBefore($(this));
        var label_id = slider_name + '-label';
        var label = $('<div>').html(threshold.val()).attr({id: label_id, class: 'slider_label'}).insertAfter(slider);      
        slider.slider({
          min: 0.00,
    			max: 1.00,
    			step: 0.01,
    			value: threshold.val(),
          slide: function(event, ui ) {
            threshold.val(ui.value);
            label.html(ui.value);
            if(!$('#'+id).attr('checked')){
              $('#'+id).click();
              $('#'+id).parents('#opencalais_entities tbody tr').addClass('selected');
            }
          },
        });
        
        this.processed = true;
      }
    });
    //add stuff to make the rows highlight when they are selected
    $('#opencalais_entities tbody tr', context).each(function(){
      var holder = this;
      if(!this.processed){
        $('.form-checkbox', this).click(function(){
          if($(this).attr('checked')){
            $(holder).addClass('selected');
          } else {
            $(holder).removeClass('selected');
          }
        });
        this.processed = true;
      }
    });
    //add stuff to highlight existing fields and add some confirmation stuff
    $('#opencalais_entities tbody tr', context).each(function(){
      var row = this;

      if(!this.processedExisting){
        $('input', this).each(function(){
          if(this.type == 'hidden' && this.value){
            $(row).addClass('existing');
            $('.form-checkbox', row).click(function(e){
              if(!this.checked){
                this.checked = !confirm('When you save the form, this field and all its data will be removed from this content type. Continue?');
                if(!this.checked){
                  $(row).addClass('deleted');
                } 
              }else {
                $(row).removeClass('selected');
                $(row).removeClass('deleted');
              }
            });
          }
        });
        this.processedExisting = true;
      }
    });
    
  }
};

})(jQuery);