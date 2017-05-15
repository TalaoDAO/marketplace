@api @watchdog
Feature: Emails
  In order to test Emails moderations and notifications
  As a Webmaster, an Administrator, a Client and an Expert
  I want to create a Request, and receive email

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name           | mail                                   | roles         |
    | webmaster1     | emindhub.test+webmaster1@gmail.com     | webmaster     |
    | administrator1 | emindhub.test+administrator1@gmail.com | administrator |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country | field_notification_frequency  |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678                  | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    | Real-time                     |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_position          | field_address:country | field_notification_frequency  |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron           | MAN               | 0712345670                  | Chieur génial    | Avengers     | emindhub.test+expert1@gmail.com | Marvel Studios       | Employee             | Energy        | Avionic Design Engineer | US                    | Real-time                     |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | KENT            | 0712345671                  | Modèle           | Avengers     | emindhub.test+expert2@gmail.com | Marvel Studios       | Employee             | Other         | C.E.O.                  | US                    | Real-time                     |
    | expert3 | emindhub.test+expert3@gmail.com | expert   | Super            | DUPONT          | 0712345672                  | Modèle           | Avengers     | emindhub.test+expert3@gmail.com | Fluide Glacial       | Employee             | Energy        | C.E.O.                  | FR                    | Real-time                     |

    Given the user "client1" is a member of the group "Avengers"
    Given the user "expert1" is a member of the group "Avengers"
    Given the user "expert2" is a member of the group "Avengers"

  @email @nodelay
  Scenario: Webmasters and Administrators are immediately notified, and after the delay, Experts are notified
    Given the test email system is enabled
    Given "request" content:
    | title                       | field_domaine | og_group_ref    | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers        | client1 | 2020-02-08 17:45:00    | 1       |

    Then the last email to "emindhub.test+webmaster1@gmail.com" should contain "Moderate this new request"
      And the last email to "emindhub.test+administrator1@gmail.com" should contain "Moderate this new request"
      And there should be no email to "emindhub.test+expert1@gmail.com" containing "Dear Iron,"

    # 1st Cron run to execute the scheduled notification action
    When I run cron
    # 2nd Cron run to process the notification queue
    When I run cron
    Then the last email to "emindhub.test+expert1@gmail.com" should contain "Dear Iron,"
      And the email should contain "A new request for expertise has been published on eMindHub"
      And the last email to "emindhub.test+expert2@gmail.com" should contain "Dear Klark,"
      And the email should contain "A new request for expertise has been published on eMindHub"

  @email @nodelay
  Scenario: Only experts in french countries are notified by email for new request publication in french
    Given the test email system is enabled
    Given "request" content:
    | title                            | field_domaine | og_group_ref    | author  | field_expiration_date  | status  | language |
    | Comment devenir un super-heros ? | Energy        | Avengers        | client1 | 2020-02-08 17:45:00    | 1       | fr       |

    # 1st Cron run to execute the scheduled notification action
    When I run cron
    # 2nd Cron run to process the notification queue
    When I run cron
    Then there should be no email to "emindhub.test+expert1@gmail.com" containing "Dear Iron,"
      And there should be no email to "emindhub.test+expert1@gmail.com" containing "Cher Iron,"
      And there should be no email to "emindhub.test+expert2@gmail.com" containing "Dear Klark,"
      And there should be no email to "emindhub.test+expert2@gmail.com" containing "Cher Klark,"
      And the last email to "emindhub.test+expert3@gmail.com" should contain "Cher Super,"
      And the email should contain "A new request for expertise has been published on eMindHub"

  @email
  Scenario: After publishing an answer, the Request Author should be notified by email
    Given "request" content:
    | title                            | field_domaine | og_group_ref | author  | field_expiration_date  | status  | language |
    | How to become a superhero?       | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 1       | en       |
    | Comment devenir un super-héros ? | Energy        | Avengers     | client1 | 2020-02-08 17:45:00    | 1       | fr       |

    Given the test email system is enabled

    # An expert responds to the request.
    Given I am logged in as "expert1"
    When I go to homepage
      And I click "How to become a superhero?" in the "content" region
      And I fill in "How to become a superhero?" with "Everybody can be, trust me, I'm the best we known."
      And I press "Publish"
    Then the last email to "emindhub.test+client1@gmail.com" should contain "Dear Captain,"
      And the email should contain "You received a new answer to the request"
    When I go to homepage
      And I click "Comment devenir un super-héros ?" in the "content" region
      And I fill in "Comment devenir un super-héros ?" with "Tout le monde il peut me faire confiance, garanti sur facture."
      And I press "Publish"
    Then the last email to "emindhub.test+client1@gmail.com" should contain "Cher Captain,"
      And the email should contain "Vous avez reçus une réponse à la requête"
      But the last email to "emindhub.test+client1@gmail.com" should not contain "You received a new answer to the request"
