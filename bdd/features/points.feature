@api
Feature: Create question and answers
  In order to test Question creation, and privacy of responses
  As a business client
  I want to create a question, and watch responses

  Background: Create questions
    Given users:
    | name    | mail                 | roles    |
    | client1 | client1@emindhub.com | business |
    | expert1 | expert1@emindhub.com | expert   |
    | expert2 | expert2@emindhub.com | expert   |
    Given I give "client1" 300 emh points
    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about ? | Energy        | All experts  | 100          | client1 |

  Scenario: respond from an expert
    Then I should have 100 points on "What about ?" node

    Given I am logged in as "expert1"
    When I go to homepage
    When I click "What about ?" in the "What about ?" row
    Given I enter "Ma réponse" for "Subject"
    And I enter "Je suis un expert" for "Public response"
    And I press "Publish"

    Given I am logged in as "expert2"
    When I go to homepage
    When I click "What about ?" in the "What about ?" row
    Given I enter "Je réponds" for "Subject"
    And I enter "J'ai une idée" for "Public response"
    And I press "Publish"

    Given I am logged in as "client1"
    When I go to "content/my-responses"
    
