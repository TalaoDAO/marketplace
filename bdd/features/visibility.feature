@api @watchdog
Feature: Test og visibility
  In order to test emh requests visibility
  As anonymous, client, expert, referent or webmaster
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
    | Linkedin  | admin   |
    | Tumblr    | admin   |
    | Amazon    | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | référent1 | emindhub.test+referent1@gmail.com | référent | Paul          | Stanley         | 0612345678      | The Starchild     | Avengers     | emindhub.test+referent1@gmail.com | Amazon  | Other | Maintenance |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | client2 | emindhub.test+client2@gmail.com | business | Charle           | Xavier          |                 |                    | X-Men        | emindhub.test+client2@gmail.com | Apple   | Freelancer | Engines     |
    | client3 | emindhub.test+client3@gmail.com | business | Tony             | Stark           |                 |                    | X-Men        | emindhub.test+client3@gmail.com | Tumblr  | Freelancer | Drones      |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise   | field_working_status | field_domaine |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Twitter   | Employee  | Other         |
    | expert3 | emindhub.test+expert3@gmail.com | expert   | Bruce            | Banner          | 0712345672      | Cogneur            | Avengers     | emindhub.test+expert3@gmail.com | Pinterest | Employee  | Drones        |
    | expert4 | emindhub.test+expert4@gmail.com | expert   | Scott            | Summers         | 0712345673      | Bucheron           | X-Men        | emindhub.test+expert4@gmail.com | Viadeo    | Employee  | Helicopters   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise   | field_working_status |
    | expert5 | emindhub.test+expert5@gmail.com | expert   | Jean             | Grey            | 0712345674      | Boulanger          | X-Men        | emindhub.test+expert5@gmail.com | Linkedin  | Employee  |

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

    # Make référent1 as a Referent member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "référent1" row
    And I check the box "Referent member"
    And I press "Update membership"

  Scenario: Webmaster can see the requests
    Given I am logged in as a user with the "webmaster" role
    When I go to homepage
    Then I should see "Fight Magneto"
    And I should see "Fight Ultron"
    And I should see "Fight Hydra"
    And I should see "Fight Thanos"

  Scenario: Referents can see the requests
    Given I am logged in as "référent1"
    When I go to homepage
    Then I should not see "Fight Magneto"
    And I should see "Fight Ultron"
    And I should see "Fight Hydra"
    And I should see "Fight Thanos"

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

  Scenario: Check profile completion and request visibility
    Given I am logged in as "expert5"

    When I go to homepage
    Then I should see "Please complete the following information to access client requests"

    When I go to "/content/fight-magneto"
    Then I should see "Please complete the following information to access client requests"
    And I should not see "Answer the question"

    When I enter "86" for "Field(s) of expertise"
    And I press "Update your profile"
    Then I should see the success message containing "You have now access to client requests."
    And I should see "Answer the question"

  Scenario: A client can only see selected experts full profiles from its circles
    Given I am logged in as "client2"

    When I go to "/users/expert2"
    Then I should see "Klark Kent"
    And I should not see "Modèle"
    And I should not see "0712345671"
    And I should not see "emindhub.test+expert2@gmail.com"

    When I go to "/users/expert3"
    Then I should see "Bruce Banner"
    And I should not see "Cogneur"
    And I should not see "0712345672"
    And I should not see "emindhub.test+expert3@gmail.com"

    When I go to "/users/expert4"
    Then I should see "Scott Summers"
    And I should see "Bucheron"
    And I should see "0712345673"
    And I should see "emindhub.test+expert4@gmail.com"

  Scenario: A référent can only see full experts profiles from its circles
    Given I am logged in as "référent1"

    When I go to "/users/expert2"
    Then I should see "Klark Kent"
    And I should see "Modèle"
    And I should see "0712345671"
    And I should see "emindhub.test+expert2@gmail.com"

    When I go to "/users/expert3"
    Then I should see "Bruce Banner"
    And I should see "Cogneur"
    And I should see "0712345672"
    And I should see "emindhub.test+expert3@gmail.com"

    When I go to "/users/expert4"
    Then I should see "Scott Summers"
    And I should not see "Bucheron"
    And I should not see "0712345673"
    And I should not see "emindhub.test+expert4@gmail.com"
