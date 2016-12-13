<?php

use Drupal\DrupalExtension\Context\RawDrupalContext,
    Drupal\DrupalExtension\Context\DrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext,
    Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException;
use Behat\MinkExtension\Context\MinkContext;
use Behat\Behat\Hook\Scope\BeforeScenarioScope,
    Behat\Behat\Hook\Scope\AfterStepScope;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;
use Behat\Mink\Exception\ExpectationException;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends DrupalContext {

  private $screenshotPath;

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct( $tempPath = '/../bdd/tmp', $screenshotPath = '/screenshots', $htmlpagePath = '/behat_page.html' ) {
    $this->tempPath = $tempPath;
    $this->screenshotPath = $screenshotPath;
    $this->htmlPagePath = $htmlpagePath;
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
  public function iAmLoggedInAsTheAdmin() {
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
  public function iAmLoggedInAsTheClient() {
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
   * @Given I give :name :points emh credits
   */
  public function assertGiveUserPoints($name, $points) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid);
    $context = array('points' => $points, 'log' => 'Behat add credits to user');
    emh_points_give_points($user, $context);
  }

  /**
   * @Given I remove :name :points emh credits
   */
  public function assertRemoveUserPoints($name, $points) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid);
    $context = array('points' => $points, 'log' => 'Behat remove credits to user');
    emh_points_remove_points($user, $context);
  }

  /**
   * @Then I should have :points credits on :name user
   */
  public function assertUserPoints($points, $name) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid, TRUE);
    if (! ($user->emh_points == (int) $points) ) {
      throw new \Exception(sprintf('The user with "%s" title should have %s credits instead of %s.', $name, $points, $user->emh_points));
    }
  }

  /**
   * @Then I should have :points credits on :title node
   */
  public function assertNodePoints($points, $title) {
    $fnode = NULL;
    foreach ($this->nodes as $snode) {
      if ($snode->title == $title) $fnode=$snode;
    }
    if (!isset($fnode)) {
      throw new \Exception(sprintf('No node with %s title is registered with the driver.', $title));
    }
    entity_get_controller('node')->resetCache(array($fnode->nid)); // temporary, should be cleaned by VBO
    $node = node_load($fnode->nid);
    if (! ($node->emh_points == (int) $points) ) {
      throw new \Exception(sprintf('The node with "%s" title should have %s credits instead of %s.', $title, $points, $node->emh_points));
    }
  }

  /**
   * @Then user :name transfers :points credits on :title node
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
   * @Then node :title transfers :points credits on :name user
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

  /**
   * Checks, that form element with specified label is visible on page.
   *
   * @Then /^(?:|I )should see an? "(?P<label>[^"]*)" form element$/
   */
  public function assertFormElementOnPage($label) {
    $element = $this->getSession()->getPage();
    $nodes = $element->findAll('css', '.form-item label');
    foreach ($nodes as $node) {
      if ($node->getText() === $label) {
        if ($node->isVisible()) {
          return;
        }
        else {
          throw new \Exception("Form item with label \"$label\" not visible.");
        }
      }
    }
    throw new \Behat\Mink\Exception\ElementNotFoundException($this->getSession(), 'form item', 'label', $label);
  }

  /**
   * Checks, that form element with specified label and type is visible on page.
   *
   * @Then /^(?:|I )should see an? "(?P<label>[^"]*)" (?P<type>[^"]*) form element$/
   */
  public function assertTypedFormElementOnPage($label, $type) {
    $container = $this->getSession()->getPage();
    $pattern = '/(^| )form-type-' . preg_quote($type). '($| )/';
    $label_nodes = $container->findAll('css', '.form-item label');
    foreach ($label_nodes as $label_node) {
      // Note: getText() will return an empty string when using Selenium2D. This
      // is ok since it will cause a failed step.
      if ($label_node->getText() === $label
        && preg_match($pattern, $label_node->getParent()->getAttribute('class'))
        && $label_node->isVisible()) {
        return;
      }
    }
    throw new \Behat\Mink\Exception\ElementNotFoundException($this->getSession(), $type . ' form item', 'label', $label);
  }

  /**
   * Checks, that element with specified CSS is not visible on page.
   *
   * @Then /^(?:|I )should not see an? "(?P<label>[^"]*)" form element$/
   */
  public function assertFormElementNotOnPage($label) {
    $element = $this->getSession()->getPage();
    $nodes = $element->findAll('css', '.form-item label');
    foreach ($nodes as $node) {
      // Note: getText() will return an empty string when using Selenium2D. This
      // is ok since it will cause a failed step.
      if ($node->getText() === $label && $node->isVisible()) {
        throw new \Exception();
      }
    }
  }

  /**
   * Checks, that form element with specified label and type is not visible on page.
   *
   * @Then /^(?:|I )should not see an? "(?P<label>[^"]*)" (?P<type>[^"]*) form element$/
   */
  public function assertTypedFormElementNotOnPage($label, $type) {
    $container = $this->getSession()->getPage();
    $pattern = '/(^| )form-type-' . preg_quote($type). '($| )/';
    $label_nodes = $container->findAll('css', '.form-item label');
    foreach ($label_nodes as $label_node) {
      // Note: getText() will return an empty string when using Selenium2D. This
      // is ok since it will cause a failed step.
      if ($label_node->getText() === $label
        && preg_match($pattern, $label_node->getParent()->getAttribute('class'))
        && $label_node->isVisible()) {
        throw new \Behat\Mink\Exception\ElementNotFoundException($this->getSession(), $type . ' form item', 'label', $label);
      }
    }
  }

  /**
   * @param int $seconds
   *   Amount of seconds when nothing to happens.
   *
   * @Given /^(?:|I )wait (\d+) seconds$/
   */
  public function waitSeconds($seconds) {
    sleep($seconds);
  }

  /**
   * @Then I go to stripped URL
   */
  public function then_i_go_to_stripped_url() {
    $url = $this->getSession()->getCurrentUrl();
    $url = preg_replace("/\?.*/","",$url);
    print ("go to $url");
    $this->getSession()->visit($url);
  }

  /**
   * This works for the Goutte driver and I assume other HTML-only ones.
   *
   * @Then /^show me the HTML page$/
   */
  public function show_me_the_html_page_in_the_browser() {

    global $base_url;
    $html_data = $this->getSession()->getDriver()->getContent();
    file_put_contents(DRUPAL_ROOT. $this->tempPath . $this->htmlPagePath, $html_data);
    echo 'Screenshot at : ' . $base_url . $this->tempPath . $this->htmlPagePath;
  }

  /**
   * Take screen-shot when step fails.
   *
   * @AfterStep
   * @param AfterStepScope $scope
   */
  public function takeScreenshotAfterFailedStep(AfterStepScope $scope) {
    // come from : https://github.com/Behat/Behat/issues/649
    // and from : https://gist.github.com/fbrnc/4550079

    global $base_url;

    if (99 === $scope->getTestResult()->getResultCode()) {

      if (! is_dir( $base_url . $this->tempPath . $this->screenshotPath )) {
        mkdir( $base_url . $this->tempPath . $this->screenshotPath, 0777, true );
      }
      $step = $scope->getStep();
	    $id = /*$step->getParent()->getTitle() . '.' .*/ $step->getType() . ' ' . $step->getText();
	    $id = $scope->getFeature()->getTitle().' '.$step->getLine().'-'.  $step->getType() . ' ' . $step->getText();
	    $filename = 'Fail.'.preg_replace('/[^a-zA-Z0-9-_\.]/','_', $id) . '.html';

      $html_data = $this->getSession()->getDriver()->getContent();
      file_put_contents( DRUPAL_ROOT. $this->tempPath . $this->screenshotPath . '/' . $filename, $html_data);
      echo 'Screenshot error at : ' . $base_url . $this->tempPath . $this->screenshotPath . '/' . $filename;
    }
  }

  /**
   * @Given /^the test email system is enabled$/
   */
  public function theTestEmailSystemIsEnabled() {
    // Store the original system to restore after the scenario.
    $this->originalMailSystem = variable_get('mail_system', array('default-system' => 'DefaultMailSystem'));
    // Set the test system.
    variable_set('mail_system', array('default-system' => 'EMHMailSystem'));
    // Flush the email buffer, allowing us to reuse this step definition to clear existing mail.
    variable_set('drupal_test_email_collector', array());
    db_query("DELETE FROM queue WHERE name='emh_request_request_email_notification'"); //delete queue from other test, can be overloaded if All Experts used
  }

  /**
   * @Then /^the email to "([^"]*)" should contain "([^"]*)"$/
   */
  public function theEmailToShouldContain($to, $contents) {
    // We can't use variable_get() because $conf is only fetched once per
    // scenario.
    $variables = array_map('unserialize', db_query("SELECT name, value FROM {variable} WHERE name = 'drupal_test_email_collector'")->fetchAllKeyed());
    $this->activeEmail = FALSE;
    foreach ($variables['drupal_test_email_collector'] as $message) {
      if ($message['to'] == $to) {
        $this->activeEmail = $message;
        if (strpos($message['body'], $contents) !== FALSE ||
          strpos($message['subject'], $contents) !== FALSE) {
          return TRUE;
        }
        throw new \Exception('Did not find expected content in message body or subject.');
      }
    }
    throw new \Exception(sprintf('Did not find expected message to %s', $to));
  }

  /**
   * @Then /^the last email to "([^"]*)" should contain "([^"]*)"$/
   */
  public function theLastEmailToShouldContain($to, $contents) {
    $variables = array_map('unserialize', db_query("SELECT name, value FROM {variable} WHERE name = 'drupal_test_email_collector'")->fetchAllKeyed());
    $this->activeEmail = FALSE;
    foreach ( array_reverse($variables['drupal_test_email_collector']) as $message) {
      if ($message['to'] == $to) {
        $this->activeEmail = $message;
        if (strpos($message['body'], $contents) !== FALSE ||
          strpos($message['subject'], $contents) !== FALSE) {
          return TRUE;
        }
        throw new \Exception('Did not find expected content in message body or subject.');
      }
    }
    throw new \Exception(sprintf('Did not find expected message to %s', $to));
  }

  /**
   * @Then /^the last email to "([^"]*)" should not contain "([^"]*)"$/
   */
  public function theLastEmailToShouldNotContain($to, $contents) {
    $variables = array_map('unserialize', db_query("SELECT name, value FROM {variable} WHERE name = 'drupal_test_email_collector'")->fetchAllKeyed());
    $this->activeEmail = FALSE;
    foreach ( array_reverse($variables['drupal_test_email_collector']) as $message) {
      if ($message['to'] == $to) {
        $this->activeEmail = $message;
        if (strpos($message['body'], $contents) == FALSE ||
          strpos($message['subject'], $contents) == FALSE) {
          return TRUE;
        }
        throw new \Exception('Found expected content in message body or subject.');
      }
    }
    // dont care if not found any email at all
  }

  /**
   * @Given /^the email should contain "([^"]*)"$/
   */
  public function theEmailShouldContain($contents) {
    if (!$this->activeEmail) {
      throw new \Exception('No active email');
    }
    $message = $this->activeEmail;
    if (strpos($message['body'], $contents) !== FALSE ||
      strpos($message['subject'], $contents) !== FALSE) {
      return TRUE;
    }
    throw new \Exception('Did not find expected content in message body or subject.');
  }

  /**
   * Clear user access static caches.
   * Solves : https://github.com/jhedstrom/drupalextension/issues/328
   * fix : #992
   *
   * @AfterUserCreate
   */
  function clearUserAccessCache() {
    drupal_static_reset('user_access');
  }

  /**
   * @Then the user :name has :perm permission
   */
  public function theUserHasPermission($name, $perm) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid);
    if (! user_access($perm, $user))
      throw new \Exception('User does not have the required permission');
  }

  /**
   * @Then the user :name don't have :perm permission
   */
  public function theUserDontHavePermission($name, $perm) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid);
    if (user_access($perm, $user))
      throw new \Exception('User should not have the required permission');
  }

  /**
   * Asserts that a given field has the disabled attribute.
   *
   * @param string $field
   *   The label, placeholder, ID or name of the field to check.
   *
   * @Then the :field field should be disabled
   *
   * @throws ExpectationException
   *   If the field does not have the disabled attribute.
   */
  public function assertDisabledField($field) {
    $element = $this->assertSession()->fieldExists($field);
    if (!$element->hasAttribute('disabled')) {
      throw new ExpectationException("Expected '{$field}' field to be disabled.", $this->getSession()->getDriver());
    }
  }
}
