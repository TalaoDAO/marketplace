<?php
/**
 * @file
 * Template by default for the request nodes.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *	 or print a subset such as render($content['field_example']). Use
 *	 hide($content['field_example']) to temporarily suppress the printing of a
 *	 given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *	 calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *	 template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *	 CSS. It can be manipulated through the variable $classes_array from
 *	 preprocess functions. The default values can be one or more of the
 *	 following:
 *	 - node: The current template type; for example, "theming hook".
 *	 - node-[type]: The current node type. For example, if the node is a
 *		 "Blog entry" it would result in "node-blog". Note that the machine
 *		 name will often be in a short form of the human readable label.
 *	 - node-teaser: Nodes in teaser form.
 *	 - node-preview: Nodes in preview mode.
 *	 The following are controlled through the node publishing options.
 *	 - node-promoted: Nodes promoted to the front page.
 *	 - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *		 listings.
 *	 - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *	 modules, intended to be displayed in front of the main title tag that
 *	 appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *	 modules, intended to be displayed after the main title tag that appears in
 *	 the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *	 into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *	 teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *	 main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */

include_once drupal_get_path('module', 'webform') . '/includes/webform.submissions.inc';
global $user;
$submissions = webform_get_submissions(array('nid' => $nid));
if ($user_submission) {
	$submission_status = emh_answer_get_status($user_submission);
}

// Show $node field, with display parameters
// echo '<pre>' . print_r($content['webform']['#node']->webform, TRUE) . '</pre>'; die;
// Show $node field, with custom display parameters
// print render(field_view_field('node', $node, 'field_duration_of_the_mission'));
?>

<?php /*if (!empty($variables['flag_my_selection'])) : ?>
<?php print $variables['flag_my_selection']['title']; ?>
<?php endif;*/ ?>

<?php //print webform_get_submission_count($node->nid); ?>

<?php /*if (!empty($content['field_expiration_date'])) : ?>
	<?php print render($content['field_expiration_date']); ?>
<?php endif;*/ ?>

<?php /*if (!empty($variables['linkPrev'])) : ?>
	<a href="<?php print base_path() . $variables['linkPrev']['href']; ?>" <?php print drupal_attributes($variables['linkPrev']['attributes']); ?>>
		<span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span> <?php print $variables['linkPrev']['title']; ?>
	</a>
<?php endif; ?>

<?php if (!empty($variables['linkNext'])) : ?>
	<a href="<?php print base_path() . $variables['linkNext']['href']; ?>" <?php print drupal_attributes($variables['linkNext']['attributes']); ?>>
		<?php print $variables['linkNext']['title']; ?> <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
	</a>
<?php endif;*/ ?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	<?php print render($title_prefix); ?>
	<?php if (!$page): ?>
		<h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
	<?php endif; ?>
	<?php print render($title_suffix); ?>

	<div class="content"<?php print $content_attributes; ?>>

		<?php if (emh_access_user_can_see_full_request()) : ?>

		<div class="section request">

			<div class="col-sm-8">

				<?php print render($content['body']); ?>

				<?php print render($content['field_domaine']); ?>

				<?php print render($content['og_group_ref']); ?>

				<?php if (emh_request_has_option($node, 'duration')) : ?>
		      <?php print render($content['field_start_date']); ?>
		      <?php print render($content['field_duration_of_the_mission']); ?>
		    <?php endif; ?>

				<?php if (emh_request_has_option($node, 'files') && !empty($content['field_request_documents'])) : ?>
					<?php print render($content['field_request_documents']); ?>
				<?php endif; ?>

			</div>

			<div class="col-sm-4">

				<?php print render($content['field_image']); ?>

				<div class="user-cartouche">
					<?php print emindhub_beautiful_user_cartouche($node); ?>
				</div>

				<?php if (!empty($elements['#node']->created)) : ?>
					<?php print t('Publication date:'); ?>
					<?php print format_date($elements['#node']->created, 'custom', 'm/d/Y'); ?>
				<?php endif; ?>

			</div>

		</div>

		<?php if ($node->uid !== $user->uid) : ?>
			<div class="section user-submission">
				<div class="col-sm-8 <?php if ($submission_status) print $submission_status['status']; ?>">
					<div class="row user-submission-title">
						<div class="col-sm-8">
							<h3><span><?php print t('Your submission'); ?></span></h3>
						</div>
						<?php if ($submission_status) : ?>
							<div class="col-sm-4">
								<span class="user-submission-status <?php if ($submission_status) print $submission_status['status']; ?>"><?php if ($submission_status) print $submission_status['label']; ?></span>
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
	          	<a href="<?php print base_path(); ?>node/<?php print $node->nid; ?>/submission/<?php print $user_submission->sid; ?>/edit"><?php print t('Edit'); ?></a>
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

    <?php if (($node->uid == $user->uid) || !emh_request_has_option($node, 'private')) : ?>
			<div class="section submissions">
				<div class="row submissions-title">
					<div class="col-sm-8">
			    	<h2><span class="submission-title"><?php print t('Submissions'); ?></span>&nbsp;<span class="submission-count">(<?php print webform_get_submission_count($node->nid); ?>)</span></h2>
					</div>
					<?php if (emh_request_has_option($node, 'private')) : ?>
						<div class="col-sm-4 text-right submissions-private-info">
							<span class="submission-private"><?php print t('Submissions are only visible by you.'); ?></span>
						</div>
					<?php endif; ?>
				</div>
				<div class="submissions-list">
		      <?php if (!empty($submissions)) : ?>
		        <?php foreach ($submissions as $submission) : ?>
							<?php if (!($node->uid == $user->uid && !empty($submission->is_draft))) : ?>
			          <?php
			            $render = webform_submission_render($node, $submission, null, 'html');
			            print drupal_render($render);
			          ?>
			          <?php if (webform_submission_access($node, $submission, 'edit')) : ?>
			          	<a href="<?php print base_path(); ?>node/<?php print $node->nid; ?>/submission/<?php print $submission->sid; ?>/edit"><?php print t('Edit'); ?></a>
			          <?php endif; ?>
							<?php endif; ?>
		        <?php endforeach; ?>
		      <?php else: ?>
		      	<?php print t("No submission at this moment."); ?>
		      <?php endif; ?>
				</div>
			</div>
    <?php endif; ?>

		<?php endif; ?>

	</div>

</div>
