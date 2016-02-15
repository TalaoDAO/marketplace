@api
Feature: Create challenge and answers
  In order to test challenge creation, and privacy of answers
  As a business client
  I want to create a question, and watch answers

  Background: Create challenge
    Given "circle" content:
    | title    | author  |
    | Avengers | client1 |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | password | og_user_node |
    | client1 | client1@emindhub.com | business | Captain          | America         | client1  | Avengers     |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | expert1  | Avengers     |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | expert2  | Avengers     |

    Given I give "client1" 300 emh points
    Given "challenge" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about?  | Energy        | Avengers  | 100          | client1 |

  Scenario: Check challenge answers privacy
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    #Then I should not see "Answers" in the "title" region
    Given I enter "I'm the best superhero in da world." for "Answer"
    And I press "Publish"
    When I go to homepage
    When I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "I'm the best superhero in da world."

    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?"
    Then I should see "I'm the best superhero in da world."

    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?"
    Then I should not see "I'm the best superhero in da world."

    Given I am logged in as "expert1"
    And I click "What about?"
    Then I should not see "Answers" in the "title" region
