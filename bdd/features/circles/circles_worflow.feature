@api @watchdog
Feature: Circles workflow for Expert
  In order to test circle membership workflow
  As an Expert
  I want to subscribe to a public circle

  Background: Create contents and users

    Given "circle" content:
    | title                   | author  | group_access |
    | Avengers                | admin   | Private      |
    | X-Men                   | admin   | Private      |
    | Guardians of the Galaxy | admin   | Public       |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |
    | Tumblr    | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client4 | emindhub.test+client4@gmail.com | business | Star             | LORD            |                 |                    | Guardians of the Galaxy        | emindhub.test+client4@gmail.com | Tumblr  | Freelancer | Drones      |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise   | field_working_status | field_domaine |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |
    | expert4 | emindhub.test+expert4@gmail.com | expert   | Scott            | SUMMERS         | 0712345673      | Bucheron           | X-Men        | emindhub.test+expert4@gmail.com | Viadeo    | Employee  | Helicopters   |

    # Make client4 as a MANager of Guardians of the Galaxy circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/guardians-galaxy"
      And I click "Group" in the "primary tabs" region
      And I click "People"
      And I click "edit" in the "Star LORD" row
      And I check the box "administrator member"
      And I press "Update membership"
    Then I should see "The membership has been updated."

  Scenario: Experts can access to its own circles
    Given I am logged in as "expert1"
    When I go to "/circles"
    Then I should see "Avengers"

    When I go to "content/avengers"
    Then I should see "Leave circle"

  Scenario: Experts cannot access to private circles
    Given I am logged in as "expert4"
    When I go to "/circles"
    Then I should not see "Avengers"

  Scenario: Experts can access to public circles
    Given I am logged in as "expert1"
    When I go to "/circles"
    Then I should see "Guardians of the Galaxy"

    When I go to "content/guardians-galaxy"
    Then I should see "Subscribe"

  Scenario: Experts can request membership to public circles and be activated by the circle manager
    Given I am logged in as "expert1"
    When I go to "content/guardians-galaxy"
    Then I should see "Subscribe"

    When I click "Subscribe"
      And I press "Ask to join"

    Given I am logged in as "client4"
    When I go to "content/guardians-galaxy"
      And I click "Group" in the "primary tabs" region
      And I click "People"

    When I click "edit" in the "Iron" row
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    Given I am logged in as "expert1"
    When I go to "content/guardians-galaxy"
    Then I should see "3 members"

  Scenario: Experts can request membership to public circles and be refused by the circle manager
    Given I am logged in as "expert4"
    When I go to "content/guardians-galaxy"
    Then I should see "Subscribe"

    When I click "Subscribe"
      And I press "Ask to join"
    Then I should see "Please complete the following information to access client requests"

    Given I am logged in as "client4"
    When I go to "content/guardians-galaxy"
      And I click "Group" in the "primary tabs" region
      And I click "People"

    When I click "remove" in the "Scott" row
      And I press "Remove"
    Then I should see "The membership was removed."

    Given I am logged in as "expert4"
    When I go to "content/guardians-galaxy"
    Then I should see "Subscribe"
