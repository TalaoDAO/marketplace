@api @watchdog
Feature: Request Prepopulation
  In order to test Request prepopulation
  As a Client
  I want to create a Request

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

    Given "request_type" terms:
      | name               | description                                      | format        | language | field_prepopulate |
      | Super-Hero mission | Search for a super-hero for a mission or project | filtered_html | en       | edit[field_options][und][questionnaire][enabled]=&edit[field_options][und][private][enabled]=&edit[field_request_questions][und][0][value]=How to become a superhero? |
      | Super-Hero CV | Canvass a community of super-heros to find CVs with rare profiles | filtered_html | en       | edit[field_options][und][questionnaire][enabled]=&edit[field_options][und][private][enabled]=&edit[field_request_questions][und][0][value]=If you want to co-opt please specify: surname / name / current positions&edit[field_request_questions][und][1][value]=How do you know this super-hero?&edit[field_request_questions][und][2][value]=Have you personally worked with this super-hero?&edit[field_request_questions][und][3][value]=Why would you recommend this super-hero?&edit[field_request_questions][und][4][value]=Have you informed the super-hero of your recommendation?&edit[field_request_questions][und][5][value]=Does the applicant agree to have their resume sent to the client requestor?&edit[field_request_questions][und][6][value]=Can the client requestor quote your name when contacting the super-hero? |

    Given I give "client1" 10000 emh credits
    Given the user "client1" is a member of the group "Avengers"

    Given I am logged in as a user with the "administrator" role
    When I go to "admin/emindhub/credits"
      And I fill in "Questionnaire" with "300"
      And I press "Save configuration"

    When I go to "taxonomy/term/768/edit?destination=admin/structure/taxonomy/request_type"
      And I fill in "Prepopulate request URL" with "node/add/request?edit[field_request_type][und][768][768]=768&edit[field_options][und][questionnaire][enabled]=&edit[field_options][und][private][enabled]=&edit[field_request_questions][und][0][value]=If you want to 'co-opt', or recommend someone in your network, please specify: surname / name / current positions, and add the link to their LinkedIn profile&edit[field_request_questions][und][1][value]=How do you know this super-hero?&edit[field_request_questions][und][2][value]=Have you personally worked with this super-hero? If yes, when, and onwhat types of activity?&edit[field_request_questions][und][3][value]=Why would you recommend this super-hero?&edit[field_request_questions][und][4][value]=Have you informed the super-hero of your recommendation?&edit[field_request_questions][und][5][value]=Does the applicant agree to have their resume sent to the client requestor? If yes, please send to cv@emindhub.com with the reference of the client request.&edit[field_request_questions][und][6][value]=Can the client requestor quote your name when contacting the super-hero?"
      And I press "Save"
      Then I should see "Updated term Call"

  @javascript
  Scenario: An author can create a prepopulated request (popin version)
    Given I am logged in as "client1"
    When I go to "node/add/request"
      And I wait for AJAX to finish
      Then the "Request title or question" field should be disabled
    When I click "Search for a super-hero for a mission or project" in the "request_type" region
      And I wait for AJAX to finish
    Then I should see "To get the most from your Super-Hero mission request, we recommend you to use the options below:"
      And the "Private answers" checkbox should be checked
      And the "Questionnaire" checkbox should be checked
      And the "field_request_questions[und][0][value]" field should contain "How to become a superhero?"
      And show me the URL
      And the "Request title or question" field should not be disabled
      #And I should see "400 credits" in the "request_options_total" region

    When I click "Canvass a community of super-heros to find CVs with rare profiles" in the "request_type" region
      And I wait for AJAX to finish
      # Waits until the provided element selector exists in the DOM
      # And I wait until "$element" "$selector" exists
      # And I wait until "div" "#modal-request-type-super-herocv" exists
    Then I should see an "#modal-request-type-super-herocv" element
    When I click "Switch to Super-Hero CV"
      And I wait for AJAX to finish
      Then show me the URL
    Then I should see "To get the most from your Super-Hero CV request, we recommend you to use the options below:"
      And the "Request title or question" field should not be disabled
      And the "Private answers" checkbox should be checked
      And the "Questionnaire" checkbox should be checked
      And the "field_request_questions[und][0][value]" field should contain "If you want to co-opt please specify: surname / name / current positions"
      And the "field_request_questions[und][1][value]" field should contain "How do you know this super-hero?"
      And the "field_request_questions[und][2][value]" field should contain "Have you personally worked with this super-hero?"
      And the "field_request_questions[und][3][value]" field should contain "Why would you recommend this super-hero?"
      And the "field_request_questions[und][4][value]" field should contain "Have you informed the super-hero of your recommendation?"
      And the "field_request_questions[und][5][value]" field should contain "Does the applicant agree to have their resume sent to the client requestor?"
      And the "field_request_questions[und][6][value]" field should contain "Can the client requestor quote your name when contacting the super-hero?"
      And I should see "400 credits" in the "request_options_total" region

    When I select "Avengers" from "Circles"
      And I fill in "Request title or question" with "How to defeat a superhero?"
      And I select "Energy" from "Fields of expertise"
      And I press "Continue"
      And I press "Publish"
    Then I should see "How to defeat a superhero? has been published"
      And I should see "How do you know this super-hero? "
      And I should have 9600 credits on "client1" user

  #Test what can be tested WITHOUT js
  Scenario: An author can create a prepopulated request
    Given I am logged in as "client1"
    When I go to "node/add/request?edit[field_request_type][und][768][768]=768&edit[field_options][und][questionnaire][enabled]=&edit[field_options][und][private][enabled]=&edit[field_request_questions][und][0][value]=If you want to 'co-opt', or recommend someone in your network, please specify: surname / name / current positions, and add the link to their LinkedIn profile&edit[field_request_questions][und][1][value]=How do you know this super-hero?&edit[field_request_questions][und][2][value]=Have you personally worked with this super-hero? If yes, when, and onwhat types of activity?&edit[field_request_questions][und][3][value]=Why would you recommend this super-hero?&edit[field_request_questions][und][4][value]=Have you informed the super-hero of your recommendation?&edit[field_request_questions][und][5][value]=Does the applicant agree to have their resume sent to the client requestor? If yes, please send to cv@emindhub.com with the reference of the client request.&edit[field_request_questions][und][6][value]=Can the client requestor quote your name when contacting the super-hero?"
    Then I should see "To get the most from your Call request, we recommend you to use the options below:"
      And the "Private answers" checkbox should be checked
      And the "Questionnaire" checkbox should be checked
      And the "field_request_questions[und][0][value]" field should contain "If you want to 'co-opt', or recommend someone in your network, please specify: surname / name / current positions, and add the link to their LinkedIn profile"
      And the "field_request_questions[und][1][value]" field should contain "How do you know this super-hero?"
      And the "field_request_questions[und][2][value]" field should contain "Have you personally worked with this super-hero? If yes, when, and onwhat types of activity?"
      And the "field_request_questions[und][3][value]" field should contain "Why would you recommend this super-hero?"
      And the "field_request_questions[und][4][value]" field should contain "Have you informed the super-hero of your recommendation?"
      And the "field_request_questions[und][5][value]" field should contain "Does the applicant agree to have their resume sent to the client requestor? If yes, please send to cv@emindhub.com with the reference of the client request."
      And the "field_request_questions[und][6][value]" field should contain "Can the client requestor quote your name when contacting the super-hero?"

    When I select "Avengers" from "Circles"
      And I fill in "Request title or question" with "How to defeat a superhero?"
      And I select "Energy" from "Fields of expertise"
      And I press "Continue"
      And I press "Publish"
    Then I should see "How to defeat a superhero? has been published"
      And I should see "How do you know this super-hero? "
      And I should have 9600 credits on "client1" user
