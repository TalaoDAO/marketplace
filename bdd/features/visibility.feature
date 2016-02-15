@api
Feature: Test og visibility
  In order to test emh requests visibility
  As anonymous, clients, and experts
  I want to check if I see the right datas

  Background: og visibility : Create questions and answers

    Given "circle" content:
    | title    | author  |
    | Avengers | client1 |
    | X-Men    | client2 |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           |
    | client1 | client1@emindhub.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | client1@emindhub.com |
    | client2 | client2@emindhub.com | business | Charle           | Xavier          |                 |                    | X-Men        | client2@emindhub.com |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | 0712345678      | Chieur génial      | Avengers     | expert1@emindhub.com |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | 0812345678      | Modèle             | Avengers     | expert2@emindhub.com |
    | expert3 | expert3@emindhub.com | expert   | Bruce            | Banner          | 0912345678      | Cogneur            | Avengers     | expert3@emindhub.com |
    | expert4 | expert4@emindhub.com | expert   | Scott            | Summers         | 0912345677      | Bucheron           | X-Men        | expert4@emindhub.com |
    | expert5 | expert5@emindhub.com | expert   | Jean             | Grey            | 0912345679      | Boulanger          | X-Men        | expert5@emindhub.com |

    Given I give "client1" 400 emh points
    Given I give "client2" 100 emh points

    Given "question1" content:
    | title         | field_domaine  | og_group_ref   | field_reward | author  |
    | Fight Magneto | Energy         | X-Men          | 100          | client2 |
    | Fight Ultron  | Energy, Drones | Avengers       | 100          | client1 |
    | Fight Hydra   | Drones         | Avengers       | 100          | client1 |

    Given "challenge" content:
    | title         | field_domaine  | og_group_ref    | field_reward | author  |
    | Fight Thanos  | Drones         | Avengers, X-Men | 100          | client1 |

  #@exclude
  Scenario: og visibility : Test visibility
    Given I am logged in as a user with the "webmaster" role
    When I go to homepage
    Then I should see "Fight Magneto"
    And I should see "Fight Ultron"
    And I should see "Fight Hydra"
    And I should see "Fight Thanos"

    Given I am logged in as "client1"
    Then I should not see "Fight Magneto"
    And I should see "Fight Ultron"
    And I should see "Fight Hydra"
    And I should see "Fight Thanos"

    Given I am logged in as "client2"
    Then I should see "Fight Magneto"
    And I should not see "Fight Ultron"
    And I should not see "Fight Hydra"
    And I should not see "Fight Thanos"

    Given I am logged in as "expert1"
    Then I should not see "Fight Magneto"
    And I should see "Fight Ultron"
    And I should see "Fight Hydra"
    And I should see "Fight Thanos"

    Given I am logged in as "expert4"
    Then I should see "Fight Magneto"
    And I should not see "Fight Ultron"
    And I should not see "Fight Hydra"
    And I should see "Fight Thanos"

    Given I am not logged in
    When I go to homepage
    Then I should not see "Fight Magneto"
    And I should not see "Fight Ultron"
    And I should not see "Fight Hydra"
    And I should not see "Fight Thanos"
    When I go to "/content/fight-magneto"
    Then I should not see "Fight Magneto"
    When I go to "/content/fight-hydra"
    Then I should not see "Fight Hydra"
    When I go to "/content/fight-thanos"
    Then I should not see "Fight Thanos"
    When I go to "/node"
    Then I should not see "Fight Magneto"
    And I should not see "Fight Ultron"
    And I should not see "Fight Hydra"
    And I should not see "Fight Thanos"

  Scenario: Check profile fields visibility
    Given I am logged in as "client2"

    When I go to "/users/expert4"
    Then I should see "Scott Summers"
    And I should see "Bucheron"
    And I should see "0912345677"
    And I should see "expert4@emindhub.com"

    When I go to "/users/expert2"
    Then I should see "Klark Kent"
    And I should not see "Modèle"
    And I should not see "0812345678"
    And I should not see "expert2@emindhub.com"

    When I go to "/users/expert3"
    Then I should see "Bruce Banner"
    And I should not see "Cogneur"
    And I should not see "0912345678"
    And I should not see "expert3@emindhub.com"
