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
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678                  | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    | Real-time                    |

    Given the user "client1" is a member of the group "Avengers"

  Scenario: Clients cannot create requests in circles they're not members
    Given I am logged in as "client1"
    When I go to "node/add/request"
    Then I should see "Create Request"
      And I should see "Avengers"
      And I should not see "X-Men"

    #DONE Nasty bug : this line should not be necessary !!!!
      And the user client1 has "edit own webform submissions" permission
      And the user client1 has "create request content" permission
