@api @watchdog
Feature: Requests visibility for Référent
  In order to test Requests visibility
  As a Référent
  I want to check if I see the right datas

  Background: og visibility : Create questions and answers

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |
    | X-Men    | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Apple     | admin   |
    | Facebook  | admin   |
    | Twitter   | admin   |
    | Pinterest | admin   |
    | Viadeo    | admin   |
    | Amazon    | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | référent1 | emindhub.test+referent1@gmail.com | référent | Paul          | STANLEY         | 0612345678      | The Starchild     | Avengers     | emindhub.test+referent1@gmail.com | Amazon  | Other | Maintenance |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | client2 | emindhub.test+client2@gmail.com | business | Charle           | XAVIER          |                 |                    | X-Men        | emindhub.test+client2@gmail.com | Apple   | Freelancer | Engines     |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise   | field_working_status | field_domaine |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Twitter   | Employee  | Other         |
    | expert3 | emindhub.test+expert3@gmail.com | expert   | Bruce            | BANNER          | 0712345672      | Cogneur            | Avengers     | emindhub.test+expert3@gmail.com | Pinterest | Employee  | Drones        |
    | expert4 | emindhub.test+expert4@gmail.com | expert   | Scott            | SUMMERS         | 0712345673      | Bucheron           | X-Men        | emindhub.test+expert4@gmail.com | Viadeo    | Employee  | Helicopters   |

    Given "request" content:
    | title         | field_domaine  | og_group_ref    | author  | field_expiration_date  | status  |
    | Fight Magneto | Energy         | X-Men           | client2 | 2017-02-08 17:45:00    | 1       |
    | Fight Ultron  | Energy, Drones | Avengers        | client1 | 2017-02-08 17:45:00    | 1       |
    | Fight Hydra   | Drones         | Avengers        | client1 | 2017-02-08 17:45:00    | 1       |
    | Fight Thanos  | Drones         | Avengers, X-Men | client1 | 2017-02-08 17:45:00    | 1       |

    # Make référent1 as a Referent member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Paul STANLEY" row
    And I check the box "Referent member"
    And I press "Update membership"
    Then I should see "The membership has been updated."

    Given I am logged in as "expert1"
    And I click "Edit account"
    And I fill in "field_address[und][0][phone_number]" with "0712345670"
    And I press "Save"

    Given I am logged in as "expert2"
    And I click "Edit account"
    And I fill in "field_address[und][0][phone_number]" with "0712345671"
    And I press "Save"

    Given I am logged in as "expert3"
    And I click "Edit account"
    And I fill in "field_address[und][0][phone_number]" with "0712345672"
    And I press "Save"

    Given I am logged in as "expert4"
    And I click "Edit account"
    And I fill in "field_address[und][0][phone_number]" with "0712345673"
    And I press "Save"

    Given I am logged in as "référent1"
    And I click "Edit account"
    And I fill in "field_address[und][0][phone_number]" with "0612345678"
    And I press "Save"

  Scenario: Referents can see the requests
    Given I am logged in as "référent1"
    When I go to homepage
    Then I should not see "Fight Magneto"
    And I should see "Fight Ultron"
    And I should see "Fight Hydra"
    And I should see "Fight Thanos"

  Scenario: A référent can only see full experts profiles from its circles
    Given I am logged in as "référent1"

    When I go to "/users/klark-kent"
    Then I should see "Klark KENT"
    And I should see "Modèle"
    And I should see "0712345671"
    And I should see "emindhub.test+expert2@gmail.com"

    When I go to "/users/bruce-banner"
    Then I should see "Bruce BANNER"
    And I should see "Cogneur"
    And I should see "0712345672"
    And I should see "emindhub.test+expert3@gmail.com"

    When I go to "/users/scott-summers"
    Then I should see "Scott SUMMERS"
    And I should not see "Bucheron"
    And I should not see "0712345673"
    And I should not see "emindhub.test+expert4@gmail.com"
