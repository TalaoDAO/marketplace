# EMH request notification submodule

## 1) when a request is published,

When a new request is published, or a request draft is published, we call **\_emh\_request\_notification\_publish()**

## 2) we send immediatly an email to Webmasters and Administrators

>In summary :
>
>+ we build the moderators list
>+ we invoke the emh\_request\_notification\_moderate event
>+ which executes the rule rules\_emh\_request\_notification\_moderate\_mail
>+ which sends the moderation emails

### 2.1)

In \_emh\_request\_notification_publish() we build a list of Webmasters and Administrators.

Then we want to send them a moderation email. To send this email, we use a rule because this way, the email content can be edited with the Rules UI.

### 2.2)

We invoke the rule Event **\_emh\_request\_notification\_moderate** *(in emh\_request\_notification.rules.inc)*

    rules_invoke_event('_emh_request_notification_moderate', $node, $moderator);

### 2.3)

This event triggers the execution of the rule Action **\_emh\_request\_notification\_moderate\_mail** *(in emh\_request\_notification.rules\_defaults.inc)*

## 3) and we send the actual notification emails 30 minutes later

>In summary :
>
>+ we schedule the execution of a component 30 minutes later
>+ 30 minutes later the component executes an action which adds an item for each indidual notification of an user
>+ when cron is executed, the queue worker evokes an event for each item
>+ the event triggers the execution of an action which sends the actual individual email

### 3.1) Just after publishing a new request and sending the moderation emails :


In \_emh\_request\_notification_publish(), we schedule 30 minutes later the execution of a component :

    rules_action(
      'schedule',
      array('component' => '_emh_request_notification_schedule')
    )->executeByArgs(array(
      'date' => time() + variable_get('emh_request_notification_delay', 30) * 60,
      'identifier' => 'request_notification_'. $node->nid,
      'param_node' => $node,
    ));

### 3.2) 30 minutes later and after a Cron,

This component **\_emh\_request\_notification\_schedule** *(in emh\_request\_notification.rules\_defaults.inc)* is an Action set, which, when executed, executs the rule \_emh\_request\_notification\_build\_queue.

### 3.3) we build the notification queue, then

This rule **\_emh\_request\_notification\_build\_queue** *(in emh\_request\_notification.module + declared as an action in emh\_request\_notification.rules.inc)* gathers the list of users concerned by the request.

For each, it adds an item in the notification queue **\_emh\_request\_notification\_queue** *(in emh\_request\_notification.module)*

### 3.4) at each Cron run, for each remaining item,

For each remaining item (individual notification of an user) of this queue, if there is time, the item is processed, otherwise it's delayed for the next Cron. When the item is processed, the worker **\_emh\_request\_notification\_queue\_worker** *(in emh\_request\_notification.module)* evokes an event.

This event, **emh\_request\_notification\_notify** *(in emh\_request\_notification.rules.inc)*, fires the last action :

### 3.5) we finally send the notification email.

**\_emh\_request\_notification\_notify\_mail** *(in emh\_request\_notification.rules\_defaults.inc)*, which at lasts sends the individual notification email to an user.
