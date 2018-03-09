# eMindHub

(eMindHub)[https://www.emindhub.com] is the ancestor of (Talao)[https://talao.io]. It's built historically on Drupal 7.

## Token ancestor

You can see that we have a "token" ancestor, in https://github.com/TalaoDAO/marketplace/tree/public/www/sites/all/modules/custom/emh_points. In this custom module of ours, we historically implemented "points", or "credits" (the name has changed some times).

The token ancestor allows, for instance, someone to purchase the full profile of an expert, for a given mount of tokens. Or to add privacy to a request posted to eMindHub. And to reward a user who has invited a new user. "Points" or tokens features are implemented in some of our custom modules in https://github.com/TalaoDAO/marketplace/blob/public/www/sites/all/modules/custom.

For instance:

+ Profile purchase: https://github.com/TalaoDAO/marketplace/blob/public/www/sites/all/modules/custom/emh_user/modules/emh_user_profile_purchase/emh_user_profile_purchase.module

+ Request options: https://github.com/TalaoDAO/marketplace/blob/public/www/sites/all/modules/custom/emh_request/emh_request.module

+ Virality (rewards a user who has invited a new user) : https://github.com/TalaoDAO/marketplace/blob/c01f0d66bf397b88ed92b93ddd64a8532690fc92/www/sites/all/modules/custom/emh_virality/emh_virality.module#L182

## Suite of Ethereum modules

In https://github.com/TalaoDAO/marketplace/tree/public/www/sites/all/modules/custom/ethereum/modules you can see our family of Ethereum custom modules. Basically, we started by backporting to Drupal 7 the Drupal 8 modules here : https://www.drupal.org/project/ethereum

Then we added some more features.

Modules:

+ ethereum_web3: to manage Web3.js library
+ ethereum_address_field: a Drupal 7 Ethereum address field, for users or in general, in Drupal entities
+ ethereum_smartcontract: manage Smart contract as Drupal entities.
+ ethereum_registry: implements the Drupal Register smart contract ()
