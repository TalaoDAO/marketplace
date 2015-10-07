Feature: Navigate
  Everything from the site.

@api
Scenario: Title
  Given I am on the homepage
  Then I should see "eMindHub"

@api
Scenario: Log in
  Given I visit "/user"
   # fill the username and password input fields, and click submit
  When I fill in "Username" with "admin"
    And I fill in "Password" with "admin"
    And I press the "Log in" button
  Then I should get a "200" HTTP response
    And I should see text matching "Hello admin"


