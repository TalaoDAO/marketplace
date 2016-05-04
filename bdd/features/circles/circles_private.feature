@api @watchdog
Feature: Public circle and threshold limit
  In order to create a content in a public circle
  As a client
  I need to have a minimum of points

  Background: og visibility : Create circles

    Given "circle" content:
    | title    | author  | group_access |
    | Avengers | admin   | Private      |
    | X-Men    | admin   | Public       |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Apple     | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node    | field_mail                     | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers, X-Men | emindhub.test+client@gmail.com | Google            | Freelancer            | Maintenance   |

    Given "question1" content:
    | title        | field_domaine | og_group_ref | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Maintenance   | X-Men        | client1 | Display my full name | Display the name      | Display                 |
    | Who about?   | Maintenance   | Avengers     | client1 | Display my full name | Display the name      | Display                 |


    Given I give "client1" 400 emh points

    # Make client1 as a Creator member of circles
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"
    And I go to "content/x-men"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"

  Scenario:
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    And I enter "0" for "Cost"
    And I press "Save"
    Then I should see the message "You should at least allocate 100 points."

  Scenario:
    Given I am logged in as "client1"
    When I go to homepage
    And I click "Who about?" in the "Who about?" row
    And I click "Edit" in the "primary tabs" region
    And I enter "0" for "Cost"
    And I press "Save"
    Then I should see the success message "Question Who about? has been updated."
