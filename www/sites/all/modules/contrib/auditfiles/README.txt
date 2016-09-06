CONTENTS
--------
 * Introduction
 * Reports
 * Buttons on the Reports
 * Limiting Features Explained
 * Troubleshooting
 * Maintainers


INTRODUCTION
------------
The Audit Files module allows for comparing and correcting files and file
references in the "files" directory, in the database, and in content. It is
designed to help keep the files on your server in sync with those used by your
Drupal site.

This module avoids using the Drupal API when dealing with the files and their
references, so that more or different problems are not created when attempting
to fix the existing ones.

The module does use the Drupal API (as much as possible) to reduce the load on
the server, including (but not necessarily limited to) paging the reports and
using the Batch API to perform the various operations.

Seven reports are included, and they can be accessed at Administer > Reports >
Audit Files (admin/reports/auditfiles).


REPORTS
-------

Not in database
---------------
This report lists the files that are on the server, but that are not in the
file_managed database table. These may be orphan files whose parent node has
been deleted, they may be the result of a module not tidying up after itself,
or they may be the result of uploading files outside of Drupal (e.g., via FTP).

From this report you can mark files for deletion. Be careful with the delete
feature on any report - the deletion is permanent - be sure the file is no
longer needed before erasing it!

You can also add one or more files to the file_managed table from this report.

Not on server
-------------
This report lists the files that are in the file_managed database table but
do not exist on the server. These missing files may mean that nodes do not
display as expected, for example, images may not display or downloads may not be
available.

You can also delete any items listed in the report from the database.

Managed not used
----------------
The files listed in this report are in the file_managed database table but not
in the file_usage table. Usually, this is normal and acceptable. This report
exists for completeness, so you may verify what is here is correct.

Used not managed
----------------
The files listed in this report are in the file_usage database table but not in
the file_managed table. Files listed here have had their Drupal management
removed, but are still being listed as used somewhere and may have content
referencing them.

You should verify the file's existence on the server and in the objects it is
listed as being used in, and either delete the reference in this report, or add
it to the file_managed table (which is a manual process, due to the fact that
the necessary data is not available to this module).

Used not referenced
-------------------
The files listed here are in the file_usage database table, but the content that
has the file field no longer contains the file reference.

The report lists both the file URI, so you can verify it still is a valid file,
and the file's usages, so you can see where it was being used. Both of those can
be used in determining what needs to happen with the reference.

Referenced not used
-------------------
Listed here are the file references in file fields attached to entities which do
not have a corresponding listing in the file_usage table.

What is listed in this report is the data of references themselves. This can be
used to determine what needs to happen with the reference.

References listed here can either be deleted from the database or added to the
file_usage table.

Merge file references
---------------------
This report lists all files listed in the file_managed, along with their usages,
grouped by file name. With it, you can merge duplicate file references into a
single one. This reduces records in the database and saves space on the file
system.


BUTTONS ON THE REPORTS
----------------------
At the tops of the reports, there might be one or more of the following buttons,
depending on how you have configured the module: "Load all files" and "Reset
file list".

Load all files
--------------
If the "Maximum records" field is not zero, this button will be displayed on the
reports. When it is pressed, the report is re-run using Drupal's Batch API, and
will load all records for the report.

Reset file list
---------------
If the "Maximum records" field is not zero, this button will be displayed on the
reports. When it is pressed, the variables used for controlling which set of
records and any saved records will be reset and the first page of the report
will be loaded anew.

At the bottoms of the reports, there will be one or both of the following
buttons, depending on the report: "Add selected..." and "Delete selected..."
(the text on these buttons is different on the various reports).

Add selected...
---------------
When there are items selected (checks in the check boxes) on the report and this
button is pressed, the items selected will be added to whatever it is that is
specified in the text of the button (a confirmation page is shown first). i.e.:
if the text of the button is "Add selected items to the database", then the
items will be added to the database.

Delete selected...
------------------
When there are items selected (checks in the check boxes) on the report and this
button is pressed, the items selected will be deleted from whatever it is the
text specifies on the button (a confirmation page is shown first). i.e.: if the
text of the button is "Delete selected items from the file_usage table", then
the items will be delete from the file_usage database table.


LIMITING FEATURES EXPLAINED
---------------------------
There are two administrative configuration settings that help with limiting the
records displayed, for when a report times out or exceeds the available memory.
They are: "Maximum records" and "Batch size" They are both found in the "Report
options" fieldset.

There are four possible combinations of these settings, one of which is invalid:
 1) Both set to zero: With these settings, all records are loaded and displayed.
 2) "Maximum records" set to some positive integer greater than zero and "Batch
    size" set to zero: With this combination, only the number of records in
    "Maximum records" will be initially loaded and displayed. At the top of the
    report page, there will be a button labeled "Load all records," with which
    you can load all records using Drupal's Batch API. This combination is also
    useful if you have a sizable number of records that take a while to display,
    but don't time out or exceed the memory limit, as it will allow a quicker
    initial load.
 3) "Maximum records" set to zero and "Batch size" set to some positive integer
    greater than zero: This combination is invalid, because if "Maximum records"
    is set to zero, it does not matter what "Batch size" is set to, because the
    records will never be loaded via the Batch API.
 4) Both set to some positive integer greater than zero: Sometimes, setting
    "Maximum records" and batch loading all the records isn't enough, and a
    report may still time out or exhaust the available memory. If that is the
    case, entering a positive integer in the "Batch size" setting will limit the
    batch operation and provide a paging mechanism for accessing the other
    records. To test if this will be helpful or not, set it to a lower number.
    If the report loads, then set it to a higher number to access more records
    per batch load operation. Since it is still using the Batch API, this number
    can be rather high, in an attempt to access as many records as possible.

For all options above, paging can be enabled with the "Number of items per page"
setting.


TROUBLESHOOTING
---------------
You receive the following error messages:
 * Warning: Unknown: POST Content-Length of [some number] bytes exceeds the
   limit of [some number] bytes in Unknown on line 0
 * Warning: Cannot modify header information - headers already sent in Unknown
   on line 0
 * (And a number of "Notice: Undefined index:..." messages.)
Set the "Maximum records" and "Batch size" settings on the Audit Files
administrative settings configuration page (admin/config/system/auditfiles), and
then use the "Load all records" button on the report that is producing the
error. See the "Limiting Features Explained" section above for more information.

You receive the following error messages:
 * Fatal error: Maximum execution time of [some number] seconds exceeded in
   [path to report file] on line [line number]
Set the "Maximum records" and "Batch size" settings on the Audit Files
administrative settings configuration page (admin/config/system/auditfiles), and
then use the "Load all records" button on the report that is producing the
error. See the Limiting Features Explained section above for more information.


MAINTAINERS
-----------
Current maintainers:
 * Andrey Andreev (andyceo) - https://www.drupal.org/user/152512
 * Jason Flatt (oadaeh) - https://www.drupal.org/user/4649

Previous maintainers:
 * Stuart Greenfield (Stuart Greenfield) - https://www.drupal.org/user/54866
