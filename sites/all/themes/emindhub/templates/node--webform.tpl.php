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
 // print render($content['field_duration_of_the_mission']);
 // Show $node field, with custom display parameters
 // print render(field_view_field('node', $node, 'field_duration_of_the_mission'));
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

	<?php print $user_picture; ?>

	<?php print render($title_prefix); ?>
	<?php if (!$page): ?>
		<h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
	<?php endif; ?>
	<?php print render($title_suffix); ?>

	<?php if ($display_submitted): ?>
		<div class="submitted">
			<?php print $submitted; ?>
		</div>
	<?php endif; ?>

	<div class="content"<?php print $content_attributes; ?>>

	  <?php
	  if (isset($variables['elements']['links']['views_navigation'])) {
	    $linkBack = $variables['elements']['links']['views_navigation']['#links']['back'];
	    $linkPrev = $variables['elements']['links']['views_navigation']['#links']['previous'];
	    $linkNext = $variables['elements']['links']['views_navigation']['#links']['next'];
	  } ?>
  	<?php if (isset($linkBack) && isset($linkPrev) && isset($linkNext)) { ?>
    <div class="row section">
      <div class="col-sm-3 challenge-to-list">
        <a href="<?php print base_path() . $linkBack['href']; ?>" <?php print drupal_attributes($linkBack['attributes']); ?>>
					<span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span> <?php print $linkBack['title']; ?>
				</a>
      </div>
      <div class="col-sm-3 col-sm-offset-3 col-xs-6 challenge-previous text-right">
				<a href="<?php print base_path() . $linkPrev['href']; ?>" <?php print drupal_attributes($linkPrev['attributes']); ?>>
					<span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span> <?php print $linkPrev['title']; ?>
				</a>
      </div>
      <div class="col-sm-3 col-xs-6 challenge-next">
				<a href="<?php print base_path() . $linkNext['href']; ?>" <?php print drupal_attributes($linkNext['attributes']); ?>>
					<?php print $linkNext['title']; ?> <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
				</a>
    	</div>
    </div>
		<?php } ?>

		<div class="row section">
			<div class="col-sm-12">
				<?php print render($content['body']); ?>
			</div>
		</div>

		<div class="row section">

      <div class="col-sm-6">

				<div class="row">
			    <div class="col-sm-12">
						<?php print render($content['field_domaine']); ?>
						<?php print render($content['field_tags']); ?>
					</div>
				</div>

      </div>

      <div class="col-sm-3 meta">

				<ul>

					<?php if (isset($content['field_autoref'])) : ?>
					<li><?php print render($content['field_autoref']); ?></li>
					<?php endif; ?>

					<?php if (isset($elements['#node']->created)) : ?>
					<li>
						<div class="field field-name-field-created-date field-type-datetime field-label-inline clearfix">
							<div class="field-label"><?php print c_szPublicationDt; ?></div>
							<div class="field-items">
								<div class="field-item even">
									<?php print format_date($elements['#node']->created, 'custom', 'm/d/Y'); ?>
								</div>
							</div>
						</div>
					</li>
					<?php endif; ?>

					<?php if (isset($content['field_start_date'])) : ?>
					<li><?php print render($content['field_start_date']); ?></li>
					<?php endif; ?>

					<?php if (isset($content['field_duration_of_the_mission'])) : ?>
					<li><?php print render($content['field_duration_of_the_mission']); ?></li>
					<?php endif; ?>

					<?php if (isset($content['field_reward'])) : ?>
					<li><?php print render($content['field_reward']); ?></li>
					<?php endif; ?>

          <?php if (!function_exists("webform_get_submission_count")) : ?>
					<?php include_once(drupal_get_path('module', 'webform')."/includes/webform.submissions.inc"); ?>
					<li>
						<div class="field field-name-field-submission field-type-serial field-label-inline clearfix">
							<div class="field-label"><?php print c_szNumResponses; ?></div>
							<div class="field-items">
								<div class="field-item even">
									<?php print webform_get_submission_count($node->nid); ?>
								</div>
							</div>
						</div>
					</li>
					<?php endif; ?>

          <?php if (isset($field_has_salary[0]['value']) && $field_has_salary[0]['value'] == 1) : ?>
            <li><?php print render($content['field_has_salary']); ?></li>
          <?php endif; ?>

				</ul>

      </div>

			<?php if (isset($content['field_image'])) : ?>
			<div class="col-sm-3 text-right">
				<?php print render($content['field_image']); ?>
			</div>
			<?php endif; ?>

	  </div>

		<?php if (isset($content['field_object_of_the_mission'])) : ?>
		<div class="row section">
			<div class="col-sm-12">
				<?php print $elements['field_object_of_the_mission'][0]['#markup']; ?>
			</div>
		</div>
		<?php endif; ?>

		<?php
		if (
		  (isset($field_anonymous[0]['value']) && $field_anonymous[0]['value'] == 1) ||
		  (isset($field_show_entreprise[0]['value']) && $field_show_entreprise[0]['value'] == 1) ||
		  (isset($field_use_my_entreprise[0]['value']) && $field_use_my_entreprise[0]['value'] == 1)
		) : ?>

		<div class="row section ">
			<h3><span><?php print c_szSubmitted; ?></span></h3>
			<div class="col-sm-12">
				<?php require_once drupal_get_path('theme', 'emindhub').'/templates/includes/userInformations.tpl.php'; ?>
			</div>
		</div>
		<?php endif; ?>

	  <div class="row section">

			<div class="col-sm-12">

		    <?php print $elements['links']['flag']['#links']['flag-my_selection']['title']; ?>

				<?php if (node_access('update', $node)) : ?>
	      <?php print l(t('Edit'),'node/'.$node->nid.'/edit', array('attributes' => array('class' => array('btn','btn-primary','btn-expert'))) ); ?>
	      <?php print l(t('Edit questions'),'node/'.$node->nid.'/webform', array('attributes' => array('class' => array('btn','btn-primary','btn-expert'))) ); ?>
				<?php print l(t('View responses'),'node/'.$node->nid.'/webform-results', array('attributes' => array('class' => array('btn','btn-primary','btn-expert'))) ); ?>
				<?php endif; ?>

			</div>

		</div>

		<div class="row section emh-fieldgroup-blue-title">

			<?php if (!user_has_role(5)): ?>
		  <h2 class="h3"><span><?php echo c_szAnswerExpertCall; ?></span></h2>
		  <?php endif; ?>

			<div class="col-sm-12">
				<?php print render($content['webform']); ?>
			</div>
		</div>

		<?php
			// We hide the comments and links now so that we can render them later.
			hide($content['comments']);
			hide($content['links']);
			//print render($content);
		?>
	</div>

	<?php //print render($content['links']); // FLAG ?>

	<?php //print render($content['comments']); ?>

</div>
