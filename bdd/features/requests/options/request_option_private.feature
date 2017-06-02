@api @watchdog
Feature: Request and answers
  In order to test Request with Private option
  As a Client and an Expert
  I want to create a request, and watch answers

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

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_position          |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy        | Avionic Design Engineer |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Marvel Studios       | Employee             | Other         | C.E.O.                  |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 0       | Mission            |

    Given I give "client1" 10000 emh credits
    Given the user "client1" is a member of the group "Avengers"
    Given the user "expert1" is a member of the group "Avengers"
    Given the user "expert2" is a member of the group "Avengers"

    # Activate option
    Given I am logged in as "client1"
    When I go to "requests/manage"
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
    Given I check "Private"
      And I press "Continue"
    # Validation page
      And I press "Publish"
    Then I should see the success message "Request How to become a superhero? has been published."

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "Your answer will only be visible by the request's author."

    Given I enter "Everybody can be, trust me, I'm the best we known." for "How to become a superhero?"
    When I press "Publish"
    Then I should see "Your answer has been published."

  Scenario: An expert can see its own private answer
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "Everybody can be, trust me, I'm the best we known." in the "user_submission" region

  Scenario: An expert cannot see other private published answers
    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should not see "Everybody can be, trust me, I'm the best we known."

  Scenario: The author can see private published answers
    Given I am logged in as "client1"
    When I go to "answers/to-me"
    Then I should see "Iron MAN"

    When I go to homepage
    Then I should see "2" in the "content" region

    When I click "How to become a superhero?" in the "content" region
    Then I should see "Answers to your request are only visible by you."
      And I should see "Iron MAN"
      And I should see "Everybody can be, trust me, I'm the best we known."

  Scenario: The circle admin can see private published answers
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
      And I click "edit" in the "Klark KENT" row
      And I check the box "administrator member"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "Everybody can be, trust me, I'm the best we known."
