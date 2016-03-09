@api
Feature: Create Challenge and answers
  In order to test Challenge creation, and privacy of answers
  As client, expert and référent
  I want to create a Challenge, and watch answers

  Background: Create challenge

    Given "circle" content:
    | title    | author  |
    | Avengers | admin   |

    Given "corporate" content:
    | title     | author  |
    | Google    | admin   |
    | Apple     | admin   |
    | Facebook  | admin   |
    | Twitter   | admin   |
    | Pinterest | admin   |
    | Viadeo    | admin   |
    | Linkedin  | admin   |
    | Tumblr    | admin   |
    | Amazon    | admin   |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | référent1 | referent1@emindhub.com | référent | Paul          | Stanley         | 0612345678      | The Starchild     | Avengers     | referent1@emindhub.com | Amazon  | Other | Maintenance |

    Given users:
    | name    | mail                 | roles    | field_first_name | field_last_name | field_telephone | field_other_areas  | og_user_node | field_mail           | field_entreprise  | field_working_status  | field_domaine |
    | client1 | client1@emindhub.com | business | Captain          | America         | 0612345678      | Chef de groupe     | Avengers     | client1@emindhub.com | Google  | Freelancer | Maintenance |
    | expert1 | expert1@emindhub.com | expert   | Iron             | Man             | 0712345670      | Chieur génial      | Avengers     | expert1@emindhub.com | Facebook  | Employee  | Energy        |
    | expert2 | expert2@emindhub.com | expert   | Klark            | Kent            | 0712345671      | Modèle             | Avengers     | expert2@emindhub.com | Twitter   | Employee  | Other         |

    Given I give "client1" 3000 emh points

    Given "challenge" content:
    | title        | field_domaine | og_group_ref | field_reward | author  | field_anonymous      | field_show_entreprise | field_use_my_entreprise |
    | What about?  | Energy        | Avengers     | 1000         | client1 | Display my full name | Display the name      | Display                 |

    # FIXME: Force user profile update for OG role addition
    Given I am logged in as "référent1"
    And I click "Edit account"
    And I press "Save"

    Given I am logged in as "client1"
    And I click "Edit account"
    And I press "Save"

    Given I am logged in as "expert1"
    And I click "Edit account"
    And I press "Save"

    Given I am logged in as "expert2"
    And I click "Edit account"
    And I press "Save"

    # Make référent1 as a Referent member of Avengers circle
    Given I am logged in as a user with the "administrator" role
    When I go to "content/avengers"
    And I click "Group"
    And I click "People"
    And I click "edit" in the "référent1" row
    And I check the box "Referent member"
    And I press "Update membership"

    # An expert can respond to the challenge
    Given I am logged in as "expert2"
    And I am on the homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    #Then I should see an "Answer" textarea form element
    Given I enter "The truth is elsewhere." for "Answer"
    And I press "Publish"

  Scenario: An author can see its own challenge
    Given I am logged in as "client1"
    And I am on the homepage
    Then I should see "Avengers" in the "What about?" row

    When I go to "my-requests"
    Then I should see "What about?"
    And I should see "1000" in the "What about?" row
    And I should see "Avengers" in the "What about?" row

  Scenario: An author can edit its own challenge
    Given I am logged in as "client1"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Challenge What about?" in the "title" region

    Given I enter "This is my challenge." for "Description"
    And I press "Save"
    Then I should see the success message "Challenge What about? has been updated."

  Scenario: An author cannot delete its own challenge
    Given I am logged in as "client1"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete" in the "actions" region

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

  Scenario: An expert can see its own answer
    Given I am logged in as "expert2"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

  Scenario: The author can see the answer
    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Klark Kent"
    And I should see "The truth is elsewhere." in the "Klark Kent" row

    When I go to the homepage
    Then I should see "1" in the "What about?" row

    When I click "What about?" in the "What about?" row
    #Then I should not see an "Answer" textarea form element
    And I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

  Scenario: A référent can see the answer
    Given I am logged in as "référent1"
    When I go to "content/what-about"
    #Then I should not see an "Answer" textarea form element
    And I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

  Scenario: Experts cannot see Answers tab
    Given I am logged in as "expert1"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    Then I should not see the link "Answers" in the "header" region

  Scenario: Another expert cannot see the answer
    Given I am logged in as "expert1"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    Then I should not see "Klark Kent"
    And I should not see "The truth is elsewhere."

  Scenario: The expert can edit its own answer
    Given I am logged in as "expert2"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    And I click "edit" in the "answers" region
    And I enter "The truth is here." for "Answer"
    And I press "Publish"
    Then I should see "The truth is here."

  Scenario: The author cannot edit an answer
    Given I am logged in as "client1"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    Then I should not see the link "edit" in the "answers" region

  Scenario: A référent cannot edit an answer
    Given I am logged in as "référent1"
    When I go to "content/what-about"
    Then I should not see the link "edit" in the "answers" region

  Scenario: The expert cannot delete its own answer
    Given I am logged in as "expert2"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    Then I should not see "delete" in the "answers" region

  Scenario: The author cannot delete an answer
    Given I am logged in as "client1"
    And I am on the homepage
    When I click "What about?" in the "What about?" row
    Then I should not see "delete" in the "answers" region

  Scenario: A référent cannot delete an answer
    Given I am logged in as "référent1"
    When I go to "content/what-about"
    Then I should not see "delete" in the "answers" region
