@api @watchdog
Feature: Create Question and public answers
  In order to test Question creation, and privacy of public answers
  As a client and an expert
  I want to create a question, and watch public answers

  Background: Create questions

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |
    | Twitter   | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Twitter   | Employee  | Other         |

    Given I give "client1" 300 emh points

    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Energy        | Avengers     | 100          | client1 | Display my full name | Display the name      | Display                 |

    # An expert responds publicly to a question
    Given I am logged in as "expert1"
    When I go to homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    #Then I should see an "Answer visibility" radio form element

    Given I select the radio button "My answer will be visible by all experts"
    And I enter "I'm the best superhero in da world." for "Public answer"
    And I press "Publish"

  Scenario: An expert can see its own public answer
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "Iron Man"
    And I should see "I'm the best superhero in da world."

  Scenario: The author can see the public answer
    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Iron Man"
    And I should see "I'm the best superhero in da world." in the "Iron Man" row

    When I go to homepage
    Then I should see "1" in the "What about?" row

    When I click "What about?" in the "What about?" row
    #Then I should not see an "Answer visibility" radio form element
    And I should see "Answers"
    And I should see "Iron Man"
    And I should see "I'm the best superhero in da world."

  Scenario: An other expert can see the public answer
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "Iron Man"
    And I should see "I'm the best superhero in da world."

  Scenario: The expert can edit its own public answer
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "edit" in the "answers" region
    And I select the radio button "My answer will be visible by all experts"
    And I enter "I'm the REAL best superhero in da world." for "Public answer"
    And I press "Save"
    Then I should see "I'm the REAL best superhero in da world."

  Scenario: The author cannot edit a public answer
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see the link "edit" in the "answers" region

  @exclude
  Scenario: An other expert cannot edit a public answer
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see the link "edit" in the "answers" region

  Scenario: The expert cannot delete its own public answer
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see the link "Delete" in the "answers" region

  Scenario: The author cannot delete a public answer
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see the link "Delete" in the "answers" region

  Scenario: An other expert cannot delete a public answer
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see the link "Delete" in the "answers" region
