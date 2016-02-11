<?php

/**
 * @file
 * Default theme implementation to display a node.
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

 // Show $node field, with display parameters
 // print render($content['field_expiration_date']);
 // Show $node field, with custom display parameters
 // print render(field_view_field('node', $node, 'field_duration_of_the_mission'));
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	<?php print render($title_prefix); ?>
	<?php if (!$page): ?>
		<h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
	<?php endif; ?>
	<?php print render($title_suffix); ?>

	<div class="content"<?php print $content_attributes; ?>>

		<?php if (emh_access_user_can_see_full_request()) : ?>

		<?php if (module_exists('progress_tracker')) : ?>
		<?php $progress_block = module_invoke('progress_tracker', 'block_view', 'progress_tracker'); ?>
		<section id="block-progress-tracker-progress-tracker" class="block block-progress-tracker emh-block-blue-title clearfix">
			<div class="content">
				<?php print render($progress_block['content']); ?>
			</div>
		</section>
		<?php endif; ?>

  	<?php require_once drupal_get_path('theme', 'emindhub').'/templates/includes/nodeNavigation.tpl.php'; ?>

		<?php if (!empty($body[0]['value']) || !empty($content['field_image'])) : ?>
		<div class="row section">
			<div class="col-sm-9">
				<?php print $body[0]['value']; ?>
			</div>
			<?php if (!empty($content['field_image'])) : ?>
			<?php // TODO : add default image ?>
			<div class="col-sm-3 text-right">
				<?php print render($content['field_image']); ?>
			</div>
			<?php endif; ?>
		</div>
		<?php endif; ?>

		<div class="row section">

			<div class="col-sm-4">
				<?php require_once drupal_get_path('theme', 'emindhub').'/templates/includes/userInformations.tpl.php'; ?>
			</div>

			<?php if ( !empty($content['field_domaine']) || !empty($content['field_tags']) ) : ?>
      <div class="col-sm-4">

				<div class="row">
			    <div class="col-sm-12">
						<?php print render($content['field_domaine']); ?>
						<?php print render($content['field_tags']); ?>
					</div>
				</div>

      </div>
			<?php endif; ?>

			<div class="col-sm-4 meta">

				<ul>

					<?php if (!empty($content['field_autoref'])) : ?>
					<li><?php print render($content['field_autoref']); ?></li>
					<?php endif; ?>

					<?php if (!empty($elements['#node']->created)) : ?>
					<li>
						<div class="field field-name-field-created-date field-type-datetime field-label-inline clearfix">
							<div class="field-label"><?php print t('Publication date:'); ?></div>
							<div class="field-items">
								<div class="field-item even">
									<?php print format_date($elements['#node']->created, 'custom', 'm/d/Y'); ?>
								</div>
							</div>
						</div>
					</li>
					<?php endif; ?>

					<?php if (!empty($content['field_expiration_date'])) : ?>
					<li><?php print render($content['field_expiration_date']); ?></li>
					<?php endif; ?>

					<?php if (!empty($content['field_reward'])) : ?>
					<li><?php print render($content['field_reward']); ?></li>
					<?php endif; ?>

					<li>
						<div class="field field-name-field-submission field-type-serial field-label-inline clearfix">
							<div class="field-label"><?php print t('Number of answers:'); ?></div>
							<div class="field-items">
								<div class="field-item even">
									<?php print $comment_count; ?>
								</div>
							</div>
						</div>
					</li>

				</ul>

      </div>

	  </div>

		<?php //require_once drupal_get_path('theme', 'emindhub').'/templates/includes/nodeLinks.tpl.php'; ?>

		<?php print render($content['comments']); ?>

		<?php
			// We hide the comments and links now so that we can render them later.
			// hide($content['comments']);
			// hide($content['links']);
			//print render($content);
		?>

		<?php else : ?>
		<?php require_once drupal_get_path('theme', 'emindhub').'/templates/includes/nodeProfileComplete.tpl.php'; ?>
		<?php endif; ?>

	</div>

</div>
