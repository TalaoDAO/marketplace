@api @watchdog
Feature: Create permissions
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
