@api @watchdog
Feature: Challenge for Référent
  In order to test Challenge CRUD and answers privacy
  As a Référent
  I want to manage a Challenge, and watch answers

  Background: Create challenge

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Twitter   | admin   |
    | Amazon    | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | référent1 | emindhub.test+referent1@gmail.com | référent | Paul          | Stanley         | 0612345678      | The Starchild     | Avengers     | emindhub.test+referent1@gmail.com | Amazon  | Other | Maintenance |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | emindhub.test+client1@gmail.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | emindhub.test+client1@gmail.com | Google  | Freelancer | Maintenance |
    | expert2 | emindhub.test+expert2@gmail.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | emindhub.test+expert2@gmail.com | Twitter   | Employee  | Other         |

    Given I give "client1" 3000 emh points

    Given "challenge" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Energy        | Avengers     | 1000         | client1 | Display my full name | Display the name      | Display                 |

    # Make référent1 as a Referent member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "Paul Stanley" row
    And I check the box "Referent member"
    And I press "Update membership"
    Then I should see "The membership has been updated."

    # An expert can respond to the challenge
    Given I am logged in as "expert2"
    And I am on the homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    #Then I should see an "Answer" textarea form element
    Given I enter "The truth is elsewhere." for "Answer"
    And I press "Publish"

  Scenario: A référent can see the challenge
    Given I am logged in as "référent1"
    And I am on the homepage
    Then I should see "What about?" in the "What about?" row

  Scenario: A référent can edit the challenge
    Given I am logged in as "référent1"
    When I go to "content/what-about"
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Challenge What about?" in the "title" region

    Given I enter "This is your challenge." for "Description"
    And I press "Save"
    Then I should see the success message "Challenge What about? has been updated."

  Scenario: A référent cannot delete the challenge
    Given I am logged in as "référent1"
    When I go to "content/what-about"
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

  Scenario: A référent cannot respond to the challenge
    Given I am logged in as "référent1"
    When I go to "content/what-about"
    #Then I should not see an "Answer" textarea form element

  Scenario: A référent can see the answer
    Given I am logged in as "référent1"
    When I go to "content/what-about"
    #Then I should not see an "Answer" textarea form element
    And I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

  Scenario: A référent cannot edit an answer
    Given I am logged in as "référent1"
    When I go to "content/what-about"
    Then I should not see the link "edit" in the "answers" region

  Scenario: A référent cannot delete an answer
    Given I am logged in as "référent1"
    When I go to "content/what-about"
    Then I should not see "delete" in the "answers" region
