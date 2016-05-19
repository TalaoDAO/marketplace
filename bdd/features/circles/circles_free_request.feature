@api @watchdog
Feature: Free circle and threshold limit
  In order to create a free content in a circle
  As a client
  I do not need to have a minimum of points

  Background: og visibility : Create circles

    Given "circle" content:
    | title    | author  | field_free_circle |
    | Avengers | admin   | Free circle       |
    | X-Men    | admin   | Paying circle     |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Twitter   | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers, X-Men | emindhub.test+client@gmail.com | Google            | Freelancer            | Maintenance   |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Twitter   | Employee  | Other         |

    Given "question1" content:
    | title        | field_domaine | og_group_ref | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Maintenance   | X-Men        | client1 | Display my full name | Display the name      | Display                 |
    | Who about?   | Maintenance   | Avengers     | client1 | Display my full name | Display the name      | Display                 |

    Given I give "client1" 400 emh points

    # Make client1 as a Creator member of circles
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group" in the "primary tabs" region
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"
    And I go to "content/x-men"
    And I click "Group" in the "primary tabs" region
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"

  Scenario: Client must allocate points to a content in paying circle
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    And I enter "0" for "Cost"
    And I press "Save"
    Then I should see the message "You should at least allocate 100 points."

  Scenario: Client do not have to allocate points to a content in free circle
    Given I remove "client1" 400 emh points
    And I am logged in as "client1"
    When I go to homepage
    And I click "Who about?" in the "Who about?" row
    And I click "Edit" in the "primary tabs" region
    And I enter "0" for "Cost"
    And I press "Save"
    Then I should see the success message "Question Who about? has been updated."

    # Expert answers to free request
    Given I am logged in as "expert2"
    When I am on the homepage
    And I click "Who about?" in the "Who about?" row
    Given I select the radio button "My answer will be visible by all experts"
    And I enter "I'm the best superhero in da world." for "Public answer"
    And I press "Publish"

    Given I am logged in as "client1"
    When I go to homepage
    And I click "Who about?" in the "Who about?" row
    And I click "Answers" in the "primary tabs" region
    And I check the box "edit-views-bulk-operations-0"
    And I press "Validate and close the request"
    And I press "edit-submit"
    Then I should see the success message "Request Who about? has been closed."
    And I should have "0" points on "Who about?" node
    And I should have "0" points on "expert2" user

    # The author cannot distribute twice.
    When I go to "/content/who-about"
    Then I should see "Closed"
    When I click "Answers" in the "primary tabs" region
    Then I should not see "Validate and close the request"
    # Author can now access expert profile from question's answer tab.
    And I should see the link "Klark KENT"
