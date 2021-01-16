/*

Dussin Francesco 4Ai 1/11/2020

Implementare in linguaggio C una lista (bidirezionale) di animali dello zoo,
utilizzare la struct del file zoo.c:

il programma deve prevedere le seguenti operazioni

- Inserire un  nuovo animale in testa o in coda

- stampare gli elementi della lista

- cancellare un animale

--------------------------------------------------------------------------------

scrivere un programma in C per gestire una lista double linked

in particolare deve essere posssibile:
inserire in testa
inserire in coda
stampa lista nell'ordine di inserimento dei dati
stampa al contrario
cercare e cancellare elemento qualsiasi

*/

/*

in a doubly linked lists each node has multiple references...
one pointing to the next node and one to the previous
 _  _  _
|_||_||_| 1-2-3
1:prev reference
2:data inside the node
3:next reference

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define massive 100

////////////////////////////////////////////////////////////////////////////////

typedef struct zoo {

  char animal1[massive];
  char animal2[massive];
  char animal3[massive];

  struct zoo *next;
  struct zoo *prev;
  struct zoo *current;
}zoo;

typedef struct zoo *List;

void List_Print(List head); // v
void List_PrintReverse(List head); // v
void List_Count(List head); // v
void List_InsertHead(List *head); // v
void List_InsertTail(List *head); // v
void List_InsertPosition(List *head); // v
List List_GetNewNode(); // v
void List_Delete(List *head); // v
void List_FindElement(List head, char element[]); // v
void List_RecursivePrint(List head); // x
void List_RecursiveFindElement(List head, char element[]);
//void List_PrintNode(List head) // x

////////////////////////////////////////////////////////////////////////////////

int main() {

  List head = NULL;

  char roger[massive];
/*
  int balls;
  printf("\n inject a new model:");
  scanf("%d", balls);
*/

  List_InsertHead(&head);

  List_RecursivePrint(head);

  printf("\n which elements would you like to find in the list?\n");
  scanf("%s", &roger);

  List_RecursiveFindElement(head, roger);
  /*
  List_Print(head);
  List_Count(head);
  List_PrintReverse(head);

  List_InsertTail(&head);
  List_Print(head);
  List_Count(head);
  List_PrintReverse(head);

  List_InsertPosition(&head);
  List_Print(head);
  List_PrintReverse(head);

  List_Delete(&head);
  List_Print(head);
  List_PrintReverse(head);

  List_FindElement(head);
  List_Print(head);
  */
}

////////////////////////////////////////////////////////////////////////////////

void List_InsertPosition(List *head) {

  List temp = NULL;
  List newtemp = NULL;

  int ncycle, xposition;
  printf("\n POSITION number of animals\n");
  scanf("%d", &ncycle);

  printf("\n insert position\n");
  printf("\n ex: 0 --> first, 1 --> second\n");
  scanf("%d", &xposition);

  int i, j;
  for(i = 0; i < ncycle; i++) {

    temp = *head;
    if(xposition == 0) {

      List_InsertHead(head);
    } else {

      newtemp = List_GetNewNode();

      for(j = 0; j < xposition; j++) {

        if (temp != NULL) { //  && temp -> prev == NULL

          temp = temp -> next;
        }
      }

      newtemp -> prev = temp -> prev;
      newtemp -> prev -> next = newtemp;
      newtemp -> next = temp;
      temp -> prev = newtemp;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_InsertHead(List *head) {

  List temp = *head;
  List newtemp = NULL;

  int ncycle;
  printf("\n HEAD number of animals\n");
  scanf("%d", &ncycle);

  int i;
  for(i = 0; i < ncycle; i++) {

    newtemp = List_GetNewNode();

    if (temp != NULL) { //  && temp -> prev == NULL

      newtemp -> next = temp;
      temp -> prev = newtemp;
    }

    temp = newtemp;
  }

  *head = temp;
}

////////////////////////////////////////////////////////////////////////////////

List List_GetNewNode() {

  List newtemp = calloc(1, sizeof(zoo)); // not yet linked to the list

  printf("\n first animal:");
  scanf("%s", newtemp-> animal1);
  printf("%s", newtemp-> animal1);

  printf("\n second animal:");
  scanf("%s", newtemp-> animal2);
  printf("%s", newtemp-> animal2);

  printf("\n third animal:");
  scanf("%s", newtemp-> animal3);
  printf("%s", newtemp-> animal3);

  return newtemp;
}

////////////////////////////////////////////////////////////////////////////////

void List_InsertTail(List *head) {

  List temp = *head;
  List newtemp = NULL;

  int ncycle;
  printf("\n TAIL number of animals\n");
  scanf("%d", &ncycle);

  int i;
  for(i = 0; i < ncycle; i++) {
/*
    if(temp == NULL) {

      temp = calloc(1,sizeof(zoo));
    }
*/
    while (temp != NULL && temp -> next != NULL) {

      //printf("%p", temp);
      temp = temp -> next;
    }

    newtemp = List_GetNewNode();

    temp -> next = newtemp;
    newtemp -> prev = temp;

    temp = newtemp;
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_Print(List head) {

  List temp = head;

  int count = 0;

  while(temp != NULL) {

    count++;

    printf("\n-------NORMAL PRINTING START NODE %d [%p]<--[%p] -------\n", count, temp -> prev, temp);

    printf("%s\n", temp-> animal1);
    printf("%s\n", temp-> animal2);
    printf("%s\n", temp-> animal3);

    printf("-------NORMAL PRINTING END NODE %d-------\n", count);

    temp = temp -> next;
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_RecursivePrint(List head) {

  List temp = head;

  if(temp == NULL) {

    return;
  } else {

    printf("\n\n%s <-- first animal\n", temp -> animal1);
    printf("\n%s <-- second animal\n", temp -> animal2);
    printf("\n%s <-- third animal\n", temp -> animal3);
    printf("\n");

    List_RecursivePrint(temp -> next); // return omissible
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_PrintReverse(List head) {

  List temp = head;

  int count = 0;

  while(temp -> next != NULL) {

    temp = temp -> next;
  }

  while(temp != NULL) {

    count++;

    printf("\n-------REVERSE PRINTING START NODE %d -- [%p] <-- [%p]\n", count, temp -> prev, temp);

    printf("%s\n", temp -> animal1);
    printf("%s\n", temp -> animal2);
    printf("%s\n", temp -> animal3);

    printf("-------REVERSE PRINTING END NODE %d------\n", count);

    temp = temp -> prev;
  }

}

////////////////////////////////////////////////////////////////////////////////

void List_Count(List head) {

  int count = 0;
  List temp = head;

  while (temp != NULL) {

    count++;
    temp = temp -> next;
  }

  if(count < 3) {

    printf("\nnumber of NODES after using HEAD: %d\n", count);
  } else {
    printf("\nnumber of NODES after using TAIL: %d\n", count);
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_Delete(List *head) { // List List_Delete(List *head) {}

  List temp = *head;
  int ask;
  int i;
  List newtemp = temp -> next;

  printf("\n which elements would you like to delete from the list?\n");
  printf("\n ex: 0 --> deletes the first node, 1 --> second one ...etc...\n");
  scanf("%d", &ask);

//  while(temp != NULL) {

  for(i = 0; i < ask; i++) {

      temp = temp -> next;
  }

  if(temp -> prev == NULL) {

    newtemp -> prev = NULL;
    free(temp);

    *head = newtemp;
  } else if(temp -> next == NULL) {

    newtemp = temp -> prev;
    free(temp);

    *head = newtemp;
  }

//
    //List newtempp = temp -> prev;
    //List newtempn = temp -> next;
//

    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;

    free(temp);
//  }
}

////////////////////////////////////////////////////////////////////////////////

void List_RecursiveFindElement(List head, char element[massive]) {

  printf("a");

//  List temp = head;

  if(head == NULL || head -> animal1 == element || head -> animal2 == element || head -> animal3 == element) {

    return;
  } else {

      if (head -> animal1 == element || head -> animal2 == element || temp -> animal3 == element) {

        printf("\n element found \n");
      }

    List_RecursiveFindElement(head -> next, element);
  }
}

////////////////////////////////////////////////////////////////////////////////

void List_FindElement(List head, char element[]) {

  List temp = head;

  if(head == NULL) {

   printf("the list is empty");
   return;
}
/*
  char element1[massive] = temp -> animal1;
  char element2[massive] = temp -> animal2;
  char element3[massive] = temp -> animal3;
*/
  char element1[massive];
  char element2[massive];
  char element3[massive];

  int i;
  char ask[massive];
  int counter = 0;

  printf("\n which elements would you like to find in the list?\n");
  scanf("%s", &ask);

    while (temp != NULL) {

      counter++;
/*
      element1 = strcpm(ask, temp -> animal1);
      element2 = strcpm(ask, temp -> animal2);
      element3 = strcpm(ask, temp -> animal3);
*/
      if(temp -> animal1 == ask || temp -> animal2 == ask || temp -> animal3 == ask) {

          printf("\n %d element found\n", ask);
      }

      temp = temp -> next;
    }
  //return ask;
}

////////////////////////////////////////////////////////////////////////////////
/*
// INVOLUNTARY List_NodePrint(List head) {

void List_Delete(List *head) { // List List_Delete(List *head) {}

  List temp = *head;
  int ask;
  int i;

  printf("\n which elements would you like to delete from the list?\n");
  printf("\n ex: 1 --> deletes the first node, 2 --> second one\n");
  scanf("%d", &ask);

  while(temp != NULL) {

    for(i = 0; i < ask; i++) {

      temp -> next = NULL;
      temp -> prev = NULL;
    }

    temp = temp -> next;
  }
}
*/
