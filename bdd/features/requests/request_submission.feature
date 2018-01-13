@api @watchdog
Feature: Request and answers
  In order to test Request answers
  As a Client and an Expert
  I want to create answers, and watch answers

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Aviation |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_position          |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Blockchain        | Avionic Design Engineer |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Marvel Studios       | Employee             | Space         | C.E.O.                  |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Blockchain        | Avengers     | client1 | 2020-02-08 17:45:00    | 1       |

    Given the user "client1" is a member of the group "Avengers"
    Given the user "expert1" is a member of the group "Avengers"
    Given the user "expert2" is a member of the group "Avengers"

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."

    # Draft answer
      And I press "Save Draft"
    Then I should see the message "Your answer has been saved as draft."

    # Published answer
    When I press "Publish"
    Then I should see the message "Your answer has been published."

    # Another expert responds to the request (draft).
    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "You have to read DC comics of course!"
    # Draft answer
      And I press "Save Draft"
    Then I should see the message "Your answer has been saved as draft."

  Scenario: An expert can see its own published answer
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "Everybody can be, trust me, I'm the best we known." in the "submissions" region
      And I should see "1 answer" in the "user_submission_count" region

  Scenario: An expert can see its own draft answer
    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "You have to read DC comics of course!" in the "user_submission" region
      And I should see "1 answer" in the "user_submission_count" region

  Scenario: An expert of the same circle can see the published answer
    Given I am logged in as "expert2"
    When I go to homepage
    Then I should see "1" in the "content" region

    When I click "How to become a superhero?" in the "content" region
    Then I should see "Everybody can be, trust me, I'm the best we known." in the "submissions" region
      And I should see "1 answer" in the "user_submission_count" region

    When I click "view" in the "submissions" region
    Then I should see "Everybody can be, trust me, I'm the best we known."

  Scenario: The author can see the published answers but not the draft ones
    Given I am logged in as "client1"
    When I go to "answers/to-me"
    Then I should see "Iron MAN"
      And I should not see "Klark KENT"

    When I go to homepage
    Then I should see "1" in the "content" region

    When I click "How to become a superhero?" in the "content" region
    Then I should see "Iron MAN" in the "submissions" region
      And I should see "Everybody can be, trust me, I'm the best we known." in the "submissions" region
      And I should see "1 answer" in the "user_submission_count" region
      And I should not see "Klark KENT" in the "submissions" region
      And I should not see "You have to read DC comics of course!" in the "submissions" region

    When I click "view" in the "submissions" region
    Then I should see "Everybody can be, trust me, I'm the best we known."

  Scenario: The request author can mark published answers as interesting and only the expert who answered can see the flag
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "Select the answer" link or button

    When I click "view" in the "submissions" region
      And I click link "Select the answer"
    Then I should see "Answer selected"

    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "Answer selected" in the "submissions" region
      And I should not see "Select the answer" link or button

    When I click "view" in the "submissions" region
    Then I should see "Answer selected" in the "block_system_main" region
      And I should not see "Select the answer" link or button

    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should not see "Select the answer" in the "submissions" region
      And I should not see "Select the answer" link or button

    When I click "view" in the "submissions" region
    Then I should not see "Select the answer" in the "block_system_main" region
      And I should not see "Select the answer" link or button

  Scenario: The author can add a feedback to published answers and only the expert who answered can see the feedback
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "Leave a feedback for the expert" link or button

    When I click "view" in the "submissions" region
      And I click link "Leave a feedback for the expert"
      And I fill in "Awesome answer!" for "field_comment_answer[und][0][value]"
      And I press the "Confirm" button
    Then I should see "Thank you for leaving a feedback to the expert!"
      And I should see "Awesome answer!" in the "block_system_main" region

    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "Awesome answer!" in the "submissions" region
      And I should not see "Leave a feedback for the expert" link or button

    When I click "view" in the "submissions" region
    Then I should see "Awesome answer!" in the "block_system_main" region
      And I should not see "Leave a feedback for the expert" link or button

    When I go to "answers/my"
    Then I should see "Awesome answer!" in the "block_system_main" region
      And I should not see "Leave a feedback for the expert" link or button

    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should not see "Awesome answer!" in the "submissions" region
      And I should not see "Leave a feedback for the expert" link or button

    When I click "view" in the "submissions" region
    Then I should not see "Awesome answer!" in the "block_system_main" region
      And I should not see "Leave a feedback for the expert" link or button

  @exclude
  Scenario: The expert cannot respond twice to the same request
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    #Then I should not see "Publish" in the "user_submission_form" region

  Scenario: The expert can edit its own answer
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "user_submission" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we know."
      And I press "Save"
    Then I should see the success message "Your answer has been updated."

  @exclude
  Scenario: The author cannot edit an answer
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should not see the link "edit" in the "submissions" region

  @exclude
  Scenario: The expert cannot delete its own answer
    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should not see the link "delete" in the "user_submission" region
      And I should not see the link "delete" in the "submissions" region

  @exclude
  Scenario: The author cannot delete an answer
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should not see the link "delete" in the "submissions" region

  Scenario: Only the Circle Admin can unpublish an answer (but cannot edit values)
    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_position          |
    | expert3 | emindhub.test+expert3@gmail.com | expert   | Super            | DUPONT          | 0712345672                  | Modèle           | Avengers     | emindhub.test+expert3@gmail.com | Fluide Glacial       | Employee             | Blockchain        | Avionic Design Engineer |

    Given I am logged in as a user with the "administrator" role

    When I go to "content/avengers"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
      And I click "edit" in the "Super DUPONT" row
      And I select "Member" from "Status"
      And I check the box "administrator member"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    Given I am logged in as "expert3"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "view" in the "submissions" region
      And I click "Edit" in the "primary tabs" region
    Then the "How to become a superhero?" field should be disabled

    When I press "Unpublish"
    Then I should see "The answer has been unpublished."

    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should not see "Everybody can be, trust me, I'm the best we known." in the "submissions" region
      And I should see "No answer" in the "user_submission_count" region

    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should not see "Everybody can be, trust me, I'm the best we known." in the "submissions" region
      And I should see "No answer" in the "user_submission_count" region

    When I go to "requests/manage"
    Then I should not see "Everybody can be, trust me, I'm the best we known."

    Given I am logged in as "expert1"
    When I go to "answers/my"
    Then I should see "draft" in the "content" region

    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "Draft" in the "user_submission" region
