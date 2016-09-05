@api @watchdog
Feature: Request and submissions
  In order to test Request with Duration option
  As a Client and an Expert
  I want to create a request, and watch Duration informations

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |
    | Twitter   | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2017-02-08 17:45:00    | 0       |

    Given I give "client1" 10000 emh points

    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "edit" in the "Captain AMERICA" row
      And I check the box "Creator member"
      And I press "Update membership"
    Then I should see "Creator member" in the "Captain AMERICA" row

    # Activate option
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I click "Edit" in the "primary tabs" region
    Given I check "Duration"
      And I enter "6 months" for "Duration of the mission"
      And I enter "07/06/2017" for "Date"
      And I press "Continue"
    # Validation page
      And I press "Publish"
    Then I should see the success message "Request How to become a superhero? has been published."

  Scenario: The author can see Duration option infos
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should see "6 months"
      And I should see "2017/07/06"

  Scenario: An expert can see Duration option infos
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should see "6 months"
      And I should see "2017/07/06"
