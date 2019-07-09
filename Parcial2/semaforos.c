#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaforito;

void* hilo(void* arg)
{
	pthread_t tid;
	tid = pthread_self();
	printf("Inicio de hilo: %u\n", (unsigned int )tid);
	//esperar
	sem_wait(&semaforito);
	printf("\nHa Entrado...\n");

	//sección Crítica
	sleep(4); //toda la rutina debiera estar en esta sección

	//señal
	printf("\nHa Salido...\n");
	sem_post(&semaforito);
}

int main()
{
	sem_init(&semaforito, 0, 1);
	pthread_t t1, t2;
	pthread_create(&t1, NULL, hilo, NULL);
	sleep(2);
	pthread_create(&t2, NULL, hilo, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	sem_destroy(&semaforito);
	return 0;
}
