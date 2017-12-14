/**
 * @file
 * A class for comminicating with a drupal site with a services endpoint.
 *
 * For documentation, see project page.
 */


/**
 * Constructor.
 */
var drupalService = function() {
  this.url;
  this.data;
  this.method;
  this.callback = function(data) {
    console.log(data);
  }
  this.error = function(data) {
    console.log(data);
  }
}

/**
 * Function to send post requests.
 */
drupalService.prototype.post = function() {
  var xhr = this.xhr('post');
  xhr.send(JSON.stringify(this.data));
}

/**
 * Function to send GET requests.
 */
drupalService.prototype.get = function() {
  var xhr = this.xhr('get');
  xhr.send();
}

/**
 * Internal function to set up ajax request.
 */
drupalService.prototype.xhr = function(op, fn) {
  var url = this.url + '/' + this.method;
  var xhr = new XMLHttpRequest();
  var service = this;
  xhr.onreadystatechange = function() {
    if (xhr.readyState == 4) {
      if (xhr.status == 200) {
        service.callback(JSON.parse(xhr.responseText));
      }
      else {
        service.error(xhr);
      }
    }
  }
  switch (op) {
    case 'get':
      xhr.open('GET', url, true);
      break;

    case 'post':
      xhr.open('POST', url, true);
      xhr.setRequestHeader("Content-type", "application/json");
      break;

    // @todo: other requests that GET and POST.
  }
  return xhr;
}
