@api @watchdog
Feature: Mission and answers for Référent
  In order to test Mission CRUD and answers privacy
  As a Référent
  I want to manage a Mission, and watch answers

  Background: Create mission

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
    | référent1 | emindhub.test+referent1@gmail.com | référent | Paul          | Stanley         | 0612345678      | The Starchild     | Avengers     | emindhub.test+referent1@gmail.com | Amazon  | Other | Maintenance |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Twitter   | Employee  | Other         |

    Given I give "client1" 1000 emh points

    Given "webform" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Energy        | Avengers     | 1000         | client1 | Display my full name | Display the name      | Display                 |

    # Make référent1 as a Referent member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Paul Stanley" row
    And I check the box "Referent member"
    And I press "Update membership"
    Then I should see the success message "The membership has been updated."

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"
    Then I should see the success message "The membership has been updated."

    # A client publish a mission.
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
    Then I should see the success message "Mission What about? has been published."

    # An expert responds to the mission.
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

    # Another expert responds to the mission.
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

  Scenario: A référent can see the mission
    Given I am logged in as "référent1"
    When I go to homepage
    Then I should see "What about?" in the "What about?" row

  Scenario: A référent can edit a mission
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Mission What about?" in the "title" region

    Given I enter "This is your mission." for "Description"
    And I press "Save"
    Then I should see the success message "Mission What about? has been updated."

  Scenario: A référent cannot delete a mission
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

  Scenario: A référent cannot respond to a mission
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
    Then I should see "Select best answer(s)"
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
