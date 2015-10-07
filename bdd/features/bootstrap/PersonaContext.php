<?php

/**
 * @file
 *
 * Add this code in a file features/bootstrap/PersonaContext.php
 *
 * Include the PersonaContext in behat.yml like this ...
 *
 * default:
 *   suites:
 *     default:
 *       contexts:
 *         - PersonaContext
 *
 * Add a personas.ini file features/bootstrap/personas.ini
 *
 *
 * [Amanda Anonymous]
 * ; Amanda represents the anonymous user.
 * is_anonymous = true
 *
 * [Andy Admin]
 * ; Andy Admin has full access
 * account[name] = "andy_admin"
 * account[mail] = "andy_admin@example.com"
 * account[status] = "1"
 * roles[] = "Administrator"
 * ; You can also set fields like this
 * field_first_name = "Andy"
 * field_last_name = "Admin"
 * ; Not all fields will work, but address field does!
 * field_address[thoroughfare] = "101 Coronation Street"
 * field_address[premise] = "Bag end"
 * field_address[locality] = "Manchester"
 * field_address[administrative_area] = "Lancashire"
 * field_address[postal_code] = "BB1 1BB"
 * ; Taxonomy reference is a bit more complicated - the syntax for this file
 * ; is as follows.
 * field_some_tag[tid] = "Example tag"
 * ; You also need to make a file at features/bootstrap/taxonomy.ini with
 * ; the value below in it.
 *
 * Contents of features/bootstrap/taxonomy.ini
 *
 * [Example tag]
 * name = "Example tag"
 * vocabulary_machine_name = "tags"
 *
 * In your FeaturesContext.php you will want to add this function, make sure you
 * close the doc comment at the top of it!
 *
 *   /** @BeforeScenario
 *  public function gatherContexts(BeforeScenarioScope $scope) {
 *    $environment = $scope->getEnvironment();
 *    $this->personaContext = $environment->getContext('PersonaContext');
 *    $this->personaContext->setDrupalContext($this);
 *  }
 *
 * You should now be able to use:
 * Given I am logged in as persona "Andy Admin"
 *
 * @todo Need to have a generic way of allowing entities to be defined in
 * ini files and then be referenced from each other.
 */

use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalDriverManager;
use Behat\Mink\Exception\ExpectationException;
use Drupal\DrupalExtension\Context\MinkContext;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;
use Drupal\DrupalExtension\Context\DrupalContext;
use Drupal\DrupalExtension\Context\RawDrupalContext;

class PersonaContext implements DrupalSubContextInterface {

  /** @var \Drupal\DrupalDriverManager */
  private $drupal;

  /** @var array */
  public $personas = array();

  /** @var array */
  public $users = array();

  /** @var MinkContext */
  private $minkContext;

  /** @var DrupalContext */
  private $drupalContext;

  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /** @BeforeScenario */
  public function gatherContexts(BeforeScenarioScope $scope) {
    $environment = $scope->getEnvironment();
    $this->minkContext = $environment->getContext('Drupal\DrupalExtension\Context\MinkContext');
  }

  public function setDrupalContext(RawDrupalContext $drupalContext) {
    $this->drupalContext = $drupalContext;
  }

  public function getDrupalContext() {
    if (empty($this->drupalContext)) {
      throw new Exception(t('You need to register you DrupalContext object with the PersonaContext via setDrupalContext'));
    }
    return $this->drupalContext;
  }

  /**
   * @return \Drupal\Driver\DrupalDriver
   */
  public function getDriver() {
    return $this->drupal->getDriver();
  }

  /**
   * Remove any created users.
   *
   * @AfterScenario
   */
  public function cleanPersonas() {
    // Remove any users that were created.
    if (!empty($this->users)) {
      foreach ($this->users as $user) {
        $this->getDriver()->userDelete($user);
      }
      $this->getDriver()->processBatch();
      $this->users = array();
    }
  }

  /**
   * @Given there is a persona user account for :persona
   *
   * Get a persona Drupal user given their persona name.
   *
   * This will create the Drupal user or retrieve an existing user
   * if they exist.
   *
   * @param string $persona
   *   The persona name
   *
   * @throws ExpectationException
   * @throws Exception
   * @return object
   *   Drupal user object (note this might be the anonymous user)
   */
  public function getPersonaUser($persona) {

    if (empty($this->personas)) {
      // @todo Use YAML rather than ini - maybe just put it in the behat.yml?
      $this->personas = parse_ini_file("personas.ini", TRUE);
    }

    // @todo make creation of other entities more extensible.
    if (!isset($this->terms)) {
      $this->terms = array();

      foreach (parse_ini_file("taxonomy.ini", TRUE) as $term_name => $term) {
        $term = (object) $term;
        $this->terms[$term_name] = $this->getDrupalContext()->termCreate($term);
      }
    }

    // If the persona doesn't exist then throw exception.
    if (!isset($this->personas[$persona])) {
      $message = sprintf('Unknown persona: %s.', $persona);
      throw new ExpectationException($message, $this->minkContext->getSession());
    }

    if (!empty($this->personas[$persona]['is_anonymous'])) {
      return drupal_anonymous_user();
    }

    // If the user doesn't exist create the account.
    if (!array_key_exists($persona, $this->users)) {

      // Check the account isn't already here.
      $account = user_load_by_mail($this->personas[$persona]['account']['mail']);

      if (empty($account)) {
        // Create account.
        $account = (object) $this->personas[$persona]['account'];

        user_save($account, array('pass' => $this->drupalContext->getRandom()->string(30)));

        if (empty($account->uid)) {
          throw new Exception(t('Could not create user account for persona @persona', array(
            '@persona' => $persona,
          )));
        }

        // Add roles.
        if (isset($this->personas[$persona]['roles'])) {
          $account->roles = array();
          foreach ($this->personas[$persona]['roles'] as $role_name) {
            $role = user_role_load_by_name($role_name);
            if ($role) {
              $account->roles[$role->rid] = $role->name;
            }
          }
        }

        /** @var EntityDrupalWrapper $account_wrapper */
        $account_wrapper = entity_metadata_wrapper('user', $account);
        foreach ($this->personas[$persona] as $field_name => $field_value) {
          $is_field = preg_match('/^field_(.*)/', $field_name, $matches);
          if (!empty($is_field)) {
            try {
              if (is_array($field_value)) {
                foreach ($field_value as $delta => $sub_field_value) {
                  // @todo make creation of entity links like this more extensible.
                  if ($delta === 'tid') {
                    // Taxonomy term reference.
                    $account_wrapper->$field_name = $this->terms[$sub_field_value]->tid;
                  }
                  else {
                    // Things like address field.
                    $account_wrapper->$field_name->$delta->set($sub_field_value);
                  }
                }
              }
              else {
                $account_wrapper->$field_name->set($field_value);
              }
            } catch (Exception $e) {
              throw new Exception('ERROR: Unable to set field from persona ini ' . $field_name . ' - ' . $e->getMessage());
            }
          }
        }

        $account_wrapper->save();
      }

      $this->users[$persona] = $account;
    }

    return $this->users[$persona];
  }

  /**
   * @Then there should be a user account for persona :persona
   */
  public function getExpectedPersonaUser($persona, $refresh = TRUE) {
    // If the persona doesn't exist then throw exception.
    if (!isset($this->personas[$persona])) {
      $message = sprintf('No personas have been loaded from the ini file during this scenario or this persona is not defined: %s.', $persona);
      throw new ExpectationException($message, $this->minkContext->getSession());
    }

    if (!empty($this->personas[$persona]['is_anonymous'])) {
      return drupal_anonymous_user();
    }

    if (empty($this->users[$persona])) {
      $message = sprintf('Could not find an expected persona user: %s.', $persona);
      throw new ExpectationException($message, $this->minkContext->getSession());
    }

    // Refresh the persona from the db.
    if ($refresh) {
      $user = $this->users[$persona];
      $user = user_load($user->uid, TRUE);
    }

    return $user;
  }

  /**
   * @Given I am logged in as persona :persona
   * @When I login as persona :persona
   */
  public function iAmLoggedInAsPersona($persona) {
    $account = $this->getPersonaUser($persona);

    if (empty($account->uid)) {
      $this->getDrupalContext()->logout();
      return;
    }

    $this->getDrupalContext()->user = $account;
    $this->login();
  }

  /**
   * Log-in the current user using one time login link.
   */
  public function login() {
    // Check if logged in.
    if ($this->getDrupalContext()->loggedIn()) {
      $this->getDrupalContext()->logout();
    }

    if (!$this->getDrupalContext()->user) {
      throw new ExpectationException('Tried to login without a user.', $this->minkContext->getSession());
    }

    $link = $this->generateOneTimeLogin($this->getDrupalContext()->user);
    $this->minkContext->visitPath($link);

    if (!$this->getDrupalContext()->loggedIn()) {
      throw new ExpectationException(
        sprintf("Failed to log in as user '%s'", $this->getDrupalContext()->user->mail),
        $this->minkContext->getSession());
    }
  }

  /**
   * Generate a one time login link.
   *
   * @param $account
   *   The user account you need to login as
   *
   * @return string
   *   URL to login
   */
  public function generateOneTimeLogin($account) {
    $timestamp = time();
    global $base_url;
    $account->login = empty($account->login) ? 0 : $account->login;
    //return url("user/reset/$account->uid/$timestamp/" . user_pass_rehash($account->pass, $timestamp, $account->login, NULL) . '/login', array('absolute' => FALSE));
    return $base_url."user/reset/$account->uid/$timestamp/" . user_pass_rehash($account->pass, $timestamp, $account->login, NULL) . '/login';
  }
}
