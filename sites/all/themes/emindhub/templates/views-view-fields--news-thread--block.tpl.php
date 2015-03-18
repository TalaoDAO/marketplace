<div class="bold upper inline bubble">
    <?php print $fields['title']->content; ?>
</div>

<div class="row">
    <div class="col-md-11 col-md-offset-1">
        <?php print format_date($row->node_created, 'long'); ?>
    </div>
</div>
<div class="row">
    <div class="col-md-12">
        <?php print $fields['field_image']->content; ?>
    </div>
</div>
<div class="row">
    <div class="col-md-12">
        <?php print $fields['body']->content; ?>
    </div>
</div>