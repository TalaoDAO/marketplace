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
    | How to become a superhero?            | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 1       | Mission            |
    | How to behave like a superhero?       | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 0       | Mission            |

    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
      And I click "edit" in the "Captain AMERICA" row
      And I select "Member" from "Status"
      And I press "Update membership"
    Then I should see "Member" in the "Captain AMERICA" row
    Then I should see "The membership has been updated."
      And I click "edit" in the "Iron MAN" row
      And I select "Member" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."
      And I click "edit" in the "Klark KENT" row
      And I select "Member" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

  Scenario: The author can change some content if no expert responded
    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
    Then the "Request title or question" field should be disabled
      And the "field_request_type[und]" field should be disabled
      And the "Describe your request" field should not be disabled
      And the "edit-field-options-und-private-enabled" field should be disabled
      And the "edit-field-request-questions" field should not be disabled

  Scenario: An expert responds to the request, then some field become disabled for the author
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Publish"
    Then I should see the message "Your answer has been published."

    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
    Then the "Request title or question" field should be disabled
      And the "field_request_type[und]" field should be disabled
      And the "Describe your request" field should not be disabled
      And the "edit-field-options-und-private-enabled" field should be disabled
      And the "edit-field-request-questions-und-0-value" field should be disabled

  Scenario: An expert responds to the request, but admin can still modify everything
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Publish"
    Then I should see the message "Your answer has been published."

    Given I am logged in as a user with the "administrator" role
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
    Then the "Request title or question" field should not be disabled
      And the "field_request_type[und]" field should not be disabled
      And the "Describe your request" field should not be disabled
      And the "edit-field-options" field should not be disabled
      And the "edit-field-options-und-private-enabled" field should not be disabled
      And the "edit-field-request-questions-und-0-value" field should not be disabled

  Scenario: Submissions should be there even if the author edits its own request!
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Publish"
    Then I should see the message "Your answer has been published."

    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
      And I press "Save"
    Then I should see "Everybody can be, trust me, I'm the best we known."

  Scenario: An author can reedit a request with a questionnaire without loosing responses
    Given I give "client1" 10000 emh credits

    Given I am logged in as "client1"
    When I go to "requests/manage"
      And I click "How to behave like a superhero?" in the "content" region
    When I click "Edit" in the "primary tabs" region
      And I select "Avengers" from "Circles"
      And I check the box "Questionnaire"
      And I fill in "edit-field-request-questions-und-0-value" with "My little questionnaire"
      And I press "Continue"
      And I press "Publish"

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to behave like a superhero?" in the "content" region
      And I fill in "My little questionnaire" with "My little response"
      And I press "Publish"
    Then I should see the message "Your answer has been published."

    Given I am logged in as "client1"
    When I go to homepage
      And I click "How to behave like a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
      And I press "Save"
    Then I should see "My little response"
