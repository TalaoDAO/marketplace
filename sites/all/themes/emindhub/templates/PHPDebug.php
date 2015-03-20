<?php
/** http://www.codeforest.net/debugging-php-in-browsers-javascript-console
 */
class PHPDebug {

    function __construct() {
        if (!defined("LOG")) {
            define("LOG", 1);
        }
        if (!defined("INFO")) {
            define("INFO", 2);
        }
        if (!defined("WARN")) {
            define("WARN", 3);
        }
        if (!defined("ERROR")) {
            define("ERROR", 4);
        }

        define("NL", "\r\n");
        echo '<script type="text/javascript">' . NL;

        /// this is for IE and other browsers w/o console
        echo 'if (!window.console) console = {};';
        echo 'console.log = console.log || function(){};';
        echo 'console.warn = console.warn || function(){};';
        echo 'console.error = console.error || function(){};';
        echo 'console.info = console.info || function(){};';
        echo 'console.debug = console.debug || function(){};';
        echo '</script>';
        /// end of IE
    }

    function debug($name, $var = NULL, $type = LOG) {
        echo ' <script type="text/javascript">' . NL;
        switch ($type) {
            case LOG:
                echo 'console.log("' . $name . '");' . NL;
                break;
            case INFO:
                echo 'console.info("' . $name . '");' . NL;
                break;
            case WARN:
                echo 'console.warn("' . $name . '");' . NL;
                break;
            case ERROR:
                echo 'console.error("' . $name . '");' . NL;
                break;
        }

        if (!empty($var)) {
            if (is_object($var) || is_array($var)) {
                $object = json_encode($var);
                echo 'var object' . preg_replace('~[^A-Z|0-9]~i', "_", $name) . ' = \'' . str_replace("'", "\'", $object) . '\';' . NL;
                echo 'var val' . preg_replace('~[^A-Z|0-9]~i', "_", $name) . ' = eval("(" + object' . preg_replace('~[^A-Z|0-9]~i', "_", $name) . ' + ")" );' . NL;
                switch ($type) {
                    case LOG:
                        echo 'console.debug(val' . preg_replace('~[^A-Z|0-9]~i', "_", $name) . ');' . NL;
                        break;
                    case INFO:
                        echo 'console.info(val' . preg_replace('~[^A-Z|0-9]~i', "_", $name) . ');' . NL;
                        break;
                    case WARN:
                        echo 'console.warn(val' . preg_replace('~[^A-Z|0-9]~i', "_", $name) . ');' . NL;
                        break;
                    case ERROR:
                        echo 'console.error(val' . preg_replace('~[^A-Z|0-9]~i', "_", $name) . ');' . NL;
                        break;
                }
            }
            else {
                switch ($type) {
                    case LOG:
                        echo 'console.debug("' . str_replace('"', '\\"', $var) . '");' . NL;
                        break;
                    case INFO:
                        echo 'console.info("' . str_replace('"', '\\"', $var) . '");' . NL;
                        break;
                    case WARN:
                        echo 'console.warn("' . str_replace('"', '\\"', $var) . '");' . NL;
                        break;
                    case ERROR:
                        echo 'console.error("' . str_replace('"', '\\"', $var) . '");' . NL;
                        break;
                }
            }
        }
        echo '</script>' . NL;
    }
}