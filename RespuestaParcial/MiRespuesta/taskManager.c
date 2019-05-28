#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"
#define TOTAL 10

/* Dumpdata */
char *nombreTareas[10] = {"Task_Manager", "Chrome_Task", "Steam_Client","File_Explorer", "Terminal", "Adobe_Reader", "Device_Manager", "Osu_Client","postgreSQL", "LOL_Of_Legends"};
char *usuariosTareas[4] = {"admin", "awerito", "cba", "vistor"};

/* Estructura nodo */
typedef struct n {
  int pid, prioridad, memoria;
  char *nombre, *usuario;

  struct n* next;
}*node;

/* isEmpty(queue); */
bool isEmpty(node queue) {
  return (queue == NULL);
}

/* showTask(queue) */
void showTask(node queue) {
  node aux = queue;

  printf("-------------------------------------------------------------------------------------------------\n");
  printf("PID\tProceso\t\t\tUsuario\t\tMemoria RAM\tPrioridad\n");
  printf("-------------------------------------------------------------------------------------------------\n");

  while (aux != NULL) {
    printf("%d\t%s\t\t%s\t\t%d\tMb\t%d\n", aux->pid, aux->nombre, aux->usuario,
    aux->memoria, aux->prioridad);
    aux = aux->next;
  }

  printf("-------------------------------------------------------------------------------------------------\n");
}

/* getPID(queue); */
int getPID(node queue) {
  return queue->pid;
}

/* queue = push(queue, value); */
node push(node queue, int pid, char* name, char* user, int memoria, int priority) {
  node aux = queue;

  node newNode = (node) malloc(sizeof(struct n));
  newNode->pid = pid;
  newNode->nombre = name;
  newNode->usuario = user;
  newNode->memoria = memoria;
  newNode->prioridad = priority;
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
  } else {
    return NULL;
  }
}

int priorityOf(node queue, int i) {
  node aux = queue;
  while (i) {
    i--;
    aux = aux->next;
  }
  return aux->prioridad;
}

int ramOf(node queue, int i) {
  node aux = queue;
  while (i) {
    i--;
    aux = aux->next;
  }
  return aux->memoria;
}

void swap(node queue, int i, int j) {
  node aux1 = queue;
  node aux2 = queue;

  while (i) {
    i--;
    aux1 = aux1->next;
  }

  while (j) {
    j--;
    aux2 = aux2->next;
  }

  int auxPid = aux1->pid;
  int auxPriori = aux1->prioridad;
  int auxMem = aux1->memoria;
  aux1->pid = aux2->pid;
  aux1->prioridad = aux2->prioridad;
  aux1->memoria = aux2->memoria;
  aux2->pid = auxPid;
  aux2->prioridad = auxPriori;
  aux2->memoria = auxMem;
}

void quicksortP(node arr, int l, int r) {
  if(l >= r) {
    return;
  }
  int pivot = priorityOf(arr, r);
  int cnt = l;
  for (int i = l; i <= r; i++) {
    if (priorityOf(arr, i) <= pivot) {
      //cnt i
      swap(arr, cnt, i);
      cnt++;
    }
  }
  quicksortP(arr, l, cnt-2);
  quicksortP(arr, cnt, r);
}

void quicksortR(node arr, int l, int r) {
  if(l >= r) {
    return;
  }
  int pivot = ramOf(arr, r);
  int cnt = l;
  for (int i = l; i <= r; i++) {
    if (ramOf(arr, i) <= pivot) {
      //cnt i
      swap(arr, cnt, i);
      cnt++;
    }
  }
  quicksortR(arr, l, cnt-2);
  quicksortR(arr, cnt, r);
}

/* El main donde esta toh pahando */
int main() {
  srand(time(NULL));
  node pendientes = NULL;
  for (size_t i = 0; i < TOTAL; i++) {
    pendientes=push(pendientes,i+1, nombreTareas[rand()%10], usuariosTareas[rand()%4], rand()%1048576 + 1, rand()%10);
  }
  printf("Lista por PID:\n");
  showTask(pendientes);

  printf("Lista por Prioridad:\n");
  quicksortP(pendientes, 0, TOTAL-1);
  showTask(pendientes);

  printf("Lista por Memoria:\n");
  quicksortR(pendientes, 0, TOTAL-1);
  showTask(pendientes);
  return 0;
}
