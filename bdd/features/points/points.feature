@api @watchdog
Feature: Test points
  In order to test emh points
  As a Client
  I want to dispatch points on experts

  Background: points : create questions and answers

    Given "circle" content:
    | title    | author  |
    | Avengers | client1 |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |
    | Twitter   | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Twitter   | Employee  | Other         |

    Given I give "client1" 500 emh points

    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about?  | Energy        | Avengers     | 100          | client1 |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"

    Given I am logged in as "expert1"
    When I go to homepage
    When I click "What about?" in the "What about?" row
    Then I enter "I'm the best superhero in da world." for "Public answer"
    And I select the radio button "My answer will be visible by all experts"
    And I press "Publish"

    Given I am logged in as "expert2"
    When I go to homepage
    When I click "What about?" in the "What about?" row
    Then I enter "You should definitely trust me." for "Public answer"
    And I select the radio button "My answer will be visible by all experts"
    And I press "Publish"

  Scenario: points: Edit already published question
    Given I am logged in as "expert2"
    Then I should have 100 points on "What about?" node

    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Reward"
    And the "Reward" field should contain "100"

    When I enter "200" for "Reward"
    And I select "Display my full name" from "Your name"
    And I select "Display the name" from "Your organisation"
    And I select "Display" from "Your activity"
    And I press "Save"
    #And I break
    Then I should have 200 points on "What about?" node
    And I should have 300 points on "client1" user

  @exclude
  Scenario: points: Manual distribute
    Given I am logged in as "expert2"
    Then I should have 100 points on "What about?" node

    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "2" in the "What about?" row

    When I go to "/my-responses"
    Then I should see "Iron Man"
    And I should see "Klark Kent"

    When node "What about?" transfers 70 points on "expert1" user
    And node "What about?" transfers 30 points on "expert2" user
    Then I should have 0 points on "What about?" node
    And I should have 70 points on "expert1" user
    And I should have 30 points on "expert2" user

    When I go to "/my-responses"
    Then I should see "70" in the "I'm the best superhero in da world." row
    And I should see "30" in the "You should definitely trust me." row

    Given I am logged in as "expert1"
    When I go to "/my-responses"
    Then I should see "70" in the "What about?" row

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/points/transaction-log"
    Then I should see "Move points from Captain America to question1 What about?."
    And I should see "Move points from question1 What about? to Iron Man. "
    And I should see "Move points from question1 What about? to Klark Kent. "

  #@exclude
  Scenario: points : VBO distribute
    Given I am logged in as "expert2"
    Then I should have 100 points on "What about?" node

    Given I am logged in as "client1"
    When I go to "/my-responses"
    Then I should see "Iron Man"
    And I should see "Klark Kent"

    # Author cannot access expert profile yet.
    Then I should not see the link "Iron Man"
    And I should not see the link "Klark Kent"

    # And from My relathionships too
    When I go to "/circles/relationships"
    Then I should not see the link "Iron Man"
    And I should not see the link "Klark Kent"

    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Answers" in the "primary tabs" region
    And I check the box "edit-views-bulk-operations-0"
    And I check the box "edit-views-bulk-operations-1"
    And I press "Distribute points"
    Then I should see "Points for Iron Man"
    And I should see "Points for Klark Kent"

    When I fill in "Points for Iron Man" with "60"
    And I fill in "Points for Klark Kent" with "40"
    And I press "edit-submit"
    Then I should see the success message "All the points have been distributed"
    And I should have 0 points on "What about?" node
    And I should have "60" points on "expert1" user
    And I should have "40" points on "expert2" user

    # The author cannot distribute twice.
    When I go to "/content/what-about"
    And I click "Answers" in the "primary tabs" region
    Then I should not see "Distribute points"
    # Author can now access expert profile from question's answer tab.
    And I should see the link "Iron MAN"
    And I should see the link "Klark KENT"

    # And from My relathionships too
    When I go to "/circles/relationships"
    Then I should see the link "Iron Man"
    And I should see the link "Klark Kent"

    # And now, the expert phone is shown
    When I click "Iron Man"
    Then I should see "0712345670"

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/points/transaction-log"
    Then I should see "Move points from Captain America to question1 What about?."
    And I should see "Move points from question1 What about? to Iron Man. "
    And I should see "Move points from question1 What about? to Klark Kent. "
