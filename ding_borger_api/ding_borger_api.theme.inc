<?php
// $Id$

/**
 * Theming of reservation detailed list form.
 */
function theme_ding_borger_api_reservation_list_form($form) {
  $date_format = variable_get('date_format_date_short', 'Y-m-d');
  $output = '';
  module_load_include('client.inc', 'ting');

  if (!empty($form['reservations']['#grouped']['fetchable'])) {
    $header = array(
      t('Select'),
      '',
      t('Title'),
      t('Pickup number'),
      t('Pickup by'),
      t('Pickup branch'),
    );

        $colgroups = array(
      array(
        array(
          'class' => 'col-selection',
        ),
      ),
      array(
        array(
          'class' => 'col-image',
        ),
      ),
      array(
        array(
          'class' => 'col-title',
        ),
      ),
      array(
        array(
          'class' => 'col-pickup-number',
        ),
      ),
      array(
        array(
          'class' => 'col-pickup-by',
        ),
      ),
      array(
        array(
          'class' => 'col-pickup-branch',
        ),
      ),
    );

    $rows = array();

    foreach ($form['reservations']['#grouped']['fetchable'] as $item) {
      $cells = array();
      if (isset($form['reserved'][$item['id']])) {
        $cells['checkbox'] = array(
          'class' => 'checkbox',
          'data' => drupal_render($form['reserved'][$item['id']]),
        );
      }
      else {
        $cells['checkbox'] = array(
          'class' => 'checkbox empty',
          'data' => '–',
        );
      }

      $image_url = ting_covers_faust_url($item['record_id'], '80_x');
      $cells['image'] = array(
        'class' => 'image',
        'data' => ($image_url) ? theme('image', $image_url, '', '', NULL, FALSE) : '',
      );

      $cells['title'] = array(
        'class' => 'title',
        'data' => theme('borger_api_library_user_list_item', 'reservation', $item) . ' (<span class="reservation-number">' . t('Res. no @num', array('@num' => $item['id'])) . '</span>)',
      );

      $cells['pickup_number'] = array(
        'class' => 'pickup_number',
        'data' => $item['pickup_number'],
      );

      $cells['pickup_expire_date'] = array(
        'class' => 'pickup_expire_date',
        'data' => ding_library_user_format_date($item['pickup_expire_date'], $date_format),
      );

      $cells['pickup_branch'] = array(
        'class' => 'pickup_branch',
        'data' => $item['pickup_branch'] ? $item['pickup_branch'] : t('Unknown'),
      );

      $rows[] = $cells;
    }

    $output .= theme('table', $header, $rows, array('id' => 'reservations-fetchable', 'colgroups' => $colgroups), t('Reservations ready for pickup'));
  }

  if (!empty($form['reservations']['#grouped']['active'])) {
    $header = array(
      t('Select'),
      '',
      t('Title'),
      t('Reserved'),
      t('Valid to'),
      t('Pickup branch'),
      t('Queue number'),
    );

    $colgroups = array(
      array(
        array(
          'class' => 'col-selection',
        ),
      ),
      array(
        array(
          'class' => 'col-image',
        ),
      ),
      array(
        array(
          'class' => 'col-title-res',
        ),
      ),
      array(
        array(
          'class' => 'col-reservation',
        ),
      ),
      array(
        array(
          'class' => 'col-valied-to',
        ),
      ),
      array(
        array(
          'class' => 'col-pickup-branch',
        ),
      ),
      array(
        array(
          'class' => 'col-queue-number',
        ),
      ),
    );

    $rows = array();
    foreach ($form['reservations']['#grouped']['active'] as $item) {
      $cells = array();
      if (isset($form['reserved'][$item['id']])) {
        $cells['checkbox'] = array(
          'class' => 'checkbox',
          'data' => drupal_render($form['reserved'][$item['id']]),
        );
      }
      else {
        $cells['checkbox'] = array(
          'class' => 'checkbox empty',
          'data' => '–',
        );
      }

      $image_url = ting_covers_faust_url($item['record_id'], '80_x');
      $cells['image'] = array(
        'class' => 'image',
        'data' => ($image_url) ? theme('image', $image_url, '', '', NULL, FALSE) : '',
      );

      $cells['title'] = array(
        'class' => 'title',
        'data' => theme('ding_library_user_list_item', 'reservation', $item) . ' (<span class="reservation-number">' . t('Res. no @num', array('@num' => $item['id'])) . '</span>)',
      );

      $cells['create_date'] = array(
        'class' => 'create_date',
        'data' => ding_library_user_format_date($item['create_date'], $date_format),
      );

      $cells['valid_to'] = array(
        'class' => 'valid_to',
        'data' => ding_library_user_format_date($item['valid_to'], $date_format),
      );

      $cells['pickup_branch'] = array(
        'class' => 'pickup_branch',
        'data' => $item['pickup_branch'] ? $item['pickup_branch'] : t('Unknown'),
      );

      $cells['queue_number'] = array(
        'class' => 'queue_no',
        'data' => $item['queue_number'],
      );

      $rows[] = array(
        'data' => $cells,
        'class' => 'active-reservations',
      );
    }

    $output .= theme('table', $header, $rows, array('id' => 'reservations-active', 'colgroups' => $colgroups), t('Active reservations'));
  }

  if (empty($output)) {
    return t('No reservations found.');
  }

  $output .= '<div class="update-controls clear-block">';
  $output .= drupal_render($form['options']);
  $output .= '</div>';

  // fisk
  $output .= '<div class="update-controls-button clear-block">';
  $output .= drupal_render($form['buttons']);
  $output .= '</div>';

  //return $output;


  //form ID etc
  //$output .= drupal_render($form);

  return $output;
}



/**
 * Theming of loan details form.
 */
function theme_ding_borger_api_loan_list_form($form) {
  $date_format = variable_get('date_format_date_short', 'Y-m-d');
  module_load_include('client.inc', 'ting');
  $groups = array();
  $output = '';
  $header = array(t('Select'), '', t('Title'), t('Loan date'), t('Due date'));

  $colgroups = array(
    array(
      array(
        'class' => 'col-selection',
      ),
    ),
    array(
      array(
        'class' => 'col-image',
      ),
    ),
    array(
      array(
        'class' => 'col-title',
      ),
    ),
    array(
      array(
        'class' => 'col-loan-date',
      ),
    ),
    array(
      array(
        'class' => 'col-due-date',
      ),
    ),
  );

  foreach ($form['loan_data']['#grouped'] as $date => $group) {
    // Overdue loans get preferential treatment. No checkboxes here.
    if ($date == 'overdue') {
      $table_title = t('Overdue loans');
    }
    // The normal loans get grouped by due date.
    else {
      if ($date == 'due') {
        $table_title = t('Due today');
      }
      else {
        $table_title = t('Due in @count days, @date', array('@date' => date('d/m/y', strtotime($date)), '@count' => ceil((strtotime($date) - $_SERVER['REQUEST_TIME']) / 86400)));
      }
    }

    $rows = array();
    foreach ($group as $loan_id) {
      $loan = $form['loan_data']['#value'][$loan_id];
      $cells = array();

      $cells['checkbox'] = array(
        'class' => 'checkbox',
        'data' => drupal_render($form['loans'][$loan_id]),
      );

      $cells['image'] = array(
        'class' => 'image',
        'data' => theme('ding_library_user_list_item_image', 'loan', $loan, '80_x'),
      );

      $cells['title'] = array(
        'class' => 'title',
        'data' => theme('ding_library_user_list_item', 'loan', $loan),
      );

      $cells['loan_date'] = array(
        'class' => 'loan_date',
        'data' => ding_library_user_format_date($loan['loan_date'], $date_format),
      );

      $cells['due_date'] = array(
        'class' => 'due_date',
        'data' => ding_library_user_format_date($loan['due_date'], $date_format),
      );

      $rows[] = array(
        'data' => $cells,
        'class' => ($checkbox) ? 'selectable' : 'immutable',
      );
    }

    if (!empty($rows)) {
      $output .= theme('table', $header, $rows, array('colgroups' => $colgroups), $table_title);
    }
  }
  if (empty($output)) {
    return t('No loans found.');
  }
  $output .= drupal_render($form);
  return $output;
}

