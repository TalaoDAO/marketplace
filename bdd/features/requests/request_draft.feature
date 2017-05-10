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
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Marvel Studios       | Employee             | Other         | C.E.O.                  |

    Given I am logged in as a user with the "administrator" role
      And the user "client1" is a member of the group "Avengers"
      And the user "expert1" is a member of the group "Avengers"
      And the user "expert2" is a member of the group "Avengers"

  Scenario: The Author can work on its own draft Request until its publication.
    Given "request" content:
    | title                                 | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?            | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 0       | Mission            |

    Given I am logged in as "client1"
    When I go to "requests/manage"
    Then I should see "Draft" in the "content" region

    When I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
      And I enter "Please join pictures." for "Describe your request"
      And I press "Save as draft"
      And I go to "requests/manage"
    Then I should see "Draft" in the "content" region

    When I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
      And I press "Continue"
      And I press "Publish"
      And I click "Edit" in the "primary tabs" region
    Then I should not see "Save as draft"

    When I go to "requests/manage"
    Then I should see "Open" in the "content" region

  Scenario: The Circle Admin can unpublish Request if no Expert answered publicly yet.
    Given "request" content:
    | title                                 | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?            | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 1       | Mission            |

    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
      And I press "Unpublish"
    Then I should not see "How to become a superhero?" in the "content" region

    Given I am logged in as "client1"
    When I go to "requests/manage"
    Then I should see "Draft" in the "content" region

    When I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
      And I press "Continue"
      And I press "Publish"

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Publish"

    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
    Then the "Unpublish" link or button should be disabled

  Scenario: The Circle Admin cannot unpublish Request if credits are allocated.
    Given I give "client1" 1000 emh credits

    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Administrate" in the "primary tabs" region
      And I click "Circle" in the "content" region
      And I fill in "Duration" with "1000"
      And I press "Save"

    Given "request" content:
    | title                                 | field_domaine | og_group_ref | author  | field_expiration_date  | status  | field_request_type |
    | How to become a superhero?            | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 0       | Mission            |

    Given I am logged in as "client1"
    When I go to "requests/manage"
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
      And I check the box "Duration"
      And I fill in "Duration of the mission" with "1 month"
      And I press "Continue"
      And I press "Publish"

    Given I am logged in as "expert2"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I click "Edit" in the "primary tabs" region
    Then the "Unpublish" link or button should be disabled
