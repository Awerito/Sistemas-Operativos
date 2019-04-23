#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

typedef struct n {
  int data;
  struct n* next;
}*node;

bool isEmpty(node queue) {
  /*
    isEmpty(queue);
  */
  return (queue == NULL);
}

void showQueue(node queue) {
  /*
    showQueue(queue);
  */
  node aux = queue;

  printf("[");
  while (aux != NULL) {
    printf("%d", aux->data);
    if (aux->next != NULL) {
      printf(",");
    }
    aux = aux->next;
  }
  printf("]\n");
}

node push(node queue, int value) {
  /*
    queue = push(queue, value);
  */
  node aux = queue;

  node newNode = (node) malloc(sizeof(struct n));
  newNode->data = value;
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

node pop(node queue) {
  /*
    queue = pop(queue);
  */
  if(!isEmpty(queue)){
    return queue->next;
  }
}

int main() {
  /*Ejemplo*/
  srand(time(NULL));
  node cola = NULL;
  for (size_t i = 0; i < 5; i++) {
    cola = push(cola, i);
  }
  showQueue(cola);
  cola = pop(cola);
  showQueue(cola);
  cola = pop(cola);
  showQueue(cola);
  cola = pop(cola);
  showQueue(cola);
  cola = pop(cola);
  showQueue(cola);
  cola = pop(cola);
  showQueue(cola);
  return 0;
  /*Ejemplo*/
}
