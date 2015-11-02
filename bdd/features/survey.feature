@api
Feature: Create survey and answers
  In order to test survey creation, and privacy of responses
  As a business client
  I want to create a survey, and watch responses

  Background: Create survey
    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | password |
    | client1 | client1@emindhub.com | business | Captain          | America         | client1  |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | expert1  |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | expert2  |
    Given I give "client1" 1000 emh points
    Given "webform" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | status |
    | What about ? | Energy        | All experts  | 1000         | client1 | 1      |

  Scenario: survey response
    Given I am logged in as "client1"
    When I go to "/content/what-about"
    Then I click "Edit your questions"
    When I fill in "New question name" with "First question"
    And I press "Add"
    And I press "Save your question"
    And I click "Publish your survey"
    And I click "Edit"
    When I select "Display my full name" from "Your name"
    And I select "Display the name" from "Your organisation"
    And I select "Display" from "Your activity"
    And I press "Save and continue" 
    #Then show me the HTML page
    Then I should see the success message containing "has been updated."

    Given I am logged in as "expert1"
    And I click "What about ?"
    Then I fill in "First question" with "My response"
    And I press "Submit my answer"
    #Then I break
