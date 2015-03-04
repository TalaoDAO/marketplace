
<div class="container container-fluid">
    <div class="row">
        <div class="col-md-4 header-emindhub">
            <?php if ($logo): ?>
                <a href="<?php print url("homepage"); ?>"><?php print $imagelogo; ?></a>
            <?php endif; ?>
            <div class="burger-menu-btn-container" onclick="var bm = document.querySelector('.region-burgermenu');if (bm) {bm.style.display = (bm.style.display != 'none'&& bm.style.display != '')? 'none': 'block';}">
                <?php print $openBurgerImg; ?>
            </div>
        </div>
        <div class="col-md-8">
            <div class="row">
                <div class="col-md-5">
                    <div class="form-group">
                        <?php print render($page['searchmodule']); ?>

                    </div>
                </div>

                <div class="col-md-6">
                    <?php if ($firstMenu): ?>
                        <?php $length = count($firstMenu); ?>
                        <?php foreach ($firstMenu as $index => $menuEntry): ?>
                            <?php print $menuEntry; ?>
                            <?php if ($index < $length-1): ?>|<?php endif; ?>
                        <?php endforeach; ?>
                    <?php endif; ?>

                </div>
                <div class="col-md-1">
                    <div class="language-select">
                        <?php print render($page['languageselect']); ?>
                    </div>
                </div>
            </div>
            <div class="row">
                <?php print render($page['topmenu']); ?>
            </div>
        </div>
    </div>
</div>