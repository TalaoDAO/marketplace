@api @watchdog
Feature: Create Question
  In order to test Question
  As a client and an expert
  I want to create a question and test CRUD

  Background: Create questions

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

    Given I give "client1" 300 emh points

    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Energy        | Avengers     | 100          | client1 | Display my full name | Display the name      | Display                 |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "client1" row
    And I check the box "Creator member"
    And I press "Update membership"

  Scenario: An author can see its own question
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "Avengers" in the "What about?" row

    When I go to "my-requests"
    Then I should see "What about?"
    And I should see "100" in the "What about?" row
    And I should see "Avengers" in the "What about?" row

  Scenario: An author can edit its own question
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Question What about?" in the "title" region

    Given I enter "This is my question." for "Description"
    And I press "Save"
    Then I should see the success message "Question What about? has been updated."

  Scenario: An author cannot delete its own question
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

  Scenario: Experts cannot see Answers tab
    Given I am logged in as "expert1"
    When I go to homepage
    When I click "What about?" in the "What about?" row
    Then I should not see the link "Answers" in the "header" region
