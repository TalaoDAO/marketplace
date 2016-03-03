@api
Feature: Create challenge and answers
  In order to test Challenge creation, and privacy of answers
  As client, expert and référent
  I want to create a Challenge, and watch answers

  Background: Create challenge

    Given "circle" content:
    | title    | author  |
    | Avengers | admin |

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

    Given I give "client1" 300 emh points

    Given "challenge" content:
    | title        | field_domaine | og_group_ref | field_reward | author  |
    | What about?  | Energy        | Avengers     | 100          | client1 |

  @exclude
  Scenario: Check challenge answers privacy
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I enter "I'm the best superhero in da world." for "Answer"
    And I press "Publish"
    And I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "I'm the best superhero in da world."

    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "I'm the best superhero in da world."

    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "I'm the best superhero in da world."

    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Answers" in the "title" region


  Scenario: An author can see its own challenge
    Given I am logged in as "client1"
    When I go to homepage
    Then I should see "Avengers" in the "What about?" row

    When I go to "my-requests"
    Then I should see "My request"
    And I should see "What about?"
    And I should see "100" in the "What about?" row
    And I should see "Avengers" in the "What about?" row

  Scenario: An admin can see the challenge
    Given I am logged in as a user with the "administrator" role
    And I go to "admin/content"
    Then I should see "What about?"

  Scenario: A référent can see the challenge
    Given I am logged in as "référent1"
    When I go to homepage
    Then I should see "What about?" in the "What about?" row

  Scenario: A référent can edit a challenge
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should see "Edit Question What about?"

    Given I enter "This is my challenge." for "Description"
    And I press "Save"
    Then I should see the success message "Question What about? has been updated."

  Scenario: A référent cannot delete a challenge
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "primary tabs" region
    Then I should not see "Delete"

  Scenario: A référent cannot respond to a challenge
    Given I am logged in as "référent1"
    When I go to homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    Then I should not see "Answer the challenge"

  Scenario: An expert responds to a challenge
    Given I am logged in as "expert2"
    When I go to homepage
    Then I should see "What about?"

    When I click "What about?" in the "What about?" row
    And I should see "Answer the challenge"
    Given I enter "The truth is elsewhere." for "Private answer"
    And I select the radio button "My answer will be visible only by the client"
    And I press "Publish"

    # An expert can see its own answer
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

    # The author can see the answer
    Given I am logged in as "client1"
    When I go to "my-responses"
    Then I should see "Klark Kent"
    And I should see "The truth is elsewhere." in the "Klark Kent" row

    When I go to homepage
    Then I should see "1" in the "What about?" row

    When I click "What about?" in the "What about?" row
    Then I should not see "Answer the challenge"
    And I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

    # A référent can see the answer
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Answer the challenge"
    And I should see "Answers"
    And I should see "Klark Kent"
    And I should see "The truth is elsewhere."

    # Another expert cannot see the answer
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should see "Private answer from another expert."
    And I should not see "Klark Kent"
    And I should not see "The truth is elsewhere."

    # The expert can edit its own answer
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    And I click "Edit" in the "answers" region
    And I enter "The truth is here." for "answer"
    And I select the radio button "My answer will be visible only by the client"
    And I press "Publish"
    Then I should see "The truth is here."

    # The author cannot edit a answer
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Edit" in the "answers" region

    # A référent cannot edit a answer
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Edit" in the "answers" region

    # An other expert cannot edit a answer
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Edit" in the "answers" region

    # The expert cannot delete its own answer
    Given I am logged in as "expert2"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Delete" in the "answers" region

    # The author cannot delete a answer
    Given I am logged in as "client1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Delete" in the "answers" region

    # A référent cannot delete a answer
    Given I am logged in as "référent1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Delete" in the "answers" region

    # An other expert cannot delete a answer
    Given I am logged in as "expert1"
    When I go to homepage
    And I click "What about?" in the "What about?" row
    Then I should not see "Delete" in the "answers" region
