@api @watchdog
Feature: Test credits dispatch in OG
  In order to test emh credits dispatch
  As a Client with a team
  I want to dispatch credits on my team members

  Background: OG Credits : Create questions and answers

    Given "circle" content:
    | title    | author  |
    | X-Men    | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Apple     | admin   |
    | Tumblr    | admin   |

    #client1 is webmaster to gain access to tabs until links are added
    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business, webmaster | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | client2 | emindhub.test+client2@gmail.com | business | Charle           | XAVIER          |                 |                    | X-Men        | emindhub.test+client2@gmail.com | Apple   | Freelancer | Engines     |
    | client3 | emindhub.test+client3@gmail.com | business | Tony             | STARK           |                 |                    | X-Men        | emindhub.test+client3@gmail.com | Tumblr  | Freelancer | Drones      |

    Given "circle" content:
    | title    | author  |
    | Avengers | client1 |

  Scenario: OG Credits : distribute credits
    Given I give "client1" 300 emh credits
    Given user "client1" transfers 200 credits on "Avengers" node
    Given I am logged in as "client1"
    Then I should see "100 credits"
      And I should have "100" credits on "client1" user

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
    Then I should see "Charle XAVIER"
      And I should see "Tony STARK"
    #Then I should see the success message containing "has been added to the group"

    When I go to "/groups"
      And I click "Avengers"
      And I click "Distribute credits"
    Then I should see "Operations"

    When I check the box "edit-views-bulk-operations-1"
      And I check the box "edit-views-bulk-operations-2"
      And I press "Distribute group credits to these entities"
    Then I should see "Credits"

    When I fill in "Credits" with "100"
      And I press "Next"
      And I fill in "Credits for Charle XAVIER" with "60"
      And I fill in "Credits for Tony STARK" with "40"
      And I press "edit-submit"
    Then I should see the success message "All the credits have been distributed"
      And I should have 100 credits on "Avengers" node
      And I should have "60" credits on "client2" user
      And I should have "40" credits on "client3" user
