@api @watchdog
Feature: Behat roles
  In order to test behat roles handling
  As a Client and an Expert
  I want to check that client can create a request and expert don't 

  Scenario: Experts can comment, business don't

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_position  | og_user_node | field_entreprise     | field_working_status | field_needs_for_expertise | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | Chef de projet  | Avengers     | Marvel Studios       | Freelancer           | Maintenance               | US                    |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_entreprise     |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron           | MAN               | Marvel Studios       |

    Given I am logged in as "client1"
    When I go to "node/add/request"
      Then I should see "Create Request"
    Given I am logged in as "expert1"
    When I go to "node/add/request"
      Then I should not see "Create Request"
      And I should see "403_authenticated"

    #DONE Nasty bug : this line should not be necessary !!!!
    Then the user client1 don't have "edit own webform submissions" permission
      And the user client1 has "create request content" permission

    Then the user expert1 has "edit own webform submissions" permission
      And the user expert1 don't have "create request content" permission

