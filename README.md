# eMindHub

[eMindHub](https://www.emindhub.com) is the ancestor of [Talao](https://talao.io). eMindHub was built historically on Drupal 7.

## Token ancestor

You can see that we have a ["token ancestor"](https://github.com/TalaoDAO/marketplace/tree/public/www/sites/all/modules/custom/emh_points). In this custom module of ours, we historically implemented "points", or "credits" [the name has changed some times].

The token ancestor allows, for instance, someone to purchase the full profile of an expert, for a given mount of tokens. Or to add privacy to a request posted to eMindHub. And to reward a user who has invited a new user. "Points" or tokens features are implemented in some of our [custom modules](https://github.com/TalaoDAO/marketplace/blob/public/www/sites/all/modules/custom).

+ [Profile purchase](https://github.com/TalaoDAO/marketplace/blob/public/www/sites/all/modules/custom/emh_user/modules/emh_user_profile_purchase/emh_user_profile_purchase.module)

+ [Request options](https://github.com/TalaoDAO/marketplace/blob/public/www/sites/all/modules/custom/emh_request/emh_request.module)

+ [Virality](https://github.com/TalaoDAO/marketplace/blob/c01f0d66bf397b88ed92b93ddd64a8532690fc92/www/sites/all/modules/custom/emh_virality/emh_virality.module#L182) [rewards a user who has invited a new user]

## Suite of Ethereum modules

We developed a [family of Ethereum custom modules](https://github.com/TalaoDAO/marketplace/tree/public/www/sites/all/modules/custom/ethereum/modules). Basically, we started by backporting to Drupal 7 the [Drupal 8 Ethereum modules](https://www.drupal.org/project/ethereum). Then we added some more features.

+ ethereum_web3: to manage [Web3.js](https://github.com/ethereum/web3.js/) library

+ ethereum_address_field: a Drupal 7 field for Ethereum addresses. It can be used with any fieldable Drupal entity. We use it in our users profiles and in our Smart Contract Drupal entities.

+ ethereum_smartcontract: to manage Smart contract as Drupal entities.

+ ethereum_registry: implements the [Drupal Register Ethereum smart](https://github.com/digitaldonkey/register_drupal_ethereum) contract. Basically, this builds on the blockchain a registry of the users of a given Drupal site [eMindHub.com]

+ ethereum_user: adds an *Ethereum* tab on the user page. Other modules such as ethereum_registry can add content to this tab.

+ ...

*Note that those Ethereum modules are still Work In Progress and that the integration in our website is still experimental and not in production. Also there are some experimental modules that might not make it for a stable release and production use. Finally, we use Web3 version 1 beta. We will probably switch back to the older version included in Metamask, when pushing those Ethereum features in production.*
