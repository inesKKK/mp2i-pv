Quelques mots sur `gdb`
==================

(`gdb` peut vous aider à trouver des erreurs, mais c'est complètement
hors programme; c'est uniquement pour ceux qui veulent, et après avoir
travaillé le reste bien sûr. Cet énoncé est un extrait d'un énoncé
écrit pour des étudiants bien plus avancés. Il est vraisemblable que
l'exercice 1 suffise à vos besoins; l'exercice 3 permet d'explorer la
pile d'appel. Je laisse les autres exercices pour les curieux.)

Le programme `gdb` est un debugueur en ligne de commande qui fonctionne avec plusieurs langages. Le but de ce tp est d'en découvrir les commandes de base, afin que vous l'utilisiez le reste du trimestre, et au-delà.


#### Exercice 1 : Variables
Pour pouvoir utiliser `gdb`, il faut compiler votre source avec l'option `-g` de `gcc`. On lance ensuite la commande suivante 

```shell
gdb ./a.out
```

(en supposant que l'exécutable se nomme `a.out`).

Quelques commandes de base de `gdb` (à terminer par un retour chariot; `gdb` supporte l'utilisation de la tabulation) :

| commande | abrév. | signification |
|:----------|:------:|:--------------|
| quit     | q      | quitter `gdb` |
| list     | l      | voir le source|
| break *point* | b | mise en place d'un point d'arrêt (suivi du numéro de ligne ou du nom de la fonction) |
| run | r | démarrer le programme (éventuellement suivi des arguments pour la commande)|
| next | n | exécuter la ligne suivante (sans entrer dans les appels de fonction)|
| step | s | exécuter la ligne suivante (en entrant dans les appels de fonction)|
| continue | c | exécuter jusqu'au prochain breakpoint |
| print *var* | p *var* | afficher la valeur de *var*|
| set var *var* = *val* | | modifier la valeur de *var*|
| print *\*tab@nb* | | afficher les nb cases du tableau |
| info locals | | voir les valeurs de toutes les variables|
| | | réexécuter la dernière commande |

1. Récupérer le programme [variables.c](variables.c), le compiler et lancer `gdb` avec l'exécutable ainsi obtenu.
2. Mettre un point d'arrêt sur le `main`, et exécuter le programme pas à pas sans entrer dans l'appel de fonction `int_tab`, en affichant les valeurs de `p`, `*p`, `t` et `*t` à chaque itération. Quand la variable `i` vaut 3, modifier sa valeur à `6` et continuer pas à pas jusqu'à la fin de l'exécution.
3. Relancer l'exécution et entrer dans l'appel de fonction `int_tab`.


#### Astuces pour rendre l'utilisation de `gdb` plus agréable :

* La commande `start` est équivalente à la suite de commande `break main` / `run`.
* Parfois l'affichage de `gdb` se décale à cause de l'affichage du programme qu'on est en train de tester; on peut tout remettre en place avec `Ctrl-l`.
* Par défaut, `gdb` montre sur la ligne précédent son prompt la prochaine ligne de code à exécuter. Ce n'est pas forcément très agréable comme affichage. On peut faire apparaître le code et le prompt de `gdb` avec `Ctrl-x a`. Le source apparaît alors dans un cadre et il y a des informations dans la marge de gauche (points d'arrêt, prochaine ligne à exécuter, etc.). La même combinaison de touches permet ensuite de faire disparaître l'affichage.


#### Exercice 2 : Points d'arrêt
On a vu qu'on peut mettre en place un point d'arrêt grâce à la commande `break`. Voici quelques commandes supplémentaires concernant les points d'arrêt :

| commande | abrév. | signification | 
|:---     |  :---:      | :----              | 
|  clear | | suppression d'un point d'arrêt (même argument que break)|
|  info breakpoints | | liste des points d'arrêt|
| del *n* | | suppression d'un point d'arrêt (suivi du numéro donné par info breakpoints)|
| break *point* if *var*==*val* | | point d'arrêt conditionnel|
|  continue | c | continuer l'exécution normalement|


1. Récupérer le programme [arrets.c](arrets.c), le compiler et lancer `gdb` avec l'exécutable ainsi obtenu.
2. Mettre un point d'arrêt sur la dernière ligne du `for` de la fonction `f`.
3. Exécuter le programme et regarder la valeur de la variable `i` à la fin de chaque itération.
4. Supprimer le point d'arrêt précédent. Ajouter un point d'arrêt sur la dernière ligne du `for` si le compteur vaut 4 et relancer le programme.


#### Exercice 3 : Pile d'appel
  
| commande | abrév. | signification | 
|:---     |  :---:      | :----              | 
|  backtrace | bt | voir la pile d'appel|
|  up | | remonter d'un niveau dans la pile d'appel|
|  up *n* | | remonter de *n* niveaux dans la pile d'appel|
|  down | do | redescendre d'un niveau dans la pile d'appel|
|  down *n* | do *n* | redescendre de *n* niveaux dans la pile d'appel|
|  frame *n* | f *n* | se placer au niveau *n*|

Attention : ces commandes permettent de naviguer dans la pile d'appel pour par exemple réexplorer les valeurs des variables, mais on ne revient pas en arrière : quand on reprend le déroulement du programme, on le reprend là où on en était.

On peut observer la pile d'appel du processus dans `gdb` grâce à la commande `backtrace`.

1. Récupérer le programme [backtrace.c](backtrace.c), le compiler avec l'option `-g` et l'exécuter pas à pas avec `gdb`.
2. Entrer dans l'exécution des fonctions `f` et `g`. Regarder la pile d'appel.
3. Regarder la valeur du caractère `c` dans la fonction `g`, puis dans la fonction `f`.
4. Continuer l'exécution du programme.


#### Exercice 4 : Points de vue
  
| commande | abrév. | signification | 
|:---     |  :---:      | :----              | 
|watch *exp* | wa *exp* | mise en place d'un point d'observation sur l'expression fournie|

On peut créer des points d'arrêt qui repose non plus sur un endroit précis du code, mais sur le fait qu'une expression change de valeur. Reprendre un des programmes précédents et tester.

#### Exercice 5 : gdb et core dump
Dans cet exercice, nous allons voir comment debuguer un programme qui génère un `core`, grâce à `gdb`.

1. Le plus souvent, par défaut la taille des fichiers `core` générés est limitée à 0. Pour supprimer toute limite, taper la commande `ulimit -c unlimited` dans un terminal.
2. Récupérer le programme [generating_core.c](generating_core.c), le compiler avec l'option `-g` et le lancer : un fichier `core` (parfois avec des extensions) a été créé.
3. Lancer `gdb` avec la ligne de commande `gdb generating_core core` (où `generating_core` est le nom de l'exécutable et `core` le nom du fichier core créé par l'erreur de segmentation précédente.
4. Regarder les valeurs de variables.

Attention, sur certains systèmes le fichier core n'est pas généré dans le répertoire courant. Dans ce cas, voici la manipulation à suivre pour récupérer le fichier :
1. Se déplacer dans `/var/lib/systemd/coredump/`
2. Décompresser avec lz4 le fichier core correspondant à l'exécution du programme.
3. Reprendre la manipulation du 3. précédent en spécifiant le fichier décompressé avec lz4 à la place de `core`.
