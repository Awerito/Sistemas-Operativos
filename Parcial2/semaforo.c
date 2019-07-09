#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int semaforo, cant_tickets;

int tomar_ticket(int *s)
{
	if (*s <= 0)
	{
		printf("Semaforo en Rojo!, Hilo devuelto a la cola\n");
		//s += 1;
		return (-1);
	}
	*s -= 1;
	return 0;
}

void terminar_turno(int *s)
{
	*s += 1;
}

void* hilo(void* arg)
{
	int ticket;
	pthread_t tid;
	tid = pthread_self();
	printf("Inicio de hilo: %u\n", (unsigned int )tid);
	//esperar
	do{
		ticket = tomar_ticket(&semaforo);
	}while(ticket == -1);
	printf("\nHa Entrado...\n");

	printf("\nSemaforo = %d\n", semaforo);

	//sección Crítica
	sleep(4); //toda la rutina debiera estar en esta sección

	printf("Fin de hilo: %u\n", (unsigned int )tid);
	//señal
	printf("\nHa Salido...\n");
	terminar_turno(&semaforo);
	printf("\nSemaforo = %d\n", semaforo);
}

int main()
{
	semaforo = 1;
	pthread_t t1, t2;
	pthread_create(&t1, NULL, hilo, NULL);
	sleep(2);
	pthread_create(&t2, NULL, hilo, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
