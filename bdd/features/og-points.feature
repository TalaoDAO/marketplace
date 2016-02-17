@api
Feature: Test points dispatch in OG
  In order to test emh points dispatch
  As a client with a team
  I want to dispatch points on my team members

  Background: OG Points : Create questions and answers

    Given "circle" content:
    | title    | author  |
    | Avengers | client1 |

    #client1 is webmaster to gain access to tabs until links are added

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | client1@emindhub.com | business, webmaster | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | client1@emindhub.com | Google  | Independant | Maintenance |
    | client2 | client2@emindhub.com | business | Charle           | Xavier          |                 |                    | X-Men        | client2@emindhub.com | Apple   | Independant | Engines     |
    | client3 | client3@emindhub.com | business | Tony             | Stark           |                 |                    | X-Men        | client3@emindhub.com | Tumblr  | Independant | Drones      |

  Scenario: OG Points : distribute points
    Given I give "client1" 300 emh points
    Given user "client1" transfers 200 points on "Avengers" node
    Given I am logged in as "client1"
    Then I should see "100 points"
    And I should have "100" points on "client1" user

    When I go to "/groups"
    Then I should see "Avengers"

    When I click "Avengers"
    #Then I should see "You are the group manager"

    When I click "Group"
    And I click "Add people"
    And I fill in "User name" with "client2"
    And I press "Add users"
    #Then I should see the success message containing "has been added to the group"
    And I fill in "User name" with "client3"
    And I press "Add users"

    When I go to "/groups"
    And I click "Avengers"
    And I click "Members"
    Then I should see "client2"
    And I should see "client3"
    #Then I should see the success message containing "has been added to the group"

    When I go to "/groups"
    And I click "Avengers"
    And I click "Distribute points"
    Then I should see "Operations"

    When I check the box "edit-views-bulk-operations-0"
    And I check the box "edit-views-bulk-operations-1"
    And I press "Distribute group points to these entities"
    Then I should see "Points"

    When I fill in "Points" with "100"
    And I press "Next"
    Then I should see "Points for Charle Xavier"
    And I should see "Points for Tony Stark"

    When I fill in "Points for Charle Xavier" with "60"
    And I fill in "Points for Tony Stark" with "40"
    And I press "edit-submit"
    Then I should see the success message "All the points have been distributed"
    And I should have 100 points on "Avengers" node
    And I should have "60" points on "client2" user
    And I should have "40" points on "client3" user
