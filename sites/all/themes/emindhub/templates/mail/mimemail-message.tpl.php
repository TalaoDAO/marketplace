<?php

/**
 * @file
 * Default theme implementation to format an HTML mail.
 *
 * Copy this file in your default theme folder to create a custom themed mail.
 * Rename it to mimemail-message--[module]--[key].tpl.php to override it for a
 * specific mail.
 *
 * Available variables:
 * - $recipient: The recipient of the message
 * - $subject: The message subject
 * - $body: The message body
 * - $css: Internal style sheets
 * - $module: The sending module
 * - $key: The message identifier
 *
 * @see template_preprocess_mimemail_message()
 */
$site_name = variable_get('site_name');
global $base_url;
?>
	<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
	<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
		<meta name="format-detection" content="telephone=no" /> <!-- disable auto telephone linking in iOS -->
		<title><?php print $subject; ?></title>
		<?php if ($css): ?>
    <style type="text/css">
      <!--
      <?php print $css ?>
      -->
    </style>
    <?php endif; ?>
		<!--[if mso 12]>
			<style type="text/css">
				.flexibleContainer{display:block !important; width:100% !important;}
			</style>
		<![endif]-->
		<!--[if mso 14]>
			<style type="text/css">
				.flexibleContainer{display:block !important; width:100% !important;}
			</style>
		<![endif]-->
	</head>
	<body id="mimemail-body" <?php if ($module && $key): print 'class="'. $module .'-'. $key .'"'; endif; ?> bgcolor="#F2F2F2" leftmargin="0" marginwidth="0" topmargin="0" marginheight="0" offset="0">

		<center style="background-color:#F2F2F2;">
			<table border="0" cellpadding="0" cellspacing="0" height="100%" width="100%" id="bodyTable" style="table-layout: fixed;max-width:100% !important;width: 100% !important;min-width: 100% !important;">
				<tr>
					<td align="center" valign="top" id="bodyCell">

						<table bgcolor="#F2F2F2" border="0" cellpadding="0" cellspacing="0" width="500" id="emailHeader">

							<tr>
								<td align="center" valign="top">
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr>
											<td align="center" valign="top">
												<table border="0" cellpadding="10" cellspacing="0" width="500" class="flexibleContainer">
													<tr>
														<td valign="top" width="500" class="flexibleContainerCell">
															<table align="left" border="0" cellpadding="0" cellspacing="0" width="100%">
																<tr>
																	<td align="left" valign="middle" id="invisibleIntroduction" class="flexibleContainerBox" style="display:none !important; mso-hide:all;">
																		<table border="0" cellpadding="0" cellspacing="0" width="100%" style="max-width:100%;">
																			<tr>
																				<td align="left" class="textContent">
																					<div style="font-family:Helvetica,Arial,sans-serif;font-size:13px;color:#828282;text-align:center;line-height:120%;">
																						<?php print $subject; ?>
																					</div>
																				</td>
																			</tr>
																		</table>
																	</td>
																</tr>
															</table>
														</td>
													</tr>
												</table>
											</td>
										</tr>
									</table>
								</td>
							</tr>

						</table>

						<table bgcolor="#FFFFFF"  border="0" cellpadding="0" cellspacing="0" width="500" id="emailBody">

							<tr>
								<td align="center" valign="top">
									<table border="0" cellpadding="0" cellspacing="0" width="100%" style="color:#FFFFFF;" bgcolor="#009FE3">
										<tr>
											<td align="center" valign="top">
												<table border="0" cellpadding="0" cellspacing="0" width="500" class="flexibleContainer">
													<tr>
														<td align="center" valign="top" width="500" class="flexibleContainerCell">
															<table border="0" cellpadding="30" cellspacing="0" width="100%">
																<tr>
																	<td align="center" valign="top" class="textContent">
																		<h1 style="color:#FFFFFF;line-height:100%;font-family:Helvetica,Arial,sans-serif;font-size:25px;font-weight:normal;margin-bottom:5px;text-align:center;"><?php print $subject; ?></h1>
																	</td>
																</tr>
															</table>
														</td>
													</tr>
												</table>
											</td>
										</tr>
									</table>
								</td>
							</tr>

							<tr>
								<td align="left" valign="top">
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr>
											<td align="left" valign="top">
												<table border="0" cellpadding="0" cellspacing="0" width="500" class="flexibleContainer">
													<tr>
														<td align="left" valign="top" width="500" class="flexibleContainerCell">
															<table border="0" cellpadding="30" cellspacing="0" width="100%">
																<tr>
																	<td align="left" valign="top">
																		<table border="0" cellpadding="0" cellspacing="0" width="100%">
																			<tr>
																				<td valign="top" class="textContent">
																					<?php print $body ?>
																				</td>
																			</tr>
																		</table>
																	</td>
																</tr>
															</table>
														</td>
													</tr>
												</table>
											</td>
										</tr>
									</table>
								</td>
							</tr>

							<!-- Signature -->
							<tr>
								<td align="left" valign="top">
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr>
											<td align="left" valign="top">
												<table border="0" cellpadding="0" cellspacing="0" width="500" class="flexibleContainer">
													<tr>
														<td align="left" valign="top" width="500" class="flexibleContainerCell">
															<table border="0" cellpadding="30" cellspacing="0" width="100%">
																<tr>
																	<td align="left" valign="top">
																		<table border="0" cellpadding="0" cellspacing="0" width="100%">
																			<tr>
																				<td valign="top" class="textContent">
																					<div style="text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:15px;margin-bottom:0;color:#333;line-height:135%;font-weight:bold;"><?php print $site_name; ?></div>
																					<div style="text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:15px;margin-bottom:0;margin-top:3px;color:#333;line-height:135%;"><a href="<?php print $base_url; ?>" target="_blank" style="text-decoration:none;color:#009FE3;"><span style="text-decoration:none;color:#009FE3;"><?php print $base_url; ?></span></a></div>
																				</td>
																			</tr>
																		</table>
																	</td>
																</tr>
															</table>
														</td>
													</tr>
												</table>
											</td>
										</tr>
									</table>
								</td>
							</tr>

						</table>

						<table bgcolor="#F2F2F2" border="0" cellpadding="0" cellspacing="0" width="500" id="emailFooter">
							<tr>
								<td align="center" valign="top">
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr>
											<td align="center" valign="top">
												<table border="0" cellpadding="0" cellspacing="0" width="500" class="flexibleContainer">
													<tr>
														<td align="center" valign="top" width="500" class="flexibleContainerCell">
															<table border="0" cellpadding="30" cellspacing="0" width="100%">
																<tr>
																	<td valign="top" bgcolor="#F2F2F2">

																		<div style="font-family:Helvetica,Arial,sans-serif;font-size:13px;color:#828282;text-align:center;line-height:120%;">
																			<div>Copyright &#169; <?php echo date("Y"); ?> <a href="<?php print $base_url; ?>" target="_blank" style="text-decoration:none;color:#828282;"><span style="color:#828282;"><?php print $site_name; ?></span></a></div>
																		</div>

																	</td>
																</tr>
															</table>
														</td>
													</tr>
												</table>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>

					</td>
				</tr>
			</table>
		</center>
	</body>
</html>
