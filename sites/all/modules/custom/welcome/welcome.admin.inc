<?php

/**
* @file
* Admin page callbacks for the welcome module.
*/


/**
* Implements hook_form().
* Admin form to configurable welcome Message
*/
function welcome_admin_settings($form, &$form_state) {

    $tokenHelp = t('Available  variables are: [site:name], [site:url], [user:name], [user:mail], [site:login-url], [site:ul-brief], [user:edit-url], [user:one-time-login-url], [user:cancel-url].');
    $roles = user_roles(TRUE);

    /*$form['welcome_message'] = array(
        '#type'  => 'textarea',
        '#title' => t('Welcome message'),
        '#description' => t('Edit the welcome e-mail messages sent to new members accounts created by an administrator.').''.$tokenHelp,
        '#rows'  => 5,
        '#required' => TRUE,
        '#default_value' => variable_get('welcome_message', 'welcome'),
    );*/
    foreach ($roles as $rid => $role) {
        $form['#tree'] = TRUE;
        $form['welcome_message'][$rid]['msg'] = array(
            '#type' => 'textarea',
            '#title'  => t('Welcome message for @role ', array('@role' => $role)),
            '#description' => t('Edit the welcome e-mail messages sent to new members accounts created by an administrator.').''.$tokenHelp,
            '#rows'  => 5,
            '#default_value' => "",
        );
        $form['welcome_message'][$rid]['weight'] = array(
            '#type' => 'weight',
            '#delta' => 10,
            '#default_value' => 10,
        );
    }
    // Submit button
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save Changes'),
    );
    return $form;
}

/**
* Save messae, weiht, and settings for welcome module.
*/
function welcome_admin_settings_submit($form, &$form_state){
    foreach ($form_state['values']['welcome_message'] as $id => $data) {
        $table = 'welcome_message';
        $record = array('rid' => $id, 'message' => $data['msg'], 'weight' => $data['weight']);
        drupal_write_record($table, $record);
    }
}
