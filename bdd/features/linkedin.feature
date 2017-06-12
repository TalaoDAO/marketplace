@api @watchdog
Feature: Update LinkdeIn data test
  In order to test the update user profiles with the linkedin account information
  As an authenticated user
  I want to update my profile with LinkedIn
  
Background: Create request

  Given users:
      | name              | mail                  | roles    | field_first_name | field_last_name | field_linkedin |
      | Benjamin GAGNAIRE | be.gagnaire@gmail.com | expert   | Benjamin         | GAGNAIRE        | coucou         |


Scenario: Test if upadte works
  Given I am logged in as "Benjamin GAGNAIRE"
  When I click "Edit my account"
  Then I should see "Linkedin"
  
  When I press "Linkedin"
  Then I should see "LINKEDIN FIELDS"