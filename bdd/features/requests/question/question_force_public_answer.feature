@api @watchdog
Feature: Create Question with forced public answers
  In order to test Question with forced public answers
  As a client and an expert
  I want to create a question and force answers to be public

  Background: Create questions

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Facebook  | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert1 | emindhub.test+expert1@gmail.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | emindhub.test+expert1@gmail.com | Facebook  | Employee  | Energy        |

    Given I give "client1" 300 emh points

    Given "question1" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise | field_force_public_answer |
    | What about?  | Energy        | Avengers     | 100          | client1 | Display my full name | Display the name      | Display                 | 1 |

  Scenario: An expert responds to a question
    Given I am logged in as "expert1"
    When I go to homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    #Then I should see an "Answer visibility" radio form element
    Given I enter "I'm the best superhero in da world." for "Public answer"
    And I should not see "Private answer"
    And I press "Publish"
