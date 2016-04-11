<?php

/**
 * @file
 * Customize the e-mails sent by Webform after successful submission.
 *
 * This file may be renamed "webform-mail-[nid].tpl.php" to target a
 * specific webform e-mail on your site. Or you can leave it
 * "webform-mail.tpl.php" to affect all webform e-mails on your site.
 *
 * Available variables:
 * - $node: The node object for this webform.
 * - $submission: The webform submission.
 * - $email: The entire e-mail configuration settings.
 * - $user: The current user submitting the form. Always the Anonymous user
 *   (uid 0) for confidential submissions.
 * - $ip_address: The IP address of the user submitting the form or '(unknown)'
 *   for confidential submissions.
 *
 * The $email['email'] variable can be used to send different e-mails to different users
 * when using the "default" e-mail template.
 */
global $base_url;
$author = user_load($node->uid);
$node_link = $base_url . '/user/login?destination=node/' . $node->nid . '?pk_campaign=new_answer_mission_' . $node->nid . '&amp;pk_kwd=link';
$node_calltoaction = $base_url . '/user/login?destination=node/' . $node->nid . '?pk_campaign=new_answer_mission_' . $node->nid . '&amp;pk_kwd=calltoaction';
?>

<h1 style="text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:22px;margin-bottom:20px;color:#333;line-height:150%;"><?php print t('A new answer just came up on your request'); ?></h1>
<div style="text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:16px;margin-bottom:20px;color:#333;line-height:150%;">
  <p><?php print t('Dear'); ?> <?php print $author->field_first_name; ?>,</p>
  <p><?php print t('A new answer has been published on your request'); ?> <strong><a title="<?php print $node->title; ?>" href="<?php print $node_link; ?>" target="_blank" style="font-weight:bold!important;"><?php print $node->title; ?></a></strong>.</p>
  <p><?php print t('Should you like to know more, just log into the platform now.'); ?></p>
</div>
<table style="min-width:100%;" width="100%" border="0" cellpadding="0" cellspacing="0" class="emailButton">
  <tbody>
    <tr>
      <td style="padding-top:0; padding-right:18px; padding-bottom:18px; padding-left:18px;" valign="top" align="center">
        <table style="border-collapse:separate!important;border-radius:0px;background-color:rgb(0, 159, 227);" border="0" cellpadding="0" cellspacing="0">
          <tbody>
            <tr>
              <td style="font-familyArial; font-size16px; padding15px; colorrgb(255, 255, 255);" valign="middle" align="center">
                <a title="<?php print t('Log in to eMindHub'); ?>" href="<?php print $node_calltoaction; ?>" target="_blank" style="font-weight:bold!important;letter-spacing:normal;line-height:100%;text-align:center;text-decoration:none;color:#FFFFFF!important;"><?php print t('Log in to eMindHub'); ?></a>
              </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>
