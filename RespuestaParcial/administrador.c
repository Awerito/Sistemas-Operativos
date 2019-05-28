#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"proceso.c"


void llenar_procesos(proceso lista[], int cant)
{
	int i;
	char *nombre_temp, *usuario_temp;
	int ram_temp, prioridad_temp;
	float prioridad_float_temp;
	char usuarioA[] = "System";
	char usuarioB[] = "Admin";
	char numero[12];
	for(i=0; i<cant; i++)
	{	
		sprintf(numero, "%d", i);
		nombre_temp = (char *) malloc(10);
		strcpy(nombre_temp, "Proceso-");
		strcat(nombre_temp,numero);
		ram_temp = rand() % (1048576 - 1 + 1) + 1;
		prioridad_temp = rand() % (10 - 0 + 1) + 0;
		prioridad_float_temp = (float) prioridad_temp/10;
		usuario_temp = (char *) malloc(10);
		if(ram_temp%2==0)
			strcpy(usuario_temp, usuarioA);
		else
			strcpy(usuario_temp, usuarioB);
		llenar_proceso_existente(&lista[i], i, nombre_temp, ram_temp, prioridad_float_temp, usuario_temp);
	}
}

void imprimir_procesos(proceso lista[], int cant)
{
	int i;
	printf("LISTA DE PROCESOS\nID\tNOMBRE\t\tMEMORIA\tPRIORIDAD\tUSUARIO\n");
	for(i=0; i<cant; i++)
		imprimir_proceso(lista[i]);
}

void ordenar_procesos_prioridad(proceso lista[], int cant)
{
	int i,j;
	//ordenamiento
	for(i=0; i<cant; i++)
		for(j=0; j<cant; j++)
			if(lista[j].prioridad < lista[i].prioridad)
				intercambiar_proceso(&lista[j],&lista[i]);

	printf("LISTA DE PROCESOS ORDENADOS POR PRIORIDAD\nID\tNOMBRE\t\tMEMORIA\tPRIORIDAD\tUSUARIO\n");
	for(i=0; i<cant; i++)
		imprimir_proceso(lista[i]);
}

void ordenar_procesos_ram(proceso lista[], int cant)
{
	int i,j;
	//ordenamiento
	for(i=0; i<cant; i++)
		for(j=0; j<cant; j++)
			if(lista[j].ram < lista[i].ram)
				intercambiar_proceso(&lista[j],&lista[i]);

	printf("LISTA DE PROCESOS ORDENADOS POR RAM\nID\tNOMBRE\t\tMEMORIA\tPRIORIDAD\tUSUARIO\n");
	for(i=0; i<cant; i++)
		imprimir_proceso(lista[i]);
}


int eliminar_proceso(proceso lista[], int cant)
{
	int i,p;
	printf("Ingrese el numero del proceso que desea eliminar:\n");
	do{
		scanf("%d",&p);
		if(p < 0 || p > cant - 1)
			printf("Ingrese un valor en el rango de cantidad de procesos existentes\n");
	}while(p < 0 || p > cant - 1);

	for(i=0; i<cant; i++)
		if(lista[i].id == p)
		{
			p=i;
			break;
		}

	for(i=p; i<cant-1; i++)
		copiar_proceso(&lista[i+1],&lista[i]);
	lista[cant-1].id=-1;
	lista[cant-1].nombre=NULL;
	lista[cant-1].ram=-1;
	lista[cant-1].prioridad=-1;
	lista[cant-1].usuario=NULL;

	return cant-1;
}




void main()
{
	int cant_procesos;
	srand(time(NULL));
	printf("Bienvenido al Administrador de Procesos PP1\n");
	printf("Ingrese la cantidad de procesos en el S.O.\n");
	do{
		scanf("%d",&cant_procesos);
		if(cant_procesos < 1)
			printf("Ingrese una cantidad positiva\n");
	}while(cant_procesos<1);

	proceso lista_procesos[cant_procesos];

	llenar_procesos(lista_procesos, cant_procesos);
	imprimir_procesos(lista_procesos, cant_procesos);

	ordenar_procesos_prioridad(lista_procesos, cant_procesos);
	ordenar_procesos_ram(lista_procesos, cant_procesos);

	cant_procesos = eliminar_proceso(lista_procesos, cant_procesos);
	imprimir_procesos(lista_procesos, cant_procesos);
}