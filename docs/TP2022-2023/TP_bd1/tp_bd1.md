TP22 : Bases de données
==

Tous les fichiers nécessaires sont installés sur les machines de la
salle de TP. Ceux qui voudraient faire le TP sur leur propre machine
doivent installer un SGBD (de préférence
[postgreSQL](https://www.postgresql.org/) ) et créer une base avec les
données du fichier [communes.sql](communes.sql). **Si vous utilisez un
autre SGBD, les commandes seront sans doute différentes de celles
de postgresql.**

Dans ce TP, on se propose d'interagir avec une base de données sur le
thème des communes de France. On va chercher à répondre à des
questions comme :

* Dans quelle commune y a-t-il le plus de boulangeries par habitant ?
* Quelles communes ont plus de lettres que d'habitants ?
* Quel est le nom de commune le plus fréquent ?
* Quelles communes ont plus d'habitants que le chef-lieu de leur département ?

Pour chaque question, je vous donnerai une information qui ne devrait
pas vous aider à trouver la réponse, mais devrait vous aider à
vérifier l'exactitude de votre réponse.


Les données proviennent du site de l'INSEE :

* Les tables `communes`, `departements` et
  `regions` ont été créées à partir de données téléchargées à
  l'adresse
  [https://www.insee.fr/fr/information/2560452](https://www.insee.fr/fr/information/2560452).
* Les tables `demographie` et `equipements` ont été
  créées puis téléchargées à partir de l'adresse suivante :
  [https://statistiques-locales.insee.fr](https://statistiques-locales.insee.fr).


La base de données `communes` regroupe les informations
nécessaires. Vous pouvez lancer `postgres` sur cette base sur les
machines de la salle TP avec la commande

```
psql communes -U utilisateur
```

(attention: c'est bien `utilisateur` qu'il faut mettre, pour tout le
monde, j'ai créé un seul compte)

Avant de commencer à écrire les requêtes, je vous
conseille de bien vous familiariser avec les schémas des tables, que
vous pouvez obtenir sur `postgres` grâce à la commande `\d`
suivi du nom de la table. La liste des tables peut être obtenue grâce
à la commande `\dt`.


On garantit que les données sont cohérentes (les informations
  récupérées sur le site de l'INSEE ne concernent pas toutes la même
  année, mais elles ont été légèrement modifiées pour que les tables
  soient cohérentes entre elles). Dans toute la
suite, on fera comme si toutes les données portaient sur une seule et
  même année.

Dans toute la suite on demande d'écrire une requête en `SQL` qui
permet de répondre à la question posée. Toutes les requêtes doivent
s'exécuter en moins de 2 s. Lorsque rien n'est précisé, le contexte
détermine si la réponse peut ou non contenir des doublons. Si l'on
demande par exemple _quelles sont les communes qui ..._ ou
_pour chaque commune donner ..._, la réponse ne doit pas
contenir de doublons, on attend une ligne par commune. En revanche si
la question est _quels sont les noms des communes qui ..._,
sans précision supplémentaire, on attend a priori toujours une ligne
par commune. Comme plusieurs communes peuvent avoir le même nom, le
résultat de cette requête peut contenir des doublons.


Nota: 

* on fera un autre TP bases de données la semaine prochaine avec des
  agrégats,

* pour certaines requêtes, je mets une indication pour que vous
  puissiez tester votre réponse,

* cette base est volontairement mal conçue, mais il faut faire avec,
  on la retravaillera ensemble la semaine prochaine.

## Questions administratives

Dans cette section, nous utilisons uniquement les tables
`communes`, `departements` et `regions`.

1. Donner la ligne correspondant à la commune de nom _Dijon_.
2. Combien y a-t-il de communes en France ?
3. Combien de communes s’appellent _Saint-Loup_ ?
4. Combien de communes contiennent la suite de lettres _Saint_
  dans leur nom, sans que le nom ne commence par cette même suite de
  lettres ? On peut tester si `a` est un facteur de `b` avec `a
  LIKE '%b%'` où '%' désigne une chaîne quelconque.
5. Quels sont, sans doublons, les noms de communes, de départements
  ou de régions, dans l'ordre lexicographique croissant ? [32807 lignes]
6. Quels sont les noms des communes qui portent le même nom que
  leur département ? [4 lignes]
7. Quels sont, sans doublons, les noms des communes qui portent le
  nom d'un département qui n'est pas le leur ? [8 lignes]
8. Dans combien de régions différentes existe-t-il une commune
  s’appelant _Sainte-Marie_ ?
9. Quel est le taux (nombre flottant entre 0 et 1) de communes dont
  le nom est constitué d'au moins trois mots séparés par des tirets ?
  On pourra multiplier par 1.0 pour avoir une division flottante.
10. Quelles sont les communes (tous les attributs) qui ne sont pas
  des chefs-lieux (de département ou de région) ? [34869 lignes]
11. Quels sont les codes et noms des communes dont le chef-lieu
  départemental et le chef-lieu régional ne sont pas les mêmes ?
  [29773 lignes]
12. Donner la table des communes avec comme colonnes : le nom de la
  commune, le nom du département de cette commune, le nom du chef-lieu
  du département, le nom de la région de cette commune, le nom du
  chef-lieu de la région. [34970 lignes]
13. Donner, sans doublons, le nom des communes qui ne sont pas les
  seules à avoir ce nom au sein d'une même région, dans l'ordre
  lexicographique croissant. [623 lignes]


## Questions démographiques

Dans cette section, nous utilisons en plus la table `demographie`.

15. Combien y a-t-il d'habitants en France ?
16. Quelle est la proportion des moins de 25 ans en France, en
  pourcentage entier.
17. Donner, pour chaque commune, le code de la commune et le nombre
  d'habitants qu'il y avait dans cette commune l'année précédente, en
  supposant qu'il n'y a eu ni émigration, ni immigration.
18. Quels sont, dans l'ordre lexicographique croissant, les codes
  des communes avec strictement plus de naissances que la moyenne des
  naissances par commune ? [4725 lignes]
19. Quelles sont les communes sans aucun habitant ? La table aura
  les mêmes colonnes que la table `communes`. On pourra utiliser
  l'étoile préfixée par le nom ou l'alias de la table. [6 lignes]
20. Quelles sont les 19 communes les moins peuplées, parmi celles
  qui comportent au moins un habitant renseigné ? On donnera le nom de
  la commune, le nom de son département et sa population. [pas plus de
  9 habitants par commune]
21. Donnez les communes (tous les attributs) ayant autant
  d’habitants que de lettres (tirets inclus) dans leur nom, avec ce
  nombre d'habitants. Vous pouvez utiliser la fonction prédéfinie
  `LENGTH` sur les chaînes de caractères. [5 lignes]
22. Quels sont les codes et noms des départements dans lesquels
  toutes les communes ont vu au moins une naissance et un décès, si
  cette valeur est renseignée. On considère que le département de
  _Mayotte_ vérifie la propriété et doit donc être présent.
25. Donnez la table des communes ayant plus d’habitants que le
  chef-lieu de leur département. La table aura pour colonnes : le nom
  de la commune, sa population, le nom du département, le nom du
  chef-lieu et la population de son chef-lieu. [58 lignes]

## Questions générales

Enfin, dans cette section, nous utilisons également la table
`equipements`

27. Combien y a-t-il de boulangeries en France ?
28. Combien y a-t-il, en moyenne, de pharmacies par commune ?
29. Dans combien de communes y-a-t-il strictement plus de poissonneries que de crèches ?
31. Quel est le nom de la commune avec le plus faible nombre
  d'habitants (connu) par boulangerie ? On donnera le nom de la
  commune avec le nombre d'habitants par boulangerie (partie entière).

