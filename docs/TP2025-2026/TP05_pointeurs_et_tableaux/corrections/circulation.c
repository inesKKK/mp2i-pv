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


uint8_t *init(int n, int frequence){
    uint8_t *ligne = (uint8_t *)malloc(n*sizeof(uint8_t));
    for(int i=0; i<n; i = i+1){
        ligne[i] = vehicule(frequence);
    }
    return ligne;
}

uint8_t *next(uint8_t *ligne, int n, int frequence){
    uint8_t *suiv = (uint8_t *)malloc(n*sizeof(uint8_t));
    suiv[0] = ligne[1];
    for(int i=1; i<n; i = i+1){
        if(ligne[i]==0){
            if(i+1<n){
                suiv[i] = ligne[i+1];
            } else {
                suiv[i] = vehicule(frequence);
            }
        } else {
            if(i==1 || ligne[i-1] == 0){
                suiv[i] = 0;
            } else {
                suiv[i] = ligne[i];
            }
        }
    }

    return suiv;
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
  int n = 60;
  int frequence = 2;
  //initialisation de la route et affichage du temps 0
  uint8_t *route = init(n, frequence);
  affiche(route, n);
  //afficher jusqu'au temps 30
  ///BEGIN SOLUTION
  for(int i=0; i<30; i = i+1){
    uint8_t *tmp = route;
    route = next(route, n, frequence);
    free(tmp);
    affiche(route, n);
  }
  ///END SOLUTION
}

int main(void){
  tests_question1();
  tests_question2();
  tests_question3();
  return 0;
}
