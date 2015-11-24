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
<!--
==================== Respmail ====================
Respmail is a response HTML email designed to work
on all major devices and responsive for smartphones
that support media queries.

** NOTE **
This template comes with a lot of standard features
that has been thoroughly tested on major platforms
and devices, it is extremely flexible to use and
can be easily customized by removing any row that
you do not need.

it is gauranteed to work 95% without any major flaws,
any changes or adjustments should thoroughly be
tested and reviewed to match with the general
structure.

** Profile **
Licensed under MIT (https://github.com/charlesmudy/responsive-html-email-template/blob/master/LICENSE)
Designed by Shina Charles Memud
Respmail v1.2 (http://charlesmudy.com/respmail/)

** Quick modification **
We are using width of 500 for the whole content,
you can change it any size you want (e.g. 600).
The fastest and safest way is to use find & replace
Sizes: [
		wrapper   : '500',
		columns   : '210',
		x-columns : [
						left : '90',
						right: '350'
				]
		}
	-->

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
		<!--
			Outlook Conditional CSS

			These two style blocks target Outlook 2007 & 2010 specifically, forcing
			columns into a single vertical stack as on mobile clients. This is
			primarily done to avoid the 'page break bug' and is optional.

			More information here:
			http://templates.mailchimp.com/development/css/outlook-conditional-css
		-->
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

		<!-- CENTER THE EMAIL // -->
		<!--
		1.  The center tag should normally put all the
			content in the middle of the email page.
			I added "table-layout: fixed;" style to force
			yahoomail which by default put the content left.

		2.  For hotmail and yahoomail, the contents of
			the email starts from this center, so we try to
			apply necessary styling e.g. background-color.
		-->
		<center style="background-color:#F2F2F2;">
			<table border="0" cellpadding="0" cellspacing="0" height="100%" width="100%" id="bodyTable" style="table-layout: fixed;max-width:100% !important;width: 100% !important;min-width: 100% !important;">
				<tr>
					<td align="center" valign="top" id="bodyCell">

						<!-- EMAIL HEADER // -->
						<!--
							The table "emailBody" is the email's container.
							Its width can be set to 100% for a color band
							that spans the width of the page.
						-->
						<table bgcolor="#F2F2F2" border="0" cellpadding="0" cellspacing="0" width="500" id="emailHeader">

							<!-- HEADER ROW // -->
							<tr>
								<td align="center" valign="top">
									<!-- CENTERING TABLE // -->
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr>
											<td align="center" valign="top">
												<!-- FLEXIBLE CONTAINER // -->
												<table border="0" cellpadding="10" cellspacing="0" width="500" class="flexibleContainer">
													<tr>
														<td valign="top" width="500" class="flexibleContainerCell">

															<!-- CONTENT TABLE // -->
															<table align="left" border="0" cellpadding="0" cellspacing="0" width="100%">
																<tr>
																	<!--
																		The "invisibleIntroduction" is the text used for short preview
																		of the email before the user opens it (50 characters max). Sometimes,
																		you do not want to show this message depending on your design but this
																		text is highly recommended.

																		You do not have to worry if it is hidden, the next <td> will automatically
																		center and apply to the width 100% and also shrink to 50% if the first <td>
																		is visible.
																	-->
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
												<!-- // FLEXIBLE CONTAINER -->
											</td>
										</tr>
									</table>
									<!-- // CENTERING TABLE -->
								</td>
							</tr>
							<!-- // END -->

						</table>
						<!-- // END -->

						<!-- EMAIL BODY // -->
						<!--
							The table "emailBody" is the email's container.
							Its width can be set to 100% for a color band
							that spans the width of the page.
						-->
						<table bgcolor="#FFFFFF"  border="0" cellpadding="0" cellspacing="0" width="500" id="emailBody">

							<!-- MODULE ROW // -->
							<!--
								To move or duplicate any of the design patterns
								in this email, simply move or copy the entire
								MODULE ROW section for each content block.
							-->
							<tr>
								<td align="center" valign="top">
									<!-- CENTERING TABLE // -->
									<!--
										The centering table keeps the content
										tables centered in the emailBody table,
										in case its width is set to 100%.
									-->
									<table border="0" cellpadding="0" cellspacing="0" width="100%" style="color:#FFFFFF;" bgcolor="#009FE3">
										<tr>
											<td align="center" valign="top">
												<!-- FLEXIBLE CONTAINER // -->
												<!--
													The flexible container has a set width
													that gets overridden by the media query.
													Most content tables within can then be
													given 100% widths.
												-->
												<table border="0" cellpadding="0" cellspacing="0" width="500" class="flexibleContainer">
													<tr>
														<td align="center" valign="top" width="500" class="flexibleContainerCell">

															<!-- CONTENT TABLE // -->
															<!--
															The content table is the first element
																that's entirely separate from the structural
																framework of the email.
															-->
															<table border="0" cellpadding="30" cellspacing="0" width="100%">
																<tr>
																	<td align="center" valign="top" class="textContent">
																		<h1 style="color:#FFFFFF;line-height:100%;font-family:Helvetica,Arial,sans-serif;font-size:35px;font-weight:normal;margin-bottom:5px;text-align:center;"><?php print $subject; ?></h1>
																	</td>
																</tr>
															</table>
															<!-- // CONTENT TABLE -->

														</td>
													</tr>
												</table>
												<!-- // FLEXIBLE CONTAINER -->
											</td>
										</tr>
									</table>
									<!-- // CENTERING TABLE -->
								</td>
							</tr>
							<!-- // MODULE ROW -->


							<!-- MODULE ROW // -->
							<tr>
								<td align="center" valign="top">
									<!-- CENTERING TABLE // -->
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr style="padding-top:0;">
											<td align="center" valign="top">
												<!-- FLEXIBLE CONTAINER // -->
												<table border="0" cellpadding="30" cellspacing="0" width="500" class="flexibleContainer">
													<tr>
														<td style="padding-top:0;" align="center" valign="top" width="500" class="flexibleContainerCell">

															<!-- CONTENT TABLE // -->
															<table align="left" border="0" cellpadding="0" cellspacing="0" width="100%">
																<tr>
																	<td align="left" valign="top" class="flexibleContainerBox">
																		<table border="0" cellpadding="0" cellspacing="0" width="210" style="max-width: 100%;">
																			<tr>
																				<td align="left" class="textContent">
																					<div style="text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:15px;margin-bottom:0;color:#333;line-height:135%;"><?php print $body ?></div>
																				</td>
																			</tr>
																		</table>
																	</td>
																</tr>
															</table>
															<!-- // CONTENT TABLE -->

														</td>
													</tr>
												</table>
												<!-- // FLEXIBLE CONTAINER -->
											</td>
										</tr>
									</table>
									<!-- // CENTERING TABLE -->
								</td>
							</tr>
							<!-- // MODULE ROW -->

						</table>
						<!-- // END -->

						<!-- EMAIL FOOTER // -->
						<!--
							The table "emailBody" is the email's container.
							Its width can be set to 100% for a color band
							that spans the width of the page.
						-->
						<table bgcolor="#F2F2F2" border="0" cellpadding="0" cellspacing="0" width="500" id="emailFooter">

							<!-- FOOTER ROW // -->
							<!--
								To move or duplicate any of the design patterns
								in this email, simply move or copy the entire
								MODULE ROW section for each content block.
							-->
							<tr>
								<td align="center" valign="top">
									<!-- CENTERING TABLE // -->
									<table border="0" cellpadding="0" cellspacing="0" width="100%">
										<tr>
											<td align="center" valign="top">
												<!-- FLEXIBLE CONTAINER // -->
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
												<!-- // FLEXIBLE CONTAINER -->
											</td>
										</tr>
									</table>
									<!-- // CENTERING TABLE -->
								</td>
							</tr>

						</table>
						<!-- // END -->

					</td>
				</tr>
			</table>
		</center>
	</body>
</html>
