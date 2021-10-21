# TP7 : Guide de survie en ligne de commande

Le but de ce TP est d'introduire les commandes de survie dans un
shell, et d'en profiter pour compiler un peu de `C` en ligne de commande.

Pour s'habituer à se servir de la ligne de commande, il faut au début
se forcer à la faire. Entre autres : bannir tout navigateur de
fichiers, et demander comment effectuer une action dès qu'on en a
besoin (voire utiliser les raccourcis claviers pour vos applications
courantes).

## Des commandes et un peu de programmation
Comme vu en cours, l'ensemble des fichiers possède une structure
arborescente. La racine de cette structure s'appelle la _racine_ et
correspond toujours au chemin absolu `/`.

On peut créer un nouveau répertoire avec la commande `mkdir` qui prend
comme argument un chemin valide. On peut supprimer un répertoire
_vide_ avec la commande `rmdir` (en lui fournissant bien entendu un
chemin valide pour le répertoire à supprimer).

exemple (rappel : le caractère `$` désigne l'invite de commande):
```bash
$ ls
$ mkdir Repertoire
$ ls
Repertoire
$ mkdir Repertoire/AAA
$ ls
Repertoire
$ ls Repertoire/
AAA
$ mkdir BBB/CCC
mkdir: impossible de créer le répertoire «BBB/CCC»: Aucun fichier ou dossier de ce type
```
La dernière commande produit une erreur car le répertoire courant ne
contient pas de sous-répertoire `BBB`.

**Exercice 1** :
1. Créez un répertoire `MP2I` et un répertoire `MPI` dans votre répertoire
   personnel (quand vous ouvrez un terminal, le répertoire courant est
   par défaut votre répertoire personnel).
2. Créez un sous-répertoire `Informatique` dans votre répertoire
   `MP2I`.
3. Trouvez (grâce à la page de manuel de `mkdir`) quelle option permet
   de créer tout un chemin de nouveaux répertoires, et utilisez-la
   pour créer le répertoire `~/MP2I/Informatique/TP/TP7` en une seule
   ligne de commande (rappel : dans le shell `~` désigne le répertoire
   personnel de l'utilisateur).
4. Faites de `~/MP2I/Informatique/TP/TP7` votre répertoire courant.
5. Créez un répertoire `SI` dans votre répertoire courant, puis
   supprimez-le.
   
   
Note : Prenez l'habitude de ranger vos données et de ne pas mettre
tout en vrac dans votre répertoire personnel, cela facilitera
grandement votre vie quotidienne sur machine au bout d'un moment.

**Exercice 2** :
Lancez la commande `setxkbmap us` dans votre terminal. Écrivez le
texte `qwerty` maintenant. À vous de trouver comment régler à nouveau
votre clavier en azerty !

**Exercice 3** :
La commande `cp` permet de copier un fichier : son premier argument
est un chemin valide désignant un fichier source et son deuxième
argument est un chemin valide désignant une destination:

* soit un répertoire existant (auquel cas le fichier est copié dans ce
    répertoire et garde son nom de base),
* soit un  fichier ou une destination inexistante (et dans ce cas un
    fichier avec ce nom est créé s'il n'existe pas, et son contenu est
    écrasé par celui du fichier source).

1. Copiez les fichiers `/home/klimann/histogramme.c` et
`/home/klimann/histogramme.h` dans votre répertoire courant (qui est
encore `~/MP2I/Informatique/TP/TP7` en principe).
2. Pour voir le contenu de ces fichiers, vous pouvez utiliser la
   commande `cat` suivi du nom du fichier (quand un fichier est long,
   on peut utiliser `less` qui permet du défilement page par page
   grâce à la barre d'espace, ou ligne à ligne grâce à la touche
   `Enter` et aux touches flèches; on arrête le défilement avec la
   touche `q`)
3. Compilez le programme `histogramme.c` avec la commande `gcc` (il
   faut que le fichier `histogramme.h` soit dans le même répertoire), et
   exécutez l'exécutable obtenu.
   
**Exercice 4** :
On veut récupérer l'affichage du programme précédent dans un
fichier. Une première solution consiste à écrire directement dans un
fichier, mais nous verrons cela plus tard dans l'année.

Tout exécutable possède trois flux de données qui permettent
d'interagir avec l'utilisateur :
* l'_entrée standard_ (en général ce que vous écrivez dans votre
  terminal, par exemple si une commande vous demande votre mot de
  passe)
* la _sortie standard_ (en général ce qui est affiché dans votre
  terminal quand l'exécution du programme ne rencontre pas d'erreur,
  par exemple le contenu d'un répertoire quand on utilise la commande `ls`)
* la _sortie erreur standard_ (en général ce qui est affiché dans
  votre terminal quand l'exécution d'un programme rencontre une
  erreur, par exemple quand un argument est un chemin non valide)
  
  
Le shell peut _rediriger_ ces flux, c'est-à-dire faire en sorte qu'ils
ne correspondent pas à l'interface habituelle (le terminal), mais à
une autre interface, en général un fichier régulier.

Pour rediriger le flux de sortie d'une ligne de commande vers un
fichier, il suffit d'écrire la ligne de commande suivie du caractère
`>` et d'un chemin valide désignant le fichier (espaces ou non autour
de `>` : c'est comme vous voulez).

Faites en sorte de récupérer la sortie standard de l'exécutable de
l'exercice précédent dans un fichier `test.gnu`, puis lancez la
ligne de commande `gnuplot -p test.gnu`.

Note : nous verrons plus tard comment écrire dans des fichiers, mais
en attendant, vous pouvez récupérer tout ce qui est affiché par
`printf` en faisant une redirection de sortie.

**Exercice 5** : Quand votre ligne de commande provoque une erreur, un
message d'erreur est affiché la plupart du temps. Ce message n'est pas
affiché sur la sortie standard, mais sur la sortie erreur standard.

1. Lancez la commande `ls schtroumpf` pour voir le message d'erreur.
2. Relancez-la avec une redirection de sortie erreur : vous voyez
   encore le message d'erreur.
3. Relancez-la sous cette forme : `ls schtroumpf 2> toto` (sans espace
   entre le `2` et le `>`) et regardez le contenu de `toto` avec la
   commande `cat` : vous venez de rediriger la sortie erreur
   <sup>[3](#myfootnote3)</sup>.


**Exercice 6** :
Copier le fichier `histogramme.c` dans un nouveau fichier
`courbe.c`. Ouvrez ce nouveau fichier avec un éditeur de texte (voir section 
   [Choisir son éditeur de texte](#editeur) ci-dessous), en écrivant
   le nom de l'éditeur suivi du nom du fichier.

Vous remarquez que vous ne pouvez plus écrire de commandes dans le
terminal. Fermez votre éditeur de texte et relancez la commande
précédente en la faisant suivre du caractère `&` (avec ou sans espace,
mais sur la même ligne de commande) : vous pouvez maintenant relancez
une commande (essayez avec la commande `ls` par exemple).

La première fois, le processus lancé par votre commande était en
_premier plan_ <sup>[1](#myfootnote1)</sup>, alors que la deuxième fois il était en
_arrière-plan_ <sup>[1](#myfootnote1)</sup>. Le processus au premier plan dans un terminal est
celui qui reçoit les informations qu'on fait passer par le terminal
(c'est souvent le shell donc).


**Exercice 7** :
Modifier la fonction `main` de `courbe.c` pour que l'exécutable prenne
autant d'arguments qu'on le souhaite, supposés représenter des
entiers, et crée un fichier pour `gnuplot` pour représenter ces
entiers sous forme d'histogramme. La fonction `atoi` permet d'obtenir
un entier à partir d'une chaîne de caractères, par exemple appliquée à
`"105"`, elle renvoie `105`.

## Droits
La plupart des systèmes multi-utilisateurs mettent en place un système
de gestion de droits. Dans les systèmes de type unix/linux, les droits
sont définis pour chaque fichier (au sens large, les répertoires sont
également concernés). Ils sont de trois types et appliqués à trois
groupes d'utilisateurs :

* types de droits : lecture (`r`) / écriture (`w`) / exécution (`x`)

* groupes d'utilisateurs : propriétaire du fichier (`u`) / groupe
  propriétaire (`g`) / autres (`o`)
  
La commande `id` permet de connaître l'identifiant et les groupes
auxquels appartient un utilisateur. Sans argument, elle s'applique à
l'utilisateur qui lance la commande, mais elle peut aussi prendre en
argument le login (=nom de connection) d'un utilisateur ou son
identifiant (tous les utilisateurs sont identifiés par un nombre).

La commande `ls` avec l'option `-l` permet de connaître les droits sur
un fichier; ce sont les neuf derniers caractères du premier bloc de dix
caractères :

* le premier caractère désigne le type de fichier : `-` pour un
  fichier régulier, `d` pour un répertoire,
* les trois caractères suivants désignent le droits du propriétaire du
  fichier,
* les trois caractères suivants désignent les droits du groupe
  propriétaire,
* les trois derniers caractères désignent les droits des autres
  utilisateurs.
  
Chaque groupe de trois caractères est composé de la manière suivante :

* le premier caractère est le droit en lecture : `r` si le type
  d'utilisateur possède ce droit, `-` sinon,
* le deuxième caractère est le droit en écriture : `w` si le type
  d'utilisateur possède ce droit, `-` sinon,
* le troisième caractère est le droit en exécution : `x` si le type
  d'utilisateur possède ce droit, `-` sinon,

Signification de ces droits :

| |fichier ordinaire|répertoire|
|--|--|--|
|`r`|voir le contenu (ex: `cat`)|voir le contenu (ex: `ls`)|
|`w`|modifier le contenu (ex: dans un éditeur)|ajouter/supprimer des fichiers ou sous-répertoires (ex: `mkdir`)|
|`x`|exécuter (lancer comme une commande)|traverser (`.../repertoire/...`)|



Attention : `ls -l Rep` où `Rep` est un répertoire donnera des
renseignements sur les fichiers et sous-répertoires de `Rep`, pas sur
`Rep` lui-même. Si on veut des renseignements sur `Rep`, il faut
ajouter l'option `-d` : `ls -l -d`, ou, plus simplement `ls -ld`.

Seuls le propriétaire d'un fichier et le super-utilisateur (aussi
appelé _root_) pour modifier les droits d'un fichier. (Notez que pour
supprimer un fichier il faut les droits en écriture sur le répertoire
qui contient ce fichier, indépendemment du fait qu'on soit
propriétaire ou non de ce fichier ou du répertoire.)

Pour modifier les droits d'un fichier (au sens large), on utilise la
commande `chmod` suivi d'information sur les nouveaux droits et du nom
du ou des fichier(s) concerné(s). Il y a plusieurs façons de spécifier
les nouveaux droits, pour l'instant nous n'en verrons qu'une: on
enchaÎne, en les séparant par des virgules (**sans espaces**) des
spécifications du type utilisateurs/opération/droit. Par exemple :

```bash
chmod ug+r,o-wx fichier1 fichier2
```
signifie qu'on ajoute les droits en lecture au propriétaire et au
groupe propriétaire du fichier et qu'on enlève les droits en écriture
et exécution aux autres, pour les fichiers `fichier1` et
`fichier2`. Ce changement est _relatif_ aux droits précédents : si par
exemple le propriétaire du fichier avait le droit d'écriture sur le
`fichier1`, il le garde, s'il ne l'avait pas, il ne l'a toujours pas.

**Exercice 8** :
1. Faites en sorte que personne d'autre que vous (et root) ne puisse
lister votre répertoire personnel. (Testez avec votre voisin(e).)
2. Créer un répertoire `public` dans votre répertoire personnel de
telle sorte que tout le monde puisse lister le contenu de ce
répertoire. (Testez avec votre voisin(e).)
3. Créer un fichier `public.c` et un fichier `prive.c` dans ce
   répertoire de telle sorte que votre voisin(e) puisse voir le
   contenu du fichier `public.c` et pas celui du fichier `prive.c`

## Plus sur la compilation

La compilation d'un programme `C` se fait en plusieurs étapes (et
ces étapes peuvent dépendre du compilateur). Au moment où le
compilateur passe dans un morceau de code où une variable, une valeur
ou une fonction est utilisée, il vérifie si les types qui apparaissent
sont cohérents, par exemple pour une affectation si le type de la
rvalue est compatible avec le type de la lvalue.

Le compilateur a donc, entre autres, besoin de connaître les types de
retour des fonctions ainsi que les types de leurs paramètres. Si la
fonction est définie (=en-tête+corps) _avant_ son utilisation, il les
connaît et peut procéder à des vérifications. Sinon ce n'est pas le
cas, et la compilation produit une erreur.

Cette étape de vérification se fait lors
de la compilation avant l'_édition de liens_ qui est l'étape où le
lien est effectivement fait entre un appel de fonction et la
définition de cette fonction (c'est-à-dire son code).

**Exercice 9** : 
1. Copier le fichier `~klimann/MP2I/TP7/ordre.c` et compilez-le. Échangez
   l'ordre de `f` et `main` et recompilez-le.
2. Repartez de la version précédente de `ordre.c` et ajoutez _avant le
   `main`_ la ligne suivante :
   ```C
   void f();
   ```
   et essayez de compiler à nouveau (avec la définition de `main`
   _avant_ celle de `f`).


### Fichiers d'en-tête
Quand on écrit un petit programme qui ne sera utilisé que par nous,
cette solution de déclarer les fonctions en tête de fichier `.c` est
parfaitement suffisante. Mais quand on écrit un programme dans le but
qu'il soit réutilisé, elle est peu satisfaisante : on n'a pas
forcément envie que l'utilisateur accède au code qu'on a écrit (ne
serait-ce que parce qu'il peut le modifier par mégarde), mais on doit
quand même lui fournir les en-tête des fonctions et les définitions de
types.

On a vu qu'il existe des fichiers d'en-tête (_headers_ en anglais) qui
permettent de déclarer des types et des fonctions. Ces fichiers
portent l'extension `.h`. **Un fichier d'en-tête ne sert pas à définir
des fonctions**, seulement à les déclarer (donc pas de corps de
fonctions, que des en-têtes).

On ne peut pas définir plusieurs fois la même entité en `C`, il est
donc important qu'un fichier d'en-tête ne soit inclus qu'une seule
fois.

**Exercice 10** :
1. Copiez les fichiers `~klimann/MP2I/TP7/entete.h` et
`~klimann/MP2I/TP7/entete.c` et compiler `entete.c`.
2. Pour remédier à ce problème, on utilise des instructions de
   pré-compilation (qui sont exécutées dans la toute première phase de
   compilation) qui permettent de dire : si telle macro n'est pas
   définie, alors on la définit et on en profite pour déclarer ce
   qu'on a à déclarer.
   Ajouter au début du fichier `entete.h` les lignes
   
```C
#ifndef _ENTETE_H_
#define _ENTETE_H_
```
et à la fin la ligne

```C
#endif
```
Compiler à nouveau `entete.c`.

**Exercice 11** : Assez vite, on arrive à des fichiers sources trop
longs, ou dont on voudrait pouvoir réutiliser une partie et pas
l'autre par exemple. Pour structurer un programme, on peut bien
entendu le séparer en plusieurs fichiers. Pour compiler un programme
éparpillé sur plusieurs fichiers, il suffit de tous les donner en
argument à `gcc`<sup>[2](#myfootnote2)</sup>. Vous pouvez tester en
écrivant un programme avec une fonction `f` dans un fichier, et un
`main` qui appelle `f` dans un autre (n'oubliez pas de déclarer `f`
dans un fichier d'en-tête !).

## <a name="editeur"></a>Choisir un éditeur de texte

Le choix d'un éditeur de texte est personnel. Pour l'instant il y a
(au moins) quatre éditeurs installés sur les ordinateurs du
lycée :

* Deux éditeurs qui ont fait leurs preuves et existent depuis très
  longtemps (avec plein d'évolutions depuis) :
  * [vim](https://www.vim.org/) (depuis 1991) : éditeur léger en mode texte; très
  intéressant quand on se connecte à distance sur une machine. Pas
  forcément adapté à un débutant. Si vous le lancez sans vous
  renseigner avant, pour en sortir, appuyez sur la combinaison
  suivante de touches (sans les espaces, une touche à la fois, dans
  l'ordre) : `Esc : q !`
  * [emacs](https://www.gnu.org/software/emacs/) (depuis 1976) : un éditeur
  extrêmement complet. Vous pouvez faire plein de choses à la souris
  le temps d'apprendre à les faire autrement (parce que c'est quand
  même plus rapide au clavier).
  
Avantages : il est probable que ces deux éditeurs perdurent encore,
vous les trouverez partout et ils ont une grosse communauté
d'utilisateurs irréductibles. Ils sont faciles à installer.
  
* Deux éditeurs beaucoup plus récents :
  * [sublimetext](https://www.sublimetext.com/) qui permet de
    manipuler plusieurs bouts de texte en même temps (et sûrement
    plein d'autres choses) [info de dernière minute : cet éditeur
    n'est pas encore installé]
  * [vscodium](https://vscodium.com), clone libre de VSCode, le
    dernier éditeur à la mode (plus un IDE qu'un éditeur)

Il y a sûrement des avantages à utiliser tout ça, mais si ça se trouve
dans deux ou trois ans j'en mettrai deux autres à la place (qui se
souvient encore d'[atom](https://atom.io/)?)

Comment choisir un éditeur ? Il faut les tester.

Mise en garde :
* je ne pourrai pas vous aider pour autre chose que `vi` et `emacs`,
* personne ne sait encore quelles seront les outils et configurations
  disponibles pour les épreuves sur machine des concours; si vous êtes
  trop dépendants de l'installation, vous risquez d'avoir de mauvaises
  surprise au moment de l'oral,
* au bout d'un moment, c'est très difficile de changer d'éditeur, car
  les nouveaux qu'on teste ne possède pas telle ou telle
  fonctionnalité tellement pratique de l'éditeur auquel vous êtes
  habitué.

------------------------------------------
<a name="myfootnote1">1</a>: Ceci est un abus de langage, ce n'est pas le processus à
proprement parlé qui est en premier-plan ou en arrière-plan, c'est la
tâche à laquelle il appartient, notion qui est hors programme. Si
certains veulent un complément, j'avais fait des vidéos là-dessus
(complètement hors programme bien sûr et vous ne comprendrez pas
tout) : [https://youtu.be/Uz7wE1Zk8zU](https://youtu.be/Uz7wE1Zk8zU)
et [https://youtu.be/dgqc8TLyqJE](https://youtu.be/dgqc8TLyqJE).

<a name="myfootnote2">2</a>: Dans la vrai vie, il existe des outils
pour gérer la compilation des gros projets et notamment spécifier les
dépendances entre tous les fichiers qui interviennent, ce qui évite de
tout recompiler quand on ne modifie qu'un seul fichier par exemple,
mais permet aussi de recompiler tout ce qu'il est nécessaire de
recompiler sans se poser de questions à chaque fois. Ces outils sont
hors programme, mais les plus curieux pourron jeter un œil à [gnu
make](https://www.gnu.org/software/make/) qui est sans doute l'outil
de base le plus classique à cet effet pour le `C`.

<a name="myfootnote3">3</a>: Attention, contrairement à la redirection
de sortie, le signe de redirection de sortie erreur dépend du shell
utilisé (`2>` est valide en `bash` et `zsh`, mais pas en `tcsh` par exemple).
