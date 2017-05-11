@api @watchdog
Feature: Fill Expert profile fields
  In order to access Requests
  As an Expert
  I want to fill my required profile fields

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678                  | Chef de groupe    | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 1       |

  Scenario: An expert without certain profile fields filled can access request by filling a form
    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670                  | Chieur génial     | Avengers     | emindhub.test+expert1@gmail.com |

    Given I am logged in as a user with the "administrator" role
      And the user "expert1" is a member of the group "Avengers"

    Given I am logged in as "expert1"
    When I go to homepage
    Then I should see "Please complete the following information to access client requests"

    When I click "How to become a superhero?" in the "content" region
    Then I should see "Please complete the following information to access client requests"
      And I should not see "Publication date"
    When I fill in "Organisation / company" with "Marvel Studios"
      And I select "Employee" from "Working status"
      And I select "Energy" from "Field(s) of expertise"
      #And I select "United States" from "Country"
      And I press "Update your profile"
    Then I should see the message "Your profile has been updated. You have now access to client requests."
      And I should see "Publication date" in the "request_right" region

  Scenario: An expert with some profile fields filled should not be asked to fill it twice
    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671                  | Modèle            | Avengers     | emindhub.test+expert2@gmail.com | Marvel Studios       |

    Given I am logged in as a user with the "administrator" role
      And the user "expert2" is a member of the group "Avengers"

    Given I am logged in as "expert2"
    When I click "View my profile"
    Then I should see "Marvel Studios"

    When I go to homepage
    Then I should see "Please complete the following information to access client requests"
      And I should not see "Organisation / company"
    When I select "Employee" from "Working status"
      And I select "Energy" from "Field(s) of expertise"
      And I press "Update your profile"
    Then I should see the message "Your profile has been updated. You have now access to client requests."

    When I click "View my profile"
    Then I should see "Marvel Studios"
