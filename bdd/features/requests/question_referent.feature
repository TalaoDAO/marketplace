@api @watchdogi
Feature: Create Question and answers
  In order to test Question creation, and privacy of answers
  As référent
  I want to create a question, and watch answers

  Background: Create questions

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

    Given I give "client1" 300 emh points

    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Energy        | Avengers     | 100          | client1 | Display my full name | Display the name      | Display                 |

    # Make référent1 as a Referent member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "référent1" row
    And I check the box "Referent member"
    And I press "Update membership"

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

  Scenario: A référent can see the question
    Given I am logged in as "référent1"
    When I go to homepage
    Then I should see "What about?" in the "What about?" row

  Scenario: A référent can edit the question
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Question What about?" in the "title" region

    Given I enter "This is your question." for "Description"
    And I press "Save"
    Then I should see the success message "Question What about? has been updated."

  Scenario: A référent cannot delete the question
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

  Scenario: A référent cannot respond to the question
    Given I am logged in as "référent1"
    When I go to homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    #Then I should not see an "Answer visibility" radio form element

  Scenario: A référent can see the public answer
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    #Then I should not see an "Answer visibility" radio form element
    And I should see "Answers"
    And I should see "Iron Man"
    And I should see "I'm the best superhero in da world."

  Scenario: A référent cannot edit a public answer
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see the link "edit" in the "answers" region

  Scenario: A référent cannot delete a public answer
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see the link "Delete" in the "answers" region

  Scenario: A référent can see the private answer
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    #Then I should not see an "Answer visibility" radio form element
    And I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."
