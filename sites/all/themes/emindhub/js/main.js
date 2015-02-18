function onClickBurgerMenuBtn() {
    var bm = document.getElementById("block-menu-menu-burger-menu");
    if (bm) {
        var bVisible = bm.style.display != "none" && bm.style.display != "";
        //bVisible = !bVisible;
        var strVisible = (bVisible)? "none": "block";
        bm.style.display = strVisible;
    }
}

document.querySelector(".region-burgermenu")