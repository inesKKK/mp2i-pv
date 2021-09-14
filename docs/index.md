## Informatique MP2I Paul Valery (Paris)

[programme officiel](https://cache.media.education.gouv.fr/file/SPE1-MEN-MESRI-4-2-2021/64/6/spe777_annexe_1373646.pdf)

### Le cours

Le cours est composé de trois grands thèmes qui sont développés en
parallèle :
* Algorithmique
* Programmation
* Systèmes

Vous avez accès à un plan de ce que nous avons fait sous plusieurs
formes :
* [vision synthétique](Cours/synthese.md)
* [vision chronologique](Cours/chronologie.md)
* par thème :  [Algorithmique](Cours/algorithmique.md) /
  [Programmation](Cours/prog.md) /  [Systèmes](Cours/systemes.md)

### Le TP

La partie `C` sera faite sur un serveur
[jupyterhub avec nbgrader](https://informatique.cpge-pv.ovh).


La partie `ocaml` sera gérée sur [essok](https://essok.learn-ocaml.org/).

La partie `sql` je ne sais pas encore.

### Le TD

Les énoncés sont disponibles sur [cahier de prépa](https://cahier-de-prepa.fr/mp2i-pv/).

### Pour s'entraîner à programmer sans rien installer

À terme c'est sûrement une bonne idée d'installer un linux et d'y
mettre les outils nécessaires pour programmer dans de bonnes
conditions. Mais en première approximation, il existe des outils
gratuits en ligne qui feront l'affaire pour la partie programmation.

pour plein de langages : [https://ideone.com/](https://ideone.com/)

`C` :
[http://pythontutor.com/c.html#mode=edit](http://pythontutor.com/c.html#mode=edit)
qui permet de voir l'état de la mémoire, ou
[https://www.mycompiler.io/](https://www.mycompiler.io/) juste pour
éditer et compiler

`ocaml` : [https://try.ocamlpro.com/](https://try.ocamlpro.com/) qui
ressemble plus à l'environnement utilisé en TP


### Pour travailler sous unix/linux

* Si vous avez un mac : rien à faire, OSX est une surcouche sur BSD.
* Si vous avez un pc sous windows, plusieurs solutions :
  * vous écrasez windows avec une distribution linux [sauvegardez vos
    données avant]
  * vous mettez en place un double boot [sauvegardez vos
    données avant]
  * vous installez un machine virtuelle [installez un distribution
    légère, surtout si votre machine possède peu de RAM]
  * utilisez un conteneur docker [pas forcément recommandé pour des
    débutants]
  * il paraît que WSL et WSL2 fonctionnent
* Quelle distribution choisir ?
  * la plus grand public et celle qui est installée au lycée : Ubuntu
  * un peu plus geek : Debian
  * encore plus geek (?) : ArchLinux
  * pour que vos grands-parents puissent aussi s'en servir : dflinux
  * pour installer sur le premier ordinateur que votre père/mère geek
    a acheté : toutou linux
  * et toutes les autres, à vous de regarder ce que vous voulez privilégier

### Pour poser des questions

* mail
* ENT
* [cahier de prépa](https://cahier-de-prepa.fr/mp2i-pv/)
* discord

### Le coin culture, articles divers et hors programme
Je vous propose ici des ressources externes et quelques documents que
j'ai produits moi-même pour vous permettre de prendre du recul sur le
programme.

* Sur la complexité :
  [intérêt](https://www.lemonde.fr/blog/binaire/2021/04/16/henri-potier-a-lecole-de-la-complexite/),
  [classes de complexité](https://interstices.info/la-theorie-de-la-complexite-algorithmique/)
* Sur l'indécidabilité du problème de l'arrêt: [vidéo du Professeur Karré](https://www.youtube.com/watch?v=13O1qhX4Bqo)
* Sur les codages de nombres en machine : [exemples de catastrophes
  dûes à des erreurs de conversion](https://www.iro.umontreal.ca/~mignotte/IFT2425/Disasters.html)
