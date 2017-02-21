# Petits principes de contribution

## Gestion .git
### Nouveau développement
Une branche par story/issue (on découpe le plus petit possible), basée sur `dev1`, nommée sur le modèle  `name-of-the-feature`

### Fix
Si fix, on nomme la branche `fix-name-of-the-feature`

### Hotfix
Si hotfix (donc développement démarré depuis la branche `master`), on nommera la branche `hotfix-name-of-the-feature`.

## Gestion des données
Pour faciliter l'industrialisation et le déploiement sur l'ensemble des instances du site (développeurs, preprod, etc.), toutes les données en base (variables, opérations sur module, changement de paramètres, feature revert, views revert, rules revert, etc.) doivent passer dans les `hook_update_n` des modules :
 - `emh_configuration` pour les opérations générales,
 - sinon dans les modules custom en fonction de la fonctionnalité.

De manière générale, on évite désormais de stocker tout et n'importe quoi dans les features (par exemple les permissions --> modules custom), mais les champs des contenus/profils sont encore dedans, on peut rester sur ce modèle pour le moment.

## Workflow

### Git

#### Faire un `rebase` depuis `dev1`
Il est important de ne pas avoir un écart trop important entre la branche `dev1` et sa branche de travail. Un `rebase` est donc profitable.

1. Mettre à jour `dev1` : `git checkout dev1 && git pull origin dev1`
2. Retour sur ta branche : `git checkout ma_branche`
3. Faire un `git pull --rebase origin dev1`
4. Régler les conflits si il y en a
5. Faire un `git add` sur les fichiers que tu as corrigé
6. Faire un `git rebase --continue`
7. Si il y a des conflits, tu reprends à l'étape 3
8. Faire un `git push origin ma_branche --force`

Attention, en cas de conflit, faire uniquement un `git add`, pas de `git commit` !

### Livraison
Toute livraison de fonctionnalité doit passer par une Merge Request (MR) sur Gitlab.
- Attribution de l'**issue** à l'utilisateur **Livreur**,
- Déplacer l'issue dans la **board** dans la colonne **À déployer en PREPROD**
- Création d'une **MR** assignée au **Livreur** :
 - On précise l'**ID** de l'issue livrée dans le titre
 - On précise la procédure de déploiement si nécessaire (normalement un `drush updb -y` doit suffire)
- Pour des raisons *évidentes* de qualité et d'harmonisation du code, la MR doit être relue et validée par les membres de l'équipe avant d'être mergée.
- On supprime la branche après le fusion : une option est disponible dans l'interface de création des MR) (/!\ pas de fusion en local, on historise tout avec les MR).
