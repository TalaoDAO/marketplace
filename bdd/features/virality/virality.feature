@api @watchdog @login
Feature: Request
  In order to test virality
  As a Client and an Expert
  I want to send invitations to join emindhub

  Background: Send invitation

    Given "corporate" content:
      | title                 | author  |
      | Marvel Studios        | admin   |

    Given "circle" content:
      | title    | author  |
      | X-Men    | admin   |

    Given users:
      | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency |
      | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678                  | Chef de groupe     | All experts  | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Aviation   | US                    | Real-time                    |
      | client2 | emindhub.test+client2@gmail.com | business | Charles          | XAVIER       | 0607080901                | Xavier Institute   | X-Men        | emindhub.test+client2@gmail.com | Marvel Studios | Freelancer           | Energy       | US                   | Real-time                    |

    Given users:
      | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency |
      | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670                  | Chieur génial      | All experts  | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Blockchain          | US                  | Real-time                    |

    Given the user "client1" is a member of the group "All experts"
    Given the user "expert1" is a member of the group "All experts"
    Given the user "client2" is a member of the group "X-Men"

    Given I give "client1" 500 emh credits

    Given "request" content:
      | title                       | field_domaine     | og_group_ref    | author  | field_expiration_date  | status  |
      | How to become a superhero?  | Blockchain        | All experts     | client1 | 2020-02-08 17:45:00    | 1       |
      | How to join the x-men?      | Blockchain        | X-Men           | client2 | 2020-02-08 18:45:00    | 1       |

  @email @nodelay @invitation
  Scenario: An author can send a general invitation
    Given the test email system is enabled
    Given I am logged in as "client1"
    When I go to homepage
    And I should see "Referral"
    And I click "Invite experts" in the "content" region
    Then I should see "Invite experts and earn credits!"

    Given I fill in "Bruce" for "First Name"
    And I fill in "Wayne" for "Last Name"
    And I fill in "emindhub.test+batman@gmail.com" for "Mail"
    And I press "Add one more"
    When I fill in "Kent" for "sponsorship_fieldset[expert][1][last_name]"
    And I fill in "Clark" for "sponsorship_fieldset[expert][1][first_name]"
    And I fill in "emindhub.test+superman@gmail.com" for "sponsorship_fieldset[expert][1][mail]"
    And I press the "emh-virality-send-invitation" button
    Then I should see the message "You just sent invitations to:"
    And I should see "emindhub.test+batman@gmail.com"
    And I should see "emindhub.test+superman@gmail.com"
    And I should see "Invited"
    And the last email to "emindhub.test+batman@gmail.com" should contain "Captain AMERICA invites you to join eMindHub"
    And the last email to "emindhub.test+superman@gmail.com" should contain "Captain AMERICA invites you to join eMindHub"


  Scenario: A client cannot access invitation page from a request
    Given I am logged in as "client2"
    When I go to homepage
    And I click "How to join the x-men?" in the "content" region
    Then I should not see the button "Recommand an expert"

  @email @nodelay
  Scenario: An user send an invitation to new user that endup validated.
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/credits"
    Then I fill in "Cost of profile purchase" with "100"
      And I press "Save configuration"

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/credits/earnings/settings"
    Then I fill in "Context: profile_buy" with "0.7"
    And I fill in "Context: user_sponsor" with "0.7"
    And I press "Save configuration"

    Given the test email system is enabled
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "How to become a superhero?" in the "content" region
    And I click "Recommand an expert" in the "content" region
    Then I should see "How to become a superhero?"
    When I fill in "Barry" for "First Name"
    And I fill in "Allen" for "Name"
    And I fill in "emindhub.test+flash@gmail.com" for "Mail"
    And I fill in "Hello Flash, join us" for "Message"
    And I press the "emh-virality-send-invitation" button
    Then I should see the message "You just sent invitations to:"
    And I should see "emindhub.test+flash@gmail.com"
    And I should see "Invited"
    And the last email to "emindhub.test+flash@gmail.com" should contain "Hello Barry,"
    And the email should contain "Hello Flash, join us"

    #Same test but with generic email
    When I go to homepage
    And I click "How to become a superhero?" in the "content" region
    And I click "Recommand an expert" in the "content" region
    Then I should see "How to become a superhero?"
    When I fill in "Bruce" for "First Name"
    And I fill in "Wayne" for "Name"
    And I fill in "emindhub.test+batman@gmail.com" for "Mail"
    And I press the "emh-virality-send-invitation" button
    And the last email to "emindhub.test+batman@gmail.com" should contain "recommanded"

    When I visit "user/logout"
    And I visit 'expert/register'
    And I fill in "Barry" for "First Name"
    And I fill in "Allen" for "Last Name"
    And I fill in "emindhub.test+flash@gmail.com" for "mail"
    And I fill in "test" for "pass[pass1]"
    And I fill in "test" for "pass[pass2]"
    And I check the box "I agree to the Terms of use document"
    And I press the "Create new account" button
    Then I should see the text "A confirmation message with further instructions has been sent to your e-mail address."

    Given I am logged in as the admin
    When I go to "admin/people"
    And I click "edit" in the "Barry ALLEN" row
    And I select the radio button "Member"
    And I select "France" from "Country"
    And I fill in "Airbus" for "field_entreprise[und][0][target_id]"
      #Notice: "Position" don't work because it's exists also in "Last position(s)" group field
    And I fill in "academics" for "field_position[und]"
    And I select "Freelancer" from "Working status"
    And I fill in "2247" for "Domain"
    And I press "Save"
    And I press "Save"
    Then I should see "The changes have been saved."

    Given I am logged in as "expert1"
    When I click "Referral"
    Then I should see "emindhub.test+flash@gmail.com"
    And I should see "Registered"

    When I go to "user/logout"
    And I visit 'user/login'
    And I fill in "emindhub.test+flash@gmail.com" for "name"
    And I fill in "test" for "pass"
    And I press the "Log in" button
    Then I should see the text "Log out"

    When I go to homepage
    And I click "How to become a superhero?" in the "content" region
    And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
    And I press "Publish"

    Given I am logged in as "expert1"
    When I click "Referral"
    Then I should see "emindhub.test+flash@gmail.com"
    And I should see "Answered to a request"

    Given I am logged in as "client1"
    When I go to homepage
    And I click "How to become a superhero?" in the "content" region
    And I click "Access profile for 100 credits" in the "content" region
    Then I press "Access profile"

    Given I am logged in as "expert1"
    When I click "Referral"
    Then I should see "emindhub.test+flash@gmail.com"
    And I should see "Validated"

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/credits/transaction-log"
    Then I should see "eMindHub rewards Iron MAN for a validated invitation"
    And I should see "Move credits from Barry Allen to eMindHub."
    And I should see "Captain AMERICA buy Barry Allen profile on \"How to become a superhero?\" request"
    And I should have "400" credits on "client1" user
    And I should have "15" earnings on "expert1" user
    And I should have "30" earnings on "emindhub.test+flash@gmail.com" user mail


  @invitation
  Scenario: Delete new user
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/people"
    And I click "edit" in the "Barry ALLEN" row
    And I press "Cancel account"
    And I press "Cancel account"
    And I wait 5 seconds
    And I follow meta refresh
    Then I should see the text "has been deleted."
