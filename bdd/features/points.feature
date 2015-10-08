@api
Feature: Create question and answers
  In order to test Question creation, and privacy of responses
  As a business client
  I want to create a question, and watch responses

  Background: Create questions and answers
    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name |
    | client1 | client1@emindhub.com | business | Captain          | America         |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            |
    Given I give "client1" 300 emh points
    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about ? | Energy        | All experts  | 100          | client1 |

    Given I am logged in as "expert1"
    When I go to homepage
    When I click "What about ?" in the "What about ?" row
    Then I enter "Je suis un expert" for "Public response"
    And I press "Publish"

    Given I am logged in as "expert2"
    When I go to homepage
    When I click "What about ?" in the "What about ?" row
    Then I enter "J'ai une idée" for "Public response"
    And I press "Publish"

  @exclude
  Scenario: Manual arrange of points
    Then I should have 100 points on "What about ?" node
    Given I am logged in as "client1"
    When I go to "content/my-responses"
    Then I should see "expert1"
    And I should see "expert2"
    Then node "What about ?" transfers 50 points on "expert1" user
    Then node "What about ?" transfers 50 points on "expert2" user
    Then I should have 0 points on "What about ?" node

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/points/transaction-log"
    Then I should see "Move points from Captain America to question1 What about ?."
    And I should see "Move points from question1 What about ? to Iron Man. "
    And I should see "Move points from question1 What about ? to Klark Kent. "

  Scenario: VBO arrange of points
    Then I should have 100 points on "What about ?" node
    Given I am logged in as "client1"
    When I go to "content/my-responses"
    Then I should see "expert1"
    And I should see "expert2"

    When I go to "homepage"
    And I click "What about ?" in the "What about ?" row
    Then I should see "2 responses"
    #Then I break
    #Then I click "2 responses"
    Then I click "Choose winners"
    And I should see "Operations"
    #When I check  "views_bulk_operations[0]"
    #When I check the box 1
    When I check the box "edit-views-bulk-operations-0"
    And I check the box "edit-views-bulk-operations-1"
    And I press "Distribute points"
    Then I should see "Points for Iron Man"
    And I should see "Points for Klark Kent"
    When I fill in "Points for Iron Man" with 50
    And I fill in "Points for Klark Kent" with 50
    And I click "Arrange points"
    #Then I should see the success message( containing) "Arranged" 
    Then I should have 0 points on "What about ?" node

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/points/transaction-log"
    Then I should see "Move points from Captain America to question1 What about ?."
    And I should see "Move points from question1 What about ? to Iron Man. "
    And I should see "Move points from question1 What about ? to Klark Kent. "

    #Then I break

