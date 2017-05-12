<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	<?php print render($title_prefix); ?>
	<?php if (!$page): ?>
		<h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
	<?php endif; ?>
	<?php print render($title_suffix); ?>

	<div class="content"<?php print $content_attributes; ?>>

		<?php if (emh_access_user_can_see_full_request()) : ?>

			<div class="section request">

				<div class="request-left">

					<?php print render($content['body']); ?>

					<?php print render($content['field_domaine']); ?>

					<?php print render($content['field_tags']); ?>

					<?php print render($content['og_group_ref']); ?>

					<?php if (emh_request_has_option($node, 'duration')) : ?>
			      <?php print render($content['field_start_date']); ?>
			      <?php print render($content['field_duration_of_the_mission']); ?>
			    <?php endif; ?>

					<?php if (emh_request_has_option($node, 'files') && !empty($content['field_request_documents'])) : ?>
						<?php print render($content['field_request_documents']); ?>
					<?php endif; ?>

					<?php if ($node->uid == $user->uid) : ?>
						<?php if (emh_request_has_option($node, 'questionnaire')) : ?>
							<?php
                $questions = ($node->status == NODE_PUBLISHED)
                  ? $node->webform['components']
                  : field_get_items('node', $node, 'field_request_questions');

                if ($questions):
                  $i = 0;
              ?>
								<div class="field field-questionnaire clearfix col-sm-12">
									<h4><?php print t('Questionnaire'); ?></h4>
									<ul class="request-questionnaire">
									<?php foreach ($questions as $question): $i++; $question = isset($question['name']) ? $question['name'] : $question['value']; ?>
										<li class="requestion-question-<?php print $i; ?>">
                      <span class="request-question-numerotation"><?php print $i; ?>.</span>&nbsp;<?php print $question; ?>
                    </li>
									<?php endforeach; ?>
                  </ul>
                </div>
							<?php endif; ?>
						<?php endif; ?>
					<?php endif; ?>

				</div>

				<div class="request-right">

					<?php print render($content['field_image']); ?>

					<?php print emh_user_cartouche_view($node->uid, 'author'); ?>

					<?php if (!empty($elements['#node']->created)) : ?>
						<?php print t('Publication date:'); ?>
						<?php print format_date($elements['#node']->created, 'short_date'); ?>
					<?php endif; ?>

				</div>

			</div>

			<?php if ($node->uid !== $user->uid) : ?>
				<div class="section user-submission">
					<div class="col-sm-8 submission-answer<?php if (!empty($submission_status)) print ' submission-' . $submission_status['status']; ?>">
						<div class="row user-submission-title">
							<div class="col-sm-8">
								<h3><span><?php print t('Your answer'); ?></span></h3>
							</div>
							<?php if (!empty($submission_status)): ?>
								<div class="col-sm-4">
									<span class="user-submission-status <?php print $submission_status['status']; ?>">
                    <?php print $submission_status['label']; ?>
                  </span>
								</div>
							<?php endif; ?>
						</div>
						<?php if (empty($user_submission) || !empty($user_submission->is_draft)) : ?>
				      <?php if ($node->webform['status'] && !empty($node->webform['components'])) : ?>
				      	<?php print render($content['webform']); ?>
				      <?php endif; ?>
						<?php else : ?>
							<?php
								$render = webform_submission_render($node, $user_submission, null, 'html');
								print drupal_render($render);
							?>
							<?php if (webform_submission_access($node, $user_submission, 'edit')) : ?>
		          	<a href="<?php print base_path(); ?>node/<?php print $node->nid; ?>/submission/<?php print $user_submission->sid; ?>/edit" class="btn btn-link"><?php print t('Edit'); ?></a>
		          <?php endif; ?>
						<?php endif; ?>
					</div>
				</div>
			<?php endif; ?>

			<?php
				// We hide the comments and links now so that we can render them later.
				hide($content['comments']);
				hide($content['links']);
			?>

		<?php endif; ?>

	</div>

</div>
