#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define ANIO 2019

// Estructura fecha
typedef struct date{
  int dia;
  int mes;
  int anio;
}Fecha;

// Estructura de un empleado
typedef struct student{
  char nombre[255];
  int edad;
  Fecha fecha;
}Alumno;

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int stdSize = 10;
  Alumno alumnos[stdSize];
  for (size_t i = 0; i < stdSize; i++) {
    printf("Nombre: ");
    scanf("%s", alumnos[i].nombre);
    alumnos[i].fecha.dia = 1 + rand()%31;
    alumnos[i].fecha.mes = 1 + rand()%12;
    alumnos[i].fecha.anio = 1980 + rand()%(2019 - 1980),
    alumnos[i].edad = ANIO - alumnos[i].fecha.anio;
  }
  for (size_t i = 0; i < stdSize; i++) {
    printf("----------------\n");
    printf("Nombre: %s\n", alumnos[i].nombre);
    printf("Fecha nacimiento: %d/%d/%d\n", alumnos[i].fecha.dia, alumnos[i].fecha.mes, alumnos[i].fecha.anio);
    printf("Edad: %d\n", alumnos[i].edad);
  }
  printf("----------------\n");
  printf("EO :v\n");
  return 0;
}
