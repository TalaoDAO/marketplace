@api @watchdog
Feature: Requests visibility for Anonymous
  In order to test Requests visibility
  As a anonymous
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

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | client2 | emindhub.test+client2@gmail.com | business | Charle           | Xavier          |                 |                    | X-Men        | emindhub.test+client2@gmail.com | Apple   | Freelancer | Engines     |

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

  Scenario: Anonymous cannot see the requests
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
