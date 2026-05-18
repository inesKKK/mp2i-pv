Oral blanc -- Manipulation d'Images en C
---

(énoncé de TP CCMP : [archive](https://concoursminesponts.fr/wp-content/uploads/2025/12/sujet_images-1.zip))

durée : 3h  (*Nota : le vrai oral CCMP dure 3h30*)

[énoncé](sujet_images/sujet.pdf)

Fichiers contenant le code de l'énoncé:

* pour la compilation : [Makefile](sujet_images/Makefile)
* fichier d'en-tête : [graphique.h](sujet_images/graphique.h)
* fichier à compléter : [image.c](sujet_images/image.c)

Images de tests:
* [image0.jpg](sujet_images/images/0.jpg)
* [image1.jpg](sujet_images/images/1.jpg)
* [image2.jpg](sujet_images/images/2.jpg)
* [image3.jpg](sujet_images/images/3.jpg)
* [image4.jpg](sujet_images/images/4.jpg)
* [image5.jpg](sujet_images/images/5.jpg)
* [image6.jpg](sujet_images/images/6.jpg)
* [image7.jpg](sujet_images/images/7.jpg)
* [image8.jpg](sujet_images/images/8.jpg)
* [image9.jpg](sujet_images/images/9.jpg)


[documentation `C`/`OCaml`](https://devdocs.io/)


Fonction alternative si l'affichage est incorrect :
```C
IMG_SaveJPG(charge_image("image.jpg"), "fichier.jpg", 50);
```
permet de sauvegarder l'image donnée en premier argument dans le
fichier dont le nom est donné en deuxième argument (le troisième
argument concerne la qualité de la sauvegarde). Vous pouvez ensuite
utiliser un logiciel de visualisation d'images (par exemple votre
navigateur web).
