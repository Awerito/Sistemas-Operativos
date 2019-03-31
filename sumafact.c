#include "stdio.h"

void sumFactorial(int number) {
  int factorial = 1, sum = 0;
  for (size_t i = 1; i <= number; i++) {
    factorial *= i;
    sum += factorial;
  }
  printf("Resultado: %d\n", sum);
}

int main(int argc, char const *argv[]) {
  int number;
  printf("Ingrese hasta donde quiere desarrollar la suma: ");
  scanf("%d", &number);
  sumFactorial(number);
  return 0;
}
