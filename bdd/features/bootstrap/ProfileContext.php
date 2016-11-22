<?php

use Symfony\Component\Stopwatch\Stopwatch;
use Behat\Behat\Context\Context;

/**
 * Defines application features from the specific context.
 */
class ProfileContext implements Context {

    private $stopwatch;
    private $stopwatchEvent;
    private $eventId;
    
    /**
     * @BeforeScenario
     */
    public function startScenarioTiming($event) {
        $this->eventId = spl_object_hash($event);
        $this->getStopwatch()->start($this->eventId);
    }

    /**
     * @AfterScenario
     */
    public function stopScenarioTiming($event) {
        $this->stopwatchEvent = $this->getStopwatch()->stop($this->eventId);
        echo "\n\033[36m| ";
<<<<<<< HEAD
<<<<<<< HEAD
        echo 'Scenario time: ' . $this->formatTime($this->stopwatchEvent->getDuration());
=======
        echo 'Step time: ' . $this->formatTime($this->stopwatchEvent->getDuration());
>>>>>>> Performance module & behat step
=======
        echo 'Scenario time: ' . $this->formatTime($this->stopwatchEvent->getDuration());
>>>>>>> Fix typo
        echo "\033[0m\n\n";
    }


    protected function getStopwatch()
    {
        if ($this->stopwatch === null) {
            $this->stopwatch = new Stopwatch();
        }
        return $this->stopwatch;
    }

    protected function formatTime($timeInMs)
    {
        $ms = $timeInMs % 1000;
        $timeInMs = floor($timeInMs / 1000);
        $seconds = $timeInMs % 60;
        $timeInMs = floor($timeInMs / 60);
        $minutes = $timeInMs % 60;
        $timeInMs = floor($timeInMs / 60); 
        return $minutes . "m " . $seconds . "." . $ms ."s";
    }

}
