<div class="container container-fluid">
    <div class="row">
        <div class="col-md-4">
            <?php if ($logo): ?>
                <?php print $imagelogo; ?>
            <?php endif; ?>
        </div>
        <div class="col-md-8">
            <div class="row">
                <div class="col-md-5">
                    <div class="form-group">
                        <input type="text" class="search-input form-control" placeholder="Votre recherche, mots clefs...">
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
                <?php if ($secondMenu): ?>
                    <?php //$length = count($firstMenu); ?>
                    <?php foreach ($$second as $index => $menuEntry): ?>
                        <?php print $menuEntry; ?>
                        <?php if ($index < $length-1): ?>|<?php endif; ?>
                    <?php endforeach; ?>
                <?php endif; ?>
                <div class="col-md-4"><a href="./content/qui-sommes-nous">QUI SOMMES NOUS ?</a></div>
                <div class="col-md-4"><a href="./content/quapportons-nous">QU'APPORTONS-NOUS ?</a></div>
                <div class="col-md-4">
                    <a  class="contact-us bold" href="">
                        <?php print $mailIcon; ?>
                        CONTACTEZ NOUS
                    </a>
                </div>
            </div>
        </div>
    </div>
</div>