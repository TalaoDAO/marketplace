/*
  How to use

  backstop reference --configPath=settings.js
       backstop test --configPath=settings.js

  backstop reference --configPath=settings.js --refhost=http://example.com
       backstop test --configPath=settings.js --testhost=http://example.com

  backstop reference --configPath=settings.js --paths=/,/contact
       backstop test --configPath=settings.js --paths=/,/contact

  backstop reference --configPath=settings.js --pathfile=paths
       backstop test --configPath=settings.js --pathfile=paths

http://fivemilemedia.co.uk/blog/backstopjs-javascript-configuration
 */

/*
  Set up some variables
 */
var arguments = require('minimist')(process.argv.slice(2)); // grabs the process arguments
var defaultPaths = ['/']; // By default is just checks the homepage
var scenarios = []; // The array that'll have the pages to test

/*
  Work out the environments that are being compared
 */
// The host to test
if (!arguments.testhost) {
  arguments.testhost  = "http://emh.box.local"; // Default test host
}
// The host to reference
if (!arguments.refhost) {
  arguments.refhost  = "https://www.emindhub.com"; // Default test host
}
/*
  Work out which paths to use, either a supplied array, an array from a file, or the defaults
 */
if (arguments.paths) {
  pathString = arguments.paths;
  var paths = pathString.split(',');
} else if (arguments.pathfile) {
  var pathConfig = require('./'+arguments.pathfile+'.js');
  var paths = pathConfig.paths.array;
  var anon_paths = pathConfig.anon_paths.array;
} else {
  var paths = defaultPaths; // keep with the default of just the homepage
}

for (var k = 0; k < anon_paths.length; k++) {
  scenarios.push({
    "label": "anonymous_"+anon_paths[k],
    //"referenceUrl": arguments.refhost+anon_paths[k],
    "url": arguments.testhost+anon_paths[k],
    "hideSelectors": [],
    "removeSelectors": [],
    "selectors": [
      ".main-container",
      ".navbar",
      ".footer"
    ],
    "readyEvent": null,
    "delay": 1500,
    "misMatchThreshold" : 0.1,
    "onBeforeScript": "onBeforeLogout.js",
    "onReadyScript": "onReady.js"
  });
}

for (var k = 0; k < paths.length; k++) {
  scenarios.push({
    "label": paths[k],
    //"referenceUrl": arguments.refhost+paths[k],
    "url": arguments.testhost+paths[k],
    "hideSelectors": [],
    "removeSelectors": [],
    "selectors": [
      ".main-container",
      ".navbar",
      ".footer"
    ],
    "readyEvent": null,
    "delay": 1500,
    "misMatchThreshold" : 0.1,
    "onBeforeScript": arguments.nologin ? "onBeforeLogout.hs": "onBeforeLogin.js",
    "onReadyScript": "onReady.js"
  });
}


var viewports = []; 
if (arguments.restricted) {
  viewports = [
    {
      "name": "mediumish",
      "width": 568,
      "height": 760
    },
    {
      "name": "large",
      "width": 1024,
      "height": 768
    },
  ];
} else {
  viewports = [
    {
      "name": "small",
      "width": 320,
      "height": 480
    },
    {
      "name": "mediumish",
      "width": 568,
      "height": 760
    },
    {
      "name": "medium",
      "width": 768,
      "height": 1024
    },
    {
      "name": "large",
      "width": 1024,
      "height": 768
    },
    {
      "name": "xlarge",
      "width": 1440,
      "height": 900
    }
  ]
}

// Configuration
module.exports =
{
  "id": "prod_test",
  "viewports": viewports,
  "scenarios": scenarios,
  "paths": {
    "bitmaps_reference": "backstop_data/bitmaps_reference",
    "bitmaps_test":      "backstop_data/bitmaps_test",
    "casper_scripts":    "backstop_scripts",
    "html_report":       "backstop_data/html_report",
    "ci_report":         "backstop_data/ci_report"
  },
  "casperFlags": [],
  "engine": "phantomjs",
  "report": ["browser"],
  "debug": false
};
