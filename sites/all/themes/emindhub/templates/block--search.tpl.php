<form action="<?=$elements['#action']?>" method="<?=$elements['#method']?>">
    <label class="element-invisible" for="edit-search-block-form--2">Rechercher </label>
    <input title="<?php print c_szSearchTerms; ?>" class="search-input form-control form-text" placeholder="<?php print c_szSearchKeywords; ?>" onkeypress="if (event.keyCode == 13) { this.parentElement.submit(); }" type="text" id="edit-search-block-form--2" name="search_block_form" value="" size="40" maxlength="128" />
    <?php
    print render($elements['form_build_id']);
    print render($elements['form_id']);
    print render($elements['form_token']);
    ?>
</form>
