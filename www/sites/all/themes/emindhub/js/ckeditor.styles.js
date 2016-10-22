// Called by all/modules/features/ft_wysiwyg/ft_wysiwyg.features.ckeditor_profile.inc

/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if(typeof(CKEDITOR) !== 'undefined') {
    CKEDITOR.addStylesSet( 'drupal',
    [
            /* Block Styles */


            /*{ name : 'Blue Titlee'		, element : 'h3', styles : { 'color' : 'Blue' } },
            { name : 'Red Titlea'		, element : 'h3', styles : { 'color' : 'Red' } },*/

            /* Inline Styles */

            { name : 'Introduction'	, element : 'div', attributes : { 'class' : 'introduction' } },
            /*{ name : 'Marker: Bleu'		, element : 'span', attributes : { 'class' : 'bleu' } },
            { name : 'Marker: Jaune'	, element : 'span', attributes : { 'class' : 'jaune' } },

            { name : 'Big'				, element : 'big' },
            { name : 'Small'			, element : 'small' },
            { name : 'Typewriter'		, element : 'tt' },

            { name : 'Computer Code'	, element : 'code' },
            { name : 'Keyboard Phrase'	, element : 'kbd' },
            { name : 'Sample Text'		, element : 'samp' },
            { name : 'Variable'			, element : 'var' },

            { name : 'Deleted Text'		, element : 'del' },
            { name : 'Inserted Text'	, element : 'ins' },

            { name : 'Cited Work'		, element : 'cite' },
            { name : 'Inline Quotation'	, element : 'q' },

            { name : 'Language: RTL'	, element : 'span', attributes : { 'dir' : 'rtl' } },
            { name : 'Language: LTR'	, element : 'span', attributes : { 'dir' : 'ltr' } },*/

            /* Object Styles */

            // {
            //         name : 'Image on Left',
            //         element : 'img',
            //         attributes :
            //         {
            //                 'style' : 'margin-right: 10px',
            //                 'align' : 'left'
            //         }
            // },
            //
            // {
            //         name : 'Image on Right',
            //         element : 'img',
            //         attributes :
            //         {
            //                 'style' : 'margin-left: 10px',
            //                 'align' : 'right'
            //         }
            // }
    ]);
}
