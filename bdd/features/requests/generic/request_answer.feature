@api @watchdog
Feature: Request and submissions
  In order to test Request creation, and privacy of submissions
  As a Client and an Expert
  I want to create a Request, and watch submissions

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |
    | Twitter   | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | Man             | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | Kent            | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Twitter   | Employee  | Other         |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2099-02-08 17:45:00    |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
    # Draft submission
    And I press "Save Draft"
    Then I should see the message "Your submission has been saved as draft."
    # Published submission
    And I press "Publish"
    Then I should see "Thank you, your submission has been sent."

    # Another expert responds to the request (draft).
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I fill in "How to become a superhero?" with "You have to read DC comics of course!"
    # Draft submission
    And I press "Save Draft"
    Then I should see the message "Your submission has been saved as draft."

  Scenario: An expert can see its own submission
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should see "You have to read DC comics of course!" in the "submission" region

  Scenario: The author can see the published submissions but not the draft ones
    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Iron Man"
    And I should not see "Klark Kent"

    When I go to homepage
    Then I should see "1" in the "How to become a superhero?" row

    When I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should see "Iron Man"
    And I should see "Everybody can be, trust me, I'm the best we known."
    And I should not see "Klark Kent"
    And I should not see "You have to read DC comics of course!"

  Scenario: The expert cannot respond twice to the same request
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see "Publish" in the "submission" region

  Scenario: The expert can edit its own submission
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit" in the "submission" region
    And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we know."
    And I press "Save"
    Then I should see the success message "Your submission has been updated."

  Scenario: The author cannot edit an submission
    Given I am logged in as "client1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see the link "edit" in the "submissions" region

  Scenario: The expert cannot delete its own submission
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see the link "delete" in the "submission" region
    And I should not see the link "delete" in the "submissions" region

  Scenario: The author cannot delete an submission
    Given I am logged in as "client1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should not see the link "delete" in the "submissions" region
