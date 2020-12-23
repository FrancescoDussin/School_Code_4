//Francesco Dussin 4AI

/* //START COMMENT SECTION

Scomporre l'espressione: y=((a+b)^a))/(c-d)

facendo svolgfere le 3 diverse operazioni a 3 processi diversi.

a,b,c,d, sono interi inseriti da tastiera.
esempio
a = 3
b = 4
c = 5
d = 6

a (sum) --> a+b --> 3+4 e
b (power)--> sum^a --> 7^3 f
c (fraction)--> sum^a / subtract --> 7^3 / -1 g
d (subtract)--> c-d --> 5-6 h

//END COMMENT SECTION */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

  int fd1[2]; //sum
  int fd2[2]; //subtract
  int fd3[2]; //fraction
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

/*
  if(d == 0) {

      printf("erroroger");
      exit(1);
  }
*/
  pipe(fd1); //opening the pipe
  pipe(fd2); //opening the pipe
  pipe(fd3); //opening the pipe

  pid_t k1_fork;
  k1_fork = fork(); //forking the first child process

  pid_t k2_fork;
  pid_t k3_fork;


  if(k1_fork == 0) {

    k2_fork = fork(); //forking the first child process
  }

  if(k2_fork == 0) {

    k3_fork = fork(); //forking the first child process
  }

  if(k1_fork == -1) { //gives an error if it's different from 0

    printf("error 4");

    exit(4);
  }

  if(k2_fork == -1) { //gives an error if it's different from 0

    printf("error 6");

    exit(6);
  }

  if(k1_fork == 0) {

    printf("figlio 1");

    sum = a + b;

    close(fd1[0]); //closing pipe reading mode
    write(fd1[1], &sum, sizeof(sum));
    //(file descriptor - variable to be written - length)

    exit(0);

  } else if(k2_fork == 0) {

    printf("figlio 2");

    sub = c - d;

    close(fd2[0]); //closing pipe reading mode
    write(fd2[1], &sub, sizeof(sub));
    //(file descriptor - variable to be written - length)

    exit(0);

  } else if(k3_fork == 0) {

    printf("figlio 3");

    close(fd3[1]);
    read(fd3[0], &sum, sizeof(sum));

    //(double)sum; //casting
    power = pow((double)sum, (double)a);

    write(fd3[1], &power, sizeof(power));

    exit(0);

  } else {

    printf("padre");

    close(fd3[1]);
    read(fd3[0], &power, sizeof(power));
    close(fd2[1]);
    read(fd2[0], &sub, sizeof(sub));

    if(sub == 0) {

      printf("the equation cannot be resolved - divided by 0-");
      printf("\n");

      exit(2);
    }

    fra = power / sub;

    printf("%d", fra);

    exit(0);
  }
}

/*
  if(k1_fork == 0) {

    pid_t k2_fork;
    k2_fork = fork(); //forking the first child process
  }

  if(k2_fork == 0) {

    pid_t k3_fork;
    k3_fork = fork(); //forking the first child process
  }

  if(k1_fork == -1) { //gives an error if it's different from 0

    printf("error ez");

    exit(1);
  }

  if(k1_fork == 0) { //step son a

      sum = a + b;

      close(fd1[0]); //closing pipe reading mode
      write(fd1[1], sum, sizeof(sum));
      //(file descriptor - variable to be written - length)

      exit(0);
  } else { //step father

      close(fd1[1]);
      g1 = read(fd1[0], &g1, sizeof(sum));
      printf(g1);
  }

  if(k2_fork == 0) { //step son

      sub = c - d;

      close(fd[0]); //closing pipe reading mode
      write(fd[1], sub, sizeof(sub));
      //(file descriptor - variable to be written - length)

      exit(0);
  } else { //step father

      close(fd2[1]);
      g2 = read(fd2[0], &g2, sizeof(sub));
      printf(g2);
  }

  pid_t k2_fork();
  k2_fork = fork(); //forking the first child process

  if(k2_fork == -1) { //gives an error if it's different from 0

    printf("error ez");

    exit(1);
  }

  if(k2_fork == 0) { //step son

      sum = a+b;

      close(fd[0]); //closing pipe reading mode
      write(fd[1], sum, sizeof(sum));
      //(file descriptor - variable to be written - length)

      exit(0);
  } else { //step father

      close(fd[1]);
      g2 = read(fd[0], &g2, sizeof(sum));
      printf(g2);
  }
*/
