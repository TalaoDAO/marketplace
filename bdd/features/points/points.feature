@api @watchdog
Feature: Test credits
  In order to test emh credits
  As a Client
  I want to dispatch credits on experts

  Background: credits : create questions and answers

    Given "circle" content:
    | title    | author  |
    | Avengers | client1 |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |
    | Twitter   | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Twitter   | Employee  | Other         |

    Given I give "client1" 500 emh credits

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2017-02-08 17:45:00    | 1       |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "edit" in the "Captain AMERICA" row
      And I check the box "Creator member"
      And I press "Update membership"
    Then I should see "Creator member" in the "Captain AMERICA" row

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Publish"
    Then I should see the message "Your submission has been published."

    # Another expert responds to the request (draft).
    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I fill in "How to become a superhero?" with "You have to read DC comics of course!"
      And I press "Publish"
    Then I should see the message "Your submission has been published."

  @exclude
  Scenario: credits: Edit already published question
    Given I am logged in as "expert2"
    Then I should have 100 credits on "How to become a superhero?" node

    Given I am logged in as "client1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Reward"
    And the "Reward" field should contain "100"

    When I enter "200" for "Reward"
    And I select "Display my full name" from "Your name"
    And I select "Display the name" from "Your organisation"
    And I select "Display" from "Your activity"
    And I press "Save"
    #And I break
    Then I should have 200 credits on "How to become a superhero?" node
    And I should have 300 credits on "client1" user

  @exclude
  Scenario: credits: Manual distribution
    Given I am logged in as "expert2"
    Then I should have 100 credits on "How to become a superhero?" node

    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "2" in the "How to become a superhero?" row

    When I go to "/my-responses"
    Then I should see "Iron MAN"
    And I should see "Klark KENT"

    When node "How to become a superhero?" transfers 70 credits on "expert1" user
    And node "How to become a superhero?" transfers 30 credits on "expert2" user
    Then I should have 0 credits on "How to become a superhero?" node
    And I should have 70 credits on "expert1" user
    And I should have 30 credits on "expert2" user

    When I go to "/my-responses"
    Then I should see "70" in the "Everybody can be, trust me, I'm the best we known." row
    And I should see "30" in the "You have to read DC comics of course!" row

    Given I am logged in as "expert1"
    When I go to "/my-responses"
    Then I should see "70" in the "How to become a superhero?" row

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/credits/transaction-log"
    Then I should see "Move credits from Captain AMERICA to request How to become a superhero?."
    And I should see "Move credits from request How to become a superhero? to Iron MAN. "
    And I should see "Move credits from request How to become a superhero? to Klark KENT. "

  @exclude
  Scenario: credits : VBO distribution
    Given I am logged in as "expert2"
    Then I should have 100 credits on "How to become a superhero?" node

    Given I am logged in as "client1"
    When I go to "/my-responses"
    Then I should see "Iron MAN"
    And I should see "Klark KENT"

    # Author cannot access expert profile yet.
    Then I should not see the link "Iron MAN"
    And I should not see the link "Klark KENT"

    # And from My relathionships too
    When I go to "/circles/relationships"
    Then I should not see the link "Iron MAN"
    And I should not see the link "Klark KENT"

    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Answers" in the "primary tabs" region
    And I check the box "edit-views-bulk-operations-0"
    And I check the box "edit-views-bulk-operations-1"
    And I press "Distribute credits"
    Then I should see "Points for Iron MAN"
    And I should see "Points for Klark KENT"

    When I fill in "Points for Iron MAN" with "60"
    And I fill in "Points for Klark KENT" with "40"
    And I press "edit-submit"
    Then I should see the success message "All the credits have been distributed"
    And I should have 0 credits on "How to become a superhero?" node
    And I should have "60" credits on "expert1" user
    And I should have "40" credits on "expert2" user

    # The author cannot distribute twice.
    When I go to "/content/how-become-superhero"
    And I click "Answers" in the "primary tabs" region
    Then I should not see "Distribute credits"
    # Author can now access expert profile from question's answer tab.
    And I should see the link "Iron MAN"
    And I should see the link "Klark KENT"

    # And from My relathionships too
    When I go to "/circles/relationships"
    Then I should see the link "Iron MAN"
    And I should see the link "Klark KENT"

    # And now, the expert phone is shown
    When I click "Iron MAN"
    Then I should see "0712345670"

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/credits/transaction-log"
    Then I should see "Move credits from Captain AMERICA to request How to become a superhero?."
    And I should see "Move credits from request How to become a superhero? to Iron MAN. "
    And I should see "Move credits from request How to become a superhero? to Klark KENT. "
