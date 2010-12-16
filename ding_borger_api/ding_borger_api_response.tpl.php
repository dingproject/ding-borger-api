<div class="ding-borger-api-data"> 
  <?php print theme_status_messages() ?>
	  <?php if ($debt_notice) : ?>
	  <div class="ding-debts">
	    <?php print $debt_notice ?>
	  </div>
  <?php endif; ?>
  <div class="ding-loans">
    <h2><?php print t('Your loans') ?></h2>
    <?php print $loans ?>
  </div>
  <div class="ding-reservations">
    <?php print $reservations ?>
  </div> 
</div>