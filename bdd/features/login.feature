@api @watchdog
Feature: Login test
  In order to test the login process
  As an anonymous user
  I want to check if I can log in

  Scenario: Login with custom parameters in query
    Given "circle" content:
    | title    | author  |
    | X-Men    | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | ENAC Alumni     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise   | field_working_status | field_domaine | field_address:country |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | ENAC Alumni     | emindhub.test+expert1@gmail.com | Marvel Studios     | Employee             | Energy        | US                  |
    | expert4 | emindhub.test+expert4@gmail.com | expert   | Scott            | SUMMERS         | 0712345673      | Bucheron           | X-Men        | emindhub.test+expert4@gmail.com | Marvel Entertainment | Employee  | Helicopters   | US                 |

    Given the user "expert1" is a member of the group "ENAC Alumni"
    Given the user "expert4" is a member of the group "X-Men"

    Given I am logged in as the admin
    When I go to "admin/people"
      And I click "edit" in the "Iron MAN" row
      And I click "Change password"
      And I fill in "test" for "pass[pass1]"
      And I fill in "test" for "pass[pass2]"
      And I press "Submit"
    Then I should see "Your password has been changed."

    When I go to "admin/people"
      And I click "edit" in the "Scott SUMMERS" row
      And I click "Change password"
      And I fill in "test" for "pass[pass1]"
      And I fill in "test" for "pass[pass2]"
      And I press "Submit"
    Then I should see "Your password has been changed."

    # Case 1: I can access to this Request.
    When I go to "user/logout"
      And I visit "user/login?destination=node/2199?pk_campaign=emh_request_notify_new_request_users_3585&utm_medium=email&utm_source=emh_request_notify_new_request_users&utm_campaign=emh_request_notify_new_request_users_3585&pk_kwd=link&utm_content=link"
      And I fill in "expert1" for "name"
      And I fill in "test" for "pass"
      And I press the "Log in" button
    Then I should see "What are the remaining obstacles to the use of drones in commercial activities such as home delivery services?"

    # Case 2: I cannot access to this Request.
    When I go to "user/logout"
      And I visit "user/login?destination=node/2199?pk_campaign=emh_request_notify_new_request_users_3585&utm_medium=email&utm_source=emh_request_notify_new_request_users&utm_campaign=emh_request_notify_new_request_users_3585&pk_kwd=link&utm_content=link"
      And I fill in "expert4" for "name"
      And I fill in "test" for "pass"
      And I press the "Log in" button
    Then I should see "Access denied"
