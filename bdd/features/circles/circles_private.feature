@api @watchdog
Feature: Private Circle
  In order to test the access to private circle
  As an user
  I want to access to my circles

  Background: Create Users & Request

    Given "circle" content:
    | title             | author  | group_access | 
    | Avengers          | admin   | Private      |
    | Justice League    | admin   | Private      |
    | Suicide Squad     | admin   | Public       |

    Given "corporate" content:
    | title                   | author  |
    | Wayne Entreprise        | admin   |
    | Marvel Studios          | admin   |
    | DC Comics               | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education    | og_user_node   | field_mail                      | field_entreprise       | field_working_status | field_domaine | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Bruce            | WAYNE           | 0612345678                  | Chef de groupe     | Justice League | emindhub.test+client1@gmail.com | Wayne Entreprise       | Freelancer           | Maintenance   | US                    |
    | client2 | emindhub.test+client2@gmail.com | business | Peter            | PARKER           | 0612345679                  | Chef de groupe     | Avengers | emindhub.test+client2@gmail.com | Daily Buggle       | Freelancer           | Maintenance   | US                    |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_education  | og_user_node   | field_mail                      | field_entreprise    | field_working_status | field_domaine | field_address:country |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670                  | Chieur génial    | Avengers       | emindhub.test+expert1@gmail.com | Marvel Studios      | Employee             | Energy        | US                    |
    | expert4 | emindhub.test+expert4@gmail.com | expert   | Barry            | Hallen          | 0712345673                  | Eclair rouge     | Justice League | emindhub.test+expert4@gmail.com | DC Comics           | Employee             | Helicopters   | US                    |

    Given "request" content:
    | title                       | field_domaine | og_group_ref   | author  | field_expiration_date  | status  |
    | How to become a superhero?  | Energy        | Avengers       | client2 | 2020-02-08 17:45:00    | 1       |
    | How to stop the Joker?      | Energy        | Justice League | client1 | 2020-02-08 17:45:00    | 1       |
    | How to kill the Batman?     | Energy        | Suicide Squad  | client1 | 2020-02-08 17:45:00    | 1       |

    Given the user "expert1" is a member of the group "Avengers"
    Given the user "expert4" is a member of the group "Justice League"

Scenario:  An authentificated user try to access to a public and private circle 
    Given I am logged in as "expert4"
    When I go to "/circles"
    Then I should not see the text "Avengers"
      And I should see the text "Justice League"
      And I should see the text "Suicide Squad"
      And I should not see the text "Aerospace Valley"
      
    When I go to "content/suicide-squad"
    Then I should see the text "Access denied"
    
    When I go to "content/justice-league"
    Then I should see the text "About this circle"
    
    When I go to "content/avengers"
    Then I should see the text "Access denied"
    
    When I go to homepage
    Then I should see the text "How to stop the Joker?"
      And I should not see the text "How to become a superhero?"
      And I should not see the text "How to kill the Batman?"      
      And I should not see the text "Avengers"
      And I should see the text "Justice League"
      And I should not see the text "Suicide Squad"
      And I should not see "Aerospace Valley"
      
    