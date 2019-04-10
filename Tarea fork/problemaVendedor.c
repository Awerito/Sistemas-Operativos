#include "stdio.h"
#include "sys/types.h"
#include "sys/wait.h"
#include "unistd.h"
#include "stdlib.h"
#include "signal.h"
#include "time.h"
#define TOTAL 10

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int arreglo[TOTAL];
  for (size_t i = 0; i < TOTAL; i++) {
    arreglo[i] = rand()%101;
  }

  for (size_t i = 0; i < TOTAL; i++) {
    pid_t cpid;
    if (fork()== 0) {
      exit(0);
    } else {
      cpid = wait(NULL);
      printf("Esperan3\n");
    }
    printf("Parent pid = %d\n", getpid());
    printf("Child pid = %d\n", cpid);
    printf("Venta: %d\n", arreglo[i]);
  }
  return 0;
}
