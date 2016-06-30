<?php
/**
 * @file
 * ft_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ft_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'What are the advantages';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'expert_avantages';
  $fe_block_boxes->body = '<p>Contenu géré directement dans le tpl du block.</p>
';

  $export['expert_avantages'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Registration block : expert/business';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_register';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['home_register'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Baseline';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_baseline';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['hp_baseline'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Create a request';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_challenge';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['hp_challenge'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Expert - Do you have an expertise?';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_expertise';
  $fe_block_boxes->body = '<h2>Do you have <strong>expertise?</strong></h2>

<h3>Get yourself known to your future clients&nbsp;and generate revenue online!</h3>

<ul>
	<li>Demonstrate your skills and find assignments</li>
	<li>Monetize your professional network</li>
</ul>
';

  $export['hp_expertise'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Our value proposition';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'hp_experts';
  $fe_block_boxes->body = '<p>Our value proposition</p>
';

  $export['hp_experts'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Experts - You are';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_experts_picto';
  $fe_block_boxes->body = '<ul>
	<li>An experienced professional</li>
	<li>An active retiree</li>
	<li>A researcher</li>
	<li>A PhD</li>
</ul>
';

  $export['hp_experts_picto'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Experts - Why should you use eMindHub?';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_experts_text';
  $fe_block_boxes->body = '<h3>Why should you use eMindHub?</h3>

<ul>
	<li>Direct contact with potential customers</li>
	<li>Maintain contact with the aerospace community</li>
	<li>Control your independence</li>
	<li>Set your fees without royalties</li>
</ul>
';

  $export['hp_experts_text'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Business - Why should you use eMindHub?';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_mobilize';
  $fe_block_boxes->body = '<h3>Why should you use eMindHub?</h3>

<ul>
	<li>Direct access to aerospace experts all over the world</li>
	<li>Instant and high quality responses to your requests</li>
	<li>Choose an expert through responses received</li>
	<li>Personalised settings for full confidentiality</li>
	<li>Manage your own network of experts</li>
</ul>
';

  $export['hp_mobilize'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Business - Is your company looking for expertise?';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_request';
  $fe_block_boxes->body = '<h2>Is your company <strong>looking for expertise?</strong></h2>

<h3>Get best experts working for you!</h3>

<ul>
	<li>Obtain advice, return on experience and insights</li>
	<li>Entrust experts with specific tasks</li>
	<li>Call experts pools for innovation</li>
</ul>
';

  $export['hp_request'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Video';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_video';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['hp_video'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Welcome';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'hp_welcome';
  $fe_block_boxes->body = 'Contenu géré dans le template.';

  $export['hp_welcome'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Business - You are';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'hp_why';
  $fe_block_boxes->body = '<ul>
	<li>OEM</li>
	<li>MRO</li>
	<li>Airline</li>
	<li>Service company</li>
</ul>

<ul>
	<li>Industrial SME</li>
	<li>Investor</li>
	<li>Research center</li>
	<li>Training center</li>
</ul>
';

  $export['hp_why'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Quality';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_why_quality';
  $fe_block_boxes->body = '<p><strong>eMindHub</strong> is based on <strong>lead experts</strong> who guarantee the quality of the responses</p>';

  $export['hp_why_quality'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Rapidity';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_why_rapidity';
  $fe_block_boxes->body = '<p><strong>eMindHub</strong> ensures a quick response with its large network of <strong>connected experts</strong></p>';

  $export['hp_why_rapidity'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Confidentiality';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_why_security';
  $fe_block_boxes->body = '<p><strong>eMindHub</strong> allows you to choose <strong>circles</strong> of trustworthy experts</p>
';

  $export['hp_why_security'] = $fe_block_boxes;

  return $export;
}
