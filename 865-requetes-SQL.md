# issue 865 : requêtes SQL anciennes transactions

## situation de départ
select * from emh_points_txn
where context is NULL

*reste 916 rows*

## Your Christmas gift from eMindHub
select * from emh_points_txn
where context is NULL
and uid=1
and source_type='user'
and source_id=1
and dest_type='user'
and operation='addition'
and description='Your Christmas gift from eMindHub'

*565 rows*

update emh_points_txn
set context='admin_manage_user_bulk'
where context is NULL
and uid=1
and source_type='user'
and source_id=1
and dest_type='user'
and operation='addition'
and description='Your Christmas gift from eMindHub'

*reste 351 rows*

## Expiration cron
select * from emh_points_txn
where context is NULL
and operation='expiration'

*61 rows*

update emh_points_txn
set context='cron'
where context is NULL
and operation='expiration'

*reste 290 rows*

## Ajout de crédit par admin (manuel ou très petits bulk)
select * from emh_points_txn
where context is NULL
and uid=1
and source_type='user'
and source_id=1
and dest_type='user'
and operation='addition'
order by description asc

*51 rows*

update emh_points_txn
set context='admin_manage_user'
where context is NULL
and uid=1
and source_type='user'
and source_id=1
and dest_type='user'
and operation='addition'

*reste 239 rows*

## Deprecated (transactions user 1 à user 1)
select * from emh_points_txn
where context is NULL
and uid=1
and source_type='user'
and source_id=1
and dest_type='user'
and (
  description='Move points from Super Admin to eMindHub.'
  or description='Move credits from Super Admin to eMindHub.'
)

*30 rows*

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
)

*reste 209 rows*

## Cas manifestes d'ajout de crédit par admin
select * from emh_points_txn
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
)

*21 rows*

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
)

*reste 188 rows*

## Achats profils
select * from emh_points_txn
where context is NULL
and uid=source_id
and source_type='user'
and dest_type='user'
and operation='transfert'
and dest_id > 1
and points in (50, 100)
order by uid

*66 rows*

update emh_points_txn
set context='profile_buy'
where context is NULL
and uid=source_id
and source_type='user'
and dest_type='user'
and operation='transfert'
and dest_id > 1
and points in (50, 100)

*reste 122 rows*

## Achats options
select * from emh_points_txn
where context is null
and uid=source_id
and source_type='user'
and dest_type='user'
and operation='transfert'
and dest_id=1
and (description like 'Move credits from%' or description like 'Move points from%')
and points in (100, 200, 300, 400, 500)

*71 rows*

Je mets 'request' en contexte mais on pourrait aussi :
- mettre request_option et mettre aussi request_option L848 dans emh_request.module
- affiner en cherchant les options du node pour avoir request_private, request_anonymous, request_private_anonymous

update emh_points_txn
set context='request'
where context is null
and uid=source_id
and source_type='user'
and dest_type='user'
and operation='transfert'
and dest_id=1
and (description like 'Move credits from%' or description like 'Move points from%')
and points in (100, 200, 300, 400, 500)

*reste 51 rows*

## Vieux système de requests
select * from emh_points_txn
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
and uid=source_id
order by points

*26 rows*

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
and uid=source_id

*reste 25 rows*

## Vieux système de requests suite
select * from emh_points_txn
where context is null
and operation='transfert'
and description like 'Move points from %'
and (
  description like '% question1 %'
  or description like '% webform %'
  or description like '% to challenge %'
)
and points in (100, 166, 168, 200, 250, 300, 400, 500, 600, 1000)

*25 rows*

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
and points in (100, 166, 168, 200, 250, 300, 400, 500, 600, 1000)

*reste 0 rows*
