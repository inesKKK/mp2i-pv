TP26 : Bases de données -- suite
==

On repart de la situation du [tp25](../TP25_BD1/tp_bd1.md). Rappel:
il faut suivre les indications du TP25 pour se connecter à la base de
données.

### Exercice 1 : modélisation
Le problème est mal modélisé dans le tp précédent car par exemple on ne peut
pas s'assurer que les attributs `cheflieu` des tables `regions` et
`departements` prennent effecctivement leurs valeurs dans les clefs
primaires de la table `communes`.

Dessiner un diagramme entités / associations modélisant la situation,
avec des cardinalités, et proposer une autre table.


### Exercice 2 : requêtes
On repart de la base du tp précédent.

14. Donner les noms des communes qui sont utilisés par au moins deux
  communes, ainsi que le nombre de communes utilisant chacun de ces
  noms. La table sera triée par ordre décroissant suivant le nombre de
  communes, puis par ordre croissant des noms des communes.
  [1456 lignes]

18. Quels sont, dans l'ordre lexicographique croissant, les codes
  des communes avec strictement plus de naissances que la moyenne des
  naissances par commune ? [4725 lignes]

23. Donner la table des régions, de leur population, du nombre de
  naissances et du nombre de décès. On souhaite avoir les mêmes
  colonnes que la table `regions`, avec trois colonnes en plus :
  une pour la population, une pour les naissances et une pour les
  décès.
  [pour le Centre-Val de Loire: population = 2577867, naissances =
  26092, décès = 26861]
  
24. Écrire une requête renvoyant le nom de la région contenant le
  département le plus peuplé ainsi que le nom de ce département.
  
25. Donnez la table des communes ayant plus d’habitants que le
  chef-lieu de leur département. La table aura pour colonnes : le nom
  de la commune, sa population, le nom du département, le nom du
  chef-lieu et la population de son chef-lieu. [58 lignes]

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

