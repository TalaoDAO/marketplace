<?php

/**
 * @file
 *  Behat subcontext for pausing the form submission if the form is time
 *  protected by Honeypot.
 *
 * When using the DrupalExtension with Behat, this file will be autoloaded,
 * and the included step definitions will be available automatically.
 *
 * @see http://behat.org
 * @see http://drupal.org/project/drupalextension
 */

use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalDriverManager;

class Honeypot implements DrupalSubContextInterface {

  private $drupal;

  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * Implements DrupalSubContextInterface::getAlias().
   */
  public static function getAlias() {
    return 'honeypot';
  }

  /**
   * @param Behat\Behat\Hook\scope\BeforeStepScope $scope
   *
   * @BeforeStep
   */
  public function checkDelayFormSubmission($scope) {
    if (module_exists('honeypot')) {

      /* @var $environment Behat\Behat\Context\Environment\InitializedContextEnvironment */
      /* @var $step        Behat\Gherkin\Node\StepNode */
      $environment = $scope->getEnvironment();
      $step = $scope->getStep();

      // Check if the current step is going to submit a form.
      if (substr($step->getText(), 0, 8) != 'I press ') {
        return;
      }

      // Check if the current form is time protected by honeypot.
      if ($environment->hasContextClass('Drupal\DrupalExtension\Context\MinkContext')) {
        $element = $environment->getContext('Drupal\DrupalExtension\Context\MinkContext')
          ->getSession()
          ->getPage()
          ->findButton(str_replace('"', '', substr($step->getText(), 8)));
        while ($element && ($element = $element->getParent())) {
          if ($element->getTagName() == 'form') {
            $form = $form_state = array();
            $form_id = str_replace('-', '_', $element->getAttribute('id'));
            honeypot_form_alter($form, $form_state, $form_id);
            if (!empty($form['honeypot_time'])) {
              $time_limit = variable_get('honeypot_time_limit', 5);
              // Output a message.
              // $output->write(sprintf('  [Pausing for %s seconds to satisfy the Honeypot module]', $time_limit));
              // Pause execution.
              sleep($time_limit);
            }
            return;
          }
        }
      }
    }
  }

}
