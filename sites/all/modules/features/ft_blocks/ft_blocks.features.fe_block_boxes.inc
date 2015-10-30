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
  $fe_block_boxes->info = 'Bêta version';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'beta';
  $fe_block_boxes->body = '<p><strong>Welcome to eMindHub!</strong>&nbsp;Thank you for being among the first users of our platform! This is a beta version, for any suggestion or comment please leave a message through the <a href="/emindhub.com/www/contact">contact form</a>.</p>
';

  $export['beta'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'What are the advantages';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'expert_avantages';
  $fe_block_boxes->body = '<p>Contenu géré directement dans le tpl du block.</p>';

  $export['expert_avantages'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Experts points info';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'experts_points_info';
  $fe_block_boxes->body = '<p>You can earn points by responding to a request and when the client recognize the value of your contribution. You can therefore monetize your points once you have reached a threshold of at least 500 points.</p>
';

  $export['experts_points_info'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Registration block : expert/business';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_register';
  $fe_block_boxes->body = '<p><a class="btn btn-submit" href="business/register">Register as a client</a></p><p><a class="btn btn-submit" href="expert/register">Register as an expert</a></p><p>Create your account in 1 minute !</p>';

  $export['home_register'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Baseline';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_baseline';
  $fe_block_boxes->body = '<p>Get online access&nbsp;to</p><p>the 1st global network of experts</p><p>in aerospace</p>';

  $export['hp_baseline'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Start a challenge';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_challenge';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>';

  $export['hp_challenge'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - You have an expertise';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_expertise';
  $fe_block_boxes->body = '<p>Contenu géré directement dans le tpl du block.</p>';

  $export['hp_expertise'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - About experts';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'hp_experts';
  $fe_block_boxes->body = 'About experts';

  $export['hp_experts'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Experts : picto';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_experts_picto';
  $fe_block_boxes->body = '<ul><li>All the experts<br />Our worldwide database of experts</li><li>Sponsored experts<br />Experts sponsored by their peers</li><li>Your active network<br />Your employees and your business partners</li><li>Your Alumni<br />People who left your organization</li><li>Your customised selection<br />Circles created on demand</li></ul>';

  $export['hp_experts_picto'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Experts : text';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_experts_text';
  $fe_block_boxes->body = '<p><strong>Experienced professionals, active retirees, researchers, students&hellip;</strong><br />Find the experts you need in the emindhub&#39;s network</p><p><strong>With emindhub,</strong><br />address your request to one or several circles of experts</p>';

  $export['hp_experts_text'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - How to mobilize the experts ?';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'hp_mobilize';
  $fe_block_boxes->body = 'How to mobilize the experts ?';

  $export['hp_mobilize'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Ask a question';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_question';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>';

  $export['hp_question'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - You have a request';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_request';
  $fe_block_boxes->body = '<p>Contenu géré directement dans le tpl du block.</p>';

  $export['hp_request'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Create a survey';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_survey';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>';

  $export['hp_survey'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Welcome';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'hp_welcome';
  $fe_block_boxes->body = 'Contenu géré dans le template.';

  $export['hp_welcome'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Why use eMindHub ?';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'hp_why';
  $fe_block_boxes->body = 'Why use eMindHub ?';

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
  $fe_block_boxes->info = 'HP - Security';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_why_security';
  $fe_block_boxes->body = '<p><strong>eMindHub</strong> allows you to choose <strong>circles</strong> of trustworthy experts</p>';

  $export['hp_why_security'] = $fe_block_boxes;

  return $export;
}
