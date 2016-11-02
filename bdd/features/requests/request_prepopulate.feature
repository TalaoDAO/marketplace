@api @watchdog
Feature: Request Prepopulate
  In order to test Request creation
  As a Client and an Expert
  I want to create a Request, and watch submissions

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance |

    Given I give "client1" 10000 emh credits

    # Make client1 as a Creator member of All experts circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
      And I click "edit" in the "Captain AMERICA" row
      And I select "Active" from "Status"
      And I check the box "Creator member"
      And I press "Update membership"
      # Again...
      And I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
    Then I should see "Creator member" in the "Captain AMERICA" row

  Scenario: An author can create prepopulated request
    Given I am logged in as "client1"
    When I go to "node/add/request"
      And I select "770" from "field_request_type[und]"
      And I click "Activate these options" in the "request_type_expert" region
    Then the "edit-field-request-type-und-770" checkbox should be checked
      And the "Private submissions" checkbox should be checked
      And the "Questionnaire" checkbox should be checked
      And the "field_request_questions[und][0][value]" field should contain "How to become a superhero?"
      And I should see "100 credits" in the "#edit-field-options-und-private" element
      And I should see "300 credits" in the "#edit-field-options-und-questionnaire" element
      #FIXME
      #And I should see "400 credits" in the ".total-wrapper" element
    When I select "Avengers" from "Circles"
      And I fill in "Request title or question" with "How to defeat a superhero?"
      And I select "Energy" from "Fields of expertise"
      And I press "Continue"
      And I press "Publish"
    Then I should see "How to defeat a superhero? has been published"
      And I should see "How to become a superhero?"
      And I should have 9600 credits on "client1" user
