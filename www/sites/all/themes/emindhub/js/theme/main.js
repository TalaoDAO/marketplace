/*
  eslint
    indent: ["off", 2],
    eqeqeq: "warn",
    no-unused-vars: "warn",
    camelcase: "warn",
*/

function onClickBurgerMenuBtn () {
  var bm = document.querySelector('.region-burgermenu');
  if (bm) {
    bm.style.display = (bm.style.display != 'none' && bm.style.display != '') ? 'none' : 'block';
    if (bm.style.display != 'none' && bm.style.display != '') {
      document.body.onclick = onClickBody;
    } else {
      document.body.onclick = null;
    }
  }
}

function onClickBody (evt) {
    var elt = evt.target;
    while (elt != null) {
        if (elt.className.indexOf('region-burgermenu') != -1 || elt.className.indexOf('burger-menu-btn-container') != -1) {
            return;
        }
        elt = elt.parentElement;
    }
    // On est arrivé jusque ici donc on as pas cliqué dans le burger menu
    var bm = document.querySelector('.region-burgermenu');
    bm.style.display = 'none';
    document.body.onclick = null;
}

document.addEventListener('DOMContentLoaded', FileUpload, false);
// Init works on file upload change to update the text input associated with file name
function FileUpload () {
    var fileInputs  = document.querySelectorAll('.form-file');

    for (var idx in fileInputs) {
        if (fileInputs.hasOwnProperty(idx)) {
            var fi = fileInputs[idx];
            if ((typeof fi).toLowerCase() == 'object') {
                fi.addEventListener('change', function () {
                    var the_return = document.querySelector("[data-fileinputtext='" + this.id + "']");
                    the_return.value = this.files[0].name;
                });
            }
        }
    }
}

(function ($) {
  // @see http://stackoverflow.com/a/13203876
  $(document).ready(function () {
    $('#signIn').popover({
      content: function () {
        return $('#signInContent').html();
      },
      container: 'body'
    });
    $('#signUp').popover({
      content: function () {
        return $('#signUpContent').html();
      },
      container: 'body'
    });

    // Bootstrap tooltip
    // $('.help-tip').tooltip({
    //   html: true,
    // });

    // Stop video in modal when you close it
    $('#videoModal').on('hidden.bs.modal', function (e) {
      $('#videoModal iframe').attr('src', $('#videoModal iframe').attr('src'));
    });
  });
})(jQuery);

function debounce (func, wait, immediate) {
  var timeout;
  return function () {
    var context = this;
    var args = arguments;
    var later = function () {
      timeout = null;
      if (!immediate) func.apply(context, args);
    };
    var callNow = immediate && !timeout;
    clearTimeout(timeout);
    timeout = setTimeout(later, wait);
    if (callNow) func.apply(context, args);
  };
};

var shiftWindow = function () { scrollBy(0, -150); };
window.addEventListener('hashchange', shiftWindow);
function load () { if (window.location.hash) shiftWindow(); }
