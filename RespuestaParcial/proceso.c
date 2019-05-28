#include <stdio.h>
#include<string.h>

typedef struct p
{
	int id;
	char *nombre;
	int ram;
	float prioridad;
	char *usuario;
}proceso;

proceso crear_proceso(int nueva_id, char *nuevo_nombre, int nueva_ram, float nueva_prioridad, char *nuevo_usuario)
{
	proceso nuevo_proceso;
	nuevo_proceso.id = nueva_id;
	nuevo_proceso.nombre = nuevo_nombre;
	if(nueva_ram>=1 && nueva_ram<=1048576)
		nuevo_proceso.ram = nueva_ram;
	else
	{
		printf("Error en Creacion de Proceso\n");
		proceso aux;
		return aux;
	}
	if(nueva_prioridad >= 0 && nueva_prioridad <= 1)
		nuevo_proceso.prioridad = nueva_prioridad;
	else
	{
		printf("Error en Creacion de Proceso\n");
		proceso aux;
		return aux;
	}
	nuevo_proceso.usuario = nuevo_usuario;

	return nuevo_proceso;
}

void llenar_proceso_existente(proceso *nuevo_proceso, int nueva_id, char *nuevo_nombre, int nueva_ram, float nueva_prioridad, char *nuevo_usuario)
{
	nuevo_proceso->id = nueva_id;
	nuevo_proceso->nombre = nuevo_nombre;
	if(nueva_ram>=1 && nueva_ram<=1048576)
		nuevo_proceso->ram = nueva_ram;
	else
	{
		printf("Error en Creacion de Proceso\n");
	}
	if(nueva_prioridad >= 0 && nueva_prioridad <= 1)
		nuevo_proceso->prioridad = nueva_prioridad;
	else
	{
		printf("Error en Creacion de Proceso\n");
	}
	nuevo_proceso->usuario = nuevo_usuario;
}

void intercambiar_proceso(proceso *origen, proceso *destino)
{
	proceso aux;
	aux.id = origen->id;
	aux.nombre = (char *) malloc(10);
	strcpy(aux.nombre, origen->nombre);
	aux.ram = origen->ram;
	aux.prioridad = origen->prioridad;
	aux.usuario = (char *) malloc(10);
	strcpy(aux.usuario, origen->usuario);

	//origen.nombre = (char *) malloc(10);
	origen->id = destino->id;
	strcpy(origen->nombre, destino->nombre);
	origen->ram = destino->ram;
	origen->prioridad = destino->prioridad;
	strcpy(origen->usuario, destino->usuario);

	//origen.nombre = (char *) malloc(10);
	destino->id = aux.id;
	strcpy(destino->nombre, aux.nombre);
	destino->ram = aux.ram;
	destino->prioridad = aux.prioridad;
	strcpy(destino->usuario, aux.usuario);
}

void copiar_proceso(proceso *origen, proceso *destino)
{
	destino->id = origen->id;
	strcpy(destino->nombre, origen->nombre);
	destino->ram = origen->ram;
	destino->prioridad = origen->prioridad;
	strcpy(destino->usuario, origen->usuario);
}

void imprimir_proceso(proceso p)
{
	printf("%d\t%s\t%d\t%.2f\t\t%s\n", p.id, p.nombre, p.ram, p.prioridad, p.usuario);
}