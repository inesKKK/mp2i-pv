Quelques raccourcis claviers pour emacs
---

Notations :

* `Esc-x` signifie qu'il faut appuyer sur la touche `Esc` (ou échappement)
  sans la maintenir, puis sur la touche `x`
* `Ctrl-x` signifie qu'il faut appuyer sur la touche `Ctrl` (ou contrôle)
  en la maintenant appuyée et sur la touche `x`, et seulement après
  relâcher `Ctrl`.
* Attention :
  * `Ctrl-x Ctrl-y` signifie qu'il faut appuyer sur la touche `Ctrl`
    en la maintenant appuyer et sur la suite de touches `x` puis `y`,
    et seulement après relâcher `Ctrl`.
  * `Ctrl-x y` signifie qu'il faut appuyer sur la touche `Ctrl`
    en la maintenant appuyée, sur la touche `x`, relâcher `Ctrl`, puis
    appuyer sur la touche `y`.

Je mets parfois entre parenthèse un mot en anglais pour vous aider à
retenir le raccourci.

## Faire apparaître les numéros de lignes

`Esc-x global-display-line-numbers-mode`

## Se déplacer

* les flèches
* un caractère :
  * à droite `Ctrl-f` (*forward*)
  * à gauche `Ctrl-b` (*backward*)
  * au-dessus `Ctrl-p` (*prevous*)
  * au-dessous `Ctrl-n` (*next*)
* ligne courante :
  * au début `Ctrl-a` (`a`, c'est la première lettre de l'alphabet)
  * à la fin `Ctrl-e` (*end*)
* mot courant :
  * au début : `Esc-b` (*backward*)
  * à la fin : `Esc-f` (*forward*)
* fichier :
  * aller au début : `Esc-<`
  * aller à la fin : `Esc->`
  
## Modifier

* supprimer la dernière modification : `Ctrl-x u` (*undo*)
* effacer la fin de la ligne courante : `Ctrl-k` (*kill*)
* effacer la fin du mot courant : `Esc-d` (*delete*)
* effacer le caractère courant : `Ctrl-d` (*delete**)
* passer en majuscules la fin du mot courant : `Esc-u` (*uppercase*)
* passer en minuscules la fin du mot courant : `Esc-u` (*lowercase*)
* passer en majuscule la première lettre et en minuscules les
  suivantes : `Esc-c` (*capitalize*)
* copier/couper/coller :
  * copier : 
    * aller au début de la zone à copier, puis `Ctrl-espace`
	* aller à la fin de la zone à copier, puis `Esc-w`
  * couper : 
    * aller au début de la zone à couper, puis `Ctrl-espace`
	* aller à la fin de la zone à couper, puis `Ctrl-w`
  * coller : aller à l'endroit désiré, puis `Ctrl-y`

## Fichiers

* ouvrir : `Ctrl-x Ctrl-f` (*file*)
* sauvegarder : `Ctrl-x Ctrl-s` (*save*)
* sauvegarder sous : `Ctrl-x Ctrl-w` (*write*)
* chercher :
  * vers l'avant : `Ctrl-s` (*search*)
  * vers l'arrière : `Ctrl-r`

## Fenêtres et sous-fenêtres

* quitter : `Ctrl-x Ctrl-c`
* séparer en 2 :
  * horizontalement : `Ctrl-x 2`
  * verticalament : `Ctrl-c 3`
* supprimer la sous-fenêtre courante : `Ctrl-x 0`
* ne conserver que la sous-fenêtre courante : `Ctrl-x 1`
