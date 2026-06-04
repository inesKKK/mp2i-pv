struct labyrinthe {
  int largeur, hauteur;
  int entree, sortie;
  bool *mur_sous; // cases numerotees de 0 à largeur * hauteur - 1
  bool *mur_droite;
};
