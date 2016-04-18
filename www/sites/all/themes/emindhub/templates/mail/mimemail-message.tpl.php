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
      <?php print $css; ?>
      -->
    </style>
    <?php endif; ?>
		<!--[if mso 12]>
			<style type="text/css">
				.flexibleContainer{display:block!important;width:100%!important;}
			</style>
		<![endif]-->
		<!--[if mso 14]>
			<style type="text/css">
				.flexibleContainer{display:block!important;width:100%!important;}
			</style>
		<![endif]-->
	</head>
	<body id="mimemail-body" <?php if ($module && $key): print 'class="'. $module .'-'. $key .'"'; endif; ?> bgcolor="#F2F2F2" leftmargin="0" marginwidth="0" topmargin="0" marginheight="0" offset="0">

		<center style="background-color:#F2F2F2;">
			<table border="0" cellpadding="0" cellspacing="0" height="100%" width="100%" id="bodyTable" style="table-layout:fixed;max-width:100%!important;width:100%!important;min-width:100%!important;">
				<tr>
					<td align="center" valign="top" id="bodyCell">

						<!-- Entête -->
						<table bgcolor="#F2F2F2" border="0" cellpadding="0" cellspacing="0" width="600" id="emailHeader">

							<tr>
								<td align="center" valign="top">
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr>
											<td align="center" valign="top">
												<table border="0" cellpadding="10" cellspacing="0" width="600" class="flexibleContainer">
													<tr>
														<td valign="top" width="600" class="flexibleContainerCell">
															<table align="center" border="0" cellpadding="0" cellspacing="0" width="100%">
																<tr>
																	<td align="center" valign="middle" class="flexibleContainerBox">
																		<table border="0" cellpadding="0" cellspacing="0" width="100%" style="max-width:100%;">
																			<tr>
																				<td align="center" style="padding:9px 18px;text-align:center!important;">
																					<a href="<?php print $base_url; ?>/?pk_campaign=website&amp;pk_kwd=logo" target="_blank" style="display:inline-block;">
																						<img alt="<?php print $site_name; ?>" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/logo/eMindHub_logo_baseline.png" style="width:200px;height:78px;margin:0px;" height="78" width="200" align="center">
																					</a>
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

						<table bgcolor="#FFFFFF" border="0" cellpadding="0" cellspacing="0" width="600" id="emailBody">

							<!-- Contenu + Signature -->
							<tr>
								<td align="left" valign="top">
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr>
											<td align="left" valign="top">
												<table border="0" cellpadding="0" cellspacing="0" width="600" class="flexibleContainer">
													<tr>
														<td align="left" valign="top" width="600" class="flexibleContainerCell">
															<table border="0" cellpadding="30" cellspacing="0" width="100%">
																<tr>
																	<td align="left" valign="top">
																		<table border="0" cellpadding="0" cellspacing="0" width="100%">
																			<tr>
																				<td valign="top">
																					<div style="text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:16px;margin-bottom:0;color:#333;line-height:150%;"><?php print $body ?></div>
																					<div style="padding-top:10px;color:#333;font-family:Helvetica,Arial,sans-serif;font-size:16px;line-height:150%;text-align:left;"><strong><?php print t('Your eMindHub team'); ?></strong></div>
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

						<table bgcolor="#F2F2F2" border="0" cellpadding="0" cellspacing="0" width="600" id="emailFooter">
							<tr>
								<td align="center" valign="top">
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr>
											<td align="center" valign="top">
												<table border="0" cellpadding="0" cellspacing="0" width="600" class="flexibleContainer">
													<tr>
														<td align="center" valign="top" width="600" class="flexibleContainerCell">
															<table border="0" cellpadding="30" cellspacing="0" width="100%">
																<tr>
																	<td bgcolor="#F2F2F2" style="padding-top:9px;padding-right:9px;padding-left:9px;" valign="top" align="center">
						                        <table align="center" border="0" cellpadding="0" cellspacing="0">
						                          <tbody><tr>
						                            <td valign="top" align="center">

                                    <!--[if mso]>
                                    <table align="center" border="0" cellspacing="0" cellpadding="0">
                                    <tr>
                                    <![endif]-->

                                      <!--[if mso]>
                                      <td align="center" valign="top">
                                      <![endif]-->


                                        <table style="display:inline;" align="left" border="0" cellpadding="0" cellspacing="0">
                                          <tbody><tr>
                                              <td style="padding-right:10px;padding-bottom:9px;" valign="top">
                                                  <table width="100%" border="0" cellpadding="0" cellspacing="0">
                                                      <tbody><tr>
                                                          <td style="padding-top:5px;padding-right:10px;padding-bottom:5px;padding-left:9px;" valign="middle" align="left">
                                                              <table width="" align="left" border="0" cellpadding="0" cellspacing="0">
                                                                  <tbody><tr>

                                                                          <td valign="middle" width="24" align="center">
                                                                              <a href="<?php print $base_url; ?>/?pk_campaign=website&amp;pk_kwd=picto" target="_blank"><img alt="<?php print $site_name; ?>" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/picto/picto_emindhub_small.png" style="display:block;" height="24" width="24"></a>
                                                                          </td>


                                                                          <td style="padding-left:5px;" valign="middle" align="left">
                                                                              <a href="<?php print $base_url; ?>/?pk_campaign=website&amp;pk_kwd=picto" target="" style="font-family:Helvetica;font-size:12px;text-decoration:none;color:rgb(101, 101, 101);">Website</a>
                                                                          </td>

                                                                  </tr>
                                                              </tbody></table>
                                                          </td>
                                                      </tr>
                                                  </tbody></table>
                                              </td>
                                          </tr>
                                      </tbody></table>

	                                  <!--[if mso]>
	                                  </td>
	                                  <![endif]-->

	                                  <!--[if mso]>
	                                  <td align="center" valign="top">
	                                  <![endif]-->

                                      <table style="display:inline;" align="left" border="0" cellpadding="0" cellspacing="0">
                                          <tbody><tr>
                                              <td style="padding-right:0;padding-bottom:9px;" valign="top">
                                                  <table width="100%" border="0" cellpadding="0" cellspacing="0">
                                                      <tbody><tr>
                                                          <td style="padding-top:5px;padding-right:10px;padding-bottom:5px;padding-left:9px;" valign="middle" align="left">
                                                              <table width="" align="left" border="0" cellpadding="0" cellspacing="0">
                                                                  <tbody><tr>

                                                                          <td valign="middle" width="24" align="center">
                                                                              <a href="https://www.linkedin.com/company/emindhub" target="_blank"><img alt="LinkedIn" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/picto/picto_linkedin_small.png" style="display:block;" height="24" width="24"></a>
                                                                          </td>


                                                                          <td style="padding-left:5px;" valign="middle" align="left">
                                                                              <a href="https://www.linkedin.com/company/emindhub" target="" style="font-family:Helvetica;font-size:12px;text-decoration:none;color:rgb(101, 101, 101);">LinkedIn</a>
                                                                          </td>

                                                                  </tr>
                                                              </tbody></table>
                                                          </td>
                                                      </tr>
                                                  </tbody></table>
                                              </td>
                                          </tr>
                                        </tbody></table>

                                      <!--[if mso]>
                                      </td>
                                      <![endif]-->

                                    <!--[if mso]>
                                    </tr>
                                    </table>
                                    <![endif]-->
																	</td>
																</tr>
															</tbody>
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
							<tr>
								<td align="center" valign="top">
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr>
											<td align="center" valign="top">
												<table border="0" cellpadding="0" cellspacing="0" width="600" class="flexibleContainer">
													<tr>
														<td align="center" valign="top" width="600" class="flexibleContainerCell">
															<table border="0" cellpadding="30" cellspacing="0" width="100%">
																<tr>
																	<td valign="top" bgcolor="#F2F2F2">

																		<div style="font-family:Helvetica,Arial,sans-serif;font-size:13px;color:#656565;text-align:center;line-height:120%;">
																			<div>Copyright &#169; <?php echo date("Y"); ?> <?php print $site_name; ?>, <?php print('All rights reserved'); ?>.</div>
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
