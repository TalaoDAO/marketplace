<?php if (!empty($fields['title_field']->content)): ?>
<h3 class="question">
    <?php print $fields['title_field']->content; ?>
</h3>
<?php endif; ?>

<?php if (!empty($fields['body']->content)): ?>
<div class="answer">
    <?php print $fields['body']->content; ?>
</div>
<?php endif; ?>
