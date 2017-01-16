# Petits principes de contribution

## Développement

### Gestion .git
#### Nouveau développement
- Une branche par story/issue (on découpe le plus petit possible), basée sur `dev1`, nommée sur le modèle  `feature/nameOfTheStory`
- Si fix, `fix/nameOfTheFix`

#### Hotfix
Si hotfix (donc développement démarré depuis la branche `master`), on nommera la branche `hotfix/nameOfTheFix`.

### Gestion des données
Pour faciliter l'industrialisation et le déploiement sur l'ensemble des instances du site (développeurs, preprod, etc.), toutes les données en base (variables, opérations sur module, changement de paramètres, feature revert, views revert, rules revert, etc.) doivent passer dans les `hook_update_n` des modules :
 - `emh_configuration` pour les opérations générales,
 - sinon dans les modules custom en fonction de la feature.

De manière générale, on évite désormais de stocker tout et n'importe quoi dans les features (par exemple les permissions --> modules custom), mais les champs des contenus/profils sont encore dedans, on peut rester sur ce modèle pour le moment.

### Workflow
#### Livraison
Toute livraison de feature doit passer par une Merge Request (MR) sur Gitlab.
- Attribution de l'**issue** à l'utilisateur **Livreur**,
- Déplacer l'issue dans la **board** dans la colonne **À déployer en PREPROD**
- Création d'une **MR** assignée au **Livreur** :
 - On précise l'**ID** de l'issue livrée dans le titre
 - On précise la procédure de déploiement si nécessaire (normalement un `drush updb -y` doit suffire)
- Pour des raisons *évidentes* de qualité et d'harmonisation du code, la MR doit être relue et validée par les membres de l'équipe avant d'être mergée.
- On supprime la branche après le merge : une option est disponible dans l'interface de création des MR) (/!\ pas de merge en local, on historise tout avec les MR).
