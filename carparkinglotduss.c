#include <stdio.h>
#include <stdlib.h>

/*
Creare un nodo, che oltre al puntatore all'elemento successivo, contenga delle informazioni rispetto ad un'automobile: nome modello, targa, anno immatricolazione, cilindrata.

Dovrà essere possibile:

1) riempire una lista di automobili;
2) stampare le automobili presenti nella lista;
3) contare quante automobili ci sono nella lista;
4) invertire l'ordine delle automobile.
*/

void reverseOrder();
void carCounter();
void carPrinter();
void carKoomer();
void carPainter();
void crisRetard();

struct s_nodo {

  int info;
  struct s_nodo *next;
}s_nodo;

typedef struct s_nodo nodo;
typedef nodo *puntaNodo;

void stampaLista(puntaNodo lista) {

 while (lista != NULL) {

   printf("%4d ", lista->info);
   lista = lista->next;
 }
};

main() {

 int x;
 puntaNodo pTesta;
 puntaNodo pNodo;
 pTesta = NULL;
 pNodo = NULL;

 for (x=0; x<5; x++) {

   pNodo = malloc(sizeof(nodo));
   pNodo -> info = x + 1;
   pNodo -> next = pTesta;
   pTesta = pNodo;
 }

 printf("\n\n Visualizzo la lista\n");
 stampaLista(pTesta);
}

void reverseOrder() {


}

void carCounter() {


}

void carPrinter() {


}

void carKoomer() {


}

void carPainter() {


}

void crisRetard() {


}
