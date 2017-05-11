@api @watchdog
Feature: Create permissions for Référents
  In order to protect node creation
  As a Référent
  I want to test CRUD

  Background: Create nodes and users

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | référent1 | emindhub.test+referent1@gmail.com | référent | Nick             | FURY            | 0612345678      | Skydiving          | Avengers     | emindhub.test+referent1@gmail.com | Marvel Studios       | Other | Maintenance |

    # Make référent1 as a Referent member of Avengers circle
    Given I am logged in as a user with the "administrator" role
      And the user "référent1" is a member of the group "Avengers"

  Scenario: A référent cann create a request
    Given I am logged in as "référent1"
    When I go to "node/add/request"
    Then I should see "Create Request"
