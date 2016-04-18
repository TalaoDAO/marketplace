CONTENTS OF THIS FILE
---------------------
 * Introduction
 * Getting started
 * Difference from legal
 * Requirements
 * Recommended modules

INTRODUCTION
------------
The Entity Legal module provides a solid, versionable, exportable and flexible
method of storing legal documents such as Terms and Conditions and Privacy
Policies. Users can be forced or soft-suggested to re-read and re-accept legal
documents when they change and a full audit trail of which user has accepted
when is available.

GETTING STARTED
---------------
 1. Enable the module.
 2. Visit admin/structure/legal
 3. Click 'Add'
 4. Fill in the document form and click Next.
 5. Create in the version form and click save.

CREATING A NEW VERSION AND FORCING USERS TO ACCEPT
--------------------------------------------------
 1. Visit the edit page for the document you've already created.
 2. Click the 'Add new version' action link at the top of the page.
 3. Fill in the form and click save.
 4. On the document form, select the radio next to the new version you've
    created in the 'Current version' section and click save.
 5. Users who have not accepted the new version will be forced to re-accept
    based on the settings you've chosen in the 'Existing users' fieldgroup.
 6. Only users who have not agreed to the current version will be prompted to
    re-accept. Reverting to a previous version will mean the users who have
    accepted that version before will not have to re-accept.
 7. All acceptances for all version are stored for each user, creating a new
    version is safe and will not cause you to lose any previous acceptances.

DIFFERENCE FROM LEGAL
---------------------
There are a few key difference from the Legal module:

 1. Support for more than one type of document on the site (eg Terms of Use as
    well as Privacy Policy and Terms and Conditions)..
 2. Entity API based and fully exportable using Features.
 3. Each document has custom settings as to whether users accept during sign-up
    and need to re-accept when a new version is created. Alternatively documents
    can live as static pages with no user interaction required.
 4. Provides an audit trail of which user accepted which version and what time.
 5. Comes loaded with different methods of notifying users of a document update
    including popup, drupal status message and full page redirection.
 6. Comes complete with a very high level of automated test coverage for each
    acceptance method and Entity type.
 7. Extensible, site administrators can create their own delivery methods using
    the modules API and because the entire module is written using Entity there
    are also many hooks provided by the Entity API that are provided.

REQUIREMENTS
------------
This module requires the following modules:
 * Entity API (https://www.drupal.org/project/entity)

RECOMMENDED MODULES
-------------------
This module requires the following modules:
 * Simpletest (simpletest):
   Core simpletest module for running module tests and extending to create your
   own tests when creating new methods.

MAINTAINERS
-----------
Current maintainers:
 * Marton Bodonyi (interactivejunky) - https://www.drupal.org/user/1633774
