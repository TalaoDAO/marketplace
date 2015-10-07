<?php

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Drupal\DrupalExtension\Context\DrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;
use Behat\MinkExtension\Context\MinkContext;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext {

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct() {
  }

  /* @BeforeScenario
  public function gatherContexts(BeforeScenarioScope $scope) {
    $environment = $scope->getEnvironment();
    $this->personaContext = $environment->getContext('PersonaContext');
    $this->personaContext->setDrupalContext($this);
  }*/

  /**
   * @Given /^(?:|I )am logged in as the admin$/
   */
  public function iAmLoggedInAsTheAdmin()    {
    // Check if logged in.
    if ($this->loggedIn()) {
      $this->logout();
    }
    $this->getSession()->visit($this->locatePath('/user'));
    $element = $this->getSession()->getPage();
    $element->fillField($this->getDrupalText('username_field'), "admin");
    $element->fillField($this->getDrupalText('password_field'), "admin");
    $submit = $element->findButton($this->getDrupalText('log_in'));
    if (empty($submit)) {
      throw new \Exception(sprintf("No submit button at %s", $this->getSession()->getCurrentUrl()));
    }
    // Log in.
    $submit->click();
    if (!$this->loggedIn()) {
      throw new \Exception(sprintf("Failed to log in as user '%s' with role '%s'", "admin", "superadmin"));
    }
  }

  /**
   * @Given /^(?:|I )am logged in as the client$/
   */
  public function iAmLoggedInAsTheClient()    {
    // Check if logged in.
    if ($this->loggedIn()) {
      $this->logout();
    }
    $this->getSession()->visit($this->locatePath('/user'));
    $element = $this->getSession()->getPage();
    $element->fillField($this->getDrupalText('username_field'), "business1");
    $element->fillField($this->getDrupalText('password_field'), "business1");
    $submit = $element->findButton($this->getDrupalText('log_in'));
    if (empty($submit)) {
      throw new \Exception(sprintf("No submit button at %s", $this->getSession()->getCurrentUrl()));
    }
    // Log in.
    $submit->click();
    if (!$this->loggedIn()) {
      throw new \Exception(sprintf("Failed to log in as user '%s' with role '%s'", "business1", "business"));
    }
  }

}

