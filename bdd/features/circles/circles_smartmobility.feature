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
    When I visit "user/login"
    And I fill in "admin" for "name"
    And I fill in "admin" for "pass"
    And I press the "Log in" button
    Then I should see the text "Log out"

  @smartmobility
  Scenario: A Smart Mobility member should be redirected to /content/smart-mobility on login
    Given the user "client1" is an admin of the group "Smart Mobility"

    Given I am logged in as the admin
    When I go to "admin/people"
      And I click "edit" in the "Captain AMERICA" row
      And I click "Change password"
      And I fill in "test" for "pass[pass1]"
      And I fill in "test" for "pass[pass2]"
      And I press "Submit"
    Then I should see "Your password has been changed."

    When I go to "user/logout"
      And I visit "smart-mobility"
      And I fill in "client1" for "name"
      And I fill in "test" for "pass"
      And I press the "Log in" button
    Then I should see "Smart Mobility"
      And I should see "Welcome to Smart Mobility"
