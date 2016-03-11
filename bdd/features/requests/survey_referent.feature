@api
Feature: Create Survey and answers
  In order to test Survey creation, and privacy of answers
  As référent
  I want to create a Survey, and watch answers

  Background: Create survey

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |
    | Twitter   | admin   |
    | Amazon    | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | référent1 | referent1@emindhub.com | référent | Paul          | Stanley         | 0612345678      | The Starchild     | Avengers     | referent1@emindhub.com | Amazon  | Other | Maintenance |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | client1@emindhub.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | client1@emindhub.com | Google  | Freelancer | Maintenance |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | expert1@emindhub.com | Facebook  | Employee  | Energy        |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | expert2@emindhub.com | Twitter   | Employee  | Other         |

    Given I give "client1" 1000 emh points

    Given "webform" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Energy        | Avengers     | 1000         | client1 | Display my full name | Display the name      | Display                 |

    # Make référent1 as a Referent member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "référent1" row
    And I check the box "Referent member"
    And I press "Update membership"

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

  Scenario: A référent can see the survey
    Given I am logged in as "référent1"
    When I go to homepage
    Then I should see "What about?" in the "What about?" row

  Scenario: A référent can edit a survey
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Survey What about?" in the "title" region

    Given I enter "This is your survey." for "Description"
    And I press "Save"
    Then I should see the success message "Survey What about? has been updated."

  Scenario: A référent cannot delete a survey
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

  Scenario: A référent cannot respond to a survey
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    #Then I should not see an "Answer" textarea form element

  Scenario: A référent can see the answers
    Given I am logged in as "référent1"
    When I go to homepage
    Then I should see "2" in the "What about?" row

    When I click "What about?" in the "What about?" row
    #Then I should not see an "Answer" textarea form element

    When I click "Answers" in the "primary tabs" region
    Then I should not see "Select best answer(s)"
    And I should see "Iron Man"
    And I should see "Everybody can be, trust me, I'm the best we known."
    And I should see "Klark Kent"
    And I should see "You have to read DC comics of course!"

    When I click "Everybody can be, trust me, I'm the best we known."
    Then I should see "How to become a superhero?"
    And I should see "Everybody can be, trust me, I'm the best we known."

  Scenario: A référent cannot edit an answer
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see the link "edit" in the "answers" region

  @exclude
  Scenario: A référent cannot delete an answer
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "delete" in the "answers" region
