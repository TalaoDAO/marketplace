@api
Feature: Create challenge and answers
  In order to test challenge creation, and privacy of answers
  As a business client
  I want to create a question, and watch answers

  Background: Create challenge

    Given "circle" content:
    | title    | author  |
    | Avengers | client1 |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Apple     | admin   |
    | Facebook  | admin   |
    | Twitter   | admin   |
    | Pinterest | admin   |
    | Viadeo    | admin   |
    | Linkedin  | admin   |
    | Tumblr    | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | client1@emindhub.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | client1@emindhub.com | Google  | Freelancer | Maintenance |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | expert1@emindhub.com | Facebook  | Employee  | Energy        |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | expert2@emindhub.com | Twitter   | Employee  | Other         |

    Given I give "client1" 300 emh points
    Given "challenge" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about?  | Energy        | Avengers     | 100          | client1 |

  Scenario: Check challenge answers privacy
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I enter "I'm the best superhero in da world." for "Answer"
    And I press "Publish"
    And I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "I'm the best superhero in da world."

    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "I'm the best superhero in da world."

    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "I'm the best superhero in da world."

    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Answers" in the "title" region
