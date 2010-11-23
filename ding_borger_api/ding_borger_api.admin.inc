<?php

// $Id$

function ding_borger_api_admin_settings_form() {
	$form = array();
	
	$form['ding_borger_api_allowed_ips'] = array(
	  '#title' => t('Allowed IPs'),
	  '#description' => t('Only requests from these IP addresses will be served. No IPs disables access protection. Add 127.0.0.1 to allow local testing.'),
    '#type' => 'textarea',
	  '#default_value' => variable_get('ding_borger_api_allowed_ips', ''),
	);
  $form['ding_borger_api_response_cache_duration'] = array(
    '#type' => 'select',
    '#title' => t('Response cache duration'),
    '#description' => t('Determines how long service responses will be cached for.'),
    '#options' => array(
      60 => t('1 minute'),
      180=> t('3 minutes'),
      300 => t('5 minutes'),
      900 => t('15 minutes'),
      1800 => t('30 minutes'),
      3600 => t('1 hour'),
      10800 => t('3 hours'),
      43200 => t('12 hours'),
    ),
    '#default_value' => variable_get('ding_borger_api_response_cache_duration', 300),
  );
	
	return system_settings_form($form);
}
