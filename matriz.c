#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void show(int size, int matriz[size][size]) {
  for (size_t i = 0; i < size; i++) {
    printf("[");
    for (size_t j = 0; j < size; j++) {
      matriz[i][j] = rand() % 11;
      printf("%d", matriz[i][j]);
      if (j == size - 1) {
        printf("]\n");
      } else {
        printf(",\t");
      }
    }
  }
}

void diagonalSum(int size, int array[size][size]) {
  int sum = 0;
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if(i == j) {
        sum += array[i][i];
      }
    }
  }
  printf("Suma diagonal principal: %d\n", sum);
}

void imparCount(int size, int array[size][size]) {
  int count = 0;
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if(array[i][j]%2 == 0) {
        count++;
      }
    }
  }
  printf("Impares encontrados: %d\n", count);
}

void triangular(int size, int matriz[size][size]) {
  int multiplication = 1;
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if (j >= i) {
        multiplication *= matriz[i][j];
      }
    }
  }
  printf("Pitatoria triangular superior: %d\n", multiplication);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int size;
  printf("Ingrese el tamaño de la matriz: ");
  scanf("%d", &size);
  int matriz[size][size];
  show(size, matriz);
  diagonalSum(size, matriz);
  imparCount(size, matriz);
  triangular(size, matriz);
  return 0;
}
