@api @watchdog
Feature: Challenge
  In order to test Challenge
  As a Client and an Expert
  I want to create a Challenge and test CRUD

  Background: Create challenge

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

    Given I give "client1" 3000 emh points

    Given "challenge" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Energy        | Avengers     | 1000         | client1 | Display my full name | Display the name      | Display                 |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "client1" row
    And I check the box "Creator member"
    And I press "Update membership"

  Scenario: An author can see its own challenge
    Given I am logged in as "client1"
    And I am on the homepage
    Then I should see "Avengers" in the "What about?" row

    When I go to "requests/manage"
    Then I should see "What about?"
    And I should see "1000" in the "What about?" row
    And I should see "Avengers" in the "What about?" row

  Scenario: An author can edit its own challenge
    Given I am logged in as "client1"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Challenge What about?" in the "title" region

    Given I enter "This is my challenge." for "Description"
    And I press "Save"
    Then I should see the success message "Challenge What about? has been updated."

  Scenario: An author cannot delete its own challenge
    Given I am logged in as "client1"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

  Scenario: Experts cannot see Answers tab
    Given I am logged in as "expert1"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    Then I should not see the link "Answers" in the "header" region
