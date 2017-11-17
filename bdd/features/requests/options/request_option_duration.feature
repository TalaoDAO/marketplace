@api @watchdog
Feature: Request and answers
  In order to test Request with Duration option
  As a Client and an Expert
  I want to create a request, and watch Duration informations

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios     | Employee             | Blockchain        |

    Given "request" content:
    | title                       | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?  | Blockchain        | Avengers     | client1 | 2020-02-08 17:45:00    | 0       | Mission            |

    Given I give "client1" 10000 emh credits
    Given the user "client1" is a member of the group "Avengers"
    Given the user "expert1" is a member of the group "Avengers"

    # Activate option
    Given I am logged in as "client1"
    When I go to "requests/manage"
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
    Given I check "Duration"
      And I enter "6 months" for "Duration of the mission"
      And I enter "07/06/2017" for "Date"
      And I press "Continue"
    # Validation page
      And I press "Publish"
    Then I should see the success message "Request How to become a superhero? has been published."

  Scenario: The author can see Duration option infos
    Given I am logged in as "client1"
    When I go to "requests/manage"
      And I click "How to become a superhero?" in the "content" region
    Then I should see "6 months"
      And I should see "2017/07/06"

  Scenario: An expert can see Duration option infos
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
    Then I should see "6 months"
      And I should see "2017/07/06"
