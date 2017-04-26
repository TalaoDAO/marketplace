@api @watchdog
Feature: Registration test
  In order to test the registration process
  As an anonymous user
  I want to check if I can register as a new user

  Scenario: Test if basic registering still works
    When I visit 'client/register'
      And I fill in "Spider" for "First Name"
      And I fill in "MAN" for "Last Name"
      And I fill in "emindhub.test+spiderman@gmail.com" for "mail"
      And I fill in "test" for "pass[pass1]"
      And I fill in "test" for "pass[pass2]"
      And I check the box "I agree to the Terms of use document"
      And I press the "Create new account" button
    Then I should see the text "A confirmation message with further instructions has been sent to your e-mail address."

    Given I am logged in as the admin
    When I go to "admin/people"
      And I click "edit" in the "Spider MAN" row
      And I select the radio button "Member"
      And I select "France" from "Country"
      And I fill in "Airbus" for "field_entreprise[und][0][target_id]"
      #Notice: "Position" don't work because it's exists also in "Last position(s)" group field
      And I fill in "academics" for "field_position[und]"
      And I select "Freelancer" from "Working status"
      And I fill in "278" for "Field(s) of expertise"
      And I press "Save"
      And I press "Save"
    Then I should see "The changes have been saved."

    When I go to "user/logout"
      And I visit 'user/login'
      And I fill in "emindhub.test+spiderman@gmail.com" for "name"
      And I fill in "test" for "pass"
      And I press the "Log in" button
    Then I should see the text "Log out"

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/people"
      And I click "edit" in the "Spider MAN" row
      And I press "Cancel account"
      And I press "Cancel account"
      And I wait 5 seconds
      And I follow meta refresh
    Then I should see the text "has been deleted."
