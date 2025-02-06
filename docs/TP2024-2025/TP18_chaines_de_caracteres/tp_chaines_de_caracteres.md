TP18 : Chaînes de caractères
==


Tout le TP est à faire en `C` et en `ocaml`, en compilant en ligne de
commande. Je fournis des fonctions de test pour les deux langages,
elles peuvent aussi vous aider à comprendre ce qui est
attendu. Écrivez votre code dans d'autres fichiers.

[tests.c](tests.c) / [tests.ml](tests.ml)

Pour que les tests fonctionnent, vous devez impérativement :

* en `C` : créer un fichier d'en-tête `tp18.h` pour déclarer vos
  fonctions;
* en `OCaml` : écrire votre code dans un fichier nommé `tp18.ml`


#### Compilation sur plusieurs fichiers en `ocaml`
On utilise `ocamlopt` en lui donnant en argument les noms de tous les
fichiers concernés (comme pour `gcc`). **Attention**: on doit
donner à `ocamlopt` les fichiers dans leur ordre de dépendance, ici
plutôt : `ocamlopt tp18.ml tests.ml`.

En l'absence d'erreur, La compilation produit un exécutable `a.out`.

Faites chaque partie dans les deux langages _avant_ de passer
à la partie suivante.

Dans tout le TP on fait l'hypothèse qu'on se limite à des caractères ascii.

## Exploration

**Exercice 1.** Sans utiliser `strlen` en `C` ou `String.length` en
`ocaml`, écrire une fonction `longueur` qui renvoie la longueur d'une
chaîne fournie en argument (pour `ocaml`: essayez d'accéder à un
caractère au-delà du dernier pour comprendre comment faire).

**Exercice 2.** Sans utiliser de fonction déjà écrite pour, écrire une
fonction `nombre_occurences` qui prend en argument un caractère et
une chaîne de caractères et renvoie le nombre d'occurences du
caractère dans la chaîne.

**Exercice 3.** Sans utiliser de fonction déjà écrite pour, écrire une
fonction `derniere_occurence` qui prend en argument un caractère et
une chaîne de caractères et renvoie l'indice de la dernière occurence
du caractère dans la chaîne:
* en `C`, la fonction doit renvoyer -1 si le caractère n'apparaît pas,
* en `ocaml` la fonction doit être de type `char -> string -> int option`.


## Extraction

**Exercice 4.** Écrire une fonction `split` qui prend en argument un
caractère et une chaîne de caractères et renvoie un tableau de chaînes
correspondant au découpage de la chaîne d'origine par le caractère
donné. La chaîne transmise ne doit pas être modifiée.


## Affichage
(pas de test pour celles-ci, il faut les exécuter et
regarder) 

**Exercice 5.** Écrire une fonction `affichage` qui prend en argument un entier
strictement positif supposé représenter la largeur d'une fenêtre et
une chaîne de caractères, et affiche la chaîne en respectant la
largeur, mais sans couper au milieu d'un mot (on peut supposer que les
seuls caractères "blancs" sont les espaces pour simplifier).


**Exercice 6.** Je vous fournis un tableau de grandes lettres. Écrire
une fonction `ascii_art` qui prend en argument une chaîne de
cacractères et l'affiche en grand, mot par mot (c'est-à-dire avec un
retour à la ligne après chaque mot).

[grandes_lettres.h](grandes_lettres.h) / [grandes_lettres.c](grandes_lettres.c)

[grandes_lettres.ml](grandes_lettres.ml)


## Comparaisons

**Exercice 7.** Écrire une fonction `sous_chaine` qui prend en
argument deux chaînes de caractères et teste
(naïvement, on verra bientôt des algorithmes plus efficaces) si la
deuxième apparaît dans la première. Je vous laisse écrire les tests vous-mêmes.

**Exercice 8.** Écrire une fonction `anagramme` qui prend en
argument deux chaînes de caractères et teste si ce sont des anagrammes.

## Transformations

Rappel: en `OCaml`, les chaînes de caractères sont immuables. Pour
créer une chaîne, on peut utiliser une des deux fonctions suivantes du
module `String`:
* `make : int -> char -> string`
* `init : int -> (int -> char) -> string`

**Exercice 9.** Écrire une fonction `min2maj` qui prend en argument
une chaîne de caractères et renvoie une nouvelle chaîne obtenue en en
recopiant les lettres autres que les lettres minuscules non accentuées
et en remplaçant les lettres minuscules non accentuées par les lettres
majuscules corresponsantes.

**Exercice 10.** Écrire une fonction `shuffle` qui prend en argument
deux chaînes de caractères et produit un tableau avec tous les
mélanges possibles.

ex : si les deux chaînes sont "abc" et "de", le tableau devra
contenir : `"abcde", "abdce", "abdec", "adbce", "adbec", "adebc",
"dabce", "dabec", "daebc", "deabc"`.
