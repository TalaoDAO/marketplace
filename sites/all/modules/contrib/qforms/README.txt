
Description
-----------

Qforms or 'Quick Forms' enables users of your site to create custom forms like
surveys, questionnaires, contact/request/register forms...

When enabled this module will create qform content type on your site. Users
with correct permission can then create new qform content and in form builder
sections can add custom form elements and configure additional form submit
actions.
Then users with permission to submit qform can submit them. Submissions are
saved in a database table and can optionally be mailed to a multiple email
address upon submission.
Past submissions are viewable for users with the correct permissions.

Qforms includes simple reporting tools and is also capable of exporting
submitted data to a csv file for detailed statistical calculations.

Qforms module is similar to webform module but it is much lighter then webform
and is much simpler for using. The main idea behind qforms module is to keep it
simple for the end user. That also means that qforms will never grown into a
complex and big module that is difficult to use & administer. Instead, qforms
offers to the developers pluggable architecture so other modules can easily add
new form element definitions. Also qforms module use node API and Drupal Form
API which is another way to alter qforms behaviors with appropriate Drupal
hooks.


Features
--------

- Main feature of qforms is very easy custom forms creation process. Complex
  forms can be created in less then a minute.
- Core qforms form elements:
  - Text field,
  - Text area,
  - Select field (single/multiple),
  - Check-box group,
  - Radio group,
- Possibility to add custom submit actions to every qform form:
  - Custom 'thank you' message,
  - Redirection to custom site page,
  - Notification of new submissions over email.
- Other qform configurations are
  - Enable/disable qform or individual qform element.
- Report page of all submissions for a given qform. Also detail view of single
  submission data.
- Export of submitted data to csv file.
- Pluggable architecture so other modules can add new qforms element
  definitions. New elements definitions are added with hook_qforms()
  implementation.


Requirements
------------

Qforms dynamic form creation should work on every modern web browser with
javascript support (including IE6). You will not be able to create forms if
javascript is disabled in your browser.


Installation
------------

- Download and unpack module as usual.
- Optionally, you can use jquery.scrollTo-min.js for nice scrolling effects
  when adding new fields in qforms. Download it from
  http://flesler-plugins.googlecode.com/files/jquery.scrollTo-1.4.2-min.js and
  save it into qforms js folder, for example
  sites/all/modules/qforms/js/jquery.scrollTo-min.js
- Enable qforms module.


Configuration
-------------

- Visit Drupal permissions page and configure qform content type
  permissions as needed:
  - "Qform: Create new content" permissions gives user ability to create
    new forms.
  - "Qform: Edit own content" gives form author permission to
    view/delete/export submitted results.
  - "Qform: Delete own content" gives form author permission to delete
    form and all submitted data.
  - "View and submit qform" gives other users permission to view and submit
    qform.


Plans for the future
--------------------

Check http://drupal.org/node/1087734


Authors
-------

Current maintainers:
- Puljic Ivica 'pivica' <http://drupal.org/user/41070>
