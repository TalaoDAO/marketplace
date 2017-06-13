@api @watchdog
Feature: Update LinkdeIn data test
  In order to test the update user profiles with the linkedin account information
  As an authenticated user
  I want to update my profile with LinkedIn


  @javascript
  Scenario: An expert without certain profile fields filled can access request by filling a form
    
    When I visit '/hybridauth/window/LinkedIn?destination=node/323&destination_error=node/323&width=800&height=500&iframe=true'
      And I fill in "be.gagnaire@gmail.com" for "mail"      
      And I fill in "jeffEtLester31" for "session_password"
      And I press the "authorize" button      
      And I wait for AJAX to finish     
    Then I should not see "Closing..."
 
    
