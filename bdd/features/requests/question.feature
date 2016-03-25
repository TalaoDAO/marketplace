@api @watchdog
Feature: Create Question and answers
  In order to test Question creation, and privacy of answers
  As client and expert
  I want to create a question, and watch answers

  Background: Create questions

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

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
    | Amazon    | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Twitter   | Employee  | Other         |

    Given I give "client1" 300 emh points

    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Energy        | Avengers     | 100         | client1 | Display my full name | Display the name      | Display                 |

    # An expert responds publicly to a question
    Given I am logged in as "expert1"
    When I go to homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    #Then I should see an "Answer visibility" radio form element

    Given I enter "I'm the best superhero in da world." for "Public answer"
    And I select the radio button "My answer will be visible by all experts"
    And I press "Publish"

    # An expert responds privately to a question
    Given I am logged in as "expert2"
    When I go to homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    And I should see "Answer the question"
    Given I enter "The truth is elsewhere." for "Private answer"
    And I select the radio button "My answer will be visible only by the client"
    And I press "Publish"

  Scenario: An author can see its own question
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "Avengers" in the "What about?" row

    When I go to "my-requests"
    Then I should see "What about?"
    And I should see "100" in the "What about?" row
    And I should see "Avengers" in the "What about?" row

  Scenario: An author can edit its own question
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Question What about?" in the "title" region

    Given I enter "This is my question." for "Description"
    And I press "Save"
    Then I should see the success message "Question What about? has been updated."

  Scenario: An author cannot delete its own question
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

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

  Scenario: Experts cannot see Answers tab
    Given I am logged in as "expert1"
    When I go to homepage
    When I click "What about?" in the "What about?" row
    Then I should not see the link "Answers" in the "header" region

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
    And I enter "I'm the REAL best superhero in da world." for "Public answer"
    And I select the radio button "My answer will be visible by all experts"
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

  Scenario: An expert can see its own private answer
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

  Scenario: The author can see the private answer
    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Klark Kent"
    And I should see "The truth is elsewhere." in the "Klark Kent" row

    When I go to homepage
    Then I should see "1" in the "What about?" row

    When I click "What about?" in the "What about?" row
    #Then I should not see an "Answer visibility" radio form element
    And I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

  Scenario: An other expert cannot see the private answer
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Private answer from another expert."
    And I should not see "Klark Kent"
    And I should not see "The truth is elsewhere."

  Scenario: The expert can edit its own private answer
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "edit" in the "answers" region
    And I enter "The truth is here." for "Public answer"
    And I select the radio button "My answer will be visible only by the client"
    And I press "Save"
    Then I should see "The truth is here."
