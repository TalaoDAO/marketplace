@api @watchdog
Feature: Update LinkdeIn data test
  In order to test the update user profiles with the linkedin account information
  As an authenticated user
  I want to update my profile with LinkedIn


  @javascript
  Scenario: An expert without certain profile fields filled can access request by filling a form
    
    
    When I visit "/user/logout"
      #And I click "Log out"
    Then I should not see "Log out"
 
    
