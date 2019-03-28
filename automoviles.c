#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define TOTAL 6

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

struct vehicle setVehicle(int number) {
  struct vehicle car;
  car.serialNumber = number;
  printf("Ingrese marca: ");
  scanf("%s", car.name);
  printf("Ingrese modelo: ");
  scanf("%s", car.model);
  printf("Año: ");
  scanf("%d", &car.year);
  printf("Número de puertas: ");
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
  printf("---------------------------------------\n");
  printf("Auto: %s %s %d puertas, %d\n", car.name, car.model, car.doors, car.year);
  printf("Serial: %d\n", car.serialNumber);
  printf("Ruedas para %s, %f cm\n", car.wheels.weather, car.wheels.diameter);
  printf("Motor: %f lt, %s\n", car.motors.capacity, car.motors.fuel);
  printf("---------------------------------------\n");
}

int strVStr(char str1[], char str2[]) {
  for (size_t i = 0; str1[i]!='\0'; i++) {
    if (str1[i]!=str2[i]) {
      return 0;
    }
  }

	return 1;
}

void swap(struct vehicle *a, struct vehicle *b) {
  struct vehicle aux = *a;
  *a = *b;
  *b = aux;
}

void quicksort(struct vehicle arr[], int l, int r) {
  if(l >= r) {
    return;
  }
  int pivot = arr[r].year;
  int cnt = l;
  for (int i = l; i <= r; i++) {
    if (arr[i].year <= pivot) {
      swap(&arr[cnt], &arr[i]);
      cnt++;
    }
  }
  quicksort(arr, l, cnt-2);
  quicksort(arr, cnt, r);
}

void bubbleAlphabet(struct vehicle car[], int total) {
	struct vehicle aux;
	for(int i=0; i<total; i++) {
		for(int j=0; j<total; j++) {
			if(car[i].model[0] < car[j].model[0]) {
				swap(&car[i], &car[j]);
			}
		}
	}
}

struct vehicle change(struct vehicle car, char value[]) {
  struct vehicle newCar = car;
  if (strVStr(value,"marca")) {
    printf("Ingrese marca: ");
    scanf("%s", newCar.name);
  } else if (strVStr(value,"modelo")) {
    printf("Ingrese modelo: ");
    scanf("%s", newCar.model);
  } else if (strVStr(value,"año")) {
    printf("Año: ");
    scanf("%d", &newCar.year);
  } else if (strVStr(value,"puertas")) {
    printf("Número de puertas: ");
    scanf("%d", &newCar.doors);
  } else if (strVStr(value,"clima")) {
    printf("Tipo de ruedas: ");
    scanf("%s", newCar.wheels.weather);
  } else if (strVStr(value,"diametro")) {
    printf("Ancho de las ruedas: ");
    scanf("%f", &newCar.wheels.diameter);
  } else if (strVStr(value,"cilindrada")) {
    printf("Tipo de cilindrada: ");
    scanf("%f", &newCar.motors.capacity);
  } else if (strVStr(value,"combustible")) {
    printf("Tipo de combustible: ");
    scanf("%s", newCar.motors.fuel);
  } else {
    printf("Algo malio sal\n");
  }
  return newCar;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  struct vehicle autito[TOTAL];
  for (size_t i = 0; i < TOTAL; i++) {
    autito[i] = setVehicle(i);
    printf("\n");
  }
  for (size_t i = 0; i < TOTAL; i++) {
    showVehicle(autito[i]);
  }

  printf("\n");
  printf("\n");
  int valor;
  char campo[255];
  printf("Eliga un vehiculo para modificar:\n");
  printf("[0, %d]\n", TOTAL-1);
  scanf("%d", &valor);
  printf("Eliga caracteristica a modificar:\n");
  printf("marca, modelo, año, puertas, clima, diametro, cilindrada, combustible\n");
  scanf("%s", campo);
  change(autito[valor], campo);

  printf("\n");
  printf("\n");
  printf("Vehiculos ordenados por año\n");
  int n = sizeof(autito) / sizeof(autito[0]);
  quicksort(autito, 0, n-1);
  for (size_t i = 0; i < TOTAL; i++) {
    showVehicle(autito[i]);
  }

  printf("\n");
  printf("\n");
  printf("Vehiculos ordenados por modelo\n");
  bubbleAlphabet(autito, TOTAL);
  for (size_t i = 0; i < TOTAL; i++) {
    showVehicle(autito[i]);
  }

  return 0;
}
