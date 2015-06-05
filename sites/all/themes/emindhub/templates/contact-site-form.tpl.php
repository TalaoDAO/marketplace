<?php
$fieldFirstName = $form['firstname'];
$fieldLastName = $form['lastname'];
$fieldCompany = $form['entreprise'];
$fieldPhone = $form['phone'];
$fieldMail = $form['mail'];
$fieldSubject = $form['subject'];
$fieldMessage = $form['message'];
$fieldCategory = $form['cid'];      //contact us or feedback
$fieldCopy = $form['copy'];         //Send yourself a copy.
$fieldActions = $form['actions'];
$fieldCivility = $form['civility'];
?>
    <div class="row border-light">
        <div class="col-md-12">
            <div class="row paddingU">
                <div class="col-md-1 col-xs-1">
                    <img src="<?php print getImgSrc("bulle.png"); ?>" />
                </div>
                <div class="col-md-10 col-xs-10 bold text-16">
                    <?php print c_szHaveQuestion; ?>
                </div>
            </div>
            <div class="row paddingU">
                <div class="col-md-1 col-xs-1">
                    <img src="<?php print getImgSrc("bulle.png"); ?>" />
                </div>
                <div class="col-md-10 col-xs-10 bold text-16">
                    <?php print c_szLearnMore; ?>
                </div>
            </div>
            <div class="text-wrapper text-16">
                <?php print c_szLeaveMsg; ?>
            </div>

            <form action="<?php print $form['#action']; ?>" method="<?php print $form['#method']; ?>">
                <div class="form-wrapper text-16">
                    <?php
                    $fieldCivility['#attributes']['class'][] = "form-control-custom";
                    $fieldCivility['#attributes']['class'][] = "select-form";
                    $fieldCivility['#title_display'] = "invisible";
                    $fieldCivility['#attributes']['placeholder'] = $fieldCivility['#title'];
                    print render($fieldCivility);
                    if ($fieldCivility['#required']): ?> <span class="required">*</span><?php endif; ?>
                </div>
                <div class="form-wrapper text-16">
                    <?php
                    $fieldLastName['#title_display'] = "invisible";
                    $fieldLastName['#attributes']['placeholder'] = $fieldLastName['#title'];
                    print render($fieldLastName);
                    if ($fieldLastName['#required']): ?> <span class="required">*</span><?php endif; ?>
                </div>
                <div class="form-wrapper text-16">
                    <?php
                    $fieldFirstName['#title_display'] = "invisible";
                    $fieldFirstName['#attributes']['placeholder'] = $fieldFirstName['#title'];
                    print render($fieldFirstName);
                    if ($fieldFirstName['#required']): ?> <span class="required">*</span><?php endif; ?>
                </div>
                <div class="form-wrapper text-16">
                    <?php
                    $fieldCompany['#title_display'] = "invisible";
                    $fieldCompany['#attributes']['placeholder'] = $fieldCompany['#title'];
                    print render($fieldCompany);
                    if ($fieldCompany['#required']): ?> <span class="required">*</span><?php endif; ?>
                </div>
                <div class="form-wrapper text-16">
                    <?php
                    $fieldPhone['#title_display'] = "invisible";
                    $fieldPhone['#attributes']['placeholder'] = $fieldPhone['#title'];
                    print render($fieldPhone);
                    if ($fieldPhone['#required']): ?> <span class="required">*</span><?php endif; ?>
                </div>
                <div class="form-wrapper text-16">
                    <?php
                    $fieldMail['#title_display'] = "invisible";
                    $fieldMail['#attributes']['placeholder'] = $fieldMail['#title'];
                    print render($fieldMail);
                    if ($fieldMail['#required']): ?> <span class="required">*</span><?php endif; ?>
                </div>
                <div class="form-wrapper text-16">
                    <?php
                    $fieldMessage['#title_display'] = "invisible";
                    $fieldMessage['#attributes']['placeholder'] = $fieldMessage['#title'];
                    print render($fieldMessage);
                    if ($fieldMessage['#required']): ?> <span class="required">*</span><?php endif; ?>
                </div>
            </form>
            <div class="row">
                <div class="col-md-6">
                    <?php print render($fieldActions);
                    print render($form['location']);
                    print render($form['form_build_id']);
                    print render($form['form_id']); ?>
                </div>
                <div class="col-md-6">
                    <span class="required">*</span><?php print c_szRequiredField; ?>
                </div>
            </div>
        </div>
    </div>

<?php
unset($fieldFirstName);
unset($fieldLastName);
unset($fieldCompany);
unset($fieldPhone);
unset($fieldMail);
unset($fieldSubject);
unset($fieldMessage);
unset($fieldCategory);
unset($fieldCopy);
unset($fieldActions);
unset($fieldCivility);
?>
