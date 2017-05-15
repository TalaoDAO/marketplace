@api @watchdog
Feature: SmartMobility circle test
  In order to test SmartMobility module
  As a member of the circle
  I want to check if I get SmartMobility features.

  Background: Create nodes and users

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Smart Mobility     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    |

  @smartmobility
  Scenario: Basic login
    When I visit 'user/login'
    And I fill in "admin" for "name"
    And I fill in "admin" for "pass"
    And I press the "Log in" button
    Then I should see the text "Log out"

  @smartmobility
  Scenario: A Smart Mobility member should be redirected to /content/smart-mobility on login
    Given I am logged in as a user with the "administrator" role
      And the user "client1" is an admin of the group "Smart Mobility"

    Given I am logged in as "client1"
    Then I should see "Smart mobility"
      And I should see "How it works"
