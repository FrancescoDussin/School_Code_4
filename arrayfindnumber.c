//Francesco Dussin 4AI

/* Il processo padre genera un vettore, di dimensione MAXELEM,
di valori double casuali compresi tra ValMin e ValMax.

Il processo padre domanda l'elemento, che può essere ripetuto, da cercare.

Poi, il processo padre, domanda quanti figli generare (o decide in base ad una banale IA)
per effettuare una ricerca di elemento ripetuto su vettore.

Dopo fork opportuni ciascun figlio cerca, su elementi non ordinati,
nella sua porzione di vettore un elemento che potrebbe presentarsi piu' volte.

Nota: il figlio, trovata la corrispondenza, la stampa a video insieme alla relativa posizione.

L'ultimo figlio cerca fino in fondo, perche' non sempre la dimensione MAXELEM
é divisibile senza resto con il numero di figli.

Creare poi una funzione per generare array con elementi casuali senza ripetizioni.

Ritestare l'algoritmo di ricerca su array molto grandi,
confrontandolo anche con l'algoritmo di ricerca sequenziale con unico processo.

Consegnare un foglio elettronico con i datiàà rilevati e una veloce analisi degli stessi.
//END COMMENT SECTION */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define arraysize 100

int main(void) {

  int answer1;
  int sz;

  printf("Enter the size of array::");
  scanf("%d", &sz);

  int i;
  double randArray[sz];

  for(i = 0; i < sz; i++) {

    randArray[i] = rand() % 100;   //Generate number between 0 to 99
  }

  printf("\nElements of the array:");
  for(i = 0; i < sz; i++) {

    printf("\nElement number %d:%d", i + 1, randArray[i]);
  }

  printf("would you rather find a number or a char?");
  printf("1 = number || 0 = char");
  scanf("%d\n", &answer1);

  if(answer1 != 0 || answer1 != 1) {

    printf("answer1 is not equal to 0 || 1");
    scanf("%d\n", &answer1);
  }

  switch (answer1) ​{

      case 1: // number

      int answer2;

      printf("user or prefixed?");
      printf("user = array size from the user || coder = array size prefixed (100)");
      scanf("%d\n", &answer2);

      if(answer2 != "user" || answer2 != "coder") {

        printf("answer2 is not equal to user || coder");
        scanf("%d\n", &answer2);
      }

      switch (answer2) ​{

          case "user": // array size from the user



            break;

          case "coder": // array size prefixed (100)



            break;

      }

  break;

////////////////////////////////////////////////////////////////////////////////

  case 0: // char

      printf("user or prefixed?");
      printf("user = array size from the user || coder = array size prefixed (100)");
      scanf("%d\n", &answer2);

      if(answer2 != "user" || answer2 != "coder") {

        printf("answer2 is not equal to user || coder");
        scanf("%d\n", &answer2);
      }

      switch (answer2) ​{

          case "user": // array size from the user



            break;

          case "coder": // array size prefixed (100)



            break;

      }

    break;

  }
}

void printArray(int data[], int size) {

  int i;
  int temporary = 0;

  for(i = 0; i < size; i++) {

    temporary++;
    printf("%d\n", data[i]);
  }

  return;
}

/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

  int fd1[2]; //sum
  int fd_sub[2]; //subtract
  int fd_sum[2]; //fraction
  int fd4[2]; //power

  int sum;
  int sub;
  int fra;
  int power;

  int a,b,c,d;
  int g1,g2,g3,g4;

  printf("tell me a first number");
  printf("\n");
  scanf("%d", &a);
  printf("tell me a second number");
  printf("\n");
  scanf("%d", &b);
  printf("tell me a third number");
  printf("\n");
  scanf("%d", &c);
  printf("tell me a fourth number");
  printf("\n");
  scanf("%d", &d);

  pipe(fd1); //opening the pipe
  pipe(fd_sub); //opening the pipe
  pipe(fd_sum); //opening the pipe

  pid_t k1_fork;
  k1_fork = fork(); //forking the first child process

  pid_t k2_fork = 1;
  pid_t k3_fork = 1;


  if(k1_fork == 0) {

    k2_fork = fork(); //forking the first child process
  }

  if(k2_fork == 0) {

    k3_fork = fork(); //forking the second child process
  }

  if(k1_fork < 0) { //gives an error if it's different from 0

    printf("error 4");

    exit(4);
  }

  if(k2_fork < 0) { //gives an error if it's different from 0

    printf("error 8");

    exit(8);
  }

  if(k3_fork < 0) {

    printf("error 6");

    exit(6);
  }

  pid_t pid = getpid();

  if(k1_fork == 0 && k2_fork != 0 && k3_fork != 0) {

    sum = a + b;

    close(fd_sum[0]); //closing pipe reading mode
    write(fd_sum[1], &sum, sizeof(sum));

    exit(0);

  } else if(k2_fork == 0 && k3_fork != 0) {

    sub = c - d;

    close(fd_sub[0]); //closing pipe reading mode
    write(fd_sub[1], &sub, sizeof(sub));
    exit(0);

  } else if(k3_fork == 0) {

    close(fd_sum[1]);
    read(fd_sum[0], &sum, sizeof(sum));

    power = pow((double)sum, (double)a); //castin' the variables!!!! boom
    write(fd_sum[1], &power, sizeof(power));

    exit(0);

  } else {
    close(fd_sum[1]);
    read(fd_sum[0], &power, sizeof(power));
    close(fd_sub[1]);
    read(fd_sub[0], &sub, sizeof(sub));

    if(sub == 0) {
      printf("Cannot divide by zero\n");
      exit(2);
    }

    fra = power / sub;
    printf("Integer result:");
    printf("((%d + %d) ^ %d)/(%d - %d) = %d\n", a,b,a,c,d, fra);
    exit(0);
  }
}
*/
