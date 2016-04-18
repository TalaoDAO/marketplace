This module can list all entries in the {variable} table that cause
unwanted PHP NOTICES such as:

  Notice: unserialize() [function.unserialize]: Error at offset 74 of 75 bytes in
  variable_initialize() (line 749 of /srv/www/<sitename>/includes/bootstrap.inc).

By knowing the offending variable name, the user can remove it from the
database, making the notice go away.


== INSTALLATION ==

Extract the module to sites/all/modules and enable it via the administrative
interface.


== USAGE ==

The module will display a status message in the Status Report, letting you
know which (if any) entries are causing a problem. You can also access it
directly at admin/reports/variablecheck
