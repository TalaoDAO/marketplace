@api @watchdog
Feature: Request and submissions
  In order to test Request with Anonymous option
  As a Client and an Expert
  I want to create a request, and watch author informations

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
    | name    | mail                            | roles    | field_first_name | field_last_name | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | Man             | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2017-02-08 17:45:00    |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"

  Scenario: The author choose to hide its name
    Given I am logged in as "client1"
    And I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit" in the "primary tabs" region
    Given I check "Anonymous"
    And I check "Hide my name"
    And I press "Save"
    Then I should see the success message "Request How to become a superhero? has been updated."

    Given I am logged in as "expert1"
    And I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see "Captain America"
    And I should see "Anonymous"

  Scenario: The author choose to hide its organisation
    Given I am logged in as "client1"
    And I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit" in the "primary tabs" region
    Given I check "Anonymous"
    And I check "Hide my organisation"
    And I press "Save"
    Then I should see the success message "Request How to become a superhero? has been updated."

    Given I am logged in as "expert1"
    And I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see "Google"

  Scenario: The author choose to hide its name & organisation and show its activity
    Given I am logged in as "client1"
    And I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit" in the "primary tabs" region
    Given I check "Anonymous"
    And I check "Hide my name"
    And I check "Hide my organisation"
    And I enter "ALMIGHTY GOD" for "You can precise your activity instead"
    And I press "Save"
    Then I should see the success message "Request How to become a superhero? has been updated."

    Given I am logged in as "expert1"
    And I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see "Captain America"
    Then I should not see "Google"
    Then I should see "ALMIGHTY GOD"
