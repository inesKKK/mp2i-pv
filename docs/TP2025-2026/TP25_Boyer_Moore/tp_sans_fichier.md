TP25 : Algorithme de Boyer-Moore - version facile
==

Il s'agit dans ce TP de programmer une version simpliste de la
commande `grep`.

Voici un extrait de la page de manuel de `grep`:

```bash
NAME
       grep, egrep, fgrep, rgrep - print lines matching a pattern

SYNOPSIS
       grep [OPTIONS] PATTERN [FILE...]
       grep [OPTIONS] -e PATTERN ... [FILE...]
       grep [OPTIONS] -f FILE ... [FILE...]

DESCRIPTION
       grep  searches  for  PATTERN  in  each  FILE.  A FILE of “-” stands for
       standard input.  If no FILE is given, recursive  searches  examine  the
       working  directory,  and nonrecursive searches read standard input.  By
       default, grep prints the matching lines.
```

Dans ce TP, on va se contenter de motifs et de textes qui sont des
chaînes de caractères.

### Exercice 1 : Occurence la plus à droite de chaque caractère

Écrire une fonction

```C
int *occ_droite(const char *motif);
```

qui prend une chaîne de caractères en argument et renvoie un tableau
de la taille de le nombre de valeurs du type `char`, qui contient la
dernière occurence de `(char) i` dans la case d'indice `i`, et -1 si
`(char) i` n'apparaît pas dans le motif.


### Exercice 2 : Algorithme de Boyer-Moore

On considère le type liste chaînée:

```C
struct liste_occ {
  int occ; //indice de début d'une occurence
  struct liste_occ *suite; //occurences suivantes
};
```

Écrire une fonction

```C
struct liste_occ *boyer_moore(const char *texte, const char *motif, int debut, int *droite);
```

qui prend en argument un texte et un motif sous forme de chaînes de
caractères, une indice `debut` à partir duquel il faut regarder le
texte et le tableau des dernières occurences droites dans le motif, et
renvoie la liste des indices de début d'occurences du motif dans le
texte, en utilisant l'algorithme de Boyer-Moore.

### Exercice 3 : Affichage _user\_friendly_

Écrire une fonction

```C
void affichage(const char *texte, const char *motif)
```

qui affiche le texte en soulignant les occurences du motif.

Exemple, si cette fonction est exécutée avec les arguments:

```C
char *texte = "ceci est une tentative en tente cartonnee\net meme une autre tentative sur\nune autre ligne\n";
char *motif="ten";
```
on doit voir l'affichage:

```bash
$  ./boyer_moore 
ceci est une tentative en tente cartonnee
             ^^^          ^^^
et meme une autre tentative sur
                  ^^^
une autre ligne

```

(On suppose que l'affichage de votre terminal se fait dans une police
de largeur fixe.)

si cette fonction est exécutée avec les arguments:

```C
texte = "aaabaaaaaabaabaaabbbaaaaaabba\naabbaaaabb";
motif= "aaa";
```

on doit voir l'affichage:

```bash
$ ./boyer_moore
aaabaaaaaabaabaaabbbaaaaaabba
^^^ ^^^^^^    ^^^   ^^^^^^
aabbaaaabb
    ^^^^
```
