@exclude @api @watchdog
Feature: Free request
  In order to create a free request in a circle
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

    Given "request" content:
    | title        | field_domaine | og_group_ref | author  |
    | How to become a superhero?  | Energy        | Avengers     | client1 |

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
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit" in the "primary tabs" region
    And I enter "0" for "Reward"
    And I press "Save"
    Then I should see the message "You should at least allocate 500 points."

  Scenario: Client do not have to allocate points to a content in free circle
    Given I am logged in as "client1"
    When I go to homepage
    And I click "Who about?" in the "Who about?" row
    And I click "Edit" in the "primary tabs" region
    And I enter "0" for "Reward"
    And I press "Save"
    Then I should see the success message "Request Who about? has been updated."

    Given I click "Edit" in the "primary tabs" region
    And I click "Questions" in the "secondary tabs" region
    When I fill in "New question" with "How to become a superhero?"
    And I press "Add"
    And I press "Save your question"
    And I click "General infos" in the "secondary tabs" region
    And I press "Publish"
    Then I should see the success message "Request Who about? has been published."

    # Expert responds to the request.
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "Who about?" in the "Who about?" row
    And I fill in "How to become a superhero?" with "You have to read DC comics of course!"
    And I press "Publish my answer"
    Then I should see "Thank you, your answer has been sent."

    Given I am logged in as "client1"
    When I go to homepage
    And I click "Who about?" in the "Who about?" row
    And I click "Answers" in the "primary tabs" region
    And I press "Close the request"
    Then I should see "Closed"

    # The author cannot distribute twice.
    When I go to "/content/who-about"
    And I click "Answers" in the "primary tabs" region
    Then I should not see "Close the request"
    # Author can now access expert profile from request's answer tab.
    And I should see the link "Klark KENT"
