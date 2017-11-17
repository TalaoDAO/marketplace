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
    | title                 | author  |
    | Marvel Studios        | admin   |
    | Marvel Entertainment  | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise   | field_working_status | field_domaine | field_address:country |
    | client4 | emindhub.test+client4@gmail.com | business | Star             | LORD            |                 |                    | Guardians of the Galaxy        | emindhub.test+client4@gmail.com | Tumblr  | Freelancer | Aviation      | US                 |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise   | field_working_status | field_domaine | field_address:country |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios     | Employee             | Blockchain        | US                  |
    | expert4 | emindhub.test+expert4@gmail.com | expert   | Scott            | SUMMERS         | 0712345673      | Bucheron           | X-Men        | emindhub.test+expert4@gmail.com | Marvel Entertainment | Employee  | Helicopters   | US                 |

    Given the user "client4" is an admin of the group "Guardians of the Galaxy"
    Given the user "expert1" is a member of the group "Avengers"
    Given the user "expert4" is a member of the group "X-Men"

  Scenario: Experts can access to its own circles
    Given I am logged in as "expert1"
    When I go to "circles"
      And I click "Avengers"
    Then I should see "Leave circle"

  Scenario: Experts cannot access to private circles
    Given I am logged in as "expert4"
    When I go to "circles"
    Then I should not see "Avengers"

  Scenario: Experts cannot access to public circles if they're not active members
    Given I am logged in as "expert1"
    When I go to "circles"
    Then I should not see the link "Guardians of the Galaxy"

    When I go to "content/guardians-galaxy"
    Then I should see "Guardians of the Galaxy"
      And I should not see "Latest requests" in the "content" region

  @email
  Scenario: Experts can join public circles and be activated by the circle admin
    Given the test email system is enabled

    Given I am logged in as "expert1"
    When I go to "circles"
      And I click "Join circle" in the "guardians_galaxy_teaser" region
      And I fill in "Request message" with "I really want to join your band"
      And I press "Ask to join"
    Then I should see "Your request is pending." in the "header" region
      And the last email to "emindhub.test+client4@gmail.com" should contain "Iron MAN membership request for 'Guardians of the Galaxy'"
      And the last email to "emindhub.test+1@gmail.com" should contain "Iron MAN membership request for 'Guardians of the Galaxy'"
      And the last email to "emindhub.test+expert1@gmail.com" should contain "Your membership request for 'Guardians of the Galaxy'"

    Given I am logged in as "client4"
    When I go to "content/guardians-galaxy"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
    Then I should see "Pending" in the "Iron MAN" row

    When I click "edit" in the "Iron" row
      And I select "Member" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    Given I am logged in as "expert1"
    When I go to "circles"
    Then I should not see "Your request is pending." in the "guardians_galaxy_teaser" region

  Scenario: Experts can join public circles and be refused by the circle admin
    Given I am logged in as "expert4"
    When I go to "circles"
      And I click "Join circle" in the "guardians_galaxy_teaser" region
      And I fill in "Request message" with "Hey guys, please accept my request!"
      And I press "Ask to join"
    Then I should see "Your request is pending." in the "header" region

    Given I am logged in as "client4"
    When I go to "content/guardians-galaxy"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
    Then I should see "Pending" in the "Scott" row

    When I click "remove" in the "Scott" row
      And I press "Remove"
    Then I should see "The membership was removed."

    Given I am logged in as "expert4"
    When I go to "circles"
    Then I should see "Join circle" in the "guardians_galaxy_teaser" region

  Scenario: Circle member can access to requests
    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Blockchain        | Avengers     | client1 | 2020-02-08 17:45:00    | 1       |

    Given I am logged in as a user with the "administrator" role
    Given the user "client1" is a member of the group "Avengers"

    # Client
    Given I am logged in as "client1"
    When I go to "content/avengers"
    Then I should see "How to become a superhero?"
    When I click "Requests" in the "primary tabs" region
    Then I should see "How to become a superhero?"

    # And expert too!
    Given I am logged in as "expert1"
    When I go to "content/avengers"
    Then I should see "How to become a superhero?"
    When I click "Requests" in the "primary tabs" region
    Then I should see "How to become a superhero?"
