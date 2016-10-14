@api @watchdog
Feature: Request and profile fields
  In order to access Requests
  As an Expert
  I want to fill my required profile fields

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail                      |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2017-02-08 17:45:00    | 1       |

    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "edit" in the "Captain AMERICA" row
      And I select "Active" from "Status"
      And I check the box "Creator member"
      And I press "Update membership"
    Then I should see "Creator member" in the "Captain AMERICA" row
    Then I should see "The membership has been updated."
      And I click "edit" in the "Iron MAN" row
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

  Scenario: An expert without certain profile fields filled can access request by filling form
    Given I am logged in as "expert1"
    When I go to homepage
    Then I should see "Please complete the following information to access client requests"

    When I click "How to become a superhero?" in the "How to become a superhero?" row
    Then I should see "Please complete the following information to access client requests"
      And I should not see "Publication date"
    When I fill in "Organisation / company" with "Marvel Studios"
      And I select "Employee" from "Working status"
      And I select "Energy" from "Field(s) of expertise"
      And I select "United States" from "Country"
    Then I press "Update your profile"
      And I press "Update your profile"
      And I should see the message "Your profile has been updated. You have now access to client requests."
      And I should see "Publication date" in the "request_right" region

  Scenario: An expert with some profile fields filled should not be asked to fill it twice
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/people"
      And I click "Member for"
      And I check the box "edit-views-bulk-operations-0"
      And I select "Change value" from "operation"
      And I press "Execute"
      And I check the box "bundle_user[show_value][field_address]"
      And I select "United States" from "Country"
      And I press "Next"
      And I press "Next"
      And I follow meta refresh
    Then I should see "Performed Change value on 1 item."

    Given I am logged in as "expert1"
    When I click "View my profile"
    Then I should see "United States"

    When I go to homepage
    Then I should see "Please complete the following information to access client requests"
      And I should not see "Country"
    When I fill in "Organisation / company" with "Marvel Studios"
      And I select "Employee" from "Working status"
      And I select "Energy" from "Field(s) of expertise"
    Then I press "Update your profile"
      And I should see the message "Your profile has been updated. You have now access to client requests."

    When I click "View my profile"
    Then I should see "United States"
