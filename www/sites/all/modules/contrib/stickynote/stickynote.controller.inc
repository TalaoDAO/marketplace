<?php

/**
 * @file
 * The controller class for the stickynote entity
 */

class StickynoteController extends DrupalDefaultEntityController {
  public function save($stickynote) {
    try {
      drupal_write_record('stickynote', $stickynote);
      field_attach_insert('stickynote', $stickynote);
      module_invoke_all('entity_insert', $stickynote, 'stickynote');
      return $stickynote;
    }
    catch (Exception $e) {
      watchdog_exception('stickynote', $e);
      throw $e;
    }
  }

  public function update($stickynote) {
    try {
      db_update('stickynote')
        ->fields(array(
          'note' => $stickynote->note,
          'updated' => $stickynote->updated,
        ))
        ->condition('snid', $stickynote->snid)
        ->execute();
      field_attach_update('stickynote', $stickynote);
      module_invoke_all('entity_update', $stickynote, 'stickynote');
      return $stickynote;
    }
    catch (Exception $e) {
      watchdog_exception('stickynote', $e);
      throw $e;
    }
  }

  public function delete($stickynote) {
    try {
      db_delete('stickynote')
        ->condition('snid', $stickynote->snid)
        ->execute();
      field_attach_delete('stickynote', $stickynote);
      module_invoke_all('entity_delete', $stickynote, 'stickynote');
    }
    catch (Exception $e) {
      watchdog_exception('stickynote', $e);
      throw $e;
    }
  }
}
