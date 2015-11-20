@api
Feature: Create challenge and answers
  In order to test challenge creation, and privacy of answers
  As a business client
  I want to create a question, and watch answers

  Background: Create challenge
    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | password |
    | client1 | client1@emindhub.com | business | Captain          | America         | client1  |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | expert1  |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | expert2  |
    Given I give "client1" 300 emh points
    Given "challenge" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about ? | Energy        | All experts  | 100          | client1 |

  Scenario: challenge : private answer visibility
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about ?" in the "What about ?" row
    #Then I should see "Answer the challenge"
    Given I enter "Je suis un expert" for "Answer"
    And I press "Publish"
    When I go to homepage
    When I click "What about ?" in the "What about ?" row
    Then I should see "Answers"
    And I should see "Je suis un expert"

    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about ?"
    Then I should see "Je suis un expert"

    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about ?"
    Then I should not see "Je suis un expert"
