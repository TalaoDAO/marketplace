@api @watchdog
Feature: Request
  In order to test Request creation
  As a Client and an Expert
  I want to create a Request, and watch answers

  Background: Create request

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given "circle" content:
    | title    | author  |
    | X-Men    | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678                  | Chef de groupe     | All experts  | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    | Real-time                    |
    | client2 | emindhub.test+client2@gmail.com | business | Charles          | XAVIER       | 0607080901                | Xavier Institute   | X-Men        | emindhub.test+client2@gmail.com | Marvel Studios | Freelancer           | Engines       | US                   | Real-time                    |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670                  | Chieur génial      | All experts  | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy          | US                  | Real-time                    |

    Given I am logged in as a user with the "administrator" role

    # Make client1 member of All experts circle
    When I go to "content/all-experts"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
      And I click "edit" in the "Captain AMERICA" row
      And I select "Member" from "Status"
      And I press "Update membership"
      # Again...
      And I go to "content/all-experts"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
    Then I should see "Member" in the "Captain AMERICA" row
      And I click "edit" in the "Iron MAN" row
      And I select "Member" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    # Validate membership of client2 in X-Men circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/x-men"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
      And I click "edit" in the "Charles XAVIER" row
      And I select "Member" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

    Given "request" content:
    | title                       | field_domaine | og_group_ref    | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | All experts     | client1 | 2020-02-08 17:45:00    | 1       |

  Scenario: An author can see its own request
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "All experts" in the "content" region

  Scenario: An author can see its own request in My requests
    Given I am logged in as "client1"
    When I go to "requests/manage"
    Then I should see "How to become a superhero?" in the "content" region
      And I should see "All experts" in the "content" region

  Scenario: An author can edit its own request
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
      And I select "770" from "field_request_type[und]"
    Then I should see "Edit Request How to become a superhero?" in the "title" region

    Given I enter "This is my request." for "Describe your request"
      And I press "Save"
    Then I should see the success message "Request How to become a superhero? has been updated."

  Scenario: An author cannot delete its own request
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

  Scenario: A user can see some infos on a request without option
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "Captain" in the "request_right" region
      And I should not see "Captain AMERICA" in the "request_right" region
      And I should see "Marvel Studios" in the "request_right" region

  Scenario: Only users belonging to a circle can add a request type restricted to this circle
    # HINT: this should work on "X-MEN" for field_circle_restriction, but, we use "Cercle de test"
    # to bypass a cleanup bug: nodes are cleaned BEFORE terms; when "Call for heroes" is cleaned
    # up, "X-Men" circle as already been deleted, and it causes a bug
    Given "request_type" terms:
    | name            | description    | format        | language | field_circle_restriction | field_prepopulate            |
    | Call for heroes | Request heroes | filtered_html | en       | Cercle de test           | edit[og_group_ref][und]=1813 |
    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node   | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency |
    | client5 | emindhub.test+client4@gmail.com | business | Hank             | MCKOY           | 0607080901                  | Xavier Institute | Cercle de test | emindhub.test+client2@gmail.com | Marvel Studios        | Freelancer           | Engines       | US                    | Real-time                    |

    Given I am logged in as a user with the "administrator" role
    When I go to "content/cercle-de-test"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
      And I click "Member since"
      And I click "Member since"
      And I click "edit" in the "Hank MCKOY" row
      And I select "Member" from "Status"
      And I press "Update membership"

    Given I am logged in as "client1"
    When I go to "node/add/request"
    Then I should not see "Call for heroes"

    Given I am logged in as "client5"
    When I go to "node/add/request"
    Then I should see "Call for heroes"
