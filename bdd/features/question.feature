@api
Feature: Create question and answers
  In order to test Question creation, and privacy of responses
  As a business client
  I want to create a question, and watch responses

  Background: Create questions
    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name |
    | client1 | client1@emindhub.com | business | Captain          | America         |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             |
    Given I give "client1" 300 emh points
    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about ? | Energy        | All experts  | 100          | client1 |

  Scenario: test questions as business
    Given I am logged in as "client1"
    When I go to "my-demands"
    Then I should see "MY DEMANDS"
    And I should see "What about ?"
    And I should see "100" in the "What about ?" row
    And I should see "All experts" in the "What about ?" row


  Scenario: test questions as admin
    Given I am logged in as a user with the "administrator" role
    And I go to "admin/content"
    Then I should see "What about ?"
    When I go to "domains/energy"
    Then I should see "What about ?"
#    When I go to "groups"
#    And I click on "All experts"
#    Then I should see "What about ?"

  Scenario: respond from an expert
    Given I am logged in as "expert1"
    When I go to homepage
    Then I should see "What about ?"
    When I click "What about ?" in the "What about ?" row
    Then I should see "Answer the question"
    #Given I enter "Ma réponse" for "Subject"
    Given I enter "Je suis un expert" for "Public response"
    And I press "Publish"
    #Then I should see "Ma réponse"
    Then I should see "Je suis un expert"
    And I should see "Iron Man"
    Given I am logged in as "client1"
    When I go to "content/my-responses"
    #Then I break
    Then I should see "expert1"
    And I should see "(No subject)" in the "expert1" row
    And I should see "All experts" in the "expert1" row

