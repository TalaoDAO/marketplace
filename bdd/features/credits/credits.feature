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
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios     | Employee             | Energy        |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Marvel Studios     | Employee             | Other         |

    Given I give "client1" 500 emh credits

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 1       |

    Given I am logged in as a user with the "administrator" role
      And the user "client1" is a member of the group "Avengers"

    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Publish"

    # Another expert responds to the request (draft).
    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "You have to read DC comics of course!"
      And I press "Publish"

  @exclude
  Scenario: credits: Edit already published question
    Given I am logged in as "expert2"
    Then I should have 0 credits on "How to become a superhero?" node

    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
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

    When I go to "answers/to-me"
    Then I should see "Iron Man"
      And I should see "Klark Kent"

    When node "How to become a superhero?" transfers 70 credits on "expert1" user
      And node "How to become a superhero?" transfers 30 credits on "expert2" user
    Then I should have 0 credits on "How to become a superhero?" node
      And I should have 70 credits on "expert1" user
      And I should have 30 credits on "expert2" user

    When I go to "answers/to-me"
    Then I should see "70" in the "I'm the best superhero in da world." row
      And I should see "30" in the "You should definitely trust me." row

    Given I am logged in as "expert1"
    When I go to "answers/my"
    Then I should see "70" in the "How to become a superhero?" row

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/credits/transaction-log"
    Then I should see "Move credits from Captain America to question1 How to become a superhero?."
      And I should see "Move credits from question1 How to become a superhero? to Iron Man. "
      And I should see "Move credits from question1 How to become a superhero? to Klark Kent. "

  @exclude
  Scenario: credits : VBO distribute
    Given I am logged in as "expert2"
    Then I should have 0 credits on "How to become a superhero?" node

    Given I am logged in as "client1"
    When I go to "answers/to-me"
    Then I should see "Iron Man"
      And I should see "Klark Kent"

    # Author cannot access expert profile yet.
    Then I should not see the link "Iron Man"
      And I should not see the link "Klark Kent"

    # And from My relationships too
    When I go to "circles/relationships"
    Then I should not see the link "Iron Man"
      And I should not see the link "Klark Kent"

    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Answers" in the "primary tabs" region
      And I check the box "edit-views-bulk-operations-0"
      And I check the box "edit-views-bulk-operations-1"
      And I press "Distribute credits"
    Then I should see "Credits for Iron Man"
      And I should see "Credits for Klark Kent"

    When I fill in "Credits for Iron Man" with "60"
      And I fill in "Credits for Klark Kent" with "40"
      And I press "edit-submit"
    Then I should see the success message "All the credits have been distributed"
      And I should have 0 credits on "How to become a superhero?" node
      And I should have "60" credits on "expert1" user
      And I should have "40" credits on "expert2" user

    # The author cannot distribute twice.
    When I go to "content/how-become-superhero"
      And I click "Answers" in the "primary tabs" region
    Then I should not see "Distribute credits"
    # Author can now access expert profile from question's answer tab.
      And I should see the link "Iron MAN"
      And I should see the link "Klark KENT"

    # And from My relationships too
    When I go to "circles/relationships"
    Then I should see the link "Iron Man"
      And I should see the link "Klark Kent"

    # And now, the expert phone is shown
    When I click "Iron MAN"
    Then I should see "0712345670"

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/credits/transaction-log"
    Then I should see "Move credits from Captain America to question1 How to become a superhero?."
      And I should see "Move credits from question1 How to become a superhero? to Iron Man. "
      And I should see "Move credits from question1 How to become a superhero? to Klark Kent. "
