@api
  Feature: Client navigation

  Scenario: test ask menus
    Given I am logged in as a user with the "business" role
    When I go to homepage
    Then I should see "Ask" in the "top" region
    And I should see "a question" in the "top" region
    And I should see "Start" in the "top" region
    And I should see "a challenge" in the "top" region
    And I should see "Create" in the "top" region
    And I should see "a survey" in the "top" region
