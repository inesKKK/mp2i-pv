# TP1 : Guide de survie en ligne de commande

Le but de ce TP est de manipuler les commandes de survie dans un
shell.

Pour s'habituer à se servir de la ligne de commande, il faut au début
se forcer à le faire. Entre autres : bannir tout navigateur de
fichiers, regarder les pages de manuel des commandes et, si on n'a pas
trouver par soi-même, demander comment effectuer une action dès qu'on
en a besoin (voire utiliser les raccourcis claviers pour vos applications
courantes).

## Particularité des machines de TP
Pour l'instant, vous avez un compte sur chaque machine de TP, avec le
même mot de passe, mais les données ne sont pas partagées. Il est donc
recommander de sauvegarder vos données en fin de séances, soit sur une
clef usb, soit en ligne, soit en vous envoyant un mail à vous même.

## Exploration du SGF

**Exercice 1** :
1. Créez un répertoire `MP2I` et un répertoire `MPI` dans votre répertoire
   personnel (quand vous ouvrez un terminal, le répertoire courant est
   par défaut votre répertoire personnel).
2. Créez un sous-répertoire `Informatique` dans votre répertoire
   `MP2I`.
3. Trouvez (grâce à la page de manuel de `mkdir`) quelle option permet
   de créer tout un chemin de nouveaux répertoires, et utilisez-la
   pour créer le répertoire `~/MP2I/Informatique/TP/TP1` en une seule
   ligne de commande (rappel : dans le shell `~` désigne le répertoire
   personnel de l'utilisateur).
4. Faites de `~/MP2I/Informatique/TP/TP1` votre répertoire
   courant avec la commande `cd`.
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
En vous aidant de sa page de manuel, trouvez ce que fait la commande
`tree` et l'option qui permet de limiter la profondeur d'exploration.

**Exercice 4** :
La commande `cp` permet de copier un fichier : son premier argument
est un chemin valide désignant un fichier source et son deuxième
argument est un chemin valide désignant une destination:

* soit un répertoire existant (auquel cas le fichier est copié dans ce
    répertoire et garde son nom de base),
* soit un  fichier ou une destination inexistante (et dans ce cas un
    fichier avec ce nom est créé s'il n'existe pas, et son contenu est
    écrasé par celui du fichier source).

1. Listez le contenu du répertoire `/tmp`.
2. Trouvez un fichier régulier dans ce répertoire sur lequel vous avez
   les droits en lecture.
3. Copiez ce fichier dans votre répertoire de login sous le nom `fic`.
4. Pour voir le contenu de ces fichiers, vous pouvez utiliser la
   commande `cat` suivi du nom du fichier (quand un fichier est long,
   on peut utiliser `less` qui permet du défilement page par page
   grâce à la barre d'espace, ou ligne à ligne grâce à la touche
   `Enter` et aux touches flèches; on arrête le défilement avec la
   touche `q`)


**Exercice 5** :
Copier le fichier `fic` dans un nouveau fichier
`copie`. Ouvrez ce nouveau fichier l'éditeur de texte `emacs` (voir
section [Choisir son éditeur de texte](#editeur) ci-dessous), en
écrivant le nom de l'éditeur suivi du nom du fichier.

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


## Se connecter chez son voisin
La commande `ifconfig` permet d'obtenir l'adresse IP de sa machine
(c'est un identifiant unique qui identifie la machine sur le
réseau). En connaissant l'adresse IP d'une machine, on peut s'y
connecter à distance avec la commande `ssh` (à condition que ce soit
autorisé).

**Exercice 6**:
Connectez-vous à la machine de votre voisin (attention:
`ssh` ne fait pas d'echo pour le mot de passe, rien ne s'affiche) et
affichez la date et l'heure de la machine.

## Droits

**Exercice 7** :
1. Faites en sorte que personne d'autre que vous (et root) ne puisse
lister votre répertoire personnel. (Testez avec votre voisin(e).)
2. Créer un répertoire `Public` dans votre répertoire personnel de
telle sorte que tout le monde puisse lister le contenu de ce
répertoire. (Testez avec votre voisin(e).)
3. Créer un fichier `public` et un fichier `prive` dans ce
   répertoire de telle sorte que votre voisin(e) puisse voir le
   contenu du fichier `public` et pas celui du fichier `prive`.


## Quelques raccourcis clavier utiles.
On a vu plus haut qu'on peut lancer dans un shell une commande en
_arrière-plan_ avec le symbole `&` afin de récupérer la main
directement (sinon le shell ne récupère la main que lorsque la
commande lancée se termine).

Comment faire quand on a oublié de mettre le symbole `&`? On peut
_suspendre_ le processus avec la combinaison de touches `Ctrl-z` dans
le terminal (on peut maintenir `Ctrl` appuyé et pendant ce temps-là
déclencher la touche `z`), puis le relancer avec la commande
`bg` (comme _background_). Quand un processus est _suspendu_, il
existe encore mais est bloqué dans le temps : son état n'est plus modifié.

**Exercice 8** : Lancer `emacs` au premier plan, puis passer le processus
en arrière-plan.

Pour _interrompre_ un processus en premier plan, c'est-à-dire faire en sorte qu'il
s'arrête, on peut utiliser la combinaison de touches `Ctrl-c`.

**Exercice 9** : Copier le fichier [eternel.c](eternel.c), le compiler et exécuter
l'exécutable ainsi obtenu en premier plan. Essayer d'utiliser le
terminal. Interrompre le processus en premier plan.

## Redirections
Tout processus (et en particulier toute commande) possède trois flux
de données qui permettent d'interagir avec l'utilisateur :
* l'_entrée standard_ (en général ce que vous écrivez dans votre
  terminal, par exemple si une commande vous demande votre mot de
  passe)
* la _sortie standard_ (en général ce qui est affiché dans votre
  terminal quand l'exécution du programme ne rencontre pas d'erreur,
  par exemple le contenu d'un répertoire quand on utilise la commande `ls`)
* la _sortie erreur standard_ (en général ce qui est affiché dans
  votre terminal quand l'exécution d'un programme rencontre une
  erreur, par exemple quand un argument est un chemin non valide)
  
![](unix1.png)
  

Quelques exemples :

* `cat` écrit sur la sortie standard ce qu'elle reçoit sur l'entrée standard.
* `date` ne prend rien sur le flot d'entrée et écrit sur le flot de sortie.
* `cd` ne prend rien en entrée et ne renvoie rien en sortie.


Le shell peut _rediriger_ ces flux, c'est-à-dire faire en sorte qu'ils
ne correspondent pas à l'interface habituelle (le terminal), mais à
une autre interface, en général un fichier régulier.



Il est souvent nécessaire de sauver les données en entrée ou en sortie d'un processus
dans des fichiers afin de pouvoir ensuite les réutiliser, les voir en totalité ou les traiter.
Par défaut, les trois flots standard correspondent au terminal depuis
lequel la commande est lancée : l'entrée standard est saisie au clavier
  et les sorties (standard et erreur) s'affichent à l'écran.
Cependant, on peut changer la destination de ces flots à l'aide du mécanisme de _redirection_.

Pour rediriger le flux de sortie d'une ligne de commande vers un
fichier, il suffit d'écrire la ligne de commande suivie du caractère
`>` et d'un chemin valide désignant le fichier (espaces ou non autour
de `>` : c'est comme vous voulez).


**Exercice 10** :
Récupérer les fichiers [histogramme.c](histogramme.c) et
[histogramme.h](histogramme.h) et les placer dans le même
répertoire. Compiler `histogramme.c` et
faire en sorte de récupérer la sortie standard de l'exécutable dans un
fichier `test.gnu`, puis lancer la ligne de commande `gnuplot -p
test.gnu`.

Note : nous verrons plus tard comment écrire dans des fichiers, mais
en attendant, vous pouvez récupérer tout ce qui est affiché sur la
sortie standard en faisant une redirection de sortie.

**Exercice 11** : Quand votre ligne de commande provoque une erreur, un
message d'erreur est affiché la plupart du temps. Ce message n'est pas
affiché sur la sortie standard, mais sur la sortie erreur standard.

1. Lancez la commande `ls schtroumpf` pour voir le message d'erreur.
2. Relancez-la avec une redirection de sortie : vous voyez
   encore le message d'erreur.
3. Relancez-la sous cette forme : `ls schtroumpf 2> toto` (sans espace
   entre le `2` et le `>`) et regardez le contenu de `toto` avec la
   commande `cat` : vous venez de rediriger la sortie erreur.

## Pour ceux qui ont terminé
[jeu Terminus](https://luffah.xyz/bidules/Terminus/)


## <a name="editeur"></a>Choisir un éditeur de texte

Le choix d'un éditeur de texte est personnel. Pour l'instant il y a
(au moins) trois éditeurs installés sur les ordinateurs du
lycée :

* Deux éditeurs qui ont fait leurs preuves et existent depuis très
  longtemps (avec plein d'évolutions depuis) :
  * [vim](https://www.vim.org/) (depuis 1991) : éditeur léger en mode texte; très
  intéressant quand on se connecte à distance sur une machine. Pas
  forcément adapté à un débutant. Si vous le lancez sans vous
  renseigner avant, pour en sortir, appuyez sur la combinaison
  suivante de touches suivie de la touche `"Entrée"` (sans les
  espaces, une touche à la fois, dans 
  l'ordre) : `Esc : q !`
  * [emacs](https://www.gnu.org/software/emacs/) (depuis 1976) : un éditeur
  extrêmement complet. Vous pouvez faire plein de choses à la souris
  le temps d'apprendre à les faire autrement (parce que c'est quand
  même plus rapide au clavier).
  
Avantages : il est probable que ces deux éditeurs perdurent encore,
vous les trouverez partout et ils ont une grosse communauté
d'utilisateurs irréductibles. Ils sont faciles à installer et souvent
installés par défaut dans les distributions linux grand public.
  
* Un éditeur beaucoup plus récent : [VSCode](https://code.visualstudio.com/), le
    dernier éditeur à la mode de microsoft (plus un IDE qu'un éditeur)

Il y a sûrement des avantages à utiliser VS Code, mais si ça se trouve
dans deux ou trois ans j'en mettrai un autre à la place (qui se
souvient encore d'[atom](https://atom.io/)?)

Comment choisir un éditeur ? Il faut les tester.

Mise en garde :
* je ne pourrai pas vous aider pour autre chose que `vim` et `emacs`,
* les configurations machine aux oraux des concours sont variées, mais il est
  certain qu'emacs et vim seront disponibles; si vous êtes
  trop dépendants de l'installation, vous risquez d'avoir de mauvaises
  surprises au moment de l'oral,
* au bout d'un moment, c'est très difficile de changer d'éditeur, car
  les nouveaux qu'on teste ne possèdent pas telle ou telle
  fonctionnalité tellement pratique de l'éditeur auquel vous êtes
  habitué,
* utilisez un éditeur qui possède une coloration syntaxique et indente
  automatiquement le code, c'est une aide appréciable pour développer.

------------------------------------------
<a name="myfootnote1">1</a> : Ceci est un abus de langage, ce n'est pas le processus à
proprement parlé qui est en premier-plan ou en arrière-plan, c'est la
tâche à laquelle il appartient, notion qui est hors programme. Si
certains veulent un complément, j'avais fait des vidéos là-dessus
(complètement hors programme bien sûr et vous ne comprendrez pas
tout) : [https://youtu.be/Uz7wE1Zk8zU](https://youtu.be/Uz7wE1Zk8zU)
et [https://youtu.be/dgqc8TLyqJE](https://youtu.be/dgqc8TLyqJE).
