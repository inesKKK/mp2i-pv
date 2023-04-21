TP24 : Algorithme de Boyer-Moore - version difficile
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

Dans ce TP, on va se contenter de motifs qui sont des
chaînes de caractères et d'un texte.

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
struct liste_occ *boyer_moore(
    FILE *fichier,        //fichier à disséquer
    char *texte,          //tampon de texte courant
    const char *motif,    //motif à chercher
    int debut_texte,      //position de début dans le tampon
    int courante_fichier, //position courante du texte
    int *droite);         //occurences les plus à droite
```

qui renvoie la liste des indices de début d'occurences du motif dans le
texte, en utilisant l'algorithme de Boyer-Moore.

L'idée de base est la suivante: on a déjà lu un peu de texte dans le
fichier, il se trouve dans `texte`, à partir de l'indice
`debut_texte`. Si on n'a plus assez de texte, il faut en récupérer
dans le `fichier`.

(`fscanf` renvoie une constante macro-définie `EOF` si on est au bout du fichier)

### Exercice 3 : Affichage _user\_friendly_

Écrire une fonction

```C
void affichage(FILE *fichier, const char *motif)
```

qui affiche le texte en soulignant les occurences du motif.

Exemple, si cette fonction est exécutée sur le texte:

```bash
$ cat texte
ceci est une tentative en tente cartonnee
et meme une autre tentative sur
une autre ligne
```
on doit voir l'affichage suivant pour le motif `ten`:

```bash
$  ./boyer_moore ten texte
ceci est une tentative en tente cartonnee
             ^^^          ^^^
et meme une autre tentative sur
                  ^^^
une autre ligne

```

(On suppose que l'affichage de votre terminal se fait dans une police
de largeur fixe.)

si cette fonction est exécutée sur le fichier:

```bash
$ cat texte
aaabaaaaaabaabaaabbbaaaaaabba
aabbaaaabb
```

on doit voir l'affichage:

```bash
$ ./boyer_moore aaa texte
aaabaaaaaabaabaaabbbaaaaaabba
^^^ ^^^^^^    ^^^   ^^^^^^
aabbaaaabb
    ^^^^
```

### Exercice 4 : Arguments du `main`
Faites en sorte qu'on puisse utiliser votre programme en spécifiant le
motif et le nom du fichier en ligne de commande.
