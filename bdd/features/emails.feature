@api @watchdog
Feature: Emails
  In order to test Emails notifications
  As a Client and an Expert
  I want to create a Request, and receive email

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles  | field_first_name | field_last_name | og_user_node |
    | expert2 | emindhub.test+expert2@gmail.com | expert | Black            | WIDOW           | Avengers     |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency  |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678                  | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    | Real-time                     |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | 
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron           | MAN               | 0712345670                  | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy        | US                    |

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
      And I check the box "Creator member"
      And I press "Update membership"
      #Then I break   #to see the error go to watchdog
      # Again...
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
    Then I should see "Creator member" in the "Captain AMERICA" row
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
      And I click "edit" in the "Black WIDOW" row
      And I go to stripped URL
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."
    Given the test email system is enabled

  Scenario: Experts are notified by email for new request publication
    Given "request" content:
    | title                       | field_domaine | og_group_ref    | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers        | client1 | 2017-02-08 17:45:00    | 1       |
    When I run cron
    #DONT FORGET : drush @dev rules-enable rules_emh_request_send_notification_email 
    Then  the last email to "emindhub.test+expert1@gmail.com" should contain "Dear Iron,"
      And the email should contain "A new request for expertise has been published on eMindHub"
      And the last email to "emindhub.test+expert2@gmail.com" should contain "Dear Black,"
      And the email should contain "A new request for expertise has been published on eMindHub"
      And the last email to "emindhub.test+client1@gmail.com" should not contain "published"
