struct liste {
  struct maillon *tete;
};

struct maillon {
  int val;
  struct maillon *suiv;
};

void initialise(struct liste *L);
void ajoute(struct liste *L, int v);
int longueur_recursif(struct liste *L);
int longueur_iteratif(struct liste *L);
void supprime_tete(struct liste *L);
void supprime_premiere_occurence_recursif(struct liste *L, int val);
void supprime_premiere_occurence_iteratif(struct liste *L, int val);
void supprime_toutes_occurences_recursif(struct liste *L, int val);
void supprime_dernier_recursif(struct liste *L);
void supprime_dernier_iteratif(struct liste *L);
void detruire_recursif(struct liste *L);
void detruire_iteratif(struct liste *L);
