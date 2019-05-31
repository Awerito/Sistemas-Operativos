// Desarrolle un programa que permita lanzar varios programas en hilos distintos a la vez hasta terminar con todos los programas de la lista de programas
// 	- Defina la cantidad de hilos a lanzar (ej: 4 hilos)
// 	- Cada programa tiene un tiempo en segundos (espera)
// 	- Imprima el identificador, nombre, usuario y tiempo de espera del programa
// 	- Cuando un hilo se libera, se ocupa en un nuevo programa
// 	- Indique la cantidad de tiempo total en terminar con todos los programas
// 	- Indique la cantidad total de tiempo si no se hubieran usado hilos

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#define  TOTAL 4

/* Node structure */
typedef struct n {
  //char *process, *user;
  int time, memory, id;
  struct n* next;
}*node;

node endedTask;

/* isEmpty(queue); */
bool isEmpty(node queue) {
  return (queue == NULL);
}

/* showQueue(queue); */
void showQueue(node queue) {
  node aux = queue;

  printf("PID\tMemory\tTime\n");
  while (aux != NULL) {
    printf("%d\t%d\t%d\n", aux->id, aux->memory, aux->time);
    aux = aux->next;
  }
  printf("\n");
}

/* showData(queue); */
int getTime(node queue) {
  return queue->time;
}

/* getPID(queue); */
int getMemory(node queue) {
  return queue->memory;
}

/* getCount(queue); */
int getID(node queue) {
  return queue->id;
}

/* queue = push(queue, values); */
node push(node queue, int id, int memory, int time) {
  node aux = queue;

  node newNode = (node) malloc(sizeof(struct n));
  newNode->id = id;
  newNode->memory = memory;
  newNode->time = time;
  newNode->next = NULL;

  if (isEmpty(queue)) {
    return newNode;
  } else {
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = newNode;
    return queue;
  }
}

/* queue = pop(queue); */
node pop(node queue) {
  if(!isEmpty(queue)){
    if (queue->next == NULL) {
      return NULL;
    }
    return queue->next;
  }
  return NULL;
}

void *inProcess(void *data) {
  node p = (node) data;
  fflush(stdout);
  sleep(p->time);
  printf("Process %d finish in %d seconds\n", (int) p->id, (int) p->time);
  return NULL;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  node tasks;

  for (size_t i = 0; i < TOTAL; i++) {
    int ram = rand() % 1048576 + 1;
    int req = rand() % 5 + 1;
    tasks = push(tasks, i, ram, req);
  }

  showQueue(tasks);

  int thread_number;

  printf("How many cores you want to use: \n");
  scanf("%d", &thread_number);

  pthread_t threads[thread_number];

  while (!isEmpty(tasks)) {
    int thread_counter = 0;
    for (size_t i = 0; i < thread_number; i++) {
      if (isEmpty(tasks)) {
        break;
      } else {
        printf("Proceso\n");
        pthread_create(&threads[i], NULL, inProcess, (void *) tasks);
        thread_counter++;
        endedTask = push(
          endedTask,
          getID(tasks),
          getMemory(tasks),
          getTime(tasks)
        );
        tasks = pop(tasks);
        showQueue(tasks);
      }
    }
    printf("Terminadas\n");
    showQueue(endedTask);
    for (size_t i = 0; i < thread_counter; i++) {
      printf("Fin Proceso\n");
      pthread_join(threads[i], NULL);
      if (isEmpty(tasks)) {
        break;
      }
    }
  }



  //pthread_t thread1, thread2, thread3, thread4;

  // pthread_create(&thread1, NULL, inProcess, (void *) &task1);
  // pthread_join(thread1, NULL);
  // printf("\n");
  return 0;
}
