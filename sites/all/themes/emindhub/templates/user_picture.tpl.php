<?php if ($account->picture): ?>
    <div class="profile-picture" style="background-image: url(<?php echo file_create_url($account->picture->uri); ?>)"></div>
<?php endif; ?>


