@api @watchdog
Feature: Emails
  In order to test Emails moderations and notifications
  As a Webmaster, an Administrator, a Client and an Expert
  I want to create a Request, and receive email

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name           | mail                                   | roles         |
    | webmaster1     | emindhub.test+webmaster1@gmail.com     | webmaster     |
    | administrator1 | emindhub.test+administrator1@gmail.com | administrator |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency  |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678                  | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    | Real-time                     |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency  |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron           | MAN               | 0712345670                  | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy        | US                    | Real-time                     |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671                  | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Marvel Studios       | Employee             | Other         | US                    | Real-time                     |
    | expert3 | emindhub.test+expert3@gmail.com | expert   | Super            | DUPONT          | 0712345672                  | Modèle             | Avengers     | emindhub.test+expert3@gmail.com | Fluide Glacial       | Employee             | Energy         | FR                    | Real-time                     |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
      And I click "edit" in the "Captain AMERICA" row
      # TODO nasty bug, on "Update membership" there is a redirection with an encoded "?redirect=xxx"
      # that provoques an error visible on watchdog ONLY with a "Then I break"
      # 2nd bug : It is not displayed by @wathdog at the end of the test
      And I go to stripped URL
      And I select "Active" from "Status"
      And I press "Update membership"
      # Again...
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
    Then I should see "Active" in the "Captain AMERICA" row
    When I click "edit" in the "Iron MAN" row
      And I go to stripped URL
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
      And I click "edit" in the "Klark KENT" row
      And I go to stripped URL
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

  @email
  Scenario: Webmasters and Administrators are immediately notified, and after the delay, Experts are notified
    Given the test email system is enabled
    Given "request" content:
    | title                       | field_domaine | og_group_ref    | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers        | client1 | 2017-02-08 17:45:00    | 1       |

    # DON'T FORGET: drush @dev rules-enable _emh_request_notification_moderate_mail
    Then  the last email to "emindhub.test+webmaster1@gmail.com" should contain "Moderate this new request"
      And the last email to "emindhub.test+administrator1@gmail.com" should contain "Moderate this new request"

    # DON'T FORGET: drush @dev rules-enable _emh_request_notification_notify_mail
      # Uncomment to see that Behat checks if the email exists and returns 'Did not find expected message'
      # And the last email to "emindhub.test+expert1@gmail.com" should contain "Dear Iron,"

    # 1st Cron run to execute the scheduled notification action
    When I run cron
    # 2nd Cron run to process the notification queue
    When I run cron

    Then  the last email to "emindhub.test+expert1@gmail.com" should contain "Dear Iron,"
      And the email should contain "A new request for expertise has been published on eMindHub"
      And the last email to "emindhub.test+expert2@gmail.com" should contain "Dear Klark,"
      And the email should contain "A new request for expertise has been published on eMindHub"
      And the last email to "emindhub.test+client1@gmail.com" should not contain "published"

  @email
  Scenario: Only experts in french countries are notified by email for new request publication in french
    Given the test email system is enabled
    Given "request" content:
    | title                             | field_domaine | og_group_ref    | author  | field_expiration_date  | status  | language |
    | Comment devenir un super-heros ?  | Energy        | Avengers        | client1 | 2017-02-08 17:45:00    | 1       | fr       |

    # DON'T FORGET: drush @dev rules-enable _emh_request_notification_notify_mail
    # 1st Cron run to execute the scheduled notification action
    When I run cron
    # 2nd Cron run to process the notification queue
    When I run cron
    Then  the last email to "emindhub.test+expert1@gmail.com" should not contain "Dear Iron,"
      # Uncomment to see that Behat checks if the email exists and returns No active email (Exception)
      # And the email should contain "A new request for expertise has been published on eMindHub"
      And the last email to "emindhub.test+expert2@gmail.com" should not contain "Dear Klark,"
      # Uncomment to see that Behat checks if the email exists and returns No active email (Exception)
      # And the email should contain "A new request for expertise has been published on eMindHub"
      And the last email to "emindhub.test+expert3@gmail.com" should contain "Dear Super,"
      And the email should contain "A new request for expertise has been published on eMindHub"
      And the last email to "emindhub.test+client1@gmail.com" should not contain "published"
