@api
Feature: Create survey and answers
  In order to test survey creation, and privacy of answers
  As a business client
  I want to create a survey, and watch answers

  Background: Create survey
    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | password |
    | client1 | client1@emindhub.com | business | Captain          | America         | client1  |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | expert1  |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | expert2  |
    Given I give "client1" 1000 emh points
    Given "webform" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | status |
    | What about?  | Energy        | All experts  | 1000         | client1 | 0      |

  Scenario: Survey publication
    Given I am logged in as "client1"
    When I go to "/content/what-about"
    Then I click "Edit" in the "tabs_primary" region
    Then I click "Questions"
    When I fill in "New question" with "How to become a superhero?"
    And I press "Add"
    And I press "Save your question"
    And I click "General infos"
    When I select "Display my full name" from "Your name"
    And I select "Display the name" from "Your organisation"
    And I select "Display" from "Your activity"
    And I press "Publish"
    Then I should see the success message containing "has been published."

    # An expert respond to the survey.
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?"
    Then I should not see "Answers" in the "title" region
    And I fill in "How to become a superhero?" with "Everybody can be, trust me."
    And I press "Submit"
    Then I should see "Thank you, your answer has been sent."

    # The author check the expert's answer.
    Given I am logged in as "client1"
    When I go to "/content/what-about"
    Then I click "Answers" in the "title" region
    Then I should see "Iron Man"
    And I click "Everybody can be, trust me."
    Then I should see "How to become a superhero?"
    And I should see "Everybody can be, trust me."
    Then I click "Back to Answers"
    And I should see "Select best answer(s)"
