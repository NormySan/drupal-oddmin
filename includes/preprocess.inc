<?php

/**
 * @file
 * This file contains all template preprocess functions.
 */

/**
 * Add classes to dropbuttons to have them work properly with Semantic UI.
 *
 * Implements hook_preprocess_HOOK().
 */
function odd_admin_preprocess_links__dropbutton__operations(&$variables) {
  $count = 1;

  // Add classes to each link and set the key name as an icon.
  foreach ($variables['links'] as $key => $link) {
    $attributes = new \Drupal\Core\Template\Attribute();

    /** @var \Drupal\Core\StringTranslation\TranslatableMarkup $title */
    $title = $variables['links'][$key]['link']['#title'];

    // The first link needs to be handled differently since it's not a menu item.
    if ($count === 1) {
      $attributes->addClass(['ui', 'button']);
    }
    else {
      $attributes->addClass('item');
    }

    $variables['links'][$key]['link']['#attributes'] = $attributes->toArray();
    $variables['links'][$key]['icon'] = $key;

    $count++;
  }
}

/**
 * Add a gravatar when the username is dislayed.
 *
 * Implements hook_preprocess_HOOK().
 */
function odd_admin_preprocess_username(&$variables) {
  /** @var \Drupal\user\UserInterface $user */
  $user = $variables['account'];

  $hashed = md5(strtolower(trim($user->getEmail())));

  $url = \Drupal\Core\Url::fromUri("https://www.gravatar.com/avatar/{$hashed}", [
    'query' => [
      'd' => 'mm',
      's' => 100,
    ],
  ]);

  $variables['gravatar'] = $url->toString();
}

/**
 * Adds type class names and icons for status messages.
 *
 * Implements hook_preprocess_HOOK().
 */
function odd_admin_preprocess_status_messages(&$variables) {
  $variables['message_classes'] = [];
  $variables['message_icons'] = [];

  // Set the message classes and icons.
  foreach ($variables['message_list'] as $type => $messages) {
    $variables['message_classes'][$type] = $type;

    switch ($type) {
      case 'status':
        $variables['message_classes'][$type] = 'success';
        $variables['message_icons'][$type] = 'info circle icon';
        break;

      case 'error':
        $variables['message_icons'][$type] = 'remove circle icon';
        break;

      case 'warning':
        $variables['message_icons'][$type] = 'warning circle icon';
        break;

      default:
        $variables['message_icons'][$type] = 'announcement icon';
    }
  }
}

/**
 * Add the username to the user account menu block.
 *
 * Implements hook_preprocess_HOOK().
 */
function odd_admin_preprocess_block__useraccountmenu(&$variables) {
  /** @var \Drupal\Core\Session\AccountProxyInterface $user */
  $user = $variables['user'];

  $variables['username'] = [
    '#theme' => 'username',
    '#account' => $user->getAccount(),
  ];
}

/**
 * Add icons to the account menu items.
 *
 * Implements hook_preprocess_HOOK().
 */
function odd_admin_preprocess_menu__account(&$variables) {
  if (!isset($variables['items']) || !count($variables['items'])) {
    return;
  }

  foreach ($variables['items'] as $item_id => $item) {
    $icon = FALSE;

    switch ($item_id) {
      case 'user.page':
        $icon = 'user icon';
        break;

      case 'user.logout':
        $icon = 'power icon';
        break;
    }

    $variables['items'][$item_id]['icon'] = $icon;
  }
}

function odd_admin_preprocess_field_group_html_element(&$variables) {
  /** @var \Drupal\Core\Template\Attribute $attributes */
  $attributes = $variables['attributes'];

  $number_words = [
    'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight',
    'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'sexteen',
  ];

  $children = \Drupal\Core\Render\Element::children($variables['element']);
  $number_index = count($children) - 1;

  if (isset($number_words[$number_index])) {
    $attributes->addClass([$number_words[$number_index], 'fields']);
  }
}

function odd_admin_preprocess_input__textfield(&$variables) {

}
