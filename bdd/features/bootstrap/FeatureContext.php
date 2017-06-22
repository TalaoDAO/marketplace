<?php

/**
 * Behat custom context.
 */

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
  public function __construct($tempPath = '/tmp', $screenshotPath = '/screenshots', $htmlpagePath = '/behat_page.html') {
    $this->tempPath = $tempPath;
    $this->screenshotPath = $screenshotPath;
    $this->htmlPagePath = $htmlpagePath;
  }

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
   * @param string $name
   *   User name.
   * @param int $points
   *   Amount of points.
   *
   * @Given I give :name :points emh credits
   */
  public function assertGiveUserPoints($name, $points) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid);
    $context = array(
      'points' => $points,
      'log' => 'Behat add credits to user',
      'txn_context' => 'behat_add',
    );
    emh_points_give_points($user, $context);
  }

  /**
   * @param string $name
   *   User name.
   * @param int $points
   *   Amount of points.
   *
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
   * @param int $points
   *   Amount of points.
   * @param string $name
   *   User name.
   *
   * @Then I should have :points credits on :name user
   */
  public function assertUserPoints($points, $name) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid, TRUE);
    if (!($user->emh_points == (int) $points)) {
      throw new \Exception(sprintf('The user with "%s" title should have %s credits instead of %s.', $name, $points, $user->emh_points));
    }
  }

  /**
   * @Then I should have :points credits on :title node
   */
  public function assertNodePoints($points, $title) {
    $fnode = NULL;
    foreach ($this->nodes as $snode) {
      if ($snode->title == $title) {
        $fnode = $snode;
      }
    }
    if (!isset($fnode)) {
      throw new \Exception(sprintf('No node with %s title is registered with the driver.', $title));
    }
    entity_get_controller('node')->resetCache(array($fnode->nid)); // temporary, should be cleaned by VBO
    $node = node_load($fnode->nid);
    if (!($node->emh_points == (int) $points)) {
      throw new \Exception(sprintf('The node with "%s" title should have %s credits instead of %s.', $title, $points, $node->emh_points));
    }
  }

  /**
   * @Then user :name transfers :points credits on :title node
   */
  public function userTransfertNodePoints($name, $points, $title) {
    $fnode = NULL;
    foreach ($this->nodes as $snode) {
      if ($snode->title == $title) {
        $fnode = $snode;
      }
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
      if ($snode->title == $title) {
        $fnode = $snode;
      }
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
    $pattern = '/(^| )form-type-' . preg_quote($type) . '($| )/';
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
    $pattern = '/(^| )form-type-' . preg_quote($type) . '($| )/';
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
   * @Then /^(?:|I )go to stripped URL$/
   */
  public function goToStrippedUrl() {
    $url = $this->getSession()->getCurrentUrl();
    $url = preg_replace("/\?.*/", "", $url);
    print ("go to $url");
    $this->getSession()->visit($url);
  }

  /**
   * @Then show me the URL
   */
  public function showMeTheUrl() {
    $url = $this->getSession()->getCurrentUrl();
    print ("Current url : $url");
  }

  /**
   * This works for the Goutte driver and /^(?:|I )assume other HTML-only ones.
   *
   * @Then /^show me the HTML page$/
   */
  public function showMeTheHtmlPageInTheBrowser() {
    global $base_url;
    $html_data = $this->getSession()->getDriver()->getContent();
    file_put_contents(DRUPAL_ROOT . $this->tempPath . $this->htmlPagePath, $html_data);
    echo 'Screenshot at : ' . $base_url . $this->tempPath . $this->htmlPagePath;
  }

  /**
   * @Given /^the test email system is enabled$/
   */
  public function theTestEmailSystemIsEnabled() {
    // Store the original system to restore after the scenario.
    $this->originalMailSystem = variable_get('mail_system', array('default-system' => 'DefaultMailSystem'));
    // Set the test system.
    variable_set('mail_system', array('default-system' => 'EMHMailSystem'));
    // Flush the email buffer, allowing us to reuse this step definition to
    // clear existing mail.
    variable_set('drupal_test_email_collector', array());
    // Delete queue from other test, can be overloaded if All Experts used.
    db_query("DELETE FROM queue WHERE name='emh_request_request_email_notification'");
    db_query('TRUNCATE TABLE {mail_logger}');
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
    $directory = variable_get('devel_debug_mail_directory', 'temporary://devel-mails');
    file_put_contents($directory . '/debug-email-collector.txt', var_export($variables, TRUE));
    throw new \Exception(sprintf('Did not find expected message to %s', $to));
  }

  /**
   * @Then /^the last email to "([^"]*)" should contain "([^"]*)"$/
   */
  public function theLastEmailToShouldContain($to, $contents) {
    $variables = array_map('unserialize', db_query("SELECT name, value FROM {variable} WHERE name = 'drupal_test_email_collector'")->fetchAllKeyed());
    $this->activeEmail = FALSE;
    foreach (array_reverse($variables['drupal_test_email_collector']) as $message) {
      if ($message['to'] == $to) {
        $this->activeEmail = $message;
        if (strpos($message['body'], $contents) !== FALSE ||
          strpos($message['subject'], $contents) !== FALSE) {
          return TRUE;
        }
        throw new \Exception('Did not find expected content in message body or subject.');
      }
    }
    $directory = variable_get('devel_debug_mail_directory', 'temporary://devel-mails');
    file_put_contents($directory . '/debug-email-collector.txt', var_export($variables, TRUE));
    throw new \Exception(sprintf('Did not find expected message to %s', $to));
  }

  /**
   * @Then /^the last email to "([^"]*)" should not contain "([^"]*)"$/
   */
  public function theLastEmailToShouldNotContain($to, $contents) {
    $variables = array_map('unserialize', db_query("SELECT name, value FROM {variable} WHERE name = 'drupal_test_email_collector'")->fetchAllKeyed());
    $this->activeEmail = FALSE;
    foreach (array_reverse($variables['drupal_test_email_collector']) as $message) {
      if ($message['to'] == $to) {
        $this->activeEmail = $message;
        if (strpos($message['body'], $contents) == FALSE ||
          strpos($message['subject'], $contents) == FALSE) {
          return TRUE;
        }
        throw new \Exception('Found expected content in message body or subject.');
      }
    }
    // Don't care if not found any email at all.
  }

  /**
   * @Then /^there should be no email to "([^"]*)" containing "([^"]*)"$/
   */
  public function thereIsNoEmailToContaining($to, $contents) {
    $recipient = FALSE;
    $not_contains = FALSE;
    $variables = array_map('unserialize', db_query("SELECT name, value FROM {variable} WHERE name = 'drupal_test_email_collector'")->fetchAllKeyed());
    foreach ($variables['drupal_test_email_collector'] as $message) {
      if ($message['to'] == $to) {
        $recipient = TRUE;
        if (strpos($message['body'], $contents) == FALSE && strpos($message['subject'], $contents) == FALSE) {
          $not_contains = TRUE;
        }
      }
    }
    if (($recipient == TRUE && $not_contains == TRUE) || $recipient == FALSE) {
      return TRUE;
    }
    else {
      throw new \Exception('Found email and expected content in message body or subject.');
    }
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
   * @Then the user :name has :perm permission
   */
  public function theUserHasPermission($name, $perm) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid);
    if (!user_access($perm, $user)) {
      throw new \Exception('User does not have the required permission');
    }
  }

  /**
   * @Then the user :name don't have :perm permission
   */
  public function theUserDontHavePermission($name, $perm) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid);
    if (user_access($perm, $user)) {
      throw new \Exception('User should not have the required permission');
    }
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
    $element = $this->getSession()->getPage()->findById($field);
    if ($element === NULL) {
      $element = $this->assertSession()->fieldExists($field);
    }
    if (!$element->hasAttribute('disabled')) {
      throw new ExpectationException("Expected '{$field}' field to be disabled.", $this->getSession()->getDriver());
    }
  }

  /**
   * Asserts that a given field has NOT the disabled attribute.
   *
   * @param string $field
   *   The label, placeholder, ID or name of the field to check.
   *
   * @Then the :field field should not be disabled
   *
   * @throws ExpectationException
   *   If the field  have the disabled attribute.
   */
  public function assertNotDisabledField($field) {
    $element = $this->getSession()->getPage()->findById($field);
    if ($element === NULL) {
      $element = $this->assertSession()->fieldExists($field);
    }
    if ($element->hasAttribute('disabled')) {
      throw new ExpectationException("Expected '{$field}' field not to be disabled.", $this->getSession()->getDriver());
    }
  }

  /**
   * @Given /^(?:|I )click link "(?P<text>[^"]*)"$/
   */
  public function iClickLinkWithText($text) {
    $session = $this->getSession();
    $page = $session->getPage();
    $element = $page->find('named', array('link', $text));

    if (empty($element)) {
      throw new ExpectationException(t('No such element with @text', array(
        '@text' => $text,
      )), $session);
    }

    $element->click();
  }

  /**
   * Checks, that link or button with the given text, title, id or alt attribute is visible on page.
   *
   * @Then /^(?:|I )should see "(?P<text>[^"]*)" link or button$/
   */
  public function assertLinkOrButtonVisibleOnPage($text) {
    $element = $this->getSession()->getPage();
    $elements = $element->findAll('named', array('link_or_button', $text));
    foreach ($elements as $element) {
      if ($element->getText() === $text) {
        if ($element->isVisible()) {
          return;
        }
        else {
          throw new \Exception("Link or button with text \"$text\" not visible.");
        }
      }
    }
  }

  /**
   * Checks, that link or button with the given text, title, id or alt attribute is not visible on page.
   *
   * @Then /^(?:|I )should not see "(?P<text>[^"]*)" link or button$/
   */
  public function assertLinkOrButtonNotVisibleOnPage($text) {
    $element = $this->getSession()->getPage();
    $elements = $element->findAll('named', array('link_or_button', $text));
    foreach ($elements as $element) {
      // Note: getText() will return an empty string when using Selenium2D. This
      // is ok since it will cause a failed step.
      if ($element->getText() === $text && $element->isVisible()) {
        throw new \Exception("Link or button with text \"$text\" visible.");
      }
    }
  }

  /**
   * Checks, that link or button with the given text, title, id or alt attribute is disabled on page.
   *
   * @Then the :text link or button should be disabled
   */
  public function assertLinkOrButtonDisabledOnPage($text) {
    $element = $this->getSession()->getPage();
    $elements = $element->findAll('named', array('link_or_button', $text));
    foreach ($elements as $element) {
      if ($element->getText() === $text) {
        if ($element->hasAttribute('disabled')) {
          return;
        }
        else {
          throw new \Exception("Link or button with text \"$text\" not disabled.");
        }
      }
    }
  }

  /**
   * Checks, that link or button with the given text, title, id or alt attribute is not disabled on page.
   *
   * @Then the :text link or button should not be disabled
   */
  public function assertLinkOrButtonNotDisabledOnPage($text) {
    $element = $this->getSession()->getPage();
    $elements = $element->findAll('named', array('link_or_button', $text));
    foreach ($elements as $element) {
      // Note: getText() will return an empty string when using Selenium2D. This
      // is ok since it will cause a failed step.
      if (!$element->hasAttribute('disabled')) {
        throw new \Exception("Link or button with text \"$text\" disabled.");
      }
    }
  }

  /**
   * Go to next page after batch, work without @javascript
   * Adapted from https://gist.github.com/eliza411/67d2aa93cfa9a31b65ad
   *
   * @Given /^I follow meta refresh$/
   */
  public function iFollowMetaRefresh() {
    while ($refresh = $this->getSession()->getPage()->find('css', 'meta[http-equiv="Refresh"]')) {
      $content = $refresh->getAttribute('content');
      $url = str_replace('0; URL=', '', $content);
      $this->getSession()->visit($url);
    }
  }

  /**
   * Wait for the Batch API to finish.
   *
   * Wait until the id="updateprogress" element is gone,
   * or timeout after 3 minutes (180,000 ms).
   * work only with @javascript
   * from https://swsblog.stanford.edu/blog/behat-custom-step-definition-wait-batch-api-finish
   *
   * @Given /^I wait for the batch job to finish$/
   */
  public function iWaitForTheBatchJobToFinish() {
    $this->getSession()->wait(180000, 'jQuery("#updateprogress").length === 0');
  }

  /**
   * Take screen-shot when step fails.
   *
   * @AfterStep
   * @param AfterStepScope $scope
   *
   * @see https://github.com/Behat/Behat/issues/649
   * @see https://gist.github.com/fbrnc/4550079
   */
  public function takeScreenshotAfterFailedStep(AfterStepScope $scope) {
    global $base_url;

    if (99 === $scope->getTestResult()->getResultCode()) {
      if (!is_dir($base_url . $this->tempPath . $this->screenshotPath)) {
        mkdir($base_url . $this->tempPath . $this->screenshotPath, 0777, TRUE);
      }
      $step = $scope->getStep();
      $id = $scope->getFeature()->getTitle() . ' ' . $step->getLine() . '-' . $step->getType() . ' ' . $step->getText();
      $filename = 'Fail.' . preg_replace('/[^a-zA-Z0-9-_\.]/', '_', $id) . '.html';

      $html_data = $this->getSession()->getDriver()->getContent();
      file_put_contents(DRUPAL_ROOT . $this->tempPath . $this->screenshotPath . '/' . $filename, $html_data);
      echo 'Screenshot error at : ' . $base_url . $this->tempPath . $this->screenshotPath . '/' . $filename;
    }
  }



  /**
   * @param string $name
   *   User name.
   * @param string $title
   *   Organic group.
   *
   * @Given the user :name is a member of the group :title
   */
  public function makeUserMemberOfGroup($name, $title) {
    if (!isset($this->users[$name])) {
      throw new \Exception(sprintf('No user with %s name is registered with the driver.', $name));
    }
    $user = user_load($this->users[$name]->uid);
    $node = node_load_by_title($title);
    if (!isset($node)) {
      throw new \Exception(sprintf('No node with %s title is found.', $title));
    }
    $gid = $node->nid;
    $values = array(
      'entity_type' => 'user',
      'entity' => $user,
      'state' => OG_STATE_ACTIVE,
      'membership_type' => OG_MEMBERSHIP_TYPE_DEFAULT
    );
    og_group('node', $gid, $values);
  }

  /**
   * @param string $name
   *   User name.
   * @param string $title
   *   Organic group.
   *
   * @Given the user :name is an admin of the group :title
   */
  public function makeUserAdminOfGroup($name, $title) {
    $this->makeUserMemberOfGroup($name,$title);
    $user = user_load($this->users[$name]->uid);
    $node = node_load_by_title($title);
    $gid = $node->nid;
    og_user_roles_role_add($gid, $user->uid, OG_ADMINISTRATOR_ROLE);
  }
  /**
   * Clear user access static caches.
   *
   * @see https://github.com/jhedstrom/drupalextension/issues/328
   *    Fix: #992.
   *
   * @AfterUserCreate
   */
  public function clearUserAccessCache() {
    drupal_static_reset('user_access');
  }

  /**
   * Prevent bad interaction between PhantomJS and Chosen module.
   *
   * @BeforeScenario @javascript
   */
  public function prepareForJs(BeforeScenarioScope $scope) {
    module_disable(array('chosen'));
  }

  /**
   * @AfterScenario @javascript
   */
  public function cleanupForJs(Behat\Behat\Hook\Scope\AfterScenarioScope $scope) {
    module_enable(array('chosen'));
  }

  /**
   * @BeforeSuite
   */
  public static function disableModules(\Behat\Testwork\Hook\Scope\BeforeSuiteScope $scope) {
    module_disable(array('emh_smartmobility', 'recaptcha'));
  }

  /**
   * @AfterSuite
   */
  public static function enableModules(\Behat\Testwork\Hook\Scope\AfterSuiteScope $scope) {
    module_enable(array('emh_smartmobility', 'recaptcha'));
  }

  /**
   * @BeforeScenario @smartmobility
   */
  public function prepareForSmartMobility(BeforeScenarioScope $scope) {
    module_enable(array('emh_smartmobility'));
    variable_set('emh_smartmobility_circle_gid', 2520);
  }

  /**
   * @AfterScenario @smartmobility
   */
  public function cleanupForSmartMobility(Behat\Behat\Hook\Scope\AfterScenarioScope $scope) {
    module_disable(array('emh_smartmobility'));
    variable_set('emh_smartmobility_circle_gid', 1813);
  }

  /**
   * @BeforeSuite
   */
  public static function disableRules(\Behat\Testwork\Hook\Scope\BeforeSuiteScope $scope) {
    emh_configuration_disable_rule('_emh_request_notification_moderate_mail');
    emh_configuration_disable_rule('_emh_request_notification_notify_mail');
  }

  /**
   * @AfterSuite
   */
  public static function enableRules(\Behat\Testwork\Hook\Scope\AfterSuiteScope $scope) {
    emh_configuration_enable_rule('_emh_request_notification_moderate_mail');
    emh_configuration_enable_rule('_emh_request_notification_notify_mail');
  }

  /**
   * @BeforeScenario @email
   */
  public function prepareForEmail(BeforeScenarioScope $scope) {
    emh_configuration_enable_rule('_emh_request_notification_moderate_mail');
    emh_configuration_enable_rule('_emh_request_notification_notify_mail');
  }

  /**
   * @AfterScenario @email
   */
  public function cleanupForEmail(Behat\Behat\Hook\Scope\AfterScenarioScope $scope) {
    emh_configuration_disable_rule('_emh_request_notification_moderate_mail');
    emh_configuration_disable_rule('_emh_request_notification_notify_mail');
  }

  /**
   * @BeforeScenario @nodelay
   */
  public function prepareForNoDelay(BeforeScenarioScope $scope) {
    variable_set('emh_request_notification_delay', '0');
  }

  /**
   * @AfterScenario @nodelay
   */
  public function cleanupForNoDelay(Behat\Behat\Hook\Scope\AfterScenarioScope $scope) {
    variable_set('emh_request_notification_delay', '1');
  }
}

/**
 * Helper function: Load node by title
 *
 * @param string $title
 *   The title of the node to be returned
 *
 * @return object
 *   The node found
 */
function node_load_by_title($title) {
  $nodes = node_load_multiple(array(), array('title' => $title), FALSE);
  $returned_node = reset($nodes);
  return $returned_node;
}

/**
 * Grant a role for a user in a group.
 *
 * @param $gid
 *   The group ID.
 * @param $uid
 *   The user ID.
 * @param $role
 *   The role name to grant.
 */
function og_user_roles_role_add($gid, $uid, $role) {
  $roles = og_roles('node', NULL, $gid);
  $rid = array_search($role, $roles);
  og_role_grant('node', $gid, $uid, $rid);
}
