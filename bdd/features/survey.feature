@api
Feature: Create survey and answers
  In order to test survey creation, and privacy of answers
  As a business client
  I want to create a survey, and watch answers

  Background: Create survey

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

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | client1@emindhub.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | client1@emindhub.com | Google  | Independant | Maintenance |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | expert1@emindhub.com | Facebook  | Employee  | Energy        |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | expert2@emindhub.com | Twitter   | Employee  | Other         |

    Given I give "client1" 1000 emh points

    Given "webform" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | status |
    | What about?  | Energy        | Avengers     | 1000         | client1 | 0      |

  Scenario: Survey publication
    Given I am logged in as "client1"
    When I go to "/content/what-about"
    Then I click "Edit" in the "tabs_primary" region
    Then I click "Questions"
    When I fill in "New question" with "How to become a superhero?"
    And I press "Add"
    And I press "Save your question"
    And I click "General infos"
    When I select "Display my full name" from "Your name"
    And I select "Display the name" from "Your organisation"
    And I select "Display" from "Your activity"
    And I press "Publish"
    Then I should see the success message containing "has been published."

    # An expert responds to the survey.
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?"
    #Then I should not see "Answers" in the "title" region
    When I fill in "How to become a superhero?" with "Everybody can be, trust me."
    # Draft answer
    And I press "Save Draft"
    Then I should see "Your answer has been saved as draft."
    # Published answer
    When I click "Edit" in the "answer" region
    Then I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
    And I press "Publish my answer"
    Then I should see "Thank you, your answer has been sent."

    # An expert cannot respond twice to the same survey.
    When I go to homepage
    And I click "What about?"
    Then I should not see "Answer the survey"
    And I should see "Everybody can be, trust me, I'm the best we known."

    # But he can edit his own answer
    When I click "Edit" in the "answer" region
    Then I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we know."
    And I press "Save"
    Then I should see "Your answer has been updated."

    # The author checks the expert's answer.
    Given I am logged in as "client1"
    When I go to "/content/what-about"
    Then I click "Answers" in the "title" region
    Then I should see "Iron Man"
    When I click "Everybody can be, trust me, I'm the best we know."
    Then I should see "How to become a superhero?"
    And I should see "Everybody can be, trust me, I'm the best we know."
    When I click "Back to Answers"
    Then I should see "Select best answer(s)"
