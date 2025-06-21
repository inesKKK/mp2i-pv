# Projet de fin d'année : programmer des jeux

## But
Il s'agit pour chaque jeu de faire deux programmes :
* un moteur qui gère les interactions avec l'utilisateur et les mises
  à jour du plateau dans un fichier (en boucle)
* un bot qui lit l'état du plateau dans le fichier et propose le
  prochain coup à faire (un seul coup, il faut relancer le bot à
  chaque mise à jour du plateau par le moteur)
  
## Jeux
Des exemples de jeux à programmer :
* [swap pins](https://www.cokojeux.com/swap-pins-jeu-de-puzzle/play/)
* [balloons and
  scissors](https://www.cokojeux.com/balloons-and-scissors-casse-tete-de-ballons-et-de-ciseaux/play/)
* [bubble
  sorting](https://www.cokojeux.com/bubble-sorting-trier-les-couleurs-dans-des-tubes-a-essai/play/)
  
## Jeu automatique
Un exemple de jeu avec un programme de communication que vous pouvez
utiliser : [exemple](src). Attention à bien vider le buffer en
écriture. Pour `OCaml`, il suffit d'utiliser `print_endline` qui
forcera le vidage.
