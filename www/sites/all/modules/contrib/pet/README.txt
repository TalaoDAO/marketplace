Previewable Email Templates (PET)
=================================

The Previewable Email Template (PET) module lets users create email templates,
with token substitution, which can be previewed before sending. The emails can
be sent to one or many email addresses in a flexible way, and the recipients
may or may not be Drupal account holders (users).

Individual email sends can be customized per email send without affecting the
template, which makes one-off customization a breeze.

PET puts all your email templates in one place which makes for easy editing by 
your users, who don't have to go into the bowels of Rules to edit an email.

Emails can also be sent programmatically by you the developer.

PET stores templates in a db table, not the variables table, so there is none
of the memory usage which goes with the latter.

PETs are based on the Entity API, which means export, import, clone, code-based
defaults, etc are supported.

PET supports the Rules module, so email actions can be triggered by any Rule.

PET supports the MimeMail module for HTML emails.

Required Modules
================

- Entity API

Optional Modules
================

- Rules
- MimeMail

Installation
============
* Copy the pet directory to the modules folder in your installation.
* Go to the Modules page (/admin/modules) and enable it.

Template Management
===================
Manage (import, add, edit, clone, delete, export) the templates for your 
site from the Structure page (/admin/structure/pets). Users must have 
"administer previewable email templates" permission for this.
 
* Title (required) - A descriptive title for the template. For reference by PET
  administrators. Doesn't appear anywhere in the email itself.
 
* Name (required) - Machine name for the template. This is used if you refer to
  your template from code.
 
* Subject (required) - The email subject. May contain tokens for substitution.
 
* Body (optional but obviously common) - The email body. Like Subject, may 
  contain tokens.
 
* From override (optional) - An alternative From address for emails originating
  from this template. If not provided the site default is used.
 
* CC default (optional) - One or more emails to be cc'd on every email sent
  using this template.

* BCC default (optional) - One or more emails to be blind cc'd on every email
  sent using this template.
 
* Recipient callback (optional) - The name of a function which is called to
  retrieve a list of email recipients, if the uid argument is 0 (not missing,
  but the number 0) for an interactive send. This is a function that you 
  provide. If there is a nid argument, the node is loaded and passed to this 
  function.

Using PET Templates
===================

Once you've created a PET template, you can fire it a) interactively, b) via
code you write, or c) via Rules.

Interactive PETs
================

To send a PET interactively a user must have "use previewable email 
templates" permission. The best way to get a feel for the UI when sending when
doing interactive sends is to create a template (/admin/structure/pets/add),
then click the link of the PET Label at (/admin/structure/pets). A form will
appear with the template data, and clicking the Preview button will show the
email as it will be sent, along with token substitutions if any and markup.

Clicking back allows edits to be made for this particular send, without 
changing the stored template itself. When happy with the preview, click Send 
email(s) to send the email.

You the developer can include a link with the path "/pet/MY_PET_NAME" anywhere
you like on your site to give your users interactive access to a template.

Interactive PETs With Substitutions
===================================

In this simple form of the path above, with no arguments provided, the user
will be required to enter one or more email addresses. User token substitutions
(if present in the template) will be made for every email that has a 
corresponding user in the site. Global token substitutions will also be made.

You can provide a default user in the To field by including uid=[uid] in the 
query, e.g. 

 /pet/MY_PET_NAME?uid=17
 
This will provide token substitution for user 17. Additional email recipients 
can also be added to the form.

To invoke a PET for a custom list of users, specify "recipient_callback=true"
in the query, for example 

 /pet/MY_PET_NAME?recipient_callback=true
 
If the PET is set up to support user token substitution then for each email 
with a corresponding drupal user the substitution will take place.

To invoke a PET with node substitution, add the node id to the arguments, e.g.

 /pet/MY_PET_NAME?uid=17&nid=244

Token substitution will be done on both user 17 and node 244. Recipient 
callback could be used as well, as in 

 /pet/MY_PET_NAME?recipient_callback=true&nid=244

For example, let's say you manage events in your site, and you wish to send an
email to all registrants reminding them of the event date. The event info is
stored in node 348 and you have a function called event_registrants($event)
which, given an event node returns an array of registrant emails. Finally, the
name of the PET template is "event_reminder". The following path would provide
an interactive way to do this send:

 /pet/event_reminder?recipient_callback=true&nid=348

Firing PET Emails From Code
===========================

PET emails can also be sent from code anywhere in your site. You can do this in
response to whatever situation you have, and you have full control over the 
output. The authors of this module fire PETs programmatically in response to 
e-commerce purchases, class signups, event reminders, membership expirations, and
many other triggering events.

There are two functions available to programmers. See function pet_send_mail() 
for sending emails to multiple recipients. See function pet_send_one_mail() for 
sending email to a single recipient. These function headers contain further 
documentation.

Additional tokens can be provided via hook_pet_substitutions_alter(). 

Triggering PET Emails From Rules
================================

If you have Rules enabled on your site (admin/config/workflow/rules) you will
see the Rules action "Send PET mail" provided by the PET module. In the action
you choose the PET template to fire, along with either a) a fixed set of email
address(es) or a recipient user provided by the Rules event. You may also
choose a node for token substitutions.

MimeMail Integration
====================

For those wanting to send HTML email, PET supports the MimeMail module. When 
MimeMail is enabled, you will see additional options in the template edit form,
including a plain text email body, and a checkbox for sending plain text only.

If you leave the plain text body empty, MimeMail will perform its usual
conversion of markup to plain text using core's drupal_html_to_text(). If you
provide a plain text version of the email, it will be included in the multipart
mime email.

MimeMail also works for programmatic and Rules triggered sends.