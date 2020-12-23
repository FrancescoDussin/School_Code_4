/*
Dussin Francesco 4AI
Creare un nodo, che oltre al puntatore all'elemento successivo, contenga delle informazioni rispetto ad un'automobile: nome modello, targa, anno immatricolazione, cilindrata.

Dovrà essere possibile:

1) riempire una lista di automobili;
2) stampare le automobili presenti nella lista;
3) contare quante automobili ci sono nella lista;
4) invertire l'ordine delle automobile.
*/

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
int List_Count(List head);
void List_Reverse(List head);

int main() {

    List head;

    int caffeine;

    //struct node_car gay;
/*
    //collegamento degli el.
    head = &n1;     //collego la testa con il primo nodo
    n1.next = &n2;  //il primo nodo lo collego al secondo
    n2.next = &n3;
    n3.next = NULL; //il 3° nodo rappresenta la coda che non punta a niente
*/

    //List_Add();
    List_Print(head);

    caffeine = List_Count(head);
    printf("%d", caffeine);

    return 0;
}

void List_Print(List head) { //struct node_car

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

int List_Count(List head) {

  int rogers = 0;
  List temp = head;

  while(temp != NULL) {

    rogers++;
    temp = temp -> next;
  }

  return rogers;
}

void List_Reverse(List head) {


}

//https://codeforwin.org/2015/09/c-program-to-insert-node-at-end-of-singly-linked-list.html
//https://www.programiz.com/c-programming/c-structures-pointers

/*

#include <stdio.h>
#include <stdlib.h>


/*Structure of a node
struct node {
    int data;          // Data
    struct node *next; // Address
}*head;


void createList(int n);
void insertNodeAtEnd(int data);
void displayList();


int main()
{
    int n, data;

    /*
     * Create a singly linked list of n nodes

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /*
     * Insert data at the end of the singly linked list

    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insertNodeAtEnd(data);

    printf("\nData in the list \n");
    displayList();

    return 0;
}

/*

 * Create a list of n nodes

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Reads data of node from the user

        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/*
 * Create a new node and inserts at the end of the linked list.

void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link the data part
        newNode->next = NULL;

        temp = head;

        // Traverse to the last node
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; // Link address part

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}


/*
 * Display entire list

void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}
*/
