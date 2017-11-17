<?php

/**
 * @file
 * The main interface to the calais web service
 */
class CalaisService {

  private $defaults = array(
    'protocol' => 'https',
    'contentType' => 'text/raw',
    'outputFormat' => 'application/json',
    'externalID' => '',
    'submitter' => 'Drupal',
    'calculateRelevanceScore' => 'true',
    'enableMetadataType' => 'SocialTags',
    'allowSearch' => 'false',
    'allowDistribution' => 'false',
    'caller' => 'Drupal',
    'apiKey' => '',
    'content' => '',
    'host' => 'api.thomsonreuters.com',
  );

  public $parameters;
  public $data = array();
  public $keywords = array();

  /**
   * Constructs an instance of the Calais facade.
   *
   * Valid parameters are specified in the options array as key/value pairs with the
   * parameter name being the key and the parameter setting being the value
   * for example array('allowSearch' => 'false')
   *
   * @param options  An array of parameter options for the Calais Web Service.
   *                  These will override the defaults.
   *
   * @see http://opencalais.com/APIcalls#inputparameters
   */
  function __construct($options = array()) {
    $this->defaults['externalID'] = time();
    $this->parameters = array_merge($this->defaults, $options);
  }

  /**
   * Analyze the content via Calais.
   *
   * @param $content The content to ship off to Calais for analysis
   * @return The processed Calais results. The raw RDF result is contained in the $this->rdf field.
   */
  public function analyze() {

    $headers = array(
      'Content-Type: ' . $this->parameters['contentType'],
      'X-AG-Access-Token: ' . $this->parameters['apiKey'],
      'Content-Length: ' . strlen($this->parameters['content']),
      'outputformat: ' . $this->parameters['outputFormat'],
    );

    // Construct the URL to calais based on host name and protocol. This is likely
    // static, but will keep this as it was for now.
    $uri = $this->parameters['protocol'] . '://' . $this->parameters['host'] . '/permid/calais';

    $curlOptions = array(
      CURLOPT_URL => $uri,
      CURLOPT_HTTPHEADER => $headers,
      CURLOPT_SSL_VERIFYPEER => FALSE,
      CURLOPT_RETURNTRANSFER => 1,
      CURLOPT_POSTFIELDS => $this->parameters['content'],
    );

    $ch = curl_init();
    curl_setopt_array($ch, $curlOptions);

    // send request and get response from api..........
    $response = curl_exec($ch);

    if (isset($response->error)) {
      self::log_calais_error($response);
      return array();
    }

    $this->data = json_decode($response);
    $this->processor = new CalaisJsonProcessor();
    $this->keywords = $this->processor->parse_json($this->data);
    return $this->keywords;
  }

  /**
   * An error logging function and message setting.
   *
   * @param object $ret
   *   The response from the analyze function.
   */
  private static function log_calais_error($ret) {
    $msg = t('OpenCalais processing error: @msg', array('@msg' => $ret->data));
    drupal_set_message($msg, 'error');
    watchdog('opencalais', 'OpenCalais processing error: (@code - @error) @msg', array('@code' => $ret->code, '@error' => $ret->error, '@msg' => $ret->data), WATCHDOG_ERROR);
  }
}
