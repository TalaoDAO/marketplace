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
      | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678                  | Chef de groupe     | All experts  | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    | Real-time                    |
      | client2 | emindhub.test+client2@gmail.com | business | Charles          | XAVIER       | 0607080901                | Xavier Institute   | X-Men        | emindhub.test+client2@gmail.com | Marvel Studios | Freelancer           | Engines       | US                   | Real-time                    |

    Given users:
      | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency |
      | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670                  | Chieur génial      | All experts  | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Blockchain          | US                  | Real-time                    |

    Given the user "client1" is a member of the group "All experts"
    Given the user "expert1" is a member of the group "All experts"
    Given the user "client2" is a member of the group "X-Men"

    Given "request" content:
      | title                       | field_domaine | og_group_ref    | author  | field_expiration_date  | status  |
      | How to become a superhero?  | Blockchain        | All experts     | client1 | 2020-02-08 17:45:00    | 1       |

  @email @nodelay
  Scenario: An author can to send a general invitation
    Given I am logged in as "client1"
    When I go to homepage
    And I click "Invite experts" in the "content" region
    Then I should see "Invite experts and earn credits!"

    Given I fill in "Bruce" for "First Name"
    And I fill in "Wayne" for "Name"
    And I fill in "emindhub.test+batman@gmail.com" for "Mail"
    And I press "Add one more"
    When I fill in "Kent" for "sponsorship_fieldset[expert][1][name]"
    And I fill in "Clark" for "sponsorship_fieldset[expert][1][first_name]"
    And I fill in "emindhub.test+superman@gmail.com" for "sponsorship_fieldset[expert][1][mail]"
    And I press the "edit-submit" button
    Then I should see the message "You just sent invitations to:"
    And I should see "emindhub.test+batman@gmail.com"
    And I should see "emindhub.test+superman@gmail.com"
    And I should see "Invitation sent."

  @email @nodelay
  Scenario: An author can to send a invitation about a request
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "How to become a superhero?" in the "content" region
    And I click "Invite experts" in the "content" region
    Then I should see "How to become a superhero?"

    Given I fill in "Barry" for "First Name"
    And I fill in "Hallen" for "Name"
    And I fill in "emindhub.test+flash@gmail.com" for "Mail"
    And I fill in "Hello, I'm Flash" for "Message"
    And I press the "edit-submit" button
    Then I should see the message "You just sent invitations to:"
    And I should see "emindhub.test+flash@gmail.com"
    And I should see "Invitation sent."
    And the last email to "emindhub.test+flash@gmail.com" should contain "Hello Barry,"
    And the email should contain "Hello, I'm Flash"

  #Scenario: An author can edit its own request
  #  Given I am logged in as "client1"
  #  When I go to homepage
  #  And I click "How to become a superhero?" in the "content" region
  #  And I click "Edit" in the "primary tabs" region
  #  And I select "770" from "field_request_type[und]"
  #  Then I should see "Edit Request How to become a superhero?" in the "title" region

  #  Given I enter "This is my request." for "Describe your request"
  #  And I press "Save"
  #  Then I should see the success message "Request How to become a superhero? has been updated."
