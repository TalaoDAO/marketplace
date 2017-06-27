@api @watchdog
Feature: Forgot Password
  In order to test the redirection for reset a password
  As an user in circle Smart Mobility
  I want to reset my password

  Background: Create Users & Request

    Given "circle" content:
    | title          | author  |
    | Smart Mobility | admin   |
       

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise   | field_working_status | field_domaine | field_address:country |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Bruce            | WAYNE           | 0712345670      | Justicier      | Smart Mobility     | emindhub.test+expert1@gmail.com | DC Comics     | Employee             | Energy        | US                  |
   
    Given the user "expert1" is a member of the group "Smart Mobility"
    

  Scenario: Test if an member at emindhub can to reset his password
  
    Given the test email system is enabled
    When I visit '/smart-mobility/'
      And I click "Forgot your password?"
      And I fill in "emindhub.test+expert1@gmail.com" for "name"
      And I press "op"
    Then the last email to "emindhub.test+expert1@gmail.com" should contain "Dear Bruce"
      And the email should contain "A request to reset the password for your account"
 
 # Scenario: Test if a non member at emindhub can to reset his password
      
    Given the test email system is enabled
    When I visit '/smart-mobility/'
      And I click "Forgot your password?"
      And I fill in "jenesuispaschezemindhub@gmail.com" for "name"
      And I press "op"
    Then there should be no email to "jenesuispaschezemindhub@gmail.com" containing "A request to reset the password for your account"
      And I should see the text "Sorry, jenesuispaschezemindhub@gmail.com is not recognized as a user name or an e-mail address."