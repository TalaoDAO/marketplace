@api @watchdog
Feature: Jail Circles test
  Experts in Jail Circles can not escape their circle. Business roles can.

  Background: Create users

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education    | og_user_node       | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Captain          | AMERICA         | 0612345678                  | Chef de groupe     | Smart Mobility     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    |
    | client1 | emindhub.test+client1@gmail.com | business | Charle           | XAVIER          |                             |                    | Smart Mobility     | emindhub.test+client2@gmail.com | Marvel Entertainment | Freelancer           | Engines       | US                    |

    Given the user "expert1" is a member of the group "Smart Mobility"
    Given the user "client1" is a member of the group "Smart Mobility"

  Scenario: An expert in a Jail Circle can not see some links and has the circle's logo and homepage.
    Given I am logged in as "expert1"
    When I visit "/content/smart-mobility"
    Then I should not see "Buy credits" in the "navbar" region
      And I should not see "Earnings" in the "navbar" region
      And I should not see "Circles" in the "navbar" region

  Scenario: A business in a Jail Circle can see some links and has EMH's logo and homepage.
    Given I am logged in as "client1"
    When I visit "/content/smart-mobility"
    Then I should see "Buy credits" in the "navbar" region
      And I should see "Earnings" in the "navbar" region
      And I should see "Circles" in the "navbar" region
