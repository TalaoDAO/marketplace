@api
Feature: Create question and answers
  In order to test Question creation, and privacy of answers
  As a business client
  I want to create a question, and watch answers

  Background: Create questions
    Given "circle" content:
    | title    | author  |
    | Avengers | client1 |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | password | og_user_node |
    | client1 | client1@emindhub.com | business | Captain          | America         | client1  | Avengers     |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | expert1  | Avengers     |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | expert2  | Avengers     |

    Given I give "client1" 300 emh points

    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about?  | Energy        | Avengers  | 100          | client1 |

  #@exclude
  Scenario: questions : test as business
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "Avengers" in the "What about?" row
    When I go to "my-requests"
    Then I should see "My request"
    And I should see "What about?"
    And I should see "100" in the "What about?" row
    And I should see "Avengers" in the "What about?" row

  #@exclude
  Scenario: questions : test as admin
    Given I am logged in as a user with the "administrator" role
    And I go to "admin/content"
    Then I should see "What about?"
    When I go to "domains/energy"
    Then I should see "What about?"

  #@exclude
  Scenario: An expert responds to a question.
    Given I am logged in as "expert1"
    When I go to homepage
    Then I should see "What about?"
    When I click "What about?" in the "What about?" row
    #Then I should not see "Answers" in the "title" region
    And I should see "Answer the question"
    Given I enter "I'm the best superhero in da world." for "Public answer"
    And I select the radio button "My answer will be visible by all experts"
    And I press "Publish"
    When I go to homepage
    When I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "Iron Man"
    And I should see "I'm the best superhero in da world."

    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Iron Man"
    And I should see "I'm the best superhero in da world." in the "Iron Man" row
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Answer the question"
    And I should see "Answers"
    And I should see "Iron Man"
    And I should see "I'm the best superhero in da world."

  #@exclude
  Scenario: Check question answers privacy
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    #Then I should not see "Answers" in the "title" region
    And I should see "Private answer"
    Given I enter "I'm the best superhero in da world." for "Private answer"
    And I select the radio button "My answer will be visible only by the client"
    And I press "Publish"
    When I go to homepage
    When I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "I'm the best superhero in da world."

    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?"
    Then I should see "I'm the best superhero in da world."
    And I should see "Iron Man"

    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?"
    Then I should not see "I'm the best superhero in da world."
    And I should not see "Iron Man"
