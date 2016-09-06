@api @watchdog
Feature: Requests visibility for Client
  In order to test Requests visibility
  As a Client
  I want to check if I see the right datas

  Background: og visibility : Create nodes and users

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |
    | X-Men    | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |
    | Marvel Entertainment  | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance |
    | client2 | emindhub.test+client2@gmail.com | business | Charle           | XAVIER          |                 |                    | X-Men        | emindhub.test+client2@gmail.com | Marvel Entertainment | Freelancer           | Engines     |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios     | Employee             | Energy        |
    | expert4 | emindhub.test+expert4@gmail.com | expert   | Scott            | SUMMERS         | 0712345673      | Bucheron           | X-Men        | emindhub.test+expert4@gmail.com | Marvel Entertainment | Employee  | Helicopters   |

    Given "request" content:
    | title         | field_domaine  | og_group_ref    | author  | field_expiration_date  | status  |
    | Fight Magneto | Energy         | X-Men           | client2 | 2017-02-08 17:45:00    | 1       |
    | Fight Ultron  | Energy, Drones | Avengers        | client1 | 2017-02-08 17:45:00    | 1       |
    | Fight Hydra   | Drones         | Avengers        | client1 | 2017-02-08 17:45:00    | 1       |
    | Fight Thanos  | Drones         | Avengers, X-Men | client1 | 2017-02-08 17:45:00    | 1       |

    Given I am logged in as "expert1"
    When I click "Edit my account"
      And I fill in "field_address[und][0][phone_number]" with "0712345670"
      And I press "Save"

    Given I am logged in as "expert4"
    When I click "Edit my account"
      And I fill in "field_address[und][0][phone_number]" with "0712345673"
      And I press "Save"

  Scenario: Clients can see the requests
    Given I am logged in as "client1"
    When I go to homepage
    Then I should not see "Fight Magneto"
      And I should see "Fight Ultron"
      And I should see "Fight Hydra"
      And I should see "Fight Thanos"

    Given I am logged in as "client2"
    When I go to homepage
    Then I should see "Fight Magneto"
      And I should not see "Fight Ultron"
      And I should not see "Fight Hydra"
      And I should not see "Fight Thanos"

  Scenario: A client can see experts' full profiles from its circles
    Given I am logged in as "client1"
    When I go to "/users/iron-man"
    Then I should see "Iron MAN"
      And I should see "Chieur génial"
      And I should see "0712345670"
      And I should see "emindhub.test+expert1@gmail.com"

    Given I am logged in as "client2"
    When I go to "/users/scott-summers"
    Then I should see "Scott SUMMERS"
      And I should see "Bucheron"
      And I should see "0712345673"
      And I should see "emindhub.test+expert4@gmail.com"

  Scenario: A client cannot see experts' full profiles outside of its circles
    Given I am logged in as "client1"
    When I am on "/users/scott-summers"
    Then I should get a "403" HTTP response

    Given I am logged in as "client2"
    When I am on "/users/iron-man"
    Then I should get a "403" HTTP response
