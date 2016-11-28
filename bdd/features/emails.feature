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
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678                  | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency  |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670                  | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy        | US                    | Real-time                     |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
      And I click "edit" in the "Captain AMERICA" row
      And I select "Active" from "Status"
      And I check the box "Creator member"
      And I press "Update membership"
      # Again...
      And I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
    Then I should see "Creator member" in the "Captain AMERICA" row
    Given I click "edit" in the "Iron MAN" row
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    Given the test email system is enabled

    Given "request" content:
    | title                       | field_domaine | og_group_ref    | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers        | client1 | 2017-02-08 17:45:00    | 1       |

  @exclude
  Scenario: Experts are notified by email for new request publication
    Given I run cron
    Then the last email should contain "Dear Iron,"
      And the email should contain "A new request for expertise has been published on eMindHub"
