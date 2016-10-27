@api @watchdog
Feature: Request
  In order to test Request creation
  As a Client and an Expert
  I want to create a Request, and watch submissions

  Background: Create request

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title                 | author  |
    | Marvel Studios        | admin   |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | AMERICA         | 0612345678      | Chef de groupe     | Avengers  | emindhub.test+client1@gmail.com | Marvel Studios       | Freelancer           | Maintenance   | US                    |

    Given users:
    | name    | mail                            | roles    | field_first_name | field_last_name | field_address:mobile_number | field_other_areas  | og_user_node | field_mail                      | field_entreprise     | field_working_status | field_domaine | field_address:country |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | MAN             | 0712345670      | Chieur génial      | Avengers  | emindhub.test+expert1@gmail.com | Marvel Studios     | Employee             | Energy          | US                    |

#    Given "request" content:
#    | title                       | field_domaine | og_group_ref    | author  | field_expiration_date  | status  |
#    | How to become a superhero?  | Energy        | All experts     | client1 | 2017-02-08 17:45:00    | 1       |

    Given I give "client1" 10000 emh credits

    # Make client1 as a Creator member of All experts circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
      And I click "edit" in the "Captain AMERICA" row
      And I select "Active" from "Status"
      And I check the box "Creator member"
      And I press "Update membership"
      # Again...
      And I go to "content/avengers"
      And I click "Group"
      And I click "People"
      And I click "Member since"
      # Twice for correct order
      And I click "Member since"
    Then I should see "Creator member" in the "Captain AMERICA" row
      And I click "edit" in the "Iron MAN" row
      And I select "Active" from "Status"
      And I press "Update membership"
    Then I should see "The membership has been updated."

  Scenario: An author can see its own request
    Given I am logged in as "client1"
    When I go to "/node/add/request?edit[field_options][und][questionnaire][enabled]=&edit[field_options][und][private][enabled]=&edit[field_options][und][questionnaire][enabled]=&edit[field_request_questions][und]['0'][value]=How to become a superhero%3F&edit[field_request_type][und]=Expert"
      Then the "Questionnaire" checkbox should be checked
      And the "Private submissions" checkbox should be checked
    #TODO : Should work, but dont ...
    #And I should see "How to become a superhero?" 
    #And the "Questions" element should contain "How to become a superhero?"
    #And the "Questions" element should contain "How to become a superhero?"
    When I select "Avengers" from "Circles"
      And I fill in "Request title or question" with "How to defeat a superhero?"
      And I select "Energy" from "Fields of expertise"
      And I press "Continue"
      And I press "Publish"
    Then I should see "How to defeat a superhero? has been published"
      And I should see "How to become a superhero?"
