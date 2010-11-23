<style type="text/css">
  @import url(<?php print url(drupal_get_path('module', 'ding_borger_api').'/css/ding_borger_api.css') ?>);
</style>
<div class="ding-borger-api-data"> 
  <?php print theme_status_messages() ?>
	  <?php if ($debt_notice) : ?>
	  <div class="ding-debts">
	    <?php print $debt_notice ?>
	  </div>
  <?php endif; ?>
  <div class="ding-loans">
    <?php print $loans ?>
  </div>
  <div class="ding-reservations">
    <?php print $reservations ?>
  </div> 
</div>