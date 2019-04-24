#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

/* Estructura nodo */
typedef struct n {
  int data;
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
    printf("%d", aux->data);
    if (aux->next != NULL) {
      printf(",");
    }
    aux = aux->next;
  }
  printf("]\n");
}

/* queue = push(queue, value); */
node push(node queue, int value) {
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

/* queue = pop(queue); */
node pop(node queue) {
  if(!isEmpty(queue)){
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

/* El main donde esta toh pahando */
int main() {
  /*Ejemplo*/
  srand(time(NULL));
  node cola = NULL;
  for (size_t i = 0; i < 20; i++) {
    cola = push(cola, rand()%100);
  }
  showQueue(cola);
  return 0;
  /*Ejemplo*/
}
