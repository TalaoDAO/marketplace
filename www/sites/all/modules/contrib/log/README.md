LOG
===

A general purpose record keeping system.

This module provides a new entity type called Log, which can be used for record
keeping. Log types can be defined with different fields.

The intended use is for record keeping, via manual or automatic entry. It is
not designed for system logging, although perhaps it would work.

Each log has a timestamp to indicate when the event took place (or when it will
take place). It also has a boolean "done" field for indicating whether or not
the task is done. Tasks can be automatically marked as done, or it can be a
manual reconciliation process (configurable on the log type level).

DEPENDENCIES
------------

This module depends on the following modules:

 * Date (http://drupal.org/project/date)
 * Entity API (http://drupal.org/project/entity)

INSTALLATION
------------

Install as you would normally install a contributed drupal module. See:
http://drupal.org/documentation/install/modules-themes/modules-7 for further
information.

MAINTAINERS
-----------

Current maintainers:
 * Michael Stenta (m.stenta) - https://drupal.org/user/581414