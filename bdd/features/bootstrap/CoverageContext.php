<?php

use Behat\Behat\Context\Context;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;
//require_once('bdd/vendor/phpunit/php-code-coverage/src/CodeCoverage/Filter.php');

/**
 * Created by PhpStorm.
 * User: elie
 * Date: 01/09/15
 * Time: 11:29
 */
class CoverageContext implements Context
{
    /**
     * @var PHP_CodeCoverage
     */
    private static $coverage;

    /** @BeforeSuite */
    public static function setup()
    {
        $filter = new PHP_CodeCoverage_Filter();
        $filter->addDirectoryToBlacklist(__DIR__ . "/../../vendor");
        $filter->addDirectoryToWhitelist(__DIR__ . "/../../src");
        self::$coverage = new PHP_CodeCoverage(null, $filter);
    }

    /** @AfterSuite */
    public static function tearDown()
    {
        $writer = new PHP_CodeCoverage_Report_HTML();
        $writer->process(self::$coverage, __DIR__ . "/../../tmp/coverage");
    }

    private function getCoverageKeyFromScope(BeforeScenarioScope $scope)
    {
        $name = $scope->getFeature()->getTitle() . '::' . $scope->getScenario()->getTitle();
        return $name;
    }

    /**
     * @BeforeScenario
     */
    public function startCoverage(BeforeScenarioScope $scope)
    {
        self::$coverage->start($this->getCoverageKeyFromScope($scope));
    }

    /** @AfterScenario */
    public function stopCoverage()
    {
        self::$coverage->stop();
    }
}
