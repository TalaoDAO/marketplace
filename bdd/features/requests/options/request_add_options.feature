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
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678                  | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Aviation   |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?  | Blockchain        | Avengers     | client1 | 2020-02-08 17:45:00    | 0       | Mission            |

    Given I give "client1" 10000 emh credits
    Given the user "client1" is a member of the group "Avengers"

  Scenario: An author can add an option on a draft request and come back to test it's readonly after publish
    Given I am logged in as "client1"
    When I go to "requests/manage"
    Then I should see "Avengers" in the "content" region

    When I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
      And I check the box "Duration"
    Then I should see "Duration of the mission"
      And I should see "Desired starting date"
      And I fill in "Duration of the mission" with "1 month"

    When I press "Continue"
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
      And I click "Mission" in the "request_type" region
      And I fill in "Request title or question" with "How to defeat a superhero?"
      And I select "Blockchain" from "Fields of expertise"
      And I select "Avengers" from "Circles"
      And I check the box "Duration"
    Then I should see "Duration of the mission"
      And I should see "Desired starting date"

    When I fill in "Duration of the mission" with "1 week"
      And I press "Continue"
    Then I should see "Request How to defeat a superhero? has been created."
      And I should see "1 week"
