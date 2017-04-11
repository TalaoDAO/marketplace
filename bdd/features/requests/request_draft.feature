@api @watchdog
Feature: Request as draft
  In order to test draft Request
  As a Request author and Circle admin
  I want to check that I can or cannot save a request as draft depending on context

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
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_position          |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy        | Avionic Design Engineer |

    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Administrate" in the "primary tabs" region
      And I click "People" in the "content" region
      And I click "edit" in the "Captain AMERICA" row
      And I select "Member" from "Status"
      And I press "Update membership"
    Then I should see "Member" in the "Captain AMERICA" row
      And I should see "The membership has been updated."
    When I click "edit" in the "Iron MAN" row
      And I select "Member" from "Status"
      And I check the box "administrator member"
      And I press "Update membership"
    Then I should see "The membership has been updated."

  Scenario: The Author can work on its own draft Request until its publication.
    Given "request" content:
    | title                                 | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?            | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 0       | Mission            |

    Given I am logged in as "client1"
    When I go to "requests/manage"
    Then I should see "Draft" in the "How to become a superhero?" row

    When I click "How to become a superhero?" in the "How to become a superhero?" row
      And I click "Edit" in the "primary tabs" region
      And I enter "Please join pictures." for "Describe your request"
      And I press "Save draft"
      And I go to "requests/manage"
    Then I should see "Draft" in the "How to become a superhero?" row

    When I click "How to become a superhero?" in the "How to become a superhero?" row
      And I click "Edit" in the "primary tabs" region
      And I press "Continue"
      And I press "Publish"
      And I click "Edit" in the "primary tabs" region
    Then I should not see "Save draft"

    When I go to "requests/manage"
    Then I should see "Open" in the "How to become a superhero?" row

  Scenario: The Circle Admin can unpublish Request if no Expert answered yet.
    Given "request" content:
    | title                                 | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?            | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 1       | Mission            |

    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "How to become a superhero?" row
      And I click "Edit" in the "primary tabs" region
      And I press "Save draft"
      And I go to homepage
    Then I should not see "How to become a superhero?"

    Given I am logged in as "client1"
    When I go to "requests/manage"
    Then I should see "Draft" in the "How to become a superhero?" row
