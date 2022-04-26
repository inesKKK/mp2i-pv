DM4 : Compression et décompression, algorithme de Huffman
==


Rappel: vous comptez le nombre de lettres dans vos noms et prénoms et

* si ce nombre est pair, vous faites la compression en `C` et la
  décompression en `ocaml`;
* si ce nombre est impair, vous faites la compression en `ocaml` et la
  décompression en `C`.
  
  
Nous avons vu en cours comment trouver l'encodage de chaque
caractère en construisant un code préfixe (avec un algorithme glouton,
même si on ne l'avait pas qualifié sur le moment). Il s'agit
maintenant de comprendre comment on sérialise un tel arbre et le texte
compressé.

## De l'arbre d'encodage à la représentation sous forme de suite de 0
et de 1, aller et retour

Dans cette première partie, vous devez être capables de transformer
l'arbre obtenu et le texte en une suite de caractères `'0'` et `'1'`.

Il y a plusieurs difficultés à gérer:
### Sérialisation d'un arbre binaire complet
On part d'un arbre binaire obtenu pour encoder des lettres: chaque
  nœud est soit un nœud interne et référence deux fils, soit une
  feuille et contient le caractère qui est encodé par le chemin
  d'accès au nœud (fils gauche=0, fils droit=1). On doit donc sérialiser
  cet arbre en distingant les nœuds internes et les feuilles. Pour
  cela, vous ferez un parcours préfixe, en signalant un nœud interne
  par un bit à~0 et une feuille par un bit à~1, un code ascii étant
  codé par sa valeur sur 8 bits.
  
Par exemple, l'arbre
```
     
    / \
   a
      / \
     d   e
```
sera sérialisé par `"01011000010101100100101100101"` en raison du
parcours:

  * nœud interne : 0;
  * feuille : 1  --  encodage de `'a'` : 97, soit 01100001 en binaire;
  * nœud interne : 0;
  * feuille : 1  --  encodage de `'d'` : 100, soit 01100100 en binaire;
  * feuille : 1  --  encodage de `'e'` : 101, soit 01100101 en binaire.

### Compression-décompression du texte
À la suite de la sérialisation de l'arbre d'encodage, il faut bien
entendu enregistrer le texte compressé grâce à ce code.
Or dans un fichier on écrit des octets, or les manipulations
précédentes n'aboutiront pas forcément à un nombre de bits
divisibles par 8, il faudra donc éventuellement compléter, par
exemple par des 0. Pour être capable de s'arrêter au bon moment,
vous ajouterez un caractère spécial qui sera encodé par votre
algorithme et qui signifiera "fin de fichier". Ainsi dès que vous le
rencontrerez à la lecture, vous saurez que c'est la fin du fichier.

## De la suite de 0 et de 1 au fichier
Je fournis le code qui permet de passer d'une chaîne de caractères à
un fichier et vice-versa. Regarder bien la documentation _avant_ de
vous lancer dans la programmation.

En `C` : [compio.h](C/compio.h) / [compio.c] (C/compio.c)
