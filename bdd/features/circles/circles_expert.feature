@api @watchdog
Feature: Requests visibility for Expert
  In order to test Requests visibility
  As an Expert
  I want to check if I see the right datas

  Background: og visibility : Create requests and submissions

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |
    | X-Men    | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Apple     | admin   |
    | Facebook  | admin   |
    | Viadeo    | admin   |
    | Linkedin  | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | client2 | emindhub.test+client2@gmail.com | business | Charle           | XAVIER          |                 |                    | X-Men        | emindhub.test+client2@gmail.com | Apple   | Freelancer | Engines     |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise   | field_working_status | field_domaine |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |
    | expert4 | emindhub.test+expert4@gmail.com | expert   | Scott            | SUMMERS         | 0712345673      | Bucheron           | X-Men        | emindhub.test+expert4@gmail.com | Viadeo    | Employee  | Helicopters   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise   | field_working_status |
    | expert5 | emindhub.test+expert5@gmail.com | expert   | Jean             | GREY            | 0712345674      | Boulanger          | X-Men        | emindhub.test+expert5@gmail.com | Linkedin  | Employee  |

    Given "request" content:
    | title         | field_domaine  | og_group_ref    | author  | field_expiration_date  | status  |
    | Fight Magneto | Energy         | X-Men           | client2 | 2017-02-08 17:45:00    | 1       |
    | Fight Ultron  | Energy, Drones | Avengers        | client1 | 2017-02-08 17:45:00    | 1       |
    | Fight Hydra   | Drones         | Avengers        | client1 | 2017-02-08 17:45:00    | 1       |
    | Fight Thanos  | Drones         | Avengers, X-Men | client1 | 2017-02-08 17:45:00    | 1       |

  Scenario: Experts can see the requests
    Given I am logged in as "expert1"
    When I go to homepage
    Then I should not see "Fight Magneto"
      And I should see "Fight Ultron"
      And I should see "Fight Hydra"
      And I should see "Fight Thanos"

    Given I am logged in as "expert4"
    When I go to homepage
    Then I should see "Fight Magneto"
      And I should not see "Fight Ultron"
      And I should not see "Fight Hydra"
      And I should see "Fight Thanos"

  Scenario: Check profile completion and request visibility
    Given I am logged in as "expert5"

    When I go to homepage
    Then I should see "Please complete the following information to access client requests"

    When I go to "/content/fight-magneto"
    Then I should see "Please complete the following information to access client requests"
      And I should not see "Your submission"

    When I enter "86" for "Field(s) of expertise"
      And I press "Update your profile"
    Then I should see the success message containing "You have now access to client requests."
      And I should see "Your submission"
