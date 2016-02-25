@api
Feature: Create question and answers
  In order to test Question creation, and privacy of answers
  As a business client
  I want to create a question, and watch answers

  Background: Create questions

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

    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about?  | Energy        | Avengers     | 100          | client1 |

  Scenario: questions : test as business
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "Avengers" in the "What about?" row

    When I go to "my-requests"
    Then I should see "My request"
    And I should see "What about?"
    And I should see "100" in the "What about?" row
    And I should see "Avengers" in the "What about?" row

  Scenario: questions : test as admin
    Given I am logged in as a user with the "administrator" role
    And I go to "admin/content"
    Then I should see "What about?"

  Scenario: An expert responds publicly to a question.
    Given I am logged in as "expert1"
    When I go to homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    And I should see "Answer the question"
    Given I enter "I'm the best superhero in da world." for "Public answer"
    And I select the radio button "My answer will be visible by all experts"
    And I press "Publish"

    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "Iron Man"
    And I should see "I'm the best superhero in da world."

    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Iron Man"
    And I should see "I'm the best superhero in da world." in the "Iron Man" row

    When I go to homepage
    Then I should see "1" in the "What about?" row

    When I click "What about?" in the "What about?" row
    Then I should not see "Answer the question"
    And I should see "Answers"
    And I should see "Iron Man"
    And I should see "I'm the best superhero in da world."

    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "Iron Man"
    And I should see "I'm the best superhero in da world."

  Scenario: An expert responds privately to a question.
    Given I am logged in as "expert2"
    When I go to homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    And I should see "Answer the question"
    Given I enter "The truth is elsewhere." for "Private answer"
    And I select the radio button "My answer will be visible only by the client"
    And I press "Publish"

    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Klark Kent"
    And I should see "The truth is elsewhere." in the "Klark Kent" row

    When I go to homepage
    Then I should see "1" in the "What about?" row

    When I click "What about?" in the "What about?" row
    Then I should not see "Answer the question"
    And I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

    # Another expert cannot view the private answer
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Private answer from another expert."
    And I should not see "Klark Kent"
    And I should not see "The truth is elsewhere."
