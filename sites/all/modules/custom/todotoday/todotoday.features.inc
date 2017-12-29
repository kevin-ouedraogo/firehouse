<?php
/**
 * @file
 * todotoday.features.inc
 */

/**
 * Implements hook_node_info().
 */
function todotoday_node_info() {
  $items = array(
    'todotoday_task' => array(
      'name' => t('Task'),
      'base' => 'node_content',
      'description' => t('new content type created to handle new todo items for the module todotoday that we are about to create'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
