#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void maxmin(int array[], int size) {
  int min = 101, max = 0;
  for (size_t i = 0; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
    if (array[i] < min) {
      min = array[i];
    }
  }
  printf("Máximo: %d\n", max);
  printf("Mínimo: %d\n", min);
}

void show(int array[], int size) {
  printf("[");
  for (size_t i = 0; i < size; i++) {
    array[i] = rand() % 101;
    printf("%d", array[i]);
    if (i == size - 1) {
      printf("]\n");
    } else {
      printf(", ");
    }
  }
}

float prom(int array[], int size) {
  float prom = 0;
  for (size_t i = 0; i < size; i++) {
    prom += (float)array[i];
  }
  prom /= size;
  printf("Promedio: %.2f\n", prom);
  return prom / size;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int size;
  printf("Ingrese el tamaño del arreglo de números: ");
  scanf("%d", &size);
  int array[size];
  show(array, size);
  maxmin(array, size);
  float promedio = prom(array, size);
  return 0;
}
