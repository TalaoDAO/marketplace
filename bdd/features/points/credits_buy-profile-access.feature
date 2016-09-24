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
    | name    | mail                            | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | All experts     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | All experts     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy        |

    Given "request" content:
    | title                       | field_domaine | og_group_ref    | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | All experts     | client1 | 2017-02-08 17:45:00    | 1       |

    Given I give "client1" 1000 emh credits
    Given I give "expert1" 1000 emh credits

    # Make client1 as a Creator member of All experts circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/all-experts"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
      And I click "edit" in the "Captain AMERICA" row
      And I select "Active" from "Status"
      And I check the box "Creator member"
      And I press "Update membership"
    When I go to "content/all-experts"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      And I click "Member since"
      And I click "edit" in the "Iron MAN" row
      And I select "Active" from "Status"
      And I press "Update membership"
      # Again...
      And I go to "content/all-experts"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
    Then I should see "Creator member" in the "Captain AMERICA" row

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/credits"
    Then I fill in "Cost of profile purchase" with "50"
      And I press "Save configuration"

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Publish"
    Then I should see the message "Your submission has been published."

    When I click "Edit my account"
      And I fill in "field_address[und][0][phone_number]" with "0712345670"
      And I press "Save"

  Scenario: An author can buy a profile
    Given I am logged in as "client1"
    When I go to "content/how-become-superhero"
    Then I should see "Iron" in the "submissions" region
      And I should not see "MAN" in the "submissions" region
      And I should see "Access profile for 50 credits" in the "submissions" region

    When I click "Access profile for 50 credits" in the "submissions" region
      And I press "Access profile"
    Then I should see "Iron MAN" in the "submissions" region
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
      And I should not see "AMERICA" in the "request_right" region
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
