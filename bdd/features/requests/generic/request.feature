@api @watchdog
Feature: Request
  In order to test Request creation
  As a Client and an Expert
  I want to create a Request, and watch answers

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |

    #Given I give "client1" 1000 emh points

    Given "request" content:
    | title        | field_domaine | og_group_ref | author  |
    | How to become a superhero?  | Energy        | Avengers     | client1 |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"

  Scenario: An author can see its own request
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "Avengers" in the "How to become a superhero?" row

  Scenario: An author can see its own request in My requests
    Given I am logged in as "client1"
    When I go to "requests/manage"
    Then I should see "How to become a superhero?"
    And I should see "Avengers" in the "How to become a superhero?" row

  Scenario: An author can edit its own request
    Given I am logged in as "client1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Request How to become a superhero?" in the "title" region

    Given I enter "This is my request." for "Description"
    And I press "Save"
    Then I should see the success message "Request How to become a superhero? has been updated."

  Scenario: An author cannot delete its own request
    Given I am logged in as "client1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

  Scenario: Experts cannot see Answers tab
    Given I am logged in as "expert1"
    When I go to homepage
    When I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see the link "Answers" in the "header" region
