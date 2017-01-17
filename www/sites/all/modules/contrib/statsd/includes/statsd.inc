<?php


/**
 * Sends statistics to the stats daemon over UDP
 *
 */

class StatsD {

  /**
   * Log timing information.
   *
   * @param string $stat
   *   A string of the metric to log timing info for.
   * @param int $time
   *   The elapsed time (ms) to log.
   * @param float $sample_rate
   *   A float between 0 and 1 representing the sampling rate.
   *
   */
  public static function timing($stat, $time, $sample_rate = NULL) {
    self::send(array($stat => "$time|ms"), $sample_rate);
  }


  /**
   * Sends a gauge, an arbitrary value to statsd.
   *
   * @param string $stat
   *   The metric to send. 
   * @param mixed $value
   *   The value to send for this metric.
   * @param float $sample_rate
   *   A float between 0 and 1 representing the sampling rate.
   *
   */
  public static function gauge($stat, $value, $sample_rate = NULL) {
    self::send(array($stat => "$value|g"), $sample_rate);
  }


  /**
   * Sends one or more set values to statsd.
   *
   * Sets count the number of unique values received during the flush interval.
   *
   * @param string $stat
   *   The metric name.
   * @param mixed $values
   *   The value (or array of values) to send for this metric.
   * @param float $sample_rate
   *   (optional) A float between 0 and 1 representing the sampling rate.
   *
   */
  public static function set($stat, $values, $sample_rate = NULL) {
    $data = array();

    if (!is_array($values)) {
      $values = array($values);
    }

    foreach ($values as $value) {
      $data[$stat] = "$value|s";
    }

    self::send($data, $sample_rate);
  }


  /**
   * Increments one or more stats counters.
   *
   * @param mixed $stats
   *   A string or an array of string representing the metric(s) to increment.
   * @param float $sample_rate
   *   A float between 0 and 1 representing the sampling rate.
   *
   */
  public static function increment($stats, $sample_rate = NULL) {
    self::updateStats($stats, 1, $sample_rate);
  }


  /**
   * Decrements one or more stats counters.
   *
   * @param mixed $stats
   *   A string or an array of string representing the metric(s) to decrement.
   * @param float $sample_rate
   *   A float between 0 and 1 representing the sampling rate.
   *
   */
  public static function decrement($stats, $sample_rate = NULL) {
    self::updateStats($stats, -1, $sample_rate);
  }


  /**
   * Updates one or more stats counters by arbitrary amounts.
   *
   * @param mixed $stats
   *   A string or an array of string representing the metric(s) to increment or decrement.
   * @param int $delta
   *   The amount to increment/decrement each metric by.
   * @param float $sample_rate
   *   A float between 0 and 1 representing the sampling rate.
   *
   */
  public static function updateStats($stats, $delta = 1, $sample_rate = NULL) {

    $data = array();

    if (!is_array($stats)) {
      $stats = array($stats);
    }

    foreach($stats as $stat) {
      $data[$stat] = "$delta|c";
    }

    self::send($data, $sample_rate);

  }


  /**
   * Squirt the metrics over UDP.
   *
   * @param array $data
   *   The data to send.
   * @param float $sample_rate
   *   A float between 0 and 1 representing the sample rate.
   *
   */
  public static function send($data, $sample_rate = NULL) {

    if (!variable_get('statsd_enabled', FALSE) ) {
      return;
    }

    $sample_rate  = $sample_rate ? $sample_rate : variable_get('statsd_sample_rate', 1);
    $sampled_data = array();
    $data         = self::prefixData($data);

    if ($sample_rate < 1) {
      foreach ($data as $stat => $value) {
        if ((mt_rand() / mt_getrandmax()) <= $sample_rate) {
          $sampled_data[$stat] = "$value|@$sample_rate";
        }
      }
    } else {
      $sampled_data = $data;
    }

    if (empty($sampled_data) ) {
      return;
    }

    $host = variable_get('statsd_host', '127.0.0.1');
    $port = variable_get('statsd_port', 8125);
    $fp   = stream_socket_client("udp://$host:$port", $errno, $errstr);

    if ($fp) {
      stream_set_blocking($fp, 0);
      foreach ($sampled_data as $stat => $value) {
        fwrite($fp, "$stat:$value");
      }
      fclose($fp);
    }

  }


  /**
   * Create the data strings that will be passed into statsd.
   * 
   * @param $data
   *   An array of key value pairs to prefix.
   *
   * @return array
   * 
   */
  protected static function prefixData($data) {

    $prefix = ($prefix = variable_get('statsd_prefix', NULL) ) ? $prefix . '.' : '';
    $suffix = ($suffix = variable_get('statsd_suffix', NULL) ) ? '.' . $suffix : '';
    $return = array();

    foreach ($data as $key => $value) {
      $name = $prefix . $key . $suffix;
      $return[$name] = $value;
    }

    return $return;

  }

}