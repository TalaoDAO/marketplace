<?php

/**
 * @file
 * Default theme implementation to display a flag link, and a message after the
 * action is carried out.
 *
 * Available variables:
 *
 * - $flag: The flag object itself. You will only need to use it when the
 *   following variables don't suffice.
 * - $flag_name_css: The flag name, with all "_" replaced with "-". For use in
 *   'class' attributes.
 * - $flag_classes: A space-separated list of CSS classes that should be applied
 *   to the link.
 *
 * - $action: The action the link is about to carry out, either "flag" or
 *   "unflag".
 * - $status: The status of the item; either "flagged" or "unflagged".
 * - $entity_id: The id of the entity item.
 *
 * - $link['href']: The path for the flag link.
 * - $link['query']: Array of query string parameters, such as "destination".
 * - $link_href: The URL for the flag link, query string included.
 * - $link_text: The text to show for the link.
 * - $link_title: The title attribute for the link.
 *
 * - $message_text: The long message to show after a flag action has been
 *   carried out.
 * - $message_classes: A space-separated list of CSS classes that should be
 *   applied to
 *   the message.
 * - $after_flagging: This template is called for the link both before and after
 *   being
 *   flagged. If displaying to the user immediately after flagging, this value
 *   will be boolean TRUE. This is usually used in conjunction with immedate
 *   JavaScript-based toggling of flags.
 * - $needs_wrapping_element: Determines whether the flag displays a wrapping
 *   HTML DIV element.
 * - $errors: An array of error messages.
 *
 * Template suggestions available, listed from the most specific template to
 * the least. Drupal will use the most specific template it finds:
 * - flag--name.tpl.php
 * - flag--link-type.tpl.php
 *
 * NOTE: This template spaces out the <span> tags for clarity only. When doing
 * some advanced theming you may have to remove all the whitespace.
 */
?>
<?php if ($needs_wrapping_element): ?>
  <div class="flag-outer flag-outer-<?php print $flag_name_css; ?>">
<?php endif; ?>
<span class="<?php print $flag_wrapper_classes; ?>">
  <?php if ($link_href): ?>
    <a href="<?php print $link_href; ?>" title="<?php print $link_title; ?>" class="<?php print $flag_classes ?>" onclick="validate_exp(); return false;" rel="nofollow"><?php print $link_text; ?></a><span class="flag-throbber">&nbsp;</span>
  <?php else: ?>
    <span class="<?php print $flag_classes ?>"><?php print $link_text; ?></span>
  <?php endif; ?>
  <?php if ($after_flagging): ?>
    <span class="<?php print $message_classes; ?>">
      <?php print $message_text; ?>
    </span>
  <?php endif; ?>
</span>
<?php global $user; $client=user_load($user->uid); render(field_view_value('user', $client, 'field_freelancer')); ?>
<script type="text/javascript">

  function validate_exp() {
    var userid = <?php global $user; print $user->uid;?>;
    var nodeid = <?php $nid = arg(1); print $nid;?>;
    var eid = <?=$entity_id?>;
    var expertid = <?php $entity = reset(entity_load('webform_submission', [$entity_id])); print $entity->uid; ?>;
    console.log(expertid);
    function drupalCall(url, method, callback) {          
            var drupal = new drupalService();
            drupal.url = url;
            drupal.method = method;
            drupal.callback = callback;
            drupal.get();
    }
        window.contract = Drupal.settings.ethereum.contracts.Freelancer.instance;
        contract.methods.owner().call().then(ownerAccount => {
          window.expert_hash = null;
          window.client_hash = null;
          var host = window.location.hostname;
          var root = 'http://'+host+'/api';
          drupalCall(root, 'user/'+userid+'.json',  (data) => {
            console.log(data);
            client_hash = data.hash;
            console.log(client_hash);
            contract.methods.validateFreelancerByHash(client_hash).call().then (client_id => {
              console.log(client_id);
              drupalCall(root, 'user/'+expertid+'.json',  (doto) => {
                expert_hash = doto.hash;
                console.log(expert_hash);
                contract.methods.validateFreelancerByHash(expert_hash).call().then( expert_id => {
                  console.log(expert_id);
                  contract.methods.registeraclientrating(expert_id, ownerAccount, 100).send({from:client_id}).then( ()=>{return null;});
                  return null;
                });
              });
            });
          });
        });
  }

</script>
<?php       drupal_add_js('sites/all/modules/contrib/drupalservicejs/app.js', array('scope' => 'footer')); ?>
<?php if ($needs_wrapping_element): ?>
  </div>
<?php endif; ?>
