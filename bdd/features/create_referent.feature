@api @watchdog
Feature: Create permissions for Référents
  In order to protect node creation
  As a référent
  I want to test CRUD

  Background: Create nodes and users

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Amazon    | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | référent1 | emindhub.test+referent1@gmail.com | référent | Paul          | Stanley         | 0612345678      | The Starchild     | Avengers     | emindhub.test+referent1@gmail.com | Amazon  | Other | Maintenance |

    # FIXME: Force user profile update for OG role addition
    Given I am logged in as "référent1"
    And I click "Edit account"
    And I press "Save"

  Scenario: A référent cannot create a question
    Given I am logged in as "référent1"
    When I go to "node/add"
    Then I should not see "Question" in the "content" region

  Scenario: A référent cannot create a survey
    Given I am logged in as "référent1"
    When I go to "node/add"
    Then I should not see "Survey" in the "content" region

  Scenario: A référent cannot create a challenge
    Given I am logged in as "référent1"
    When I go to "node/add"
    Then I should not see "Challenge" in the "content" region
