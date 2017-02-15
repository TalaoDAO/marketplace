# EMH request notification submodule

## 1) when a request is published

When a new request is published, or a request draft is published, it calls **\_emh\_request\_notification\_publish()** 

*(see emh_request.module : hook_node_insert() and hook_node_update()*

## 2) send immediatly an email to Webmasters and Administrators

In \_emh\_request\_notification_publish() we build a list of Webmasters and Administrators.

Then we want to send them a moderation email. To send this email, we use a rule because this way, the email content can be edited with the Rules UI. The rule is **rules\_emh\_request\_notification\_moderate\_mail** *(in emh_request_notification.rules_defaults.inc)*

But this rule needs to be executed. So we build the event **emh\_request\_notification\_moderate** *(in emh\_request\_notification.rules.inc)*

And in \_emh\_request\_notification_publish(), just after building the Webmasters and Administrators list, we invoke this event :

    rules_invoke_event('emh_request_notification_moderate', $node, $moderator);

In summary :

+ we build the moderators list
+ we invoke the emh\_request\_notification\_moderate event
+ which executes the rule rules\_emh\_request\_notification\_moderate\_mail
+ which sends the moderation emails