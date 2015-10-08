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
class FeatureContext extends DrupalContext {

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

   /**
   * @Given I give :name :points emh points
   */
  public function assertGiveUserPoints($name, $points) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid);
    $context = array('points' => $points, 'log' => 'Behat add points to user');
    emh_points_give_points($user, $context);
  }

   /**
   * @Then I should have :points points on :node node
   */
  public function assertNodePoints($points, $title) {
    $fnode = NULL;
    foreach ($this->nodes as $snode) {
      if ($snode->title == $title) $fnode=$snode;
    }
    if (!isset($fnode)) {
      throw new \Exception(sprintf('No node with %s title is registered with the driver.', $title));
    }
    $node = node_load($fnode->nid);
    if (!  ($node->emh_points == (int) $points) ) {
      throw new \Exception(sprintf('The node with %s title should have %s points instead of %s.', $title, $points, $node->emh_points));
    }
  }

   /**
   * @Then user :name transfers :points points on :title node
   */
  public function userTransfertNodePoints($name, $points, $title) {
    $fnode = NULL;
    foreach ($this->nodes as $snode) {
      if ($snode->title == $title) $fnode=$snode;
    }
    if (!isset($fnode)) {
      throw new \Exception(sprintf('No node with %s title is registered with the driver.', $title));
    }
    $node = node_load($fnode->nid);

    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid);
    emh_points_move_points($user, $node, (int) $points);
  }

   /**
   * @Then node :title transfers :points points on :name user
   */
  public function nodeTransfertUserPoints($title, $points, $name) {
    $fnode = NULL;
    foreach ($this->nodes as $snode) {
      if ($snode->title == $title) $fnode=$snode;
    }
    if (!isset($fnode)) {
      throw new \Exception(sprintf('No node with %s title is registered with the driver.', $title));
    }
    $node = node_load($fnode->nid);
    
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    } 
    $user = user_load($this->users[$name]->uid);
    emh_points_move_points($node, $user, (int) $points);
  }

}

