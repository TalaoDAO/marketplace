<?php

/**
 * @file
 * Plugin for Adminer. Provide using adminer without login.
 */

class AdminerDrupal {
  protected $db;
  protected $access;

  /**
   * Plugin constructor.
   */
  public function __construct() {
    if ($this->access = user_access('use adminer without login')) {
      $this->db = Database::getConnectionInfo();
    }
  }

  /**
   * Returns site name.
   */
  public function name() {
    return variable_get('site_name', 'Adminer');
  }

  /**
   * Returns db credentials.
   */
  public function credentials() {
    if ($this->access) {
      return array(
        $this->db['default']['host'],
        $this->db['default']['username'],
        $this->db['default']['password'],
      );
    }
    return array(SERVER, $_GET["username"], get_session("pwds"));
  }

  /**
   * Returns database link.
   */
  public function database() {
    if ($this->access) {
      return $this->db['database'];
    }
    return DB;
  }

  /**
   * Include CSS.
   */
  public function head() {
    print '<link rel="stylesheet" type="text/css" href="' . file_create_url(adminer_get_css()) . '"/>' . "\n";
    return FALSE;
  }
}
