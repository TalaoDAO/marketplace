<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	<?php print render($title_prefix); ?>
	<?php if (!$page): ?>
		<h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
	<?php endif; ?>
	<?php print render($title_suffix); ?>

	<div class="content"<?php print $content_attributes; ?>>

		<?php if (emh_access_user_can_see_full_request()) : ?>
		<div class="section request">

			<div class="request-left">
				<?php print render($content['body']); ?>
        <?php print render($content['field_expiration_date']); ?>
        <?php print render($content['field_tags']); ?>
				<?php print render($content['field_domaine']); ?>
				<?php print render($content['og_group_ref']); ?>

				<?php if (emh_request_has_option($node, 'duration')): ?>
		      <?php print render($content['field_start_date']); ?>
		      <?php print render($content['field_duration_of_the_mission']); ?>
		    <?php endif; ?>

				<?php if (emh_request_has_option($node, 'files') && !empty($content['field_request_documents'])): ?>
					<?php print render($content['field_request_documents']); ?>
				<?php endif; ?>

				<?php if (emh_request_has_option($node, 'anonymous')): ?>
					<?php if ($hidden_name): ?>
						<div class="field field-name-field-hide-organisation clearfix">
							<i><?php print t("My name will be hidden."); ?></i>
						</div>
					<?php endif; ?>

					<?php if ($hidden_organisation): ?>
						<div class="field field-name-field-hide-name clearfix">
							<i><?php print t("My organisation will be hidden."); ?></i>
						</div>
					<?php endif; ?>

					<?php print render($content['field_activity']); ?>
				<?php endif; ?>

        <?php if (emh_request_has_option($node, 'questionnaire')): ?>
					<?php print render($content['field_request_questions']); ?>
				<?php endif; ?>
			</div>

			<div class="request-right">
				<?php print render($content['field_image']); ?>
			</div>

		</div>
    <?php endif; ?>

	</div>
</div>
