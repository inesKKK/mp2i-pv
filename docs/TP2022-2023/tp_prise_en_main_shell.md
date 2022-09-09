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
Vos comptes contiennent par défaut plusieurs répertoires, dont le
répertoire `Documents`. Ce répertoire n'est pas local à la machine,
mais se trouve sur un serveur de
fichiers: vous le retrouverez quelle que soit la machine de TP sur
laquelle vous vous connecterez, il est donc conseillé de mettre tous
vos fichiers dans cette arborescence. (Note: d'autres répertoires sont
également partagés, mais pas votre répertoire de login.)

## Exploration du SGF
Comme vu en cours, l'ensemble des fichiers possède une structure
arborescente. Le point de départ de cette structure s'appelle la _racine_ et
correspond toujours au chemin absolu `/`.

On peut créer un nouveau répertoire avec la commande `mkdir` qui prend
comme argument un chemin valide. On peut supprimer un répertoire
_vide_ avec la commande `rmdir` (en lui fournissant bien entendu un
chemin valide pour le répertoire à supprimer).


**exemple** (rappel : le caractère `$` désigne l'invite de commande):
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
1. Créez un répertoire `MP2I` et un répertoire `MPI` dans le
   sous-répertoire `Documents` de votre répertoire
   personnel (quand vous ouvrez un terminal, le répertoire courant est
   par défaut votre répertoire personnel).
2. Créez un sous-répertoire `Informatique` dans votre répertoire
   `MP2I`.
3. Trouvez (grâce à la page de manuel de `mkdir`) quelle option permet
   de créer tout un chemin de nouveaux répertoires, et utilisez-la
   pour créer le répertoire `~/Documents/MP2I/Informatique/TP/TP1` en une seule
   ligne de commande (rappel : dans le shell `~` désigne le répertoire
   personnel de l'utilisateur).
4. Faites de `~/Documents/MP2I/Informatique/TP/TP1` votre répertoire
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

**Exercice 7** :
1. Faites en sorte que personne d'autre que vous (et root) ne puisse
lister votre répertoire personnel. (Testez avec votre voisin(e).)
2. Créer un répertoire `Public` dans votre répertoire personnel de
telle sorte que tout le monde puisse lister le contenu de ce
répertoire. (Testez avec votre voisin(e).)
3. Créer un fichier `public` et un fichier `prive` dans ce
   répertoire de telle sorte que votre voisin(e) puisse voir le
   contenu du fichier `public` et pas celui du fichier `prive`.

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
* je ne pourrai pas vous aider pour autre chose que `vi` et `emacs`,
* personne ne sait encore quelles seront les outils et configurations
  disponibles pour les épreuves sur machine des concours, mais il est
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
<a name="myfootnote1">1</a>: Ceci est un abus de langage, ce n'est pas le processus à
proprement parlé qui est en premier-plan ou en arrière-plan, c'est la
tâche à laquelle il appartient, notion qui est hors programme. Si
certains veulent un complément, j'avais fait des vidéos là-dessus
(complètement hors programme bien sûr et vous ne comprendrez pas
tout) : [https://youtu.be/Uz7wE1Zk8zU](https://youtu.be/Uz7wE1Zk8zU)
et [https://youtu.be/dgqc8TLyqJE](https://youtu.be/dgqc8TLyqJE).
