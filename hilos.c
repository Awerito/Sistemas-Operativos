#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct datos {
  char *cadena;
  int x, y;
}parametro;

void gotoxy(int x, int y) {
  printf("\033[%d;%df", y, x);
}

void *funcion1(void *datos) {
  // char *cadena_hilo = (char *) datos;
  parametro *p = (parametro *) datos;
  for (size_t i = 0; i < strlen(p->cadena); i++) {
    fflush(stdout);
    gotoxy(p->x + i, p->y);
    printf("%c", p->cadena[i]);
  }
}

int main(int argc, char const *argv[]) {
  // char *cadena = "Hola Clase, k ase";
  parametro p1, p2, p3;
  pthread_t h1, h2, h3;

  p1.cadena = "Hola ";
  p1.x = 10;
  p1.y = 20;

  p2.cadena = "Clase, ";
  p2.x = 30;
  p2.y = 20;

  p3.cadena = "k ase!";
  p3.x = 40;
  p3.y = 20;

  pthread_create(&h1, NULL, funcion1, (void *) &p1);
  pthread_create(&h2, NULL, funcion1, (void *) &p2);
  pthread_create(&h3, NULL, funcion1, (void *) &p3);
  pthread_join(h1, NULL);
  pthread_join(h2, NULL);
  pthread_join(h3, NULL);
  printf("\n");
  return 0;
}
