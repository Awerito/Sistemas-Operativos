#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct wheel{
  float diameter;
  char weather[255];
};

struct motor{
  float capacity;
  char fuel[255];
};

struct vehicle{
  char name[255];
  char model[255];
  int serialNumber;
  int doors;
  int year;
  struct wheel wheels;
  struct motor motors;
};

struct vehicle setVehicle() {
  struct vehicle car;
  printf("Engrese marca: ");
  scanf("%s", car.name);
  printf("Ingrese modelo: ");
  scanf("%s", car.model);
  printf("Año: ");
  scanf("%d", &car.year);
  car.serialNumber = rand();
  printf("Número de puestas: ");
  scanf("%d", &car.doors);
  printf("Tipo de ruedas: ");
  scanf("%s", car.wheels.weather);
  car.wheels.diameter = rand()%30 + 60;
  printf("Cilindrada: ");
  scanf("%f", &car.motors.capacity);
  printf("Combustible: ");
  scanf("%s", car.motors.fuel);

  return car;
}

void showVehicle(struct vehicle car) {
  printf("---------------------\n");
  printf("Auto: %s %s %d puertas, %d\n", car.name, car.model, car.doors, car.year);
  printf("Serial: %d\n", car.serialNumber);
  printf("Ruedas para %s, %d cm\n", car.wheels.weather, car.wheels.diameter);
  printf("Motor: %f lt, %s\n", car.motors.capacity, car.motors.fuel);
  printf("---------------------\n");
}

void uName(struct vehicle car, char name[]) {
  car.name =
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  struct vehicle autito;
  autito = setVehicle();
  showVehicle(autito);

  return 0;
}
