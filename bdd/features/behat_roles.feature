@api @watchdog
Feature: Behat roles
  In order to test behat roles handling
  As a Client and an Expert
  I want to check that client can create a request and expert don't 

  Background: Create request

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_entreprise     |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | Marvel Studios       |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_entreprise     | 
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron           | MAN               | Marvel Studios       |

  Scenario: Experts can comment, business don't
    Given I am logged in as "client1"
    When I go to "node/add/request"
      Then I should see "Create Request"
    Given I am logged in as "expert1"
    When I go to "node/add/request"
      Then I should not see "Create Request"
      And I should see "403_authenticated"
  
