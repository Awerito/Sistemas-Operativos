#include<stdio.h>
#define L 30 //largo de cadena


//estructura de automovil
typedef struct automovil{
	int anio;
	char marca[L];
	char modelo[L];
} vehiculo;

//Función de ingreso de datos
void ingresar(vehiculo *a)
{
	printf("Ingrese anio del vehiculo\n");
	scanf("%d", &a->anio);

	printf("Ingrese la Marca del Vehiculo\n");
	scanf("%s", a->marca);

	printf("Ingrese el Modelo del Vehiculo\n");
	scanf("%s", a->modelo);
}

//Función para comparar dos cadenas, retorna 1 si son iguales, retorna 0 si no lo son
int comparar(char a[], char b[])
{
	int i,j;
	for (i=0; a[i]!='\0';i++);
	for (j=0; b[j]!='\0';j++);
	if(i!=j)
		return 0;
	for (i=0; a[i]!='\0';i++)
	{
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}

//Función para modificar la información de un automovil dado, según el dato que se requiere cambiar
void modificar(vehiculo *a, char atributo[])
{
	if(comparar(atributo,"anio")==1)
	{
		printf("Ingrese anio del vehiculo\n");
		scanf("%d", &a->anio);
	}
	else if(comparar(atributo, "marca")==1)
	{
		printf("Ingrese la Marca del Vehiculo\n");
		scanf("%s", a->marca);
	}
	else if(comparar(atributo,"modelo")==1)
	{
		printf("Ingrese el Modelo del Vehiculo\n");
		scanf("%s", a->modelo);
	}
	else if(comparar(atributo,"all")==1)
	{

		printf("Ingrese anio del vehiculo\n");
		scanf("%d", &a->anio);
		printf("Ingrese la Marca del Vehiculo\n");
		scanf("%s", a->marca);
		printf("Ingrese el Modelo del Vehiculo\n");
		scanf("%s", a->modelo);
	}
	else
		printf("ERROR: No se indica un atributo correspondiente a Automovil\n");
}

//imprimir la información de un automovil
void imprimir_vehiculo(vehiculo *x)
{
	printf("Anio: %d\n", x->anio);
	printf("Marca: %s\n", x->marca);
	printf("Modelo: %s\n", x->modelo);
}

//Copiar una cadena origen a una destino
void copiar(char *o, char *d)
{
	*d = *o; // se copia la dirección de memoria de una cadena, y se traspasa a otra.
}

//Función de cambio de información entre un dato de tipo Automovil origen a uno destino
void cambio(vehiculo *hasta, vehiculo *desde)
{
	hasta->anio = desde->anio;
	copiar(desde->marca,hasta->marca);
	copiar(desde->modelo,hasta->modelo);
}

//Función para ordenar la informacion de un arreglo de tipo automovil (vehículo) por su año
void ordenar_anio(vehiculo a[], int total)
{
	int i,j;
	vehiculo aux;
	for(i=0; i<total; i++)
	{
		for(j=0; j<total; j++)
		{
			if(a[i].anio > a[j].anio)
			{
				cambio(&aux,&a[i]);
				cambio(&a[i],&a[j]);
				cambio(&a[j],&aux);
			}
		}
	}
}

//Función para ordenar la informacion de un arreglo de tipo automovil (vehículo) por su modelo (Alfabeticamente)
void ordenar_alfabeto_modelo(vehiculo a[], int total)
{
	int i,j;
	vehiculo aux;
	for(i=0; i<total; i++)
	{
		for(j=0; j<total; j++)
		{
			if(a[i].modelo[0] < a[j].modelo[0])
			{
				cambio(&aux,&a[i]);
				cambio(&a[i],&a[j]);
				cambio(&a[j],&aux);
			}
		}
	}
}

//Función Main (Inserción de vehiculos, modificar vehiculo, imprimir, ordenar por anio, ordenar por modelo)
int main()
{
	int i,aModificar;
	vehiculo autitos[5];

	for(i=0; i<5; i++)
	{
		ingresar(&autitos[i]);
		imprimir_vehiculo(&autitos[i]);
	}

	printf("Ingrese un vehículo a modificar\n");
	scanf("%d", &aModificar);

	modificar(&autitos[aModificar],"all");
	printf("Auto Modificador\n");

	printf("\nNormal\n");
	for(i=0; i<5; i++)
		imprimir_vehiculo(&autitos[i]);

	printf("\nOrden por Anio\n");
	ordenar_anio(autitos,5);
	for(i=0; i<5; i++)
		imprimir_vehiculo(&autitos[i]);

	printf("\nOrden por Modelo\n");
	ordenar_alfabeto_modelo(autitos,5);
	for(i=0; i<5; i++)
		imprimir_vehiculo(&autitos[i]);

	printf("\nFin del Programa sin Problemas\n");
}
