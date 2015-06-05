function onClickBurgerMenuBtn() {
    var bm = document.querySelector('.region-burgermenu');
    if (bm) {
        bm.style.display = (bm.style.display != 'none'&& bm.style.display != '') ? 'none': 'block';
        if (bm.style.display != 'none'&& bm.style.display != '') {
            document.body.onclick = onClickBody;
        }
        else {
            document.body.onclick = null;
        }
    }
}

function onClickBody(evt) {
    var elt = evt.target;
    while (elt != null) {
        if (elt.className.indexOf("region-burgermenu") != -1 || elt.className.indexOf("burger-menu-btn-container") != -1) {
            return;
        }
        elt = elt.parentElement;
    }
    //On est arrivé jusque ici donc on as pas cliqué dans le burger menu
    var bm = document.querySelector('.region-burgermenu');
    bm.style.display = 'none';
    document.body.onclick = null;
}


document.addEventListener('DOMContentLoaded', FileUpload, false);
//Init works on file upload change to update the text input associated with file name
function FileUpload() {
    var fileInputs  = document.querySelectorAll(".form-file");

    for (var idx in fileInputs) {
        if (fileInputs.hasOwnProperty(idx)) {
            var fi = fileInputs[idx];
            if ((typeof fi).toLowerCase() == "object") {
                fi.addEventListener( "change", function() {
                    var the_return =document.querySelector("[data-fileinputtext='" + this.id + "']");
                    the_return.value = this.files[0].name;
                });
            }
        }
    }
}


function signInClick(evt) {
    var eltSignUp = document.querySelector("div.popup-sign-up");
    eltSignUp.classList.remove("popup-sign-up-click");
    var elt = document.querySelector("div.popup-sign-in");
    elt.classList.add("popup-sign-in-click");
    document.body.onclick = onClickBodySignIn;
}

function onClickBodySignIn(evt) {
    var elt = evt.target;
    while (elt != null) {
        if (elt.className.indexOf("popup-sign-in") != -1 || elt.className.indexOf("popup-sign-in-content") != -1) {
            return;
        }
        elt = elt.parentElement;
    }
    //On est arrivé jusque ici donc on as pas cliqué dans le burger menu
    var elt = document.querySelector('div.popup-sign-in');
    elt.classList.remove("popup-sign-in-click");
    //bm.style.display = 'none';
    document.body.onclick = null;
}

function signUpClick(evt) {
    var eltSignIn = document.querySelector('div.popup-sign-in');
    eltSignIn.classList.remove("popup-sign-in-click");
    var elt = document.querySelector("div.popup-sign-up");
    elt.classList.add("popup-sign-up-click");
    document.body.onclick = onClickBodySignUp;
}

function onClickBodySignUp(evt) {
    var elt = evt.target;
    while (elt != null) {
        if (elt.className.indexOf("popup-sign-up") != -1 || elt.className.indexOf("popup-sign-up-content") != -1) {
            return;
        }
        elt = elt.parentElement;
    }
    //On est arrivé jusque ici donc on as pas cliqué dans le burger menu
    var elt = document.querySelector('div.popup-sign-up');
    elt.classList.remove("popup-sign-up-click");
    //bm.style.display = 'none';
    document.body.onclick = null;
}

/*
function signUpHover(evt) {

    console.log(event);
    var elt = event.toElement;
    var left = elt.offsetLeft /2;
    elt = elt.offsetParent;
    while (elt != null) {
        left += elt.offsetLeft;
        elt = elt.offsetParent;
    }
    console.log(left);
}*/
/*
$(function () {
    var options = {
        html: true,
        content: $('.popup-sign-up-content').html(),
        placement: 'bottom',
        //trigger: 'hover',
        trigger: 'manual',
        delay: {
            "show": 100,
            "hide": 800
        }
    };
    $('[data-toggle="popover"]').popover(options).mouseenter(function (e) {
        $(this).popover('show');
    });
})*/