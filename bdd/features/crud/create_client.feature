@api @watchdog
Feature: Create permissions for Clients
  In order to protect node creation
  As a Client
  I want to test CRUD

  Background: Create nodes and users

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "edit" in the "Captain AMERICA" row
      And I select "Active" from "Status"
      And I check the box "Creator member"
      And I press "Update membership"

  Scenario: Clients cannot create requests in circles they're not members
    Given I am logged in as "client1"
    When I go to "node/add/request"
    Then I should see "Avengers"
      And I should not see "X-Men"
