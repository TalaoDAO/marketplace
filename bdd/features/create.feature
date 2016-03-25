@api @watchdog
Feature: Create
  Everything from the site.

  Background: Create nodes and users

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Amazon    | admin   |

    Given "page" content:
    | title    |
    | Page one |
    | Page two |

    Given  "article" content:
    | title          |
    | First article  |
    | Second article |

    Given users:
    | name     | mail            | status |
    | Joe User | joe@example.com | 1      |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | référent1 | emindhub.test+referent1@gmail.com | référent | Paul          | Stanley         | 0612345678      | The Starchild     | Avengers     | emindhub.test+referent1@gmail.com | Amazon  | Other | Maintenance |

    # FIXME: Force user profile update for OG role addition
    Given I am logged in as "référent1"
    And I click "Edit account"
    And I press "Save"

  Scenario: Create a node
    Given I am logged in as a user with the "administrator" role
    When I am viewing an "article" content with the title "My article"
    Then I should see the heading "My article"

  Scenario: Create many nodes
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/content"
    Then I should see "Page one"
    And I should see "Page two"
    And I should see "First article"
    And I should see "Second article"

  Scenario: Create users
    Given I am logged in as a user with the "administrator" role
    When I visit "admin/people"
    Then I should see the link "Joe User"

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
