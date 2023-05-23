type maillon = {
    mutable donnee : int;
    mutable prec : maillon option;
    mutable suiv : maillon option;
  }

type liste_chainee = {
    mutable debut : maillon option;
    mutable fin : maillon option
  }
