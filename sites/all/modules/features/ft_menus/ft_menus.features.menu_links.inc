<?php
/**
 * @file
 * ft_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ft_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about-us:node/267
  $menu_links['main-menu_about-us:node/267'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/267',
    'router_path' => 'node/%',
    'link_title' => 'About us',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_about-us:node/267',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_contact-us:contact
  $menu_links['main-menu_contact-us:contact'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact us',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_contact-us:contact',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_fields-of-expertise:fields-of-expertise
  $menu_links['main-menu_fields-of-expertise:fields-of-expertise'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'fields-of-expertise',
    'router_path' => 'fields-of-expertise',
    'link_title' => 'Fields of expertise',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_fields-of-expertise:fields-of-expertise',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_groups:groups
  $menu_links['main-menu_groups:groups'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'groups',
    'router_path' => 'groups',
    'link_title' => 'Groups',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_groups:groups',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_our-services:node/268
  $menu_links['main-menu_our-services:node/268'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/268',
    'router_path' => 'node/%',
    'link_title' => 'Our services',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_our-services:node/268',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-burger-menu_my-blog:blog/1
  $menu_links['menu-burger-menu_my-blog:blog/1'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'blog/1',
    'router_path' => 'blog/%',
    'link_title' => 'My blog',
    'options' => array(
      'menu_token_link_path' => 'blog/[current-user:name]',
      'menu_token_data' => array(),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-burger-menu_my-blog:blog/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-burger-menu_my-circles:my-circles
  $menu_links['menu-burger-menu_my-circles:my-circles'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'my-circles',
    'router_path' => 'my-circles',
    'link_title' => 'My circles',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'my-circles',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-burger-menu_my-circles:my-circles',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-burger-menu_my-dashboard:mybox
  $menu_links['menu-burger-menu_my-dashboard:mybox'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'mybox',
    'router_path' => 'mybox',
    'link_title' => 'My dashboard',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'my-dashboard',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-burger-menu_my-dashboard:mybox',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-burger-menu_my-demands:my-demands
  $menu_links['menu-burger-menu_my-demands:my-demands'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'my-demands',
    'router_path' => 'my-demands',
    'link_title' => 'My demands',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-burger-menu_my-demands:my-demands',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-burger-menu_my-drafts:user/2/drafts
  $menu_links['menu-burger-menu_my-drafts:user/2/drafts'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'user/2/drafts',
    'router_path' => 'user/%',
    'link_title' => 'My drafts',
    'options' => array(
      'menu_token_link_path' => 'user/[current-user:uid]/drafts',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 1,
      ),
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'my-drafts',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-burger-menu_my-drafts:user/2/drafts',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-burger-menu_my-profile:user
  $menu_links['menu-burger-menu_my-profile:user'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My profile',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-burger-menu_my-profile:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-burger-menu_my-responses:node/300
  $menu_links['menu-burger-menu_my-responses:node/300'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'node/300',
    'router_path' => 'node/%',
    'link_title' => 'My responses',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'my-responses',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-burger-menu_my-responses:node/300',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-burger-menu_my-responses:node/375
  $menu_links['menu-burger-menu_my-responses:node/375'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'node/375',
    'router_path' => 'node/%',
    'link_title' => 'My responses',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-burger-menu_my-responses:node/375',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-burger-menu_my-selections:my-selections
  $menu_links['menu-burger-menu_my-selections:my-selections'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'my-selections',
    'router_path' => 'my-selections',
    'link_title' => 'My selections',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'my-selections',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-burger-menu_my-selections:my-selections',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-burger-menu_my-testimony:testimony/1
  $menu_links['menu-burger-menu_my-testimony:testimony/1'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'testimony/1',
    'router_path' => 'testimony',
    'link_title' => 'My testimony',
    'options' => array(
      'menu_token_link_path' => 'testimony/[current-user:uid]',
      'menu_token_data' => array(),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-burger-menu_my-testimony:testimony/1',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-burger-menu_my-working-groups:groups
  $menu_links['menu-burger-menu_my-working-groups:groups'] = array(
    'menu_name' => 'menu-burger-menu',
    'link_path' => 'groups',
    'router_path' => 'groups',
    'link_title' => 'My working groups',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'my-working-groups',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-burger-menu_my-working-groups:groups',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-menu_legal-notice:node/304
  $menu_links['menu-footer-menu_legal-notice:node/304'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/304',
    'router_path' => 'node/%',
    'link_title' => 'Legal notice',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_legal-notice:node/304',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-menu_terms-of-use:legal/document/terms-of-use
  $menu_links['menu-footer-menu_terms-of-use:legal/document/terms-of-use'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'legal/document/terms-of-use',
    'router_path' => 'legal/document/%',
    'link_title' => 'Terms of Use',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_terms-of-use:legal/document/terms-of-use',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-networks_linkedin:https://www.linkedin.com/company/emindhub
  $menu_links['menu-networks_linkedin:https://www.linkedin.com/company/emindhub'] = array(
    'menu_name' => 'menu-networks',
    'link_path' => 'https://www.linkedin.com/company/emindhub',
    'router_path' => '',
    'link_title' => 'LinkedIn',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'id' => 'link-LinkedIn',
        'target' => '_blank',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-networks_linkedin:https://www.linkedin.com/company/emindhub',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top_my-account:user/164/edit
  $menu_links['menu-top_my-account:user/164/edit'] = array(
    'menu_name' => 'menu-top',
    'link_path' => 'user/164/edit',
    'router_path' => 'user/%/edit',
    'link_title' => 'My account',
    'options' => array(
      'menu_token_link_path' => 'user/[current-user:uid]/edit',
      'menu_token_data' => array(),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-top_my-account:user/164/edit',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top_my-circles:my-circles
  $menu_links['menu-top_my-circles:my-circles'] = array(
    'menu_name' => 'menu-top',
    'link_path' => 'my-circles',
    'router_path' => 'my-circles',
    'link_title' => 'My circles',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'no-after',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-top_my-circles:my-circles',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-top_my-workspace:<nolink>',
  );
  // Exported menu link: menu-top_my-demands:my-demands
  $menu_links['menu-top_my-demands:my-demands'] = array(
    'menu_name' => 'menu-top',
    'link_path' => 'my-demands',
    'router_path' => 'my-demands',
    'link_title' => 'My demands',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-top_my-demands:my-demands',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-top_my-workspace:<nolink>',
  );
  // Exported menu link: menu-top_my-drafts:menutoken/5562dd58b4022
  $menu_links['menu-top_my-drafts:menutoken/5562dd58b4022'] = array(
    'menu_name' => 'menu-top',
    'link_path' => 'menutoken/5562dd58b4022',
    'router_path' => 'menutoken/%',
    'link_title' => 'My drafts',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'menu_token_link_path' => 'user/[current-user:uid]/drafts',
      'menu_token_data' => array(),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'identifier' => 'menu-top_my-drafts:menutoken/5562dd58b4022',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-top_my-workspace:<nolink>',
  );
  // Exported menu link: menu-top_my-messages:messages
  $menu_links['menu-top_my-messages:messages'] = array(
    'menu_name' => 'menu-top',
    'link_path' => 'messages',
    'router_path' => 'messages',
    'link_title' => 'My messages',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-top_my-messages:messages',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-top_my-responses:node/300
  $menu_links['menu-top_my-responses:node/300'] = array(
    'menu_name' => 'menu-top',
    'link_path' => 'node/300',
    'router_path' => 'node/%',
    'link_title' => 'My responses',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-top_my-responses:node/300',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -36,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-top_:my-contributions/1',
  );
  // Exported menu link: menu-top_my-responses:node/375
  $menu_links['menu-top_my-responses:node/375'] = array(
    'menu_name' => 'menu-top',
    'link_path' => 'node/375',
    'router_path' => 'node/%',
    'link_title' => 'My responses',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-top_my-responses:node/375',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-top_my-workspace:<nolink>',
  );
  // Exported menu link: menu-top_my-selections:my-selections
  $menu_links['menu-top_my-selections:my-selections'] = array(
    'menu_name' => 'menu-top',
    'link_path' => 'my-selections',
    'router_path' => 'my-selections',
    'link_title' => 'My selections',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-top_my-selections:my-selections',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-top_my-workspace:<nolink>',
  );
  // Exported menu link: menu-top_my-testimony:testimony/1
  $menu_links['menu-top_my-testimony:testimony/1'] = array(
    'menu_name' => 'menu-top',
    'link_path' => 'testimony/1',
    'router_path' => 'testimony',
    'link_title' => 'My testimony',
    'options' => array(
      'menu_token_link_path' => 'testimony/[current-user:uid]',
      'menu_token_data' => array(),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-top_my-testimony:testimony/1',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-top_my-workspace:<nolink>',
  );
  // Exported menu link: menu-top_my-workspace:<nolink>
  $menu_links['menu-top_my-workspace:<nolink>'] = array(
    'menu_name' => 'menu-top',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'My workspace',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'top-menu-my-workspace',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-top_my-workspace:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: user-menu_messages:messages
  $menu_links['user-menu_messages:messages'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'messages',
    'router_path' => 'messages',
    'link_title' => 'Messages',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_messages:messages',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_register-as-an-expert:expert/register
  $menu_links['user-menu_register-as-an-expert:expert/register'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'expert/register',
    'router_path' => 'expert/register',
    'link_title' => 'Register as an expert',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_register-as-an-expert:expert/register',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_user-account:user
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About us');
  t('Contact us');
  t('Fields of expertise');
  t('Groups');
  t('Home');
  t('Legal notice');
  t('LinkedIn');
  t('Log out');
  t('Messages');
  t('My account');
  t('My blog');
  t('My circles');
  t('My dashboard');
  t('My demands');
  t('My drafts');
  t('My messages');
  t('My profile');
  t('My responses');
  t('My selections');
  t('My testimony');
  t('My working groups');
  t('My workspace');
  t('Our services');
  t('Register as an expert');
  t('Terms of Use');
  t('User account');

  return $menu_links;
}
