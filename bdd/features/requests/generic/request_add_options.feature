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
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | status |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 0      |

    # Make client1 as a Creator member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"

  Scenario: An author can add an option on a draft request and come back to test it's readonly after publish
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "Avengers" in the "How to become a superhero?" row
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    When I click "Edit" in the "primary tabs" region 
    And I check the box "Duration"
    Then I should see "Duration of the mission"
    And I should see "Desired starting date"
    Then I fill in "Duration of the mission" with "1 month"
    And I press "Publish"

    Then I should see "Request How to become a superhero? has been updated."
    And I should see "1 month"

    Then I click "Edit" in the "primary tabs" region
    And the "Duration" checkbox should be checked
    #TODO : Not the best way to test, but right now, no "readonly" test exists
    Then I check the box "Duration" 
    And the "Duration" checkbox should be checked

  Scenario: An author can add an option on a new request 
    When I go to "node/add/request"
    And I fill in "Title" with "How to defeat a superhero?"
    And I select "Energy" from "Domain(s)"
    And I select "Avengers" from "Choose circle of experts" 
    And I check the box "Duration"
    Then I should see "Duration of the mission"
    And I should see "Desired starting date"
    Then I fill in "Duration of the mission" with "1 week"
    And I press "Publish"

    Then I should see "Request How to defeat a superhero? has been created."
    And I should see "1 week"
