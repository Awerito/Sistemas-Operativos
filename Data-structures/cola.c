#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

/* Estructura nodo */
typedef struct n {
  int data;
  int pid;
  int count;
  struct n* next;
}*node;

/* isEmpty(queue); */
bool isEmpty(node queue) {
  return (queue == NULL);
}

/* showQueue(queue); */
void showQueue(node queue) {
  node aux = queue;

  printf("[");
  while (aux != NULL) {
    printf("(%d, %d, %d)", aux->pid, aux->data, aux->count);
    if (aux->next != NULL) {
      printf(",");
    }
    aux = aux->next;
  }
  printf("]\n");
}

/* showFrontData(queue); */
int showFrontData(node queue) {
  return queue->data;
}

/* showFrontPID(queue); */
int showFrontPID(node queue) {
  return queue->pid;
}

/* showFrontCount(queue); */
int showFrontCount(node queue) {
  return queue->count;
}

/* queue = push(queue, value); */
node push(node queue, int value, int pid, int count) {
  node aux = queue;

  node newNode = (node) malloc(sizeof(struct n));
  newNode->data = value;
  newNode->pid = pid;
  newNode->count = count;
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
}

/* queue = swap(queue, value1, value2) */
node swap(node queue, int value1, int value2) {
  node aux1 = queue, aux2 = queue;
  while(value1 != aux1->data) {
    aux1 = aux1->next;
  }
  while(value2 != aux2->data) {
    aux2 = aux2->next;
  }
  aux1->data = value2;
  aux2->data = value1;
  int temp = aux1->pid;
  aux1->pid = aux2->pid;
  aux2->pid = temp;

  return queue;
}

/* valueOf(queue, index) */
int valueOf(node queue, int index) {
  node aux = queue;
  while (index != 0) {
    aux = aux->next;
    index--;
  }
  return aux->data;
}

/* pidOf(queue, index) */
int pidOf(node queue, int index) {
  node aux = queue;
  while (index != 0) {
    aux = aux->next;
    index--;
  }
  return aux->pid;
}

/* El main donde esta toh pahando */
int main() {
  /*Ejemplo*/
  srand(time(NULL));
  int quantum = 10;
  node pendientes = NULL;
  for (size_t i = 0; i < 4; i++) {
    pendientes = push(pendientes, rand()%100, rand()%25, 0);
  }
  showQueue(pendientes);

  node terminadas = NULL;
  if (isEmpty(terminadas)) {
    printf("vacia\n");
  } else {
    printf("llena\n");
  }
  terminadas = push(pendientes, showFrontData(pendientes), showFrontPID(pendientes), showFrontCount(pendientes) + 1);
  pop(terminadas);
  if (isEmpty(terminadas)) {
    printf("vacia\n");
  } else {
    showQueue(terminadas);
    printf("llena\n");
  }

  // while (!isEmpty(pendientes)) {
  //   int aux = showFrontData(pendientes) - quantum;
  //   if (aux > 0) {
  //     pendientes = push(pendientes, aux, showFrontPID(pendientes), showFrontCount(pendientes) + 1);
  //   } else {
  //     terminadas = push(pendientes, aux, showFrontPID(pendientes), showFrontCount(pendientes) + 1);
  //   }
  //   pendientes = pop(pendientes);
  // }
  showQueue(pendientes);
  showQueue(terminadas);
  return 0;
  /*Ejemplo*/
}
