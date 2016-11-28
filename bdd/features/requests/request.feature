@api @watchdog
Feature: Request
  In order to test Request creation
  As a Client and an Expert
  I want to create a Request, and watch submissions

  Background: Create request

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers  | emindhub.test+expert1@gmail.com | Marvel Studios     | Employee             | Energy          | US                    |


    Given the test email system is enabled
    # Make client1 as a Creator member of All experts circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
      And I click "edit" in the "Captain AMERICA" row
      Then I go to stripped URL
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
      And I click "edit" in the "Iron MAN" row
      Then I go to stripped URL
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    Given "request" content:
    | title                       | field_domaine | og_group_ref    | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2017-02-08 17:45:00    | 1       |
    Then I break

  Scenario: Experts are notified by email for new request publication
    #Given the email to "emindhub.test+expert1@gmail.com" should contain "A new request for expertise has been published on eMindHub"
    Then I run cron
    Then the last email should contain "Dear Super,"
      And the email should contain "A new request for expertise has been published on eMindHub"

  @exclude
  Scenario: An author can see its own request
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "All experts" in the "How to become a superhero?" row

  @exclude
  Scenario: An author can see its own request in My requests
    Given I am logged in as "client1"
    When I go to "requests/manage"
    Then I should see "How to become a superhero?"
      And I should see "All experts" in the "How to become a superhero?" row

  @exclude
  Scenario: An author can edit its own request
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I click "Edit" in the "primary tabs" region
      And I select "770" from "field_request_type[und]"
    Then I should see "Edit Request How to become a superhero?" in the "title" region

    Given I enter "This is my request." for "Describe your request"
      And I press "Save"
    Then I should see the success message "Request How to become a superhero? has been updated."

  @exclude
  Scenario: An author cannot delete its own request
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

  @exclude
  Scenario: A user can see some infos on a request without option
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should see "Captain" in the "request_right" region
      And I should not see "Captain AMERICA" in the "request_right" region
      And I should see "Marvel Studios" in the "request_right" region
