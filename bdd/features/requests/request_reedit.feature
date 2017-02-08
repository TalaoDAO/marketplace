@api @watchdog
Feature: Request re-editions
  In order to test Request re-editions
  As a Client and an Expert and an Webmaster
  I want to check that I can or cannot re-edit my request depending on context

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_position          |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy        | Avionic Design Engineer |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Marvel Studios       | Employee             | Other         | C.E.O.                  |

    Given "request" content:
    | title                                 | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?            | Energy        | Avengers     | client1 | 2017-02-08 17:45:00    | 1       | Mission            |

    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "edit" in the "Captain AMERICA" row
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "Active" in the "Captain AMERICA" row
    Then I should see "The membership has been updated."
      And I click "edit" in the "Iron MAN" row
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."
      And I click "edit" in the "Klark KENT" row
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

  Scenario: The author can change some content if no expert responded
    Given I am logged in as "client1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit"
    Then the "Request title or question" field should be disabled
    And the "field_request_type[und]" field should be disabled
    And the "Describe your request" field should not be disabled
    #TODO: And the "edit-field-options" field should not be disabled
    And the "edit-field-options-und-private-enabled" field should be disabled
    And the "edit-field-request-questions" field should not be disabled

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Save Draft"
    Then I should see the message "Your answer has been saved as draft."
    When I press "Publish"
    Then I should see the message "Your answer has been published."

    #When request has response, some field become disabled
    Given I am logged in as "client1"
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit"
    Then the "Request title or question" field should be disabled
    And the "field_request_type[und]" field should be disabled
    And the "Describe your request" field should not be disabled
    #TODO: And the "edit-field-options" field should be disabled
    And the "edit-field-options-und-private-enabled" field should be disabled
    And the "edit-field-request-questions-und-0-value" field should be disabled

    #but admin can still modify everything
    Given I am logged in as a user with the "administrator" role
    When I go to homepage
    And I click "How to become a superhero?" in the "How to become a superhero?" row
    And I click "Edit"
    Then the "Request title or question" field should not be disabled
    And the "field_request_type[und]" field should not be disabled
    And the "Describe your request" field should not be disabled
    And the "edit-field-options" field should not be disabled
    And the "edit-field-options-und-private-enabled" field should not be disabled
    And the "edit-field-request-questions-und-0-value" field should not be disabled
