@api @watchdog
Feature: Buy profile access
  In order to test profile access purchasing
  As a Client and an Expert
  I want to buy a profile and watch it

  Background: Create request

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | All experts     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_position          |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | All experts     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy        | US                    | Avionic Design Engineer |

    Given "request" content:
    | title                       | field_domaine | og_group_ref    | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | All experts     | client1 | 2020-02-08 17:45:00    | 1       |

    Given I give "client1" 1000 emh credits
    Given I give "expert1" 1000 emh credits

    Given I am logged in as a user with the "administrator" role
      And the user "client1" is an admin of the group "All experts"
      And the user "expert1" is a member of the group "All experts"

    When I go to "admin/emindhub/credits"
    Then I fill in "Cost of profile purchase" with "50"
      And I press "Save configuration"

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Publish"
    Then I should see the message "Your answer has been published."

  Scenario: An author can buy a profile
    Given I am logged in as "client1"
    When I go to "content/how-become-superhero"
    Then I should see "Iron" in the "submissions" region
      And I should not see "Iron MAN" in the "submissions" region
      And I should see "Access profile for 50 credits" in the "submissions" region
    When I click "view" in the "submissions" region
    Then I should see "Iron"
      And I should not see "Iron MAN"

    When I go to "content/how-become-superhero"
      And I click "Access profile for 50 credits" in the "submissions" region
      And I press "Access profile"
    Then I should see "Iron MAN" in the "submissions" region
      And I should see "1" in the "user_purchased_count" region
      And I should have "950" credits on "client1" user
      And I should have "1050" credits on "expert1" user

    When I go to "circles/relationships"
    Then I should see "Iron MAN"

    When I click "Iron MAN"
    Then I should see "Iron MAN"
      And I should see "Chieur génial"
      And I should see "0712345670"
      And I should see "emindhub.test+expert1@gmail.com"

  @exclude
  Scenario: An expert can buy an author profile
    Given I am logged in as "expert1"
    When I go to "content/how-become-superhero"
    Then I should see "Captain" in the "request_right" region
      And I should not see "Captain AMERICA" in the "request_right" region
      And I should see "Access profile for 50 credits" in the "request_right" region

    When I click "Access profile for 50 credits" in the "request_right" region
    Then I should see ""

    When I press "Access profile"
    Then I should see ""
      And I should have "1050" credits on "client1" user
      And I should have "950" credits on "expert1" user

    When I go to "content/how-become-superhero"
    Then I should see "Captain AMERICA" in the "request_right" region

    When I go to "circles/relationships"
    Then I should see "Captain AMERICA"
