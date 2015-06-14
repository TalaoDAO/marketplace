
<div class="container container-fluid">
	<div class="row">
		<div class="col-sm-4 col-xs-12 header-emindhub">
			<?php if ($logo): ?>
				<a href="<?php print url("homepage"); ?>"><?php print $imagelogo; ?></a>
			<?php endif; ?>
			<?php if (user_is_logged_in()): ?>
				<div class="burger-menu-btn-container" onclick="onClickBurgerMenuBtn()">
					<?php print $openBurgerImg; ?>
				</div>
			<?php endif; ?>
		</div>
		<div class="col-sm-8 col-xs-12">
			<div class="row">
				<div class="col-sm-5 col-xs-12">
					<div class="form-group">
						<?php print render($page['searchmodule']); ?>
					</div>
				</div>

				<div class="col-sm-5 col-xs-9 text-right">
					<?php if ($firstMenu) {
						$length = count($firstMenu);
						foreach ($firstMenu as $index => $menuEntry) {
							if (strpos(strtolower($menuEntry), "sign-in") !== false) {  //looking for a class name added by template.php fn GetMenu() ?>
								<div class="popup-sign-in">
									<?php print $menuEntry; ?>
									<div class="popup-sign-in-content">
										<?php $tmp = drupal_get_form('user_login');
										print drupal_render($tmp); ?>
									</div>
								</div>
								<?php
							}
							else if (strpos(strtolower($menuEntry), "sign-up") !== false) {  //looking for a class name added by template.php fn GetMenu() ?>
							  <div class="popup-sign-up">
								  <?php print $menuEntry; ?>
								  <div class="popup-sign-up-content">
									  <?php print c_szSignIn; ?>
									  <span class="light-blue-text"><?php print c_szInAMinute; ?></span>
									  <?php print c_szStart; ?>
									  <a href="<?php print url("business/register"); ?>" class="btn btn-primary"><?php print c_szSeeker; ?></a>
									  <a href="<?php print url("expert/register"); ?>" class="btn btn-primary"><?php print c_szExpert; ?></a>
								  </div>
							  </div>
							<?php
							}
							else {
								print $menuEntry;
							}
							if ($index < $length-1) { ?>
								&nbsp;|&nbsp;
							<?php }
						 };
					} ?>
				</div>
				<div class="col-sm-1 col-xs-3">
					<div class="language-select">
						<?php print render($page['languageselect']); ?>
					</div>
				</div>
			</div>
			<div class="row">
				<?php print render($page['topmenu']); ?>
			</div>
		</div>
	</div>
</div>
