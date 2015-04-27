<?php

/**
 * Implements hook_drush_command().
 */
function export_structure_drush_command() {
  $items = array();
  $items['export-structure'] = array(
    'description' => 'Export all content types, vocabularies and fields to the install profile of your choosing.',
    'options' => array(),
  );

  $defaults = _export_structure_get_defaults();
  foreach ($defaults as $option => $data) {
    $items['export-structure']['options'][$option] = $data['desc'];
  }

  return $items;
}

/**
 * Callback function for export-structure
 */
function drush_export_structure() {
  $defaults = _export_structure_get_defaults();
  $args = array();
  foreach ($defaults as $name => $data) {
    $args[$name] = drush_get_option($name, $data['val']);
  }

  _export_structure_page_callback($args);
}