@api
Feature: Create question and answers
  In order to test Question creation, and privacy of responses
  As a business client
  I want to create a question, and watch responses

  Background: Create questions
    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | password |
    | client1 | client1@emindhub.com | business | Captain          | America         | client1  |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | expert1  |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | expert2  |
    Given I give "client1" 300 emh points
    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about ? | Energy        | All experts  | 100          | client1 |

  #@exclude
  Scenario: test questions as business
    Given I am logged in as "client1"
    When I go to "my-requests"
    Then I should see "My request"
    And I should see "What about ?"
    And I should see "100" in the "What about ?" row
    And I should see "All experts" in the "What about ?" row

  #@exclude
  Scenario: test questions as admin
    Given I am logged in as a user with the "administrator" role
    And I go to "admin/content"
    Then I should see "What about ?"
    When I go to "domains/energy"
    Then I should see "What about ?"
#    When I go to "groups"
#    And I click on "All experts"
#    Then I should see "What about ?"

  #@exclude
  Scenario: respond from an expert
    Given I am logged in as "expert1"
    When I go to homepage
    Then I should see "What about ?"
    When I click "What about ?" in the "What about ?" row
    Then I should see "Answer the question"
    #Given I enter "Ma réponse" for "Subject"
    Given I enter "Je suis un expert" for "Public answer"
    And I press "Publish"
    #And I wait for AJAX to finish -> don't work, force reload
    When I go to homepage
    When I click "What about ?" in the "What about ?" row
    Then I should see "Responses"
    And I should see "Select best answers"
    #And I should see "Iron Man" in the "comment" region
    And I should see "Iron Man"
    #And I should see "Je suis un expert" in the "comment" region
    And I should see "Je suis un expert"

    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Iron Man"
    And I should see "Je suis un expert" in the "Iron Man" row
    And I should see "All experts" in the "Iron Man" row
    When I go to homepage
    And I click "What about ?" in the "What about ?" row
    Then I should not see "Answer the question"
    And I should see "Responses"
    And I should see "Iron Man"
    And I should see "Je suis un expert"

  Scenario: private response visibility
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about ?" in the "What about ?" row
    Then I should see "Private answer"
    Given I enter "Je suis un expert" for "Private answer"
    And I press "Publish"
    When I go to homepage
    When I click "What about ?" in the "What about ?" row
    Then I should see "Responses"
    And I should see "Je suis un expert"

    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about ?"
    Then I should see "Je suis un expert"

    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about ?"
    Then I should not see "Je suis un expert"
