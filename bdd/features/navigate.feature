@api @watchdog
Feature: Navigation
  Everything from the site.

  Scenario: Title
    Given I am on the homepage
    Then I should see "eMindHub"

  Scenario: Log in
    Given I visit "/user"
    # fill the username and password input fields, and click submit
    When I fill in "E-mail or username" with "admin"
    And I fill in "Password" with "admin"
    And I press the "Log in" button
    Then I should get a "200" HTTP response
    And I should see text matching "Hello admin"

  Scenario: test ask menus
    Given I am logged in as a user with the "business" role
    When I go to homepage
    Then I should see "Create a question" in the "top" region
    And I should see "Create a challenge" in the "top" region
    And I should see "Create a survey" in the "top" region
