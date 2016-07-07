@api @watchdog
Feature: Request
  In order to test Request creation with options
  As a Client
  I want to create a Request, and add options

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2017-02-08 17:45:00    | 0       |

    Given I give "client1" 10000 emh points

    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "edit" in the "Captain AMERICA" row
      And I check the box "Creator member"
      And I press "Update membership"
    Then I should see "Creator member" in the "Captain AMERICA" row

  Scenario: An author can add an option on a draft request and come back to test it's readonly after publish
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "Avengers" in the "How to become a superhero?" row

    When I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit" in the "primary tabs" region
    And I check the box "Duration"
    Then I should see "Duration of the mission"
      And I should see "Desired starting date"
      And I fill in "Duration of the mission" with "1 month"

    When I press "Publish"
    # Validation page
      And I press "Publish"
    Then I should see "Request How to become a superhero? has been published."
      And I should see "1 month"

    When I click "Edit" in the "primary tabs" region
    Then the "Duration" checkbox should be checked

    #TODO : Not the best way to test, but right now, no "readonly" test exists
    When I check the box "Duration"
    Then the "Duration" checkbox should be checked

  Scenario: An author can add an option in request creation
    Given I am logged in as "client1"
    When I go to "node/add/request"
      And I fill in "Request title or question" with "How to defeat a superhero?"
      And I select "Energy" from "Fields of expertise"
      And I select "Avengers" from "Circles"
      And I check the box "Duration"
    Then I should see "Duration of the mission"
      And I should see "Desired starting date"

    When I fill in "Duration of the mission" with "1 week"
      And I press "Publish"
    Then I should see "Request How to defeat a superhero? has been created."
      And I should see "1 week"
