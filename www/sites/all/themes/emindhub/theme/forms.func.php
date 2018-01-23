<?php

// https://www.drupal.org/node/1341034#comment-5895860
function emindhub_process_format($element) {
  // array of field names to restrict (add more here as needed)
  $fields = array(
    'body',
    'field_textarea',
    'comment_body',
  );

  $element = filter_process_format($element);

  // Hide the 'text format' pane below certain text area fields.
  if (isset($element['#field_name']) && in_array($element['#field_name'], $fields)){
    $element['format']['#access'] = FALSE;
  }
  return $element;
}

/**
 * Implements hook_form_alter().
 */
function emindhub_form_alter(&$form, &$form_state, $form_id) {
  // echo '<pre>' . print_r($form_id, TRUE) . '</pre>';
  // echo '<pre>' . print_r($form, TRUE) . '</pre>';
  // echo '<pre>' . print_r(element_children($form), TRUE) . '</pre>';

  if (!empty($form['actions'])) {
    // Actions order
    $i = 0;
    foreach (
    array(
      'cancel',
      'close',
      'delete',
      'preview_changes',
      'draft',
      'preview',
      'submit',
      'save',
      'publish',
    ) as $field) {
      if (!empty($form['actions'][$field])) {
        $form['actions'][$field]['#weight'] = $i++;
      }
    }

    // Bootstrap buttons group
    $secondary_actions = array(
      'cancel'	=> array(),
      'close'	=> array(),
      'delete'	=> array(),
    );
    emindhub_beautiful_form_actions($form, $secondary_actions, 'secondary');
    $primary_actions = array(
      'preview_changes'	=> array(),
      'draft'						=> array(),
      'preview'					=> array(),
      'submit'					=> array(),
      'save'						=> array(),
      'publish'					=> array(),
    );
    emindhub_beautiful_form_actions($form, $primary_actions);
  }

  // Add required legend if minimum one field is required
  if (emindhub_form_has_required($form, $form_id)) {
    $form['actions']['#suffix'] = '
      <div class="form-mandatory">
        <span class="form-required">*</span>&nbsp;' . t('Required fields') . '
      </div>';
  }

  // Hide "Show row weights" for regular users
  global $user;

  if (!(in_array('webmaster', $user->roles) || in_array('administrator', $user->roles))) {
    if (empty($form['#attached']['js'])) {
      $form['#attached']['js'] = array();
    }

    $form['#attached']['js'] += array(
      drupal_get_path('theme', 'emindhub') . '/js/disable_show_row_weights.js',
    );
  }

  if (isset($form['#node']->nid) && ($form_id == 'webform_client_form_' . $form['#node']->nid)) {
    global $user;
    $account = user_load($user->uid);

    $fields = emh_profile_complete_submission_set_fields();
    $fields = _emh_profile_complete_get_empty_fields('user', 'user', $user, $fields);

    $first = FALSE; $last = FALSE; $i = 0;
    foreach($fields as $field => $value) {
      $fields[$field] = array(
        'first' => FALSE,
        'last' => FALSE,
      );
      if (!$first) {
        $first = TRUE;
        $fields[$field]['first'] = TRUE;
        $form[$field]['#prefix'] = '<fieldset>';
        $form[$field]['#prefix'] .= '<legend>' . t('Complete your profile') . '</legend>';
        $form[$field]['#prefix'] .= '<p>' . t('Please fill in the information below to publish your request. This information is required only once and will enable the requester to access your profile.') . '</p>';
      }
      if ($i % 2 == 0) {
        if (isset($form[$field]['#prefix'])) {
          $form[$field]['#prefix'] .= '<div class="form-group-2col row">';
        }
        else {
          $form[$field]['#prefix'] = '<div class="form-group-2col row">';
        }
      }
      else {
        $form[$field]['#suffix'] = '</div>';
      }
      $i++;
    }
    $fields = array_reverse($fields);
    foreach($fields as $field => $value) {
      if (!$last) {
        $last = TRUE;
        $fields[$field]['last'] = TRUE;
        $form[$field]['#suffix'] = '</fieldset>';
      }
    }
    $fields = array_reverse($fields);

    // Set the fields weights > 1st field in order to be in fieldset.
    $form['field_position']['#weight'] = '24';
    $form['field_working_status']['#weight'] = '25';
    $form['field_domaine']['#weight'] = '26';
    $form['field_address']['#weight'] = '27';
    $form['field_cv']['#weight'] = '28';

    // Address.
    $form['field_address'][LANGUAGE_NONE][0]['#type'] = 'div';
  }

  switch ($form_id) {
    case 'user_login':
    case 'user_login_block':
      $form['name']['#title_display'] = 'invisible';
      $form['name']['#attributes']['placeholder'] = t('Email');

      $form['pass']['#title_display'] = 'invisible';
      $form['pass']['#attributes']['placeholder'] = $form['pass']['#title'];

      $markup = l(t('Forgot your password?'), 'user/password', array('attributes' => array('title' => t('Request new password via e-mail.'))));
      $markup = '<div class="login-links">' . $markup . '</div>';
      $form['links']['#markup'] = $markup;
      $form['links']['#weight'] = 8;

      $form['actions']['#weight'] = 9;

      $form['hybridauth']['#weight'] = 10;
      break;

    case 'user_register_form_client':
    case 'user_register_form_expert':
      $form['#groups']['group_account']->label = '';
      $form['emh_baseline'] = array(
        '#markup' => '<p class="emh-title-baseline">' . sprintf(t('Create your account %sfor free in no time%s'), '<strong>', '</strong>') . '</p>',
        '#weight' => '-1000',
      );
      // Add class before & after fields.
      if ($form['field_first_name'] && $form['field_last_name']) {
        $form['field_first_name']['#prefix'] = '<div class="row">';
        $form['field_last_name']['#suffix'] = '</div>';
      }
      // Reduce email description for better Bootstrap display (tooltip)
      $form['account']['mail']['#description'] = t('All e-mails from the system will be sent to this address. The e-mail address will only be used if you wish to receive a new password or certain news or notifications by e-mail.');
      break;
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_form_user_pass_alter(&$form, &$form_state) {
  $form['name']['#title_display'] = 'invisible';
  $form['name']['#attributes']['placeholder'] = t('Email');
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_form_user_profile_form_alter(&$form, &$form_state, $form_id) {
  $element_info = element_info('password_confirm');
  $process = $element_info['#process'];
  $process[] = 'emindhub_form_process_password_confirm';
  $form['account']['pass']['#process'] = $process;

  // Reduce email description for better Bootstrap display (tooltip)
  $form['account']['mail']['#description'] = t('All e-mails from the system will be sent to this address. The e-mail address will only be used if you wish to receive a new password or certain news or notifications by e-mail.');

  // Contact.
  $form['field_address'][LANGUAGE_NONE][0]['#type'] = 'div';

  if ($form['field_address'][LANGUAGE_NONE][0]['street_block']['thoroughfare'] && $form['field_address'][LANGUAGE_NONE][0]['street_block']['premise']) {
    $form['field_address'][LANGUAGE_NONE][0]['street_block']['thoroughfare']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_address'][LANGUAGE_NONE][0]['street_block']['premise']['#suffix'] = '</div>';
  }

  if ($form['field_address'][LANGUAGE_NONE][0]['phone_block']['phone_number'] && $form['field_address'][LANGUAGE_NONE][0]['phone_block']['mobile_number']) {
    $form['field_address'][LANGUAGE_NONE][0]['phone_block']['phone_number']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_address'][LANGUAGE_NONE][0]['phone_block']['mobile_number']['#suffix'] = '</div>';
  }

  if ($form['field_link_to_my_blog'] && $form['field_linkedin'] && $form['field_twitter']) {
    $form['field_link_to_my_blog']['#prefix'] = '<div class="user-social form-group-3col row">';
    $form['field_twitter']['#suffix'] = '</div>';
  }

  if ($form['field_position'] && $form['field_titre_metier'] && $form['field_working_status']) {
    $form['field_position']['#prefix'] = '<div class="form-group-3col row">';
    $form['field_working_status']['#suffix'] = '</div>';
  }

  if ($form['field_emh_usage'] && $form['field_needs_for_expertise']) {
    $form['field_emh_usage']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_needs_for_expertise']['#suffix'] = '</div>';
  }
  $form['field_needs_for_expertise'][LANGUAGE_NONE]['#title'] = $form['field_needs_for_expertise'][LANGUAGE_NONE]['#title'] . ' ' . t('(choose one or several fields)');
  $form['field_specific_skills3'][LANGUAGE_NONE]['#title'] = $form['field_specific_skills3'][LANGUAGE_NONE]['#title'] . ' ' . t('(using keywords or tags)');

  if ($form['field_sponsorship'] && $form['field_sponsor1']) {
    $form['field_sponsorship']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_sponsor1']['#suffix'] = '</div>';
  }

  if ($form['field_notification_frequency'] && $form['field_known_specific']) {
    $form['field_notification_frequency']['#prefix'] = '<div class="form-group-3col row">';
    $form['field_known_specific']['#suffix'] = '</div>';
  }
  if (user_access('create question1 content') || user_access('create webform content') || user_access('create challenge content')) {
    $form['field_notification_frequency'][LANGUAGE_NONE]['#description'] = t('How often do you want to receive eMindHub\'s notifications about new answers to your requests ?');
  }
  if (user_access('question1: comment on any question1 content') || user_access('edit own webform submissions') || user_access('challenge: comment on any challenge content')) {
    $form['field_notification_frequency'][LANGUAGE_NONE]['#description'] = t('How often do you want to receive eMindHub\'s notifications about new requests ?');
  }

  $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';

  // FIXME : fait buguer la prévisualisation des portraits
  // $form['field_photo'][LANGUAGE_NONE][0]['#process'][] = 'emindhub_my_file_element_process';
  $form['field_cv'][LANGUAGE_NONE][0]['#process'][] = 'emindhub_my_file_element_process';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_form_emh_profile_complete_request_form_alter(&$form, &$form_state, $form_id) {
  $form['field_entreprise']['#weight'] = '1';
  $form['field_working_status']['#weight'] = '2';
  $form['field_domaine']['#weight'] = '3';

  $form['actions']['#weight'] = '100';
  $form['actions']['#suffix'] = '';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_form_lang_dropdown_form_alter(&$form, &$form_state, $form_id) {
  $form['#attributes']['class'][] = 'navbar-form';
  $form['#attributes']['class'][] = 'navbar-right';
}

// Check if form and fields are required
// https://www.drupal.org/node/72197#comment-6000064
function emindhub_form_has_required($form, $form_id) {
  if ($form_id != 'user_login_block') {
    if (!empty($form['#required'])) {
      return TRUE;
    }
    foreach (element_children($form) as $key) {
      if (emindhub_form_has_required($form[$key], $form_id)) {
        return TRUE;
      }
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_form_search_block_form_alter(&$form, &$form_state, $form_id) {
  $form['search_block_form']['#title'] = t('Search'); // Change the text on the label element
  $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibility
  $form['search_block_form']['#size'] = 40;  // define size of the textfield

  // Add extra attributes to the text box
  $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search';}";
  $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == 'Search') {this.value = '';}";

  // Prevent user from searching the default text
  $form['search_block_form']['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search'){ alert('Please enter a search'); return false; }";

  // Alternative (HTML5) placeholder attribute instead of using the javascript
  $form['search_block_form']['#attributes']['placeholder'] = t('Type your search, keywords...');

  // echo '<pre>' . print_r($form['search_block_form'], TRUE) . '</pre>'; die;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_form_user_register_form_expert_alter(&$form, &$form_state, $form_id) {
  $form['emh_content'] = array(
    '#markup' => '<p class="emh-title-baseline">' . t('You can directly login with your LinkedIn account or complete the form below to create your account.') . '</p>',
    '#weight' => '-999',
  );
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_form_comment_form_alter(&$form, &$form_state, $form_id) {
  $form['author']['#access'] = 0;
  $form['subject']['#access'] = 0;
  if (empty($form['cid']['#value'])) $form['actions']['submit']['#value'] = t('Publish');

  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_views_bulk_operations_form_alter(&$form, $form_state, $vbo_handler) {
  // Only when we want it.
  $view = arg(2); $nid = arg(1);
  if (!empty($view) && ($view == 'answers' || $view == 'results')) {
    $form['select']['action::emh_points_arrange_node_points']['#attributes']['class'][] = 'btn-submit';
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_form_emh_points_arrange_form_alter(&$form, &$form_state, $type_source) {
  $form['submit']['#attributes']['class'][] = 'btn-submit';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_form_change_pwd_page_form_alter(&$form, &$form_state, $form_id) {
  $form['account']['pass']['#title'] = t('Enter your new password');

  $form['submit']['#value'] = t('Change my password');
  $form['submit']['#attributes']['class'][] = 'btn-submit';

  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 * node/add/webform
 * node/%/edit
 */
function emindhub_form_webform_node_form_alter(&$form, &$form_state, $form_id) {

  // Add class before & after fields
  if ($form['field_duration_of_the_mission'] && $form['field_start_date']) {
    $form['field_duration_of_the_mission']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_start_date']['#suffix'] = '</div>';
  }

  if ($form['field_document'] && $form['field_image']) {
    $form['field_document']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_image']['#suffix'] = '</div>';
  }

  if ($form['field_domaine'] && $form['field_tags']) {
    $form['field_domaine']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_tags']['#suffix'] = '</div>';
  }

  if ($form['field_anonymous'] && $form['field_use_my_entreprise']) {
    $form['field_anonymous']['#prefix'] = '<div class="form-group-3col row">';
    $form['field_use_my_entreprise']['#suffix'] = '</div>';
  }

  if ($form['field_expiration_date'] && $form['field_reward']) {
    $form['field_expiration_date']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_reward']['#suffix'] = '</div>';
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 * node/add/challenge
 * node/%/edit
 */
function emindhub_form_challenge_node_form_alter(&$form, &$form_state, $form_id) {
  // Add class before & after fields
  if ($form['field_document'] && $form['field_image']) {
    $form['field_document']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_image']['#suffix'] = '</div>';
  }

  if ($form['field_domaine'] && $form['field_tags']) {
    $form['field_domaine']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_tags']['#suffix'] = '</div>';
  }

  if ($form['field_anonymous'] && $form['field_use_my_entreprise']) {
    $form['field_anonymous']['#prefix'] = '<div class="form-group-3col row">';
    $form['field_use_my_entreprise']['#suffix'] = '</div>';
  }

  if ($form['field_expiration_date'] && $form['field_reward']) {
    $form['field_expiration_date']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_reward']['#suffix'] = '</div>';
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 * node/add/question1
 * node/%/edit
 */
function emindhub_form_question1_node_form_alter(&$form, &$form_state, $form_id) {
  // Add class before & after fields
  if ($form['field_domaine'] && $form['field_tags']) {
    $form['field_domaine']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_tags']['#suffix'] = '</div>';
  }

  if ($form['field_anonymous'] && $form['field_use_my_entreprise']) {
    $form['field_anonymous']['#prefix'] = '<div class="form-group-3col row">';
    $form['field_use_my_entreprise']['#suffix'] = '</div>';
  }

  if ($form['field_expiration_date'] && $form['field_reward']) {
    $form['field_expiration_date']['#prefix'] = '<div class="form-group-2col row">';
    $form['field_reward']['#suffix'] = '</div>';
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 * node/add/request
 * node/%/edit
 */
function emindhub_form_request_node_form_alter(&$form, &$form_state, $form_id) {
  global $base_url, $user;

  if ($form['field_request_type']) {
    $form['field_request_type']['#prefix'] = '<div class="section step1"><h2>' . t('What do you want to do?') . '</h2>';
    $form['field_request_type']['#suffix'] .= '</div>';
  }

  if ($form['title_field'] && $form['body']) {
    $form['title_field']['#prefix'] = '<div class="section step2"><h2>' . t('What is your request about?') . '</h2>';
    if (isset($_REQUEST['edit']['field_request_type'][LANGUAGE_NONE]['771']['771'])) {
      $form['title_field']['#prefix'] .= '<div class="emh-prepopulate-type-help" role="alert">' . t('Please specify the co-option reward in the title and/or description of your request. The reward must not be less than 500 euros. See <a href="' . $base_url . '/' . drupal_get_path_alias('faq-client') . '">FAQ</a> for more information.') . '</div>';
    }
    $form['body']['#suffix'] = '</div>';
  }

  if ($form['field_domaine'] && $form['language']) {
    $form['field_domaine']['#prefix'] = '<div class="section step3"><h2>' . t('Tell us more about your request:') . '</h2>';
    $form['language']['#suffix'] = '</div>';
  }
  $form['field_domaine'][LANGUAGE_NONE]['#title'] = t('Fields of expertise');

  $form['og_group_ref']['#prefix'] = '<div class="section step4"><h2>' . t('Select circle(s) of experts you want to address your request') . '</h2>';
  $form['og_group_ref']['#suffix'] = '</div>';

  $options_prefix = isset($form['field_options']['#prefix']) ? $form['field_options']['#prefix'] : '';
  $form['field_options']['#prefix'] = '<div class="section step5"><h2>' . t('Add options and get the most from your request!') . '</h2>';
  $form['field_options']['#prefix'] .= '<p class="emh-credits-buy">' . t('Do you need more credits? Please contact us at <a href="mailto:credits@emindhub.com?Subject=Credits%20needed%20by%20!current_user&Body=Your%20company%3A%0AYour%20position%3A%0APhone%20number%3A%0AAmount%20of%20credits%20needed%3A">credits@emindhub.com</a>', array(
        '!current_user' => format_username($user),
  )) . '</p>';
  $form['field_options']['#prefix'] .= $options_prefix;
  $form['field_options'][LANGUAGE_NONE]['#type'] = 'div';
  $form['field_options']['#suffix'] = '</div>';

  $form['field_options'][LANGUAGE_NONE]['questionnaire']['enabled']['#suffix'] = '<div class="form-item-description">' . $form['field_options'][LANGUAGE_NONE]['questionnaire']['enabled']['#description'] . '</div>';
  $form['field_options'][LANGUAGE_NONE]['questionnaire']['enabled']['#description'] = '';
  $form['field_request_questions'][LANGUAGE_NONE]['add_more']['#value'] = t('Add another question');

  $form['field_options'][LANGUAGE_NONE]['private']['enabled']['#suffix'] = '<div class="form-item-description">' . $form['field_options'][LANGUAGE_NONE]['private']['enabled']['#description'] . '</div>';
  $form['field_options'][LANGUAGE_NONE]['private']['enabled']['#description'] = '';

  $form['field_options'][LANGUAGE_NONE]['files']['enabled']['#suffix'] = '<div class="form-item-description">' . $form['field_options'][LANGUAGE_NONE]['files']['enabled']['#description'] . '</div>';
  $form['field_options'][LANGUAGE_NONE]['files']['enabled']['#description'] = '';

  $form['field_options'][LANGUAGE_NONE]['duration']['enabled']['#suffix'] = '<div class="form-item-description">' . $form['field_options'][LANGUAGE_NONE]['duration']['enabled']['#description'] . '</div>';
  $form['field_options'][LANGUAGE_NONE]['duration']['enabled']['#description'] = '';

  $form['field_options'][LANGUAGE_NONE]['anonymous']['enabled']['#suffix'] = '<div class="form-item-description">' . $form['field_options'][LANGUAGE_NONE]['anonymous']['enabled']['#description'] . '</div>';
  $form['field_options'][LANGUAGE_NONE]['anonymous']['enabled']['#description'] = '';

  if ($form['field_hide_name'] && $form['field_hide_organisation']) {
    $form['field_hide_name']['#prefix'] = '<div class="request-option-anonymous">';
    $form['field_hide_organisation']['#suffix'] = '</div>';
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emindhub_form_contact_site_form_alter(&$form, &$form_state) {
  $form['firstname']['#prefix'] = '<div class="contact-left">';
  $form['mail']['#suffix'] = '</div>';
  $form['message']['#prefix'] = '<div class="contact-right">';
  $form['message']['#suffix'] = '</div>';
}
