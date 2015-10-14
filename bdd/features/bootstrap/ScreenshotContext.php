<?php

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;
use Behat\MinkExtension\Context\MinkContext;
use Behat\Behat\Hook\Scope\AfterStepScope;


/**
 * Defines application features from the specific context.
 */
class ScreenshotContext extends RawDrupalContext {

    /**
     * @AfterStep
     * @param AfterStepScope $scope
     */
    public function takeScreenshotAfterFailedStep(AfterStepScope $scope)
    {
        if (99 === $scope->getTestResult()->getResultCode()) {
            $this->takeScreenshot();
        }
    }

    private function takeScreenshot()
    {
        $driver = $this->getSession()->getDriver();
        if (!$driver instanceof Selenium2Driver) {
	    print "NOT SELENIUM";
            return;
        }
        //$baseUrl = $this->getMinkParameter('base_url');
        $fileName = date('d-m-y') . '-' . uniqid() . '.png';
        //$filePath = $this->getContainer()->get('kernel')->getRootdir() . '/tmp/';

        $baseUrl = "http://gitemindhub/";
        $filePath = "/var/www/tmp";

        $this->saveScreenshot($fileName, $filePath);
        print 'Screenshot at: ' . $baseUrl . 'tmp/' . $fileName;
    }
}

