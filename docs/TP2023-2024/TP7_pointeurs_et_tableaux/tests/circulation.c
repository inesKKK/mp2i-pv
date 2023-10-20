#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <wchar.h>
#include <locale.h>


/** frequence : la route est libre avec frequence 1/frequence
 * sortie : un entier entre 0 et 4 qui représente soit une portion de route libre, soit un type de véhicule
 */
uint8_t vehicule(int frequence){
    if(random()%frequence==0){
        return 0;
    } else {
        return (random()%4) + 1;
    }
}



/** route : état de la route
 * n : longueur de la route
 * sortie : affichage de la route
 */
void affiche(uint8_t *route, int n){
    //le type wint_t est hors programme
    wint_t voiture[] = {' ',(wint_t)128663, (wint_t)128665, (wint_t)128661, (wint_t)127949};
    //cette instruction est hors programme et permet l'affichage des caractères bizarres au-dessus;
    setlocale(LC_ALL, "");
    for(int i=0; i<n; i++){
        printf("%lc", voiture[route[i]]);
    }
    printf("\n");
}


void affichage(){
  int n = 60;
  int frequence = 2;
  //initialisation de la route et affichage du temps 0
  uint8_t *route = init(n, frequence);
  affiche(route, n);
  //afficher jusqu'au temps 30
  //a vous de jouer
}


void tests_question1(){
  uint8_t *test = init(15, 4);
  for(int i=0; i<15; i = i+1){
    assert(test[i]>=0 && test[i]<=4);
  }
  free(test);
}

void tests_question2(){
  uint8_t test[] = {0, 1, 2, 0, 0, 0, 3, 0, 4, 3, 2};
  uint8_t *test2 = next(test, 11, 3);
  assert(test2[0] == 1);
  assert(test2[1] == 0);
  assert(test2[2] == 2);
  assert(test2[3] == 0);
  assert(test2[4] == 0);
  assert(test2[5] == 3);
  assert(test2[6] == 0);
  assert(test2[7] == 4);
  assert(test2[8] == 0);
  assert(test2[9] == 3);
  assert(test2[10] == 2);
  free(test2);
}

void tests_question3(){
  affichage();
}


int main(void){
  tests_question1();
  //tests_question2(); //a decommenter
  //tests_question3(); //a decommenter
  return 0;
}
