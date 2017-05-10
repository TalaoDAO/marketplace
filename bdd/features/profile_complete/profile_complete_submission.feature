@api @watchdog
Feature: Fill Expert profile fields
  In order to save Answer
  As an Expert
  I want to fill my required profile fields

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 1       |

  @exclude
  Scenario: An expert without certain profile fields filled can submit a answer by filling a form
    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios     | Employee             | Energy        |

    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
      And I click "edit" in the "Iron MAN" row
      And I select "Member" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      # FIXME: manage field with autocomplete
      #And I fill in "Position" with "C.E.O."

    # Draft answer
      And I press "Save Draft"
    Then I should see the message "Your answer has been saved as draft."

    When I click "View my profile"
    Then I should see "C.E.O."

    # Published answer
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I press "Publish"
    Then I should see the message "Your answer has been published."

    When I click "View my profile"
    Then I should see "C.E.O."

  Scenario: An expert with some profile fields filled should not be asked to fill it twice
    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_position  |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Marvel Studios     | Employee             | Other         | C.E.O.            |

    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
      And I click "edit" in the "Klark KENT" row
      And I select "Member" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    Given I am logged in as "expert2"
    When I click "View my profile"
    Then I should see "C.E.O."

    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Publish"
    Then I should see the message "Your answer has been published."

    When I click "View my profile"
    Then I should see "C.E.O."
