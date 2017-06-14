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
      And I visit "/user/6195/edit"  
    Then I should see "LinkedIn"
    
    When I fill in "coucou" for "field_address[und][0][locality]"
      And I press the "edit-submit" button
    Then I should see "The changes have been saved."
    
    When I visit "/user/6195/edit/emh_linkedin"
      And I check the box "location"
      And I press the "edit-submit" button
    Then I should see "The configuration options have been saved."
    
    When I press the "edit-submit--2" button
    Then I should see "Successful update"
    
    When I visit "/user/6195"
    Then I should see "TOULOUSE"
    
    When I visit "/user/logout"
      #And I click "Log out"
    Then I should not see "Log out"
 
    
