Feature: Basic
  Everything from the site.

@api
Scenario: Title
  Given I am on the homepage
  Then I should see "eMindHub"

@api 
Scenario: Log in
  Given I am logged in as the admin
  Then I should see text matching "Hello admin"

