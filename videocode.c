#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define bigness 500

typedef struct car {

    char model[bigness];
    char licenceplate[bigness];
    int carregistrationyear;
    int engine;
}car;

//typedef per non dover scrivere ogni volta struct nodo,  (creo la variabile di tipo nodo_lista)
typedef struct car node_car;
//typedef link *next_el; //puntatore ad un elemento dello stesso tipo

typedef struct node {

    struct node *next;
    struct car *vehicle;
}node;

//typedef per non dover scrivere ogni volta struct nodo,  (creo la variabile di tipo nodo_lista)
typedef node *List; // se scrivo list è l'equivalente di node*
//typedef link *next_el; //puntatore ad un elemento dello stesso tipo

void List_Print(List head);
void List_Add(List head);

int main() {

    List head;
/*
    //collegamento degli el.
    head = &n1;     //collego la testa con il primo nodo
    n1.next = &n2;  //il primo nodo lo collego al secondo
    n2.next = &n3;
    n3.next = NULL; //il 3° nodo rappresenta la coda che non punta a niente
*/

    //List_Add();
    //List_Print();
    printf("222\n");

    return 0;
}

void List_Print(List head) {

    List temp = head;

    while (temp != NULL) {

        printf("%d", temp -> vehicle -> model);
        printf("%d", temp -> vehicle -> licenceplate);
        printf("%d", temp -> vehicle -> carregistrationyear);
        printf("%d", temp -> vehicle -> engine);

        temp = temp -> next; // cosi temp 1-> [ ] 2-> [ ] punterà al 2
    }
}

void List_Add(List head) {

  List temp = head;

  while (temp != NULL) {

      temp = temp -> next; // cosi temp 1-> [ ] 2-> [ ] punterà al 2
  }

  //quante celle vuoi dare all'array
  List newtemp = calloc(1, sizeof(node));
  newtemp -> vehicle = calloc(1, sizeof(node_car));
  printf("\n inject a new model:");
  scanf("%s", newtemp-> vehicle -> model);
  printf("\n inject a new licenceplate:");
  scanf("%s", newtemp -> vehicle -> licenceplate);
  printf("\n inject a new carregistrationyear:");
  scanf("%d", newtemp -> vehicle -> carregistrationyear);
  printf("\n inject a new engine:");
  scanf("%d", newtemp -> vehicle -> engine);

  temp -> next = newtemp; //per aggiungere new temp all'ultima posizine di temp
}
