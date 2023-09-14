# TP2 : Processus et redirections


## Retour au TP1
**Exercice**: Les terminaux de vos comptes fonctionnent cette semaine,
il faut donc reprendre l'exercice 7 sur les droits du
[tp1](tp_prise_en_main_shell.html).

## Quelques raccourcis clavier utiles.
On a vu lors du TP précédent qu'on peut lancer dans un shell une commande en
_arrière-plan_ avec le symbole `&` afin de récupérer la main
directement (sinon le shell ne récupère la main que lorsque la
commande lancée se termine).

Comment faire quand on a oublié de mettre le symbole `&`? On peut
_suspendre_ le processus eavec la combinaison de touches `Ctrl-z` dans
le terminal (on peut maintenir `Ctrl` appuyé et pendant ce temps-là
déclencher la touche `z`), puis le relancer avec la commande
`bg` (comme _background_). Quand un processus est _suspendu_, il
existe encore mais est bloqué dans le temps: son état n'est plus modifié.

**Exercice**: Lancer `emacs` au premier plan, puis passer le processus
en arrière-plan.

Pour _interrompre_ un processus en premier plan, c'est-à-dire faire en sorte qu'il
s'arrête, on peut utiliser la combinaison de touches `Ctrl-c`.

**Exercice**: Copier le fichier [eternel.c](eternel.c), le compiler et exécuter
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
  

Quelques exemples:

* `cat` écrit sur la sortie standard ce qu'elle reçoit sur l'entrée standard.
* `date` ne prend rien sur le flot d'entrée et écrit sur le flot de sortie.
* `cd` ne prend rien en entrée et ne renvoie rien en sortie.


Le shell peut _rediriger_ ces flux, c'est-à-dire faire en sorte qu'ils
ne correspondent pas à l'interface habituelle (le terminal), mais à
une autre interface, en général un fichier régulier.



Il est souvent nécessaire de sauver les données en entrée ou en sortie d'un processus
dans des fichiers afin de pouvoir ensuite les réutiliser, les voir en totalité ou les traiter.
Par défaut, les trois flots standard correspondent au terminal depuis
lequel la commande est lancée: l'entrée standard est saisie au clavier
  et les sorties (standard et erreur) s'affichent à l'écran.
Cependant, on peut changer la destination de ces flots à l'aide du mécanisme de _redirection_.

Pour rediriger le flux de sortie d'une ligne de commande vers un
fichier, il suffit d'écrire la ligne de commande suivie du caractère
`>` et d'un chemin valide désignant le fichier (espaces ou non autour
de `>` : c'est comme vous voulez).


**Exercice** :
Récupérer les fichiers [histogramme.c](histogramme.c) et
[histogramme.h](histogramme.h) et les placer dans le même
répertoire. Compiler `histogramme.c` et
faire en sorte de récupérer la sortie standard de l'exécutable dans un
fichier `test.gnu`, puis lancer la ligne de commande `gnuplot -p
test.gnu`.

Note : nous verrons plus tard comment écrire dans des fichiers, mais
en attendant, vous pouvez récupérer tout ce qui est affiché sur la
sortie standard en faisant une redirection de sortie.

**Exercice** : Quand votre ligne de commande provoque une erreur, un
message d'erreur est affiché la plupart du temps. Ce message n'est pas
affiché sur la sortie standard, mais sur la sortie erreur standard.

1. Lancez la commande `ls schtroumpf` pour voir le message d'erreur.
2. Relancez-la avec une redirection de sortie erreur : vous voyez
   encore le message d'erreur.
3. Relancez-la sous cette forme : `ls schtroumpf 2> toto` (sans espace
   entre le `2` et le `>`) et regardez le contenu de `toto` avec la
   commande `cat` : vous venez de rediriger la sortie erreur.
