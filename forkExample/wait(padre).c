#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void){
    pid_t pid, w;
    int i, status;
    char value[3];
    for (i=0; i<3; ++i) {
        if ((pid= fork()) == 0) {
            sprintf(value, "%d", i);
            execl("hijo", "hijo", value, (char *) 0);
        } else
            printf("Hijo creado con fork %d\n", pid);
    }
    while ((w= wait(&status)) && w!=-1){
        printf("PID del proceso esperado:%d - status: %04X\n", w, status);
    }
    exit(0);
}
