# Sistemas Operativos
## nSystem
Es un sistema que implementa *threads* en el sistema **Unix** compartiendo espacio de direcciones virtuales
>Es como un emulador de un sistema Operativos

## Programación Concurrente
Es la disciplina que trabaja las multitareas simuntaneas considerando recursos compartidos con el principal objetivo de asegurar la correcta secuencia de interacciones entre los procesos.
### Ejemplo implementación nSystem
Implementación de calculo de la secuancia de Fibonacci.
```
int pfib(int n) {
  if (n<=1) {
    return 1;
  } else {
    nTask task1= nEmitTask(pfib, n-1);
    nTask task2= nEmitTask(pfib, n-2);
    return nWaitTask(task1)+nWaitTask(task2);
  }
}
```
## Dependendencias
La utilización del comando *fork()* es dependiende de **glibc**. Para incluir estas dependencias debemos incluir en el código:
```
sys/types.h
unistd.h
```
> Los compiladores gcc y g++ poseen esta biblioteca instalada.
