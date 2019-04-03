#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#define TOTAL 1

// dumpdata
const char *nombres[10] = {"Diego","Vistor","Cba", "Alvaro", "Juan", "Pedro", "Alverto", "Rodrigo", "Ricardo", "Ignacio"};
const char *apellidos[10] = {"Muñoz","Lillo","Vidal", "Cárdena", "Bodoque", "Ramos", "Maturana", "Stuardo", "Milos", "Fabia"};
const char *estadios[5] = {"Estadio1", "Estadio2", "Estadio3", "Estadio4", "Estadio5"};
const char *equipos[5] = {"Equipo1", "Equipo2", "Equipo3", "Equipo4", "Equipo5"};

// dateGame
typedef struct d{
  int day, month, year;
}dateGame;

// refereeGame
typedef struct r{
  char *name;
}refereeGame;

// playerGame
typedef struct p{
  char *firtName, *lastName;
  int number, goals, asists, passes, shorcuts, age;
  dateGame birth;
}playerGame;

// teamGame
typedef struct t{
  char *name, *director;
  float prom;
  playerGame players[11];
  refereeGame referees[4];
}teamGame;

// matchGame
typedef struct m{
  char *stadium;
  dateGame dayMatch;
  teamGame team1, team2;
}matchGame;

void swap(playerGame *a, playerGame *b) {
  playerGame aux = *a;
  *a = *b;
  *b = aux;
}

void quicksort(playerGame arr[], int l, int r) {
  if(l >= r) {
    return;
  }
  int pivot = arr[r].number;
  int cnt = l;
  for (int i = l; i <= r; i++) {
    if (arr[i].number <= pivot) {
      swap(&arr[cnt], &arr[i]);
      cnt++;
    }
  }
  quicksort(arr, l, cnt-2);
  quicksort(arr, cnt, r);
}

void bubbleAlphabet(playerGame jugador[]) {
	playerGame aux;
	for(int i=0; i<11; i++) {
		for(int j=0; j<11; j++) {
			if(jugador[i].lastName[0] < jugador[j].lastName[0]) {
				swap(&jugador[i], &jugador[j]);
			}
		}
	}
}

void autoFillMatches(matchGame partidos[]) {
  for (size_t i = 0; i < TOTAL; i++) {
    partidos[i].stadium = malloc(10);
    strcpy(partidos[i].stadium, estadios[rand()%6]);
    partidos[i].dayMatch.day = rand()%32;
    partidos[i].dayMatch.month = rand()%13;
    partidos[i].dayMatch.year = rand()%29 + 1990;
    partidos[i].team1.name = malloc(10);
    strcpy(partidos[i].team1.name, equipos[rand()%6]);
    partidos[i].team2.name = malloc(10);
    strcpy(partidos[i].team2.name, equipos[rand()%6]);
    partidos[i].team1.director = malloc(10);
    strcpy(partidos[i].team1.director, nombres[rand()%6]);
    partidos[i].team2.director = malloc(10);
    strcpy(partidos[i].team2.director, nombres[rand()%6]);
    int sum1 = 0, sum2 = 0;
    for (size_t j = 0; j < 11; j++) {
      partidos[i].team1.players[j].firtName = malloc(10);
      strcpy(partidos[i].team1.players[j].firtName, nombres[rand()%6]);
      partidos[i].team1.players[j].lastName = malloc(10);
      strcpy(partidos[i].team1.players[j].lastName, apellidos[rand()%6]);
      partidos[i].team1.players[j].number = rand()%40;
      partidos[i].team1.players[j].goals = rand()%40;
      partidos[i].team1.players[j].asists = rand()%40;
      partidos[i].team1.players[j].passes = rand()%40;
      partidos[i].team1.players[j].shorcuts = rand()%40;
      partidos[i].team1.players[j].birth.day = rand()%32;
      partidos[i].team1.players[j].birth.month = rand()%13;
      partidos[i].team1.players[j].birth.year = rand()%10 + 1990;
      partidos[i].team1.players[j].age = 2019 - partidos[i].team1.players[j].birth.year;
      sum1 += partidos[i].team1.players[j].age;

      partidos[i].team2.players[j].firtName = malloc(10);
      strcpy(partidos[i].team2.players[j].firtName, nombres[rand()%6]);
      partidos[i].team2.players[j].lastName = malloc(10);
      strcpy(partidos[i].team2.players[j].lastName, apellidos[rand()%6]);
      partidos[i].team2.players[j].number = rand()%40;
      partidos[i].team2.players[j].goals = rand()%40;
      partidos[i].team2.players[j].asists = rand()%40;
      partidos[i].team2.players[j].passes = rand()%40;
      partidos[i].team2.players[j].shorcuts = rand()%40;
      partidos[i].team2.players[j].birth.day = rand()%32;
      partidos[i].team2.players[j].birth.month = rand()%13;
      partidos[i].team2.players[j].birth.year = rand()%10 + 1990;
      partidos[i].team2.players[j].age = 2019 - partidos[i].team2.players[j].birth.year;
      sum2 += partidos[i].team2.players[j].age;
    }
    partidos[i].team1.prom = sum1 / 11;
    partidos[i].team2.prom = sum2 / 11;
    for (size_t j = 0; j < 4; j++) {
      partidos[i].team1.referees->name = malloc(10);
      strcpy(partidos[i].team1.referees->name, nombres[rand()%6]);
      partidos[i].team2.referees->name = malloc(10);
      strcpy(partidos[i].team2.referees->name, nombres[rand()%6]);
    }
  }
}

void showMatches(matchGame partidos[]) {
  for (size_t i = 0; i < TOTAL; i++) {
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Estadio: %s\n", partidos[i].stadium);
    printf("Fecha: %d/%d/%d\n", partidos[i].dayMatch.day, partidos[i].dayMatch.month, partidos[i].dayMatch.year);
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%s\t\t\t|número\t|goles\t|edad\t\t|%s\t\t|número\t|goles\t|edad\n", partidos[i].team1.name, partidos[i].team2.name);
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    for (size_t j = 0; j < 11; j++) {
      printf("%s %s\t\t|%d\t|%d\t|%d\t\t|%s %s\t\t|%d\t|%d\t|%d\n", partidos[i].team1.players[j].firtName,
      partidos[i].team1.players[j].lastName,
      partidos[i].team1.players[j].number,
      partidos[i].team1.players[j].goals,
      partidos[i].team1.players[j].age,
      partidos[i].team2.players[j].firtName,
      partidos[i].team2.players[j].lastName,
      partidos[i].team2.players[j].number,
      partidos[i].team2.players[j].goals,
      partidos[i].team2.players[j].age);
    }
    printf("Promedio\t\t\t\t|%.2f\t\t|Promedio\t\t\t\t|%.2f\n", partidos[i].team1.prom, partidos[i].team2.prom);
  }
  printf("------------------------------------------------------------------------------------------------------------------------------\n");
}

float promedio(playerGame jugadores[]) {
  int suma = 0;
  for (size_t i = 0; i < 11; i++) {
    suma += jugadores[i].age;
  }
  return (float)suma/11;
}

void dataGame(matchGame partidos[]) {
  int maxGolID, teamMax, teamMin, teamGoal;
  int min, max, minID, maxID, maxGol;
  for (size_t i = 0; i < TOTAL; i++) {
    min = 40;
    max = 0;
    maxGol = 0;
    for (size_t j = 0; j < 11; j++) {
      if (min > partidos[i].team1.players[j].age) {
        min = partidos[i].team1.players[j].age;
        minID = j;
        teamMin = 1;
      }
      if (min > partidos[i].team2.players[j].age) {
        min = partidos[i].team2.players[j].age;
        minID = j;
        teamMin = 2;
      }
      if (max < partidos[i].team1.players[j].age) {
        max = partidos[i].team1.players[j].age;
        maxID = j;
        teamMax = 1;
      }
      if (max < partidos[i].team2.players[j].age) {
        max = partidos[i].team2.players[j].age;
        maxID = j;
        teamMax = 2;
      }

      if (maxGol < partidos[i].team1.players[j].goals) {
        maxGol = partidos[i].team1.players[j].goals;
        maxGolID = j;
        teamGoal = 1;
      }
      if (maxGol < partidos[i].team2.players[j].goals) {
        maxGol = partidos[i].team2.players[j].goals;
        maxGolID = j;
        teamGoal = 2;
      }
    }
    if (teamMin == 1) {
      printf("Jugador más joven: %s %s\n", partidos[i].team1.players[minID].firtName, partidos[i].team1.players[minID].lastName);
    } else {
      printf("Jugador más joven: %s %s\n", partidos[i].team2.players[minID].firtName, partidos[i].team2.players[minID].lastName);
    }
    if (teamMax == 1) {
      printf("Jugador más viejo: %s %s\n", partidos[i].team1.players[maxID].firtName, partidos[i].team1.players[maxID].lastName);
    } else {
      printf("Jugador más viejo: %s %s\n", partidos[i].team2.players[maxID].firtName, partidos[i].team2.players[maxID].lastName);
    }
    if (teamGoal == 1) {
      printf("Jugador con más goles: %s %s\n", partidos[i].team1.players[maxGolID].firtName, partidos[i].team1.players[maxGolID].lastName);
    } else {
      printf("Jugador con más goles: %s %s\n", partidos[i].team2.players[maxGolID].firtName, partidos[i].team2.players[maxGolID].lastName);
    }
  }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  matchGame partidos[TOTAL];

  autoFillMatches(partidos);
  showMatches(partidos);

  printf("\n");
  printf("\n");
  printf("Datos\n");
  dataGame(partidos);

  printf("\n");
  printf("\n");
  printf("Tablas ordenadas por número\n");
  for (size_t i = 0; i < TOTAL; i++) {
    int n = sizeof(partidos[i].team1.players) / sizeof(partidos[i].team1.players[0]);
    quicksort(partidos[i].team1.players, 0, n-1);
  }
  for (size_t i = 0; i < TOTAL; i++) {
    int n = sizeof(partidos[i].team2.players) / sizeof(partidos[i].team2.players[0]);
    quicksort(partidos[i].team2.players, 0, n-1);
  }
  showMatches(partidos);

  printf("\n");
  printf("\n");
  printf("Tablas ordenadas por apellidos\n");
  for (size_t i = 0; i < TOTAL; i++) {
    bubbleAlphabet(partidos[i].team1.players);
  }
  for (size_t i = 0; i < TOTAL; i++) {
    bubbleAlphabet(partidos[i].team2.players);
  }
  showMatches(partidos);

  return 0;
}
