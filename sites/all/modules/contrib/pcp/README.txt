The PCP (Profile Percent Complete) module allows privileged users to tag profile
fields created through the profile module as fields needed for a users profile
to be 100% complete. The module checks these tagged fields against each user and
determines, based on what a user has successfully completed, the percentage that
has been complete.

INSTALL
==============================================
1. Download and extract the PCP module into your Drupal site.
2. Go to admin/build/modules and activate "Profile Complete Percentage" module.
3. Make sure you set up the desired profile fields in the profile module at
   admin/config/people/accounts/fields. You can also use the Profile2 module.
4. Go to admin/config/people/pcp and select the profile fields you want to use
   for completion then save.
5. Go to admin/build/block and place the "Profile Complete Percentage" block
   to your desired location.

After steps 1 - 5 of INSTALL are complete, you will see a basic block informing
you of how much your profile has been complete. All data is determined on the
fly so should you opt to activate or deactivate fields to be required in
admin/config/people/pcp the displayed data will adjust when the change has
been made.
