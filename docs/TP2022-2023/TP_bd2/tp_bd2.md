TP23 : Bases de données -- suite
==

On repart de la situation du [tp22](../TP_bd1/tp_bd1.md).


### Exercice 1 : modélisation
Le problème est mal modélisé dans le tp précédent car par exemple on ne peut
pas s'assurer que les attributs `cheflieu` des tables `regions` et
`departements` prennent effecctivement leurs valeurs dans les clefs
primaires de la table `communes`.

Dessiner un diagramme entités / associations modélisant la situation,
avec des cardinalités, et proposer une autre table.


### Exercice 2 : requêtes
On repart de la base du tp précédent. Rappel: 
* pour vous connecter à la
base sur laquelle nous travaillons, vous devez utiliser la ligne de
commande `psql communes2 -U utilisateur`;
* pour ceux qui sont sur leurs ordis, vous pouvez, après avoir
  installé `postgres`, mettre en place la base à l'aide du fichier
  [communes.sql](../TP_bd1/communes.sql), avec la commande `psql
  communes -f /chemin/vers/communes.sql`. Je vous conseille ensuite de
  l'utiliser en tant qu'utilisateur `postgres`, ça vous évitera
  d'avoir à mettre en place les droits.

14. Donnez les noms des communes qui sont utilisés par au moins deux
  communes, ainsi que le nombre de communes utilisant chacun de ces
  noms. La table sera triée par ordre décroissant suivant le nombre de
  communes, puis par ordre croissant des noms des communes.
  [1456 lignes]
  
23. Donner la table des régions, de leur population, du nombre de
  naissances et du nombre de décès. On souhaite avoir les mêmes
  colonnes que la table `regions`, avec trois colonnes en plus :
  une pour la population, une pour les naissances et une pour les
  décès.
  [pour le Centre-Val de Loire: population = 2577867, naissances =
  26092, décès = 26861]
  
24. Écrire une requête renvoyant le nom de la région contenant le
  département le plus peuplé ainsi que le nom de ce département.
  
26. Donnez la table des régions en y ajoutant le pourcentage entier
  de la population de la région habitant dans le chef-lieu de région.
[17% à la Réunion]
  
30. Donner le nombre de lycées par département. On donnera le nom et
  le nombre de lycées de chaque département, ordonnés par nombre de
  lycées décroissant puis par nom de département croissant pour
  l'ordre lexicographique.
  [Finistère : 82]
  
32. Quels sont les départements dans lesquels toutes les communes
  sont dotées d'au moins une pharmacie ?
  [4 lignes]
  
33. Quel est le nom de la région ayant le plus de poissonneries
  par habitant de plus de 65 ans ?
  [Le nom de la région contient un `y`.]
  
34. Quelles sont les régions dont tous les départements ont au moins
  un cinquième de leurs communes qui ont au moins une crèche pour 30
  naissances ?
  [4 lignes]
  
35. Donner la table des régions avec en plus, pour chaque région, le
  nom du département contenant le plus de boulangeries, et la
  proportion, en pourcentage entier, de boulangeries de la région qui
  sont dans ce département.
[Dans le Grand-Est, il y a 20% de boulangeries en Moselle.]

