/*

Those SQL queries add a context to the already existing credit transactions which don't have any.

See http://gitemindhub/yoann.babel/emindhub/issues/865.


All transactions without context :

select * from emh_points_txn
where context is NULL

*/

/* Your Christmas gift from eMindHub */
update emh_points_txn
set context='admin_manage_user_bulk'
where context is NULL
and uid=1
and source_type='user'
and source_id=1
and dest_type='user'
and operation='addition'
and description='Your Christmas gift from eMindHub';

/* Expiration cron */
update emh_points_txn
set context='cron'
where context is NULL
and operation='expiration';

/* Ajout de crédit par admin (manuel ou très petits bulk) */
update emh_points_txn
set context='admin_manage_user'
where context is NULL
and uid=1
and source_type='user'
and source_id=1
and dest_type='user'
and operation='addition';

/* Deprecated (transactions user 1 à user 1) */
update emh_points_txn
set context='deprecated'
where context is NULL
and uid=1
and source_type='user'
and source_id=1
and dest_type='user'
and (
  description='Move points from Super Admin to eMindHub.'
  or description='Move credits from Super Admin to eMindHub.'
);

/* Cas manifestes d'ajout de crédit par admin */
update emh_points_txn
set context='admin_manage_user'
where context is NULL
and (
  description='Free trial offer'
  or description='Trial offer'
  or description='Trial offer (correction)'
  or description='Offre d\'essai Air Corsica'
  or description='A regler avant le 18/11'
  or description='	C\'est Noël !'
  or description='C\'est Noël !'
  or description='Order AFR 0000104011'
  or description='Requests'
  or description='Théo -> François'
  or description='Transfert request'
);

/* Achats profils */
update emh_points_txn
set context='profile_buy'
where context is NULL
and uid=source_id
and source_type='user'
and dest_type='user'
and operation='transfert'
and dest_id > 1
and points in (50, 100);

/* Achats options */
update emh_points_txn
set context='request'
where context is null
and uid=source_id
and source_type='user'
and dest_type='user'
and operation='transfert'
and dest_id=1
and (description like 'Move credits from%' or description like 'Move points from%')
and points in (100, 200, 300, 400, 500);

/* Vieux système de requests */
update emh_points_txn
set context='deprecated'
where context is null
and source_type='user'
and dest_type='node'
and operation='transfert'
and description like 'Move points from %'
and (
  description like '% to question1 %'
  or description like '% to webform %'
  or description like '% to challenge %'
)
and uid=source_id;

/* Vieux système de requests suite */
update emh_points_txn
set context='deprecated'
where context is null
and operation='transfert'
and description like 'Move points from %'
and (
  description like '% question1 %'
  or description like '% webform %'
  or description like '% to challenge %'
)
and points in (100, 166, 168, 200, 250, 300, 400, 500, 600, 1000);

/* Autres ajouts manuels */
update emh_points_txn
set context='admin_manage_user'
where context is null
and txn_id in (289, 356, 1071);
