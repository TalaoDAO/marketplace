@api @watchdog
Feature: Create Survey and answers
  In order to test Survey creation, and privacy of answers
  As client and expert
  I want to create a Survey, and watch answers

  Background: Create survey

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
    | client1 | client1@emindhub.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | client1@emindhub.com | Google  | Freelancer | Maintenance |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | expert1@emindhub.com | Facebook  | Employee  | Energy        |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | expert2@emindhub.com | Twitter   | Employee  | Other         |

    Given I give "client1" 1000 emh points

    Given "webform" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Energy        | Avengers     | 1000         | client1 | Display my full name | Display the name      | Display                 |

    # A client publish a survey.
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    And I click "Questions" in the "secondary tabs" region
    And I fill in "New question" with "How to become a superhero?"
    And I press "Add"
    And I press "Save your question"
    And I click "General infos" in the "secondary tabs" region
    And I press "Publish"
    Then I should see the success message "Survey What about? has been published."

    # An expert responds to the survey.
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I fill in "How to become a superhero?" with "Everybody can be, trust me."
    # Draft answer
    And I press "Save Draft"
    Then I should see the message "Your answer has been saved as draft."
    # Published answer
    When I click "Edit" in the "answer" region
    And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
    And I press "Publish my answer"
    Then I should see "Thank you, your answer has been sent."

    # Another expert responds to the survey.
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I fill in "How to become a superhero?" with "You have to read DC comics."
    # Draft answer
    And I press "Save Draft"
    Then I should see the message "Your answer has been saved as draft."
    # Published answer
    When I click "Edit" in the "answer" region
    And I fill in "How to become a superhero?" with "You have to read DC comics of course!"
    And I press "Publish my answer"
    Then I should see "Thank you, your answer has been sent."

  Scenario: An author can see its own survey
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "Avengers" in the "What about?" row

    When I go to "my-requests"
    Then I should see "What about?"
    And I should see "1000" in the "What about?" row
    And I should see "Avengers" in the "What about?" row

  Scenario: An author can edit its own survey
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Survey What about?" in the "title" region

    Given I enter "This is my survey." for "Description"
    And I press "Save"
    Then I should see the success message "Survey What about? has been updated."

  Scenario: An author cannot delete its own survey
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

  Scenario: An expert can see its own answer
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Your answer" in the "answers" region
    And I should see "You have to read DC comics of course!" in the "answers" region

  Scenario: The author can see the answers
    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Iron Man"
    And I should see "Klark Kent"

    When I go to homepage
    Then I should see "2" in the "What about?" row

    When I click "What about?" in the "What about?" row
    #Then I should not see an "Answer" textarea form element

    When I click "Answers" in the "primary tabs" region
    Then I should see "Select best answer(s)"
    And I should see "Iron Man"
    And I should see "Everybody can be, trust me, I'm the best we known."
    And I should see "Klark Kent"
    And I should see "You have to read DC comics of course!"

    When I click "Everybody can be, trust me, I'm the best we known."
    Then I should see "How to become a superhero?"
    And I should see "Everybody can be, trust me, I'm the best we known."

  Scenario: Experts cannot see Answers tab
    Given I am logged in as "expert1"
    When I go to homepage
    When I click "What about?" in the "What about?" row
    Then I should not see the link "Answers" in the "header" region

  Scenario: Another expert cannot see the answer
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I should not see "You have to read DC comics of course!" in the "answers" region

  Scenario: The expert cannot respond twice to the same survey
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Answer the survey" in the "answers" region

  Scenario: The expert can edit its own answer
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "answer" region
    And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we know."
    And I press "Save"
    Then I should see the success message "Your answer has been updated."

  Scenario: The author cannot edit an answer
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see the link "edit" in the "answers" region

  @exclude
  Scenario: The expert cannot delete its own answer
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "delete" in the "answers" region

  @exclude
  Scenario: The author cannot delete an answer
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "delete" in the "answers" region
