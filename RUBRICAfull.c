#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <windows.h> //sleep


#define ROWS 10
#define COLS 6
#define LEN 128

/*

typedef struct {

    char cognome[256];
    char nome[256];
    char citta[256];
    char telefono[14];
    bool leva;

} Contatti;

*/

////////////////////////////////////////////////////////////////////////////////

void menu(int r, int c, char m[][c][LEN]);
void add(int r, int c, char m[][c][LEN]);
void delete(int r, int c, char m[][c][LEN]);
void modify(int r, int c, char m[][c][LEN]);
void block(int r, int c, char m[][c][LEN]);
void calling(int r, int c, char m[][c][LEN]);
void search(int r, int c, char m[][c][LEN]);
void visualizeinfo(int pos, int r, int c, char m[][c][LEN]);
void visualizeall(int r, int c, char m[][c][LEN]);
bool isemptyrow(int targetrow, int r, int c, char m[][c][LEN]);

////////////////////////////////////////////////////////////////////////////////

int main() {

  char m[ROWS][COLS][LEN] = {0};
  FILE *fp = fopen("rubrica.txt", "r+"); //r

  if(!fp) {

    printf("Enter a the number of the contact ex. 1..2..3: \n");

    exit(1);

  }

  char *line = NULL;
  size_t len = 0; //int len win fgets (getline legge fino alla fine della riga con 0 len.....fgets deve sapere quanto deve leggere!!! devi mettere un numero per fargli leggere tutto)
  int r = 0, c = 0, k = 0;
  int i = 0;

//https://riptutorial.com/c/example/8274/get-lines-from-a-file-using-getline--

  while(getline(&line, &len, fp) != -1) {

    //https://pubs.opengroup.org/onlinepubs/000095399/functions/fgets.html
    //getline restituisce numero di bytes letti

    c = 0;
    k = 0;

    for(i = 0; line[i] != 0; i++) {// '\0'

      if(line[i] == ';' || line[i] == '\n') {

        c++;
        k = 0;
        i++;

      } //end if

      m[r][c][k++] = line[i];

    } //end for cycle

    m[r][c][k-1] = '\0';
    r++;

  } //end while cycle

  menu(ROWS, COLS, m);

  fclose(fp);

  return 0;

} //end main

////////////////////////////////////////////////////////////////////////////////

void menu(int r, int c, char m[][c][LEN]) {

  int choice = 0;

  do{

    //V COMPLETED!!!
    //X STILL THINKIN' ABOUT IT!!!
    //XV IN THE PROCESS OF MAKIN' IT!!!

    printf("PRESS 0: ADD A CONTACT\n"); //0 V
    printf("PRESS 1: DELETE A CONTACT\n"); //1 XXXXX
    printf("PRESS 2: MODIFY A CONTACT\n"); //2 V
    printf("PRESS 3: BLOCK A CONTACT\n"); //3 V
    printf("PRESS 4: CALL A CONTACT\n"); //4 V
    printf("PRESS 5: SEARCH A CONTACT\n"); //5 V
    printf("PRESS 6: VISUALIZE CONTACT INFO\n"); //6 V
    printf("PRESS 7: VISUALIZE ALL CONTACTS\n"); //7 V
    printf("PRESS 8: SORT CONTACTS\n"); //8 V

    printf("\n"); //8

    scanf("%d", &choice);

    switch(choice) {

      case 0:

      add(r,c,m);
      //printrubrica(r,c,m);
      //ordina(r,c,m);

      break;

      case 1:

      delete(r,c,m);

      break;

      case 2:

      modify(r,c,m);

      break;

      case 3:

      block(r,c,m);

      break;

      case 4:

      calling(r, c, m);

      break;

      case 5:

      search(r,c,m);

      break;

      case 6:

      visualizeinfo(-1,r,c,m);

      break;

      case 7:

      visualizeall(r,c,m);

      break;

      case 8:

      sort(r,c,m);

      break;

    }

  }while(choice >= 0 && choice <= 8);

}

////////////////////////////////////////////////////////////////////////////////

  void add(int r, int c, char m[][c][LEN]) {

    //char o[][c][LEN]

      int i, j,characters;
      char newm[r+1][c][LEN];

      //memcpy(newm, m, sizeof(m));

      for (i = 0; i < r; i++) {

        for (j = 0; j < c; j++) {

          for (characters = 0; characters < LEN; characters++) {

            newm[i][j][characters] = m[i][j][characters];

          }

        }

      }

  //[LEN] == ULTIMO CARATTERE

      printf("NEW SURNAME\n");
      scanf(" %s", newm[r][0]);

      printf("NEW NAME\n");
      scanf(" %s", newm[r][1]);

      printf("NEW T.NUMBER\n");
      scanf(" %s", newm[r][2]);

      printf("NEW CITY\n");
      scanf(" %s", newm[r][3]);

      printf("NEW MILITARY DRAFT (LEVA MILITARE)\n");
      scanf( "%s", newm[r][4]);

      m = newm;

      visualizeall(r+1,c,m);

    }

////////////////////////////////////////////////////////////////////////////////

  void delete(int r, int c, char m[][c][LEN]) {



  }

////////////////////////////////////////////////////////////////////////////////

  void modify(int r, int c, char m[][c][LEN]) {

    char pointless;
    int answer;
    char temp[LEN] = {0};

    visualizeall(r,c,m);

    printf("which of these contacts would you like to modify\n");
    scanf(" %d", &answer); // " %d" cavi via uno spazio

      scanf("%c",&pointless);

          printf("NEW SURNAME\n");
          fgets(temp, LEN, stdin);

          if(temp[0] != '\n'){

            //DESTINATION---SOURCE
            strcpy(m[answer][0], temp);

          }

          printf("NEW NAME\n");
          fgets(temp, LEN, stdin);

          if(temp[0] != '\n'){

            //DESTINATION---SOURCE
            strcpy(m[answer][1], temp);

          }

          //leggi tutto finche non trovi un ()\n invio()
          printf("NEW T.NUMBER\n");
          fgets(temp, LEN, stdin);

          if(temp[0] != '\n'){

            //DESTINATION---SOURCE
            strcpy(m[answer][2], temp);

          }


          printf("NEW CITY\n");
          fgets(temp, LEN, stdin);

          if(temp[0] != '\n'){

            //DESTINATION---SOURCE
            strcpy(m[answer][3], temp);

          }


          printf("NEW MILITARY DRAFT (LEVA MILITARE)\n");
          fgets(temp, LEN, stdin);

          if(temp[0] != '\n'){

            //DESTINATION---SOURCE
            strcpy(m[answer][4], temp);

          }

      visualizeall(r,c,m);

  }

////////////////////////////////////////////////////////////////////////////////

  void block(int r, int c, char m[][c][LEN]) {

    //1 block true
    //0 block false
    int number;

      visualizeall(r,c,m);

      printf("Enter the number of the contact\n");
      scanf("%d", &number);

      strcpy(m[number][5], "1");

      printf("You blocked\n: %d,%s \n", number, m[number][2]); //[0/LEN]

      //if(m[number][2] )

    }

////////////////////////////////////////////////////////////////////////////////

  void calling(int r, int c, char m[][c][LEN]) {

    int number;

      printf("Enter the number of the contact:\n");
      scanf("%d", &number);

      //sleep(2);
      printf("You are calling: %s \n", m[number][2]); //[0/LEN]

  }

////////////////////////////////////////////////////////////////////////////////

  void search(int r, int c, char m[][c][LEN]) {

    int i = 0, j = 0;
    char keyword[LEN] = {0};

      printf("Enter the key word of the contact you want to search:\n");
      scanf(" %s", keyword);

      //sleep(2);
      printf("You looked for: %s \n", keyword); //[0/LEN]

      for(i = 0; i < r; i++) {

        for(j = 0; j < c; j++) {

          if (!isemptyrow(i,r,c,m) && strcmp(m[i][j],keyword) == 0 ) {

            visualizeinfo(i,r,c,m);

          }


        }

      }



  }

////////////////////////////////////////////////////////////////////////////////

  void visualizeinfo(int pos, int r, int c, char m[][c][LEN]) {

    int j = 0;

    if(pos < 0){
      printf("Enter the number of the contact you want to visualize\n");
      scanf(" %d", &pos);
    }

    for(j = 0; j < c; j++) {

      printf("%s | ", m[pos][j]);

    }

    printf("\n");

  }

////////////////////////////////////////////////////////////////////////////////

  void visualizeall(int r, int c, char m[][c][LEN]) {

      int i = 0, j = 0;

      for(i = 0; i < r && !isemptyrow(i, r, c, m); i++) {

        printf("%d)" ,i );
        printf("| ");

        for(j = 0; j < c; j++) {

          printf("%s | ", m[i][j]);

        }

        printf("\n");

      }

      printf("\n");

  }

////////////////////////////////////////////////////////////////////////////////

  void sort(int r, int c, char m[][c][LEN]) {

    int j = 0;
    int i = 0;
    char temp[] = {0};
    char arr[LEN];

    for (int j = 0; j < m[r][0]; j++) {

        for (i = j+1; i < m[r][c]; i++) {

            if (strcmp(arr[j], arr[i]) > 0) {

                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[i]);
                strcpy(arr[i], temp);

            }

        }

      }

      visualizeall(r,c,m);

    }

////////////////////////////////////////////////////////////////////////////////

  bool isemptyrow(int targetrow, int r, int c, char m[][c][LEN]) {

    bool isempty = true;
    int j = 0;

    for(j = 0; isempty && j < c; j++) {

      if(m[targetrow][j][0] != 0) {

        isempty = false;

      }

    }

    return isempty;

  }


  /*

  extra crappy

  void menu(int r, int c, char m[r][c][LEN]) {

  int a = 8;
  int b = 1;
  int space = 256;

  char roger[b][a][space] = {{"ADD A CONTACT"},
                            {"delete A CONTACT"},
                            {"MODIFY A CONTACT"},
                            {"BLOCK A CONTACT"},
                            {"CALL A CONTACT"},
                            {"SEARCH A CONTACT"},
                            {"VISUALIZE CONTACT INFO"},
                            {"VISUALIZE ALL CONTACTS INFO"}};

    int choice = 0;
    int count = 9;

    printf("\n");
    for (size_t i = 0; i < count; i++) {

      printf("%d)",i + roger[i]);

    }

    switch(choice) {

      case 0:

      break;

    }

  }

  */
