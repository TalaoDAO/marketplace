@api @watchdog
Feature: Request Option Price
  In order to test Request with different prices in circles
  As a Client and an Expert
  I want to create a Request with the paying options with different prices depending on circles

  Background: Create request

    Given "circle" content:
    | title            | author  | field_free_circle | 
    | Avengers         | admin   | Paying circle     |
    | LeagueOfJustice  | admin   | Paying circle     |
    | GuardiansOfGalaxy | admin   | Free circle       |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers, LeagueOfJustice, GuardiansOfGalaxy     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers, LeagueOfJustice, GuardiansOfGalaxy     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |

    Given I give "client1" 10000 emh points

    Given I am logged in as a user with the "administrator" role
    # Set price for options
    When I go to "content/avengers"
    And I click "Edit"
    And I fill in "Questionnaire" with "1000"
    And I fill in "Duration" with "1000"
    And I press "Save"

    When I go to "content/leagueofjustice"
    And I click "Edit"
    And I fill in "Questionnaire" with "700"
    And I fill in "Duration" with "1300"
    And I press "Save"

    # Make client1 as a Creator member of circles
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"

    When I go to "content/leagueofjustice"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"

    When I go to "content/guardiansofgalaxy"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Captain America" row
    And I check the box "Creator member"
    And I press "Update membership"



  Scenario: An author can create a request with a questionnaire and duration with changing prices
    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | status | field_expiration_date |
    | How to become a superhero?  | Energy        |              | client1 | 0      | 2017-02-08 17:45:00   |

    Given I am logged in as "client1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    When I click "Edit" in the "primary tabs" region
    Then I should see "500 points" in the "#edit-field-options-und-questionnaire" element
    And I should see "200 points" in the "#edit-field-options-und-duration" element

    When I select "Avengers" from "Circles"
    And I press "Save draft"
    And I click "Edit" in the "primary tabs" region
    Then I should see "1000 points" in the "#edit-field-options-und-questionnaire" element
    And I should see "1000 points" in the "#edit-field-options-und-duration" element

    When I additionally select "LeagueOfJustice" from "Circles"
    And I press "Save draft"
    And I click "Edit" in the "primary tabs" region
    Then I should see "1000 points" in the "#edit-field-options-und-questionnaire" element
    And I should see "1300 points" in the "#edit-field-options-und-duration" element

    And I check the box "Duration"
    Then I should see "Duration of the mission"
    And I should see "Desired starting date"
    Then I fill in "Duration of the mission" with "1 month"

    And I check the box "Questionnaire"
    Then I should see "Questions"
    And I fill in "edit-field-request-questions-und-0-value" with "My little questionnaire"

    And I press "Publish"

    Then I should see "Request How to become a superhero? has been updated."
    And I should see "1 month"
    And I press "Publish"
    And I should have "7700" points on "client1" user

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I should see "My little questionnaire"
