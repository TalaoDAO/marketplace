@api
Feature: Basic
  Everything from the site.

  Scenario: Title
    Given I am on the homepage
    Then I should see "eMindHub"

  Scenario: Log in
    Given I am logged in as the admin
    Then I should see text matching "Hello admin"
