<!--    <select name="language">
        <option value="fr">FR</option>
        <option value="en">EN</option>
    </select>
-->

    <?php
    /*function theme_i18n_link($text, $target, $lang, $query= NULL, $fragment = NULL){
        $output = '<span class="i18n-link">';
        $attributes = ($lang == i18n_get_lang()) ? array('class' => 'active') : NULL;
        $output .= l(theme('i18n_language_icon', $lang), $target, $attributes, $query, $fragment, FALSE, TRUE);
        $output .= "&nbsp;";
        $output .= l($text, $target, $attributes, $query, $fragment, FALSE, TRUE);
        $output .= '</span>';
        return $output;
    }*/

    /** $Id: i18n_link.tpl.php, v 1.0 2007/11/06 quiptime Exp $
    *
    * Produces a language link with a right flag
    */
    function theme_i18n_link($text, $target, $lang, $query= NULL, $fragment = NULL){
        $output = '';
        $output .= '<span class="i18n-link">';
        $attributes = ($lang == i18n_get_lang()) ? array('class' => 'active') : NULL;
        $output .= l(theme('i18n_language_icon', $lang), $target, $attributes, $query, $fragment, FALSE, TRUE);
        $output .= "&nbsp;";
        $output .= l($text, $target, $attributes, $query, $fragment, FALSE, TRUE);
        $output .= '</span>';
        print $output;
    }
?>