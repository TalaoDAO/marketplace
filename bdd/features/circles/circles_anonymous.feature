@api @watchdog
Feature: Requests visibility for Anonymous
  In order to test Requests visibility
  As an anonymous
  I want to check if I see the right datas

  Background: og visibility : Create requests

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |
    | X-Men    | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |
    | Marvel Entertainment  | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Aviation   | US                    |
    | client2 | emindhub.test+client2@gmail.com | business | Charle           | XAVIER          |                 |                    | X-Men        | emindhub.test+client2@gmail.com | Marvel Entertainment | Freelancer           | Connected Car       | US                    |

    Given "request" content:
    | title         | field_domaine  | og_group_ref    | author  | field_expiration_date  | status  |
    | Fight Magneto | Blockchain         | X-Men           | client2 | 2020-02-08 17:45:00    | 1       |
    | Fight Ultron  | Blockchain, Aviation | Avengers        | client1 | 2020-02-08 17:45:00    | 1       |
    | Fight Hydra   | Aviation         | Avengers        | client1 | 2020-02-08 17:45:00    | 1       |
    | Fight Thanos  | Aviation         | Avengers, X-Men | client1 | 2020-02-08 17:45:00    | 1       |

  Scenario: Anonymous cannot see the requests
    Given I am not logged in
    When I go to homepage
    Then I should not see "Fight Magneto"
      And I should not see "Fight Ultron"
      And I should not see "Fight Hydra"
      And I should not see "Fight Thanos"

    When I go to "content/fight-magneto"
    Then I should not see "Fight Magneto"

    When I go to "content/fight-hydra"
    Then I should not see "Fight Hydra"

    When I go to "content/fight-thanos"
    Then I should not see "Fight Thanos"

    When I go to "node"
    Then I should not see "Fight Magneto"
      And I should not see "Fight Ultron"
      And I should not see "Fight Hydra"
      And I should not see "Fight Thanos"
