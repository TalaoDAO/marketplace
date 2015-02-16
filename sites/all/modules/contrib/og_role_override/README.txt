OG Role Override
================

This module provides Core permissions to act as particular OG roles in specific group types.

In other words, it creates permissions of the form 'Act as ROLE in GROUP-TYPE' for each role and each OG group type. Granting this permission to a Core role gives it the same permissions as that OG role, in all groups of that type.

For example, you might want users with your 'site editor' role to be able to act as a 'board member' in all OG groups, without having to add them to each group, and without having to replicate all the OG permissions as Core permissions.

Requirements
------------

- Organic Groups 7.x-2.3 or later

Instructions
------------

The OG setting 'Strict node access permissions' at admin/config/group/settings should be disabled, as when enabled only OG grants access to node creation, updating, and deletion.

1. At admin/config/group/permissions, identify the role(s) you want your users to be able to act as. Also note the group type (of the form 'Entity type - bundle').
2. At admin/people/permissions, grant permissions (under 'OG Role Override') for core roles to act in groups. Each group type has a permission for each of its roles.
