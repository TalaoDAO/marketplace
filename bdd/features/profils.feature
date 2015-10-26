@api
Feature: Test profil visibility 
  In order to test profile visibility
  As a client with some experts
  I want check if profile is well displayed

  Background: Create questions and answers
    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas |
    | client1 | client1@emindhub.com | business | Captain          | America         | 0612345678      | Chef de groupe     |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | 0712345678      | Chieur génial      |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | 0812345678      | Modèle             |
    | expert3 | expert3@emindhub.com | expert   | Bruce            | Banner          | 0912345678      | Cogneur            |
    Given I give "client1" 300 emh points
    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about ? | Energy        | All experts  | 100          | client1 |

    Given I am logged in as "expert1"
    When I go to homepage
    When I click "What about ?" in the "What about ?" row
    Then I enter "Je suis un expert" for "Public answer"
    And I select the radio button "My answer will be public"
    And I press "Publish"

    Given I am logged in as "expert2"
    When I go to homepage
    When I click "What about ?" in the "What about ?" row
    Then I enter "J'ai une idée" for "Public answer"
    And I select the radio button "My answer will be public"
    And I press "Publish"

  #TODO: tel visibility not implemented yet
  #@exclude
  Scenario: Check visibility
    Then I should have 100 points on "What about ?" node
    Given I am logged in as "client1"
    When I go to "my-responses"
    When node "What about ?" transfers 50 points on "expert1" user
    And node "What about ?" transfers 50 points on "expert2" user
    Then I should have 0 points on "What about ?" node
    And I should have 50 points on "expert1" user
    And I should have 50 points on "expert2" user
    #When I click "My relationships"
    When I go to "my-relationships"
    #Then I should see "Operations"
    Then I should see "Iron"
    And I should see "Klark"
    And I should not see "Bruce"
    When I click "view" in the "Iron" row
    Then I should see "Iron Man"
    When I click "Make him my contact"
    Then I should see "Your cannot undo this action"
    When I go to "/users/expert1"
    Then I should see "Iron Man"
    And I should see "Chieur Génial"
    And I should see "0712345678"
    When I go to "/users/expert2"
    Then I should see "Klark Kent"
    And I should see "Modèle"
    And I should not see "0812345678"
    When I go to "/users/expert3"
    Then I should see "Bruce Banner"
    And I should not see "Cogneur"
    And I should not see "0912345678"
