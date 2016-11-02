@api @watchdog
Feature: Request and submissions
  In order to test Request submissions
  As a Client and an Expert
  I want to create submissions, and watch submissions

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_position          |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy        | Avionic Design Engineer |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Marvel Studios       | Employee             | Other         | C.E.O.                  |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2017-02-08 17:45:00    | 1       | Other              |

    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "edit" in the "Captain AMERICA" row
      And I select "Active" from "Status"
      And I check the box "Creator member"
      And I press "Update membership"
    Then I should see "Creator member" in the "Captain AMERICA" row
    Then I should see "The membership has been updated."
      And I click "edit" in the "Iron MAN" row
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."
      And I click "edit" in the "Klark KENT" row
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."

    # Draft submission
      And I press "Save Draft"
    Then I should see the message "Your submission has been saved as draft."

    # Published submission
    When I press "Publish"
    Then I should see the message "Your submission has been published."

    # Another expert responds to the request (draft).
    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I fill in "How to become a superhero?" with "You have to read DC comics of course!"
    # Draft submission
      And I press "Save Draft"
    Then I should see the message "Your submission has been saved as draft."

  Scenario: An expert can see its own submission
    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should see "You have to read DC comics of course!" in the "user_submission" region
      And I should see "1" in the "user_submission_count" region

  Scenario: An expert of the same circle can see the published submission
    Given I am logged in as "expert1"
    When I go to homepage
    Then I should see "1" in the "How to become a superhero?" row

    When I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should see "Everybody can be, trust me, I'm the best we known." in the "submissions" region
      And I should see "1" in the "user_submission_count" region

    When I click "view" in the "submissions" region
    Then I should see "Everybody can be, trust me, I'm the best we known."

  Scenario: The author can see the published submissions but not the draft ones
    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Iron MAN"
      And I should not see "Klark KENT"

    When I go to homepage
    Then I should see "1" in the "How to become a superhero?" row

    When I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should see "Iron MAN" in the "submissions" region
      And I should see "Everybody can be, trust me, I'm the best we known." in the "submissions" region
      And I should see "1" in the "user_submission_count" region
      And I should not see "Klark KENT" in the "submissions" region
      And I should not see "You have to read DC comics of course!" in the "submissions" region

    When I click "view" in the "submissions" region
    Then I should see "Everybody can be, trust me, I'm the best we known."

  @exclude
  Scenario: The expert cannot respond twice to the same request
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
    #Then I should not see "Publish" in the "user_submission_form" region

  Scenario: The expert can edit its own submission
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I click "Edit" in the "user_submission" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we know."
      And I press "Save"
    Then I should see the success message "Your submission has been updated."

  @exclude
  Scenario: The author cannot edit an submission
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see the link "edit" in the "submissions" region

  @exclude
  Scenario: The expert cannot delete its own submission
    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see the link "delete" in the "user_submission" region
      And I should not see the link "delete" in the "submissions" region

  @exclude
  Scenario: The author cannot delete an submission
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see the link "delete" in the "submissions" region
