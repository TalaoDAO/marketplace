@api @watchdog
Feature: Request Option Questionnaire
  In order to test Request with questionnaire creation
  As a Client and an Expert
  I want to create a Request with the paying questionnaire option, and watch answers

  Background: Create request

    Given "circle" content:
    | title                   | author  |
    | Avengers                | admin   |
    | League Of Justice       | admin   |
    | Guardians Of The Galaxy | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers, League Of Justice, Guardian Of Galaxy     | emindhub.test+client1@gmail.com | Marvel Studios     | Freelancer | Aviation | US |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers, League Of Justice, Guardian Of Galaxy     | emindhub.test+expert1@gmail.com | Marvel Studios     | Employee  | Blockchain        | US |

    Given I give "client1" 10000 emh credits

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?  | Blockchain        |              | client1 | 2020-02-08 17:45:00    | 0       | Mission            |

    Given the user "client1" is a member of the group "Avengers"
    Given the user "expert1" is a member of the group "Avengers"

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/credits"
    Then I fill in "Questionnaire" with "300"
      And I press "Save configuration"

  Scenario: An author can create a request with a questionnaire
    Given I am logged in as "client1"
    When I go to "requests/manage"
      And I click "How to become a superhero?" in the "content" region
    When I click "Edit" in the "primary tabs" region
    Then I should see "300 credits" in the "#edit-field-options-und-questionnaire" element

    When I select "Avengers" from "Circles"
      And I check the box "Questionnaire"
    Then I should see "Questions"
      And I fill in "edit-field-request-questions-und-0-value" with "My little questionnaire"
      And I press "Continue"
    Then I should see "Request How to become a superhero? has been updated."
    # Validation page
      And I press "Publish"
      And I should have "9700" credits on "client1" user

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I should see "My little questionnaire"
