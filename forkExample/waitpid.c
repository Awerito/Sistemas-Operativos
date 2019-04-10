#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void){
    pid_t pid[3], w;
    int i, status;
    char value[3];
    for (i=0; i<3; ++i) {
        if ((pid[i] = fork()) == 0) {
            sprintf(value, “%d”, i);
            execl(“hijo”, “hijo”, value, (char *) 0);
        } else
            printf(“Hijo creado con fork %d\n”, pid[i]);
        for (i=0; (w = waitpid(pid[i], &status, 0)) && w!=-1; ++i){
            if (WIFEXITED(status))
                printf(“PID esperado:%d - valor retornado:%04X\n”, w, WEXITSTATUS(status));
            else if (WIFSIGNALED(status))
                printf(“PID esperado:%d - señal retornada:%04X\n”, w, WTERMSIG(status));
        }
        exit(0);
    }
}