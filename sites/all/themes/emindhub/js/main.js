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