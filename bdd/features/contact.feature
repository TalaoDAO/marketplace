@api @watchdog
Feature: Contact
  In order to test the contact mail
  As an user
  I want to send a mail to contact emindhub

  @email @nodelay
  Scenario: Test if the contact mail was sent
    Given the test email system is enabled
    When I visit '/contact'
      And I fill in "Bruce" for "firstname"
      And I fill in "Wayne" for "lastname"
      And I fill in "emindhub.test+batman@gmail.com" for "mail"
      And I fill in "Gotham City" for "message"
      And I press "Send"
    Then I should see the text "Your message has been sent."
     
    Then the last email to "contact@emindhub.com" should contain "(emindhub.test+batman@gmail.com)"
      And the email should contain "From - Bruce Wayne"
      
      